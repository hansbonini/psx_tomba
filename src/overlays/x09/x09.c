#include "common.h"
#include "game.h"
#include "game/gte.h"

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011589C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801158DC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801158F0);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80115C70);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80115D0C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80115F20);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801160A0);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", func_80115214);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115228);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115258);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", func_80115274);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_8011528C);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801152A8);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801152CC);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801152E4);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801152FC);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115314);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_8011532C);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115344);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115364);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_8011537C);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_8011539C);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801153B4);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801153CC);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801153EC);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115404);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115428);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115440);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115458);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115488);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801154A0);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801154C0);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801154D8);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_801154F8);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115528);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115540);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115558);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", jtbl_80115570);

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", func_801155A8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116120);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011619C);




typedef struct { char p[3]; u8 n; s32 e[0x58]; u8 b164; } Q_1619C;
extern unsigned long D_80129BA0[];
extern s32 getScrollOffsetX(void);

#define PUSH(i)                                 \
    q->e[q->n] = (s32)base + off[i];            \
    q->n++;

void func_8011619C(Q_1619C *q, u8 *base)
{
    RECT r;
    s16 lo, hi, a, i;
    s32 d;
    u8 cnt = base[0];
    s32 *off = (s32 *)(base + 4);

    switch (D_8009BCCA) {
    case 0:
        if ((D_8009C608.purifiedAreas & 1) && q->b164 == 0) {
            r.x = 0xb0;
            r.y = 0x1f0;
            r.w = 0x10;
            r.h = 1;
            LoadImage(&r, D_80129BA0);
            r.x = 0xa;
            r.y = 0x170;
            r.w = 0x16;
            r.h = 0x40;
            MoveImage(&r, 0x2a, 0x140);
            r.x = 0x20;
            r.y = 0x110;
            r.w = 0x16;
            r.h = 0x10;
            MoveImage(&r, 0x20, 0x100);
            q->b164++;
        }
        if (D_8009C068.disableSelectMenu) {
            if (D_8009C068.nextArea == 3) {
                hi = cnt - 1;
                for (i = cnt - 0x10; i <= hi; i++) {
                    PUSH(i)
                }
            } else if (D_8009C068.nextArea == 1) {
                hi = cnt - 4;
                for (i = cnt - 0x14; i <= hi; i++) {
                    PUSH(i)
                }
                hi = 0x1b;
                for (i = 0x13; i <= hi; i++) {
                    PUSH(i)
                }
            } else {
                a = (SCRATCHPAD.unk168[3].p.whole - 0x384) / 80;
                if (a < 0) a = 0;
                a += 0x1c;
                hi = a + 8;
                if (hi >= cnt) hi = cnt - 1;
                for (i = a; i <= hi; i++) {
                    PUSH(i)
                }
            }
        }
        if (D_8009BCCC == 0x20 || D_8009BC98.unk0A == 0) {
            if (D_800A38DC == 0)
                { register s32 t asm("$3") = SCRATCHPAD.unk168[3].p.whole - 0x668; d = t / 80; }
            else
                d = (SCRATCHPAD.unk168[3].p.whole + getScrollOffsetX() - 0x668) / 80;
            lo = d; asm("" : "=r"(lo) : "0"(lo)); { register s32 h asm("$3") = d + 8; hi = h; }
            if (lo < 0) lo = 0;
            if (hi >= 0x1d) hi = 0x1c;
            for (i = lo; i <= hi; i++) {
                PUSH(i)
            }
        }
        if (D_800A38DC == 0) {
            a = (SCRATCHPAD.unk168[3].p.whole - 0x3ac) / 80;
            if (a < 0) a = 0;
            a += 0x1c;
            hi = a + 8;
        } else {
            a = (SCRATCHPAD.unk168[3].p.whole + getScrollOffsetX() - 0x3ac) / 80;
            if (a < 0) a = 0;
            a += 0x1b;
            hi = a + 10;
        }
        if (hi >= cnt) hi = cnt - 1;
        for (i = a; i <= hi; i++) {
            PUSH(i)
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 6:
        for (i = 0; i < 0x40 && i < cnt; i++) {
            PUSH(i)
        }
        break;
    }
}
#undef PUSH

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801167B4);
typedef struct { s16 vx, vy, vz, pad; } SV_167B4;

void func_801167B4(GameObject *o)
{
    SV_167B4 r;
    void *m = &o->unk48;

    getBaseMatrix(m);
    r.vx = o->unk84;
    r.vy = o->unk88;
    r.vz = o->unk8C;
    RotMatrix(&r, m);
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116814);
typedef struct { s16 vx, vy, vz, pad; } SV_16814;
typedef struct { s32 vx, vy, vz; } LV_16814;

#define V(o) ((LV_16814 *)&(o)->unk5C)

void func_80116814(GameObject *o)
{
    char m[32];
    SV_16814 r;
    GameObject *p;

    o->x.p.whole = V(o)->vx;
    o->y.p.whole = V(o)->vy;
    o->z.p.whole = V(o)->vz;
    p = (GameObject *)o->unk90;
    getBaseMatrix(&o->unk48);
    r.vx = o->unk30 >> 16;
    r.vy = o->unk34 >> 16;
    r.vz = o->unk38 >> 16;
    SetRotMatrix(&p->unk48);
    ApplyRotMatrix(&r, V(o));
    V(o)->vx += p->x.p.whole;
    V(o)->vy += p->y.p.whole;
    V(o)->vz += p->z.p.whole;
    o->velX = V(o)->vx - o->x.p.whole;
    o->velY = V(o)->vy - o->y.p.whole;
}
#undef V

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801168EC);


struct GSInventory_168EC { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_168EC { u8 weapon; u8 pants; };

typedef struct { s16 vx, vy, vz, pad; } SVEC_168EC;

extern GameObject *D_8009BCB4[];
extern void func_80117098(GameObject *);
extern void func_80116B48(GameObject *);
extern void func_80116C00(GameObject *);

void func_801168EC(GameObject *o)
{
    extern void func_80022D3C(GameObject *, s32);
    GameObject *e;
    SVEC_168EC v;

    switch (o->state) {
    case 0:
        e = (GameObject *)o->unk94;
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unk6A = 0;
        o->objectIndex = 0;
        o->unkA4 = 0;
        *(s32 *)&o->unk5C = o->x.p.whole;
        o->unk60 = o->y.p.whole;
        o->buffSize = o->z.p.whole;
        while (e) {
            *(GameObject **)&e->unkA8 = o;
            if ((e->category == 4 && (GameObject *)e->unk90 != o) || e->category == 3) {
                e->unk90 = (s32)o;
                e->unk30 = e->x.raw - o->x.raw;
                e->unk34 = e->y.raw - o->y.raw;
                e->unk38 = e->z.raw - o->z.raw;
            }
            e = (GameObject *)e->unk94;
        }
        o->unk30 = o->h->raw;
        o->unk34 = o->y.raw;
        o->unk38 = o->d->raw;
        if (o->animFrame == 2) {
            (*(GameObject **)&D_8009BC98.unk18)->unk94 = (s32)o;
            D_8009BCB4[0]->unk94 = (s32)o;
        } else {
            func_80117098(o);
        }
        break;
    case 1:
        if (GAME.selectedPlane == 0x20 || D_8009BC98.unk0A != 1) {
            func_80022D3C(o, 0xa0);
            func_80116B48(o);
            func_80116C00(o);
            getBaseMatrix(&o->unk48);
            v.vx = o->unk84;
            v.vy = o->unk88;
            v.vz = o->unk8C;
            RotMatrix(&v, &o->unk48);
            if (!o->subtype && D_8009BC98.unk10 && D_8009BC98.unk11 == 0x8a) D_8009C068.unk71e = 1;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer8(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116B48);
typedef struct { char p0[8]; s32 d08; } X_16B48;
#define DBC(o) (*(s32 *)((char *)(o) + 0xbc))

void func_80116B48(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->velH = 0x80;
        o->unk74 = -2;
        DBC(o) = 0;
        o->unk7A = o->velH;
        o->unk7++;
        break;
    case 1: {
        X_16B48 *x;
        DBC(o) += o->velH;
        o->velH += o->unk74;
        x = (X_16B48 *)((char *)o + 0xb4);
        if (o->velH == o->unk7A || o->velH == -o->unk7A) o->unk74 *= -1;
        o->unk8C = x->d08 >> 8;
        break;
    }
    }
}
#undef DBC

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116C00);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116C78);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116C7C);

extern void playSFXWithPitchSlide(s32, s32, s32, s32);
extern void playSFX(s32);

void func_80116C7C(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (D_8009C608.playerEquips_1) {
            if (o->unk6A == 1) {
                o->step = 1;
                o->timer = 0x20;
                o->velV = 0x100;
                playSFXWithPitchSlide(0x93, 1, 8, 0x78);
                playSFX(0x91);
            } else if (o->unk6A == 2) {
                o->step = 2;
                o->timer = 0x20;
                o->velV = 0x100;
                playSFXWithPitchSlide(0x94, 1, -8, 0x78);
                playSFX(0x92);
            }
        }
        break;
    case 1:
        o->y.raw -= o->velV << 8;
        if (--o->timer == -1) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    case 2:
        o->y.raw += o->velV << 8;
        if (--o->timer == -1) {
            o->subState = 2;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116DEC);
void func_80116DEC(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (D_8009C608.playerEquips_1 == 0) {
            o->step = 1;
            o->unk6A = 3;
            o->timer = 0x20;
            o->velV = 0x100;
            break;
        }
        switch (o->unk6A) {
        case 1:
            break;
        case 2:
            o->step = 2;
            o->timer = 0x40;
            o->velV = 0x100;
            playSFXWithPitchSlide(0x94, 1, -8, 0x78);
            playSFX(0x92);
            break;
        }
        break;
    case 1:
        o->y.raw += o->velV << 8;
        if (--o->timer == -1) {
            o->subState = 0;
            o->step = 0;
        }
        break;
    case 2:
        o->y.raw += o->velV << 8;
        if (--o->timer == -1) {
            o->subState = 2;
            o->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116F40);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80116FFC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011700C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117098);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117210);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801172E8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117334);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117390);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801173FC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011767C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117790);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801178B8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117B88);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117C4C);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117C60);
extern GameObject *allocObjectLayer3(void);

