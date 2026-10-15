#include "common.h"
#include "game.h"
#include "game/gte.h"

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80024CFC);

typedef struct {
    u16 clut, tpage;
    unsigned long c0;
    u16 p8[3];
    u16 uv0;
    u16 p10[3];
    u16 uv1;
    u16 p18[3];
    u16 uv2;
} Face_24CFC;
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned short x2, y2;
    unsigned short uv2, pad;
} PolyFT3_22120;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0;
    unsigned short p8[3];
    unsigned short uv0;
    unsigned short p10[3];
    unsigned short uv1;
    unsigned short p18[3];
    unsigned short uv2;
} Face_22120;

extern PolyFT3_22120 *D_1F800164__80024CFC;
extern long LZ_FILE_CTRL__80024CFC;
extern char *D_1F80008C__80024CFC;
extern unsigned long *D_1F8001E0__80024CFC;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_gt3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_80024CFC(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_22120 *p;
    Face_22120 *e;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x7000000;
        do {

            gte_ldv3c(vtx + 8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80024CFC);
            if (LZ_FILE_CTRL__80024CFC >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80024CFC);
                if (LZ_FILE_CTRL__80024CFC > 0) {
                    p = D_1F800164__80024CFC;
                    gte_stsxy3_gt3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80024CFC) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = ((Face_22120 *)f)->c0;
                            p->clut = ((Face_22120 *)f)->clut;
                            p->tpage = ((Face_22120 *)f)->tpage;
                            p->uv0 = ((Face_22120 *)f)->uv0;
                            p->uv1 = ((Face_22120 *)f)->uv1;
                            *(unsigned short *)((char *)p + 0x1c) = ((Face_22120 *)f)->uv2;
                            D_1F800164__80024CFC = D_1F800164__80024CFC + 1;
                        }
                    }
                }
            }
            f += 8;
            vtx += 0x20;
        } while (--n != 0);
    }
    D_1F80008C__80024CFC = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_gt3
#undef gte_avsz3
#undef gte_stotz
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned short x2, y2;
    unsigned short uv2, pad;
} PolyFT3_2216C;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0;
    unsigned short p8[3];
    unsigned short uv0;
    unsigned short p10[3];
    unsigned short uv1;
    unsigned short p18[3];
    unsigned short uv2;
} Face_2216C;

extern PolyFT3_2216C *D_1F800164__80024CFC;
extern long LZ_FILE_CTRL__80024CFC;
extern char *D_1F80008C__80024CFC;
extern unsigned long *D_1F8001E0__80024CFC;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_gt3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_80024CFC(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_2216C *p;
    Face_2216C *e;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x7000000;
        do {

            gte_ldv3c(vtx + 8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80024CFC);
            if (LZ_FILE_CTRL__80024CFC >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80024CFC);
                if (LZ_FILE_CTRL__80024CFC > 0) {
                    p = D_1F800164__80024CFC;
                    gte_stsxy3_gt3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80024CFC) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = ((Face_2216C *)f)->c0;
                            p->clut = ((Face_2216C *)f)->clut;
                            p->tpage = ((Face_2216C *)f)->tpage;
                            p->uv0 = ((Face_2216C *)f)->uv0;
                            p->uv1 = ((Face_2216C *)f)->uv1;
                            *(unsigned short *)((char *)p + 0x1c) = ((Face_2216C *)f)->uv2;
                            D_1F800164__80024CFC = D_1F800164__80024CFC + 1;
                        }
                    }
                }
            }
            f += 8;
            vtx += 0x20;
        } while (--n != 0);
    }
    D_1F80008C__80024CFC = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_gt3
#undef gte_avsz3
#undef gte_stotz
#else
char *func_80024CFC(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_FT3 *p;
    Face_24CFC *e;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x7000000;
        do {

            gte_ldv3c(vtx + 8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (POLY_FT3 *)D_1F800164;
                    gte_stsxy3_ft3(p);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            (*(u32 *)&p->r0) = ((Face_24CFC *)f)->c0;
                            p->clut = ((Face_24CFC *)f)->clut;
                            p->tpage = ((Face_24CFC *)f)->tpage;
                            (*(u16 *)&p->u0) = ((Face_24CFC *)f)->uv0;
                            (*(u16 *)&p->u1) = ((Face_24CFC *)f)->uv1;
                            *(u16 *)((char *)p + 0x1c) = ((Face_24CFC *)f)->uv2;
                            D_1F800164 = (u8 *)((POLY_FT3 *)D_1F800164 + 1);
                        }
                    }
                }
            }
            f += 8;
            vtx += 0x20;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80024EEC);

typedef struct {
    u16 clut, tpage;
    unsigned long c0;
    u16 p08[3];
    u16 uv0;
    u16 p10[3];
    u16 uv1;
    u16 p18[3];
    u16 uv2;
    u16 p20[3];
    u16 uv3;
} Face_24EEC;
extern unsigned long *D_1F8001E0_UnsignedLongPtrArr[] asm("D_1F8001E0");



#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned short x2, y2;
    unsigned short uv2, pad2;
    unsigned short x3, y3;
    unsigned short uv3, pad3;
} PolyFT4_22310;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0;
    unsigned short p08[3];
    unsigned short uv0;
    unsigned short p10[3];
    unsigned short uv1;
    unsigned short p18[3];
    unsigned short uv2;
    unsigned short p20[3];
    unsigned short uv3;
} Face_22310;

extern PolyFT4_22310 *D_1F800164__80024EEC;
extern long LZ_FILE_CTRL__80024EEC;
extern char *D_1F80008C__80024EEC;
extern unsigned long *D_1F8001E0__80024EEC_2;
extern unsigned long *D_1F8001E0__80024EEC[];

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_ft4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy2(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")

char *func_80024EEC(GameObject *o, long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT4_22310 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {
            gte_ldv3c(vtx + 0x8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80024EEC);
            if (LZ_FILE_CTRL__80024EEC >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80024EEC);
                if (LZ_FILE_CTRL__80024EEC > 0) {
                    p = D_1F800164__80024EEC;
                    gte_stsxy3_ft4(p);
                    gte_ldv0(vtx + 0x20);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__80024EEC);
                    if (LZ_FILE_CTRL__80024EEC >= 0) {
                        gte_stsxy2(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            p->c0 = ((Face_22310 *)f)->c0;
                            p->clut = ((Face_22310 *)f)->clut;
                            p->tpage = ((Face_22310 *)f)->tpage;
                            if (o != 0 && (o->category & 0xf) == 8 && o->type == 1) {
                                p->uv0 = o->hitOffsetX;
                                p->uv1 = o->hitWidth;
                                p->uv2 = o->hitOffsetY;
                                p->uv3 = o->hitHeight;
                                otz = (long)D_1F8001E0__80024EEC[0] + 0xc;
                            } else {
                                otz = (otz << 2) + (long)ot;
                                if ((unsigned long)(otz - (long)D_1F8001E0__80024EEC_2) >= 0xca0) goto next;
                                p->uv0 = ((Face_22310 *)f)->uv0;
                                p->uv1 = ((Face_22310 *)f)->uv1;
                                p->uv2 = ((Face_22310 *)f)->uv2;
                                p->uv3 = ((Face_22310 *)f)->uv3;
                            }
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            D_1F800164__80024EEC = D_1F800164__80024EEC + 1;
                        }
                    }
                }
            }
        next:
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80024EEC = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_ft4
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy2
#undef gte_avsz4
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned short x2, y2;
    unsigned short uv2, pad2;
    unsigned short x3, y3;
    unsigned short uv3, pad3;
} PolyFT4_2235C;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0;
    unsigned short p08[3];
    unsigned short uv0;
    unsigned short p10[3];
    unsigned short uv1;
    unsigned short p18[3];
    unsigned short uv2;
    unsigned short p20[3];
    unsigned short uv3;
} Face_2235C;

extern PolyFT4_2235C *D_1F800164__80024EEC;
extern long LZ_FILE_CTRL__80024EEC;
extern char *D_1F80008C__80024EEC;
extern unsigned long *D_1F8001E0__80024EEC_2;
extern unsigned long *D_1F8001E0__80024EEC[];

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_ft4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy2(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")

char *func_80024EEC(GameObject *o, long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT4_2235C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {
            gte_ldv3c(vtx + 0x8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80024EEC);
            if (LZ_FILE_CTRL__80024EEC >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80024EEC);
                if (LZ_FILE_CTRL__80024EEC > 0) {
                    p = D_1F800164__80024EEC;
                    gte_stsxy3_ft4(p);
                    gte_ldv0(vtx + 0x20);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__80024EEC);
                    if (LZ_FILE_CTRL__80024EEC >= 0) {
                        gte_stsxy2(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            p->c0 = ((Face_2235C *)f)->c0;
                            p->clut = ((Face_2235C *)f)->clut;
                            p->tpage = ((Face_2235C *)f)->tpage;
                            if (o != 0 && (o->category & 0xf) == 8 && o->type == 1) {
                                p->uv0 = o->hitOffsetX;
                                p->uv1 = o->hitWidth;
                                p->uv2 = o->hitOffsetY;
                                p->uv3 = o->hitHeight;
                                otz = (long)D_1F8001E0__80024EEC[0] + 0xc;
                            } else {
                                otz = (otz << 2) + (long)ot;
                                if ((unsigned long)(otz - (long)D_1F8001E0__80024EEC_2) >= 0xca0) goto next;
                                p->uv0 = ((Face_2235C *)f)->uv0;
                                p->uv1 = ((Face_2235C *)f)->uv1;
                                p->uv2 = ((Face_2235C *)f)->uv2;
                                p->uv3 = ((Face_2235C *)f)->uv3;
                            }
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            D_1F800164__80024EEC = D_1F800164__80024EEC + 1;
                        }
                    }
                }
            }
        next:
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80024EEC = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_ft4
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy2
#undef gte_avsz4
#else
char *func_80024EEC(GameObject *o, long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_FT4 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {
            gte_ldv3c(vtx + 0x8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (POLY_FT4 *)D_1F800164;
                    gte_stsxy3_ft4(p);
                    gte_ldv0(vtx + 0x20);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if (LZ_FILE_CTRL_Long >= 0) {
                        gte_stsxy2(&p->x3);
                        if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0 || (u16)p->y3 < 0xE0) &&
                            ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            (*(u32 *)&p->r0) = ((Face_24EEC *)f)->c0;
                            p->clut = ((Face_24EEC *)f)->clut;
                            p->tpage = ((Face_24EEC *)f)->tpage;
                            if (o != 0 && (o->category & 0xf) == 8 && o->type == 1) {
                                (*(u16 *)&p->u0) = o->hitOffsetX;
                                (*(u16 *)&p->u1) = o->hitWidth;
                                (*(u16 *)&p->u2) = o->hitOffsetY;
                                (*(u16 *)&p->u3) = o->hitHeight;
                                otz = (long)D_1F8001E0_UnsignedLongPtrArr[0] + 0xc;
                            } else {
                                otz = (otz << 2) + (long)ot;
                                if ((unsigned long)(otz - (long)D_1F8001E0) >= 0xca0) goto next;
                                (*(u16 *)&p->u0) = ((Face_24EEC *)f)->uv0;
                                (*(u16 *)&p->u1) = ((Face_24EEC *)f)->uv1;
                                (*(u16 *)&p->u2) = ((Face_24EEC *)f)->uv2;
                                (*(u16 *)&p->u3) = ((Face_24EEC *)f)->uv3;
                            }
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
                        }
                    }
                }
            }
        next:
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_800251C0);

