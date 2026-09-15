#include "common.h"
#include "game.h"
//#include "psyq/libcd.h"

#define D_8009B034 ((DISPENV*)((byte*)&D_8009B010+0x24))
#define D_8009B01C ((u_long*)((byte*)&D_8009B010+0xC))

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021340);
// #define CD_REQ   (*(u8**)0x1F800288)   /* entrada corrente da fila */
// #define CD_HDR   (*(s16**)0x1F80028C)  /* cabecalho do arquivo */
// #define CD_DST   (*(u8**)0x1F800290)   /* destino da leitura */
// #define CD_NSEC  (*(s32*)0x1F800294)   /* setores a ler */
// #define CD_HEAD  (*(s32*)0x1F80029C)
// #define CD_TAIL  (*(s32*)0x1F8002A0)
// #define CD_FLAGS (*(s32*)((u8*)CD_HDR + 0x10))

// void func_80021340(void)
// {
//     RECT    rect;
//     u_char  param[40];
//     s32     i;
//     s32     r;
//     s32     base;
//     s32     nvag;
//     s32     nprog;
//     s32     tail;
//     s32     head;
//     s32     id;
//     s32     flags;
//     u32     spuAddr;
//     u32     len;
//     u8*     vagTop;
//     u8*     progTop;
//     u8*     vagCur;
//     u8*     progCur;
//     u8*     a;
//     u8*     b;
//     u8*     entry;
//     s16*    hdr;
//     s16     vabId;

//     LOAD_COMPLETE = 0;
//     D_8009C8B0 = 0;
//     param[0] = 0x80;
//     CURRENT_TASK->state0 = 0;
//     CURRENT_TASK->state1 = 0;
//     while (CdControl(14, param, 0) == 0) {
//     }

//     for (;;) {
//         switch ((u16)CURRENT_TASK->state0) {
//         case 0:
//             if (CD_HEAD == CD_TAIL) {
//                 break;
//             }
//             CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//             break;

//         case 1:
//             entry = (u8*)(&D_8009E748 + CD_TAIL * 2);
//             hdr = *(s16**)entry;
//             id = *hdr;
//             CD_REQ = entry;
//             CD_HDR = hdr;
//             CdControlF(2, (u8*)&D_800791A0 + (id * 8));
//             CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//             break;

//         case 2:
//             r = CdSync(1, 0);
//             if (r == 2) {
//                 CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//             } else if (r == 5) {
//                 CURRENT_TASK->state0 = 1;
//                 D_8009C8B0++;
//             }
//             break;

//         case 3:
//             flags = CD_FLAGS;
//             CD_NSEC = (u32)((&D_800791A4)[*CD_HDR * 2] + 0x7FF) >> 11;
//             switch (flags & 0xF) {
//             case 0:
//             case 3:
//                 if (CD_FLAGS & 0x10) {
//                     CD_DST = (u8*)&D_800B3188;
//                 } else {
//                     CD_DST = D_800A3348;
//                 }
//                 break;
//             case 1:
//             case 2:
//             case 4:
//                 CD_DST = *(u8**)(CD_REQ + 4);
//                 break;
//             }
//             if (CdRead(CD_NSEC, (u_long*)CD_DST, 0x80) == 0) {
//                 D_8009C8B0++;
//             } else {
//                 CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//             }
//             break;

//         case 4:
//             r = CdReadSync(1, 0);
//             if (r == 0) {
//                 CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//             } else if (r == -1) {
//                 CURRENT_TASK->state0 = 1;
//                 D_8009C8B0++;
//             }
//             break;

//         case 5:
//             switch ((u16)CURRENT_TASK->state1) {
//             case 0:
//                 switch (CD_FLAGS & 0xF) {
//                 case 0:
//                     switch (*((u8*)CD_HDR + 3) & 0xF0) {
//                     case 0x10:
//                         CURRENT_TASK->state1 = 2;
//                         break;
//                     case 0x90:
//                         CURRENT_TASK->state1 = 5;
//                         break;
//                     }
//                     break;
//                 case 1:
//                     CURRENT_TASK->state1 = (u16)CURRENT_TASK->state1 + 1;
//                     break;
//                 case 2:
//                 case 4:
//                     if ((*((u8*)CD_HDR + 3) & 0xF0) == 0x90) {
//                         CURRENT_TASK->state1 = 5;
//                         break;
//                     }
//                     CURRENT_TASK->state1 = 0;
//                     CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//                     break;
//                 case 3:
//                     CURRENT_TASK->state1 = 4;
//                     break;
//                 }
//                 break;

