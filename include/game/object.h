#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* Game objects, their views and sprite slots.
   Part of game.h: include "game.h", not this file. */

typedef enum {
    OBJECT_LAYER_1 = 1,
    OBJECT_LAYER_2 = 2,
    OBJECT_LAYER_3 = 3,
    OBJECT_LAYER_4 = 4,
    OBJECT_LAYER_5 = 5,
    OBJECT_LAYER_7 = 7,
    OBJECT_LAYER_8 = 8,
} OBJECT_LAYER;

/* Item definition entry, reached through D_8007E6E4[D_8007E61C[item_id]].
   Holds the sprite/CLUT/animation description for one item. */
typedef struct itemDef {
    /* 0x00 */ u_char unk0;
    /* 0x01 */ u_char unk1;
    /* 0x02 */ u_char unk2;
    /* 0x03 */ u_char unk3;
    /* 0x04 */ u_char unk4;
    /* 0x05 */ u_char unk5;
    /* 0x06 */ u_char unk6;
    /* 0x07 */ u_char unk7;
    /* 0x08 */ short  x;
    /* 0x0A */ short  y;
    /* 0x0C */ u_char unkC;
    /* 0x0D */ u_char unkD;
    /* 0x0E */ u_char unkE;
    /* 0x0F */ u_char unkF;
    /* 0x10 */ int    unk10;
} itemDef;

/* Views over the object returned by the allocator family
   (allocObjectLayer3 / allocObjectLayer4 / allocObjectLayer7). They describe the same
   block through different field subsets and cannot be merged into a single
   struct: offset 0x10 is u_char in ObjectRawView and int in
   ObjectPosView. */
typedef struct ObjectRawView {
    u_char  unk0;
    u_char  unk1;
    u_char  unk2;
    u_char  unk3;
    u_char  unk4;
    u_char  unk5;
    u_char  unk6;
    u_char  unk7;
    u_char  unk8;
    u_char  unk9;
    u_char  unkA;
    u_char  unkB;
    u_char  unkC;
    u_char  unkD;
    u_char  unkE;
    u_char  unkF;
    u_char  unk10;
    u_char  unk11;
    u_short unk12;
    u_short unk14;
    u_short unk16;
    u_short unk18;
    u_short unk1A;
} ObjectRawView;

typedef struct ObjectAxisView {
    byte  data[0x1C];
    byte  layer;
    byte  pad0[0x23];
    void* drawBufA;
    void* drawBufB;
} ObjectAxisView;

typedef struct ObjectPosView {
    byte  unk0;
    byte  unk1;
    byte  unk2;
    byte  unk3;
    byte  unk4;
    byte  unk5;
    byte  unk6;
    byte  pad[0x6];
    byte  unkD;
    byte  unkE;
    byte  unkF;
    int   posX;
    int   posY;
    int   posZ;
    byte  pad2[0x11];
    short unk2E;
} ObjectPosView;

typedef struct ObjectVariantView {
    byte data[3];
    u_char unk3;
} ObjectVariantView;

/* 16.16 fixed point value. */
typedef struct { u16 frac; s16 whole; } FixParts;
typedef union { s32 raw; FixParts p; } Fix16;

/* Game object. The layout follows the TObj struct of afsenovilla/Tombi-Decomp
   (MIT licence, (c) 2026 afsenovilla and Tombi-Decomp contributors). */
typedef struct GameObject {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 visible;
    /* 0x02 */ u8 type;
    /* 0x03 */ u8 subtype;
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 subState;
    /* 0x06 */ u8 step;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ s16 clut;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ Fix16 x;
    /* 0x14 */ Fix16 y;
    /* 0x18 */ Fix16 z;
    /* 0x1C */ u8 category;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ s16 tpage;
    /* 0x20 */ s16 timer;
    /* 0x22 */ s16 cooldownTimer;
    /* 0x24 */ void* anim;
    /* 0x28 */ void* movetab;
    /* 0x2C */ u16 animTimer;
    /* 0x2E */ u16 animFrame;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 spriteBank;
    /* 0x40 */ Fix16* h;
    /* 0x44 */ Fix16* d;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ u8 pad54[2];
    /* 0x56 */ s16 unk56;
    /* 0x58 */ u16 unk58;
    /* 0x5A */ u8 pad5A[2];
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ u8 pad5E[2];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 buffSize;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 touchFlag;
    /* 0x6A */ u8 unk6A;
    /* 0x6B */ u8 objectIndex;
    /* 0x6C */ s16 hitOffsetX;
    /* 0x6E */ s16 hitWidth;
    /* 0x70 */ s16 hitOffsetY;
    /* 0x72 */ s16 hitHeight;
    /* 0x74 */ s16 unk74;
    /* 0x76 */ s16 unk76;
    /* 0x78 */ s16 unk78;
    /* 0x7A */ s16 unk7A;
    /* 0x7C */ s16 velX;
    /* 0x7E */ s16 velY;
    /* 0x80 */ s16 velH;
    /* 0x82 */ s16 velV;
    /* 0x84 */ s32 unk84;
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s32 unk8C;
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
    /* 0x98 */ s16 unk98;
    /* 0x9A */ s16 unk9A;
    /* 0x9C */ u8 unk9C;
    /* 0x9D */ u8 unk9D;
    /* 0x9E */ u8 unk9E;
    /* 0x9F */ u8 unk9F;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ u8 unkA4;
    /* 0xA5 */ u8 unkA5;
    /* 0xA6 */ u8 unkA6;
    /* 0xA7 */ u8 unkA7;
    /* 0xA8 */ s16 unkA8;
    /* 0xAA */ s16 unkAA;
    /* 0xAC */ s16 unkAC;
    /* 0xAE */ s16 unkAE;
    /* 0xB0 */ s16 unkB0;
    /* 0xB2 */ s16 unkB2;
    /* 0xB4 */ s16 unkB4;
    /* 0xB6 */ s16 unkB6;
    /* 0xB8 */ s16 unkB8;
    /* 0xBA */ s16 unkBA;
    /* 0xBC */ s16 unkBC;
    /* 0xBE */ u8 unkBE;
    /* 0xBF */ u8 unkBF;
} GameObject;

typedef struct SpriteSlot {
    short id;
    short refCount;
    char val[6];
} SpriteSlot;

/* reward.c */
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    int* unk8;
} unk_8007D6E0;

/* reward.c */
typedef struct {
    int unk0;
    s16 unk4;
    s16 unk6;
} unk_8007E868;

#endif
