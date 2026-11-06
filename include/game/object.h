#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/* Game objects, their views and sprite slots.
   Part of game.h: include "game.h", not this file. */

typedef enum {
    OBJ_CAT_NONE = 0,
    OBJ_CAT_WEAPON = 1,
    OBJ_CAT_ACTOR = 2,
    OBJ_CAT_EFFECT = 3,
    OBJ_CAT_AREA = 4,
    OBJ_CAT_ITEM = 5,
    OBJ_CAT_FX = 7,
    OBJ_CAT_MODEL = 8,
} ObjectCategory;

/* Item definition entry, reached through ITEM_INIT_TABLE[ITEM_INIT_INDEX[item_id]].
   Holds the sprite/CLUT/animation description for one item. */
typedef struct ItemInit {
    /* 0x00 */ u_char drawType;
    /* 0x01 */ u_char unk1;
    /* 0x02 */ u_char tpage;
    /* 0x03 */ u_char priority;
    /* 0x04 */ u_char spriteBank;
    /* 0x05 */ u_char drawFlags;
    /* 0x06 */ u_char clutMode;
    /* 0x07 */ u_char animMode;
    /* 0x08 */ short  clutX;
    /* 0x0A */ short  clutY;
    /* 0x0C */ u_char hitboxX;
    /* 0x0D */ u_char hitboxW;
    /* 0x0E */ u_char hitboxY;
    /* 0x0F */ u_char hitboxH;
    /* 0x10 */ int    anim;
} ItemInit;

/* Views over the object returned by the allocator family
   (allocEffectObject / allocAreaObject / allocFxObject). They describe the same
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
    byte  category;
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


typedef enum DrawType {
    DRAW_SPRITE = 0,
    DRAW_SPRITE_SCALED = 1,
    DRAW_SPRITE_ROTATED = 2,
    DRAW_SPRITE_SCALED_ROTATED = 3,
    DRAW_SPRITE_3D = 4,
    DRAW_AREA = 5,
    DRAW_OVERLAY_6 = 6,
    DRAW_OVERLAY_7 = 7,
    DRAW_OVERLAY_8 = 8,
    DRAW_OVERLAY_9 = 9,
    DRAW_OVERLAY_10 = 10,
    DRAW_SPRT = 13,
    DRAW_NONE_14 = 14,
    DRAW_MODEL = 0x10,
    DRAW_MODEL_ROTATED = 0x11,
    DRAW_MODEL_EX_ROTATED = 0x12,
    DRAW_MODEL_ROTATED_SCALED = 0x13,
    DRAW_MODEL_SCREEN = 0x14,
    DRAW_MODEL_MATRIX = 0x15,
    DRAW_MODEL_EX_MATRIX = 0x16
} DrawType;

typedef enum OtMode {
    OT_MODE_DEPTH = 0,
    OT_MODE_FIXED = 1,
    OT_MODE_FIXED16 = 2
} OtMode;

/* Game object. The layout follows the TObj struct of afsenovilla/Tombi-Decomp
   (MIT licence, (c) 2026 afsenovilla and Tombi-Decomp contributors). */