void func_80117C60(void)
{
    GameObject *p = allocObjectLayer3();

    if (p != 0) {
        p->active = 1;
        p->type = 0x26;
        p->h->raw = 0x7430000;
        p->y.raw = 0xfcc00000;
        p->d->raw = 0xb540000;
        p->subtype = 0;
        p->unkC = 0;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117CC0);
typedef struct { s16 vx, vy, vz, pad; } SV_17CC0;
typedef struct {
    u8 pad[0x24];
    u16 *anim;
    u8 pad28[0xb4 - 0x28];
    SV_17CC0 sv[4];
} P_17CC0;
typedef struct { s16 v[8]; } E_17CC0;

extern E_17CC0 D_80129E08[];

void func_80117CC0(P_17CC0 *o)
{
    o->sv[0].vx = D_80129E08[*o->anim].v[0];
    o->sv[0].vy = D_80129E08[*o->anim].v[1];
    o->sv[0].vz = 0;
    o->sv[1].vx = D_80129E08[*o->anim].v[2];
    o->sv[1].vy = D_80129E08[*o->anim].v[3];
    o->sv[1].vz = 0;
    o->sv[2].vx = D_80129E08[*o->anim].v[4];
    o->sv[2].vy = D_80129E08[*o->anim].v[5];
    o->sv[2].vz = 0;
    o->sv[3].vx = D_80129E08[*o->anim].v[6];
    o->sv[3].vy = D_80129E08[*o->anim].v[7];
    o->sv[3].vz = 0;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117DD0);

typedef struct { char p[0xe]; u8 b0e; char q[0x5c - 0xf]; s32 d5c; } X_17DD0;
#define B0E(o) (((X_17DD0 *)(o))->b0e)
#define D5C(o) (((X_17DD0 *)(o))->d5c)
extern void *D_8012DD6C[];
extern void *D_8012DD68[];
extern void readAnimFrameCount(GameObject *);

void func_80117DD0(GameObject *o)
{
    GameObject *e;
    s32 *g = ((s32*)&SCRATCHPAD.sprData[8]);

    o->tpage = 1;
    o->unkD = 0;
    B0E(o) = 0;
    o->spriteBank = g[0];
    o->subtype = 1;
    o->unkC = 1;
    o->anim = D_8012DD6C[0];
    readAnimFrameCount(o);
    func_80117CC0(o);
    o->timer = 0;
    e = allocObjectLayer3();
    if (e == 0) return;
    e->active = 1;
    e->unk1D = o->unk1D;
    e->category = o->category;
    e->type = o->type;
    e->subtype = o->subtype;
    e->unk30 = 0;
    e->unk34 = 0;
    e->unk38 = 0;
    e->unk90 = (s32)o;
    e->h->raw = o->h->raw;
    e->y.raw = o->y.raw;
    e->d->raw = o->d->raw;
    e->unkA = o->unkA;
    e->animFrame = 1;
    e->unkF = 0;
    e->unk84 = 0;
    e->unk88 = 0;
    e->unk8C = 0;
    D5C(e) = e->x.p.whole;
    e->unk60 = e->y.p.whole;
    e->buffSize = e->z.p.whole;
    e->tpage = 1;
    e->unkD = 0;
    B0E(e) = 0;
    e->state++;
    e->spriteBank = g[0];
    e->subtype = 0;
    e->unkC = 0;
    e->anim = D_8012DD68[0];
    func_80117CC0(e);
}
#undef B0E
#undef D5C

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80117F48);

typedef struct { s16 x, y, z, pad; } SV_17F48;
#define V(o) ((SV_17F48 *)((char *)(o) + 0xb4))
extern void *D_8012DD98[];
extern void *D_8012DD90;

void func_80117F48(GameObject *o)
{
    GameObject *e;
    s32 *s;
    s32 d;
    void *a;

    V(o)[0].x = -0x20;
    V(o)[0].y = -0x24;
    V(o)[0].z = 0;
    V(o)[1].x = 0x10;
    V(o)[1].y = -0x24;
    V(o)[1].z = 0;
    V(o)[2].x = -0x20;
    V(o)[2].y = 0xc;
    V(o)[2].z = 0;
    V(o)[3].x = 0x10;
    V(o)[3].y = 0xc;
    V(o)[3].z = 0;
    o->tpage = 0xb;
    o->unkD = 1;
    o->clut = GetClut(0x120, 0x1e1);
    s = &SCRATCHPAD.sprData[8];
    o->unkE = 0;
    o->spriteBank = *s;
    o->subtype = 1;
    o->anim = D_8012DD98[0];
    o->timer = 0;
    e = allocObjectLayer3();
    if (e) {
        e->active = 1;
        e->unk1D = o->unk1D;
        e->category = o->category;
        e->type = o->type;
        e->subtype = o->subtype;
        e->unk30 = 0;
        e->unk34 = 0;
        e->unk38 = 0;
        e->unk90 = (s32)o;
        e->h->raw = o->h->raw;
        e->y.raw = o->y.raw;
        e->d->raw = o->d->raw;
        e->unkA = o->unkA;
        *(s32 *)&e->unk5C = e->x.p.whole;
        e->animFrame = 0x81;
        e->unkF = 0;
        e->unk84 = 0;
        e->unk88 = 0;
        e->unk8C = 0;
        e->unk60 = e->y.p.whole;
        e->buffSize = e->z.p.whole;
        e->state++;
        e->tpage = 0xb;
        e->unkD = 1;
        e->clut = GetClut(0x120, 0x1ee);
        e->unkE = 0;
        d = *s;
        e->subtype = 0;
        a = D_8012DD90;
        V(e)[0].x = -0x2b;
        V(e)[0].y = -0x4c;
        V(e)[0].z = 0;
        V(e)[1].x = 0x1e;
        V(e)[1].y = -0x4c;
        V(e)[1].z = 0;
        V(e)[2].x = -0x2b;
        V(e)[2].y = 0xc;
        V(e)[2].z = 0;
        V(e)[3].x = 0x1e;
        V(e)[3].y = 0xc;
        V(e)[3].z = 0;
        e->spriteBank = d;
        e->anim = a;
    }
}
#undef V

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80118150);
extern GameObject *allocObjectLayer2(void);

void func_80118150(GameObject *o)
{
    GameObject *n;

    switch (o->step) {
    case 0:
        o->step++;
        o->timer = 0x3c;
        break;
    case 1:
        if (--o->timer == -1)
            o->step++;
        break;
    case 2:
        n = allocObjectLayer2();
        if (n) {
            n->active = 1;
            n->type = 0x2c;
            n->h->raw = o->h->raw - 0x160000;
            n->y.raw = o->y.raw;
            n->d->raw = o->d->raw - 0x1a0000;
            n->subtype = 1;
            n->unk8C = 0xc0;
        }
        n = allocObjectLayer2();
        if (n) {
            n->active = 1;
            n->type = 0x2c;
            n->h->raw = o->h->raw + 0xe0000;
            n->y.raw = o->y.raw;
            n->d->raw = o->d->raw - 0x160000;
            n->subtype = 0;
            n->unk8C = 0x40;
        }
        o->step = 0;
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801182CC);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80118500);

struct GSInventory_18500 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_18500 { u8 weapon; u8 pants; };
extern void func_8011869C(GameObject *);

void func_80118500(GameObject *o)
{
    switch (o->state) {
    case 0:
        switch (o->subState) {
        case 0:
            o->subState++;
            break;
        case 1:
            o->state++;
            o->subState = 0;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            *(s32 *)&o->unk5C = o->x.p.whole;
            o->unk60 = o->y.p.whole;
            o->buffSize = o->z.p.whole;
            if (o->animFrame & 0x80)
                func_80117F48(o);
            else
                func_80117DD0(o);
            break;
        }
        break;
    case 1:
        if (GAME.selectedPlane != 0x20 && D_8009BC98.unk0A == 1) {
            o->state++;
            break;
        }
        func_80116814(o);
        if (o->animFrame & 0x80) {
            func_801182CC(o);
        } else {
            func_80022E44(o);
            if (o->subtype != 0)
                func_8011869C(o);
        }
        break;
    case 2:
        if (GAME.selectedPlane == 0x20)
            o->state--;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011869C);
extern s32 tickAnimation(GameObject *);

#define SET(n)                          \
    {                                   \
        o->unkC = n;                     \
        o->anim = D_8012DD6C[(n) - 1];  \
        readAnimFrameCount(o);            \
        func_80117CC0(o);               \
    }

void func_8011869C(GameObject *o)
{
    u8 v;

    switch (o->subState) {
    case 0:
        switch (o->step) {
        case 0:
            v = (*(GameObject **)&o->unkA8)->unk6A;
            if (v == 1) {
                o->step = 1;
                SET(4);
            } else if (v == 2) {
                o->step = 2;
                SET(9);
            }
            break;
        case 1:
            if (tickAnimation(o)) {
                o->subState = 1;
                o->step = 0;
                SET(2);
            }
            break;
        case 2:
            if (tickAnimation(o)) {
                o->subState = 2;
                o->step = 0;
                SET(3);
            }
            break;
        }
        break;
    case 1:
        switch (o->step) {
        case 0:
            v = (*(GameObject **)&o->unkA8)->unk6A;
            if (v == 1) {
                if (o->visible) {
                    tickAnimation(o);
                    if (++o->timer % 240 == 0)
                        playSFX(0x91);
                }
            } else if (v == 3) {
                o->step = 1;
                SET(5);
            } else if (v == 2) {
                o->step = 2;
                SET(6);
            }
            break;
        case 1:
            if (tickAnimation(o)) {
                o->subState = 0;
                o->step = 0;
                SET(1);
            }
            break;
        case 2:
            if (tickAnimation(o)) {
                o->subState = 2;
                o->step = 0;
                SET(3);
            }
            break;
        }
        break;
    case 2:
        switch (o->step) {
        case 0:
            if ((*(GameObject **)&o->unkA8)->unk6A == 2 && o->visible) {
                tickAnimation(o);
                if (++o->timer % 240 == 0)
                    playSFX(0x92);
            }
            v = (*(GameObject **)&o->unkA8)->unk6A;
            if (v == 3) {
                o->step = 1;
                SET(8);
            } else if (v == 1) {
                o->step = 2;
                SET(7);
            }
            break;
        case 1:
            if (tickAnimation(o)) {
                o->subState = 0;
                o->step = 0;
                SET(1);
            }
            break;
        case 2:
            if (tickAnimation(o)) {
                o->subState = 1;
                o->step = 0;
                SET(2);
            }
            break;
        }
        break;
    }
}
#undef SET

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80118ABC);

extern u16 D_80129EFC[];
extern u16 D_80129EF4[];
extern void **D_80129EE8[];
extern s32 func_80022D3C(GameObject *, s32);

void func_80118ABC(GameObject *o)
{
    u32 v;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 10;
        o->unkD = 1;
        o->clut = ((D_80129EFC[o->subtype] + o->unkC) << 6) | ((D_80129EF4[o->subtype] >> 4) & 0x3f);
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = *D_80129EE8[o->subtype];
        v = *(u8 *)&o->hitOffsetX >> 4;
        if (v < 12)
            o->buffSize = (v << 10) + 0x1000;
        else
            o->buffSize = 0x1000 - ((v - 11) << 9);
        v = *(u8 *)&o->hitOffsetX & 0xf;
        if (v < 8)
            o->unk8C = v << 2;
        else
            o->unk8C = (u8)(-((s32)(v - 7) << 5) / 8);
        break;
    case 1:
        func_80022D3C(o, 200);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80118C2C);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80118EFC);

typedef struct { u8 b0f; char p; u16 w1e; u16 cx, cy; void **anims; } E12_18EFC;
extern E12_18EFC D_80129F04[];
extern s16 D_1F800186_S16Arr[] asm("D_1F800186");
extern void pushDrawListCapped(GameObject *);
extern u16 GetClut(s32, s32);

void func_80118EFC(GameObject *o)
{
    E12_18EFC *e;
    u8 s = o->state;

    switch (s) {
    case 0:
        o->state = s + 1;
        o->animFrame = 1;
        o->unkD = 1;
        o->unkA = 7;
        o->unk30 = o->x.p.whole;
        o->unk34 = o->y.p.whole;
        e = &D_80129F04[o->subtype];
        o->tpage = e->w1e;
        o->clut = GetClut(e->cx, e->cy);
        o->unkF = e->b0f;
        o->anim = e->anims[o->unkC];
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        o->x.p.whole = o->unk30 - ((s16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))[0];
        o->y.p.whole = o->unk34 - D_1F800186_S16Arr[0];
        pushDrawListCapped(o);
        tickAnimation(o);
        break;
    case 2:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011907C);
typedef struct { s16 x, y, z, pad; } P8_1907C;
typedef struct { s16 i, b6, b8, ba; s32 bc, c0; } X_1907C;
extern P8_1907C D_80129FD0[];

void func_8011907C(char *o)
{
    X_1907C *x = (X_1907C *)(o + 0xb4);
    s32 dx, dz, dy, d;

    for (;;) {
        dx = D_80129FD0[x->i + 1].x - D_80129FD0[x->i].x;
        dz = D_80129FD0[x->i + 1].z - D_80129FD0[x->i].z;
        dy = D_80129FD0[x->i + 1].y - D_80129FD0[x->i].y;
        d = SquareRoot0(dx * dx + dz * dz);
        if (d != 0) {
            x->c0 = d << 8;
            if (x->bc < (d << 8)) break;
            x->bc -= d << 8;
        }
        x->i++;
    }
    x->ba = ratan2(dy, d);
    x->b8 = ratan2(dz, dx);
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011919C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801192AC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80119404);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80119798);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801197F8);


