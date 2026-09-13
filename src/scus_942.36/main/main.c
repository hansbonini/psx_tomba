#include "common.h"
#include "game.h"

#define CURRENT_TASK *(unkstruct_1F8001D4**)0x1F8001D4
#define TASK_TABLE  0x801FD800

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", main);
void main(void)
{
    u8 cdMode;
    u16 toggled;
    u16 flags;
    u16 targetFrame;
    u16 joypad_state;
    u16 newFlags;
    u16 curFlags;
    s32 dbgMode;
    u_short* joypad_state_ptr;

    SetDispMask(0);
    SetVideoMode(MODE_NTSC);
    ResetCallback();
    initGlobalState();
    ResetGraph(0);
    SetGraphDebug(0);
    InitGeom();
    CdInit();
    cdMode = 0x80;
    while (CdControl(0xE, &cdMode, 0) == 0);
    DecDCTReset(0);
    *(s32*)0x1F8002A0 = 0;
    *(s32*)0x1F80029C = 0;
    initGraphics();
    GsSetOrigin(1, 1);
    func_800211A4();
    SetDefDispEnv(&D_8009AFE8, 0, 0, 512, 240);
    memCardInit();
    joypadInit();
    initTasks();
    startTask(0, bootSequenceTask);
    EnterCriticalSection();
    *(s32*)0x1F8001D8 = OpenEvent(RCntCNT3, EvSpINT, RCntMdINTR, &vblankHandler);
    ExitCriticalSection();
    joypad_state_ptr = &D_8009EB5A;
    EnableEvent(*(u32*)(&D_1F8000C0[0]+0x118));
    SetDispMask(1);
    while (true) {
        *(u16*)((byte*)&D_1F8001A0+0x48) = 0;
        if (*(u16*)(&SCRATCHPAD+0x1F0) < 0x4001U) {
            D_8009C8A8 = (*(s16*)0x1F8001F4 * 0x780) + &D_800A1890;
            dispatchTasks();
        }
        if (*(u16*)0x1F8001EC != 0) {
            DrawSync(0);
        }
        targetFrame = *(u16*)(&D_1F8000C0[0]+0x12A);
        while (((unkstruct_1F8001D4*)0x1F8001D4)->unk14 < targetFrame) {
        }
        if (*(u16*)(&SCRATCHPAD+0x1EC) == 0) {
            ResetGraph(1);
        }
        if ((*(u8*)0x1F8001BD != 0) && ((*(u8*)0x1F8001D1 | *(u8*)0x1F8001D0) != 0)) {
            while (~*joypad_state_ptr & JOY_R2) {
                if (~*joypad_state_ptr & JOY_LEFT) {
                    D_8009AFE8.disp.x -= 4;
                }
                if (~*joypad_state_ptr & JOY_RIGHT) {
                    D_8009AFE8.disp.x += 4;
                }
                if (~*joypad_state_ptr & JOY_UP) {
                    D_8009AFE8.disp.y -= 4;
                }
                if (~*joypad_state_ptr & JOY_DOWN) {
                    D_8009AFE8.disp.y += 4;
                }
                VSync(0);
                PutDispEnv(&D_8009AFE8);
                do {} while (0);
            }
        }

        switch (*(u8*)0x1F8001CC) {
            case 2:
                break;
            case 0:
            case 1:
                if (*(u16*)0x1F8001F0 <= 0x4000) {
                    flipFrameBuffer();
                    tickTaskTimers();
                }
                break;
            case 3:
                *(u8*)(&SCRATCHPAD+0x1CC) = 2;
                if (*(u16*)0x1F8001F0 <= 0x4000) {
                    flipFrameBuffer();
                    tickTaskTimers();
                }
                break;
        }

        if (*(u8*)0x1F8001BF != 0) {
            if ((*(u8*)0x1F8001CC == 0) && ((*(u8*)0x1F8001D1 | *(u8*)0x1F8001D0) != 0) && (*(u8*)0x1F8001CE == 1) && (*(u16*)0x1F8001FC & JOY_L1)) {
                *(u16*)(&SCRATCHPAD+0x1F0) = (u16)(0x8000 - *(u16*)0x1F8001F0);
            }
        } else if (*(u8*)0x1F8001BE != 0 && *(u8*)0x1F8001CC == 0 && ((*(u8*)0x1F8001D1 | *(u8*)0x1F8001D0) != 0)) {
            dbgMode = *(u8*)0x1F8001CE;
            if (dbgMode == 1) {
                joypad_state = *(u16*)0x1F8001FC;
                if (joypad_state & JOY_L1) {
                    toggled = 1 - *(u16*)0x1F8001EE;
                    *(u16*)(&SCRATCHPAD+0x1EE) = toggled;
                    *(u16*)0x1F8001F0 = (u16)(toggled << 0xF);
                }
                if (*(u16*)(0x1F8001EE) != 0) {
                    *(u16*)0x1F8001F0 = 0x8000U;
                    if (joypad_state & JOY_L2) {
                        *(u16*)(&SCRATCHPAD+0x1F0) = 0U;
                    }
                } else if (joypad_state & JOY_L2) {
                    flags = *(u16*)0x1F8001F0;
                    newFlags = (~flags & 0x4000) | (flags & 0xBFFF);
                    *(u16*)(&D_1F800118[0]+0xD8) = newFlags;
                    if (!(newFlags & 0x4000)) {
                        *(u16*)(&SCRATCHPAD+0x1F0) = (u16)(newFlags & 0xFFF0);
                    }
                } else {
                    curFlags = *(u16*)0x1F8001F0;
                    if (curFlags & 0x4000) {
                        *(u16*)(&SCRATCHPAD+0x1F0) = (u16)((curFlags + 1) & 0xFFF3);
                    }
                }
            }
        }   
    };
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", flipFrameBuffer);
void flipFrameBuffer(void)
{
    short bufIndex;
    u_long* ot;
    u_long* prevOt;

    bufIndex = 1 - *(u_short* )(0x1F8001F4);
    ot = (bufIndex * 0xD10) + (byte*)&OT_FRAMEBUFFER;
    prevOt = *(u_long** )((byte*)&D_1F8000C0[0]+0x120);
    *(u_short* )(&SCRATCHPAD+0x1f4) = (u_short) bufIndex;
    *(u_long* )(&SCRATCHPAD+0x1E0) = ot;
    *(u_long** )(&SCRATCHPAD+0x1E4) = prevOt;
    PutDispEnv(ot + 0x328);
    PutDrawEnv(*(u_long* )0x1F8001E0 + 0xCB4);
    compactOrderingTable(*(u_long* )(&SCRATCHPAD+0x1E4) + 0xC9C);
    DrawOTag(*(u_long* )(&SCRATCHPAD+0x1E4) + 0xC9C);
    ClearOTagR(*(u_long* )(&SCRATCHPAD+0x1E0), 0x328);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", GsSetOrigin);
void GsSetOrigin(short id, short arg1)
{
    typedef inline struct {
        byte data[0x1EA];
        short unk1EA;
        short unk1EC;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;

    scratch->unk1EA = id;
    scratch->unk1EC = arg1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initGlobalState);
void initGlobalState(void)
{
    typedef inline struct {
        byte data[0x1C4];
        char unk1C4;
        char unk1C5;
        short unk1C6;
        char pad[4];
        char unk1CC;
        char unk1CD;
        char unk1CE;
        char unk1CF;
        char unk1D0;
        char unk1D1;
        char unk1D2;
        char unk1D3;
        byte pad1[0x12];
        short unk1E6;
        short unk1E8;
        short unk1EA;
        short unk1EC;
        short unk1EE;
        short unk1F0;
        short unk1F2;
        short unk1F4;
        short unk1F6;
        short unk1F8;
        byte pad3[0x1D2];
        u_char unk3CC;
        byte pad4[0x5];
        u_char unk3D2;
        u_char unk3D3;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;
    
    D_8009EB5A = 0xFFFF;
    D_8009EB7C = 0xFFFF;
    scratch->unk3D3 = 0xFF;
    scratch->unk3D2 = 0xFF;
    scratch->unk1F0 = 0;
    scratch->unk1F2 = 0;
    scratch->unk1EE = 0;
    scratch->unk1F6 = 0;
    scratch->unk1F8 = 0;
    scratch->unk1CC = 0;
    scratch->unk1D0 = 0;
    scratch->unk1D1 = 0;
    scratch->unk1CE = 0;
    scratch->unk1CF = 0;
    scratch->unk1D3 = 0;
    scratch->unk1C6 = 0;
    scratch->unk1C4 = 0;
    scratch->unk1C5= 0;
    scratch->unk3CC = 0;
    D_8009C9DA = 0;
    D_8009C9DE = 0;
    D_8009C940 = 0;
    D_8009EB52 = 0;
    D_8009C864 = 0;
    D_8009C866 = 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initGraphics);
void initGraphics(void)
{
    RECT rect;
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    MATRIX* matrix = (MATRIX*)0x1F8000F8;

    SetGeomOffset(160, 112);
    SetGeomScreen(544);
    matrix->m[0][0] = 4096;
    matrix->m[0][1] = 0;
    matrix->m[0][2] = 0;
    matrix->m[1][0] = 0;
    matrix->m[1][1] = 4096;
    matrix->m[1][2] = 0;
    matrix->m[2][0] = 0;
    matrix->m[2][1] = 0;
    matrix->m[2][2] = 4096;
    matrix->t[2] = 0;
    matrix->t[1] = 0;
    matrix->t[0] = 0;
    getBaseMatrix((MATRIX*)(&D_1F8000C0));
    camera->vrx= 0;
    camera->vry = 0;
    camera->vrz= -544;
    camera->vpx = 0;
    camera->vpy = 0;
    camera->vpz = 0;
    func_80024B3C((MATRIX*)(&D_1F800118));
    initDisplay(96U, 151U, 255U);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage(&rect, 0U, 0U, 0U);
    ClearOTagR(&OT_FRAMEBUFFER, 0x328);
    ClearOTagR(&OT_FRAMEBUFFER + 0x344, 0x328);
    *(short* )&PSX_SCRATCH[0x1F4] = 0;
    *(u_int** )&PSX_SCRATCH[0x1E0] = &OT_FRAMEBUFFER;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDisplay);
void initDisplay(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = (DRAWENV*)&D_8009D6C4;
    dispenv1 = (DISPENV*)((byte*)(&D_8009D6C4) - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)(&D_8009D6C4) + 0xD10);
    dispenv2 = (DISPENV*)((byte*)(&D_8009D6C4) + 0xD10 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 256, 320, 224);
    SetDefDispEnv(dispenv1, 704, 256, 320, 224);
    SetDefDrawEnv(drawenv2, 704, 256, 320, 224);
    SetDefDispEnv(dispenv2, 384, 256, 320, 224);
    setWH(&dispenv1->screen, 256, 224);
    setWH(&dispenv2->screen, 256, 224);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = false;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    setXY(&dispenv1->screen, D_8009C864, D_8009C866);
    setXY(&dispenv2->screen, D_8009C864, D_8009C866);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDisplay2x);
void initDisplay2x(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = (DRAWENV*)&D_8009D6C4;
    dispenv1 = (DISPENV*)((byte*)(&D_8009D6C4) - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)(&D_8009D6C4) + 0xD10);
    dispenv2 = (DISPENV*)((byte*)(&D_8009D6C4) + 0xD10 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 0, 640, 480);
    SetDefDispEnv(dispenv1, 384, 0, 640, 480);
    SetDefDrawEnv(drawenv2, 384, 0, 640, 480);
    SetDefDispEnv(dispenv2, 384, 0, 640, 480);
    setRECT(&dispenv1->screen, 0, 0, 256, 240);
    setRECT(&dispenv2->screen, 0, 0, 256, 240);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = true;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", compactOrderingTable);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initTasks);
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
        task->task_sp = 0x801FE400 + i * 0x800;   /* <- sem variavel `stack` */
        task++;
        tcb->reg[R_SR] = 0x40000404;
    }
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", dispatchTasks);
void dispatchTasks(void)
{
    int tid;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;

    *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4) = (u32*)TASK_TABLE;
    for (task = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4); task <= 0x801FD94FU; task = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4) = *(u32* )(&D_1F8000C0[0]+0x114) + sizeof(unkstruct_1F8001D4)) {
        tid = 2;
        switch ((u16)(*(unkstruct_1F8001D4** )((byte*)&D_1F8001A0+0x34))->unk0) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", startTask);
void startTask(s32 id, int fn)
{
    setTaskEntry((unkstruct_01*)(0x801FD80C + id * 0x70), fn);
    openTask(id, ((unkstruct_1F8001D4*)(TASK_TABLE + id * 0x70))->task_func);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", openTask);
void openTask(s32 arg0, long (*func)())
{
    int off = arg0 * sizeof(unkstruct_1F8001D4);

    ((unkstruct_1F8001D4*)(TASK_TABLE + off))->unk0 = 2;
    EnterCriticalSection();
    *(int*)(0x801FD804 + off) = OpenTh(func,
                                           *(int*)(0x801FD808 + off),
                                           *(int*)(0x801FD810 + off));
    ExitCriticalSection();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", sleepTask);
void sleepTask(s16 arg0)
{
    unkstruct_1F8001D4* task;

    task = CURRENT_TASK;
    task->unk2 = arg0;
    task->unk0 = 1;
    ChangeTh(DescTH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", exitTask);
void exitTask(void)
{
    (CURRENT_TASK)->unk0 = 0;
    EnterCriticalSection();
    CloseTh((*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->task_id);
    ExitCriticalSection();
    ChangeTh(DescTH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", closeTask);
void closeTask(s32 id)
{
    s32  off;
    u16* flag;

    off  = id * 0x70;
    flag = (u16*)(TASK_TABLE + off);

    if (*flag != 0) {
        *flag = 0;
        EnterCriticalSection();
        CloseTh(*(s32*)(0x801FD804 + off));
        ExitCriticalSection();
    }
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", setTask);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", setTaskFlag10);
void setTaskFlag10(s32 id)
{
    u16* p;

    p = (u16*)(TASK_TABLE + id * 0x70);
    *p |= 0x10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", clearTaskFlag10);
void clearTaskFlag10(s32 id)
{
    u16* p;

    p = (u16*)(TASK_TABLE + id * 0x70);
    *p &= ~0x10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", vblankHandler);
void vblankHandler(void)
{
    typedef inline struct {
        byte data[0x1E8];
        volatile u_short unk1E8;
        byte pad[0xC];
        u_short unk1F6;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;

    scratch->unk1E8++;
    scratch->unk1F6++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", tickTaskTimers);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", setTaskEntry);
void setTaskEntry(unkstruct_01* arg0, int arg1)
{
    DrawSync(0);
    arg0->unk0 = arg1;
    arg0->saved_reg_gp = GetGp();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", loadImageRect);
void loadImageRect(u_long* p, short x, short y, short w, short h)
{
    RECT rect;
    setRECT(&rect, x, y, w, h);
    LoadImage(&rect, p);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", loadTIM);
void loadTIM(u_long* address, short x, short y, short x2, short y2)
{
    TIM_IMAGE tim;
    TIM_IMAGE *pTim;

    pTim= &tim;
    if (OpenTIM(address)) {
        return;
    }
    if (ReadTIM(pTim) == NULL) {
        return;
    }
    pTim->prect->x = x;
    pTim->prect->y = y;
    pTim->crect->x = x2;
    pTim->crect->y = y2;
    if (((pTim->mode & 8) != 0) && ((x2 << 16) >= 0)) {
        LoadImage(pTim->crect, pTim->caddr);
    }
    if ((x << 16) >= 0) {
        LoadImage(pTim->prect, pTim->paddr);
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDrawLists);
void initDrawLists(void)
{
    func_80017CA0();
    func_80017D70();
    func_80017E44();
    func_80017EEC();
    func_80017F1C();
    func_80017F88();
    func_80017FB8();
    func_80018094();
    func_800180F0();
    func_8001811C();
    func_800180C4();
    func_80017CCC();
    func_800181F0();
    func_8001821C();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", resetDrawLists);
void resetDrawLists(void)
{
    *(int** )0x1F800218 = &D_800B0528;
    *(int** )0x1F80025C = &D_800B0528;
    *(int** )0x1F80021C = &D_800A5970;
    *(int** )0x1F800260 = &D_800A5970;
    *(int** )0x1F800220 = &D_800B0680;
    *(int** )0x1F800264 = &D_800B0680;
    *(int** )0x1F800224 = &D_800B0470;
    *(int** )0x1F800268 = &D_800B0470;
    *(int** )0x1F800230 = &D_800B3184;
    *(int** )0x1F800274 = &D_800B3184;
    *(int** )0x1F800228 = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    *(short* )0x1F80024E = 0;
    *(short* )0x1F800244 = 0;
    *(short* )0x1F800250 = 0;
    *(short* )0x1F800246 = 0;
    *(short* )0x1F800252 = 0;
    *(short* )0x1F80024A = 0;
    *(short* )0x1F800254 = 0;
    *(short* )0x1F80024C = 0;
    *(short* )0x1F800258 = 0;
    *(short* )0x1F800242 = 0;
    *(short* )0x1F800256 = 0;
    *(short* )0x1F800248 = 0;
    *(int** )0x1F80022C = &D_800A5858;
    *(int** )0x1F800270 = &D_800A5858;
    *(short* )0x1F80025A = 0;
    *(short* )0x1F800240 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", resetCamera);
void resetCamera(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    getBaseMatrix((MATRIX* ) D_1F8000C0);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -120;
    *(int* )0x1F800200 = 69;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    *(char* )0x1F8003CE = 0;
    *(short* )0x1F8001C8 = 0;
    *(char* )0x1F8003D1 = 0;
    *(u_char* )0x1F8003D2 = 0xFF;
    *(u_char* )0x1F8003D3 = 0xFF;
    D_8009EBA0 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initGameConfig);
void initGameConfig(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    memset((u_char *)&GAME, 0, sizeof(gameConfig));
    memset(&D_8009BC98, 0, 0x2C);
    getBaseMatrix((MATRIX* ) D_1F8000C0);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -120;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    *(int* )0x1F800200 = 69; // ?
    *(u_char* )0x1F8003D2 = 0xFF;
    *(u_char* )0x1F8003D3 = 0xFF;
    GAME.playerAP = 0;
    *&GAME.selectedArea = AREA00_VILLAGEOFALLBEGINNINGS;
    GAME.playerLives = 3;
    GAME.saveSlot = 0xFF;
    GAME.unk730 = 0xFF;
    *(char* )0x1F8003CE = 0; // INVENTORY ENABLED
    *(short* )0x1F8001C8 = 0; // SPRITE ZOOM
    *(char* )0x1F8003D1 = 0; 
    D_8009EBA0 = 0;
    GAME.selectedSection = AREA00_SECTION00_VILLAGEOFALLBEGINNINGS;
    GAME.inventoryScreen = INVENTORY_SCREEN_ITEM;
    GAME.unk13 = 1;
    GAME.unk54f = 1;
    GAME.event[EVENT_GRANDPASBRACELET] = 1;
    GAME.unk12 = 9;
    GAME.playerHealthDisplayed = 4;
    GAME.playerHealth = 4;
    GAME.unk670 = 0x5DA;
    GAME.unk672 = 0x639;
    GAME.unk674 = 0x691;
    GAME.unk5bc = D_8009E744;
    if (*(u8* )0x1F8001B3 == 0) {
        // 0 = NORMAL MODE | 1 = EASY MODE
        if (*(u8* )0x1F8001AB != 0) {
            GAME.inventory.slots[0] = ITEM_BLACKJACK;
            GAME.inventory.slots[1] = ITEM_GRAPPLE;
            GAME.inventory.slots[2] = ITEM_GRAPPLEJACK;
            GAME.inventory.slots[3] = ITEM_WOODBOOMERANG;
            GAME.inventory.slots[4] = ITEM_STONEBOOMERANG;
            GAME.inventory.slots[5] = ITEM_IRONBOOMERANG;
            GAME.inventory.slots[6] = ITEM_NORMALPANTS;
            GAME.inventory.slots[7] = ITEM_JUMPINGPANTS;
            GAME.inventory.slots[8] = ITEM_DASHINGPANTS;
            GAME.inventory.slots[9] = ITEM_FLASHPANTS;
            GAME.inventory.slots[10] = ITEM_100YEAROLDBELL;
            GAME.inventory.slots[11] = ITEM_100YEAROLDKEY;
            GAME.inventory.slots[12] = ITEM_1000YEAROLDKEY;
            GAME.inventory.slots[13] = ITEM_FUNKYPARASOL;
            GAME.inventory.counter = 14;
            GAME.item[ITEM_BLACKJACK] = 1;
            GAME.item[ITEM_GRAPPLE] = 1;
            GAME.item[ITEM_GRAPPLEJACK] = 1;
            GAME.item[ITEM_WOODBOOMERANG] = 1;
            GAME.item[ITEM_STONEBOOMERANG] = 1;
            GAME.item[ITEM_IRONBOOMERANG] = 1;
            GAME.item[ITEM_DASHINGPANTS] = 1;
            GAME.item[ITEM_NORMALPANTS] = 1;
            GAME.item[ITEM_JUMPINGPANTS] = 1;
            GAME.item[ITEM_FLASHPANTS] = 1;
            GAME.item[ITEM_100YEAROLDBELL] = 1;
            GAME.item[ITEM_100YEAROLDKEY] = 1;
            GAME.item[ITEM_1000YEAROLDKEY] = 1;
            GAME.item[ITEM_FUNKYPARASOL] = 1;
            GAME.inventory.sortMode = SORT_MODE_DEFAULT;
        } else {
            GAME.inventory.slots[0] = ITEM_BLACKJACK;
            GAME.inventory.slots[1] = ITEM_NORMALPANTS;
            GAME.inventory.counter = 2;
            GAME.item[ITEM_BLACKJACK] = 1;
            GAME.item[ITEM_NORMALPANTS] = 1;
            GAME.inventory.sortMode = SORT_MODE_DEFAULT;
        }
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initHud);
void initHud(void)
{
    char *tmp;

    memset(&D_8009BC98, 0, 0x2C);
    *(s16* )0x1F8001C6 = 0;
    GAME.fadeScreenControl = 1;
    *(s8* )0x1F8003D0 = 0;
    GAME.playerIdleState = 0;
    func_80018F04();
    func_80020CB0();
    
    tmp = D_800B07AC;
    *tmp++ = (GAME.playerAP / 10000000) % 10;
    *tmp++ = (GAME.playerAP / 1000000 ) % 10;
    *tmp++ = (GAME.playerAP / 100000  ) % 10;
    *tmp++ = (GAME.playerAP / 10000   ) % 10;
    *tmp++ = (GAME.playerAP / 1000    ) % 10;
    *tmp++ = (GAME.playerAP / 100     ) % 10;
    *tmp++ = (GAME.playerAP / 10      ) % 10;
    *tmp++ = (GAME.playerAP / 1       ) % 10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017CA0);
void func_80017CA0(void)
{
    memset(&D_800A5398, 0, 0x178);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017CCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017E44);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017EEC);
void func_80017EEC(void)
{
    *(int* )0x1F80021C = &D_800A5970;
    *(int* )0x1F800260 = &D_800A5970;
    *(short* )0x1F800250 = 0;
    *(short* )0x1F800246 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017F1C);
void func_80017F1C(void)
{
    s32 i;
    s32 off;

    *(s32** )0x1F800264 = *(s32** )0x1F800220 = &D_800B0680;
    *(s16* )0x1F80024A = *(s16* )0x1F800252 = 0;
    for (i = 7; 0 <= i; --i) {
        off = i * 0x8C;
        *(s16*)&D_800A3348[off] = 0xFFFF;
    }
    func_80018D7C();
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017F88);
void func_80017F88(void)
{
    *(int** )0x1F800224 = &D_800B0470;
    *(int** )0x1F800268 = &D_800B0470;
    *(short* )0x1F800254 = 0;
    *(short* )0x1F80024C = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017FB8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018094);
void func_80018094(void)
{
    *(int** )0x1F800228 = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    *(short* )0x1F800256 = 0;
    *(short* )0x1F800248 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800180C4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800180F0);
void func_800180F0(void)
{
    memset(&D_800B00F8, 0, 0x16C);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001811C);

void func_800181F0(void)
{
    memset(&D_800B0770, 0, 0x68);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001821C);
void func_8001821C(void)
{
    memset(&D_800A3940, 0, 0x70);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800182C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018354);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", allocObjectLayer3);
void* allocObjectLayer3(void)
{
    typedef inline struct {
        byte data[0x1C8];
        u_short unk1C8;
        byte pad0[0x3E];
        void** unk208;
        byte pad1[0x2C];
        short unk238;
    } scratchpad;

    typedef inline struct {
        byte data[0x1C];
        byte unk1C;
        byte pad0[0x23];
        void* unk40;
        void* unk44;
    } unkstruct_800183E4;

    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_800183E4* obj;
    u_char layer = 3;

    if (scratch->unk238 > 0) {
        scratch->unk238 -= 1;
        obj = *scratch->unk208++;
        obj->unk1C = layer;

        if ((scratch->unk1C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018504);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018594);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800186E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001872C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800187D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018828);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001887C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800188D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001891C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/main", D_80010000);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/main", D_80010008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018954);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018BC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D40);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D7C);
void func_80018D7C(void)
{
    int u;
    int v;

    int i;
    
    u = 0;
    v = 0x6A;
    
    for (i = 0; i < 60; i++) {
        D_800A5140[i].val[0] = u;
        D_800A5140[i].unk0 = -1;
        D_800A5140[i].unk2 = 0;
        D_800A5140[i].val[1] = v;
        D_800A5140[i].val[2] = 4;
        D_800A5140[i].val[3] = 16;
        D_800A5140[i].val[4] = 0;
        D_800A5140[i].val[5] = 0;

        u += 4;
        
        if (u >= 61) {
            u = 0;
            v += 16;
        }
    }
    for (i=0; i < 8; i+=2) {
        D_800A39B0[i].unk0 = -1;
        D_800A39B0[i].unk2 = -1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018E58);
void func_80018E58(void)
{
    int u;
    int v;

    int i;
    
    u = 0;
    v = 0x9E;
    
    for (i = 0; i < 48; i++) {
        D_800AFF18[i].val[0] = u;
        D_800AFF18[i].unk0 = -1;
        D_800AFF18[i].unk2 = 0;
        D_800AFF18[i].val[1] = v;
        D_800AFF18[i].val[2] = 4;
        D_800AFF18[i].val[3] = 24;
        D_800AFF18[i].val[4] = 0;
        D_800AFF18[i].val[5] = 0;

        u += 4;
        
        if (u >= 60) {
            u = 0;
            v += 24;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018F04);
void func_80018F04(void) {
    int u;
    int p;

    if (D_8009CA04 == 0) return;
    p = &D_8009EBA8;
    func_8003B478(p);
            
    switch(GAME.selectedArea&0xFFFF) {
        case AREA00_VILLAGEOFALLBEGINNINGS:
            switch (GAME.selectedSection) {
                case AREA00_SECTION00_VILLAGEOFALLBEGINNINGS:
                case AREA00_SECTION01_FORESTOFALLBEGINNINGS:
                case AREA00_SECTION02_FORESTOFALLBEGINNINGSHUTENTRANCE:
                    u = *(int* )0x1F8002B8;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
            }
            break;
        case AREA01_DWARFFOREST:
            switch (GAME.selectedSection) {
                 case AREA01_SECTION00_FORESTOF100FLOWERS:
                 case AREA01_SECTION01_FORESTOF100FLOWERSRIGHTENTRANCE:
                 case AREA01_SECTION02_WOBBLYWHARF:
                 case AREA01_SECTION03_WATCHTOWER:
                 case AREA01_SECTION04_CHARITYSQUARE:
                    u = *(int* )0x1F8002B8;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
            }
            break;
        case AREA02_DWARFVILLAGE:
            switch(GAME.selectedSection) {
                case AREA02_SECTION00_DWARFVILLAGE:
                    u = *(int* )0x1F8002BC;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
                 case AREA02_SECTION01_DWARFELDERSHUT:
                 case AREA02_SECTION02_UNDERGROUNDPRISON:
                    u = *(int* )0x1F8002B8;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
            }
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019020);
void memCardInit(void)
{
    EnterCriticalSection();
    MEMCARD_SW_END_IO = OpenEvent(SwCARD, EvSpIOE, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_END_ERROR = OpenEvent(SwCARD, EvSpERROR, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_TIMEOUT = OpenEvent(SwCARD, EvSpTIMOUT, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_NEW_DEVICE = OpenEvent(SwCARD, EvSpNEW, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_END_IO = OpenEvent(HwCARD, EvSpIOE, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_END_ERROR = OpenEvent(HwCARD, EvSpERROR, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_TIMEOUT = OpenEvent(HwCARD, EvSpTIMOUT, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_NEW_DEVICE = OpenEvent(HwCARD, EvSpNEW, EvMdNOINTR, EvStUNUSED);
    InitCARD(0);
    ExitCriticalSection();
    StartCARD();
    _bu_init();
    EnableEvent(MEMCARD_SW_END_IO);
    EnableEvent(MEMCARD_SW_END_ERROR);
    EnableEvent(MEMCARD_SW_TIMEOUT);
    EnableEvent(MEMCARD_SW_NEW_DEVICE);
    EnableEvent(MEMCARD_HW_END_IO);
    EnableEvent(MEMCARD_HW_END_ERROR);
    EnableEvent(MEMCARD_HW_TIMEOUT);
    EnableEvent(MEMCARD_HW_NEW_DEVICE);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", bootSequenceTask);
void bootSequenceTask(void)
{
    u16 state;
    unkstruct_1F8001D4* task5;
    unkstruct_1F8001D4* task6;
    unkstruct_1F8001D4* task7;
    unkstruct_1F8001D4* task8;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;
    unkstruct_1F8001D4* task4;
    unkstruct_1F8001D4* task9;

    D_8009D6DD = 0;
    D_8009D6DE = 0;
    D_8009D6DF = 0;
    D_8009E3ED = 0;
    D_8009E3EE = 0;
    D_8009E3EF = 0;
    *(s8* )0x1F8001D1 = 0;
    *(s8* )0x1F8001D0 = 0;
    D_8009E744 = 0;
    D_8009C9E4 = 1;
    D_8009E450 = 0;
    func_80023A3C();
    task = CURRENT_TASK;
    task->state0 = 9U;
    task->state1 = 0U;
    task->state2 = 0;
    SetDispMask(0);
    do {
        state = (CURRENT_TASK)->state0;
        switch (state) {
            case 0:
                *(u8* )0x1F8001CE = 0;
                func_800223A0(0);
                func_800223A0(1);
                func_800222B8(0, 1);
                *(s8* )0x1F8001C4 = 0;
                *(s8* )0x1F8001C5 = 0;
                memset(&D_1F8001A0, 0, 0x24);
                task9 = CURRENT_TASK;
                task9->state0++;
                break;
            case 1:
                if (*(u8* )0x1F8001CE != 0) {
                    cdSeekStream(0x15);
                    (CURRENT_TASK)->state0 = 4U;
                }
                break;
            case 2:
                SetDispMask(1);
                task5 = CURRENT_TASK;
                task5->timer = 120;
                task5->state0++;
                break;
            case 3:
                task7 = CURRENT_TASK;
                *(s32* )0x1F800164 = (s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
                task7->timer--;
                if ((s16) task7->timer == -1) {
                    task7->state0++;
                }
                fontDebugPrintf(0x50, 0x60, 0, &D_80010000);
                fontDebugPrintf(0x50, 0x70, 0, &D_80010008);
                break;
            case 4:
                task2 = CURRENT_TASK;
                task2->state0 = 0U;
                task2->state1 = 1U;
                task2->state2 = 0;
                setTask((s32*)titleSequenceTask);
                break;
            case 9:
                SetDispMask(0);
                *(byte* )0x1F8001CE = 0U;
                func_800222B8(0x5E, 1);
                (CURRENT_TASK)->state0 = 0xAU;
                break;
            case 10:
                if (*(u8* )0x1F8001CE != 0) {
                    SetDispMask(0);
                    initDisplay2x(0U, 0U, 0U);
                    SetDispMask(1);
                    task3 = CURRENT_TASK;
                    task3->timer = 240;
                    task3->state0 = 0xBU;
                    task3->state1 = 0U;
                }
                break;
            case 11:
                task8 = CURRENT_TASK;
                *(int* )0x1F800164 = (s32) ((s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF);
                switch (task8->state1) {                    // switch 1; irregular
                    case 0:                             // switch 1
                        task8->unk5A = 1U;
                        task8->state1++;
                        break;
                    case 1:                             // switch 1
                        task8->unk5A++;
                        if ((s16) task8->unk5A >= 0x80) {
                            task8->timer = 0xB4U;
                            task8->state1++;
                            break;
                        }
                        break;
                    case 2:                             // switch 1
                        task8->timer--;
                        if ((s16) task8->timer == -1) {
                            task8->state1++;
                        }
                        break;
                    case 3:                             // switch 1
                        task8->unk5A--;
                        if ((s16)task8->unk5A == 0) {
                            SetDispMask(0);
                            initDisplay(0U, 0U, 0U);
                            task4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            *(byte* )0x1F8001D1 = 0;
                            *(s16* )0x1F8001F6 = 0;
                            task4->state0 = 0U;
                            task4->state1 = 0U;
                        }
                        break;
                }
                task6 = CURRENT_TASK;
                if (*(u16*)&task6->state0 == 0xB) {
                    func_8001964C((u8) task6->unk5A, 1);
                }
                break;
        }
        sleepTask(1);
    } while(true);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001964C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", titleSequenceTask);
void titleSequenceTask(void)
{
        typedef inline struct {
        byte data[0x1CC];
        byte unk1CC;
        byte unk1CD;
        byte unk1CE;
        byte unk1CF;
        byte unk1D0;
        byte unk1D1;
        byte unk1D2;
        byte unk1D3;
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = *(unkstruct_1F8001D4**)scratch->unk1D4;

    u32 sp10[2];
    u16 state;

    *(s8* )&scratch->unk1D1 = 1;
    *(s8* )&scratch->unk1D0 = 0;
    sp10[0] = 0;
    scratch->unk1D4->titleScreenSelectedOption = 0;
    while(true) {
        *(u16* )0x1F8001F8 = *(u16* )(D_1F8000F8+0x100) + 1;
        asm("");
        func_800223E0();
        task = CURRENT_TASK;
        state = task->state0;
        if ((state >= 3U) && (*(u16* )0x1F8001FC & (JOY_CROSS | JOY_START)) && (state != 4)) {
            task->state0 = 4U;
            task->state1 = 0;
            task->state2 = 0;
            sp10[0] = 1;
            func_80020C00(0);
            if (*(u8* )0x1F8001CC != 0) {
                *(s8* )0x1F8001D3 = 1;
            }
        }
        switch ((u16)(CURRENT_TASK)->state0) {
            case 0:
                func_800199B8(sp10);
                break;
            case 1:
                func_80019CA4();
                break;
            case 2:
                func_8001A328();
                break;
            case 3:
                func_80019D78();
                break;
            case 4:
                loopTitleScreen(sp10);
                break;
        }
        sleepTask(1);
    };
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800199B8);
void func_800199B8(void)
{
    u16 state2;
    u16 timer;
    u16 state1;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;
    unkstruct_1F8001D4* task4;
    unkstruct_1F8001D4* task5;
    unkstruct_1F8001D4* task6;
    unkstruct_1F8001D4* task7;
    unkstruct_1F8001D4* task8;

    state1 = (CURRENT_TASK)->state1;
    switch (state1) {
        case 0:
            task3 = CURRENT_TASK;
            state2 = task3->state2;
            switch (state2) {                      // switch 1; irregular
                case 0:                             // switch 1
                    SetDispMask(0);
                    *(u8* )0x1F8001CE = 0U;
                    func_800223A0(1);
                    func_800222B8(1, 1);
                    task4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                    task4->state2++;
                    return;
                case 1:                             // switch 1
                    if (*(u8* )0x1F8001CE != 0) {
                        task3->state1 = 2U;
                        task3->state2 = 0U;
                        func_800E7D5C();
                        return;
                    }
                default:
                    return;
            }
            break;
        case 1:
            SetDispMask(0);
            func_800E7D5C();
            task5 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            task5->state1++;
            return;
        case 2:
            task2 = CURRENT_TASK;
            *(u8* )0x1F8001CC = 1;
            *(s8* )0x1F8001CD = 0x15;
            task2->state1++;
            openTask(1, moviePlayerTask);
            return;
        case 3:
            if (*(u8* )0x1F8001CC != 0) {
                return;
            }
            task5 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            task5->state1++;
            return;
        case 4:
            SetDispMask(0);
            initDisplay2x(240U, 240U, 240U);
            SetDispMask(1);
            *(s32* )0x1F800164 = (s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
            func_800E7D74();
            task = CURRENT_TASK;
            task->timer = 120;
            task->state1++;
            return;
        case 5:
            *(s32* )0x1F800164 = (s32) ((s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF);
            func_800E7D74();
            task6 = CURRENT_TASK;
            timer = task6->timer - 1;
            task6->timer = timer;
            if ((timer << 0x10) <= 0) {
                func_80020C00(0);
                SetDispMask(0);
                initDisplay(0U, 0U, 0U);
                *(u8* )0x1F8001CE = 0U;
                func_800223A0(2);
                func_800222B8(2, 1);
                task5 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                task5->state1++;
                return;
            }
            break;
        case 6:
            if (*(u8* )0x1F8001CE != 0) {
                task7 = CURRENT_TASK;
                task7->state1++;
                cdSeekStream(0);
                return;
            }
            break;
        case 7:
            task8 = CURRENT_TASK;
            task8->state0 = 3;
            task8->state1 = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019CA4);
void func_80019CA4(void)
{
    typedef inline struct {
        byte data[0x1CC];
        byte unk1CC;
        byte unk1CD;
        byte unk1CE;
        byte unk1CF;
        byte pad[0x4];
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    
    unkstruct_1F8001D4* task2;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = scratch->unk1D4;

    switch (task->state1) {                              // irregular
        case 0:
            SetDispMask(0);
             *(u8* )&scratch->unk1CE = 0;
            func_800223A0(2);
            func_800222B8(2, 1);
            scratch->unk1D4->state1++;
            return;
        case 1:
            if (*(u8* )&scratch->unk1CE != 0) {
                task->state1++;
                cdSeekStream(0);
                return;
            }
            return;
        case 2:
            task2 = *(u_long**)&scratch->unk1D4;
            task2->state0 = 4;
            task2->state1 = 0;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019D78);
void func_80019D78(void)
{
    typedef inline struct {
        byte data[0x1CC];
        byte unk1CC;
        byte unk1CD;
        byte unk1CE;
        byte unk1CF;
        byte pad[0x4];
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    
    u8 temp_v0;
    unkstruct_1F8001D4* task2;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = scratch->unk1D4;
    
    switch (task->state1) {
        case 0:
            SetDispMask(0);
            initDisplay(0U, 0U, 0U);
            *(u8* )&scratch->unk1CC = 1;
            *(s8* )&scratch->unk1CD = 0;
            scratch->unk1D4->state1 ++;
            openTask(1, &moviePlayerTask);
            break;
        case 1:
            temp_v0 = *(u_long**)&scratch->unk1CC;
            if (temp_v0 == 0) {
                task->state1++;
                return;
            }
            break;
        case 2:
            func_80020C00(0);
            task2 = *(u_long**)&scratch->unk1D4;
            task2->state0 = 4;
            task2->state1 = 0;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", loopTitleScreen);
void loopTitleScreen(int* arg0)
{
    int amount;
    unkstruct_1F8001D4* gameControl;
    unkstruct_1F8001D4* gameControlTemp;
    unkstruct_1F8001D4* gameControlTemp2;
    unkstruct_1F8001D4* gameControlTemp3;
    unkstruct_1F8001D4* gameControlTemp4;
    unkstruct_1F8001D4* gameControlTemp5;
    unkstruct_1F8001D4* gameControlTemp6;
    unkstruct_1F8001D4* gameControlTemp7;

    switch ((CURRENT_TASK)->state1) {
        case 0:
            SetDispMask(0);
            gameControl = CURRENT_TASK;
            gameControl->state2 = 0U;
            gameControl->state1++;
        case 1:
            if (*(u_char* )0x1F8001CC == 0) {
                initDisplay(0U, 0U, 0U);
                gameControl = CURRENT_TASK;
                gameControl->state1++;
                return;
            }
        default:
            return;
        case 2:
            func_800E7DA4();
            SetDispMask(1);
            func_80020AF0(0);
            printTitleScreenMessage(48, 192, TITLESCREEN_MESSAGE_WHOOPCAMPCOPYRIGHT);
            (CURRENT_TASK)->titleScreenSelectedOption = TITLESCREEN_NEWGAME;
            gameControl = (*(unkstruct_1F8001D4** )((byte*)&D_1F8001A0+0x34));
            gameControl->unk6A = (u_char) (&D_80076E80)[gameControl->titleScreenSelectedOption];
            gameControl = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
            gameControl->unk6B = (u_char) (&D_80076E80)[gameControl->titleScreenSelectedOption];
            gameControlTemp = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            gameControlTemp->timer = 972;
            gameControlTemp->state1++;
            return;
        case 3:
            gameControlTemp5 = *(unkstruct_1F8001D4** )((byte*)&D_1F8001A0+0x34);
            *(int* )0x1F800164 = (int) ((*(short* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
            gameControlTemp5->timer--;
            if ((short)gameControlTemp5->timer <= 0) {
                gameControlTemp5->state1++;
            }
            func_800E7DDC(arg0);
            if (*&D_8009C9D8 != 0) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->timer = 972;
            }
            gameControlTemp2 = CURRENT_TASK;
            switch ((u_short)gameControlTemp2->state2) {                    // switch 1; irregular
                case 0:                             // switch 1
                    if (*(u_short* )0x1F8001FC & JOY_LEFT) {
                        if (gameControlTemp2->titleScreenSelectedOption != 0) {
                            gameControlTemp2->titleScreenSelectedOption--;
                            gameControl = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                            gameControl->unk6B = (u_char) (&D_80076E80)[gameControl->titleScreenSelectedOption];
                            gameControl = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            gameControl->state2++;
                            playSFX(8);
                        }
                    }
                    if (*(u_short* )0x1F8001FC & JOY_RIGHT) {
                        gameControlTemp3 = CURRENT_TASK;;
                        if (gameControlTemp3->titleScreenSelectedOption < 2U) {
                            gameControlTemp3->titleScreenSelectedOption++;
                            gameControl = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                            gameControl->unk6B = (u_char) (&D_80076E80)[gameControl->titleScreenSelectedOption];
                            gameControl = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            gameControl->state2++;
                            playSFX(8);
                        }
                    }
                    if (*(u_short* )0x1F8001FC & (JOY_CROSS | JOY_START)) {
                        func_80020C00(0);
                        gameControlTemp6 = CURRENT_TASK;
                        switch (gameControlTemp6->titleScreenSelectedOption) {       // switch 2; irregular
                            case TITLESCREEN_NEWGAME:                 // switch 2
                                gameControlTemp6->loadGameSelected = 0;
                                playSFXAndSetNote(10, 10);
                                setTask(func_8001A51C);
                                break;
                            case TITLESCREEN_LOADGAME:                 // switch 2
                                gameControlTemp6->loadGameSelected = 1;
                                playSFXAndSetNote(10, 10);
                                setTask(func_8001A51C);
                                break;
                            case TITLESCREEN_OPTIONS:                 // switch 2
                                gameControlTemp6->state0 = 2;
                                gameControlTemp6->state1 = 0U;
                                playSFXAndSetNote(10, 10);
                                break;
                        }
                    }
                    break;
                case 1:                             // switch 1
                    if (gameControlTemp2->unk6A != gameControlTemp2->unk6B) {
                        amount = -4;
                        if (gameControlTemp2->unk6A < gameControlTemp2->unk6B) {
                            amount = 4;
                        }
                        gameControlTemp2->unk6A += amount;
                        gameControlTemp4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                        if (gameControlTemp4->unk6B == gameControlTemp4->unk6A) {
                            gameControlTemp4->state2--;
                        }
                    }
                    break;
            }
            printTitleScreenMessage(48, 192, TITLESCREEN_MESSAGE_WHOOPCAMPCOPYRIGHT);
            if (*(u_short* )0x1F8001F8 & 0x20) {
                printTitleScreenMessage(56, 144, TITLESCREEN_MESSAGE_PRESSSTART);
            }
            gameControlTemp7 = CURRENT_TASK;
            func_800E8E78(gameControlTemp7->unk6A, gameControlTemp7->titleScreenSelectedOption);
            func_8001F6D4();
            return;
        case 4:
            func_80020C00(0);
            *arg0 = 0;
            gameControl = CURRENT_TASK;
            gameControl->state0 = 3;
            gameControl->state1 = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A328);
void func_8001A328(void)
{
    u_short state2;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;

    *(int* )0x1F800164 = (int) ((*(short* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
    switch ((CURRENT_TASK)->state1) {
        case 0:
            func_80020C00(0);
            SetDispMask(0);
            *(u_char* )0x1F8001CE = 0;
            func_800223A0(3);
            func_800222B8(8, 1);
            (CURRENT_TASK)->state1++;
            return;
        case 1:
            if (*(u_char* )0x1F8001CE != 0) {
                SetDispMask(1);
                func_800E75C4();
                func_80020AF0(0);
                task2 = CURRENT_TASK;
                task2->state2 = 0U;
                (CURRENT_TASK)->state1++;
                return;
            }
        default:
            return;
        case 2:
            task = CURRENT_TASK;
            state2 = task->state2;
            switch (state2) {                    // switch 1; irregular
                case 0:                             // switch 1
                    task->unk4E.value = 0;
                    task->state2++;
                    // fallthrough
                case 1:                             // switch 1
                    if (func_800E75CC(task) != 0) {
                    (CURRENT_TASK)->state1++;
                    return;
                    }
                    break;
                case 2:                             // switch 1
                    func_800E7960(task);
                    return;
                case 3:                             // switch 1
                    func_800E7A48(task);
                    return;
            }
            break;
        case 3:
            func_80020C00(0);
            SetDispMask(0);
            *(u_char* )0x1F8001CE = 0U;
            func_800223A0(2);
            func_800222B8(2, 1);
            (CURRENT_TASK)->state1++;
            return;
        case 4:
            if (*(u_char* )0x1F8001CE != 0) {
                task3 = CURRENT_TASK;
                task3->state0 = 4;
                task3->state1 = 0U;
            }
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A51C);
void func_8001A51C(void)
{
    typedef inline struct {
        byte data[0x1CE];
        char unk1CE;
        char unk1CF;
        char unk1D0;
        char unk1D1;
        char unk1D2;
        char unk1D3;
        char unk1D4;
        char pad[6];
        short unk1DC;
        short unk1DE;
        char pad2[28];
        short unk1FC;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = *(unkstruct_1F8001D4**)&scratch->unk1D4;
    int state;

    scratch->unk1D1 = 0;
    scratch->unk1D0 = 1;
    task->state0 = 0;
    task->state1 = 0;
    task->state2 = 0;
    task->unk4E.value = 0;
    task->unk6A = 0;
    setRGB0((DRAWENV*)&D_8009D6C4, 0, 0, 0);
    setRGB0((DRAWENV*)D_8009E3D4, 0, 0, 0);
    scratch->unk1DC = -1;
    scratch->unk1DE = 0;
    D_8009EB4C = 0;
    scratch->unk1CE = 0;
    D_8009EBA0 = 0;
    func_80024B3C(D_1F800118);
    scratch->unk1FC  = 0;
    while (true){
        func_800223E0();
        state = (CURRENT_TASK)->state0;
        switch ((u_short)state) {
            case 0:
                func_8001A670(); // New Game
                break;
            case 1:
                func_8001A954(); // Debug
                break;
            case 2:
                func_8001A774(); // Load Game
                break;
        }
        sleepTask(1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A670);
void func_8001A670(void)
{

    typedef inline struct {
        byte data[0x1CF];
        byte unk1CF;
        byte pad[0x4];
        byte unk1D4;
    } scratchpad;
    
    RECT rect;
    s16 var_v0;
    u16 timer;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = *(u_long**)&scratch->unk1D4;

    switch (task->state1) {                              // irregular
        case 0:
            task->unk5A = 1U;
            task->state1 += 1;
            setRECT(&rect, 0, 0, 64, 256);
            ClearImage((RECT* ) &rect, 0U, 0U, 0U);
            initGameConfig();
            scratch->unk1CF = 0;
            return;
        case 1:
            timer = task->unk5A - 1;
            task->unk5A = timer;
            if ((short)timer <= 0) {
                task->state1 += 1;
                return;
            }
            return;
        case 2:
            task->state2 = 0;
            task->unk4E.value = 0;
            if (task->loadGameSelected != 0) {
                var_v0 = 2;
            } else {
                var_v0 = 1;
                asm("");
            }
            task->state0 = var_v0;
            task->state1 = 0U;
            break;
    }
}
