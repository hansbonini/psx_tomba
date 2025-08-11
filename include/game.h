#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

#define IS_DEBUG_MODE_ENABLED ((u8)(PSX_SCRATCH + 0x1B4))
#define LZ_FILE_CTRL ((lz_t*)0x1F800070)
#define READ32(_dst, _src) { \
    _dst = (((u8 *)_src)[1] << 8) | (((u8 *)_src)[0] << 0) \
        | ((((u8 *)_src)[3] << 8) | (((u8 *)_src)[2] << 0) << 16);\
    _src = (char*)_src + 4; \
}
#define READ16(_dst, _src) { \
    _dst = (((u8 *)_src)[1] << 8) | ((u8 *)_src)[0]; \
    _src = (char*)_src + 2; \
}

typedef struct lz_t {
    s32 size;
    s32 offset;
} lz_t;

// extern void* bcopy(void*, void*, int); /* src,dest */
extern s32 D_1F8000C0;
extern s32 D_1F800118;
extern u_long FRAMEBUFFER_OT;
extern u8 LZ_CURRENT_BIT;
extern u16 LZ_BITMASK;

#endif