typedef struct GameObject {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 visible;
    /* 0x02 */ u8 type;
    /* 0x03 */ u8 id;
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 subState;
    /* 0x06 */ u8 step;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ s16 clut;
    /* 0x0A */ u8 drawType;
    /* 0x0B */ u8 otMode;
    /* 0x0C */ u8 param;
    /* 0x0D */ u8 drawFlags;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 priority;
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
    /* 0x30 */ s32 localX;
    /* 0x34 */ s32 localY;
    /* 0x38 */ s32 localZ;
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
    /* 0x64 */ s32 scale;
    /* 0x68 */ u8 unk68;
    /* 0x69 */ u8 touchFlag;
    /* 0x6A */ u8 unk6A;
    /* 0x6B */ u8 objectIndex;
    /* 0x6C */ s16 hitboxX;
    /* 0x6E */ s16 hitboxW;
    /* 0x70 */ s16 hitboxY;
    /* 0x72 */ s16 hitboxH;
    /* 0x74 */ s16 scaleX;
    /* 0x76 */ s16 scaleY;
    /* 0x78 */ s16 scaleZ;
    /* 0x7A */ s16 unk7A;
    /* 0x7C */ s16 velX;
    /* 0x7E */ s16 velY;
    /* 0x80 */ s16 velH;
    /* 0x82 */ s16 velV;
    /* 0x84 */ s32 rotX;
    /* 0x88 */ s32 rotY;
    /* 0x8C */ s32 rotZ;
    /* 0x90 */ s32 parent;
    /* 0x94 */ s32 child;
    /* 0x98 */ s16 unk98;
    /* 0x9A */ s16 unk9A;
    /* 0x9C */ u8 unk9C;
    /* 0x9D */ u8 unk9D;
    /* 0x9E */ u8 unk9E;
    /* 0x9F */ u8 unk9F;
    /* 0xA0 */ s32 model;
    /* 0xA4 */ u8 modelLit;
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

#define setHitbox(o, x, y, w, h) ((o)->hitboxX = (x), (o)->hitboxW = (w), (o)->hitboxY = (y), (o)->hitboxH = (h))
#define setObjState(o, s, ss, st) ((o)->state = (s), (o)->subState = (ss), (o)->step = (st))

typedef struct ObjectAC {
    s16 x;
    s16 y;
    u16 tpage;
    u16 clut;
    u16 tpage2;
    u16 clut2;
    s8 mode;
    u8 frame;
    s16 angle;
    u16 shadow[8];
    u16 shadow2[8];
    s16 shadowLen;
    s16 shadowLen2;
    s16 w34;
    s16 w36;
} ObjectAC;

typedef struct Unk8009C968 {
    s16 w0;
    s16 w2;
    s16 w4;
    u8 pad6[0xA];
    u16 w10;
    u8 pad12[0x2];
    u8 b14;
    u8 pad15[0x5B];
    u16 w70;
    u8 pad72[0x2];
    u16 w74;
    u8 pad76[0x1E];
    s32 i94;
    u8 pad98[0x4];
    s32 i9c;
    s32 ia0;
    u8 pada4[0xC];
} Unk8009C968;

/* PLAYER.obj.state: what updatePlayer runs. */
typedef enum PlayerState {
    PLAYER_INIT = 0,       /* initPlayer */
    PLAYER_ACTIVE = 1,     /* updatePlayerActive, by sub-state */
    PLAYER_HURT = 2,       /* taking damage, by PlayerHurtType */
    PLAYER_SCRIPTED = 5,   /* no control while the game runs a scene: respawn,
                              item get, reading a sign */
} PlayerState;

/* PLAYER.obj.subState while PLAYER_HURT (updatePlayer picks one of five
   handlers; 3 and 4 are not identified). */
typedef enum PlayerHurtType {
    PLAYER_HURT_NORMAL = 0,  /* playerHurt: enemies, spikes */
    PLAYER_HURT_BITTEN = 1,  /* playerHurtBitten: caught and spat out (Biting Plant Flower) */
    PLAYER_HURT_WATER = 2,   /* playerFallInWater: the section reloads */
} PlayerHurtType;

/* PLAYER.obj.subState while PLAYER_SCRIPTED (only this one identified). */
#define PLAYER_READ_MESSAGE 0x61

/* PLAYER.obj.subState while PLAYER_ACTIVE (the jump table of
   updatePlayerActive has 0x64 entries; these are the ones identified). */
typedef enum PlayerSubState {
    PLAYER_IDLE = 0x00,
    PLAYER_WALK = 0x01,               /* playerWalk */
    PLAYER_JUMP = 0x02,               /* playerJump */
    PLAYER_ATTACK = 0x03,             /* playerAttack */
    PLAYER_AIR_ATTACK = 0x04,
    PLAYER_GRAB_LEDGE = 0x06,         /* playerGrabLedge */
    PLAYER_CLIMB_OVER_LEDGE = 0x0B,   /* playerClimbOverLedge */
    PLAYER_CLING = 0x0D,              /* playerCling: on a vine or a wall */
    PLAYER_HOLD_ENEMY = 0x0E,         /* playerHoldEnemy */
    PLAYER_THROW_ENEMY = 0x0F,        /* playerThrowEnemy */
    PLAYER_JUMP_TO_BACK_WALL = 0x11,  /* playerJumpToBackWall */
    PLAYER_JUMP_PLANE = 0x12,         /* playerJumpPlane: to the next depth plane */
    PLAYER_CLIMB_WALL = 0x15,         /* playerClimbWall */
    PLAYER_HOP_ONTO_LEDGE = 0x16,     /* playerHopOntoLedge */
    PLAYER_CLIMB = 0x1D,              /* playerClimb */
} PlayerSubState;

typedef struct Player {
    /* 0x00 */ GameObject obj;
    /* 0xC0 */ u8 unkC0[0x24];
    /* 0xE4 */ struct GameObject *heldObject;  /* the enemy grabbed last (kept after the throw) */
    /* 0xE8 */ u8 unkE8[0x90];
} Player;

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
    int ap;
    s16 clutX;
    s16 clutY;
} ApReward;

/* Setup table entry of the area objects: hitbox (b0 hitOffsetX, b1 hitWidth,
   b2 hitOffsetY, b3 hitHeight), w4 tpage, w6 SPR_DATA index, anim table. */
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} ObjSetupHitbox;

#endif
