#include "common.h"
#include "game.h"
#include "game/gte.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80024CFC);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80024EEC);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800251C0);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800253C8);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002564C);


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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025810);


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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025A38);


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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025C14);


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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025E74);


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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002601C);


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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026228);



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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800263F0);



typedef struct { char pad[0xe]; u8 b0e; } O;
typedef struct { long c[4]; } C4_263F0;
extern C4_263F0 D_8007C160[];

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026694);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026E48);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80027600);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800279E8);
void func_800279E8(u8* arg0, s32 arg1, s32 arg2)
{
    u8* r;

    arg0 += 4;
    r = func_80024EEC(arg2, arg0, arg0 + 4, arg1);
    func_80025C14(r + 0x14, r + 0x18, arg1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", subtractScaledVertices);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028638);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", joypadInit);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028794);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800287F8);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800288C4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028A74);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028B34);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028CE4);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028D70);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028EF4);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80029008);

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

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/render/ui", D_80010368);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002907C);
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