typedef struct {
    u16 clut, tpage;
    unsigned long c0, c1, c2;
    u16 p10[3];
    u16 uv0;
    u16 p18[3];
    u16 uv1;
    u16 p20[3];
    u16 uv2;
} Face_251C0;


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned short uv2, pad;
} PolyGT3_225E4;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0, c1, c2;
    unsigned short p10[3];
    unsigned short uv0;
    unsigned short p18[3];
    unsigned short uv1;
    unsigned short p20[3];
    unsigned short uv2;
} Face_225E4;

extern PolyGT3_225E4 *D_1F800164__800251C0;
extern long LZ_FILE_CTRL__800251C0;
extern char *D_1F80008C__800251C0;
extern unsigned long *D_1F8001E0__800251C0;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_gt3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 20( %0 );swc2 $14, 32( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_800251C0(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyGT3_225E4 *p;
    Face_225E4 *e;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {

            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__800251C0);
            if (LZ_FILE_CTRL__800251C0 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__800251C0);
                if (LZ_FILE_CTRL__800251C0 > 0) {
                    p = D_1F800164__800251C0;
                    gte_stsxy3_gt3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__800251C0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = ((Face_225E4 *)f)->c0;
                            p->c1 = ((Face_225E4 *)f)->c1;
                            p->c2 = ((Face_225E4 *)f)->c2;
                            p->clut = ((Face_225E4 *)f)->clut;
                            p->tpage = ((Face_225E4 *)f)->tpage;
                            p->uv0 = ((Face_225E4 *)f)->uv0;
                            p->uv1 = ((Face_225E4 *)f)->uv1;
                            *(unsigned short *)((char *)p + 0x24) = ((Face_225E4 *)f)->uv2;
                            D_1F800164__800251C0 = D_1F800164__800251C0 + 1;
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__800251C0 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_gt3
#undef gte_avsz3
#undef gte_stotz
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned short uv2, pad;
} PolyGT3_22630;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0, c1, c2;
    unsigned short p10[3];
    unsigned short uv0;
    unsigned short p18[3];
    unsigned short uv1;
    unsigned short p20[3];
    unsigned short uv2;
} Face_22630;

extern PolyGT3_22630 *D_1F800164__800251C0;
extern long LZ_FILE_CTRL__800251C0;
extern char *D_1F80008C__800251C0;
extern unsigned long *D_1F8001E0__800251C0;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_gt3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 20( %0 );swc2 $14, 32( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_800251C0(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyGT3_22630 *p;
    Face_22630 *e;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {

            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__800251C0);
            if (LZ_FILE_CTRL__800251C0 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__800251C0);
                if (LZ_FILE_CTRL__800251C0 > 0) {
                    p = D_1F800164__800251C0;
                    gte_stsxy3_gt3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__800251C0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = ((Face_22630 *)f)->c0;
                            p->c1 = ((Face_22630 *)f)->c1;
                            p->c2 = ((Face_22630 *)f)->c2;
                            p->clut = ((Face_22630 *)f)->clut;
                            p->tpage = ((Face_22630 *)f)->tpage;
                            p->uv0 = ((Face_22630 *)f)->uv0;
                            p->uv1 = ((Face_22630 *)f)->uv1;
                            *(unsigned short *)((char *)p + 0x24) = ((Face_22630 *)f)->uv2;
                            D_1F800164__800251C0 = D_1F800164__800251C0 + 1;
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__800251C0 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_gt3
#undef gte_avsz3
#undef gte_stotz
#else
char *func_800251C0(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_GT3 *p;
    Face_251C0 *e;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {

            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (POLY_GT3 *)D_1F800164;
                    gte_stsxy3_gt3(p);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            (*(u32 *)&p->r0) = ((Face_251C0 *)f)->c0;
                            (*(u32 *)&p->r1) = ((Face_251C0 *)f)->c1;
                            (*(u32 *)&p->r2) = ((Face_251C0 *)f)->c2;
                            p->clut = ((Face_251C0 *)f)->clut;
                            p->tpage = ((Face_251C0 *)f)->tpage;
                            (*(u16 *)&p->u0) = ((Face_251C0 *)f)->uv0;
                            (*(u16 *)&p->u1) = ((Face_251C0 *)f)->uv1;
                            *(u16 *)((char *)p + 0x24) = ((Face_251C0 *)f)->uv2;
                            D_1F800164 = (u8 *)((POLY_GT3 *)D_1F800164 + 1);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_800253C8);

typedef struct {
    u16 clut, tpage;
    unsigned long c0, c1, c2;
    unsigned long c3;
    u16 p14[3];
    u16 uv0;
    u16 p1c[3];
    u16 uv1;
    u16 p24[3];
    u16 uv2;
    u16 p2c[3];
    u16 uv3;
} Face_253C8;



#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned short uv2, pad;
    unsigned long c3;
    unsigned short x3, y3;
    unsigned short uv3, pad3;
} PolyGT3_227EC;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0, c1, c2;
    unsigned long c3;
    unsigned short p14[3];
    unsigned short uv0;
    unsigned short p1c[3];
    unsigned short uv1;
    unsigned short p24[3];
    unsigned short uv2;
    unsigned short p2c[3];
    unsigned short uv3;
} Face_227EC;

extern PolyGT3_227EC *D_1F800164__800253C8;
extern long LZ_FILE_CTRL__800253C8;
extern char *D_1F80008C__800253C8;
extern unsigned long *D_1F8001E0__800253C8;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_gt3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 20( %0 );swc2 $14, 32( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy2(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")

char *func_800253C8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyGT3_227EC *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0xc000000;
        do {
            gte_ldv3c(vtx + 0x14);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__800253C8);
            if (LZ_FILE_CTRL__800253C8 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__800253C8);
                if (LZ_FILE_CTRL__800253C8 > 0) {
                    p = D_1F800164__800253C8;
                    gte_stsxy3_gt3(p);
                    gte_ldv0(vtx + 0x2c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__800253C8);
                    if (LZ_FILE_CTRL__800253C8 >= 0) {
                        gte_stsxy2(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0__800253C8) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                p->c0 = ((Face_227EC *)f)->c0;
                                p->c1 = ((Face_227EC *)f)->c1;
                                p->c2 = ((Face_227EC *)f)->c2;
                                p->c3 = ((Face_227EC *)f)->c3;
                                p->clut = ((Face_227EC *)f)->clut;
                                p->tpage = ((Face_227EC *)f)->tpage;
                                p->uv0 = ((Face_227EC *)f)->uv0;
                                p->uv1 = ((Face_227EC *)f)->uv1;
                                p->uv2 = ((Face_227EC *)f)->uv2;
                                *(unsigned short *)((char *)p + 0x30) = ((Face_227EC *)f)->uv3;
                                D_1F800164__800253C8 = D_1F800164__800253C8 + 1;
                            }
                        }
                    }
                }
            }
            f += 13;
            vtx += 0x34;
        } while (--n != 0);
    }
    D_1F80008C__800253C8 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_gt3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy2
#undef gte_avsz4
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short uv0, clut;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned short uv1, tpage;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned short uv2, pad;
    unsigned long c3;
    unsigned short x3, y3;
    unsigned short uv3, pad3;
} PolyGT3_22838;

typedef struct {
    unsigned short clut, tpage;
    unsigned long c0, c1, c2;
    unsigned long c3;
    unsigned short p14[3];
    unsigned short uv0;
    unsigned short p1c[3];
    unsigned short uv1;
    unsigned short p24[3];
    unsigned short uv2;
    unsigned short p2c[3];
    unsigned short uv3;
} Face_22838;

extern PolyGT3_22838 *D_1F800164__800253C8;
extern long LZ_FILE_CTRL__800253C8;
extern char *D_1F80008C__800253C8;
extern unsigned long *D_1F8001E0__800253C8;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_gt3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 20( %0 );swc2 $14, 32( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy2(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")

char *func_800253C8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyGT3_22838 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0xc000000;
        do {
            gte_ldv3c(vtx + 0x14);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__800253C8);
            if (LZ_FILE_CTRL__800253C8 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__800253C8);
                if (LZ_FILE_CTRL__800253C8 > 0) {
                    p = D_1F800164__800253C8;
                    gte_stsxy3_gt3(p);
                    gte_ldv0(vtx + 0x2c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__800253C8);
                    if (LZ_FILE_CTRL__800253C8 >= 0) {
                        gte_stsxy2(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0__800253C8) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                p->c0 = ((Face_22838 *)f)->c0;
                                p->c1 = ((Face_22838 *)f)->c1;
                                p->c2 = ((Face_22838 *)f)->c2;
                                p->c3 = ((Face_22838 *)f)->c3;
                                p->clut = ((Face_22838 *)f)->clut;
                                p->tpage = ((Face_22838 *)f)->tpage;
                                p->uv0 = ((Face_22838 *)f)->uv0;
                                p->uv1 = ((Face_22838 *)f)->uv1;
                                p->uv2 = ((Face_22838 *)f)->uv2;
                                *(unsigned short *)((char *)p + 0x30) = ((Face_22838 *)f)->uv3;
                                D_1F800164__800253C8 = D_1F800164__800253C8 + 1;
                            }
                        }
                    }
                }
            }
            f += 13;
            vtx += 0x34;
        } while (--n != 0);
    }
    D_1F80008C__800253C8 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_gt3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy2
