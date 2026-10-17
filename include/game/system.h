#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

/* Tasks, scratchpad layout, joypad.
   Part of game.h: include "game.h", not this file. */

typedef enum {
    JOY_SELECT   = 0x1,
    JOY_L3       = 0x2,
    JOY_R3       = 0x4,
    JOY_START    = 0x8,
    JOY_UP       = 0x10,
    JOY_RIGHT    = 0x20,
    JOY_DOWN     = 0x40,
    JOY_LEFT     = 0x80,
    JOY_L2       = 0x100,
    JOY_R2       = 0x200,
    JOY_L1       = 0x400,
    JOY_R1       = 0x800,
    JOY_TRIANGLE = 0x1000,
    JOY_CIRCLE   = 0x2000,
    JOY_CROSS    = 0x4000,
    JOY_SQUARE   = 0x8000,
} JOYPAD_BUTTONS;

typedef struct { u16 frac; s16 whole; } FixParts;
typedef union { s32 raw; FixParts p; } Fix16;

typedef struct lz_t {
    int size;
    int offset;
} lz_t;

typedef struct TaskEntry {
    int func;
    int saved_reg_gp;
} TaskEntry;

typedef struct Task {
    short status;
    short sleepTimer;
    int task_id;
    int task_sp;
    int task_func;
    int task_gp;
    volatile u_short unk14;
    byte unk16;
    byte unk17;
    byte unk18;
    byte unk19;
    byte unk1a;
    byte unk1b;
    byte unk1c;
    byte unk1d;
    byte unk1e;
    byte unk1f;
    byte unk20;
    byte unk21;
    byte unk22;
    byte unk23;
    byte unk24;
    byte unk25;
    byte unk26;
    byte unk27;
    byte unk28;
    byte unk29;
    byte unk2a;
    byte unk2b;
    byte unk2c;
    byte unk2d;
    byte unk2e;
    byte unk2f;
    byte unk30;
    byte unk31;
    byte unk32;
    byte unk33;
    byte unk34;
    byte unk35;
    byte unk36;
    byte unk37;
    byte unk38;
    byte unk39;
    byte unk3a;
    byte unk3b;
    byte unk3c;
    byte unk3d;
    byte unk3e;
    byte unk3f;
    byte unk40;
    byte unk41;
    byte unk42;
    byte unk43;
    byte unk44;
    byte unk45;
    byte unk46;
    byte unk47;
    short state0;
    u_short state1;
    short state2;
    union {
        volatile u_short volatile_value;
        u_short value;
    } step;
    byte unk50;
    byte unk51;
    byte unk52;
    byte unk53;
    byte unk54;
    byte unk55;
    byte unk56;
    byte unk57;
    u_short timer;
    u_short unk5A;
    u_short countdown;
    u_short unk5E;
    short unk60;
    short unk62;
    u_short unk64;
    byte unk66;
    byte unk67;
    u_char loadGameSelected;
    u_char titleScreenSelectedOption;
    u_char unk6A;
    u_char unk6B;
    u_char unk6C;
    u_char unk6D;
    u_char unk6E;
    u_char unk6F;
} Task;