struct GSInventory_197F8 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_197F8 { u8 weapon; u8 pants; };
extern unsigned long *D_8012A4E8;
extern unsigned long *D_8012A4FC;
extern unsigned long *D_8012A4D8[];
extern unsigned long *D_8012A4EC[];
extern void *D_80130408;
extern void loadImageRect(unsigned long *, s16, s16, s16, s16);

void func_801197F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        (*(GameObject *)&PLAYER).active = 5;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkA = 0;
        o->unkF = 0;
        o->animFrame = 0;
        *(s32 *)&o->unk5C = o->x.p.whole;
        o->unk60 = o->y.p.whole;
        o->buffSize = o->z.p.whole;
        if (D_8009C068.unk5a6) {
            loadImageRect(D_8012A4E8, 0x90, 0x1f0, 0x10, 1);
            loadImageRect(D_8012A4FC, 0x90, 0x1f1, 0x10, 1);
        } else if (D_8009C068.unk6a6) {
            loadImageRect(D_8012A4E8, 0x90, 0x1f0, 0x10, 1);
            loadImageRect(D_8012A4FC, 0x90, 0x1f1, 0x10, 1);
        } else {
            loadImageRect(D_8012A4D8[GAME.displayExpBar], 0x90, 0x1f0, 0x10, 1);
            loadImageRect(D_8012A4EC[D_8009C608.unk953], 0x90, 0x1f1, 0x10, 1);
        }
        o->tpage = 1;
        o->unkD = 0x80;
        o->state++;
        o->spriteBank = SCRATCHPAD.sprData[6];
        o->anim = D_80130408;
        readAnimFrameCount(o);
        break;
    case 1:
        func_801192AC(o);
        tickAnimation(o);
        o->visible = 1;
        pushDrawListCapped(o);
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801199F0);

s32 func_801199F0(GameObject *o)
{
    GameObject **list = (*(GameObject ***)&(*(void * *)&SCRATCHPAD.unk260));
    GameObject *pl = &PLAYER;
    GameObject *n;

    if ((D_1F80019E = SCRATCHPAD.unk250) == 0)
        goto out;
loop:
    {
        n = *list++;
        D_1F80019E--;
        if (!(n->active & 1))
            goto next;
        if (n->type != 0xa)
            goto next;
        if (n->subtype & 0x80)
            goto next;
        if ((u16)(pl->d->p.whole - n->d->p.whole + 0x2d) >= 0x5b)
            goto next;
        if ((u16)(pl->h->p.whole - n->h->p.whole + 0x60) >= 0xc1)
            goto next;
        if ((u16)(pl->y.p.whole - n->y.p.whole + 0x40) >= 0x81)
            goto next;
        o->x.p.whole = n->x.p.whole;
        o->y.p.whole = n->y.p.whole - 0x10;
        o->z.p.whole = n->z.p.whole;
        o->unk90 = (s32)n;
        return 1;
    }
next:
    if (D_1F80019E != 0)
        goto loop;
out:
    return 0;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80119B30);


extern void *D_8012D40C[];

static __inline__ void setAnim_19B30(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_80119B30(GameObject *o)
{
    u8 t = o->state;
    GameObject *p;

    switch (t) {
    case 0:
        o->state = t + 1;
        *(s8 *)&o->unkF = -11;
        o->tpage = 11;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        setAnim_19B30(o, D_8012D40C[0]);
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if (D_8009BC98.unk10 == 0) break;
            if (D_8009BC98.unk11 != 0x75) break;
            if (func_801199F0(o)) {
                o->timer = 0x1e;
                o->subState++;
            }
            break;
        case 1:
            p = (GameObject *)o->unk90;
            o->x.p.whole = p->x.p.whole;
            o->y.p.whole = p->y.p.whole - 0x10;
            o->z.p.whole = p->z.p.whole;
            tickAnimation(o);
            if (--o->timer == -1) {
                o->subState++;
                p->active = 2;
                p->subState = 8;
                p->step = 0;
                p->subtype |= 0x80;
                o->timer = 100;
            }
            func_80022E44(o);
            break;
        case 2:
            tickAnimation(o);
            if (--o->timer == -1) {
                o->subState = 0;
                D_8009BC98.unk12 = 0;
                D_8009BC98.unk0F = 0;
                D_8009BC98.unk10 = 0;
            }
            func_80022E44(o);
            break;
        }
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80119D54);


void func_80119D54(GameObject *o)
{
    switch (o->step) {
    case 0:
        if ((u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) + 0x20) < 0x41 &&
            (u16)(o->y.p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) + 0x30) < 0x61) {
            if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) == 1) break;
            if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) == 2) {
                o->step++;
                o->velY = 0;
            } else if (D_8009BC98.unk0A == 0) {
                o->step = 3;
                o->unk88 = 0xa00;
            }
        }
        break;
    case 1:
        o->unk88 = (o->unk88 - 0x20) & 0xfff;
        if (o->unk88 < 0xa01) o->step++;
        break;
    case 2:
        break;
    case 3:
        o->unk88 = (o->unk88 + 0x20) & 0xfff;
        if (o->unk88 == 0) o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80119E94);
extern void freeObjectLayer4(GameObject *o);

void func_80119E94(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
            func_80119D54(o);
            break;
        case 1:
            switch (o->step) {
            case 0:
                o->step = ((GameObject *)o->unk90)->step;
                if (o->step == 3) o->unk88 = 0x600;
                break;
            case 1:
                o->unk88 = (o->unk88 + 0x20) & 0xfff;
                if (o->unk88 >= 0x600) o->step++;
                break;
            case 2:
                break;
            case 3:
                o->unk88 = (o->unk88 - 0x20) & 0xfff;
                if (o->unk88 == 0) o->step = 0;
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A01C);

struct GSInventory_1A01C { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1A01C { u8 weapon; u8 pants; };

typedef struct { s16 b0, b1, b2, b3; } B4_1A01C;

extern B4_1A01C D_8012A500[];
extern void func_80022C08(GameObject *, s16);
extern void func_8011A1E4(GameObject *o);

void func_8011A01C(GameObject *o)
{
    s16 d;

    switch (o->state) {
    case 0:
        switch (o->subState) {
        case 0:
            o->subState++;
            o->hitOffsetX = D_8012A500[o->subtype].b0;
            o->hitWidth = D_8012A500[o->subtype].b1;
            o->hitOffsetY = D_8012A500[o->subtype].b2;
            o->hitHeight = D_8012A500[o->subtype].b3;
            break;
        case 1:
            o->state++;
            o->subState = 0;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            *(s32 *)&o->unk5C = o->x.p.whole;
            o->unk60 = o->y.p.whole;
            o->buffSize = o->z.p.whole;
            func_8011A1E4(o);
            break;
        }
        break;
    case 1:
        if (GAME.selectedPlane == 0x20 || D_8009BC98.unk0A != 1) {
            func_80116814(o);
            d = o->hitWidth - o->hitOffsetX;
            if (d < o->hitOffsetX) d = o->hitOffsetX + 0x10;
            func_80022C08(o, d);
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A1E4);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A268);
typedef struct { u8 b0; s8 b1, b2, b3; } T4_1A268;
extern T4_1A268 D_8012A560[];
extern GameObject *allocObjectLayer2(void);

GameObject *func_8011A268(GameObject *o, s32 k)
{
    u8 s;
    GameObject *n = allocObjectLayer2();
    if (n == 0)
        return 0;
    n->active = 1;
    n->unk1D = 0;
    n->type = 0xa;
    s = D_8012A560[k].b0;
    n->unkC = 0;
    n->unkA = 0;
    n->animFrame = 1;
    n->unkF = 0;
    n->subtype = s;
    n->unk30 = D_8012A560[k].b1;
    n->unk34 = D_8012A560[k].b2;
    n->unk38 = D_8012A560[k].b3;
    n->x.raw = (n->unk30 << 16) + o->x.raw;
    n->y.raw = (n->unk34 << 16) + o->y.raw;
    n->z.raw = (n->unk38 << 16) + o->z.raw;
    n->unk90 = (s32)o;
    n->unk94 = 0;
    return n;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A36C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A4B4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A650);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A6F8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A7C0);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011A858);
extern void *D_8012D3D0;

static __inline__ s32 vdiv_1A858(s32 a, s32 b)
{
    return a / b;
}

static __inline__ void start_1A858(GameObject *o)
{
    s32 vy, vx;

    o->visible = (*(GameObject *)&PLAYER).visible;
    o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
    o->anim = D_8012D3D0;
    o->h->p.whole = (*(GameObject *)&PLAYER).h->p.whole;
    o->y.p.whole = (*(GameObject *)&PLAYER).y.p.whole;
    o->d->p.whole = (*(GameObject *)&PLAYER).d->p.whole;
    *(volatile s16 *)&o->timer = 20;
    vy = vdiv_1A858(-0x6c00 - (o->y.p.whole << 8), o->timer);
    o->unk8C = 0;
    o->unk30 = 0x20;
    o->unk34 = -0x3c0;
    vx = vdiv_1A858(0x79b00 - (o->h->p.whole << 8), 20);
    o->category |= 0x80;
    o->velY = vy;
    o->velX = vx;
    o->unkF = (*(GameObject *)&PLAYER).unkF - 1;
    o->step++;
}

void func_8011A858(GameObject *o)
{
    char pad[16];

    if (o->visible == 0)
        return;
    switch (o->subState) {
    case 0:
        break;
    case 1:
        func_8011A36C(o);
        break;
    case 2:
        if (o->step != 0)
            break;
        start_1A858(o);
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011AA0C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011AAF4);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011AC30);

extern void *D_8012CF18[];
extern void *D_8012CF20[];
extern s32 fixedMulSin2(s32, s32);

void func_8011AC30(GameObject *o)
{
    GameObject *e;
    s32 r;

    switch (o->state) {
    case 0:
        o->state++;
        o->subState = 0;
        o->step = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->tpage = 6;
        o->unkA = 2;
        o->unkD = 1;
        o->touchFlag = 0;
        o->clut = GetClut(0x80, 0x1ff);
        switch (o->subtype & 1) {
        case 0:
            o->anim = D_8012CF18[o->unkC];
            o->active = 2;
            break;
        case 1:
            o->anim = D_8012CF20[o->unkC];
            o->hitOffsetX = 0x20;
            o->hitWidth = 0x40;
            o->hitOffsetY = 0;
            o->hitHeight = 0x20;
            o->active = 1;
            break;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        switch (o->subtype & 1) {
        case 0:
            o->velX += 2;
            o->velH = fixedMulSin2(o->velX & 0xff, 0x1000);
            o->unk8C = (o->velH >> 8) & 0xfff;
            break;
        case 1:
            e = (GameObject *)o->unk90;
            o->h->p.whole = e->h->p.whole - fixedMulSin2(*(u8 *)&e->unk8C, 0x4c);
            o->y.p.whole = e->y.p.whole + fixedMulCos2(*(u8 *)&e->unk8C, 0x4c);
            o->unk8C = e->unk8C;
            break;
        }
        tickAnimation(o);
        func_80022E44(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011AE5C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011B1CC);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011B328);
#define E(o, k) (((GameObject **)((char *)(o) + 0xb4))[k])
extern GameObject *allocObjectLayer3(void);

void func_8011B328(GameObject *o)
{
    GameObject *e;
    u8 one, five;

    switch (o->step) {
    case 0:
        if (o->touchFlag != 1 || (*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) != o->touchFlag)
            break;
        one = 1;
        e = allocObjectLayer3();
        if (e) {
            e->type = 0x44;
            e->x.raw = 0x07480000;
            e->y.raw = 0xfe200000;
            e->active = one;
            e->unkC = one;
            e->z.raw = 0x0ba40000;
        }
        E(o, 0) = e;
        five = 5;
        e = allocObjectLayer3();
        if (e) {
            e->type = 0x44;
            e->x.raw = 0x07580000;
            e->y.raw = 0xfe200000;
            e->active = one;
            e->unkC = five;
            e->z.raw = 0x0ba40000;
        }
        E(o, 1) = e;
        e = allocObjectLayer3();
        if (e) {
            e->type = 0x44;
            e->x.raw = 0x07680000;
            e->y.raw = 0xfe200000;
            e->active = one;
            e->unkC = 0;
            e->z.raw = 0x0ba40000;
        }
        E(o, 2) = e;
        e = allocObjectLayer3();
        if (e) {
            e->type = 0x44;
            e->x.raw = 0x07780000;
            e->y.raw = 0xfe200000;
            e->active = one;
            e->unkC = 0;
            e->z.raw = 0x0ba40000;
        }
        E(o, 3) = e;
        e = allocObjectLayer3();
        if (e) {
            e->type = 0x44;
            e->x.raw = 0x07880000;
            e->y.raw = 0xfe200000;
            e->active = one;
            e->unkC = 0;
            e->z.raw = 0x0ba40000;
        }
        E(o, 4) = e;
        e = allocObjectLayer3();
        if (e) {
            e->type = 0x44;
            e->x.raw = 0x07980000;
            e->y.raw = 0xfe200000;
            e->active = one;
            e->unkC = 0;
            e->z.raw = 0x0ba40000;
        }
        E(o, 5) = e;
        o->step++;
        break;
    case 1:
        if (o->touchFlag == 1) {
            if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) == 1)
                break;
            E(o, 0)->state = 2;
            E(o, 1)->state = 2;
            E(o, 2)->state = 2;
            E(o, 3)->state = 2;
            E(o, 4)->state = 2;
            E(o, 5)->state = 2;
            o->cooldownTimer = 0x1e;
            o->step++;
        }
        E(o, 0)->state = 2;
        E(o, 1)->state = 2;
        E(o, 2)->state = 2;
        E(o, 3)->state = 2;
        E(o, 4)->state = 2;
        E(o, 5)->state = 2;
        o->cooldownTimer = 0x1e;
        o->step++;
        break;
    case 2:
        if (--o->cooldownTimer == -1) {
            o->step++;
        }
    case 3:
        if (o->touchFlag != 1 || (*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) != 1) {
            o->step = 0;
        }
        break;
    }
}
#undef E

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011B65C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011B7E4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011B91C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011BA78);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011BB80);

