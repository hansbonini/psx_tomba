#ifndef GAME_MACROS_H
#define GAME_MACROS_H

/* Scratchpad accessors and small helper macros.
   Part of game.h: include "game.h", not this file. */

/* Scratchpad fields reached from code that has no `scratchpad*` handy.
   Each expands to exactly the cast it replaced, so the generated code is
   unchanged; the names mirror the fields of `struct scratchpad`. */
#define NEXT_PRIM          (*(int*)0x1F800164)      /* 0x164 */
#define MOVIE_PLAY_STATE   (*(u8*)0x1F8001CC)       /* 0x1CC */
#define LOAD_COMPLETE      (*(u8*)0x1F8001CE)       /* 0x1CE */
#define MOVIE_ID           (*(u_char*)0x1F8001CD)      /* 0x1CD */
#define MOVIE_SKIP_REQUEST (*(u_char*)0x1F8001D3)      /* 0x1D3 */
#define CD_QUEUE_HEAD      (*(s32*)0x1F80029C)        /* 0x29C */
#define CD_QUEUE_TAIL      (*(s32*)0x1F8002A0)        /* 0x2A0 */
#define CURRENT_OT         (*(u_long*)0x1F8001E0)   /* 0x1E0 */
#define PAUSE_TOGGLE       (*(u16*)0x1F8001EE)      /* 0x1EE */
#define PAUSE_FLAGS        (*(u16*)0x1F8001F0)      /* 0x1F0 */
#define FRAME_BUFFER_INDEX (*(s16*)0x1F8001F4)      /* 0x1F4 */
#define JOYPAD_STATE       (*(u16*)0x1F8001FC)      /* 0x1FC */

#define CURRENT_TASK       (*(Task**)0x1F8001D4)
#define TASK_TABLE  0x801FD800
#define TIM_SCRATCH ((u_long*)0x801FBE00)

#define MOVIE_DEC_IMGBUF ((u_long*)((byte*)&MOVIE_DEC_ENV+0xC))
#define MOVIE_DEC_DISPENV ((DISPENV*)((byte*)&MOVIE_DEC_ENV+0x24))
#define LZ_FILE_CTRL ((lz_t*)0x1F800070)
#define DRAW_ENV_2 ((void*)0x8009E3D4)

#define READ32(_dst, _src) { \
    _dst = (((u_char *)_src)[1] << 8) | (((u_char *)_src)[0] << 0) \
        | ((((u_char *)_src)[3] << 8) | (((u_char *)_src)[2] << 0) << 16);\
    _src = (char*)_src + 4; \
}
#define READ16(_dst, _src) { \
    _dst = (((u_char *)_src)[1] << 8) | ((u_char *)_src)[0]; \
    _src = (char*)_src + 2; \
}
/*
 * Set Primitive X/Y
 */
#define setXY(p, _x, _y) (p)->x = _x, (p)->y = _y

#endif
