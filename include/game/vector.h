#ifndef GAME_VECTOR_H
#define GAME_VECTOR_H

/* Small vector types.
   Part of game.h: include "game.h", not this file. */

typedef struct {
    s16 x;
    s16 y;
} Vec2s;

typedef struct { s32 x, y, z; } Vec3L;

typedef struct {
    int x;
    int y;
    int z;
} VEC3;

#endif
