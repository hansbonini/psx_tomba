#ifndef GAME_MACROS_H
#define GAME_MACROS_H

/* Scratchpad accessors and small helper macros.
   Part of game.h: include "game.h", not this file. */

/* Scratchpad fields reached from code that has no `scratchpad*` handy.
   Each expands to exactly the cast it replaced, so the generated code is
   unchanged; the names mirror the fields of `struct scratchpad`. */
#define NEXT_PRIM          (*(int *)&SPAD->nextprim)      /* 0x164 */
#define MOVIE_PLAY_STATE   (*(u8 *)&SPAD->moviePlayState)       /* 0x1CC */
#define LOAD_COMPLETE      (*(u8 *)&SPAD->loadComplete)       /* 0x1CE */
/* Which list file sits at 0x80097FA8: 0 = SYS/LDSYS.BIN, area + 1 = that
   area's SYS/LDARnn.BIN (loadAreaListFile), 0xFF = none yet. */
#define LOADED_LIST_FILE   (*(u_char *)&SPAD->loadedListFile)   /* 0x3D2 */
/* Index into SOUND_SET_LOAD_LISTS of the sound set in memory, 0xFF = none. */
#define LOADED_SOUND_SET   (*(u_char *)&SPAD->loadedSoundSet)   /* 0x3D3 */
#define MOVIE_ID           (*(u_char *)&SPAD->movieId)      /* 0x1CD */
#define MOVIE_SKIP_REQUEST (*(u_char *)&SPAD->movieSkipRequest)      /* 0x1D3 */
#define CD_QUEUE_HEAD      (*(s32 *)&SPAD->cdQueueHead)        /* 0x29C */
#define CD_QUEUE_TAIL      (*(s32 *)&SPAD->cdQueueTail)        /* 0x2A0 */
#define CURRENT_OT         ((*(u_long *)&SPAD->ot))   /* 0x1E0 */
#define PAUSE_TOGGLE       ((*(u16 *)&SPAD->pauseToggle))      /* 0x1EE */
#define PAUSE_FLAGS        ((*(u16 *)&SPAD->pauseFlags))      /* 0x1F0 */
#define FRAME_BUFFER_INDEX (*(s16 *)&SPAD->frameBufferIndex)      /* 0x1F4 */
#define JOYPAD_STATE       (*(u16 *)&SPAD->joypad_state)      /* 0x1FC */

#define CURRENT_TASK       (*(Task* *)&SPAD->currentTask)
#define TASK_TABLE  0x801FD800
#define TIM_SCRATCH ((u_long*)0x801FBE00)

#define MOVIE_DEC_IMGBUF ((u_long*)((byte*)&MOVIE_DEC_ENV+0xC))
#define MOVIE_DEC_DISPENV ((DISPENV*)((byte*)&MOVIE_DEC_ENV+0x24))
#define LZ_FILE_CTRL ((lz_t*)0x1F800070)

/* A field of a struct reached by its byte offset. */
#define S8(o, n) (*(s8 *)((char *)(o) + (n)))
#define U8(o, n) (*(u8 *)((char *)(o) + (n)))
#define S16(o, n) (*(s16 *)((char *)(o) + (n)))
#define U16(o, n) (*(u16 *)((char *)(o) + (n)))
#define S32(o, n) (*(s32 *)((char *)(o) + (n)))
#define U32(o, n) (*(u32 *)((char *)(o) + (n)))
#define PTR(o, n) (*(void **)((char *)(o) + (n)))

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