#undef gte_avsz4
#else
char *func_800253C8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_GT4 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0xc000000;
        do {
            gte_ldv3c(vtx + 0x14);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (POLY_GT4 *)D_1F800164;
                    gte_stsxy3_gt3(p);
                    gte_ldv0(vtx + 0x2c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if (LZ_FILE_CTRL_Long >= 0) {
                        gte_stsxy2(&p->x3);
                        if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0 || (u16)p->y3 < 0xE0) &&
                            ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                (*(u32 *)&p->r0) = ((Face_253C8 *)f)->c0;
                                (*(u32 *)&p->r1) = ((Face_253C8 *)f)->c1;
                                (*(u32 *)&p->r2) = ((Face_253C8 *)f)->c2;
                                (*(u32 *)&p->r3) = ((Face_253C8 *)f)->c3;
                                p->clut = ((Face_253C8 *)f)->clut;
                                p->tpage = ((Face_253C8 *)f)->tpage;
                                (*(u16 *)&p->u0) = ((Face_253C8 *)f)->uv0;
                                (*(u16 *)&p->u1) = ((Face_253C8 *)f)->uv1;
                                (*(u16 *)&p->u2) = ((Face_253C8 *)f)->uv2;
                                *(u16 *)((char *)p + 0x30) = ((Face_253C8 *)f)->uv3;
                                D_1F800164 = (u8 *)((POLY_GT4 *)D_1F800164 + 1);
                            }
                        }
                    }
                }
            }
            f += 13;
            vtx += 0x34;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_8002564C);


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned char r0, g0, b0, code;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_22A70;

extern PolyF3_22A70 *D_1F800164__8002564C;
extern long LZ_FILE_CTRL__8002564C;
extern char *D_1F80008C__8002564C;
extern unsigned long *D_1F8001E0__8002564C;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")

char *func_8002564C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_22A70 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = D_1F800164__8002564C;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__8002564C);
            if (LZ_FILE_CTRL__8002564C >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__8002564C);
                if (LZ_FILE_CTRL__8002564C > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__8002564C) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->r0);
                            D_1F800164__8002564C = D_1F800164__8002564C + 1;
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__8002564C = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned char r0, g0, b0, code;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_22ABC;

extern PolyF3_22ABC *D_1F800164__8002564C;
extern long LZ_FILE_CTRL__8002564C;
extern char *D_1F80008C__8002564C;
extern unsigned long *D_1F8001E0__8002564C;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")

char *func_8002564C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_22ABC *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = D_1F800164__8002564C;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__8002564C);
            if (LZ_FILE_CTRL__8002564C >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__8002564C);
                if (LZ_FILE_CTRL__8002564C > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__8002564C) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->r0);
                            D_1F800164__8002564C = D_1F800164__8002564C + 1;
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__8002564C = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#else
char *func_8002564C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_F3 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (POLY_F3 *)D_1F800164;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->r0);
                            D_1F800164 = (u8 *)((POLY_F3 *)D_1F800164 + 1);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80025810);


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned char r0, g0, b0, code;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
    unsigned short x3, y3;
} PolyF3_22C34;

extern PolyF3_22C34 *D_1F800164__80025810;
extern long LZ_FILE_CTRL__80025810;
extern char *D_1F80008C__80025810;
extern unsigned long *D_1F8001E0__80025810;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy2(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")

char *func_80025810(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_22C34 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x5000000;
        do {
            p = D_1F800164__80025810;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025810);
            if (LZ_FILE_CTRL__80025810 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025810);
                if (LZ_FILE_CTRL__80025810 > 0) {
                    gte_stsxy3_f3(p);
                    gte_ldv0(vtx + 0x1c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__80025810);
                    if (LZ_FILE_CTRL__80025810 < 0) goto next;
                    gte_stsxy2(&p->x3);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80025810) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x2c);
                            gte_ldv0((char *)f + 0x24);
                            gte_nccs();
                            gte_strgb(&p->r0);
                            D_1F800164__80025810 = D_1F800164__80025810 + 1;
                        }
                    }
                }
            }
        next:
            f += 12;
            vtx += 0x30;
        } while (--n != 0);
    }
    D_1F80008C__80025810 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz4
#undef gte_rtps
#undef gte_stsxy2
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned char r0, g0, b0, code;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
    unsigned short x3, y3;
} PolyF3_22C80;

extern PolyF3_22C80 *D_1F800164__80025810;
extern long LZ_FILE_CTRL__80025810;
extern char *D_1F80008C__80025810;
extern unsigned long *D_1F8001E0__80025810;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy2(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")

char *func_80025810(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_22C80 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x5000000;
        do {
            p = D_1F800164__80025810;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025810);
            if (LZ_FILE_CTRL__80025810 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025810);
                if (LZ_FILE_CTRL__80025810 > 0) {
                    gte_stsxy3_f3(p);
                    gte_ldv0(vtx + 0x1c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__80025810);
                    if (LZ_FILE_CTRL__80025810 < 0) goto next;
                    gte_stsxy2(&p->x3);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80025810) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x2c);
                            gte_ldv0((char *)f + 0x24);
                            gte_nccs();
                            gte_strgb(&p->r0);
                            D_1F800164__80025810 = D_1F800164__80025810 + 1;
                        }
                    }
                }
            }
        next:
            f += 12;
            vtx += 0x30;
        } while (--n != 0);
    }
    D_1F80008C__80025810 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz4
#undef gte_rtps
#undef gte_stsxy2
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#else
char *func_80025810(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_F4 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x5000000;
        do {
            p = (POLY_F4 *)D_1F800164;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    gte_ldv0(vtx + 0x1c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if (LZ_FILE_CTRL_Long < 0) goto next;
                    gte_stsxy2(&p->x3);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0 || (u16)p->y3 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140)) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x2c);
                            gte_ldv0((char *)f + 0x24);
                            gte_nccs();
                            gte_strgb(&p->r0);
                            D_1F800164 = (u8 *)((POLY_F4 *)D_1F800164 + 1);
                        }
                    }
                }
            }
        next:
            f += 12;
            vtx += 0x30;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80025A38);


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned char r0, g0, b0, code;
    unsigned short x0, y0;
    unsigned char r1, g1, b1, p1;
    unsigned short x1, y1;
    unsigned char r2, g2, b2, p2;
    unsigned short x2, y2;
} PolyF3_22E5C;

extern PolyF3_22E5C *D_1F800164__80025A38;
extern long LZ_FILE_CTRL__80025A38;
extern char *D_1F80008C__80025A38;
extern unsigned long *D_1F8001E0__80025A38;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb3_g3(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")

char *func_80025A38(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_22E5C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 12);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025A38);
            if (LZ_FILE_CTRL__80025A38 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025A38);
                if (LZ_FILE_CTRL__80025A38 > 0) {
                    p = D_1F800164__80025A38;
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80025A38) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164__80025A38 = D_1F800164__80025A38 + 1;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80025A38 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_ncct
#undef gte_strgb3_g3
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned char r0, g0, b0, code;
    unsigned short x0, y0;
    unsigned char r1, g1, b1, p1;
    unsigned short x1, y1;
    unsigned char r2, g2, b2, p2;
    unsigned short x2, y2;
} PolyF3_22EA8;

extern PolyF3_22EA8 *D_1F800164__80025A38;
extern long LZ_FILE_CTRL__80025A38;
extern char *D_1F80008C__80025A38;
extern unsigned long *D_1F8001E0__80025A38;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb3_g3(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")

char *func_80025A38(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_22EA8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 12);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025A38);
            if (LZ_FILE_CTRL__80025A38 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025A38);
                if (LZ_FILE_CTRL__80025A38 > 0) {
                    p = D_1F800164__80025A38;
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80025A38) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164__80025A38 = D_1F800164__80025A38 + 1;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80025A38 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_ncct
#undef gte_strgb3_g3
#else
char *func_80025A38(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_G3 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 12);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (POLY_G3 *)D_1F800164;
                    gte_stsxy3_ft3(p);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164 = (u8 *)((POLY_G3 *)D_1F800164 + 1);
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80025C14);


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned long c3;
    unsigned short x3, y3;
} PolyG4_23038;

extern PolyG4_23038 *D_1F800164__80025C14;
extern long LZ_FILE_CTRL__80025C14;
extern char *D_1F80008C__80025C14;
extern unsigned long *D_1F8001E0__80025C14;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb3_g4(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")

char *func_80025C14(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG4_23038 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x8000000;
        do {
            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025C14);
            if (LZ_FILE_CTRL__80025C14 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025C14);
                if (LZ_FILE_CTRL__80025C14 > 0) {
                    p = D_1F800164__80025C14;
                    gte_stsxy3_g4(p);
                    gte_ldv0(vtx + 0x28);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__80025C14);
                    if (LZ_FILE_CTRL__80025C14 >= 0) {
                        gte_stsxy(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0__80025C14) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                gte_ldrgb((char *)f + 0x50);
                                gte_ldv0((char *)f + 0x48);
                                gte_nccs();
                                gte_strgb(&p->c3);
                                gte_ldv3c((char *)f + 0x30);
                                gte_ncct();
                                gte_strgb3_g4(p);
                                D_1F800164__80025C14 = D_1F800164__80025C14 + 1;
                            }
                        }
                    }
                }
            }
            f += 21;
            vtx += 0x54;
        } while (--n != 0);
    }
    D_1F80008C__80025C14 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_rtps
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_g4
#undef gte_stsxy
#undef gte_avsz4
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#undef gte_ncct
#undef gte_strgb3_g4
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned long c3;
    unsigned short x3, y3;
} PolyG4_23084;

