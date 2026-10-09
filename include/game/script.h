#ifndef GAME_SCRIPT_H
#define GAME_SCRIPT_H

/* Script interpreter context.
   Part of game.h: include "game.h", not this file. */

typedef struct ScriptContext {
    /* 0x0000 */ byte    data[0x88];
    /* 0x0088 */ u_char  state;
    /* 0x0089 */ u_char  cmpFlag;
    /* 0x008A */ u_short pc;
    /* 0x008C */ u_short sp;
    /* 0x008E */ byte    unk8E[2];
    /* 0x0090 */ int     stack[0x400];
    /* 0x1090 */ int     vars[0x40];
    /* 0x1190 */ short   result;
    /* 0x1192 */ short   unk1192;
    /* 0x1194 */ short   unk1194;
} ScriptContext;

#endif