s32 func_8011BB80(GameObject *o)
{
    if (D_8009BC98.unk0A == 0) goto ret0;
    if (D_8009BC98.unk0F | D_8009BC98.unk10) return 0;
    if ((*(GameObject *)&PLAYER).active == 2) return 0;
    if ((u16)((*(GameObject *)&PLAYER).d->p.whole - o->d->p.whole + 0x2d) >= 0x5b) return 0;
    if ((u16)((*(GameObject *)&PLAYER).h->p.whole - o->h->p.whole + (o->hitOffsetX + (*(GameObject *)&PLAYER).hitOffsetX)) > o->hitWidth + (*(GameObject *)&PLAYER).hitWidth) {
    ret0:
        return 0;
    }
    return (u16)((*(GameObject *)&PLAYER).y.p.whole - o->y.p.whole + ((*(GameObject *)&PLAYER).hitOffsetY + o->hitOffsetY)) <= (*(GameObject *)&PLAYER).hitHeight + o->hitHeight;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011BC94);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011BD20);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011BE24);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011BFF8);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C0D4);


extern char D_8012A5CC[];
extern s16 D_8012A60C[];
extern void pushDrawListLayer4(GameObject *);

#define W32(o) (((s16 *)&(o)->unk30)[1])
#define W36(o) (((s16 *)&(o)->unk34)[1])

static __inline__ s32 Near_1C0D4(GameObject *o)
{
    if (D_8009BC98.unk0A == 0) return 0;
    if ((u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))) >= 0x12d) return 0;
    return (u16)((*(u16 *)&SCRATCHPAD.unk168[7].p.whole) - (o->y.p.whole + 0x10)) < 0xc9;
}

void func_8011C0D4(GameObject *o)
{
    u8 s = o->state;
    GameObject *e;
    s16 v;
    s32 a, b;

    switch (s) {
    case 0:
        if (D_8009C068.item_2A == 0 || (D_8009C608.purifiedAreas & 0x20)) {
            o->state = 3;
            break;
        }
        o->state = s + 1;
        o->unkA = 0x13;
        o->unk6A = 0;
        o->active = 2;
        if (o->unkC == 0) {
            RECT r;
            r.x = 0x80;
            r.y = 0x1fc;
            r.w = 0x10;
            r.h = 2;
            LoadImage(&r, D_8012A5CC);
            o->hitOffsetX = 0x18;
            o->hitWidth = 0x30;
            o->hitOffsetY = 0x18;
            o->hitHeight = 0x32;
        } else {
            o->hitOffsetX = 10;
            o->hitWidth = 0x14;
            o->hitOffsetY = 0xe;
            o->hitHeight = 0x36;
        }
        o->unk84 = 0;
        o->unk88 = D_8012A60C[o->unkC];
        o->unk8C = 0;
        if (D_8009C068.unk5b0 == 0) {
            o->subState = 0;
            v = 0x800;
        } else {
            if (o->unkC == 0) {
                o->subState = 2;
                o->active = 1;
            } else {
                o->subState = 1;
                o->active = 2;
            }
            v = 0x1000;
        }
        o->unk74 = v;
        o->unk76 = v;
        o->unk78 = v;
        break;
    case 1:
        if (o->unkC) {
            e = (GameObject *)o->unk90;
            if (e->visible == 0) break;
            o->unk74 = e->unk74;
            o->unk76 = e->unk76;
            o->unk78 = e->unk78;
            a = W32(o) * o->unk74;
            b = W36(o) * o->unk74;
            o->h->raw = e->h->raw + (a << 4);
            o->y.raw = e->y.raw + (b << 4);
            o->visible = 1;
            pushDrawListLayer4(o);
            switch (o->subState) {
            case 0:
                if (o->unk6A) o->subState++;
                break;
            case 1:
                if (o->unkC == 2) {
                    o->unk88 -= 0x20;
                    if (o->unk88 < -0x638) {
                        o->unk88 = -0x638;
                        o->subState++;
                    }
                } else {
                    o->unk88 += 0x20;
                    if (o->unk88 > 0x638) {
                        o->unk88 = 0x638;
                        o->subState++;
                    }
                }
                break;
            case 2:
                o->active = 1;
                break;
            }
        } else {
            func_80022E44(o);
            switch (o->subState) {
            case 0:
                if (Near_1C0D4(o)) o->subState++;
                break;
            case 1:
                func_8011BC94(o);
                break;
            case 2:
                func_8011BE24(o);
                break;
            }
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
#undef W32
#undef W36

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C4CC);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C678);
extern void spawnEffectObject(s32, s32, s32, s32);

void func_8011C678(GameObject *o)
{
    D_8009C068.unk597 = 0;
    if (D_8009C068.unk698 != 0) {
        spawnEffectObject(0, o->x.p.whole, o->y.p.whole, o->z.p.whole);
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C6BC);

extern GameObject *D_8009C650;

void func_8011C6BC(GameObject *o)
{
    o->touchFlag = 0;
    (*(u8*)&o->unkAC) = 3;
    o->unk9C = 0;
    o->velX = 0;
    o->velY = 0;
    o->velH = 0;
    o->velV = 0;
    o->unkB2 = 0;
    func_800EDD9C(o);
    D_8009C650->unk8C = (0x100 - o->unk8C) & 0xff;
    o->step = 3;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C730);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C914);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011C9C4);
typedef struct { char p0; u8 b1; s16 w2; char p4[4]; u8 b8; char p9[5]; s16 we; } PL_1C9C4;
extern PL_1C9C4 *D_8009B698;

void func_8011C9C4(GameObject *o, s32 unused, s32 ang)
{
    GameObject *g = D_8009E454;
    s32 a;
    PL_1C9C4 *p;
    s32 t, w;

    o->unk30 += g->velX;
    o->unk34 += g->velY;
    if (o->animFrame & 1) {
        a = 0x1bf;
        a -= ang;
        a &= 0xff;
        o->h->p.whole = fixedMulCos2(a, D_8009B698->b1) + o->unk30;
        a = fixedMulSin2(a, D_8009B698->b1);
        o->unk84 = 0;
        o->unk8C = 0x100 - (ang & 0xff);
        o->y.p.whole = a + o->unk34;
    } else {
        a = ang + 0xc0;
        a &= 0xff;
        o->h->p.whole = fixedMulCos2(a, D_8009B698->b1) + o->unk30;
        a = fixedMulSin2(a, D_8009B698->b1);
        o->unk84 = 0;
        o->unk8C = ang & 0xff;
        o->y.p.whole = a + o->unk34;
    }
    p = D_8009B698;
    t = p->we;
    if (p->b8 != 0) {
        w = p->w2;
        p->we = t - w;
    } else {
        w = p->w2;
        p->we = t + w;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011CB24);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011CC08);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011CCE8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011CE24);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011CF50);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011CF9C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D098);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D1A8);

typedef struct {
    char p0[2]; s16 w2; char p4[4]; u8 b8, b9; char pa[2]; s16 wc, we;
    char p10[0x28 - 0x10]; u16 w28, w2a;
} G_1D1A8;
extern G_1D1A8 *D_8009B698_G_1D1A8Ptr asm("D_8009B698");
extern void func_800EE1F0(GameObject *o);
extern void playSFXWithVolume(s32, s32);
extern void func_800EDEBC(GameObject *o, s32);

void func_8011D1A8(GameObject *o)
{
    G_1D1A8 *g;

    o->h->p.whole += (*(GameObject **)&D_8009E454)->velX;
    o->y.p.whole += (*(GameObject **)&D_8009E454)->velY;
    switch (o->step) {
    case 0:
        g = D_8009B698_G_1D1A8Ptr;
        o->unkB6 = 0;
        g->b8 = 0;
        g->we = 0;
        g->w2 = 0;
        D_8009B698_G_1D1A8Ptr->b9 = 0;
        D_8009B698_G_1D1A8Ptr->wc = 0;
        D_8009B698_G_1D1A8Ptr->w28 = 0xffff;
        D_8009B698_G_1D1A8Ptr->w2a = 0xffff;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->h->p.whole = o->h->p.whole;
        o->y.p.whole += 4;
        func_800EE1F0(o);
        playSFXWithVolume(4, 0x7f);
        func_800EDEBC(o, 7);
        o->step++;
    case 1:
        tickAnimation(o);
        if (D_1F8001FC & SCRATCHPAD.buttonJump) {
            D_8009B698_G_1D1A8Ptr->b9 = 0;
            o->state = 1;
            o->subState = 0x27;
            o->step = 0;
            o->y.p.whole += 0x10;
        }
        if (D_1F8001FC & 0x10) {
            D_8009B698_G_1D1A8Ptr->b9 = 0;
            o->state = 1;
            o->subState = 0x27;
            o->step = 0;
            o->y.p.whole += 0x10;
        }
        if (D_1F8001FC & 0x40) {
            D_8009B698_G_1D1A8Ptr->b9 = 0;
            o->unk9E = 6;
            o->subState = 0x25;
            o->step = 0;
            o->y.p.whole += 9;
        }
        break;
    }
    func_800EE50C(o);
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D3A8);
extern u8 D_80114638[];
extern void playSFXWithVolume(s32, s32);
extern void advanceAnimFrame(GameObject *, s32);