extern PolyG4_23084 *D_1F800164__80025C14;
extern long LZ_FILE_CTRL__80025C14;
extern char *D_1F80008C__80025C14;
extern unsigned long *D_1F8001E0__80025C14;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb3_g4(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")

char *func_80025C14(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG4_23084 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x8000000;
        do {
            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025C14);
            if (LZ_FILE_CTRL__80025C14 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025C14);
                if (LZ_FILE_CTRL__80025C14 > 0) {
                    p = D_1F800164__80025C14;
                    gte_stsxy3_g4(p);
                    gte_ldv0(vtx + 0x28);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__80025C14);
                    if (LZ_FILE_CTRL__80025C14 >= 0) {
                        gte_stsxy(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0__80025C14) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                gte_ldrgb((char *)f + 0x50);
                                gte_ldv0((char *)f + 0x48);
                                gte_nccs();
                                gte_strgb(&p->c3);
                                gte_ldv3c((char *)f + 0x30);
                                gte_ncct();
                                gte_strgb3_g4(p);
                                D_1F800164__80025C14 = D_1F800164__80025C14 + 1;
                            }
                        }
                    }
                }
            }
            f += 21;
            vtx += 0x54;
        } while (--n != 0);
    }
    D_1F80008C__80025C14 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_rtps
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_g4
#undef gte_stsxy
#undef gte_avsz4
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#undef gte_ncct
#undef gte_strgb3_g4
#else
char *func_80025C14(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_G4 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x8000000;
        do {
            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (POLY_G4 *)D_1F800164;
                    gte_stsxy3_g4(p);
                    gte_ldv0(vtx + 0x28);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if (LZ_FILE_CTRL_Long >= 0) {
                        gte_stsxy(&p->x3);
                        if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0 || (u16)p->y3 < 0xE0) &&
                            ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                gte_ldrgb((char *)f + 0x50);
                                gte_ldv0((char *)f + 0x48);
                                gte_nccs();
                                gte_strgb(&(*(u32 *)&p->r3));
                                gte_ldv3c((char *)f + 0x30);
                                gte_ncct();
                                gte_strgb3_g4(p);
                                D_1F800164 = (u8 *)((POLY_G4 *)D_1F800164 + 1);
                            }
                        }
                    }
                }
            }
            f += 21;
            vtx += 0x54;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80025E74);


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_23298;

extern PolyF3_23298 *D_1F800164__80025E74;
extern long LZ_FILE_CTRL__80025E74;
extern char *D_1F80008C__80025E74;
extern unsigned long *D_1F8001E0__80025E74;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_80025E74(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_23298 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = D_1F800164__80025E74;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025E74);
            if (LZ_FILE_CTRL__80025E74 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025E74);
                if (LZ_FILE_CTRL__80025E74 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80025E74) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            *(unsigned long *)((char *)p + 4) = *f;
                            D_1F800164__80025E74 = D_1F800164__80025E74 + 1;
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80025E74 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz3
#undef gte_stotz
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_232E4;

extern PolyF3_232E4 *D_1F800164__80025E74;
extern long LZ_FILE_CTRL__80025E74;
extern char *D_1F80008C__80025E74;
extern unsigned long *D_1F8001E0__80025E74;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_80025E74(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_232E4 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = D_1F800164__80025E74;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80025E74);
            if (LZ_FILE_CTRL__80025E74 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80025E74);
                if (LZ_FILE_CTRL__80025E74 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80025E74) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            *(unsigned long *)((char *)p + 4) = *f;
                            D_1F800164__80025E74 = D_1F800164__80025E74 + 1;
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80025E74 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_avsz3
#undef gte_stotz
#else
char *func_80025E74(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_F3 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (POLY_F3 *)D_1F800164;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            *(unsigned long *)((char *)p + 4) = *f;
                            D_1F800164 = (u8 *)((POLY_F3 *)D_1F800164 + 1);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_8002601C);


#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
    unsigned short x3, y3;
} PolyF4_23440;

extern PolyF4_23440 *D_1F800164__8002601C;
extern long LZ_FILE_CTRL__8002601C;
extern char *D_1F80008C__8002601C;
extern unsigned long *D_1F8001E0__8002601C;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_8002601C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF4_23440 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x5000000;
        do {
            p = D_1F800164__8002601C;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__8002601C);
            if (LZ_FILE_CTRL__8002601C >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__8002601C);
                if (LZ_FILE_CTRL__8002601C > 0) {
                    gte_stsxy3_f3(p);
                    gte_ldv0(vtx + 0x1c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__8002601C);
                    if (LZ_FILE_CTRL__8002601C >= 0) {
                    gte_stsxy(&p->x3);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__8002601C) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            *(unsigned long *)((char *)p + 4) = *f;
                            D_1F800164__8002601C = D_1F800164__8002601C + 1;
                        }
                    }
                    }
                }
            }
            f += 12;
            vtx += 0x30;
        } while (--n != 0);
    }
    D_1F80008C__8002601C = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy
#undef gte_avsz4
#undef gte_avsz3
#undef gte_stotz
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
    unsigned short x3, y3;
} PolyF4_2348C;

extern PolyF4_2348C *D_1F800164__8002601C;
extern long LZ_FILE_CTRL__8002601C;
extern char *D_1F80008C__8002601C;
extern unsigned long *D_1F8001E0__8002601C;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

char *func_8002601C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF4_2348C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x5000000;
        do {
            p = D_1F800164__8002601C;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__8002601C);
            if (LZ_FILE_CTRL__8002601C >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__8002601C);
                if (LZ_FILE_CTRL__8002601C > 0) {
                    gte_stsxy3_f3(p);
                    gte_ldv0(vtx + 0x1c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__8002601C);
                    if (LZ_FILE_CTRL__8002601C >= 0) {
                    gte_stsxy(&p->x3);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__8002601C) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            *(unsigned long *)((char *)p + 4) = *f;
                            D_1F800164__8002601C = D_1F800164__8002601C + 1;
                        }
                    }
                    }
                }
            }
            f += 12;
            vtx += 0x30;
        } while (--n != 0);
    }
    D_1F80008C__8002601C = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy
#undef gte_avsz4
#undef gte_avsz3
#undef gte_stotz
#else
char *func_8002601C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_F4 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x5000000;
        do {
            p = (POLY_F4 *)D_1F800164;
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    gte_ldv0(vtx + 0x1c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if (LZ_FILE_CTRL_Long >= 0) {
                    gte_stsxy(&p->x3);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0 || (u16)p->y3 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140)) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            *(unsigned long *)((char *)p + 4) = *f;
                            D_1F800164 = (u8 *)((POLY_F4 *)D_1F800164 + 1);
                        }
                    }
                    }
                }
            }
            f += 12;
            vtx += 0x30;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80026228);



#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
} PolyG3_2364C;

extern PolyG3_2364C *D_1F800164__80026228;

extern long LZ_FILE_CTRL__80026228;
extern char *D_1F80008C__80026228;
extern unsigned long *D_1F8001E0__80026228;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_stsxy3_g3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")

char *func_80026228(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG3_2364C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = D_1F800164__80026228;
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026228);
            if (LZ_FILE_CTRL__80026228 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026228);
                if (LZ_FILE_CTRL__80026228 > 0) {
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026228) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->c1 = f[1];
                            *(unsigned long *)((char *)p + 0x14) = f[2];
                            D_1F800164__80026228 = D_1F800164__80026228 + 1;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026228 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy
#undef gte_avsz4
#undef gte_avsz3
#undef gte_stotz
#undef gte_stsxy3_g3
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
} PolyG3_23698;

extern PolyG3_23698 *D_1F800164__80026228;

extern long LZ_FILE_CTRL__80026228;
extern char *D_1F80008C__80026228;
extern unsigned long *D_1F8001E0__80026228;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_stsxy3_g3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")

char *func_80026228(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG3_23698 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = D_1F800164__80026228;
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026228);
            if (LZ_FILE_CTRL__80026228 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026228);
                if (LZ_FILE_CTRL__80026228 > 0) {
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026228) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->c1 = f[1];
                            *(unsigned long *)((char *)p + 0x14) = f[2];
                            D_1F800164__80026228 = D_1F800164__80026228 + 1;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026228 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy
#undef gte_avsz4
#undef gte_avsz3
#undef gte_stotz
#undef gte_stsxy3_g3
#else
char *func_80026228(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_G3 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (POLY_G3 *)D_1F800164;
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_g3(p);
                    if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0) &&
                        ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            (*(u32 *)&p->r0) = f[0];
                            (*(u32 *)&p->r1) = f[1];
                            *(unsigned long *)((char *)p + 0x14) = f[2];
                            D_1F800164 = (u8 *)((POLY_G3 *)D_1F800164 + 1);
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_800263F0);



typedef struct { char pad[0xe]; u8 b0e; } O;
typedef struct { long c[4]; } C4_263F0;
extern C4_263F0 D_8007C160[];

#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned long c3;
    unsigned short x3, y3;
} PolyG4_23814;

extern PolyG4_23814 *D_1F800164__800263F0;

extern long LZ_FILE_CTRL__800263F0;
extern char *D_1F80008C__800263F0;
extern unsigned long *D_1F8001E0__800263F0;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_stsxy3_g3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")

typedef struct { char pad[0xe]; unsigned char b0e; } O_23814;
typedef struct { long c[4]; } C4_23814;
extern C4_23814 D_80079148__sces01330[];

char *func_800263F0(O_23814 *o, long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG4_23814 *p;
    unsigned long len;
    unsigned long t;
    int i;

    n = *f++;
    if (n != 0) {
        len = 0x8000000;
        do {
            p = D_1F800164__800263F0;
            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__800263F0);
            if (LZ_FILE_CTRL__800263F0 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__800263F0);
                if (LZ_FILE_CTRL__800263F0 > 0) {
                    gte_stsxy3_g3(p);
                    gte_ldv0(vtx + 0x28);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__800263F0);
                    if (LZ_FILE_CTRL__800263F0 >= 0) {
                        gte_stsxy(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0__800263F0) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                if (o == 0 || o->b0e == 0) {
                                    p->c0 = f[0];
                                    p->c1 = f[1];
                                    p->c2 = f[2];
                                    p->c3 = f[3];
                                } else {
                                    i = 0x12 - n;
                                    p->c0 = D_80079148__sces01330[i].c[0];
                                    p->c1 = D_80079148__sces01330[i].c[1];
                                    p->c2 = D_80079148__sces01330[i].c[2];
                                    p->c3 = D_80079148__sces01330[i].c[3];
                                }
                                D_1F800164__800263F0 = D_1F800164__800263F0 + 1;
                            }
                        }
                    }
                }
            }
            f += 21;
            vtx += 0x54;
        } while (--n != 0);
    }
    D_1F80008C__800263F0 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy
#undef gte_avsz4
#undef gte_avsz3
#undef gte_stotz
#undef gte_stsxy3_g3
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
    unsigned long c3;
    unsigned short x3, y3;
} PolyG4_23860;

extern PolyG4_23860 *D_1F800164__800263F0;

extern long LZ_FILE_CTRL__800263F0;
extern char *D_1F80008C__800263F0;
extern unsigned long *D_1F8001E0__800263F0;

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

#define gte_stsxy3_g3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")

typedef struct { char pad[0xe]; unsigned char b0e; } O_23860;
typedef struct { long c[4]; } C4_23860;
extern C4_23860 D_8007965C__sces01331[];

char *func_800263F0(O_23860 *o, long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG4_23860 *p;
    unsigned long len;
    unsigned long t;
    int i;

    n = *f++;
    if (n != 0) {
        len = 0x8000000;
        do {
            p = D_1F800164__800263F0;
            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__800263F0);
            if (LZ_FILE_CTRL__800263F0 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__800263F0);
                if (LZ_FILE_CTRL__800263F0 > 0) {
                    gte_stsxy3_g3(p);
                    gte_ldv0(vtx + 0x28);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL__800263F0);
                    if (LZ_FILE_CTRL__800263F0 >= 0) {
                        gte_stsxy(&p->x3);
                        if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100 || p->y3 < 0x100) &&
                            (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0__800263F0) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                if (o == 0 || o->b0e == 0) {
                                    p->c0 = f[0];
                                    p->c1 = f[1];
                                    p->c2 = f[2];
                                    p->c3 = f[3];
                                } else {
                                    i = 0x12 - n;
                                    p->c0 = D_8007965C__sces01331[i].c[0];
                                    p->c1 = D_8007965C__sces01331[i].c[1];
                                    p->c2 = D_8007965C__sces01331[i].c[2];
                                    p->c3 = D_8007965C__sces01331[i].c[3];
                                }
                                D_1F800164__800263F0 = D_1F800164__800263F0 + 1;
                            }
                        }
                    }
                }
            }
            f += 21;
            vtx += 0x54;
        } while (--n != 0);
    }
    D_1F80008C__800263F0 = vtx;
    return (char *)f;
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_ldv0
#undef gte_rtps
#undef gte_stsxy
#undef gte_avsz4
#undef gte_avsz3
#undef gte_stotz
#undef gte_stsxy3_g3
#else
char *func_800263F0(O *o, long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    POLY_G4 *p;
    unsigned long len;
    unsigned long t;
    s32 i;

    n = *f++;
    if (n != 0) {
        len = 0x8000000;
        do {
            p = (POLY_G4 *)D_1F800164;
            gte_ldv3c(vtx + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_g3(p);
                    gte_ldv0(vtx + 0x28);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if (LZ_FILE_CTRL_Long >= 0) {
                        gte_stsxy(&p->x3);
                        if (((u16)p->y0 < 0xE0 || (u16)p->y1 < 0xE0 || (u16)p->y2 < 0xE0 || (u16)p->y3 < 0xE0) &&
                            ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140)) {
                            gte_avsz4();
                            gte_stotz(&otz);
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                                t = *(unsigned long *)otz;
                                *(unsigned long *)otz = (unsigned long)p;
                                p->tag = t | len;
                                if (o == 0 || o->b0e == 0) {
                                    (*(u32 *)&p->r0) = f[0];
                                    (*(u32 *)&p->r1) = f[1];
                                    (*(u32 *)&p->r2) = f[2];
                                    (*(u32 *)&p->r3) = f[3];
                                } else {
                                    i = 0x12 - n;
                                    (*(u32 *)&p->r0) = D_8007C160[i].c[0];
                                    (*(u32 *)&p->r1) = D_8007C160[i].c[1];
                                    (*(u32 *)&p->r2) = D_8007C160[i].c[2];
                                    (*(u32 *)&p->r3) = D_8007C160[i].c[3];
                                }
                                D_1F800164 = (u8 *)((POLY_G4 *)D_1F800164 + 1);
                            }
                        }
                    }
                }
            }
            f += 21;
            vtx += 0x54;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80026694);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 x1, y1;
    u16 x2, y2;
} PolyF3_26694;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    unsigned long w0c;
    u16 x1, y1;
    unsigned long w14;
    u16 x2, y2;
} PolyFT3_26694;
extern char *D_1F800164_CharPtrArr[] asm("D_1F800164");


static __inline__ char *drawF3_26694(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyF3_26694 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + sizeof(PolyF3_26694);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_26694(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyFT3_26694 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->w0c = f[1];
                            p->w14 = f[2];
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}

static __inline__ char *drawF3L_26694(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyF3_26694 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->c0);
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + sizeof(PolyF3_26694);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}

static __inline__ char *drawG3L_26694(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyFT3_26694 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (void *)D_1F800164_CharPtrArr[0];
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}

#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_23AB8;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long w0c;
    unsigned short x1, y1;
    unsigned long w14;
    unsigned short x2, y2;
} PolyFT3_23AB8;

