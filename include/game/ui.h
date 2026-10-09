#ifndef GAME_UI_H
#define GAME_UI_H

/* Inventory and title screen ids.
   Part of game.h: include "game.h", not this file. */

typedef enum {
    /* 0x0 */ INVENTORY_SCREEN_ITEM,
    /* 0x1 */ INVENTORY_SCREEN_EVENT,
    /* 0x2 */ INVENTORY_SCREEN_STATUS,
    /* 0x3 */ INVENTORY_SCREEN_MAP,
    /* 0x4 */ INVENTORY_SCREEN_ITEM_ONLY,
} INVENTORY_SCREEN_ID;

typedef enum {
    INVENTORY_SORT_MODE_1,
    INVENTORY_SORT_MODE_2,
    INVENTORY_SORT_MODE_3,
    INVENTORY_SORT_MODE_4,
    INVENTORY_SORT_MODE_DEFAULT = 0x8000,
} INVENTORY_SORT_MODE_ID;

typedef enum {
    TITLESCREEN_OPTION_NEWGAME,
    TITLESCREEN_OPTION_LOADGAME,
    TITLESCREEN_OPTION_OPTIONS
} TITLESCREEN_OPTION_ID;

typedef enum {
    TITLESCREEN_MESSAGE_PRESSSTART,
    TITLESCREEN_MESSAGE_WHOOPCAMPCOPYRIGHT,
} TITLESCREEN_MESSAGE_ID;

/* Sprite of the loading screens (drawutil.c). */
typedef struct {
    u_short u;
    u_short v;
    u_short w;
    u_short h;
    short clutX;
    short clutY;
} UiSpriteDef;

/* Sprite with its own tpage (boot.c). */
typedef struct {
    s16 x;
    s16 y;
    u8 u;
    u8 v;
    s16 w;
    s16 h;
    s16 tpage;
    s16 clutX;
    s16 clutY;
} unk_80076E40;

#endif