void func_8011D3A8(GameObject *o)
{
    playSFXWithVolume(0x1c, 0x7f);
    o->unk9C = 0;
    o->anim = D_80010DB0;
    advanceAnimFrame(o, 4);
    *(u8 *)&o->unkAA = 0;
    o->unk88 = 0;
    o->unk8C = D_80114638[o->unkB0];
    o->step++;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D41C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D4F4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D6A8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011D9CC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011DA00);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011DE38);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011E00C);
extern s16 func_80120974(GameObject *, s16, s16, u8);

s32 func_8011E00C(GameObject *o)
{
    GameObject **list = (*(GameObject ***)&(*(void * *)&SCRATCHPAD.unk268));
    GameObject *e;
    s16 u;

    if ((D_1F80019E = (*(u16 *)&SCRATCHPAD.unk254)) == 0)
        goto out;
loop:
    {
        e = *list++;
        D_1F80019E--;
        if (!(e->active & 1))
            goto next;
        if (e->type != 0x1c)
            goto next;
        if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) >= 0x5b)
            goto next;
        u = o->h->p.whole - e->h->p.whole + (o->hitOffsetX + e->hitOffsetX);
        if ((u16)u >= e->hitWidth + o->hitWidth)
            goto next;
        if ((u16)(o->y.p.whole - e->y.p.whole + (e->hitOffsetY + o->hitOffsetY)) >= e->hitHeight + o->hitHeight)
            goto next;
        u = o->h->p.whole - (e->h->p.whole - e->hitOffsetX);
        if ((u16)u >= e->hitWidth)
            goto next;
        {s16 w = o->y.p.whole - (e->y.p.whole + (e->hitHeight - e->hitOffsetY));
        if (func_80120974(o, u, w, e->subtype))
            return 1;}
    }
next:
    if (D_1F80019E != 0)
        goto loop;
out:
    return 0;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011E194);

extern char D_8007728C[];
extern void *D_8012D3F8;
extern void *D_8012D3FC;
extern s16 probeCollisionAtDepthB(GameObject *, s16, s16);
extern void printInfoMessage(s32, s32);

static __inline__ void setbox_1E194(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->hitOffsetX = a;
    o->hitWidth = b;
    o->hitOffsetY = c;
    o->hitHeight = d;
}

void func_8011E194(GameObject *o)
{
    u8 *c;

    switch (o->state) {
    case 0:
        o->state++;
        setbox_1E194(o, 8, 0x10, 8, 0x10);
        o->tpage = 9;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8012D3F8;
        readAnimFrameCount(o);
        o->unk8C = 0;
        o->active = 2;
        o->unkA5 = 0;
        o->unk98 = 0;
        o->movetab = D_8007728C;
        o->unkA = 2;
        break;
    case 1:
        tickAnimation(o);
        if (o->animFrame & 1)
            o->unk8C = (o->unk8C + 0x14) & 0xff;
        else
            o->unk8C = (o->unk8C - 0x14) & 0xff;
        o->y.raw += 0x50000;
        if (func_8011E00C(o) || probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole + 8)) {
            o->active = 2;
            o->unkA5 = 0;
            o->state = 2;
            o->subState = 0;
            o->step = 0;
        }
        if (!func_80022E44(o)) {
            o->state = 2;
            o->subState = 1;
        }
        break;
    case 2:
        switch (o->subState) {
        case 0:
            switch (o->step) {
            case 0:
                o->unkB = 1;
                o->unk8C = 0;
                o->unkF = 4;
                o->unkA5 = 0;
                o->y.p.whole -= 10;
                playSFX(7);
                func_800E92D4(0x1f4, o->x.p.whole, o->y.p.whole, o->z.p.whole);
                o->anim = D_8012D3FC;
                readAnimFrameCount(o);
                o->step++;
                break;
            case 1:
                if (tickAnimation(o)) {
                    o->step = 0;
                    o->subState++;
                }
                break;
            }
            if (!func_80022E44(o))
                o->subState++;
            break;
        case 1:
            c = &D_8009C068.unk596;
            printInfoMessage(*c + 0x29, 2);
            (*c)++;
            ((u8 *)&D_8009C068.unk685)[o->unkC] = 1;
            o->state++;
            break;
        }
        break;
    case 3:
        freeObjectLayer1(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011E46C);
extern void (*D_8007DE28[])(GameObject *);

void func_8011E46C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (D_8009C481 != 0 || D_8009C068.unk5a6 != 0) {
            o->state = 3;
            break;
        }
        initItemObject(o);
        o->active = 2;
        o->state++;
        break;
    case 1:
        if (func_80022E44(o))
            tickAnimation(o);
        break;
    case 2:
        D_8007DE28[D_8007DD88[o->subtype]](o);
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011E584);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011ECB0);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 uv0, clut;
    u16 x1, y1;
    u16 uv1, tpage;
    u16 x2, y2;
    u16 uv2, pad;
} PolyFT3_1ECB0;

typedef struct {
    u16 clut, tpage;
    unsigned long c0;
    u16 p8[3];
    u16 uv0;
    u16 p10[3];
    u16 uv1;
    u16 p18[3];
    u16 uv2;
} Face_1ECB0;
extern PolyFT3_1ECB0 *D_1F800164_PolyFT3_1ECB0Ptr asm("D_1F800164");
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");


long *func_8011ECB0(long *f, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyFT3_1ECB0 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x7000000;
        do {
            gte_ldv3c((char *)f + 8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_avsz3();
                    gte_stotz(&otz);
                    p = D_1F800164_PolyFT3_1ECB0Ptr;
                    gte_stsxy3_ft3(p);
                    if ((p->y0 < 0xf1 || p->y1 < 0xf1 || p->y2 < 0xf1) &&
                        (p->x0 < 0x141 || p->x1 < 0x141 || p->x2 < 0x141)) {
                        p->c0 = ((Face_1ECB0 *)f)->c0;
                        p->clut = ((Face_1ECB0 *)f)->clut;
                        p->tpage = ((Face_1ECB0 *)f)->tpage;
                        p->uv0 = ((Face_1ECB0 *)f)->uv0;
                        p->uv1 = ((Face_1ECB0 *)f)->uv1;
                        *(u16 *)((char *)p + 0x1c) = ((Face_1ECB0 *)f)->uv2;
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 0xca0) {
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            D_1F800164_PolyFT3_1ECB0Ptr = D_1F800164_PolyFT3_1ECB0Ptr + 1;
                        }
                    }
                }
            }
            f += 8;
        } while (--n != 0);
    }
    return f;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011EE90);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 uv0, clut;
    u16 x1, y1;
    u16 uv1, tpage;
    u16 x2, y2;
    u16 uv2, pad1;
    u16 x3, y3;
    u16 uv3, pad2;
} PolyFT4_1EE90;

typedef struct {
    u16 clut, tpage;
    unsigned long c0;
    u16 p8[3];
    u16 uv0;
    u16 p10[3];
    u16 uv1;
    u16 p18[3];
    u16 uv2;
    u16 p20[3];
    u16 uv3;
} Face_1EE90;
extern PolyFT4_1EE90 *D_1F800164_PolyFT4_1EE90Ptr asm("D_1F800164");


long *func_8011EE90(long *f, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyFT4_1EE90 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {
            gte_ldv3c((char *)f + 8);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = D_1F800164_PolyFT4_1EE90Ptr;
                    gte_stsxy3_ft4(p);
                    gte_ldv0((char *)f + 0x20);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if ((LZ_FILE_CTRL_Long & 0x7f810000) == 0) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        gte_stsxy(&p->x3);
                        if ((p->y0 < 0xf1 || p->y1 < 0xf1 || p->y2 < 0xf1 || p->y3 < 0xf1) &&
                            (p->x0 < 0x141 || p->x1 < 0x141 || p->x2 < 0x141 || p->x3 < 0x141)) {
                            p->c0 = ((Face_1EE90 *)f)->c0;
                            p->clut = ((Face_1EE90 *)f)->clut;
                            p->tpage = ((Face_1EE90 *)f)->tpage;
                            p->uv0 = ((Face_1EE90 *)f)->uv0;
                            p->uv1 = ((Face_1EE90 *)f)->uv1;
                            p->uv2 = ((Face_1EE90 *)f)->uv2;
                            *(u16 *)((char *)p + 0x24) = ((Face_1EE90 *)f)->uv3;
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0) < 4)
                                otz = (long)D_1F8001E0 + 16;
                            else if ((unsigned long)(otz - (long)D_1F8001E0) >= 0xca0)
                                goto next;
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            D_1F800164_PolyFT4_1EE90Ptr = D_1F800164_PolyFT4_1EE90Ptr + 1;
                        }
                    }
                }
            }
        next:
            f += 10;
        } while (--n != 0);
    }
    return f;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011F108);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 uv0, clut;
    unsigned long c1;
    u16 x1, y1;
    u16 uv1, tpage;
    unsigned long c2;
    u16 x2, y2;
    u16 uv2, pad;
} PolyGT3_1F108;

typedef struct {
    u16 clut, tpage;
    unsigned long c0, c1, c2;
    u16 p10[3];
    u16 uv0;
    u16 p18[3];
    u16 uv1;
    u16 p20[3];
    u16 uv2;
} Face_1F108;
extern PolyGT3_1F108 *D_1F800164_PolyGT3_1F108Ptr asm("D_1F800164");


long *func_8011F108(long *f, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyGT3_1F108 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0x9000000;
        do {
            gte_ldv3c((char *)f + 0x10);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    gte_avsz3();
                    gte_stotz(&otz);
                    p = D_1F800164_PolyGT3_1F108Ptr;
                    gte_stsxy3_gt3(p);
                    if ((p->y0 < 0xf1 || p->y1 < 0xf1 || p->y2 < 0xf1) &&
                        (p->x0 < 0x141 || p->x1 < 0x141 || p->x2 < 0x141)) {
                        p->c0 = ((Face_1F108 *)f)->c0;
                        p->c1 = ((Face_1F108 *)f)->c1;
                        p->c2 = ((Face_1F108 *)f)->c2;
                        p->clut = ((Face_1F108 *)f)->clut;
                        p->tpage = ((Face_1F108 *)f)->tpage;
                        p->uv0 = ((Face_1F108 *)f)->uv0;
                        p->uv1 = ((Face_1F108 *)f)->uv1;
                        *(u16 *)((char *)p + 0x24) = ((Face_1F108 *)f)->uv2;
                        *((u8 *)p + 7) = 0x34;
                        otz = (otz << 2) + (long)ot;
                        if ((unsigned long)(otz - (long)D_1F8001E0) < 4)
                            otz = (long)D_1F8001E0 + 16;
                        else if ((unsigned long)(otz - (long)D_1F8001E0) >= 0xca0)
                            goto next;
                        t = *(unsigned long *)otz;
                        *(unsigned long *)otz = (unsigned long)p;
                        p->tag = t | len;
                        D_1F800164_PolyGT3_1F108Ptr = D_1F800164_PolyGT3_1F108Ptr + 1;
                    }
                }
            }
        next:
            f += 10;
        } while (--n != 0);
    }
    return f;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011F324);
typedef struct {
    unsigned long tag;
    unsigned long c0;
    u16 x0, y0;
    u16 uv0, clut;
    unsigned long c1;
    u16 x1, y1;
    u16 uv1, tpage;
    unsigned long c2;
    u16 x2, y2;
    u16 uv2, pad1;
    unsigned long c3;
    u16 x3, y3;
    u16 uv3, pad2;
} PolyGT4_1F324;

typedef struct {
    u16 clut, tpage;
    unsigned long c0, c1, c2, c3;
    u16 p14[3];
    u16 uv0;
    u16 p1c[3];
    u16 uv1;
    u16 p24[3];
    u16 uv2;
    u16 p2c[3];
    u16 uv3;
} Face_1F324;
extern PolyGT4_1F324 *D_1F800164_PolyGT4_1F324Ptr asm("D_1F800164");