extern char *D_1F800164__80026694[];
extern long LZ_FILE_CTRL__80026694;
extern char *D_1F80008C__80026694;
extern unsigned long *D_1F8001E0__80026694;
extern char *func_80024CFC__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_80024EEC__80026694(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_800251C0__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_800253C8__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_8002601C__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_800263F0__80026694(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_80025810__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_80025C14__80026694(char *f, char *vtx, unsigned long *ot);

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_ft3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb3_g3(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

static __inline__ char *drawF3_23AB8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_23AB8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026694[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + sizeof(PolyF3_23AB8);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_23AB8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_23AB8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164__80026694[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->w0c = f[1];
                            p->w14 = f[2];
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

static __inline__ char *drawF3L_23AB8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_23AB8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026694[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->c0);
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + sizeof(PolyF3_23AB8);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

static __inline__ char *drawG3L_23AB8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_23AB8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    p = (void *)D_1F800164__80026694[0];
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

void func_80026694(char *f, unsigned long *ot, void *o, unsigned char lit)
{
    f = func_80024CFC__80026694(f, f + 4, ot);
    f = func_80024EEC__80026694(o, f, f + 4, ot);
    f = func_800251C0__80026694(f, f + 4, ot);
    f = func_800253C8__80026694(f, f + 4, ot);
    if (lit) {
        f = drawF3L_23AB8((long *)f, f + 4, ot);
        f = func_80025810__80026694(f, f + 4, ot);
        f = drawG3L_23AB8((long *)f, f + 4, ot);
        func_80025C14__80026694(f, f + 4, ot);
    } else {
        f = drawF3_23AB8((long *)f, f + 4, ot);
        f = func_8002601C__80026694(f, f + 4, ot);
        f = drawFT3_23AB8((long *)f, f + 4, ot);
        func_800263F0__80026694(o, f, f + 4, ot);
    }
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_stsxy3_ft3
#undef gte_avsz3
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#undef gte_ncct
#undef gte_strgb3_g3
#undef gte_stotz
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_23B04;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long w0c;
    unsigned short x1, y1;
    unsigned long w14;
    unsigned short x2, y2;
} PolyFT3_23B04;

extern char *D_1F800164__80026694[];
extern long LZ_FILE_CTRL__80026694;
extern char *D_1F80008C__80026694;
extern unsigned long *D_1F8001E0__80026694;
extern char *func_80024CFC__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_80024EEC__80026694(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_800251C0__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_800253C8__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_8002601C__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_800263F0__80026694(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_80025810__80026694(char *f, char *vtx, unsigned long *ot);
extern char *func_80025C14__80026694(char *f, char *vtx, unsigned long *ot);

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_ft3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb3_g3(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

static __inline__ char *drawF3_23B04(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_23B04 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026694[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + sizeof(PolyF3_23B04);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_23B04(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_23B04 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164__80026694[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->w0c = f[1];
                            p->w14 = f[2];
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

static __inline__ char *drawF3L_23B04(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_23B04 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026694[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->c0);
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + sizeof(PolyF3_23B04);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

static __inline__ char *drawG3L_23B04(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_23B04 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026694);
            if (LZ_FILE_CTRL__80026694 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026694);
                if (LZ_FILE_CTRL__80026694 > 0) {
                    p = (void *)D_1F800164__80026694[0];
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026694) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164__80026694[0] = D_1F800164__80026694[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026694 = vtx;
    return (char *)f;
}

void func_80026694(char *f, unsigned long *ot, void *o, unsigned char lit)
{
    f = func_80024CFC__80026694(f, f + 4, ot);
    f = func_80024EEC__80026694(o, f, f + 4, ot);
    f = func_800251C0__80026694(f, f + 4, ot);
    f = func_800253C8__80026694(f, f + 4, ot);
    if (lit) {
        f = drawF3L_23B04((long *)f, f + 4, ot);
        f = func_80025810__80026694(f, f + 4, ot);
        f = drawG3L_23B04((long *)f, f + 4, ot);
        func_80025C14__80026694(f, f + 4, ot);
    } else {
        f = drawF3_23B04((long *)f, f + 4, ot);
        f = func_8002601C__80026694(f, f + 4, ot);
        f = drawFT3_23B04((long *)f, f + 4, ot);
        func_800263F0__80026694(o, f, f + 4, ot);
    }
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_stsxy3_ft3
#undef gte_avsz3
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_strgb
#undef gte_ncct
#undef gte_strgb3_g3
#undef gte_stotz
#else
void func_80026694(char *f, unsigned long *ot, void *o, u8 lit)
{
    f = func_80024CFC(f, f + 4, ot);
    f = func_80024EEC(o, f, f + 4, ot);
    f = func_800251C0(f, f + 4, ot);
    f = func_800253C8(f, f + 4, ot);
    if (lit) {
        f = drawF3L_26694((long *)f, f + 4, ot);
        f = func_80025810(f, f + 4, ot);
        f = drawG3L_26694((long *)f, f + 4, ot);
        func_80025C14(f, f + 4, ot);
    } else {
        f = drawF3_26694((long *)f, f + 4, ot);
        f = func_8002601C(f, f + 4, ot);
        f = drawFT3_26694((long *)f, f + 4, ot);
        func_800263F0(o, f, f + 4, ot);
    }
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80026E48);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 x1, y1;
    u16 x2, y2;
} PolyF3_26E48;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    unsigned long c1;
    u16 x1, y1;
    unsigned long c2;
    u16 x2, y2;
} PolyG3_26E48;
extern char *volatile D_1F80008C_CharPtrVolatile asm("D_1F80008C");


static __inline__ char *drawF3_26E48(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyF3_26E48 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + sizeof(PolyF3_26E48);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    ((char **)&D_1F80008C)[0] = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_26E48(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyG3_26E48 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->c1 = f[1];
                            p->c2 = f[2];
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C_CharPtrVolatile = vtx;
    return (char *)f;
}

static __inline__ char *litF3_26E48(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyF3_26E48 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->c0);
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + sizeof(PolyF3_26E48);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    ((char **)&D_1F80008C)[0] = vtx;
    return (char *)f;
}

static __inline__ char *litG3_26E48(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyG3_26E48 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = (void *)D_1F800164_CharPtrArr[0];
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C_CharPtrVolatile = vtx;
    return (char *)f;
}

#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_2426C;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
} PolyG3_2426C;

extern char *D_1F800164__80026E48[];
extern long LZ_FILE_CTRL__80026E48;
extern char *D_1F80008C__80026E48[];
extern char *volatile D_1F80008C__80026E48_2;
extern unsigned long *D_1F8001E0__80026E48;
extern char *func_80024CFC__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_80024EEC__80026E48(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_800251C0__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_800253C8__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_80025810__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_80025C14__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_8002601C__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_800263F0__80026E48(void *o, char *f, char *vtx, unsigned long *ot);

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_g3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")
#define gte_strgb3_g3(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")

static __inline__ char *drawF3_2426C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_2426C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026E48[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + sizeof(PolyF3_2426C);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026E48[0] = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_2426C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG3_2426C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164__80026E48[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->c1 = f[1];
                            p->c2 = f[2];
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026E48_2 = vtx;
    return (char *)f;
}

static __inline__ char *litF3_2426C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_2426C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026E48[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->c0);
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + sizeof(PolyF3_2426C);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026E48[0] = vtx;
    return (char *)f;
}

static __inline__ char *litG3_2426C(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG3_2426C *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    p = (void *)D_1F800164__80026E48[0];
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026E48_2 = vtx;
    return (char *)f;
}

void func_80026E48(char *f, unsigned long *ot, void *o, char *x, unsigned char lit)
{
    char **v = D_1F80008C__80026E48;

    f = func_80024CFC__80026E48(f, x, ot);
    f = func_80024EEC__80026E48(o, f, *v, ot);
    f = func_800251C0__80026E48(f, *v, ot);
    f = func_800253C8__80026E48(f, *v, ot);
    if (lit) {
        char **w;
        f = litF3_2426C((long *)f, *v, ot);
        w = D_1F80008C__80026E48;
        f = func_80025810__80026E48(f, *w, ot);
        f = litG3_2426C((long *)f, *w, ot);
        func_80025C14__80026E48(f, D_1F80008C__80026E48_2, ot);
    } else {
        char **w;
        f = drawF3_2426C((long *)f, *v, ot);
        w = D_1F80008C__80026E48;
        f = func_8002601C__80026E48(f, *w, ot);
        f = drawFT3_2426C((long *)f, *w, ot);
        func_800263F0__80026E48(o, f, D_1F80008C__80026E48_2, ot);
    }
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_stsxy3_g3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_ncct
#undef gte_strgb
#undef gte_strgb3_g3
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_242B8;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long c1;
    unsigned short x1, y1;
    unsigned long c2;
    unsigned short x2, y2;
} PolyG3_242B8;

extern char *D_1F800164__80026E48[];
extern long LZ_FILE_CTRL__80026E48;
extern char *D_1F80008C__80026E48[];
extern char *volatile D_1F80008C__80026E48_2;
extern unsigned long *D_1F8001E0__80026E48;
extern char *func_80024CFC__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_80024EEC__80026E48(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_800251C0__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_800253C8__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_80025810__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_80025C14__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_8002601C__80026E48(char *f, char *vtx, unsigned long *ot);
extern char *func_800263F0__80026E48(void *o, char *f, char *vtx, unsigned long *ot);

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_g3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_ldrgb(r0) __asm__ volatile ("lwc2 $6, 0( %0 )" : : "r"(r0))
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_nccs() __asm__ volatile ("nop;nop;.word 0x4b08041b")
#define gte_ncct() __asm__ volatile ("nop;nop;.word 0x4b18043f")
#define gte_strgb(r0) __asm__ volatile ("swc2 $22, 0( %0 )" : : "r"(r0) : "memory")
#define gte_strgb3_g3(r0) __asm__ volatile ("swc2 $20, 4( %0 );swc2 $21, 12( %0 );swc2 $22, 20( %0 )" : : "r"(r0) : "memory")

static __inline__ char *drawF3_242B8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_242B8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026E48[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + sizeof(PolyF3_242B8);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026E48[0] = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_242B8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG3_242B8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164__80026E48[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->c1 = f[1];
                            p->c2 = f[2];
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026E48_2 = vtx;
    return (char *)f;
}

static __inline__ char *litF3_242B8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_242B8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80026E48[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x24);
                            gte_ldv0((char *)f + 0x1c);
                            gte_nccs();
                            gte_strgb(&p->c0);
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + sizeof(PolyF3_242B8);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80026E48[0] = vtx;
    return (char *)f;
}

static __inline__ char *litG3_242B8(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyG3_242B8 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80026E48);
            if (LZ_FILE_CTRL__80026E48 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80026E48);
                if (LZ_FILE_CTRL__80026E48 > 0) {
                    p = (void *)D_1F800164__80026E48[0];
                    gte_stsxy3_g3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80026E48) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            gte_ldrgb((char *)f + 0x3c);
                            gte_ldv3c((char *)f + 0x24);
                            gte_ncct();
                            gte_strgb3_g3(p);
                            D_1F800164__80026E48[0] = D_1F800164__80026E48[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80026E48_2 = vtx;
    return (char *)f;
}

void func_80026E48(char *f, unsigned long *ot, void *o, char *x, unsigned char lit)
{
    char **v = D_1F80008C__80026E48;

    f = func_80024CFC__80026E48(f, x, ot);
    f = func_80024EEC__80026E48(o, f, *v, ot);
    f = func_800251C0__80026E48(f, *v, ot);
    f = func_800253C8__80026E48(f, *v, ot);
    if (lit) {
        char **w;
        f = litF3_242B8((long *)f, *v, ot);
        w = D_1F80008C__80026E48;
        f = func_80025810__80026E48(f, *w, ot);
        f = litG3_242B8((long *)f, *w, ot);
        func_80025C14__80026E48(f, D_1F80008C__80026E48_2, ot);
    } else {
        char **w;
        f = drawF3_242B8((long *)f, *v, ot);
        w = D_1F80008C__80026E48;
        f = func_8002601C__80026E48(f, *w, ot);
        f = drawFT3_242B8((long *)f, *w, ot);
        func_800263F0__80026E48(o, f, D_1F80008C__80026E48_2, ot);
    }
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_stsxy3_g3
#undef gte_avsz3
#undef gte_stotz
#undef gte_ldrgb
#undef gte_ldv0
#undef gte_nccs
#undef gte_ncct
#undef gte_strgb
#undef gte_strgb3_g3
#else
void func_80026E48(char *f, unsigned long *ot, void *o, char *x, u8 lit)
{
    char **v = ((char **)&D_1F80008C);

    f = func_80024CFC(f, x, ot);
    f = func_80024EEC(o, f, *v, ot);
    f = func_800251C0(f, *v, ot);
    f = func_800253C8(f, *v, ot);
    if (lit) {
        char **w;
        f = litF3_26E48((long *)f, *v, ot);
        w = ((char **)&D_1F80008C);
        f = func_80025810(f, *w, ot);
        f = litG3_26E48((long *)f, *w, ot);
        func_80025C14(f, D_1F80008C_CharPtrVolatile, ot);
    } else {
        char **w;
        f = drawF3_26E48((long *)f, *v, ot);
        w = ((char **)&D_1F80008C);
        f = func_8002601C(f, *w, ot);
        f = drawFT3_26E48((long *)f, *w, ot);
        func_800263F0(o, f, D_1F80008C_CharPtrVolatile, ot);
    }
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80027600);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 x1, y1;
    u16 x2, y2;
} PolyF3_27600;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    unsigned long w0c;
    u16 x1, y1;
    unsigned long w14;
    u16 x2, y2;
} PolyFT3_27600;


static __inline__ char *drawF3_27600(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyF3_27600 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + sizeof(PolyF3_27600);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_27600(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyFT3_27600 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164_CharPtrArr[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0xE0 || p->y1 < 0xE0 || p->y2 < 0xE0) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->w0c = f[1];
                            p->w14 = f[2];
                            D_1F800164_CharPtrArr[0] = D_1F800164_CharPtrArr[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C = vtx;
    return (char *)f;
}

#if defined(VERSION_SCES_01330)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_24A24;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long w0c;
    unsigned short x1, y1;
    unsigned long w14;
    unsigned short x2, y2;
} PolyFT3_24A24;

extern char *D_1F800164__80027600[];
extern long LZ_FILE_CTRL__80027600;
extern char *D_1F80008C__80027600;
extern unsigned long *D_1F8001E0__80027600;
extern char *func_80024CFC__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_80024EEC__80027600(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_800251C0__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_800253C8__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_8002601C__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_800263F0__80027600(void *o, char *f, char *vtx, unsigned long *ot);

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_ft3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

static __inline__ char *drawF3_24A24(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_24A24 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80027600[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80027600);
            if (LZ_FILE_CTRL__80027600 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80027600);
                if (LZ_FILE_CTRL__80027600 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80027600) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164__80027600[0] = D_1F800164__80027600[0] + sizeof(PolyF3_24A24);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80027600 = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_24A24(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_24A24 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164__80027600[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80027600);
            if (LZ_FILE_CTRL__80027600 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80027600);
                if (LZ_FILE_CTRL__80027600 > 0) {
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80027600) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->w0c = f[1];
                            p->w14 = f[2];
                            D_1F800164__80027600[0] = D_1F800164__80027600[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80027600 = vtx;
    return (char *)f;
}

void func_80027600(char *f, unsigned long *ot)
{
    f = func_80024CFC__80027600(f, f + 4, ot);
    f = func_80024EEC__80027600(0, f, f + 4, ot);
    f = func_800251C0__80027600(f, f + 4, ot);
    f = func_800253C8__80027600(f, f + 4, ot);
    f = drawF3_24A24((long *)f, f + 4, ot);
    f = func_8002601C__80027600(f, f + 4, ot);
    f = drawFT3_24A24((long *)f, f + 4, ot);
    func_800263F0__80027600(0, f, f + 4, ot);
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_stsxy3_ft3
#undef gte_avsz3
#undef gte_stotz
#elif defined(VERSION_SCES_01331)
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned short x1, y1;
    unsigned short x2, y2;
} PolyF3_24A70;
typedef struct {
    unsigned long tag;
    unsigned long c0;
    unsigned short x0, y0;
    unsigned long w0c;
    unsigned short x1, y1;
    unsigned long w14;
    unsigned short x2, y2;
} PolyFT3_24A70;

extern char *D_1F800164__80027600[];
extern long LZ_FILE_CTRL__80027600;
extern char *D_1F80008C__80027600;
extern unsigned long *D_1F8001E0__80027600;
extern char *func_80024CFC__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_80024EEC__80027600(void *o, char *f, char *vtx, unsigned long *ot);
extern char *func_800251C0__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_800253C8__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_8002601C__80027600(char *f, char *vtx, unsigned long *ot);
extern char *func_800263F0__80027600(void *o, char *f, char *vtx, unsigned long *ot);

#define gte_ldv3c(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 8( %0 );lwc2 $3, 12( %0 );lwc2 $4, 16( %0 );lwc2 $5, 20( %0 )" : : "r"(r0))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stflg(r0) __asm__ volatile ("cfc2 $12, $31;nop;sw $12, 0( %0 )" : : "r"(r0) : "$12", "memory")
#define gte_nclip() __asm__ volatile ("nop;nop;.word 0x4b400006")
#define gte_stopz(r0) __asm__ volatile ("swc2 $24, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_f3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 12( %0 );swc2 $14, 16( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy3_ft3(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")

static __inline__ char *drawF3_24A70(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyF3_24A70 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x4000000;
        do {
            p = (void *)D_1F800164__80027600[0];
            gte_ldv3c(vtx + 4);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80027600);
            if (LZ_FILE_CTRL__80027600 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80027600);
                if (LZ_FILE_CTRL__80027600 > 0) {
                    gte_stsxy3_f3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80027600) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            D_1F800164__80027600[0] = D_1F800164__80027600[0] + sizeof(PolyF3_24A70);
                        }
                    }
                }
            }
            f += 10;
            vtx += 0x28;
        } while (--n != 0);
    }
    D_1F80008C__80027600 = vtx;
    return (char *)f;
}

static __inline__ char *drawFT3_24A70(long *f, char *vtx, unsigned long *ot)
{
    long otz;
    int n;
    PolyFT3_24A70 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x6000000;
        do {
            p = (void *)D_1F800164__80027600[0];
            gte_ldv3c(vtx + 0xc);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL__80027600);
            if (LZ_FILE_CTRL__80027600 >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL__80027600);
                if (LZ_FILE_CTRL__80027600 > 0) {
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0x100 || p->y1 < 0x100 || p->y2 < 0x100) &&
                        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140)) {
                        gte_avsz3();
                        gte_stotz(&otz);
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0__80027600) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            p->c0 = f[0];
                            p->w0c = f[1];
                            p->w14 = f[2];
                            D_1F800164__80027600[0] = D_1F800164__80027600[0] + 0x1c;
                        }
                    }
                }
            }
            f += 16;
            vtx += 0x40;
        } while (--n != 0);
    }
    D_1F80008C__80027600 = vtx;
    return (char *)f;
}

void func_80027600(char *f, unsigned long *ot)
{
    f = func_80024CFC__80027600(f, f + 4, ot);
    f = func_80024EEC__80027600(0, f, f + 4, ot);
    f = func_800251C0__80027600(f, f + 4, ot);
    f = func_800253C8__80027600(f, f + 4, ot);
    f = drawF3_24A70((long *)f, f + 4, ot);
    f = func_8002601C__80027600(f, f + 4, ot);
    f = drawFT3_24A70((long *)f, f + 4, ot);
    func_800263F0__80027600(0, f, f + 4, ot);
}
#undef gte_ldv3c
#undef gte_rtpt
#undef gte_stflg
#undef gte_nclip
#undef gte_stopz
#undef gte_stsxy3_f3
#undef gte_stsxy3_ft3
#undef gte_avsz3
#undef gte_stotz
#else
void func_80027600(char *f, unsigned long *ot)
{
    f = func_80024CFC(f, f + 4, ot);
    f = func_80024EEC(0, f, f + 4, ot);
    f = func_800251C0(f, f + 4, ot);
    f = func_800253C8(f, f + 4, ot);
    f = drawF3_27600((long *)f, f + 4, ot);
    f = func_8002601C(f, f + 4, ot);
    f = drawFT3_27600((long *)f, f + 4, ot);
    func_800263F0(0, f, f + 4, ot);
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", func_800279E8);
void func_800279E8(u8* arg0, s32 arg1, s32 arg2)
{
    u8* r;

    arg0 += 4;
    r = func_80024EEC(arg2, arg0, arg0 + 4, arg1);
    func_80025C14(r + 0x14, r + 0x18, arg1);
}

// INCLUDE_ASM("nonmatchings/main/render/ui", subtractScaledVertices);
void subtractScaledVertices(u8* dst, u8* src, s32 scale)
{
    s32 n;

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xA) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x20;
            src += 0x20;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xA) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x28;
            src += 0x28;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x28;
            src += 0x30;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x26) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x28) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x2C) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x2E) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x30) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x34;
            src += 0x40;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x4) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x6) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x28;
            src += 0x20;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x4) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x6) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x30;
            src += 0x28;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x40;
            src += 0x30;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x28) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x2A) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x2C) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x54;
            src += 0x40;
        } while (--n != 0);
    }
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80028638);
void func_80028638(s32 *src, char *dst)
{
    u16 sz[8];
    s16 i = 0;
    s32 v;
    u16 *p;
    sz[0] = 0x20; sz[1] = 0x28; sz[2] = 0x28; sz[3] = 0x34;
    sz[4] = 0x28; sz[5] = 0x30; sz[6] = 0x40; sz[7] = 0x54;
    do {
        v = *src++;
        if (v != 0) {
            p = (u16 *)(((i << 16) >> 15) + (s32)sz);
            *p = *p * v;
            memcpy(dst, src, *p);
            dst += *p & 0xfffc;
            src = (s32 *)((char *)src + (*p & 0xfffc));
        }
        i++;
    } while (i < 8);
}
#if defined(VERSION_SCES_01330)
extern char D_8009F2E0__sces01330;
extern unsigned short D_1F8003DA__sces01330;
extern int PadInfoMode(int, int, int);
extern void PadSetMainMode(int, int, int);

