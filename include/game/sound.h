#ifndef GAME_SOUND_H
#define GAME_SOUND_H

/* Sound: BGM and SFX tables and the SFX command queue.
   Part of game.h: include "game.h", not this file. */

typedef struct {
    u8 seq;
    u8 vab;
    u8 fadeIn;
    u8 unk3;
} BgmDef;

typedef struct {
    u8 vab;
    u8 prog;
    u8 tone;
    u8 note;
    u8 volume;
    u8 priority;
    u8 pad[2];
} SfxDef;

typedef struct {
    u16 id;
    s16 arg;
} SfxQueueEntry;

#endif