long *func_8011F324(long *f, unsigned long *ot)
{
    long otz;
    s32 n;
    PolyGT4_1F324 *p;
    unsigned long len;
    unsigned long t;

    n = *f++;
    if (n != 0) {
        len = 0xc000000;
        do {
            gte_ldv3c((char *)f + 0x14);
            gte_rtpt();
            gte_stflg(&LZ_FILE_CTRL_Long);
            if (LZ_FILE_CTRL_Long >= 0) {
                gte_nclip();
                gte_stopz(&LZ_FILE_CTRL_Long);
                if (LZ_FILE_CTRL_Long > 0) {
                    p = D_1F800164_PolyGT4_1F324Ptr;
                    gte_stsxy3_gt4(p);
                    gte_ldv0((char *)f + 0x2c);
                    gte_rtps();
                    gte_stflg(&LZ_FILE_CTRL_Long);
                    if ((LZ_FILE_CTRL_Long & 0x7f810000) == 0) {
                        gte_avsz4();
                        gte_stotz(&otz);
                        gte_stsxy(&p->x3);
                        if ((p->y0 < 0xf1 || p->y1 < 0xf1 || p->y2 < 0xf1 || p->y3 < 0xf1) &&
                            (p->x0 < 0x141 || p->x1 < 0x141 || p->x2 < 0x141 || p->x3 < 0x141)) {
                            p->c0 = ((Face_1F324 *)f)->c0;
                            p->c1 = ((Face_1F324 *)f)->c1;
                            p->c2 = ((Face_1F324 *)f)->c2;
                            p->c3 = ((Face_1F324 *)f)->c3;
                            p->clut = ((Face_1F324 *)f)->clut;
                            p->tpage = ((Face_1F324 *)f)->tpage;
                            p->uv0 = ((Face_1F324 *)f)->uv0;
                            p->uv1 = ((Face_1F324 *)f)->uv1;
                            p->uv2 = ((Face_1F324 *)f)->uv2;
                            *(u16 *)((char *)p + 0x30) = ((Face_1F324 *)f)->uv3;
                            *((u8 *)p + 7) = 0x3c;
                            otz = (otz << 2) + (long)ot;
                            if ((unsigned long)(otz - (long)D_1F8001E0) < 4)
                                otz = (long)D_1F8001E0 + 16;
                            else if ((unsigned long)(otz - (long)D_1F8001E0) >= 0xca0)
                                goto next;
                            t = *(unsigned long *)otz;
                            *(unsigned long *)otz = (unsigned long)p;
                            p->tag = t | len;
                            D_1F800164_PolyGT4_1F324Ptr = D_1F800164_PolyGT4_1F324Ptr + 1;
                        }
                    }
                }
            }
        next:
            f += 13;
        } while (--n != 0);
    }
    return f;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011F5C4);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011F650);
void func_8011F650(GameObject *o, GameObject *e)
{
    if (e->subtype != 0) return;
    if ((u16)(o->d->p.whole - e->d->p.whole + 0x3c) >= 0x79) return;
    if ((u16)(o->h->p.whole - e->h->p.whole) >= 0x21) return;
    if ((u16)(o->hitOffsetY + (o->y.p.whole - e->y.p.whole + 0x20)) > o->hitHeight + 0x40) return;
    if (D_8009C068.unk68e != 1) return;
    *(u8 *)&o->unkA8 = 8;
    *(u8 *)&o->unkA0 = 1;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011F710);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011F7C0);
typedef struct { u16 frac, whole; } UF_1F7C0;
typedef struct O_1F7C0 {
    u8 active, visible, type, subtype;
    char p04[0x16 - 4];
    u16 y;
    char p18[0x40 - 0x18];
    UF_1F7C0 *h, *d;
    char p48[0x6c - 0x48];
    u16 box0;
    s16 box1;
    u16 box2;
    s16 box3;
    char p74[0x7c - 0x74];
    s16 velX, velY, velH;
    char p82[0x9c - 0x82];
    u8 b9c, b9d, b9e;
    char p9f[0xa6 - 0x9f];
    u8 ba6;
    char pa7[0xaa - 0xa7];
    u8 baa;
} O_1F7C0;

extern s16 D_1F80019E;
extern s16 func_80120778(O_1F7C0 *, s16, s16, s32, u8);
extern s16 func_80120814(O_1F7C0 *, s16, s16, u8);
extern s16 func_80120904(O_1F7C0 *, s16, s16, s32);

void func_8011F7C0(O_1F7C0 *o, O_1F7C0 *e)
{
    u16 a, b, d;
    s32 l, r, t;
    s16 f;
    s16 c;
    s32 x1, x2, d2;

    if (o->b9e) return;
    a = o->d->whole - e->d->whole + 0x2d;
    if ((u16)a >= 0x5b) return;
    b = o->h->whole - e->h->whole + (o->box0 + e->box0);
    if ((u16)b >= e->box1 + o->box1) return;
    d = o->y - e->y + (e->box2 + o->box2);
    if ((u16)d >= e->box3 + o->box3) return;
    if (o->b9c) {
        if (o->velX >= 0) { l = 8; r = -8; } else { l = -8; r = 8; }
    } else {
        if (o->velH >= 0) { l = 8; r = -8; } else { l = -8; r = 8; }
    }
    x1 = o->h->whole + l - (t = e->h->whole - e->box0);
    a = x1;
    x2 = o->h->whole + r - t;
    f = (u16)a < e->box1;
    b = x2;
    if ((u16)b < e->box1) f |= 2;
    d2 = o->y - (e->y + ((u16)e->box3 - e->box2));
    d = d2;
    c = o->baa == 0;
    switch (f) {
    case 0:
        return;
    case 1:
        if (c && func_80120778(o, x1, d2 + 8, 0, e->subtype)) o->ba6 = 2;
        {
            s16 sx = a;
            if (func_80120814(o, sx, d - 0xc, e->subtype)) goto hit;
            if (!func_80120904(o, sx, d + o->box2, e->subtype)) return;
            goto hit2;
        }
    case 2:
        if (c && func_80120778(o, x2, d2 + 8, 1, e->subtype)) o->ba6 = 3;
        {
            s16 sx = b;
            if (func_80120814(o, sx, d - 0xc, e->subtype)) goto hit;
            if (!func_80120904(o, sx, d + o->box2, e->subtype)) return;
            goto hit2;
        }
    case 3:
        {
            s16 sx, sy;
            if (c) {
                sy = d2 + 8;
                if (func_80120778(o, x1, sy, 0, e->subtype)) o->ba6 = 2;
                else if (func_80120778(o, x2, sy, 1, e->subtype)) o->ba6 = 3;
            }
            sx = a;
            sy = d - 0xc;
            if (func_80120814(o, sx, sy, e->subtype) || func_80120814(o, sx, sy, e->subtype)) {
            hit:
                if (o->velY < 0) o->velY = 0;
                D_1F80019E = 0;
                return;
            }
            if (func_80120904(o, sx, d + o->box2, e->subtype)) goto hit2;
            if (func_80120904(o, b, d + o->box2, e->subtype)) goto hit2;
        }
        return;
    default:
        return;
    }
hit2:
    applyCollisionTileResponse(o);
    o->h->whole += e->velX;
    D_1F80019E = 0;
    o->velY = 0;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011FC08);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011FD70);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011FEE4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8011FFAC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120278);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801204C4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120598);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801205D8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120608);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120708);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120778);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120814);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120884);

extern char *getCollisionColumnPtr(s16, u8);
extern s16 func_80044B0C(GameObject *, s16, s16, s32);

s16 func_80120884(GameObject *o, s16 x, s16 y, s32 k)
{
    (*(char **)&(*(void * *)&SCRATCHPAD.unk278)) = getCollisionColumnPtr(x, k);
    return func_80044B0C(o, x, y, k & 0xff);
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120904);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120974);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801209E4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120AC8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120B3C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120C78);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120CA8);
typedef struct { char p0[8]; s16 w8; s16 wa; } X_20CA8;

static __inline__ s32 snap_20CA8(GameObject *o, s16 t, s16 d)
{
    if (d < 5) o->h->p.whole = t;
    return 1;
}
static __inline__ s32 right_20CA8(GameObject *o, s16 h, s16 t)
{
    if (h < t) return snap_20CA8(o, t, t - h);
    return 0;
}
static __inline__ s32 left_20CA8(GameObject *o, s16 h, s16 t)
{
    if (h > t) return snap_20CA8(o, t, h - t);
    return 0;
}

s32 func_80120CA8(GameObject *o)
{
    X_20CA8 *x = (X_20CA8 *)((char *)o + 0xb4);
    s32 r;
    if ((o->subtype & 0x7f) == 0) {
        GameObject *p = (GameObject *)o->unk90;
        if (o->animFrame & 1) {
            o->unkBC = p->x.p.whole - p->hitOffsetX + 0x14;
        } else {
            *(s16 *)&o->unkBE = p->x.p.whole + (p->hitWidth - p->hitOffsetX) - 0x14;
        }
    }
    if (o->animFrame & 1) r = right_20CA8(o, o->x.p.whole, x->w8);
    else r = left_20CA8(o, o->x.p.whole, x->wa);
    return r;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120D9C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120E90);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80120ECC);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121070);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801210A4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801211A0);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012137C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121410);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121468);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121748);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801217F0);

extern u8 D_8012A61C[];

static __inline__ s32 Other_217F0(GameObject *o)
{
    if (o->unkB4 == 3) return 0;
    return o->unkB4 != D_8009C608.playerEquips_1;
}

static __inline__ s32 Near_217F0(GameObject *o)
{
    if ((u16)((*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) - o->h->p.whole + 0x64) >= 0xf1) return 0;
    return (u16)((*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) - o->y.p.whole + 0x50) < 0xc9;
}

void func_801217F0(GameObject *o)
{
    if (Other_217F0(o)) {
        o->subState = 3;
        o->step = 0;
        return;
    }
    if (o->timer != 0) return;
    o->timer = 0xb4;
    if (Near_217F0(o)) {
        if (D_8012A61C[nextRandom() & 7] == 0) {
            o->subState = 7;
            o->step = 0;
        }
    } else {
        if (D_8012A61C[nextRandom() & 7] == 0) {
            o->subState = 2;
            o->step = 0;
        }
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121900);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121C00);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121CD4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121CF0);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121D5C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121F54);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80121FF4);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012224C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80122258);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012228C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80122538);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801225D8);
extern void *D_8012DDEC[];
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

static __inline__ s32 Ground_225D8(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        return 1;
    }
    return 0;
}

void func_801225D8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unkB4 = 3;
        o->unk6A = 1;
        o->movetab = D_80077214;
        o->unkAC = 0x12;
        o->step++;
        o->anim = D_8012DDEC[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (tickAnimation(o)) {
            o->timer = 0x78;
            o->step++;
        }
        break;
    case 2:
        if (--o->timer == 0) {
            o->subState = 3;
            o->step = 0;
        }
        break;
    }
    if (o->visible && !Ground_225D8(o)) applyFrameVelocityY(o);
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80122734);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80122B1C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80122B6C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80122E44);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012302C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80123038);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80123168);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80123870);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801238A0);
void applyAnimVelocityX(GameObject *o, u16 v);

void func_801238A0(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->active = 2;
        o->unkB = 1;
        o->unkF = 4;
        o->velV = -0x400;
        o->unk8C = 0;
        o->movetab = ((char *)&D_8007722C);
        o->step++;
        o->animFrame &= 1;
        o->anim = D_8012D3F8;
        readAnimFrameCount(o);
        {
            u8 *c = &D_8009C068.unk596;
            printInfoMessage(*c + 0x29, 2);
            *c = *c + 1;
        }
        ((u8 *)&D_8009C068.unk685)[o->unkC] = 1;
        break;
    case 1:
        applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x40;
        if (o->velV > 0x400) {
            o->velV = 0x400;
        }
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1) {
        o->unk8C = (o->unk8C + 0x14) & 0xff;
    } else {
        o->unk8C = (o->unk8C - 0x14) & 0xff;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80123A14);


