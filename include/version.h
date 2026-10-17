#ifndef _VERSION_H
#define _VERSION_H

#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
#define VERSION_PAL
#define NTSC_PAL(ntsc, pal) (pal)
#else
#define NTSC_PAL(ntsc, pal) (ntsc)
#endif

#if defined(VERSION_SLPS_01144)
#define VERSION_NTSC_J
#define NTSC_J(us, jp) (jp)
#else
#define NTSC_J(us, jp) (us)
#endif

#define SCREEN_HEIGHT NTSC_PAL(0xE0, 0x100)

#endif