void func_80025B4C_sces01330(void)
{
    if (D_8009F2E0__sces01330 == 0 && PadInfoMode(0, 2, 0) != 0 && D_1F8003DA__sces01330 == 7)
        PadSetMainMode(0, 1, 0);
}
#endif
#if defined(VERSION_SCES_01331)
extern char D_8009EB58__80025B98_sces01331;
extern unsigned short D_1F8003DA__sces01331;
extern int func_8006911C__sces01331(int, int, int);
extern void func_800693C8__sces01331(int, int, int);

void func_80025B98_sces01331(void)
{
    if (D_8009EB58__80025B98_sces01331 == 0 && func_8006911C__sces01331(0, 2, 0) != 0 && D_1F8003DA__sces01331 == 7)
        func_800693C8__sces01331(0, 1, 0);
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/ui", joypadInit);
void joypadInit(void)
{
    D_8009C97A = 1;
    D_8009C97C = 0;
    D_8009C97D = 0;
    D_8009C97E = 0;
    D_8009C97F = 0;
    D_8009C982 = 0;
    D_8009C983 = 0;
    PadInitDirect(&D_8009EB58, &D_8009EB58 + 0x22);
    ((void (*)())PadStartCom)();
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80028794);
s16 func_80028794(u8* p, s16 mode)
{
    u8  v = *p;
    s32 a;
    s32 b;
    s32 r = 0;

    switch (mode) {
    case 0:
        a = 0x80;
        b = 0x20;
        break;
    case 1:
        a = 0x10;
        b = 0x40;
        break;
    }
    if (v == 0) {
        r = a;
    }
    if (v == 0xFF) {
        r = b;
    }
    return r;
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_800287F8);
s16 func_800287F8(u8 *p, s16 mode)
{
    u8 v = *p;
    s16 hi, lo, r;
    u16 t;
    u16 w;

    switch (mode) {
    case 0:
        hi = 0x80;
        lo = 0x20;
        break;
    case 1:
        hi = 0x10;
        lo = 0x40;
        break;
    }
    w = v;
    *p = 0;
    if ((u32)(w - 0x50) < 0x60) {
        return 0;
    }
    t = w - 0x30;
    if (t < 0xa0) {
        *p = 1;
        r = lo;
        if (t < 0x50) r = hi;
    } else {
        t = w - 0x10;
        if (t < 0xe0) {
            *p = 2;
            r = lo;
            if (t < 0x70) r = hi;
        } else {
            *p = 3;
            r = lo;
            if (v < 0x80) r = hi;
        }
    }
    return r;
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_800288C4);
typedef struct { char p0[9]; u8 b9; } G_288C4;
extern u8 D_8009C980;
extern u16 D_800A5474;

#define AXIS(v, c, a, hi, lo) ({                                  \
    s32 d;                                                      \
    s32 r;                                                      \
    d = a - 0x50;                                               \
    if ((u32)d < 0x60) r = 0;                              \
    else {                                                      \
        d = a - 0x30;                                           \
        if ((u16)d < 0xa0) { (v) = 1; { s32 t = ((u16)d < 0x50) ? hi : lo; r = t; } } \
        else {                                                  \
            d = a - 0x10;                                       \
            (a) = 0;                                            \
            if ((u16)d < 0xe0) { (v) = 2; { s32 t = ((u16)d < 0x70) ? hi : lo; r = t; } } \
            else { (v) = 3; { s32 t = (c < 0x80) ? hi : lo; r = t; } }         \
        }                                                       \
    }                                                           \
    r; })