typedef struct scratchpad {
    /* 0x000 */ MATRIX workMatrix;
    /* 0x020 */ MATRIX unk020;
    /* 0x040 */ VECTOR unk040;
    /* 0x050 */ u8 pad050[0x10];
    /* 0x060 */ SVECTOR unk060;
    /* 0x068 */ SVECTOR unk068;
    /* 0x070 */ lz_t lz;
    /* 0x078 */ u8 pad078[0x14];
    /* 0x08C */ s32 unk08C;
    /* 0x090 */ MATRIX unk090;
    /* 0x0B0 */ u8 pad0B0[0x10];
    /* 0x0C0 */ MATRIX viewMatrix;
    /* 0x0E0 */ Fix16 vrx;
    /* 0x0E4 */ Fix16 vry;
    /* 0x0E8 */ Fix16 vrz;
    /* 0x0EC */ Fix16 vpx;
    /* 0x0F0 */ Fix16 vpy;
    /* 0x0F4 */ Fix16 vpz;
    /* 0x0F8 */ MATRIX baseMatrix;
    /* 0x118 */ u_char unk118;
    /* 0x119 */ u8 pad119[0x4B];
    /* 0x164 */ int nextprim;
    /* 0x168 */ Fix16 unk168[8];
    /* 0x188 */ u8 pad188[0x4];
    /* 0x18C */ s32 unk18C;
    /* 0x190 */ s32 unk190;
    /* 0x194 */ u8 pad194[0x4];
    /* 0x198 */ s32 unk198;
    /* 0x19C */ s16 unk19C;
    /* 0x19E */ s16 unk19E;
    /* 0x1A0 */ u8 unk1A0[4];
    /* 0x1A4 */ u8 unk1A4;
    /* 0x1A5 */ u8 pad1A5[0x6];
    /* 0x1AB */ u8 unk1AB;
    /* 0x1AC */ u8 pad1AC[0x7];
    /* 0x1B3 */ u8 unk1B3;
    /* 0x1B4 */ u_char debug_mode_enabled;
    /* 0x1B5 */ u8 pad1B5[0x3];
    /* 0x1B8 */ u8 unk1B8;
    /* 0x1B9 */ u8 pad1B9[0x2];
    /* 0x1BB */ u_char unk1BB;
    /* 0x1BC */ u8 pad1BC[0x1];
    /* 0x1BD */ u8 unk1BD;
    /* 0x1BE */ u8 unk1BE;
    /* 0x1BF */ u8 unk1BF;
    /* 0x1C0 */ u8 pad1C0[0x2];
    /* 0x1C2 */ u_char unk1C2;
    /* 0x1C3 */ u_char unk1C3;
    /* 0x1C4 */ u_char unk1C4;
    /* 0x1C5 */ u_char unk1C5;
    /* 0x1C6 */ short unk1C6;
    /* 0x1C8 */ u_short unk1C8;
    /* 0x1CA */ u_char unk1CA[2];
    /* 0x1CC */ u_char moviePlayState;
    /* 0x1CD */ u_char movieId;
    /* 0x1CE */ u_char loadComplete;
    /* 0x1CF */ u_char unk1CF;
    /* 0x1D0 */ u_char unk1D0;
    /* 0x1D1 */ u_char unk1D1;
    /* 0x1D2 */ u_char unk1D2;
    /* 0x1D3 */ u_char movieSkipRequest;
    /* 0x1D4 */ Task* currentTask;
    /* 0x1D8 */ s32 unk1D8;
    /* 0x1DC */ short unk1DC;
    /* 0x1DE */ short unk1DE;
    /* 0x1E0 */ int ot;
    /* 0x1E4 */ void* prevOt;
    /* 0x1E8 */ volatile u_short vblankCount;
    /* 0x1EA */ short unk1EA;
    /* 0x1EC */ short useDrawSync;
    /* 0x1EE */ short pauseToggle;
    /* 0x1F0 */ short pauseFlags;
    /* 0x1F2 */ short unk1F2;
    /* 0x1F4 */ short frameBufferIndex;
    /* 0x1F6 */ u_short frameCount;
    /* 0x1F8 */ u_short unk1F8;
    /* 0x1FA */ u_short joypadPressed;
    /* 0x1FC */ u_short joypad_state;
    /* 0x1FE */ u16 unk1FE;
    /* 0x200 */ int unk200;
    /* 0x204 */ s32* unk204;
    /* 0x208 */ void** freeObjects;
    /* 0x20C */ s32* unk20C;
    /* 0x210 */ s32* unk210;
    /* 0x214 */ s32* unk214;
    /* 0x218 */ s32* unk218;
    /* 0x21C */ int unk21C;
    /* 0x220 */ s32* unk220;
    /* 0x224 */ s32* unk224;
    /* 0x228 */ s32* unk228;
    /* 0x22C */ s32* unk22C;
    /* 0x230 */ s32* unk230;
    /* 0x234 */ u8 pad234[0x2];
    /* 0x236 */ u16 unk236;
    /* 0x238 */ short freeObjectCount;
    /* 0x23A */ u16 unk23A;
    /* 0x23C */ u16 unk23C;
    /* 0x23E */ u16 unk23E;
    /* 0x240 */ short unk240;
    /* 0x242 */ short unk242;
    /* 0x244 */ short unk244;
    /* 0x246 */ s16 unk246;
    /* 0x248 */ short unk248;
    /* 0x24A */ s16 unk24A;
    /* 0x24C */ u16 unk24C;
    /* 0x24E */ short unk24E;
    /* 0x250 */ u16 unk250;
    /* 0x252 */ s16 unk252;
    /* 0x254 */ short unk254;
    /* 0x256 */ short unk256;
    /* 0x258 */ short unk258;
    /* 0x25A */ short unk25A;
    /* 0x25C */ s32* unk25C;
    /* 0x260 */ void** unk260;
    /* 0x264 */ void** unk264;
    /* 0x268 */ void** unk268;
    /* 0x26C */ u8 pad26C[0x4];
    /* 0x270 */ s32* unk270;
    /* 0x274 */ s32* unk274;
    /* 0x278 */ s32 unk278;
    /* 0x27C */ s16 unk27C;
    /* 0x27E */ s16 unk27E;
    /* 0x280 */ s16 unk280;
    /* 0x282 */ u16 unk282;
    /* 0x284 */ s16 unk284;
    /* 0x286 */ s16 unk286;
    /* 0x288 */ u8 pad288[0xC];
    /* 0x294 */ s32 unk294;
    /* 0x298 */ s32 loadNextAddr;
    /* 0x29C */ s32 cdQueueHead;
    /* 0x2A0 */ s32 cdQueueTail;
    /* 0x2A4 */ s32 loadSlots[5];
    /* 0x2B8 */ int wssData[4];
    /* 0x2C8 */ int sprData[16];
    /* 0x308 */ int whmData[2];
    /* 0x310 */ int fourData[8];
    /* 0x330 */ int wmdData[6];
    /* 0x348 */ int wppData[3];
    /* 0x354 */ int wppTimPack;
    /* 0x358 */ int apdData[16];
    /* 0x398 */ int wfm3Data;
    /* 0x39C */ u_short* unk39C;
    /* 0x3A0 */ u8 pad3A0[0x8];
    /* 0x3A8 */ s16 vabIds[10];
    /* 0x3BC */ s16 unk3BC;
    /* 0x3BE */ u8 pad3BE[0x2];
    /* 0x3C0 */ struct GameObject* unk3C0;
    /* 0x3C4 */ u16 unk3C4;
    /* 0x3C6 */ u16 buttonJump;
    /* 0x3C8 */ u16 buttonAttack;
    /* 0x3CA */ u16 buttonMenu;
    /* 0x3CC */ u_char unk3CC;
    /* 0x3CD */ u8 unk3CD;
    /* 0x3CE */ u8 unk3CE;
    /* 0x3CF */ u8 pad3CF[0x1];
    /* 0x3D0 */ s8 unk3D0;
    /* 0x3D1 */ u8 unk3D1;
    /* 0x3D2 */ u_char loadedListFile;
    /* 0x3D3 */ u_char loadedSoundSet;
    /* 0x3D4 */ u8 pad3D4[0x6];
    /* 0x3DA */ u16 unk3DA;
    /* 0x3DC */ u8 pad3DC[0x24];
} scratchpad;

#define SPAD ((scratchpad *)PSX_SCRATCH)

/* One of the two frame buffers at OT_FRAMEBUFFER: the ordering table and
   the environments flipFrameBuffer hands to PutDispEnv / PutDrawEnv. */
#define OT_LENGTH 0x328

typedef struct {
    /* 0x000 */ u_long  ot[OT_LENGTH];
    /* 0xCA0 */ DISPENV disp;
    /* 0xCB4 */ DRAWENV draw;
} FrameBuffer; /* size: 0xD10 */

#endif
