#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

/* Functions of the engine every code overlay carries at 0x800E7388
   (src/overlays/x00/engine*.c).
   Part of game.h: include "game.h", not this file. */

void func_800E7DF8(void *, s32, s32);
void func_800E8758(void *, s32, s32);
void func_800E8A30(void *, s32, s32);
void func_800ED788(GameObject *);
void func_800EDD9C(GameObject*);
void func_800EE50C(GameObject*);
void func_800EE7F0(char*);
void func_8010E750(GameObject *);
void func_8011032C(u8*);
void func_8011068C(char*);
void func_8011070C(GameObject*);

#endif
