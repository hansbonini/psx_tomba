# Tomba! CD File Loading

How the game gets a file off the disc and into memory, VRAM or SPU RAM.

Everything here is derived from the disassembly and from the partially decompiled
`src/scus_942.36/main/system/cdfile.c`. Addresses are for **SCUS-94236 (USA)**.
Where a fact could not be established from the code it is marked as open rather
than guessed — see [Open questions](#-open-questions).

## 📋 Overview

Loading is asynchronous. Callers never touch the CD directly: they push requests
onto a ring buffer and a dedicated task drains it.

```
caller
  │  func_80021C24(groupId)      "load this group and block until done"
  ├─► func_80021D70(...)         push every file of the group onto the queue
  │     └─► func_80021B84(dst, hdr)   push one entry
  │
  ├─► openTask(2, func_80021340)      start the loader task
  └─► sleepTask(1) until LOAD_COMPLETE

func_80021340  (the loader task)
  queue entry ──► FileLinkArray ──► CdlSetloc ──► CdRead ──► post-process
                  (disc position)                            (LZ / VRAM / SPU)
```

The loader task runs until the queue is empty, sets `LOAD_COMPLETE` and calls
`exitTask()`. It is created fresh for each batch, not kept resident.

## 🗂️ The FileLinkArray (FLA)

`D_800791A0` — the table that maps a file id to its position and size on disc.
It lives in the executable itself, at file offset `0x699A0` (`vram − 0x8000F800`),
and holds **1054 entries** in the USA build. See
[file-analysis.md](file-analysis.md) for the per-region offsets and counts.

Each entry is **8 bytes**:

| Offset | Size | Field | Notes |
|--------|------|-------|-------|
| `0x00` | 4 | `CdlLOC` | minute / second / sector, passed straight to `CdlSetloc` |
| `0x04` | 4 | size in bytes | converted to a sector count by the loader |

`func_80021340` is the only reader of this table. The two accesses are:

```c
CdControlF(CdlSetloc, (u8*)&D_800791A0 + (id * 8));          /* seek     */
CD_NSEC = (u32)((&D_800791A4)[id * 2] + 0x7FF) >> 11;        /* sectors  */
```

`D_800791A4` is simply `D_800791A0 + 4`, so the second access reads the size
field of the same entry. The sector count rounds up to the 2048-byte boundary:
`(size + 0x7FF) / 0x800`.

## 🔄 The request queue

A 128-slot ring buffer at `D_8009E748`. Each slot is **8 bytes**:

| Offset | Field |
|--------|-------|
| `0x00` | pointer to the file header (`cdFileHeader*`) |
| `0x04` | destination pointer, meaning depends on the file type |

Head and tail live in the scratchpad and wrap with `& 0x7F`:

| Address | Role |
|---------|------|
| `0x1F80029C` | head — advanced by the producer |
| `0x1F8002A0` | tail — advanced by the loader task |

Both are zeroed during boot in [main.c:29-30](../src/scus_942.36/main/main.c#L29-L30).
The queue is empty when `head == tail`.

`func_80021B84(dst, hdr)` is the enqueue primitive — sixteen instructions, no
overflow check:

```c
head = CD_HEAD;
D_8009E748[head * 2]     = hdr;    /* slot + 0x00 */
D_8009E74C[head * 2]     = dst;    /* slot + 0x04 */
CD_HEAD = (head + 1) & 0x7F;
```

## 📄 The file header

`cdFileHeader`, declared in [game.h:925](../include/game.h#L925). The queue slot
points at one of these; the loader reads the file id from it and keeps a pointer
in `CD_HDR` for the whole transfer.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| `0x00` | `s16` | `fileId` | indexes the FileLinkArray |
| `0x02` | `u8` | `unk2` | |
| `0x03` | `u8` | `subType` | high nibble selects post-processing, low nibble is the VAB slot base |
| `0x04` | `u8[4]` | `unk4` | |
| `0x08` | `s16` | `x` | VRAM destination, graphics types only |
| `0x0A` | `s16` | `y` | |
| `0x0C` | `s16` | `w` | |
| `0x0E` | `s16` | `h` | also indexes the SPU address table `D_80077D50` |
| `0x10` | `u32` | `flags` | low nibble = file type, bit `0x10` = buffer select |

Two fields drive every decision the loader makes:

- **`flags & 0xF`** — the file type, chooses the read destination and the
  post-processing path.
- **`subType & 0xF0`** — `0x10` means "upload to VRAM", `0x90` means "this is a
  VAB". Only consulted for some types.

## ⚙️ The loader state machine

`func_80021340` is a task, so it re-enters on every frame via `sleepTask(1)` at
the bottom of its loop. `state0` is the main state, held in the task control
block ([game.h:822](../include/game.h#L822)).

On entry it clears `LOAD_COMPLETE`, resets the error counter `D_8009C8B0`, and
spins on `CdControl(14, param, 0)` — command `0x0E` is `CdlSetmode`, with
`param[0] = 0x80` (`CdlModeSpeed`, double speed).

| `state0` | Action | Next |
|----------|--------|------|
| 0 | Idle. If `head == tail` stay put. | 1 when work arrives |
| 1 | Pop the entry at `tail`, latch `CD_REQ`/`CD_HDR`, `CdControlF(CdlSetloc, &FLA[id])` | 2 |
| 2 | `CdSync(1, 0)` | 3 on `CdlComplete` (2); back to 1 on `CdlDiskError` (5) |
| 3 | Compute sector count, pick the destination, `CdRead(nsec, dst, CdlModeSpeed)` | 4 on success |
| 4 | `CdReadSync(1, 0)` | 5 on 0; back to 1 on −1 |
| 5 | Post-processing, driven by `state1` | 6 when finished |
| 6 | Advance `tail`. Queue empty → `LOAD_COMPLETE = 1`, `exitTask()`. Otherwise → 1 | 1 |

Errors are not fatal: states 2, 3 and 4 bump `D_8009C8B0` and rewind to state 1,
which re-seeks and retries the same entry indefinitely.

### Read destination

Chosen in state 3 from the file type:

| `flags & 0xF` | Destination |
|---------------|-------------|
| 0, 3 | shared work buffer — `D_800B3188` if `flags & 0x10`, else `D_800A3348` |
| 1, 2, 4 | the queue entry's own `dst` pointer |

## 🎬 Post-processing

State 5 runs a second state machine in `state1`. Sub-state 0 dispatches on the
file type and jumps to the right path:

| `flags & 0xF` | `subType & 0xF0` | Path |
|---------------|------------------|------|
| 0 | `0x10` | → 2: `LoadImage` straight from the work buffer |
| 0 | `0x90` | → 5: VAB |
| 1 | — | → 1: LZ decompress, then `LoadImage` |
| 2, 4 | `0x90` | → 5: VAB |
| 2, 4 | other | done, nothing to do — the raw read was the whole job |
| 3 | — | → 4: LZ decompress into the caller's buffer |

| `state1` | Action |
|----------|--------|
| 1 | `lzDecompress(entry->dst, workBuffer)`, then falls through to 2 |
| 2 | Build a `RECT` from the header's `x/y/w/h`, `LoadImage(&rect, workBuffer)` |
| 3 | `DrawSync(0)`, then done |
| 4 | `lzDecompress(workBuffer, entry->dst)`, then done |
| 5 | VAB upload, see below |

`lzDecompress` is in [lz.c:111](../src/scus_942.36/main/system/lz.c#L111); the
compressed format is documented in [game-formats.md](game-formats.md).

Note the asymmetry between paths 1 and 4. Type 1 reads compressed data into the
*caller's* buffer and decompresses into the *shared* buffer, because the result
is headed for VRAM. Type 3 does the opposite — reads into the shared buffer and
decompresses into the caller's, because the result stays in RAM.

### VAB upload (`state1 == 5`)

The loaded blob is a container holding two offset tables. `subType & 0xF` gives
the base slot for this batch, with `0xF` remapped to `0`.

```c
blob     = entry->dst;
bodyTop  = blob + *(s32*)(blob + 0);   /* waveform data  */
headerTop= blob + *(s32*)(blob + 4);   /* VAB headers    */
```

Each table starts with its own byte size, which doubles as the offset to the
first element, so the entry count is `size / 4 - 1`.

The routine then does four passes over the slots `base .. base + count`:

1. **Close** — any slot holding a VAB id other than `-1` is released with
   `SsVabClose`. Open ids live in `D_1F8003A8` (scratchpad).
2. **Resolve headers** — `D_8009C758[base + i] = headerTop + headerTop[i]`
3. **Resolve bodies** — `D_8009C658[base + i] = bodyTop + bodyTop[i]`
4. **Transfer** — per VAB:

```c
a   = D_8009C658[base + i];                 /* body start           */
b   = (i == count - 1) ? bodyTop + *bodyCur /* last: end of table   */
                       : D_8009C65C[base + i];  /* next body start  */
len = b - a;

SpuSetTransferStartAddr(spuAddr);
SpuWrite(a, len);                           /* see the note below   */
SpuIsTransferCompleted(1);

vabId = SsVabFakeHead(D_8009C758[base + i], -1, spuAddr);
spuAddr += len;
D_1F8003A8[base + i] = vabId;
SsVabFakeBody(vabId);
```

The starting SPU address comes from `D_80077D50[header->h * 2]` — the header's
`h` field is reused as an index into a table of SPU RAM addresses, stride 8
bytes.

Sizes are computed as the gap to the *next* body pointer, so the bodies must be
stored contiguously and in table order.

> **Symbol warning.** The call at this point is written as `SpuRead` because that
> is the name `symbols/scus_942.36/symbol_addrs.txt` gives to `0x800767A8`. That
> name is wrong: the function clamps its size to `0x7EFF0` and tail-calls
> `_spu_write` (`0x80074AC4`), which is the body of **`SpuWrite`**. The direction
> is main RAM → SPU RAM, as the surrounding
> `SpuSetTransferStartAddr` / `SpuIsTransferCompleted` / `SsVabFakeHead` sequence
> implies. Reading the code as "SpuRead" inverts the data flow.

## 🧠 Scratchpad variables

The loader keeps all of its live state in scratchpad RAM.

| Address | Macro | Type | Role |
|---------|-------|------|------|
| `0x1F8001CE` | `LOAD_COMPLETE` | `u8` | set when the queue drains; callers poll it |
| `0x1F800288` | `CD_REQ` | `u8*` | current queue entry |
| `0x1F80028C` | `CD_HDR` | `s16*` | current file header |
| `0x1F800290` | `CD_DST` | `u8*` | read destination |
| `0x1F800294` | `CD_NSEC` | `s32` | sectors to read |
| `0x1F80029C` | `CD_HEAD` | `s32` | queue head |
| `0x1F8002A0` | `CD_TAIL` | `s32` | queue tail |
| `0x1F8003A8` | `D_1F8003A8` | `s16[]` | open VAB ids, indexed by slot |
| `0x1F8003D2` | — | `u8` | last group loaded, guards re-entry |

`CD_FLAGS` is not a variable — it is a macro for `*(s32*)((u8*)CD_HDR + 0x10)`,
the `flags` field of whatever header is currently latched.

## 🚪 The blocking entry point

`func_80021C24(groupId)` is what gameplay code calls. It:

1. Returns immediately if `groupId + 1` already equals the guard at `0x1F8003D2`
   — the group is already loaded.
2. Looks the group up in `D_800782F8[groupId]` and hands it to `func_80021D70`,
   which pushes every file of the group onto the queue.
3. Clears `LOAD_COMPLETE` and starts the loader with `openTask(2, func_80021340)`.
4. Sleeps one frame at a time while the task is alive, until `LOAD_COMPLETE` is
   set.

So the call looks synchronous to the caller, while the rest of the task system
keeps running.

## ❓ Open questions

Things the code does not settle, listed so nobody has to re-derive the dead end:

- **Work buffer extents.** `D_800A3348` and `D_800B3188` are both taken by
  address (`addiu`, not `lw`), so they are buffers rather than pointer variables.
  Their sizes are not established — the `[0x3D4]` on `D_800A3348` in `game.h` is
  a placeholder, and the neighbouring externs around it are inferred, not proven.
- **Local names in `cdfile.c`.** The locals currently called `vagTop` and
  `progTop` hold, respectively, the **header** table and the **body** table —
  the opposite of what the names suggest. Worth renaming once the function
  matches.
- **`unk2` and `unk4[4]`** in `cdFileHeader` are never read by the loader. They
  may be consumed elsewhere, or be padding.
- **Queue overflow** is unchecked. Whether 128 slots is always enough, or whether
  a group can exceed it, has not been verified.
- **`D_800782F8`**, the group table consumed by `func_80021D70`, has not been
  mapped. `func_80021D70` is still undecompiled.
