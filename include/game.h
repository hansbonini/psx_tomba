#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

#define LZ_FILE_CTRL ((lz_t*)0x1F800070)
#define IS_DEBUG_MODE_ENABLED ((u8)(0x1F80001B4))
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
extern long D_8009E45C;
extern long D_8009E460;
extern long D_8009E464;
extern long D_8009E468;
extern long D_8009E474;
extern long D_8009E478;
extern long D_8009E47C;
extern long D_8009E480;
extern u8 D_800A5398;

#endif