//             case 1:
//                 if (CD_FLAGS & 0x10) {
//                     lzDecompress(*(u8**)(CD_REQ + 4), (u8*)&D_800B3188);
//                 } else {
//                     lzDecompress(*(u8**)(CD_REQ + 4), D_800A3348);
//                 }
//                 CURRENT_TASK->state1 = (u16)CURRENT_TASK->state1 + 1;
//                 /* fallthrough */
//             case 2:
//                 rect.x = CD_HDR[4];
//                 rect.y = CD_HDR[5];
//                 rect.w = CD_HDR[6];
//                 rect.h = CD_HDR[7];
//                 if (CD_FLAGS & 0x10) {
//                     LoadImage(&rect, (u_long*)&D_800B3188);
//                 } else {
//                     LoadImage(&rect, (u_long*)D_800A3348);
//                 }
//                 CURRENT_TASK->state1 = (u16)CURRENT_TASK->state1 + 1;
//                 break;

//             case 3:
//                 DrawSync(0);
//                 CURRENT_TASK->state1 = 0;
//                 CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//                 break;

//             case 4:
//                 if (CD_FLAGS & 0x10) {
//                     lzDecompress((u8*)&D_800B3188, *(u8**)(CD_REQ + 4));
//                 } else {
//                     lzDecompress(D_800A3348, *(u8**)(CD_REQ + 4));
//                 }
//                 CURRENT_TASK->state1 = 0;
//                 CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//                 break;

//             case 5:
//                 base = *((u8*)CD_HDR + 3) & 0xF;
//                 if (base == 0xF) {
//                     base = 0;
//                 }
//                 a = *(u8**)(CD_REQ + 4);
//                 vagTop = a + *(s32*)(a + 4);
//                 progTop = a + *(s32*)a;
//                 len = (u32)*(s32*)progTop;
//                 vagCur = vagTop;
//                 progCur = progTop;
//                 nvag = ((u32)*(s32*)vagCur >> 2) - 1;
//                 nprog = (len >> 2) - 1;

//                 i = 0;
//                 if (nvag > 0) {
//                     do {
//                         vabId = (&D_1F8003A8)[base + i];
//                         if (vabId != -1) {
//                             SsVabClose(vabId);
//                         }
//                         i++;
//                     } while (i < nvag);
//                 }

//                 i = 0;
//                 if (nvag > 0) {
//                     do {
//                         (&D_8009C758)[base + i] = (s32)(vagTop + *(s32*)vagCur);
//                         i++;
//                         vagCur += 4;
//                     } while (i < nvag);
//                 }

//                 i = 0;
//                 if (nprog > 0) {
//                     do {
//                         (&D_8009C658)[base + i] = (s32)(progTop + *(s32*)progCur);
//                         i++;
//                         progCur += 4;
//                     } while (i < nprog);
//                 }

//                 spuAddr = (&D_80077D50)[CD_HDR[7] * 2];
//                 i = 0;
//                 if (nvag > 0) {
//                     do {
//                         if (i == (nvag - 1)) {
//                             a = (u8*)(&D_8009C658)[base + i];
//                             b = progTop + *(s32*)progCur;
//                         } else {
//                             b = (u8*)(&D_8009C65C)[base + i];
//                             a = (u8*)(&D_8009C658)[base + i];
//                         }
//                         len = b - a;
//                         SpuSetTransferStartAddr(spuAddr);
//                         SpuRead((u_char*)(&D_8009C658)[base + i], len);
//                         SpuIsTransferCompleted(1);
//                         vabId = SsVabFakeHead((u_char*)(&D_8009C758)[base + i], -1, spuAddr);
//                         spuAddr += len;
//                         (&D_1F8003A8)[base + i] = vabId;
//                         SsVabFakeBody(vabId);
//                         i++;
//                     } while (i < nvag);
//                 }
//                 CURRENT_TASK->state1 = 0;
//                 CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
//                 break;
//             }
//             break;

