#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

#include "psyq/libgpu.h"
#include "psyq/libgte.h"

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

extern s32 D_1F8000C0;
extern s32 D_1F800118;
extern s32 D_8007D6A0;
extern u8 LZ_CURRENT_BIT;
extern u16 LZ_BITMASK;
extern u32 D_8009B138;
extern u16 D_8009C864;
extern u16 D_8009C866;
extern s16 D_8009C940;
extern s16 D_8009C9DA;
extern s16 D_8009C9DE;
extern u_long FRAMEBUFFER_OT;
extern s16 D_8009D6B8;
extern s16 D_8009D6BA;
extern s16 D_8009D6BC;
extern s16 D_8009D6BE;
extern DRAWENV* D_8009D6C4;
extern s8 D_8009D6DA;
extern s8 D_8009D6DB;
extern s8 D_8009D6DC;
extern s8 D_8009D6DD;
extern s8 D_8009D6DE;
extern s8 D_8009D6DF;
extern s16 D_8009E3C8;
extern s16 D_8009E3CA;
extern s16 D_8009E3CC;
extern s16 D_8009E3CE;
extern s8 D_8009E3EA;
extern s8 D_8009E3EB;
extern s8 D_8009E3EC;
extern s8 D_8009E3ED;
extern s8 D_8009E3EE;
extern s8 D_8009E3EF;
extern long D_8009E45C;
extern long D_8009E460;
extern long D_8009E464;
extern long D_8009E468;
extern long D_8009E474;
extern long D_8009E478;
extern long D_8009E47C;
extern long D_8009E480;
extern s16 D_8009EB52;
extern u16 D_8009EB5A;
extern u16 D_8009EB7C;
extern u8 D_800A3940;
extern u8 D_800A5398;
extern s32 D_800A5970;
extern u8 D_800B00F8;
extern u8 D_800B0770;

#endif
