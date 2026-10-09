#ifndef GAME_MESSAGE_H
#define GAME_MESSAGE_H

/* Message boxes, info messages and the dialogue control codes.
   Part of game.h: include "game.h", not this file. */

typedef enum {
    /*0x00*/ BALLOON_TAIL_BOTTOM_CENTER,
    /*0x01*/ BALLOON_TAIL_BOTTOM_LEFT,
    /*0x02*/ BALLOON_TAIL_LEFT,
    /*0x03*/ BALLOON_TAIL_TOP_LEFT,
    /*0x04*/ BALLOON_TAIL_TOP_CENTER,
    /*0x05*/ BALLOON_TAIL_TOP_RIGHT,
    /*0x06*/ BALLOON_TAIL_RIGHT,
    /*0x07*/ BALLOON_TAIL_BOTTOM_RIGHT,
    /*0x08*/ BALLOON_TAIL_NONE
} BALLOON_TAIL;

typedef enum {
    MSG_ANIMALDASH_ACQUIRED    = 0x0C,
    MSG_EFFECT_NOTICE          = 0x0F,
    MSG_ONEUP_ACQUIRED         = 0x14,
    MSG_VITALITYMAXUP_ACQUIRED = 0x15,
    MSG_LOSTANDFOUND_STARTED   = 0x16,
    MSG_LOSTANDFOUND_PROGRESS  = 0x17,
    MSG_ITS_LOCKED             = 0x26,
} INFO_MESSAGE;

typedef enum {
    MSG_TYPE_ITEM   = 0,
    MSG_TYPE_INFO   = 2,
    MSG_TYPE_REWARD = 3,
} INFO_MESSAGE_TYPE;

/* Control codes of the dialogue streams of a WFM3 file (updateMessageBox). */
typedef enum {
    /*0xFFF2*/ MSG_POSE = 0xFFF2,   /* n: TALK_POSE = n */
    /*0xFFF3*/ MSG_HALT = 0xFFF3,
    /*0xFFF5*/ MSG_CHOICE = 0xFFF5,
    /*0xFFF6*/ MSG_MOVE = 0xFFF6,   /* dx, dy */
    /*0xFFF7*/ MSG_COLOR = 0xFFF7,  /* n */
    /*0xFFF8*/ MSG_VOICE = 0xFFF8,  /* tone, BALLOON_TAIL << 12 */
    /*0xFFF9*/ MSG_DELAY = 0xFFF9,  /* frames */
    /*0xFFFA*/ MSG_BOX = 0xFFFA,    /* w, h */
    /*0xFFFB*/ MSG_CLEAR = 0xFFFB,
    /*0xFFFC*/ MSG_WAIT = 0xFFFC,
    /*0xFFFD*/ MSG_NEWLINE = 0xFFFD,
    /*0xFFFE*/ MSG_CLOSE = 0xFFFE,
    /*0xFFFF*/ MSG_END = 0xFFFF
} MessageCode;

/* One open message box: how many glyphs it shows and where (MESSAGE_SLOTS). */
typedef struct MessageSlot {
    /* 0x0 */ s16 count;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 x;
    /* 0x6 */ s16 y;
} MessageSlot;

/* One glyph placed in a message box (MESSAGE_GLYPHS[slot][n]). */
typedef struct MessageGlyph {
    /* 0x0 */ u16 id;
    /* 0x2 */ u16 clut;
    /* 0x4 */ s16 x;
    /* 0x6 */ s16 y;
} MessageGlyph;

/* One glyph uploaded to VRAM (GLYPH_CACHE). */
typedef struct GlyphSlot {
    /* 0x0 */ s16 id;
    /* 0x2 */ u16 mask;
    /* 0x4 */ u8 u;
    /* 0x5 */ u8 v;
    /* 0x6 */ u8 w;
    /* 0x7 */ u8 h;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 flag;
} GlyphSlot;

/* Position argument of openMessageBox (message.c). */
typedef struct msgBox {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} msgBox;

/* Frame drawn by drawBalloonFrame (actorrender3.c). */
typedef struct {
    /* 0x00 */ s16  unk0[4];
    /* 0x08 */ RECT rect;     /* box on screen */
    /* 0x10 */ s16  tail;     /* BALLOON_TAIL << 12, or -1 for none */
    /* 0x12 */ s16  unk12[3];
} BalloonFrame;

#endif
