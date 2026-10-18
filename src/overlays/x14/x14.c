#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115524);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_801155A8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115608);

INCLUDE_RODATA("overlays/x14/nonmatchings/x14/x14", func_80115214);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_8011570C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_801158DC);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115BF0);
extern void func_8011570C(void);

void func_80115BF0(void)
{
    func_8011570C();
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115C10);
extern void stepScrollReturnY(GameObject *);
extern void dampCameraAngle(GameObject *);
extern void func_8002A9FC(GameObject *);
extern void func_8002ABC0(GameObject *);

void func_80115C10(GameObject *o)
{
    stepScrollReturnY(o);
    dampCameraAngle(o);
    func_8002A9FC(o);
    func_8002ABC0(o);
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115C50);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115C70);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115D0C);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115D60);

typedef struct {
    u8 b0, b1, b2, b3;
    s32 pc;
    char pad[0x164 - 8];
    u8 b164, b165, b166;
} G_15D60;
extern u16 D_80124CBC[];
extern u16 D_80124EA8[];
extern char D_80124AFC[];
extern char D_80124BDC[];
extern char D_80124CC8[];
extern char D_80124D68[];
extern char D_80124E08[];

void func_80115D60(G_15D60 *g, char *s)
{
    RECT r;
    s32 *q = (s32 *)(s + 4);
    s32 i;
    s16 t;

    if (GAME.selectedSection == 6) {
        if (g->b164 == 0) {
            func_80115C50(0, 0);
            func_80115C50(1, 0);
            func_80115C50(2, 0);
            func_80115C50(3, 0);
            g->b165 = 0x3c;
            g->b164++;
        }
        if (g->b165-- <= 0) {
            i = g->b166;
            g->b165 = D_80124CBC[i];
            g->b166++;
            if (g->b166 >= 6) g->b166 = 0;
            r.x = 0x120;
            r.y = 0x1e0;
            r.w = 0x10;
            r.h = 7;
            if (!(i & 1)) LoadImage(&r, D_80124AFC);
            else LoadImage(&r, D_80124BDC);
        }
    } else if (GAME.selectedSection == 3 && !(SCRATCHPAD.unk1F8 & 7)) {
        i = g->b165;
        t = D_80124EA8[i];
        g->b165++;
        if (g->b165 >= 6) g->b165 = 0;
        r.x = 0x130;
        r.y = 0x1f0;
        r.w = 0x10;
        r.h = 5;
        if (t == 0) LoadImage(&r, D_80124CC8);
        else if (t == 1) LoadImage(&r, D_80124D68);
        else LoadImage(&r, D_80124E08);
    }
    g->pc = (s32)s + *q;
    g->b3 = 1;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115F60);
extern GameObject *allocObjectLayer3(void);

void func_80115F60(GameObject *o)
{
    GameObject *n = allocObjectLayer3();
    if (n != 0) {
        n->active = 1;
        n->type = 0x15;
        n->unkC = o->subState;
        n->unkF = o->unkF - 1;
        n->unk90 = (s32)o;
        n->x.p.whole = o->x.p.whole;
        n->y.p.whole = o->y.p.whole;
        n->z.p.whole = o->z.p.whole;
        n->unkAC = o->unkAC;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80115FEC);
extern GameObject *allocObjectLayer3(void);

void func_80115FEC(GameObject *o)
{
    GameObject *n = allocObjectLayer3();
    if (n != 0) {
        n->active = 1;
        n->type = 0x60;
        n->unkC = o->subState;
        n->unkF = o->unkF - 2;
        n->unk90 = (s32)o;
        n->x.p.whole = o->x.p.whole;
        n->y.p.whole = o->y.p.whole;
        n->z.p.whole = o->z.p.whole;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_8011606C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_801160A0);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116210);

extern u16 D_80124EB4[];
extern void *D_80124F44[];
extern char D_80129558[];
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);

void func_80116210(GameObject *o)
{
    u8 t = o->state;
    GameObject *p;
    s8 *q;

    switch (t) {
    case 0:
        o->tpage = 1;
        o->unkD = 0x81;
        o->clut = (D_80124EB4[GAME.selectedSection] << 6) | 0xb;
        o->animFrame = 0;
        o->anim = D_80129558;
        *(void **)((char *)o + 0x94) = D_80124F44[GAME.selectedSection];
        o->spriteBank = SCRATCHPAD.sprData[5];
        o->state++;
        readAnimFrameCount(o);
        o->timer = 9;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if (--o->timer == -1) o->subState++;
            break;
        case 1:
            p = (GameObject *)o->unk90;
            q = (s8 *)o->unk94 + (p->unkB8 & 0xe);
            o->x.p.whole = p->x.p.whole + q[0];
            o->y.p.whole = p->y.p.whole + q[1];
            if (tickAnimation(o)) o->state++;
            func_80022E44(o);
            break;
        }
        break;
    case 2:
        o->state = t + 1;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_801163EC);
