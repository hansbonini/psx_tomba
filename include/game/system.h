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

/* PSX scratchpad (data cache) at 0x1F800000, 1 KiB.
   Field offsets were verified against the 14 local definitions this replaces. */
typedef struct scratchpad {
    /* 0x000  Shared scratch area -- NOT a stable layout. These bytes are reused
       with a different shape by each user, so do not name fields in here:
         - drawBootLogo / drawMessageBox / drawBalloonFrame assemble a SPRT at
           0x000-0x013 (code 0x003, rgb 0x004-0x006, xy 0x008/0x00A,
           uv 0x00C/0x00D, clut 0x00E, wh 0x010/0x012) writing it field by field
           and reading it back word-wise to copy into the OT;
         - 0x014 / 0x018 / 0x01C hold unrelated 4-byte values for ~10 other
           functions -- 0x018 in particular is one byte of the staged primitive
           in drawBalloonFrame and a word everywhere else.
       Two stable overlays live further up and are reached by explicit cast,
       never through this struct: a CAMERA at 0x0E2 and a MATRIX at 0x0F8. */
    /* 0x000 */ u_char  unk000[0x164];
    /* 0x164 */ int     nextprim;
    /* 0x168 */ u_char  unk168[0x4C];
    /* 0x1B4 */ u_char  debug_mode_enabled;
    /* 0x1B5 */ u_char  unk1B5[0xD];
    /* 0x1C2 */ u_char  unk1C2;
    /* 0x1C3 */ u_char  unk1C3;
    /* 0x1C4 */ u_char  unk1C4;
    /* 0x1C5 */ u_char  unk1C5;
    /* 0x1C6 */ short   unk1C6;
    /* 0x1C8 */ u_short unk1C8;
    /* 0x1CA */ u_char  unk1CA[2];
    /* 0x1CC */ u_char  moviePlayState;
    /* 0x1CD */ u_char  movieId;
    /* 0x1CE */ u_char  loadComplete;
    /* 0x1CF */ u_char  unk1CF;
    /* 0x1D0 */ u_char  unk1D0;
    /* 0x1D1 */ u_char  unk1D1;
    /* 0x1D2 */ u_char  unk1D2;
    /* 0x1D3 */ u_char  movieSkipRequest;
    /* 0x1D4 */ Task* currentTask;
    /* 0x1D8 */ u_char  unk1D8[4];
    /* 0x1DC */ short   unk1DC;
    /* 0x1DE */ short   unk1DE;
    /* 0x1E0 */ int     ot;
    /* 0x1E4 */ void*   prevOt;
    /* 0x1E8 */ volatile u_short vblankCount;
    /* 0x1EA */ short   unk1EA;
    /* 0x1EC */ short   useDrawSync;
    /* 0x1EE */ short   pauseToggle;
    /* 0x1F0 */ short   pauseFlags;
    /* 0x1F2 */ short   unk1F2;
    /* 0x1F4 */ short   frameBufferIndex;
    /* 0x1F6 */ u_short frameCount;
    /* 0x1F8 */ short   unk1F8;
    /* 0x1FA */ u_char  unk1FA[2];
    /* 0x1FC */ u_short joypad_state;
    /* 0x1FE */ u_char  unk1FE[0xA];
    /* 0x208 */ void**  freeObjects;
    /* 0x20C */ u_char  unk20C[0x2C];
    /* 0x238 */ short   freeObjectCount;
    /* 0x23A */ u_char  unk23A[0x162];
    /* 0x39C */ u_short* unk39C;
    /* 0x3A0 */ u_char  unk3A0[0x2C];
    /* 0x3CC */ u_char  unk3CC;
    /* 0x3CD */ u_char  unk3CD[5];
    /* 0x3D2 */ u_char  unk3D2;
    /* 0x3D3 */ u_char  unk3D3;
    /* 0x3D4 */ u_char  unk3D4[0x2C];
} scratchpad;

#endif
