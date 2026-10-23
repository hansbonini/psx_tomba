#ifndef _LIBSTAMP_H
#define _LIBSTAMP_H

/*
 * Every PSY-Q library starts its .data with 8 bytes that identify it:
 *
 *   0x0  u16 magic    "Ps" (0x50 0x73)
 *   0x2  u8  lib      library number (PsyqLib)
 *   0x3  u8  build    build of the package the library comes from: the same
 *                     for every library of one SDK (12 in the 3.7 the game
 *                     uses, 21 in 4.0); libpad, shipped on its own, has
 *                     its own (34 for 4.2.1, 40 for 4.3.1)
 *   0x4  u16 time     time the library was built, in the MS-DOS format:
 *                     hour << 11 | minute << 5 | second / 2
 *   0x6  u8  version  major.minor in BCD (0x37 = 3.7, 0x42 = 4.2)
 *   0x7  u8  patch    revision in the high nibble (0x10 = .1)
 *
 * libpad is 4.2.1 in SCUS-94236, SCES-01330 and the menu of SCES-01331, and
 * 4.3.1 in the MAINs of SCES-01331; SLPS-01144 links an older libpad
 * without a stamp. libapi follows it: 4.2.0 (build 33) and 4.3.0 (build
 * 37) in the same executables, and the 3.7 of the SDK in SLPS-01144.
 */

/* The libraries are numbered in alphabetical order. */
typedef enum PsyqLib {
    PSYQ_LIB_API  = 0x00, /* libapi */
    PSYQ_LIB_C2   = 0x02, /* libc2 */
    PSYQ_LIB_CARD = 0x03, /* libcard */
    PSYQ_LIB_CD   = 0x04, /* libcd */
    PSYQ_LIB_ETC  = 0x06, /* libetc */
    PSYQ_LIB_GPU  = 0x07, /* libgpu */
    PSYQ_LIB_GTE  = 0x09, /* libgte */
    PSYQ_LIB_PAD  = 0x0C, /* libpad */
} PsyqLib;

typedef struct PsyqStamp {
    /* 0x0 */ u16 magic;
    /* 0x2 */ u8 lib;
    /* 0x3 */ u8 build;
    /* 0x4 */ u16 time;
    /* 0x6 */ u8 version;
    /* 0x7 */ u8 patch;
} PsyqStamp;

#define PSYQ_STAMP_MAGIC 0x7350 /* "Ps" */

/* the build of the libraries of the SDK the game uses (3.7) */
#define PSYQ_SDK_BUILD 12

#define PSYQ_VERSION(major, minor)   (((major) << 4) | (minor))
#define PSYQ_PATCH(patch)            ((patch) << 4)
#define PSYQ_TIME(hour, min, sec)    (((hour) << 11) | ((min) << 5) | ((sec) / 2))

/* library lib, version major.minor.patch, package build, built at hour:min:sec */
#define PSYQ_STAMP(lib, major, minor, patch, build, hour, min, sec)                       \
    { PSYQ_STAMP_MAGIC, (lib), (build), PSYQ_TIME(hour, min, sec), PSYQ_VERSION(major, minor), \
      PSYQ_PATCH(patch) }

/* a library of the SDK the game uses: 3.7.0 */
#define PSYQ_SDK_STAMP(lib, hour, min, sec) PSYQ_STAMP(lib, 3, 7, 0, PSYQ_SDK_BUILD, hour, min, sec)

/* reading a stamp */
#define PSYQ_STAMP_IS_VALID(s)   ((s)->magic == PSYQ_STAMP_MAGIC)
#define PSYQ_VERSION_MAJOR(s)    ((s)->version >> 4)
#define PSYQ_VERSION_MINOR(s)    ((s)->version & 0xF)
#define PSYQ_VERSION_PATCH(s)    ((s)->patch >> 4)
#define PSYQ_TIME_HOUR(s)        ((s)->time >> 11)
#define PSYQ_TIME_MINUTE(s)      (((s)->time >> 5) & 0x3F)
#define PSYQ_TIME_SECOND(s)      (((s)->time & 0x1F) * 2)

/* the same fields read from the two words of a stamp */
#define PSYQ_STAMP_MAGIC_MASK    0x0000FFFF
#define PSYQ_STAMP_LIB_MASK      0x00FF0000
#define PSYQ_STAMP_LIB_SHIFT     16
#define PSYQ_STAMP_BUILD_MASK    0xFF000000
#define PSYQ_STAMP_BUILD_SHIFT   24
#define PSYQ_STAMP_TIME_MASK     0x0000FFFF
#define PSYQ_STAMP_VERSION_MASK  0x00FF0000
#define PSYQ_STAMP_VERSION_SHIFT 16
#define PSYQ_STAMP_PATCH_MASK    0xFF000000
#define PSYQ_STAMP_PATCH_SHIFT   24

#endif
