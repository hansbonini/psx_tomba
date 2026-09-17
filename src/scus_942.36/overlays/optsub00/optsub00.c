#include "common.h"

extern s16   D_8009E744;
extern u8    D_8009C9E4;
extern u8    D_8009E450;
extern s32   D_800E9D08[];
extern u8    D_800E9648;
extern u8    D_800E9DBC;
extern s32   D_800E9C90[];
extern s32   D_800E9CF4[];
void func_800E9348(void);
extern s16   D_800EA2EC;
extern u8    D_800E9C64;

typedef struct optsubRequest {
    /* 0x00 */ s16   unk0;
    /* 0x02 */ s16   unk2;
    /* 0x04 */ s16   unk4;
    /* 0x08 */ s32   unk8;
    /* 0x0C */ void* unkC;
    /* 0x10 */ void* unk10;
    /* 0x14 */ s32   unk14;
} optsubRequest;

extern u8    D_800E9DD4;
extern void* D_8009C998;
extern s16   D_800EA36C;
extern s16   D_800EA370;
extern s16   D_800EA374;
extern s16   D_800EA378;
extern s16   D_800EA37C;

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E73C0);

void func_800E75C4(void) {
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E75CC);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7960);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7A48);

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7D5C);
void func_800E7D5C(void)
{
    D_8009C998 = &D_800E9C64;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7D74);
void func_800E7D74(void)
{
    func_800E73C0(&D_800E9DD4, 0, 0, 1);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7DA4);
void func_800E7DA4(void)
{
    D_800EA378 = 0x1000;
    D_800EA36C = 0;
    D_800EA370 = 0;
    D_800EA374 = 0;
    D_800EA37C = 0x40;
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7DDC);

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7EB0);
void func_800E7EB0(void)
{
    *(u8*)0x1F8001CF = 1;
    func_800E8160();
    func_800E83EC(D_8009C9E4, D_8009E450);
    func_800E8814();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7EFC);
void func_800E7EFC(void)
{
    *(u8*)0x1F8001CF = 1;
    func_800E82F4();
    func_800E8570(D_8009E744);
    func_800E8814();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7F40);
void func_800E7F40(void)
{
    *(u8*)0x1F8001CF = 1;
    func_800E8680();
    func_800E8814();
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7F74);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8160);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E82F4);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E83EC);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8570);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8680);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8814);

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", printTitleScreenMessage);
void printTitleScreenMessage(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 6;
    req.unk8 = D_800E9C90[arg2];
    req.unkC = &func_800E9348;
    req.unk10 = (void*)D_800E9CF4[arg2];
    func_800E8B6C(&req, 0, 1, 1);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8908);
void func_800E8908(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 9;
    req.unk8 = D_800E9D08[arg2];
    req.unkC = &D_800E9648;
    func_800E8B6C(&req, 0, 1, 0);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8964);
void func_800E8964(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 2;
    req.unk8 = D_800E9D08[arg2];
    req.unkC = &D_800E9648;
    req.unk10 = &D_800E9DBC;
    func_800E8B6C(&req, 0, 1, 2);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E89CC);
void func_800E89CC(s16 arg0, s16 arg1, s32 arg2, s32 arg3)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 9;
    req.unk8 = D_800E9D08[arg2];
    req.unkC = &D_800E9648;
    func_800E8B6C(&req, 0, 1, arg3);
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8A24);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8B6C);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8E78);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E90CC);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E9348);