struct GSInventory_23A14 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_23A14 { u8 weapon; u8 pants; };

extern u8 D_8009C485[];

void func_80123A14(GameObject *o)
{
    s32 t = o->state;
    s32 s;

    switch (t) {
    case 0:
        o->active = 1;
        o->hitOffsetX = 0x10;
        o->hitWidth = 0x20;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->tpage = 9;
        o->unkD = 0;
        o->unkA = 0;
        if (D_8009C485[0] == 0) {
            o->unkD = 0x80;
            o->active = 2;
            o->objectIndex = 0x4f;
            o->unkA = 0xd;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8012D3F8;
        *(s8 *)&o->unkF = -9;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        readAnimFrameCount(o);
        o->state++;
        if (((u8 *)&D_8009C068.unk685)[o->unkC]) o->state = 3;
        if (D_8009C068.event_26 == 0xff) o->state = 3;
        break;
    case 1:
        if (GAME.selectedPlane == 0x21 && D_8009BC98.unk0A == 1) break;
        tickAnimation(o);
        func_80022E44(o);
        break;
    case 2:
        func_80022E44(o);
        s = o->subState;
        switch (s) {
        case 0:
        case 1:
            if (o->step == 0) tickAnimation(o);
            break;
        case 2:
            func_801238A0(o);
            if (o->visible == 0) o->state = 3;
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80123C18);

struct GSInventory_23C18 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_23C18 { u8 weapon; u8 pants; };

extern s32 D_1F8002D4[];
extern void *D_8012D3B0[];
extern void setEventComplete(s32, s32);
extern void addItemToInventory(s32, s32, s32);
extern void func_80123FB4(GameObject *);

void func_80123C18(GameObject *o)
{
    u8 s;

    switch (o->state) {
    case 0:
        if (o->subtype == 4) {
            o->unkA7 = 2;
            o->hitOffsetX = 0xc;
            o->hitWidth = 0x18;
            o->hitOffsetY = 0xe;
            o->hitHeight = 0x1c;
        } else {
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0xa;
            o->hitHeight = 0x14;
            o->unkA7 = o->animFrame;
            *(s32 *)&o->unk5C = o->x.p.whole;
            o->unk60 = o->y.p.whole;
            o->buffSize = o->z.p.whole;
        }
        *(s8 *)&o->unkF = -2;
        o->subState = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->animFrame = 0;
        o->unkD = 0;
        o->unkA = 0;
        o->tpage = 9;
        o->state++;
        o->spriteBank = D_1F8002D4[0];
        o->anim = D_8012D3B0[o->unkC];
        if (o->unkA7 != 1) {
            o->unk30 = o->x.raw;
            o->unk34 = o->y.raw;
            o->unk38 = o->z.raw;
        }
        break;
    case 1:
        if (GAME.selectedPlane != 0x20 && D_8009BC98.unk0A == 1)
            break;
        if (o->unkA7 == 1)
            func_80116814(o);
        func_80022E44(o);
        break;
    case 2:
        if (o->subtype == 4) {
            switch (o->subState) {
            case 0:
            case 1:
                func_80022E44(o);
                break;
            case 2:
                func_80022E44(o);
                PLAYER.obj.subtype = 1;
                setEventComplete(0xbd, 0);
                o->state = 3;
                break;
            }
            break;
        }
        switch (s = o->subState) {
        case 0:
            func_80022E44(o);
            if (o->unkA7 == 1)
                func_80116814(o);
            break;
        case 1:
            func_80022E44(o);
            if (o->subtype == 3)
                break;
            if (o->unkA7 == s) {
                ((GameObject *)o->unk90)->unk6A = o->subtype;
                break;
            }
            ((GameObject *)o->unk90)->unk6A = o->subtype;
            if (o->unk94 != 0)
                ((GameObject *)o->unk94)->unk6A = o->subtype;
            break;
        case 2:
            func_80022E44(o);
            if (o->subtype != 3) {
                D_8009C608.playerEquips_1 = o->subtype;
                if (o->unkA7 == 1)
                    ((GameObject *)o->unk90)->unk6A = o->subtype;
            }
            o->subState = 3;
            o->step = 0;
            break;
        case 3:
            if (o->subtype == 3) {
                addItemToInventory(9, 1, 1);
                o->state = 3;
                break;
            }
            if (GAME.selectedPlane != 0x21)
                func_80123FB4(o);
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80123FB4);
void func_80123FB4(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (o->unkA7 == 1) {
            o->unk34 += 0x1c0000;
            func_80116814(o);
        } else {
            o->x.raw = o->unk30;
            o->y.raw = o->unk34 + 0x1c0000;
            o->z.raw = o->unk38;
        }
        o->timer = 0x4b0;
        o->step++;
        break;
    case 1:
        if (--o->timer == -1) {
            o->active = 5;
            o->timer = 0x38;
            o->step++;
            if (o->unkA7 == 1)
                func_80116814(o);
        }
        break;
    case 2:
        func_80022E44(o);
        if (o->unkA7 == 1) {
            o->unk34 += -0x8000;
            func_80116814(o);
        } else {
            o->y.raw += -0x8000;
        }
        if (--o->timer == -1) {
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->active = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80124148);

typedef struct { s16 x, y; } P_24148;
extern void *D_8012E22C[];
extern s32 angleBetweenPoints(P_24148, P_24148);
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

static __inline__ s32 blocked_24148(GameObject *o)
{
    s32 d;
    u16 f = o->animFrame;
    if ((o->unk9D & 2) && f == (o->unk9D & 1)) {
        return 1;
    }
    {
        s16 g = f;
        d = g ? -16 : 16;
        return func_80043AB0(o, o->h->p.whole + d, o->y.p.whole + 0x30, g);
    }
}

void func_80124148(GameObject *o)
{
    P_24148 a, b;
    s16 r;
    s16 c;
    u8 st;
    s16 t;

    st = o->step;
    switch (st) {
    case 0:
        if (!o->visible) {
        o->step++;
        a.x = o->h->p.whole;
        a.y = o->y.p.whole;
        if (o->h->p.whole < SCRATCHPAD.unk168[3].p.whole + 0xa0) {
            b.x = SCRATCHPAD.unk168[3].p.whole + 0x20;
            o->animFrame = 0;
        } else {
            b.x = SCRATCHPAD.unk168[3].p.whole + 0x120;
            o->animFrame = 1;
        }
        b.y = SCRATCHPAD.unk168[7].p.whole - 0xc8;
        o->unk88 = angleBetweenPoints(a, b);
        o->unk74 = b.x;
        o->unkAC = 0;
        o->anim = D_8012E22C[0];
        readAnimFrameCount(o);
        } else {
            o->step = 2;
            tickAnimation(o);
        }
        break;
    case 1:
        if (o->visible) {
            if (!(o->animFrame & 1)) c = o->h->p.whole < o->unk74;
            else c = o->h->p.whole > o->unk74;
            if (!c) o->step = st + 1;
            o->velH = 1;
            o->unkAC = 0;
            o->anim = D_8012E22C[0];
            readAnimFrameCount(o);
        } else {
            if (!(o->animFrame & 1)) c = o->h->p.whole < o->unk74;
            else c = o->h->p.whole > o->unk74;
            if (c) o->step = 0;
            o->velH = 0xc;
        }
        o->h->raw += (D_8007DB88[(u8)o->unk88] * o->velH) << 4;
        o->y.raw += (D_8007D988[(u8)o->unk88] * o->velH) << 4;
        r = blocked_24148(o);
        t = probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x30);
        if (r && t) o->y.p.whole -= 2;
        break;
    case 2:
        if (o->subtype) o->subState = 5;
        else o->subState = 1;
        o->step = 0;
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801244B0);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012477C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80124D7C);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80125410);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80125504);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801257A8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80125BD8);

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80126028);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801265D8);

extern void *D_8012E244[];

static __inline__ void mv_265D8(GameObject *o)
{
    o->unk30 = (D_8007DB88[(*(u8*)&o->unk84)] * o->velH) >> 4;
    o->h->raw += o->unk30;
    o->unk84 = (o->unk84 + 1) & 0xff;
    if ((*(s16*)((char*)&o->unk30 + 2)) > 0) {
        if (!(o->unk9D & 2) || o->animFrame != (o->unk9D & 1))
            func_80043AB0(o, o->h->p.whole - 0x10, o->y.p.whole + 0x30, 1);
    } else {
        if (!(o->unk9D & 2) || o->animFrame != (o->unk9D & 1))
            func_80043AB0(o, o->h->p.whole + 0x10, o->y.p.whole + 0x30, 0);
    }
    {
        s32 v = D_8007D988[(*(u8*)&o->unk88)] * o->velV;
        o->unk88 = (o->unk88 + 3) & 0xff;
        o->y.raw = o->y.raw + (v >> 4) + 0x8000;
    }
    probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x30);
    tickAnimation(o);
}

void func_801265D8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->unkF = PLAYER.obj.unkF + 1;
        if (o->animFrame)
            o->velH = -0x100;
        else
            o->velH = 0x100;
        o->velV = 0x100;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkAC = 0;
        o->anim = D_8012E244[0];
        readAnimFrameCount(o);
        o->unk9A = 0;
        break;
    case 1:
        mv_265D8(o);
        if (!o->unkA7) {
            o->timer = 300;
            o->step++;
        }
        break;
    case 2:
        mv_265D8(o);
        if (--o->timer == -1) o->step++;
        if (o->unkA7) o->step = 1;
        break;
    case 3:
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        o->active = 1;
        o->unkF -= 2;
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80126A14);

s32 func_80126A14(GameObject *o)
{
    u8 t;
    if (o->subtype == 0) {
        switch (o->unk7) {
        case 0:
            if (D_8009C068.event_25 == 0xff) {
                o->unk7 = 3;
                return 0;
            }
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0E = 1;
            o->timer = 300;
            o->unk7++;
            setEventComplete(0x25, 0);
            goto ret0;
        case 1:
            if (--o->timer == -1) o->unk7++;
        ret0:
            return 0;
        case 2:
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            o->unk7++;
            return 0;
        case 3:
            return 1;
        }
    } else {
        t = (*(GameObject **)&o->unkA8)->unk7;
        o->unk7 = t;
        return t == 3;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80126B64);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801274C8);

typedef struct { Fix16 x, y, z; } V3F_274C8;

extern u8 D_8009C496;
extern void spawnItemDropAtPos(s32, s32, V3F_274C8 *, s32, s32);

void func_801274C8(GameObject *o)
{
    V3F_274C8 v;
    s32 k;

    if (!(D_8009C608.purifiedAreas & 1)) {
        k = D_8009C068.event_25;
        if (k == 0xff) {
        if (D_8009C496 || D_8009C068.unk71e) {
            o->state = 3;
            return;
        }
        if (o->subtype == 0) {
            v.x.p.whole = 0xd90;
            v.y.p.whole = -0x244;
            v.z.p.whole = 0xb9a;
            spawnItemDropAtPos(0x8a, 0, &v, 0, 0);
        }
        o->state = 3;
        return;
        }
        o->clut = 0x78d2;
    } else {
    if (!D_8009C496 && !D_8009C068.unk71e && !o->subtype) {
        v.x.p.whole = 0xd90;
        v.y.p.whole = -0x244;
        v.z.p.whole = 0xb9a;
        spawnItemDropAtPos(0x8a, 0, &v, 0, 0);
    }
    if (D_8009C068.unk723 == 2) {
    if (D_8009C068.item_0C || D_8009C068.unk721 || o->subtype) {
        o->state = 3;
        return;
    }
    v.x.p.whole = 0xbb8;
    v.y.p.whole = -0x276;
    v.z.p.whole = 0xb9a;
    spawnItemDropAtPos(0xc, 0, &v, 0, 0);
    o->state = 3;
    return;
    }
    o->clut = 0x7912;
    }
    *(s8 *)&o->unkF = -9;
    o->unkD = 1;
    o->tpage = 4;
    o->state++;
    o->unk7A = o->objectIndex;
    o->spriteBank = SCRATCHPAD.sprData[10];
    o->anim = (*(void **)&D_8012E22C);
    o->unkAC = 0;
    readAnimFrameCount(o);
    k = 0x10;
    o->hitWidth = 0x20;
    o->hitHeight = 0x20;
    o->hitOffsetX = k;
    o->hitOffsetY = k;
    o->unkA7 = 0;
    o->touchFlag = 0;
    o->unk9A = 0;
    o->unk98 = 3;
    o->objectIndex = 0;
    o->unk6A = 0;
    *(s32 *)&o->unkA8 = o->unk90 ? o->unk90 : o->unk94;
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801276EC);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80127C00);

