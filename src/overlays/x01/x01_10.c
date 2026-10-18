#include "common.h"
#include "game.h"
#include "x01.h"

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_80139DF0);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A248);


extern GameObject PLAYER_GameObject asm("PLAYER");
extern u16 D_800A53C6_U16Arr[] asm("D_800A53C6");
extern GameObject *D_800A5428[];
extern char D_800108A8[];
extern GameObject *showMessageBox(s32, s32, s32, s32);

void func_8013A248(GameObject *o)
{
    GameObject *e = *(GameObject **)&o->category;
    GameObject *p;

    switch (o->subState) {
    case 0:
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk0E = 1;
        D_8009BC98.unk12 = 1;
        PLAYER_GameObject.anim = D_800108A8;
        readAnimFrameCount(&PLAYER_GameObject);
        D_800A53C6 = 0;
        e->state = 1;
        e->subState = 0;
        e->step = 0;
        D_800A539C = 5;
        D_800A539D = 0;
        D_800A539E = 0;
        D_800A5428[0] = showMessageBox(2, 0x1e, 0x80, 0x6c);
        D_800A53C6_U16Arr[0] = (*(Fix16 **)&D_800A53D8)->p.whole > e->h->p.whole;
        e->animFrame = (*(Fix16 **)&D_800A53D8)->p.whole < e->h->p.whole;
        o->subState++;
    case 1:
        p = D_800A5428[0];
        if (p->state == 2) {
            p->state = 3;
            GAME.fadeScreenControl = 3;
            o->subState++;
        }
        break;
    case 2:
        if (GAME.fadeScreenControl == 1) {
            D_8009C068.event_B5 = 1;
            GAME.nextArea = GAME.selectedArea;
            D_8009C068.unk57e = 0;
            D_8009C068.unk57f = 0;
            GAME.nextSpawnPoint = 0;
            GAME.nextSection = GAME.selectedSection;
            (*(GameTask **)&D_1F8001D4)->mode = 7;
            (*(GameTask **)&D_1F8001D4)->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A42C);
extern u8 D_800A5458;
extern void func_800EDE44(GameObject *, s32, s32);

void func_8013A42C(GameObject *o)
{
    GameObject *e = *(GameObject **)&o->category;
    GameObject *p;

    switch (o->subState) {
    case 0:
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk0E = 1;
        D_8009BC98.unk12 = 1;
        PLAYER_GameObject.anim = D_800108A8;
        readAnimFrameCount(&PLAYER_GameObject);
        e->animFrame = 0;
        D_800A53C6 = 0;
        (*(GameObject **)&D_800A5428) = showMessageBox(2, 0x19, 0x80, 0x6c);
        func_800EDE44(&PLAYER_GameObject, 0, 0);
        o->subState++;
        break;
    case 1:
        p = (*(GameObject **)&D_800A5428);
        if (p->state == 2) {
            p->state = 3;
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk0E = 0;
            D_8009BC98.unk12 = 0;
            D_8009C068.event_B5 = 1;
            D_8009C068.unk57e = 1;
            D_800A5458 = 0;
            D_800A539C = 1;
            D_800A539D = 0;
            D_800A539E = 0;
            e->subtype = 1;
            e->subState = 1;
            e->step = 0;
            e->animFrame = 0;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A58C);

void func_8013A58C(void)
{
    switch (D_8009C068.event_B5) {
    case 1:
        switch (D_8009C068.unk57e) {
        case 0:
            func_80139C04();
            break;
        case 1:
            func_80139DF0();
            break;
        }
        break;
    case 2:
        if (D_8009C068.unk57e == 0) ((void (*)(void))func_8013A248)();
        break;
    case 3:
        if (D_8009C068.unk57e == 0) ((void (*)(void))func_8013A42C)();
        break;
    case 0xff:
        func_80139DF0();
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A670);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A67C);

void func_8013A67C(GameObject *o)
{
    GameObject *e, *f;
    s16 i;
    s16 n;

    o->state = 3;
    if (D_8009C068.event_B2 == 0xff) return;
    e = allocObjectLayer8();
    if (e) {
        s32 **g;
        s32 *b;
        s32 t;
        g = ((s32 **)&D_1F800338);
        b = *g;
        e->active = 1;
        e->type = 6;
        e->animFrame = 0;
        e->unkA = 0x10;
        e->subtype = 0;
        e->unkC = 0;
        e->unkF = 0;
        t = (s32)*g + b[1];
        e->x.p.whole = 0xdc2;
        e->y.p.whole = -0x3a5;
        e->unkA4 = 1;
        e->z.p.whole = 0x880;
        e->unkA0 = t;
        *(GameObject **)&o->category = e;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
    }
    f = allocObjectLayer8();
    if (f) {
        s32 **g;
        s32 *b;
        s32 t;
        g = ((s32 **)&D_1F800338);
        b = *g;
        f->active = 1;
        f->type = 6;
        f->animFrame = 0;
        f->unkA = 0x10;
        f->subtype = 1;
        f->unkC = 0;
        f->unkF = 0;
        t = (s32)*g + b[2];
        f->x.p.whole = 0xdc2;
        f->y.p.whole = -0x3a5;
        f->unkA4 = 1;
        f->z.p.whole = 0x880;
        f->unkA0 = t;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
    }
    e->unk94 = (s32)f;
    f->unk90 = (s32)e;
    n = D_8009C068.unk54f;
    if (n > 30) n = 30;
    for (i = 0; i < n; i++) func_80113C20(e, 2, e->x.p.whole, e->y.p.whole, 0x87c);
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A83C);
s32 func_8013A83C(void)
{
    return D_8009C068.event_B2 != 0xff;
}

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_10", func_801158DC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013A854);

extern u16 D_800A53AA_U16Arr[] asm("D_800A53AA");
extern Fix16 *D_800A53D8_Fix16PtrArr[] asm("D_800A53D8");
extern s32 fixedMulSin(s32, s32);


void func_8013A854(GameObject *o)
{
    GameObject *e = *(GameObject **)&o->category;
    GameObject *p;
    s16 i;
    s16 n;
    s32 a, b;

    switch (o->subState) {
    case 0:
        o->subState++;
    case 1:
        if (D_8009C068.unk582) {
            n = D_8009C068.item_10;
            if (n > 30) n = 30;
            for (i = 0; i < n; i++) {
                a = nextRandom() & 3;
                b = nextRandom() & 3;
                func_80113C20(e, 1, (s16)(D_800A53AA_U16Arr[0] + a), (s16)(D_800A53AA_U16Arr[2] - b), (s16)(D_800A53AA_U16Arr[4] - 0x10));
            }
            D_8009C068.unk581 = 1;
            D_8009C068.unk582 = 0;
        }
        if (D_8009C068.event_B2 != 2) break;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk0E = 1;
        D_8009BC98.unk12 = 1;
        PLAYER_GameObject.anim = D_800108A8;
        readAnimFrameCount(&PLAYER_GameObject);
        o->x.raw = e->h->raw;
        {
            s32 y = e->y.raw;
            o->subState++;
            o->clut = 0x3c;
            o->y.raw = y;
        }
        break;
    case 2:
        e->h->raw = o->x.raw + ((((nextRandom() & 3) << 8) - 0x180) << 8);
        e->y.raw = o->y.raw + ((((nextRandom() & 7) << 8) - 0x380) << 8);
        if (o->clut != 0 && --o->clut <= 0) D_8009C068.event_B2 = 3;
        if (D_8009C068.event_B2 != 4) break;
        e->h->raw = o->x.raw;
        e->y.raw = o->y.raw;
        o->y.raw = 0;
        p = D_8009E654[0];
        (*(s16*)&o->unk34) = D_800A53D8_Fix16PtrArr[0]->p.whole - e->h->p.whole;
        (*(s16*)((char*)&o->unk34 + 2)) = D_800A53AE[0] - e->y.p.whole;
        (*(s16*)&o->unk38) = p->h->p.whole - e->h->p.whole;
        (*(s16*)((char*)&o->unk38 + 2)) = p->y.p.whole - e->y.p.whole;
        (*(s16*)&o->unkA) = 0;
        o->subState++;
        break;
    case 3:
        if (--(*(s16*)&o->unkA) > 0) break;
        (*(s16*)&o->unkA) = 0x3c;
        o->subState++;
        break;
    case 4:
        o->clut = (o->clut + 2) & 0xff;
        e->h->raw = o->x.raw + ((fixedMulSin(o->clut, 0x40) << 16) >> 8);
        e->y.raw += o->y.raw << 8;
        D_800A53D8_Fix16PtrArr[0]->p.whole = e->h->p.whole + (*(s16*)&o->unk34);
        p = D_8009E654[0];
        D_800A53AE[0] = e->y.p.whole + (*(s16*)((char*)&o->unk34 + 2));
        p->h->p.whole = e->h->p.whole + (*(s16*)&o->unk38);
        p->y.p.whole = e->y.p.whole + (*(s16*)((char*)&o->unk38 + 2));
        o->y.raw -= 8;
        if (--(*(s16*)&o->unkA) > 0) break;
        D_8009C068.unk66f = 1;
        GAME.fadeScreenControl = 3;
        o->subState++;
        break;
    case 5:
        if (GAME.fadeScreenControl != 1) break;
        (*(s16*)&GAME.nextArea) = 0x13;
        (*(s16*)&GAME.nextSection) = 2;
        (*(s16*)&GAME.nextSpawnPoint) = 1;
        {
            GameObject *q = D_1F8001D4;
            q->unk4C = 7;
            q->unk4E = 0;
        }
        o->subState++;
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013ACB0);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013ACBC);
extern s16 func_80138E64(GameObject *);

void func_8013ACBC(GameObject *o)
{
    GameObject *e;

    switch (o->state) {
    case 0:
        if (D_8009C068.event_0E >= 2 || (GAME.area00_eventControl & 0x100)) {
            o->state = 3;
            break;
        }
        e = allocObjectLayer2();
        if (e) {
            e->active = 1;
            e->type = 0x16;
            e->unkA = 2;
            e->x.p.whole = 0x105b;
            e->y.p.whole = -0x506;
            e->animFrame = 0;
            e->subtype = 0;
            e->unkC = 0;
            e->z.p.whole = 0x47a;
            *(GameObject **)&o->category = e;
        }
        o->state = 1;
        break;
    case 1:
        if (func_80138E64(o)) func_80138F88(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013ADE8);


static __inline__ s16 check_3ADE8(GameObject *o)
{
    s32 r = 0;

    if (D_8009C068.baronState != 0 && D_8009C068.baronState < 4 && PLAYER.obj.touchFlag != 0
        && (u16)((*(Fix16 **)&PLAYER.obj.h)->p.whole - 0xaad) < 0x40 && PLAYER.obj.y.p.whole >= -0x10f) {
        if (o->animTimer != 0) {
            r = 1;
        } else if ((*(s8 *)&D_8009C618) == 1 && (D_1F8001FC & (*(u16 *)&D_1F8003C4))) {
            r = 1;
            D_8009BC98.unk12 = 1;
            D_800A5458 = 1;
            o->animTimer = 1;
        }
    }
    return r;
}

void func_8013ADE8(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80139410(o);
        break;
    case 1:
        if (check_3ADE8(o)) func_80139610(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013AF5C);
s16 func_8013999C(GameObject *o);

void func_8013AF5C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_801397E8(o);
        break;
    case 1:
        if (func_8013999C(o)) {
            switch (D_8009C068.event_B5) {
            case 1:
                switch (D_8009C068.unk57e) {
                case 0:
                    ((void (*)(GameObject *o))func_80139C04)(o);
                    break;
                case 1:
                    func_80139DF0(o);
                    break;
                }
                break;
            case 2:
                if (D_8009C068.unk57e == 0) {
                    func_8013A248(o);
                }
                break;
            case 3:
                if (D_8009C068.unk57e == 0) {
                    func_8013A42C(o);
                }
                break;
            case 0xff:
                func_80139DF0(o);
                break;
            }
        }
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013B0D8);
void func_8013B0D8(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8013A67C(o);
        break;
    case 1:
        { s32 x = D_8009C068.event_B2; x ^= 0xff; if (x) func_8013A854(o); }
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013B180);

typedef struct {
    u8 active, visible, type, subtype, b04, step, state, substep;
    s16 w08;
    char p0a[0x1c - 0xa];
    s16 w1c, w1e, w20;
} O_3B180;

extern s16 D_1F80016E[];

void func_8013B180(O_3B180 *o)
{
    u16 t;
    GameObject *e;
    s16 *p = &o->w1c;

    switch (o->b04) {
    case 0:
        o->w1c = 0;
        o->w1e = 0;
        o->w20 = 0;
        o->w08 = D_8013BD38[nextRandom() & 7];
        if (D_8009C068.event_11) o->b04++;
        else o->b04 = 3;
        break;
    case 1:
        t = (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2));
        if ((u16)(t - 1000) < 0x49d && o->w1c < 2) {
            if (!(t & 0x1f)) {
                o->w1e = 1;
                if (--o->w08 != -1) break;
            } else {
                if (o->w1e != 1) break;
                if (--o->w08 != -1) break;
                o->w1e = 0;
            }
            o->w08 = D_8013BD38[nextRandom() & 7];
            e = allocObjectLayer2();
            if (e) {
                e->active = 2;
                e->type = 2;
                e->animFrame = 0;
                e->subtype = 8;
                e->unkC = 0;
                e->x.p.whole = 0;
                e->y.p.whole = D_1F80016E[0];
                e->z.p.whole = 0;
                o->w1c++;
                e->unk94 = (s32)p;
            }
        }
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_10", func_8013B360);

typedef struct { char pad[0xa]; s16 w0a; } W0AS_3B360;
#define W0A(p) (((W0AS_3B360 *)(p))->w0a)


extern GameObject *D_8009BCB0[];
extern Vec2s D_8013BD48[];

void func_8013B360(GameObject *o)
{
    GameObject *e;
    s32 r;

    switch (o->state) {
    case 0:
        o->clut = 600;
        W0A(o) = 0;
        D_8009BCB0[0] = o;
        o->state++;
        break;
    case 1:
        if (W0A(o) < 2) {
            if (--o->clut == -1) {
                o->clut = D_8013BD58[nextRandom() & 3];
                e = allocObjectLayer2();
                if (e) {
                    e->active = 2;
                    e->type = 0x13;
                    e->subtype = ((*(u8*)&SCRATCHPAD.unk1F8) + SCRATCHPAD.unk198) & 1;
                    e->unkC = 0;
                    r = nextRandom() & 3;
                    e->x.raw = SCRATCHPAD.vpx.raw;
                    e->y.raw = D_8013BD48[r].y << 16;
                    e->z.raw = D_8013BD48[r].x << 16;
                    W0A(D_8009BCB0[0])++;
                }
            }
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}
#undef W0A

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_10", D_80115910);
