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

typedef enum ITEM {
    /* 0x00 */ ITEM_CHICK,
    /* 0x01 */ ITEM_FROG,
    /* 0x02 */ ITEM_LOSTDWARF,
    /* 0x03 */ ITEM_BANANAS,
    /* 0x04 */ ITEM_FURIOUSTORNADO,
    /* 0x05 */ ITEM_100YEAROLDBELL,
    /* 0x06 */ ITEM_100YEAROLDKEY,
    /* 0x07 */ ITEM_CHARITYWINGS,
    /* 0x08 */ ITEM_BITINGPLANTFLOWER,
    /* 0x09 */ ITEM_HEALINGMUSHROOM,
    /* 0x0A */ ITEM_BUCKET,
    /* 0x0B */ ITEM_TELESCOPE,
    /* 0x0C */ ITEM_TEARJAR,
    /* 0x0D */ ITEM_FLOWERTEARS,
    /* 0x0E */ ITEM_BARON,
    /* 0x0F */ ITEM_BAKEDYAM,
    /* 0x10 */ ITEM_LEAFBUTTERFLIES,
    /* 0x11 */ ITEM_TORCH,
    /* 0x12 */ ITEM_BUCKETOFWATER,
    /* 0x13 */ ITEM_DIRTYMIRROR,
    /* 0x14 */ ITEM_FUNKYPARASOL,
    /* 0x15 */ ITEM_WOODBOOMERANG,
    /* 0x16 */ ITEM_IRONBOOMERANG,
    /* 0x17 */ ITEM_STONEBOOMERANG,
    /* 0x18 */ ITEM_DASHINGPANTS,
    /* 0x19 */ ITEM_MAP,
    /* 0x1A */ ITEM_BROKENVASE,
    /* 0x1B */ ITEM_BLACKJACK,
    /* 0x1C */ ITEM_FLASHPANTS,
    /* 0x1D */ ITEM_JUMPINGPANTS,
    /* 0x1E */ ITEM_LUNCHBOX,
    /* 0x1F */ ITEM_LARGELUNCHBOX,
    /* 0x20 */ ITEM_NORMALPANTS,
    /* 0x21 */ ITEM_GRAPPLE,
    /* 0x22 */ ITEM_GRAPPLEJACK,
    /* 0x23 */ ITEM_BABYPIG,
    /* 0x24 */ ITEM_1000YEAROLDKEY,
    /* 0x25 */ ITEM_REDEVILPIGBAG,
    /* 0x26 */ ITEM_ORANGEEVILPIGBAG,
    /* 0x27 */ ITEM_YELLOWEVILPIGBAG,
    /* 0x28 */ ITEM_GREENVILPIGBAG,
    /* 0x29 */ ITEM_BLUEVILPIGBAG,
    /* 0x2A */ ITEM_NAVYVILPIGBAG,
    /* 0x2B */ ITEM_PINKVILPIGBAG,
    /* 0x2C */ ITEM_10000YEAROLDKEY,
    /* 0x2D */ ITEM_LARGEKEYPANEL1,
    /* 0x2E */ ITEM_LARGEKEYPANEL2,
    /* 0x2F */ ITEM_LARGEKEYPANEL3,
    /* 0x30 */ ITEM_LARGEKEYPANEL4,
    /* 0x31 */ ITEM_LARGEKEYPANEL5,
    /* 0x32 */ ITEM_FUELBAR,
    /* 0x33 */ ITEM_RAINESSENCE,
    /* 0x34 */ ITEM_BIGKEY,
    /* 0x35 */ ITEM_SMALLKEY,
    /* 0x36 */ ITEM_CHEESE,
    /* 0x37 */ ITEM_MAGICMIRROR,
    /* 0x38 */ ITEM_TORNMAP1,
    /* 0x39 */ ITEM_TORNMAP2,
    /* 0x3A */ ITEM_RUBBERGLOVES,
    /* 0x3B */ ITEM_BOMB,
    /* 0x3C */ ITEM_IRON,
    /* 0x3D */ ITEM_IRONWHEEL,
    /* 0x3E */ ITEM_FLOWERSEEDS,
    /* 0x3F */ ITEM_PIPE,
    /* 0x40 */ ITEM_WINE,
    /* 0x41 */ ITEM_BUNKFLOWER,
    /* 0x42 */ ITEM_MATHBEAD1,
    /* 0x43 */ ITEM_MATHBEAD2,
    /* 0x44 */ ITEM_MATHBEAD3,
    /* 0x45 */ ITEM_MATHBEAD4,
    /* 0x46 */ ITEM_MATHBEAD5,
    /* 0x47 */ ITEM_MATHBEAD6,
    /* 0x48 */ ITEM_MATHBEAD7,
    /* 0x49 */ ITEM_MATHBEAD8,
    /* 0x4A */ ITEM_MATHBEAD9,
    /* 0x4B */ ITEM_MATHBEAD10,
} ITEM;

typedef enum {
    /* 0x00 */ EVENT_GRANDPASBRACELET,
    /* 0x01 */ EVENT_THE100YEAROLDWISEMAN,
} EVENT;

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