extern void *D_8012DD9C[];

void func_80127C00(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0xb;
        o->unkD = 0x81;
        o->clut = GetClut(0x120, 0x1ef);
        o->spriteBank = SCRATCHPAD.sprData[8];
        o->anim = D_8012DD9C[0];
        o->unkA = 2;
        o->hitOffsetX = 2;
        o->hitWidth = 4;
        o->hitOffsetY = 8;
        o->hitHeight = 0xc;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            o->subState++;
            o->velV = 0x80;
            o->velH = 0x100;
            o->velX = 8;
            o->timer = 0x3c;
            break;
        case 1:
            o->y.raw += o->velV << 8;
            if (o->subtype == 0) {
                o->h->raw += o->velH << 8;
                o->unk8C -= 2;
            } else {
                o->h->raw -= o->velH << 8;
                o->unk8C += 2;
            }
            o->velH -= o->velX;
            if (o->velH == 0) {
                o->velV = 0x180;
                o->subState++;
            }
            o->timer--;
            break;
        case 2:
            o->y.raw += o->velV << 8;
            if (--o->timer == -1) o->state = 3;
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80127E40);
typedef struct { void **anims; s32 a; s32 b; } AT_27E40;
extern AT_27E40 D_8012A62C[];

void func_80127E40(GameObject *o, s16 n, s16 k)
{
    o->anim = D_8012A62C[o->subtype].anims[n];
    advanceAnimFrame(o, k);
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80127E94);
void func_80127E94(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = D_8012A62C[o->subtype].anims[0x18];
        readAnimFrameCount(o);
        o->velX = -0x100;
        o->velY = 0;
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        if (o->visible == 0) o->step = 2;
        break;
    case 2:
        o->state = 2;
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80127F8C);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128214);
void func_80128214(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = D_8012A62C[o->subtype].anims[0x18];
        readAnimFrameCount(o);
        o->velX = -0x100;
        o->velY = 0;
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += 0x60000;
        probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
        o->touchFlag = 0;
        if (o->h->p.whole < 0x708) o->step = 2;
        break;
    case 2:
        o->animFrame = 0;
        o->anim = D_8012A62C[o->subtype].anims[0x18];
        readAnimFrameCount(o);
        o->velX = 0x100;
        o->velY = 0;
        o->step++;
        break;
    case 3:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += 0x60000;
        probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
        if (o->h->p.whole > 0x780) o->step = 0;
        break;
    }
    if (o->unk68) {
        o->subState = 1;
        o->step = 0;
    }
    if (D_8009C068.event_28 == 0xff && !o->visible) o->state = 3;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012843C);

static __inline__ void pushL_2843C(s16 x, s16 w)
{
    if (x - w < (*(Fix16 **)&PLAYER.obj.h)->p.whole) (*(Fix16 **)&PLAYER.obj.h)->p.whole = x - w;
}

static __inline__ void pushR_2843C(s16 w1, s16 w0, s16 x)
{
    register Fix16 *p asm("$6") = (*(Fix16 **)&PLAYER.obj.h);
    if (p->p.whole < x + (w1 - w0)) p->p.whole = x + (w1 - w0);
}

void func_8012843C(GameObject *o)
{
    if (o->unkC == 0) {
        if ((o->active & 8) && D_8009BC98.unk0A && (u16)(o->y.p.whole - (*(u16*)&PLAYER.obj.y.p.whole) + 0x80) < 0x100) {
            if (o->animFrame & 1)
                pushL_2843C(o->h->p.whole, o->hitOffsetX);
            else
                pushR_2843C(o->hitWidth, o->hitOffsetX, o->h->p.whole);
        }
        switch (o->subState) {
        case 0:
            tickAnimation(o);
            break;
        case 1:
            switch (o->step) {
            case 0:
                o->animFrame = 1;
                o->anim = D_8012A62C[o->subtype].anims[24];
                readAnimFrameCount(o);
                o->velX = -0x100;
                o->velY = 0;
                o->step++;
            case 1:
                tickAnimation(o);
                o->h->raw += o->velX << 8;
                o->y.raw += o->velY << 8;
                if (o->visible == 0) o->step = 2;
                break;
            case 2:
                o->state = 2;
                break;
            }
            break;
        }
    } else {
        switch (o->subState) {
        case 0:
            func_80128214(o);
            break;
        case 1:
            func_80127F8C(o);
            break;
        }
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_8012868C);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80129344_2868C;

extern T80129344_2868C D_8012A624[];
extern s32 SPR_DATA[];

extern void readAnimFrameCount(GameObject *);

void func_8012868C(GameObject *o)
{
    o->hitOffsetX = D_8012A624[o->subtype].b0;
    o->hitWidth = D_8012A624[o->subtype].b1;
    o->hitOffsetY = D_8012A624[o->subtype].b2;
    o->hitHeight = D_8012A624[o->subtype].b3;
    o->tpage = D_8012A624[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_8012A624[o->subtype].w6];
    o->anim = D_8012A624[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->active = 10;
    o->unkD = 1;
    o->clut = 0x7c12;
    o->unk8C = 0;
    o->unkA = 0;
    o->unkF = 0;
    o->subState = 0;
    o->category |= 0x80;
    o->state++;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801287FC);
void func_801287FC(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8012868C(o);
        break;
    case 1:
        func_80022E44(o);
        func_8012843C(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_801288A4);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128C48);
void func_80128C48(GameObject *o)
{
    o->state = 1;
    o->subState = 0;
    o->step = 0;
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128C5C);
extern GameObject PLAYER_GameObject asm("PLAYER");
extern void func_800EDE44(GameObject *, s32, s32);

void func_80128C5C(GameObject *o)
{
    switch (o->subState) {
    case 0:
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        PLAYER_GameObject.animFrame = 1;
        PLAYER_GameObject.state = 5;
        PLAYER_GameObject.subState = 0;
        PLAYER_GameObject.step = 0;
        PLAYER_GameObject.visible = 1;
        func_800EDE44(&PLAYER_GameObject, 2, 0);
        PLAYER_GameObject.touchFlag = 0;
        *(s8 *)&PLAYER_GameObject.unkF = -8;
        o->subState++;
    case 1:
        if (PLAYER_GameObject.touchFlag) {
            PLAYER_GameObject.state = 5;
            PLAYER_GameObject.subState = 100;
            PLAYER_GameObject.step = 0;
            PLAYER_GameObject.y.p.whole = -0x1d0;
            func_800EDE44(&PLAYER_GameObject, 2, 0);
            o->subState++;
        }
        break;
    case 2:
        PLAYER_GameObject.h->raw -= 0x10000;
        if (PLAYER_GameObject.h->p.whole < 0x1068) {
            PLAYER_GameObject.h->p.whole = 0x1068;
            func_800EDE44(&PLAYER_GameObject, 0x2c, 0);
            o->subState++;
        }
        break;
    case 3:
        PLAYER_GameObject.d->raw -= 0x10000;
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128E14);
typedef struct PLXBlock_28E14 {
    u8 b60f8;
    u8 _pad1[0x3];
    u16 s60fc;
    u8 _pad6[0x1];
    u8 b60ff;
    u8 b6100;
    u8 _pad9[0x1];
    u8 b6102;
    u8 _padb[0x1];
    u8 b6104;
    u8 _padd[0x3];
    s16 s6108;
    s16 s610a;
    u8 _pad14[0xc];
    s16 s6118;
    u8 b611a;
    u8 b611b;
    void * p611c;
    u8 _pad28[0x58];
} PLXBlock_28E14;
extern PLXBlock_28E14 D_800A5458;


static __inline__ s16 chk_28E14(void)
{
    if (D_8009BC98.unk0A == 0) return 0;
    if (D_8009BC98.unk08 != 0) return 0;
    if (PLAYER.obj.touchFlag == 0 && D_800A5458.b6100 == 0) return 0;
    if ((u16)((*(u16 **)&PLAYER.obj.h)[1] - 0x1034) >= 0xc8) return 0;
    if (PLAYER.obj.y.p.whole < -0x1d0) return 0;
    return 1;
}

s32 func_80128E14(void)
{
    return chk_28E14();
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128EAC);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128EB8);

extern void freeObjectUnlayered(GameObject *);

static __inline__ s16 Cond_28EB8(void)
{
    if (!D_8009BC98.unk0A) return 0;
    if (D_8009BC98.unk08) return 0;
    if (!PLAYER.obj.touchFlag && !D_800A5458.b6100) return 0;
    if ((u32)((u16)(*(Fix16 **)&PLAYER.obj.h)->p.whole - 0x1034) >= 0xc8) return 0;
    if (PLAYER.obj.y.p.whole < -0x1d0) return 0;
    return 1;
}

void func_80128EB8(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        break;
    case 1:
        if (Cond_28EB8()) func_80128C5C(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80128FE0);
typedef struct {
    s16 flags;
    s16 frame;
    s16 wb4;
    s16 w74, w76, w78, w7a;
    s16 wba, wb8;
    s16 x, y, z;
    s16 subtype;
    s16 b0c;
} E_28FE0;
extern E_28FE0 D_8012A630[];

void func_80128FE0(GameObject *o)
{
    E_28FE0 *e;
    s16 i;
    GameObject *p;

    for (i = 0, e = D_8012A630; e->flags != 0xff; e = &D_8012A630[++i]) {
        if (*(volatile u16 *)&e->flags & 0x80) {
            GameObject *m = allocObjectLayer4();
            if (m) {
                m->active = 1;
                m->type = 0x1a;
                m->unkA = 0x10;
                m->animFrame = e->frame;
                m->subtype = e->subtype;
                m->unkC = e->b0c;
                m->x.p.whole = e->x;
                m->y.p.whole = e->y;
                m->z.p.whole = e->z;
            }
        } else {
            p = allocObjectLayer2();
            if (p) {
                p->active = 3;
                p->type = 0x32;
                p->unkA = 0;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
                p->unkB4 = e->wb4;
                p->unkB8 = e->wb8;
                p->unkBA = e->wba;
                p->unk74 = e->w74;
                p->unk76 = e->w76;
                p->unk78 = e->w78;
                p->unk7A = e->w7a;
                p->unk90 = (s32)o;
                SCRIPT_OBJECTS[i] = p;
                if (*(u16 *)&p->unkBA == 0 && D_8009C068.event_B0 == 0xff) p->state = 2;
                if (*(u16 *)&p->unkBA == 1) {
                    if (D_8009C068.event_28 == 0xff) p->state = 3;
                    if (((u8 *)&D_8009C068.event_28)[-2] != 0xff) p->state = 3;
                }
            }
        }
    }
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80129240);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80129A28);
extern void func_80129240(void);

void func_80129A28(void)
{
    func_80129240();
}

INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80129A48);

// INCLUDE_ASM("overlays/x09/nonmatchings/x09/x09", func_80129A54);
void func_80129A54(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80128FE0(o);
        o->state++;
        break;
    case 1:
        ((void (*)(GameObject *))func_80129240)(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_RODATA("overlays/x09/nonmatchings/x09/x09", func_80115608);