extern GameObject *allocObjectLayer3(void);

s32 func_801163EC(GameObject *o, u8 n)
{
    GameObject *e = allocObjectLayer3();
    if (e) {
        e->active = 2;
        e->type = 0x23;
        e->subtype = n;
        e->x.raw = o->x.raw;
        e->y.raw = o->y.raw;
        e->z.raw = o->z.raw;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116464);

extern void *D_8012939C[];
extern u16 D_80124F64[];
extern u16 D_80124F6C[];

void func_80116464(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unkA = 2;
        o->tpage = 1;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkF = 0;
        o->unkD = 0x80;
        o->spriteBank = SCRATCHPAD.sprData[5];
        o->unkAC = 0;
        o->anim = D_8012939C[o->subtype];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
            if (tickAnimation(o)) o->state = 3;
            break;
        case 1:
        case 2:
        case 3:
            switch (o->subState) {
            case 0:
                o->timer = D_80124F64[nextRandom() & 3];
                o->subState++;
                o->velV = D_80124F6C[o->subtype];
                break;
            case 1:
                o->y.raw -= o->velV << 8;
                if (--o->timer == -1) o->state = 3;
                break;
            }
            tickAnimation(o);
            break;
        }
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_8011662C);


extern void *D_801293B8;

void func_8011662C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 1;
        *(s32 *)((char *)o + 0x84) = 0;
        *(s32 *)((char *)o + 0x88) = 0;
        *(s32 *)((char *)o + 0x8c) = 0;
        o->unkF = 0;
        o->unkA = 0;
        o->unkD = 0x80;
        o->spriteBank = SCRATCHPAD.sprData[5];
        o->timer = 0x28;
        o->velH = 0x100;
        if (o->animFrame) o->velH = -0x100;
        o->unkAC = 0;
        o->anim = D_801293B8;
        readAnimFrameCount(o);
        break;
    case 1:
        if (D_8009BC98.unk12 == 0) {
            o->x.raw += o->velH << 8;
            tickAnimation(o);
            if (--o->timer == -1) {
                o->state++;
            }
        }
        func_80022E44(o);
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116778);
extern GameObject *allocObjectLayer3(void);

s32 func_80116778(GameObject *o)
{
    GameObject *p = allocObjectLayer3();
    if (p != 0) {
        p->active = 2;
        p->type = 0x4f;
        p->x.p.whole = o->x.p.whole;
        p->y.p.whole = o->y.p.whole;
        p->z.p.whole = o->z.p.whole;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_801167E0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116814);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_801168F0);


extern void *D_80129340;
extern void func_8004FB54(s32);

void func_801168F0(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0x10;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_80129340;
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o)) tickAnimation(o);
        if (o->subtype != 1) break;
        switch (o->subState) {
        case 0:
            if (GAME.fadeScreenControl != 0) break;
            D_8009BC98.unk0C = 2;
            o->animFrame = 0x60;
            func_8004FB54(0x60);
            o->subState++;
            break;
        case 1:
            func_8004FB54((s16)o->animFrame);
            if (GAME.fadeScreenControl == 3) o->subState--;
            break;
        case 2:
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116A60);

extern void *D_801293C0;
extern void pushDrawListCapped(GameObject *);

void func_80116A60(GameObject *o)
{
    u8 b = o->state;

    switch (b) {
    case 0:
        o->state = b + 1;
        o->buffSize = 0x6000;
        o->tpage = 0xd;
        o->unkD = 0x80;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_801293C0;
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116B14);

extern void *D_801293D0[];

void func_80116B14(GameObject *o)
{
    u8 b = o->state;

    switch (b) {
    case 0:
        o->state = b + 1;
        o->tpage = 0xc;
        o->velX = 0x80;
        if (o->subtype == 0) {
            o->unkA5 = 0;
            o->unkA6 = 0x40;
        } else {
            *(s8 *)&o->unkA5 = -0x50;
            o->unkA6 = 0;
        }
        o->unk8C = 0;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_801293D0[o->subtype];
        readAnimFrameCount(o);
        break;
    case 1:
        tickAnimation(o);
        o->visible = 1;
        pushDrawListCapped(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116C1C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116C78);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116DF8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_80116FA0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", updatePointsBalloon);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14", func_8011700C);

INCLUDE_RODATA("overlays/x14/nonmatchings/x14/x14", func_80115274);
