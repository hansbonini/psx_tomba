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
  │  loadAreaListFile(groupId)      "load this group and block until done"
  ├─► queueLoadList(...)         push every file of the group onto the queue
  │     └─► func_80021B84(dst, hdr)   push one entry
  │
  ├─► openTask(2, cdLoadTask)      start the loader task
  └─► sleepTask(1) until LOAD_COMPLETE

cdLoadTask  (the loader task)
  queue entry ──► FileLinkArray ──► CdlSetloc ──► CdRead ──► post-process
                  (disc position)                            (LZ / VRAM / SPU)
```

The loader task runs until the queue is empty, sets `LOAD_COMPLETE` and calls
`exitTask()`. It is created fresh for each batch, not kept resident.

## 🗂️ The FileLinkArray (FLA)

`FILE_LINKS` — the table that maps a file id to its position and size on disc.
It lives in the executable itself, at file offset `0x699A0` (`vram − 0x8000F800`),
and holds **1054 entries** in the USA build. See
[file-analysis.md](file-analysis.md) for the per-region offsets and counts.

Each entry is **8 bytes**:

| Offset | Size | Field | Notes |
|--------|------|-------|-------|
| `0x00` | 4 | `CdlLOC` | minute / second / sector, passed straight to `CdlSetloc` |
| `0x04` | 4 | size in bytes | converted to a sector count by the loader |

`cdLoadTask` is the only reader of this table. The two accesses are:

```c
CdControlF(CdlSetloc, (u8*)&FILE_LINKS + (id * 8));          /* seek     */
CD_NSEC = (u32)((&FILE_LINK_SIZES)[id * 2] + 0x7FF) >> 11;        /* sectors  */
```

`FILE_LINK_SIZES` is simply `FILE_LINKS + 4`, so the second access reads the size
field of the same entry. The sector count rounds up to the 2048-byte boundary:
`(size + 0x7FF) / 0x800`.

## 🔄 The request queue

A 128-slot ring buffer at `CD_QUEUE`. Each slot is **8 bytes**:

| Offset | Field |
|--------|-------|
| `0x00` | pointer to the file header (`LoadRecord*`) |
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
CD_QUEUE[head * 2]     = hdr;    /* slot + 0x00 */
CD_QUEUE_DST[head * 2]     = dst;    /* slot + 0x04 */
CD_HEAD = (head + 1) & 0x7F;
```

## 📄 The file header

`LoadRecord`, declared in [game.h](../include/game.h). The queue slot
points at one of these; the loader reads the file id from it and keeps a pointer
in `CD_HDR` for the whole transfer.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| `0x00` | `s16` | `fileId` | `CdFile`, indexes `FILE_LINKS`; `-1` ends a list |
| `0x02` | `u8` | `slot` | `0xFF` none; below `0x80` saves the destination in `LOAD_SLOTS`, otherwise reads it back |
| `0x03` | `u8` | `kind` | `LoadKind` in the high nibble (which table gets the pointer), index in the low nibble |
| `0x04` | `u32` | `addr` | destination address, `0` = right after the previous record |
| `0x08` | `u32` | `arg` | size in bytes, or `LOAD_XY(x, y)` for `LOAD_KIND_GRPX` |
| `0x0C` | `s16` | `w` | |
| `0x0E` | `s16` | `h` | for sound banks, indexes the SPU address table `SPU_BANK_ADDRS` |
| `0x10` | `u32` | `type` | `LoadType` in the low nibble, bit `0x10` = `LOAD_TYPE_ALT_BUFFER`; `LOAD_TYPE_SUB` marks a piece inside the previous file |

Two fields drive every decision the loader makes:

- **`type & 0xF`** — the file type, chooses the read destination and the
  post-processing path.
- **`kind & 0xF0`** — `0x10` means "upload to VRAM", `0x90` means "this is a
  VAB". Only consulted for some types.

## ⚙️ The loader state machine

`cdLoadTask` is a task, so it re-enters on every frame via `sleepTask(1)` at
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

| `type & 0xF` | Destination |
|---------------|-------------|
| 0, 3 | shared work buffer — `LOAD_BUFFER_ALT` if `flags & 0x10`, else `LOAD_BUFFER` |
| 1, 2, 4 | the queue entry's own `dst` pointer |

## 🎬 Post-processing

State 5 runs a second state machine in `state1`. Sub-state 0 dispatches on the
file type and jumps to the right path:

| `type & 0xF` | `kind & 0xF0` | Path |
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

The loaded blob is a container holding two offset tables. `kind & 0xF` gives
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
   `SsVabClose`. Open ids live in `VAB_IDS` (scratchpad).
2. **Resolve headers** — `WVD_HEADERS[base + i] = headerTop + headerTop[i]`
3. **Resolve bodies** — `WVD_BODIES[base + i] = bodyTop + bodyTop[i]`
4. **Transfer** — per VAB:

```c
a   = WVD_BODIES[base + i];                 /* body start           */
b   = (i == count - 1) ? bodyTop + *bodyCur /* last: end of table   */
                       : WVD_BODIES_NEXT[base + i];  /* next body start  */
len = b - a;

SpuSetTransferStartAddr(spuAddr);
SpuWrite(a, len);                           /* see the note below   */
SpuIsTransferCompleted(1);

vabId = SsVabFakeHead(WVD_HEADERS[base + i], -1, spuAddr);
spuAddr += len;
VAB_IDS[base + i] = vabId;
SsVabFakeBody(vabId);
```

The starting SPU address comes from `SPU_BANK_ADDRS[header->h * 2]` — the header's
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
| `0x1F8003A8` | `VAB_IDS` | `s16[]` | open VAB ids, indexed by slot |
| `0x1F8003D2` | — | `u8` | last group loaded, guards re-entry |

`CD_FLAGS` is not a variable — it is a macro for `*(s32*)((u8*)CD_HDR + 0x10)`,
the `flags` field of whatever header is currently latched.

## 🚪 The blocking entry point

`loadAreaListFile(groupId)` is what gameplay code calls. It:

1. Returns immediately if `groupId + 1` already equals the guard at `0x1F8003D2`
   — the group is already loaded.
2. Looks the group up in `LDAR_LOAD_LISTS[groupId]` and hands it to `queueLoadList`,
   which pushes every file of the group onto the queue.
3. Clears `LOAD_COMPLETE` and starts the loader with `openTask(2, cdLoadTask)`.
4. Sleeps one frame at a time while the task is alive, until `LOAD_COMPLETE` is
   set.

So the call looks synchronous to the caller, while the rest of the task system
keeps running.

## ❓ Open questions

Things the code does not settle, listed so nobody has to re-derive the dead end:

- **Work buffer extents.** `LOAD_BUFFER` and `LOAD_BUFFER_ALT` are both taken by
  address (`addiu`, not `lw`), so they are buffers rather than pointer variables.
  Their sizes are not established — the `[0x3D4]` on `LOAD_BUFFER` in `game.h` is
  a placeholder, and the neighbouring externs around it are inferred, not proven.
- **Queue overflow** is unchecked. Whether 128 slots is always enough, or whether
  a group can exceed it, has not been verified.
- **`queueLoadList`** is still undecompiled; what it does was read from its
  assembly. `LDAR_LOAD_LISTS[area]` loads `SYS/LDARnn.BIN`, the list file of an
  area.
