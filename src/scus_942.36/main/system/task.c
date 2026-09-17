#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", compactOrderingTable);
void compactOrderingTable(u_long* ot)
{
    s32     n;
    u_long* p;
    u_long* hole;
    u_long* next;
    u_long  val;
    u_long  cur;
    u_long  prev;
    int     differs;

    n = 0x327;
    hole = (u_long*)(((u_long)ot) & 0xFFFFFF);
    p = hole;

loop1:
    val = *p;
    prev = (u_long)(p - 1);
    if ((*p) == prev) {
        goto found;
    }
    val = (n--) == 0;
    if (val) {
        return;
    }
    p--;
    goto loop1;

found:
    hole = p;
    if ((n--) == 0) {
        return;
    }
    p++;
    p--;
    p--;

loop2:
    val = *p;
    cur = val;
    prev = (u_long)(p - 1);
    differs = cur != prev;
    next = (u_long*)val;
    if (differs) {
        goto link;
    }
    if ((n--) == 0) {
        return;
    }
    p = next;
    goto loop2;

link:
    *hole = (u_long)p;
    prev = (n--) == 0;
    if (prev) {
        return;
    }
    p--;
    goto loop1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", initTasks);
void initTasks(void)
{
    struct TCB*         tcb;
    unkstruct_1F8001D4* task;
    s32                 i;

    tcb  = *(struct TCB**)0x110;
    task = (unkstruct_1F8001D4*)TASK_TABLE;

    for (i = 0; i < 3; i++) {
        tcb++;
        task->unk0    = 0;
        task->task_sp = 0x801FE400 + i * 0x800;
        task++;
        tcb->reg[R_SR] = 0x40000404;
    }
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", dispatchTasks);
void dispatchTasks(void)
{
    int tid;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;

    *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4) = (u32*)TASK_TABLE;
    for (task = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4); task <= 0x801FD94FU; task = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4) = *(u32* )(&D_1F8000C0[0]+0x114) + sizeof(unkstruct_1F8001D4)) {
        tid = 2;
        switch ((u16)(*(unkstruct_1F8001D4** )((byte*)D_1F8001A0+0x34))->unk0) {
            case 3:
                EnterCriticalSection();
                task2 = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                (CURRENT_TASK)->task_id = OpenTh(task2->task_func, task2->task_sp, task2->task_gp);
                ExitCriticalSection();
            case 2:
                task3 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                task3->unk0 = tid*2;
                ChangeTh(task3->task_id);
                break;
        }
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", startTask);
void startTask(s32 id, int fn)
{
    setTaskEntry((unkstruct_01*)((TASK_TABLE + 0xC) + id * 0x70), fn);
    openTask(id, ((unkstruct_1F8001D4*)(TASK_TABLE + id * 0x70))->task_func);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", openTask);
void openTask(s32 arg0, long (*func)())
{
    int off = arg0 * sizeof(unkstruct_1F8001D4);

    ((unkstruct_1F8001D4*)(TASK_TABLE + off))->unk0 = 2;
    EnterCriticalSection();
    *(int*)((TASK_TABLE + 0x4) + off) = OpenTh(func,
                                           *(int*)((TASK_TABLE + 0x8) + off),
                                           *(int*)((TASK_TABLE + 0x10) + off));
    ExitCriticalSection();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", sleepTask);
void sleepTask(s16 arg0)
{
    unkstruct_1F8001D4* task;

    task = CURRENT_TASK;
    task->unk2 = arg0;
    task->unk0 = 1;
    ChangeTh(DescTH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", exitTask);
void exitTask(void)
{
    (CURRENT_TASK)->unk0 = 0;
    EnterCriticalSection();
    CloseTh((*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->task_id);
    ExitCriticalSection();
    ChangeTh(DescTH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", closeTask);
void closeTask(s32 id)
{
    s32  off;
    u16* flag;

    off  = id * 0x70;
    flag = (u16*)(TASK_TABLE + off);

    if (*flag != 0) {
        *flag = 0;
        EnterCriticalSection();
        CloseTh(*(s32*)((TASK_TABLE + 0x4) + off));
        ExitCriticalSection();
    }
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", setTask);
void setTask(s32 arg0)
{
    unkstruct_1F8001D4* task;

    task = CURRENT_TASK;
    task->unk0 = 3;
    task->task_func = arg0;
    EnterCriticalSection();
    CloseTh((*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->task_id);
    ExitCriticalSection();
    ChangeTh(DescTH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", setTaskFlag10);
void setTaskFlag10(s32 id)
{
    u16* p;

    p = (u16*)(TASK_TABLE + id * 0x70);
    *p |= 0x10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", clearTaskFlag10);
void clearTaskFlag10(s32 id)
{
    u16* p;

    p = (u16*)(TASK_TABLE + id * 0x70);
    *p &= ~0x10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", vblankHandler);
void vblankHandler(void)
{
    scratchpad* scratch = PSX_SCRATCH;

    scratch->vblankCount++;
    scratch->frameCount++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", tickTaskTimers);
void tickTaskTimers(void)
{
    #define D_801FD800 ((void*)TASK_TABLE)
    u16* p;
    u16  t;

    p = (u16*)(D_801FD800);
    do {
        if (*p == 1) {
            t = p[1] - 1;
            p[1] = t;
            if ((t << 0x10) == 0) {
                *p = 2;
            }
        }
        p += 0x38;
    } while (p <= (u16*)(D_801FD800 + 0x14F));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/task", setTaskEntry);
void setTaskEntry(unkstruct_01* arg0, int arg1)
{
    DrawSync(0);
    arg0->unk0 = arg1;
    arg0->saved_reg_gp = GetGp();
}
