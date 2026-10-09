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

typedef struct {
    u_char spawnMode;
    u_char unk1;
    u_char unk2;
    u_char item_id;
    u_char state;
    u_char subState;
    u_char step;
    u_char unk7;
    short clut;
    u_char unkA;
    u_char unkB;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    signed char unkF;
    short unk10;
    short x;
    short unk14;
    short y;
    short unk18;
    short z;
    u_char unk1C;
    u_char unk1D;
    short tpage;
    short unk20;
    u_short cooldownTimer;
    int animData;
    short velocityTable;
    short unk2A;
    short animTimer;
    short unk2E;
    u_char pad4[0xC];
    int spriteBank;
    u_char pad5[0x24];
    int buffSize;
    u_char unk68;
    u_char touchFlag;
    u_char unk6A;
    u_char objectIndex;
    short hitOffsetX;
    short hitWidth;
    short hitOffsetY;
    short hitHeight;
    u_char pad6[0x8];
    short unk7C;
    u_char pad7[0x3];
    short speedY;
    u_char pad8[0x8];
    int unk8C;
    u_char pad9[0x15];
    u_char unkA5;
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