//         case 6:
//             tail = CD_TAIL;
//             head = CD_HEAD;
//             base = (s32)&CD_TAIL;
//             tail = (tail + 1) & 0x7F;
//             *(s32*)base = tail;
//             if (head == tail) {
//                 LOAD_COMPLETE = 1;
//                 exitTask();
//             } else {
//                 CURRENT_TASK->state0 = 1;
//                 CURRENT_TASK->state1 = 0;
//             }
//             break;
//         }
//         sleepTask(1);
//     }
// }


//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021B7C);
int func_80021B7C(void)
{
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021B84);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021BC4);
void func_80021BC4(int arg1, int arg2)
{
    func_80021D70((D_8007912C)[arg2]);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", startSoundTask);
void startSoundTask(void)
{
    *(byte* )0x1F8001CE = 0;
    openTask(2, &func_80021340);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021C24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800222B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800223A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800223E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224B0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224CC);
void func_800224CC(u8* self, s32 arg1)
{
    if (self[1] != 0) {
        playSFX(arg1);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800225B0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800225F0);
void func_800225F0(u8* self, u16 arg1)
{
    u8* row = *(u8**)(self + 0x28) + arg1 * 4;

    *(s32*)(self + 0x14) += *(s16*)(row + 2) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022618);
void func_80022618(u8* self, u16 arg1)
{
    u8*  row = *(u8**)(self + 0x28) + arg1 * 4;
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)row << 8;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022644);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022684);
void func_80022684(u8* self)
{
    u8*  row = *(u8**)(self + 0x28) + *(u16*)(self + 0x2E) * 4;
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)row << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800226B0);
void func_800226B0(u8* self)
{
    u8* row = *(u8**)(self + 0x28) + *(u16*)(self + 0x2E) * 4;

    *(s32*)(self + 0x14) += *(s16*)(row + 2) << 8;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800226D8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022714);
void func_80022714(u8* self, s16* tab)
{
    s32* p = *(s32**)(self + 0x40);

    tab = (s16*)((u8*)tab + *(u16*)(self + 0x2E) * 4);

    *p += *tab << 8;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002273C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800227A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002280C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022874);
void func_80022874(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x80) << 8;
    *(s32*)(self + 0x14) += *(s16*)(self + 0x82) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800228A4);
void func_800228A4(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x80) << 8;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800228C0);
void func_800228C0(u_short* id)
{
    ((u_int*)(id))[0x5] = (int)(((u_int*)(id))[0x5] + (((short*)(id))[0x41] << 8));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800228D8);
void func_800228D8(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x7C) << 8;
    *(s32*)(self + 0x14) += *(s16*)(self + 0x7E) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022908);
void func_80022908(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x7C) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022924);
void func_80022924(short* id)
{
    ((u_int*)(id))[0x5] = (int) (((u_int*)(id))[0x5] + (((short*)(id))[0x3F] << 8));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002293C);
s32 func_8002293C(s16 arg0, s16 arg1)
{
    return (((&D_8007D788)[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002296C);
s32 func_8002296C(s16 arg0, s16 arg1)
{
    return (((&D_8007DB88)[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002299C);
s32 func_8002299C(s16 arg0, s16 arg1)
{
    return (((&D_8007D988)[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800229CC);
s32 func_800229CC(s16 arg0, s16 arg1)
{
    return (((&D_8007DB88)[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800229FC);
void func_800229FC(u8* self)
{
    *(s16*)(self + 0x2C) =
        *(u16*)(*(u8**)(self + 0x24) + 6) & 0x3FFF;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A18);
void func_80022A18(u_short* id)
{
    ((u_short*)(id))[0x16] = ((u_short*)(id))[0x10];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022B34);
