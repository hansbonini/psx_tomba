#ifndef GAME_RENDER_H
#define GAME_RENDER_H

/* Rendering state built on the PSY-Q GTE types.
   Part of game.h: include "game.h", not this file. */

/* Lighting set up by initLighting / applyLighting (camera.c): the first
   0x4A bytes of the object those functions receive. */
typedef struct LightEnv {
    /* 0x00 */ MATRIX light;  /* local light matrix, rebuilt from rotX / rotY */
    /* 0x20 */ MATRIX color;  /* passed to SetColorMatrix */
    /* 0x40 */ u8     backR;  /* SetBackColor */
    /* 0x41 */ u8     backG;
    /* 0x42 */ u8     backB;
    /* 0x43 */ u8     pad43;
    /* 0x44 */ s16    rotX;
    /* 0x46 */ s16    rotY;
    /* 0x48 */ s16    rotZ;
} LightEnv;

/* The two matrices kept in the scratchpad: the view matrix handed to
   SetRotMatrix / SetTransMatrix and the base matrix every other one is
   copied from. */
#define SCRATCH_VIEW_MATRIX ((MATRIX*)D_1F8000C0)
#define SCRATCH_BASE_MATRIX ((MATRIX*)(&D_1F8000F8))

/* One part of a sprite frame in a SPR/WPP bank: the UVs and CLUT/tpage of the
   SPRT or POLY_FT4, its size and its offset from the object. */
typedef struct SprFrag {
    /* 0x00 */ u8 u, v;
    /* 0x02 */ u16 clut;
    /* 0x04 */ u16 uv1;
    /* 0x06 */ u16 tpage;
    /* 0x08 */ u16 uv2;
    /* 0x0A */ u8 w, h;
    /* 0x0C */ u16 uv3;
    /* 0x0E */ s8 dx, dy;
} SprFrag;

#endif
