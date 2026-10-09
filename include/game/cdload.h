#ifndef GAME_CDLOAD_H
#define GAME_CDLOAD_H

/* CD file table and the load records walked by queueLoadList / cdLoadTask.
   Part of game.h: include "game.h", not this file. */

typedef struct fileLink {
    /* 0x0 */ CdlLOC loc;
    /* 0x4 */ int    size;
} fileLink;

/* Load record, walked by queueLoadList until fileId == -1 and consumed by
   cdLoadTask. A record of type LOAD_TYPE_SUB names a piece inside the file
   of the record before it. */
typedef enum {
    /*0x10*/ LOAD_KIND_GRPX = 0x10, /* pixels sent to VRAM with LoadImage */
    /*0x20*/ LOAD_KIND_NONE = 0x20, /* nothing is registered */
    /*0x30*/ LOAD_KIND_SPR = 0x30, /* sprite frame definitions, SPR_DATA[n] */
    /*0x40*/ LOAD_KIND_FOUR = 0x40, /* unknown, FOUR_DATA[n] */
    /*0x50*/ LOAD_KIND_WMD = 0x50, /* 3D models, WMD_DATA[n] */
    /*0x60*/ LOAD_KIND_WPP = 0x60, /* packed sprite frames, WPP_DATA[n] */
    /*0x70*/ LOAD_KIND_WHM = 0x70, /* collision plane data, WHM_DATA[n] */
    /*0x80*/ LOAD_KIND_APD = 0x80, /* asset placement data, APD_DATA[n] */
    /*0x90*/ LOAD_KIND_WVD = 0x90, /* sound bank, WVD_BODIES[n] */
    /*0xA0*/ LOAD_KIND_UNKA = 0xA0, /* VAB headers of a sound bank, WVD_HEADERS[n] */
    /*0xB0*/ LOAD_KIND_SEQ = 0xB0, /* sequenced music, SEQ_DATA[n] */
    /*0xC0*/ LOAD_KIND_WSS = 0xC0, /* AREA15 files, WSS_DATA[n] */
    /*0xD0*/ LOAD_KIND_WFM3 = 0xD0, /* font and dialogues, WFM3_DATA[n] */
    /*0xF0*/ LOAD_KIND_INS = 0xF0, /* code overlay, loaded at 0x800E7388 */
    /*0xF8*/ LOAD_KIND_LDSYS = 0xF8  /* SYS/LDSYS.BIN, loaded at 0x80097FA8 */
} LoadKind;

typedef enum {
    /*0x00*/ LOAD_TYPE_STAGING = 0, /* read to the staging buffer; GRPX goes to LoadImage, WVD to the SPU */
    /*0x01*/ LOAD_TYPE_LZ_TO_VRAM = 1, /* read, lzDecompress to the staging buffer, LoadImage */
    /*0x02*/ LOAD_TYPE_RAW = 2, /* read to the destination */
    /*0x03*/ LOAD_TYPE_LZ_TO_RAM = 3, /* read to the staging buffer, lzDecompress to the destination */
    /*0x04*/ LOAD_TYPE_RAW_4 = 4, /* read to the destination */
    /*0x10*/ LOAD_TYPE_ALT_BUFFER = 0x10 /* flag: staging buffer is LOAD_BUFFER_ALT */
} LoadType;

#define LOAD_TYPE_SUB 0xFFFFFFFF
#define LOAD_XY(x, y) (((y) << 16) | (x))
#define LOAD_LIST_END { -1, 0, 0, 0, 0, 0, 0, 0 }

typedef struct LoadRecord {
    /* 0x00 */ s16 fileId; /* CdFile, index into FILE_LINKS */
    /* 0x02 */ u8  slot;   /* 0xFF none; < 0x80 saves the destination in LOAD_SLOTS, else reads it */
    /* 0x03 */ u8  kind;   /* LoadKind | index in the table of that kind */
    /* 0x04 */ u32 addr;   /* destination, 0 = after the previous record */
    /* 0x08 */ u32 arg;    /* size in bytes, or LOAD_XY(x, y) for LOAD_KIND_GRPX */
    /* 0x0C */ s16 w;
    /* 0x0E */ s16 h;      /* for LOAD_KIND_WVD, index into SPU_BANK_ADDRS */
    /* 0x10 */ u32 type;   /* LoadType, or LOAD_TYPE_SUB */
} LoadRecord;

#endif
