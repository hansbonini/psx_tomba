#ifndef OVERLAY_OPTSUB00_H
#define OVERLAY_OPTSUB00_H

extern u8 D_800E9348[];
extern u8 D_800E9648;
extern u8 D_800E9C64;
extern s32 D_800E9C90[];
extern s32 D_800E9CF4[];
extern s32 D_800E9D08[];
extern s32 D_800E9D8C[];
extern s32 D_800E9DB4;
extern s32 D_800E9DB8;
extern u8 D_800E9DBC;
extern u8 D_800E9DD4;
extern u8 D_800E9E14[];
extern u8 D_800E9E44[];
extern s16 D_800EA36C;
extern s16 D_800EA370;
extern s16 D_800EA374;
extern s16 D_800EA378;
extern u16 D_800EA37C;
extern s16 D_800EA380;

extern void* SEQ_DATA;
void drawOptsubNumber(s16 arg0, s16 arg1, s32 arg2);
void drawOptsubSpriteList();
void drawOptsubText(s16 arg0, s16 arg1, s32 arg2);
void func_800E7EFC(void);
void func_800E82F4(void);
void func_800E83EC(s32 arg0, s32 arg1);
void func_800E8570(s32 arg0);
void func_800E8814(void);
void func_800E8964(s16 arg0, s16 arg1, s32 arg2);
void func_800E89CC(s16 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_800E8B6C();

void func_800E8160();
void func_800E8680();

#endif
