#ifndef GAME_MOVIE_H
#define GAME_MOVIE_H

/* Movie player.
   Part of game.h: include "game.h", not this file. */

typedef enum {
    MOVIE_STATE_IDLE     = 0,
    MOVIE_STATE_STARTING = 1,
    MOVIE_STATE_PLAYING  = 2,
    MOVIE_STATE_ENDING   = 3,
} MOVIE_STATE;

typedef struct {
    u_long* vlcbuf[2];
    int vlcid;
    u_short* imgbuf[2];
    int imgid;
    RECT rect[2];
    int rectid;
    RECT slice;
    int isdone;
} DecEnv;

#endif