void func_800288C4(void)
{
    u16 m;
    u8 c1, c2;
    u32 a1, a2;
    volatile u16 *pad;
    G_288C4 *g = &D_8009C978;
    D_8009C9DC = D_800A5474;
    c1 = D_8009C980;
    D_8009C980 = 0;
    m = *(volatile u16 *)&D_8009C9D8 & 0xff0f;
    a1 = c1;
    m |= AXIS(D_8009C980, c1, a1, 0x80, 0x20);
    c2 = g->b9;
    g->b9 = 0;
    a2 = c2;
    m |= AXIS(g->b9, c2, a2, 0x10, 0x40);
    pad = &D_8009C9D8;
    *pad = m;
    D_1F8001FC = *pad & ~D_8009C9DC;
    D_1F8001FE = D_8009C9DC & ~*pad;
    D_800A5474 = *pad;
}
#undef AXIS

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80028A74);
typedef struct { char c[6]; } B_28A74;

void func_80028A74(s32 a, s32 b, s32 c, s32 d)
{
    extern void PadSetAct(u8, void *, s32, s32);
    extern B_28A74 D_80010368;
    B_28A74 buf;
    char *p;
    buf = D_80010368;
    p = D_8009C978;
    if ((*(u16 *)&D_8009C97A) != 0 && D_8009C97E == 0 && (*(u16 *)&D_8009C97C) == 0) {
        D_8009C97D = c;
        D_8009C97C = b;
        PadSetAct(a, p + 4, 2, d);
        D_8009C97F = d;
        D_8009C97E = 1;
    }
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80028B34);
typedef struct { char c[6]; } B_28B34;

void func_80028B34(void)
{
    extern void PadSetActAlign(s32, void *);
    extern B_28B34 D_80010368;
    B_28B34 buf;
    char *p;
    buf = D_80010368;
    p = D_8009C978;
    if ((*(u16 *)&D_8009C97A) == 0)
        return;
    switch (D_8009C97E) {
    case 0:
        if ((*(u16 *)&D_8009C97C) != 0) {
            D_8009C97C = 0;
            D_8009C97D = 0;
            PadSetAct(0, p + 4, 2);
        }
        if (PadGetState(0) == 6)
            PadSetActAlign(0, &buf);
        break;
    case 1:
        if (PadGetState(0) == 6) {
            PadSetActAlign(0, &buf);
            D_8009C97E = 2;
        }
        break;
    case 2:
        if (D_8009C97F != 0) {
            D_8009C97F--;
        } else {
            D_8009C97C = 0;
            D_8009C97D = 0;
            PadSetAct(0, p + 4, 2);
            D_8009C97F = 0;
            D_8009C97E = 3;
        }
        break;
    case 3:
        if (PadGetState(0) == 6) {
            PadSetActAlign(0, &buf);
            D_8009C97E = 0;
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80028CE4);
extern s32 PadSetAct(s32, u8 *, s32);
extern void PadSetActAlign(s32, s8 *);

typedef struct { s8 b[6]; } PadAlign_28CE4;
extern PadAlign_28CE4 D_80010368;

void func_80028CE4(void)
{
    PadAlign_28CE4 align = D_80010368;
    D_8009C97C = 0;
    D_8009C97D = 0;
    PadSetAct(0, &D_8009C97C, 2);
    if (PadGetState(0) == 6)
        PadSetActAlign(0, &align.b[0]);
}

INCLUDE_ASM("nonmatchings/main/render/ui", func_80028D70);

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80028EF4);
typedef struct { char a; char pad[0x1f]; void *p[6]; char pad2[0x5c - 0x38]; char r[3][4]; } GT_28EF4;
extern u8 D_8009BCD8;

void func_80028EF4(void)
{
    s32 i;
    GT_28EF4 *g = &D_800B0770;
    g->a = 1;
    D_800B07B4 = -1;
    D_800B0772 = 0;
    D_800B0773 = 0;
    D_800B07BC = 600;
    D_800B07BA = 0;
    D_800B0788 = (void *)D_1F8002D8[0];
    D_800B07C2 = D_8009BCD8;
    D_800B07C0 = D_8009BCD8;
    D_800B07C4 = D_8009BCD8;
    if (D_8009C3E7 == 0)
        D_800B078C = D_800121A8;
    else
        D_800B078C = D_800121C8;
    g->p[0] = D_8001224C;
    g->p[1] = D_80012260;
    g->p[2] = D_800122B0;
    g->p[3] = D_800123F8;
    g->p[4] = D_80012650;
    g->p[5] = D_800127D0;
    i = 0;
    do {
        g->r[0][i] = 0;
        g->r[1][i] = 0;
        g->r[2][i] = 0;
        i++;
    } while (i < 3);
}

// INCLUDE_ASM("nonmatchings/main/render/ui", func_80029008);

void func_80029008(void)
{

    if (D_800B0770[0] != 0) {
        if (*(u_long*)&GAME.selectedArea == 6) {
            if (D_800B0778 != 0) {
                D_800B0778 -= 1;
            }
        } else {
            func_8002907C(D_800B0770);
        }
    }
}

INCLUDE_RODATA("nonmatchings/main/render/ui", D_80010368);

// INCLUDE_ASM("nonmatchings/main/render/ui", func_8002907C);
extern u8 D_8009BCF8[];
extern u8 D_800B07C8[];
extern u8 D_800A5464[];
extern u8 D_8009BCD9[];

void func_8002907C(GameObject *o)
{
    s32 i;
    u8 *p;

    switch (o->state) {
    case 0:
        o->clut = 0;
        o->state++;
        break;
    case 1:
    if (o->clut != 0)
        o->clut--;
    if (D_8009BCD4 != o->d)
        o->d = D_8009BCD4;
    if (D_8009BCD8 != o->unk50) {
        o->unk50 = D_8009BCD8;
        o->unk4E = 6;
        if (o->unk4A == 0)
            o->unk4A++;
    }
    o->unk48 = 1;
    switch (o->unk4A) {
    case 0:
        if (--o->unk4C <= 0) {
            o->unk4C = 0;
            if (D_8009BCD9[0] - 1 < ((u8 *)&D_8009BCD8)[0])
                o->unk48 = 0;
        }
        break;
    case 1:
        o->unk4C = 6;
        o->unk52 = *(s16 *)((u8 *)o + 0x54);
        o->unk4A++;
        break;
    case 2:
        if (--o->unk4C <= 0)
            o->unk4A++;
        break;
    case 3:
        o->unk4C = 6;
        o->unk52 = o->unk50;
        o->unk4A++;
        break;
    case 4:
        if (--o->unk4C <= 0) {
            if (--o->unk4E <= 0) {
                o->unk4C = 0xb4;
                o->unk4A = 0;
                *(s16 *)((u8 *)o + 0x54) = o->unk50;
            } else {
                o->unk4A = 1;
            }
        }
        break;
    }
    for (i = 0; i < 3; i++) {
        if (D_8009C40C[D_8007C280[i]] != 0 && D_8009BCF8[0] == D_8007C288[i]) {
            switch (D_800A5464[0]) {
            case 0:
                if (--D_800B07C8[4 + i] == 0) {
                    D_800B07C8[4 + i] = 3;
                    if (++D_8009BCF8[0x40f] >= 0x3c) {
                        D_800A5464[0] = 1;
                        D_8009BCF8[0x40f] = 0x3c;
                        D_800B07C8[4 + i] = 0;
                        D_800B07C8[12 + i] = 1;
                        D_800B07C8[8 + i] = 6;
                    }
                }
                break;
            case 1:
                break;
            case 2:
                D_800B07C8[4 + i] = 0x78;
                D_800B07C8[8 + i] = 0;
                D_800B07C8[12 + i] = 0;
                D_8009BCF8[0x40f] = 0;
                break;
            case 3:
                D_800B07C8[8 + i] = 0;
                if (--D_800B07C8[4 + i] == 0) {
                    D_800A5464[0] = 0;
                    D_800B07C8[4 + i] = 1;
                }
                break;
            }
            if (D_800B07C8[8 + i] != 0 && --D_800B07C8[8 + i] == 0) {
                if (++D_800B07C8[12 + i] >= 4)
                    D_800B07C8[12 + i] = 0;
                D_800B07C8[8 + i] = 6;
            }
        } else {
            if (D_800B07C8[4 + i] != 0) {
                D_800B07C8[i] = 0x78;
                D_800B07C8[4 + i]--;
                if (++D_8009BCF8[0x40c + i] >= 0x3c) {
                    if (D_8009BCF8[0x408 + i] == 9) {
                        D_8009BCF8[0x40c + i] = 0x3c;
                        D_800B07C8[4 + i] = 0;
                    } else {
                        D_8009BCF8[0x408 + i]++;
                        D_8009BCF8[0x40c + i] -= 0x3c;
                        D_800B07C8[12 + i] = 1;
                        D_800B07C8[8 + i] = 6;
                    }
                }
            }
            if (D_800B07C8[i] != 0)
                D_800B07C8[i]--;
            p = (u8 *)o + i;
            if (p[0x64] != 0 && --p[0x60] == 0) {
                if (++p[0x64] >= 4)
                    p[0x64] = 0;
                p[0x60] = 6;
            }
        }
    }
        break;
    case 2:
        o->state++;
        break;
    }
}
