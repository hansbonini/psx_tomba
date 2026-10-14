#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EEAC0);
extern void readAnimFrameCount(GameObject *);
extern void advanceAnimFrame(GameObject *, s32);

void func_800EEAC0(GameObject *o, u16 k)
{
    extern char D_800108A8[];
    s32 r = 0;

    switch (k) {
    case 0:
        o->anim = D_800108A8;
        readAnimFrameCount(o);
        return;
    case 1:
        switch (*(u16 *)o->anim) {
        case 8:
        case 24:
            r = 0;
            break;
        case 9:
            r = 1;
            break;
        case 10:
            r = 2;
            break;
        case 12:
            r = 3;
            break;
        case 13:
            r = 4;
            break;
        case 14:
            r = 5;
            break;
        case 15:
            r = 6;
            break;
        case 16:
            r = 7;
            break;
        case 17:
            r = 8;
            break;
        case 18:
            r = 9;
            break;
        case 19:
            r = 10;
            break;
        case 20:
            r = 11;
            break;
        case 21:
            r = 12;
            break;
        case 22:
            r = 13;
            break;
        }
        o->anim = D_80010974;
        break;
    case 2:
        switch (*(u16 *)o->anim) {
        case 17:
        case 34:
            r = 0;
            break;
        case 18:
        case 35:
            r = 1;
            break;
        case 19:
        case 36:
            r = 2;
            break;
        case 20:
        case 37:
            r = 3;
            break;
        case 38:
            r = 4;
            break;
        case 21:
        case 39:
            r = 5;
            break;
        case 22:
        case 40:
            r = 6;
            break;
        case 24:
        case 25:
            r = 7;
            break;
        case 9:
        case 26:
            r = 8;
            break;
        case 10:
        case 27:
            r = 9;
            break;
        case 12:
        case 28:
            r = 10;
            break;
        case 13:
        case 29:
            r = 11;
            break;
        case 30:
            r = 12;
            break;
        case 14:
        case 31:
            r = 13;
            break;
        case 15:
        case 32:
            r = 14;
            break;
        case 16:
        case 33:
            r = 15;
            break;
        }
        o->anim = D_800109E8;
        break;
    case 3:
        switch (*(u16 *)o->anim) {
        case 18:
        case 40:
            r = 0;
            break;
        case 19:
        case 25:
            r = 1;
            break;
        case 20:
        case 26:
            r = 2;
            break;
        case 21:
        case 27:
            r = 3;
            break;
        case 22:
        case 28:
            r = 4;
            break;
        case 23:
        case 29:
            r = 5;
            break;
        case 24:
        case 30:
            r = 6;
            break;
        case 9:
        case 31:
            r = 7;
            break;
        case 10:
        case 32:
            r = 8;
            break;
        case 11:
        case 33:
            r = 9;
            break;
        case 12:
        case 34:
            r = 10;
            break;
        case 13:
        case 35:
            r = 11;
            break;
        case 14:
        case 36:
            r = 12;
            break;
        case 15:
        case 37:
            r = 13;
            break;
        case 16:
        case 38:
            r = 14;
            break;
        case 17:
        case 39:
            r = 15;
            break;
        }
        o->anim = D_80010A6C;
        break;
    case 33:
        switch (*(u16 *)o->anim) {
        case 223:
            r = 1;
            break;
        case 224:
            r = 2;
            break;
        case 225:
            r = 3;
            break;
        case 226:
            r = 4;
            break;
        case 227:
            r = 5;
            break;
        case 228:
            r = 6;
            break;
        case 229:
            r = 7;
            break;
        case 230:
            r = 0;
            break;
        }
        o->anim = D_80011340;
        break;
    default:
        return;
    }
    advanceAnimFrame(o, r);
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EEDE0);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EEF64);

INCLUDE_RODATA("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", D_800E7764);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EEFEC);
typedef struct { GameObject o; char p0[6]; u8 c6, c7; char p1[0xe3 - 0xc8]; u8 e3; } TObjX_EEFEC;
extern GameObject *D_8009C650;
extern void playSFXWithVolume(s32 a, s32 b);

void func_800EEFEC(TObjX_EEFEC *x, s16 f)
{
    extern u8 *D_8009B698;
    GameObject *g;
    if (*(u8 *)&x->o.unkAC >= 2) {
        D_8009C650 = D_800A547C;
        D_8009C650->state = 2;
        D_8009C650->subState = 2;
        D_8009C650->step = 0;
    }
    *(u8 *)&x->o.unkAC = 0;
    D_8009BC9C = 0;
    x->c7 = 1;
    x->o.unk9D = 0;
    x->c6 = 0;
    x->e3 = 0;
    D_8009B698[0] = 0;
    switch (x->o.unk9E) {
    case 1:
        x->o.velX = 0;
        x->o.velY = 0;
        x->o.subState = 7; x->o.step = 0;
        break;
    case 2:
        x->o.velX = 0;
        x->o.velY = 0;
        x->o.subState = 6; x->o.step = 0;
        break;
    case 3:
        if ((u16)(x->o.velX + 0x1c0) > 0x380) D_8009B698[5] = 1;
        x->o.anim = D_80010D6C;
        readAnimFrameCount(x);
        x->o.unkF = 0;
        g = (*(GameObject **)&D_8009E454);
        x->o.unk30 = g->h->p.whole + x->o.unkB8 + 4;
        x->o.unk34 = g->y.p.whole + x->o.unkBA - 4;
        x->o.h->p.whole = x->o.unk30;
        x->o.subState = 5;
        x->o.step = 0;
        x->o.y.p.whole = x->o.unk34 + 12;
        return;
    case 4:
        if (((*(GameObject **)&D_8009E454)->category & 0x7f) == 2) {
            playSFXWithNote(0x1e, 0x1c);
            x->o.subState = 8; x->o.step = 0;
        } else {
            if ((*(GameObject **)&D_8009E454)->type == 2) (*(GameObject **)&D_8009E454)->touchFlag = 1;
            playSFXWithNote(0x1e, 0x1c);
            x->o.subState = 8; x->o.step = 0;
        }
        break;
    case 5:
        x->o.velX = 0;
        x->o.velY = 0;
        x->o.unk74 = x->o.h->p.whole;
        x->o.unk76 = x->o.y.p.whole;
        if (f != 0) { x->o.subState = 0xc; x->o.step = 0; }
        else { x->o.subState = 0x24; x->o.step = 0; }
        break;
    case 6:
        x->o.velX = 0;
        x->o.velY = 0;
        playSFXWithVolume(4, 0x7f);
        if (f != 0) { x->o.subState = 0xd; x->o.step = 0; }
        else { x->o.subState = 0x25; x->o.step = 0; }
        break;
    case 7:
        if ((*(u16 *)&GAME) != 10) { x->o.subState = 0x22; x->o.step = 0; }
        else { x->o.subState = 0x46; x->o.step = 0; }
        break;
    case 8:
        x->o.subState = 0x2e; x->o.step = 0;
        break;
    case 9:
        x->o.velX = 0;
        x->o.velY = 0;
        x->o.subState = 6; x->o.step = 0;
        break;
    case 10: case 11: case 12:
        x->o.subState = 0x2f; x->o.step = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EF27C);
s32 func_800EF27C(GameObject *o)
{
    extern u8 *D_8009B698;
    s32 r = 0;
    u8 t;
    if (o->unkBE) {
        o->velY = 0;
        o->unk9C = 0;
        t = o->subState;
        if (!(t == 0x10 || t == 0x17 || t == 0x1b || t == 0x1e || t == 0x1f)) {
            if (o->unkBE & 2) {
                if ((o->unkBE & 1) ? (o->unkB2 < -0x144) : (o->unkB2 > 0x144))
                    r = 1;
            } else if (o->unkBE & 4) {
                r = 2;
            } else if (o->unkBE & 8) {
                r = 3;
            } else if (o->unkBE & 0x10) {
                if ((o->unkBE & 1) ? (o->unkB2 < -0x144) : (o->unkB2 > 0x144))
                    r = 4;
            } else if (o->unkBE & 0x40) {
                r = 5;
            }
        }
        if ((o->unkBE & 0x20) && o->subState != 0x1f) {
            if (*D_8009B698 == 0 && ((u8 *)o)[0xc6] == 0) {
                D_8009B698[8] = o->animFrame & 1;
                o->subState = 0x1f;
                o->step = 0;
            }
            r = 0;
        }
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EF40C);
extern s32 D_8009BCEC;

void func_800EF40C(GameObject *o)
{
    extern void probeSidesAndApplyTileResponse(GameObject *, s32, s32);
    extern GameObject *D_8009B698;
    s32 v;

    *(u8 *)((u8 *)o + 0xad) = 0;
    if (*(u8 *)((u8 *)o + 0xab) != 2) {
        switch (func_800EF27C(o)) {
        case 1:
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            if ((D_8009BCEC & 0x40) && (D_8009C9D8[0] & (*(u16 *)&D_1F8003C4))) o->unkA7 = 1;
            *(u8 *)((u8 *)D_8009B698 + 8) = o->animFrame & 1;
            o->subState = 0x10;
            o->step = 0;
            break;
        case 2:
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            *(u8 *)((u8 *)D_8009B698 + 8) = o->animFrame & 1;
            o->subState = 0x17;
            o->step = 0;
            break;
        case 3:
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            *(u8 *)((u8 *)D_8009B698 + 8) = o->animFrame & 1;
            o->subState = 0x1b;
            o->step = 0;
            break;
        case 4:
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            *(u8 *)((u8 *)D_8009B698 + 8) = o->animFrame & 1;
            if ((D_8009BCEC & 0x40) && (D_8009C9D8[0] & (*(u16 *)&D_1F8003C4))) o->unkA7 = 1;
            o->subState = 0x1e;
            o->step = 0;
            break;
        case 5:
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            *(u8 *)((u8 *)D_8009B698 + 8) = o->animFrame & 1;
            o->subState = 0x21;
            o->step = 0;
            break;
        }
    }
    probeSidesAndApplyTileResponse(o, 0, 0);
    if ((o->touchFlag | o->unk9C | o->unk9E | o->unk9F | o->unkBE) == 0) {
        *(u8 *)((u8 *)o + 0xad) = 1;
        o->velY += 0x223;
        o->y.raw += o->velY << 8;
        D_8009B698->timer = 0x21;
        if (o->velY >= 0x447) {
            *(u8 *)((u8 *)o + 0xad) = 0;
            o->velY = 0;
            o->unk9C = 2;
            *(u8 *)((u8 *)o + 0xac) = 1;
            *(u8 *)((u8 *)o + 0xc3) = 0;
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            D_8009C618[0] = 0;
            v = 0x10;
            if (o->subState == 3) {
                o->timer = 10;
                o->unk84 = 0;
                if (o->animFrame & 1) v = 0xf0;
                o->unk88 = v;
                o->unk8C = 0;
                o->subState = 4;
                o->step = 1;
            } else {
                o->timer = 10;
                o->unk84 = 0;
                if (o->animFrame & 1) v = 0xf0;
                o->unk88 = v;
                o->unk8C = 0;
                o->subState = 2;
                o->step = 3;
            }
        }
    } else {
        o->velY = 0;
        o->unk9C = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EF6D4);
s32 func_800EF6D4(GameObject *o)
{
    extern GameObject *D_8009B698;
    *(u8 *)((u8 *)o + 0xad) = 0;
    probeSidesAndApplyTileResponse(o, 0, 0);
    if ((o->touchFlag | o->unk9C | o->unk9E | o->unk9F | o->unkBE) == 0) {
        *(u8 *)((u8 *)o + 0xad) = 1;
        o->velY += 0x223;
        o->y.raw += o->velY << 8;
        D_8009B698->timer = 0x21;
        if (o->velY >= 0x447) {
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            *(u8 *)((u8 *)o + 0xad) = 0;
            o->velY = 0;
            o->unk9C = 2;
            *(u8 *)((u8 *)o + 0xc3) = 0;
            o->unk8C = 0;
            return 1;
        }
    } else {
        o->velY = 0;
        o->unk9C = 0;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EF7B0);
typedef struct S_EF7B0 { char pad[0x16]; u16 h; char pad2[0x69 - 0x18]; char c; } S_EF7B0;
extern void probeSidesAndApplyTileResponse(S_EF7B0 *s, s32 a, s32 b);

void func_800EF7B0(S_EF7B0 *s)
{
    if (s->c) {
        s->h = s->h + 2;
    }
    probeSidesAndApplyTileResponse(s, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EF7F0);
typedef struct {
    u8 b0;
    u8 _p1[3];
    u8 b4;
    u8 _p5[0xf];
    s16 w14;
    u8 _p16[0x12];
    u16 w28;
    u16 w2a;
    u16 w2c;
    u16 w2e;
} PL_EF7F0;
typedef struct {
    GameObject t;
    u8 _pc0[9];
    u8 bc9;
    u8 _pca[0x24];
    u16 wee;
    u16 wf0;
    u16 wf2;
    u16 wf4;
    s16 wf6;
    PL_EF7F0 pl;
} TObjX_EF7F0;
typedef struct { u8 c, f, a, b; } E;
typedef struct { u16 a, b; } T2_EF7F0;
extern void loadCompressedTIM(s32);
extern void func_8002F138(void);
extern void func_8002F804(GameObject *, s32, s32);
extern void func_80117C60(void);
extern void func_80121CD4(GameObject *);
extern void func_80121C00(GameObject *);
extern void func_801205D8(GameObject *);
extern void func_8011CF9C(GameObject *);
extern void func_8011CC08(GameObject *);
extern void func_8011C678(GameObject *);
extern u8 D_8009C360;
extern u8 D_8009C26E;
extern u8 D_8009C61B;
extern u8 D_8009BCF8;
extern u8 D_800A545A[];
extern T2_EF7F0 D_8007D5BC[];
extern u16 D_800A53A0[];
extern u16 D_800A545C[];
extern u8 D_8009BCD8_U8Arr[] asm("D_8009BCD8");
extern E **D_801144E0[];
extern u8 D_8009BCA2_U8Arr[] asm("D_8009BCA2");
extern u8 D_8009C1A9;

#define LOADP() p = (u8 *)D_801144E0[(*(u16 *)&GAME)]; p = ((u8 **)p)[D_8009BCCA]; p += (*(u16 *)&D_8009BCEA) * 4

void func_800EF7F0(GameObject *o)
{
    extern u8 D_8009C36E[];
    extern u8 D_8009BCD8;
    extern PL_EF7F0 *D_8009B698;
    extern char D_800108A8[];
    PL_EF7F0 *pl;
    u8 *p;
    s16 c;
    u16 t;
    Fix16 *d;
    s32 a;
    char pad[0xe0];

    D_8009B698 = &((TObjX_EF7F0 *)o)->pl;
    switch (o->subState) {
    case 0:
        pl = D_8009B698;
        if (GetGraphType() != 1) GetGraphType();
        pl->w14 = 0;
        o->tpage = 0;
        switch (D_8009C61A[0]) {
        case 8: a = 1; break;
        case 9: a = 2; break;
        case 7: a = 0; break;
        default: a = 0; break;
        }
        loadCompressedTIM(a);
        {
            PL_EF7F0 *q = D_8009B698;
            *(u8 *)q = 0;
            q->w28 = 0xffff;
            q->w2a = 0xffff;
            q->w2e = 0xffff;
        }
        D_8009B698->b4 = 0;
        o->visible = 1;
        *(s8 *)&o->unkF = -8;
        o->unkA = 0;
        o->unkA5 = 0;
        o->unkB0 = 0;
        o->velH = 0;
        o->velV = 0;
        o->unkB2 = 0;
        o->unk9D = 0;
        o->subtype = 0;
        D_8009C360 = 0;
        if (D_8009C36E[0]) o->subtype = 2;
        if (D_8009C26E) o->subtype = 1;
        else D_8009C61B &= 3;
        D_800A545A[0] = D_8009C61B;
        D_800A53A0[0] = D_8007D5BC[D_8009BCF8].a;
        D_800A545C[0] = D_8007D5BC[D_8009C61B].b;
        o->unk9A = D_8009BCD8;
        o->unk98 = D_8009BCD8_U8Arr[0];
        o->spriteBank = SPR_DATA[0];
        o->anim = D_800108A8;
        readAnimFrameCount(o);
        o->subState++;
        if (D_8009C260) {
            ((TObjX_EF7F0 *)o)->bc9 = 1;
            func_8002F138();
        }
        switch ((*(u16 *)&GAME)) {
        case 0: func_80121C00(o); break;
        case 1: case 7: func_801205D8(o); break;
        case 3: func_8011CF9C(o); break;
        case 4: case 12: func_8011CC08(o); break;
        case 9: func_8011C678(o); break;
        }
        switch ((*(s8 *)&D_8009C618)) {
        case 3:
            LOADP();
            { u8 t3 = p[2];
            o->state = 5;
            o->subState = 4;
            o->step = 0;
            o->unk7 = 0;
            o->animFrame = t3; }
            break;
        case 4:
            LOADP();
            o->active = 1;
            { u8 t4 = p[2];
            o->state = 1;
            o->subState = 99;
            o->step = 0;
            o->animFrame = t4; }
            break;
        }
        if ((*(u32 *)&GAME) == 0x2000e) {
            o->state = 1;
            o->step = 0;
            o->subState = 0x3e;
            o->active = 1;
            o->animFrame = 0;
            o->cooldownTimer = 0;
            o->unk56 = -2000;
            D_8009BCA2 = 1;
        }
        break;
    case 1:
        LOADP();
        c = *p; p += 2;
        o->animFrame = p[0];
        o->timer = p[1];
        if (c == 99) {
            o->state = 5;
            o->subState = 12;
            o->step = 0;
            break;
        }
        if (c == 98) {
            if (D_8009C1A9) break;
            o->state = 5;
            o->subState = 4;
            o->step = 0;
            break;
        }
        if (o->animFrame & 0x80) func_8002F804(o, 0, 0);
        if (o->animFrame & 0x40) {
            o->cooldownTimer = 0x3c;
            if ((c & 0xff) == 7 || (c & 0xff) == 9) o->cooldownTimer = 1;
        }
        o->state = 5;
        o->animFrame &= 0xf;
        if (c == 2) {
            D_8009BCA2 = 1;
            o->active = 1;
        }
        o->subState = c;
        o->step = 0;
        o->unk7 = 0;
        if ((*(u16 *)&GAME) == 0) func_80121CD4(o);
        switch (o->subState) {
        case 2:
            { u16 t2 = o->h->p.whole;
            ((TObjX_EF7F0 *)o)->wf2 = o->y.p.whole;
            ((TObjX_EF7F0 *)o)->wf6 = 0;
            o->active = 3;
            o->state = 0;
            o->cooldownTimer = 0x3c;
            o->subState = 3;
            o->step = 0;
            o->unk7 = 0;
            ((TObjX_EF7F0 *)o)->wee = t2; }
            D_8009BCA2_U8Arr[0] = 1;
            break;
        case 3:
            func_80117C60();
            t = o->h->p.whole;
            ((TObjX_EF7F0 *)o)->wf2 = o->y.p.whole;
            d = o->d;
            ((TObjX_EF7F0 *)o)->wee = t;
            { s32 v = d->p.whole - 0x5a;
            o->active = 3;
            o->timer = 0x3c;
            o->cooldownTimer = 0x3c;
            o->state = 0;
            o->subState = 4;
            o->step = 0;
            o->unk7 = 0;
            ((TObjX_EF7F0 *)o)->wf6 = (v / 0x5a) * 0x5a; }
            break;
        }
        break;
    case 2:
        o->active = 3;
        LOADP();
        c = p[0];
        o->cooldownTimer = 0x3c;
        { u8 t5 = p[2];
        o->state = 1;
        o->step = 0;
        o->unk7 = 0;
        o->animFrame = t5 & 0xf; }
        o->subState = c;
        D_8009BCA2 = 1;
        break;
    case 3:
        break;
    case 4:
        if (--o->timer <= 0) {
            o->state = 5;
            o->subState = 2;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
}
#undef LOADP

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EFEBC);
typedef struct { s16 x; s16 y; } Cam_EFEBC;
extern u8 D_8009C436;

s16 func_800EFEBC(void)
{
    s16 r = 0;
    switch ((*(u16 *)&GAME)) {
    case 1:
        if (D_8009BCCA != 1)
            r = 1;
        else if (D_8009C11D)
            r = 1;
        break;
    case 9:
        if (D_8009BCCA != 1)
            r = 1;
        else if (D_8009C436 == 0) {
            if ((*(Cam_EFEBC **)&D_800A53D8)->y >= 0x73)
                r = 1;
        } else if ((*(Cam_EFEBC **)&D_800A53D8)->y < 0x72)
            r = 1;
        break;
    default:
        r++;
        break;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800EFF88);
typedef struct {
    u8 _p00[0x1e];
    u8 b1e;
    u8 _p1f[0xf];
    u16 w2e;
} PL_EFF88;
extern char D_80010F40[];
extern u8 D_8009C173;
extern u8 D_8009C442;
extern u8 D_8009C441;
extern u8 D_8009C130;
extern u8 D_8009C12D;

s32 func_800EFF88(GameObject *o)
{
    extern PL_EFF88 *D_8009B698;
    s32 r = 0;

    switch (*(u8 *)&o->unkA8) {
    case 1:
        r = 0xff;
        if (D_8009C619 == 1) {
            r = 10;
            if ((*(u16 *)&GAME) == 3) {
                r = 0xc;
                o->unk7A = 7;
            }
        }
        break;
    case 2:
        r = 0xff;
        if (D_8009C619 == 2) r = 9;
        break;
    case 3:
        r = 0xff;
        break;
    case 4:
        if (D_8009C173 == 0) {
            D_8009B698->w2e = 0xffff;
            o->anim = D_80010F40;
            readAnimFrameCount(o);
            r = 1;
        } else {
            D_8009B698->b1e++;
            r = 3;
        }
        break;
    case 5:
        if (D_8009C442 != 0) {
            D_8009B698->b1e++;
            r = 3;
        } else r = 0xff;
        break;
    case 6:
        if (D_8009C441 != 0) {
            D_8009B698->b1e++;
            r = 3;
        } else r = 0xff;
        break;
    case 7:
        if (D_8009C62B & 2) {
            D_8009B698->b1e++;
            o->unk7A = 8;
            r = 0xb;
        } else r = 0xff;
        break;
    case 8:
        D_8009B698->b1e++;
        r = 3;
        break;
    case 9:
        D_8009B698->w2e = 0xffff;
        o->anim = D_80010F40;
        readAnimFrameCount(o);
        r = 0xd;
        break;
    case 10:
        if (D_8009C130 == 0xff) {
            D_8009B698->b1e++;
            r = 0xb;
            o->unk7A = 9;
        } else r = 0xff;
        break;
    case 11:
        if (D_8009C441 != 0) {
            D_8009B698->b1e++;
            o->unk7A = 0x25;
            r = 0xb;
        } else r = 0xff;
        break;
    case 12:
        if (D_8009C12D == 0xff) {
            D_8009B698->b1e++;
            r = 0xb;
            o->unk7A = 0x37;
        } else r = 0xff;
        break;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F01DC);
typedef struct {
    u8 p0[0x1e];
    u8 b1e;
    u8 b1f;
    u8 p20[0x2c - 0x20];
    u16 w2c;
    u16 w2e;
} Q800F0E7C_F01DC;
extern Q800F0E7C_F01DC *D_8009B698_Q800F0E7C_F01DCPtr asm("D_8009B698");
extern u8 D_8009C11A;

#define SETANIM(n) \
    D_8009B698_Q800F0E7C_F01DCPtr->w2c = n; \
    func_800EEF64(o); \
    advanceAnimFrame(o, 0); \
    D_8009B698_Q800F0E7C_F01DCPtr->w2e = D_8009B698_Q800F0E7C_F01DCPtr->w2c;

#define SETANIM_IF(n) \
    D_8009B698_Q800F0E7C_F01DCPtr->w2c = n; \
    if (D_8009B698_Q800F0E7C_F01DCPtr->w2e != n) { \
        D_8009B698_Q800F0E7C_F01DCPtr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_Q800F0E7C_F01DCPtr->w2e = D_8009B698_Q800F0E7C_F01DCPtr->w2c; \
    }

s16 func_800F01DC(GameObject *o)
{
    s16 r = 0;
    u16 f = o->animFrame;

    if (f & 2) {
        if (f & 8) {
            D_8009B698_Q800F0E7C_F01DCPtr->b1f = 0;
            switch (((u8 *)o)[0xa0] & 0xf) {
            case 1:
                ((u8 *)o)[0xa2] = 1;
                if (func_800EFEBC()) {
                    SETANIM(0x49);
                    if (((u8 *)o)[0xa8]) {
                        r = func_800EFF88(o);
                    } else {
                        r = 3;
                        D_8009B698_Q800F0E7C_F01DCPtr->b1e++;
                    }
                }
                break;
            case 2:
                if (D_8009BCCA == 1 && ((*(u16 *)&GAME) == 2 || (*(u16 *)&GAME) == 0x13)) {
                    if (D_8009C11A != 0xff || D_8009C11D != 0xff) {
                        return r;
                    }
                }
                SETANIM(0x14);
                r = 1;
                ((u8 *)o)[0xa2] = 1;
                break;
            case 3:
                SETANIM_IF(0x24);
                r = 5;
                break;
            case 4:
                SETANIM_IF(0x24);
                ((u8 *)o)[0xa2] = 1;
                r = 4;
                break;
            case 5:
                SETANIM_IF(0x24);
                ((u8 *)o)[0xa2] = 1;
                r = 0x75;
                break;
            }
        } else if (f & 4) {
            D_8009B698_Q800F0E7C_F01DCPtr->b1e = 0;
            switch (((u8 *)o)[0xa0] >> 4) {
            case 1:
                SETANIM(0x18);
                r = 2;
                ((u8 *)o)[0xa3] = 1;
                break;
            case 2:
                SETANIM(0x48);
                r = 7;
                D_8009B698_Q800F0E7C_F01DCPtr->b1f++;
                break;
            case 3:
                SETANIM_IF(0x24);
                r = 6;
                break;
            case 4:
                SETANIM(0x18);
                ((u8 *)o)[0xa3] = 1;
                D_8009B698_Q800F0E7C_F01DCPtr->b1f++;
                r = 8;
                break;
            }
        } else {
            D_8009B698_Q800F0E7C_F01DCPtr->b1e = 0;
            D_8009B698_Q800F0E7C_F01DCPtr->b1f = 0;
        }
    }
    return r;
}
#undef SETANIM
#undef SETANIM_IF

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F0668);
extern u8 TALK_POSE;
extern GameObject *D_8009B698_GameObjectPtr asm("D_8009B698");
extern s32 rand(void);

#define SETANIM(o, n)                                     \
    {                                                     \
        GameObject *p = D_8009B698_GameObjectPtr;                           \
        p->animTimer = n;                                 \
        if (p->animFrame != n) {                          \
            p->animTimer = n;                             \
            func_800EEF64(o);                              \
            advanceAnimFrame(o, 0);                           \
            D_8009B698_GameObjectPtr->animFrame = D_8009B698_GameObjectPtr->animTimer; \
        }                                                 \
    }

void func_800F0668(GameObject *o)
{
    extern s32 tickAnimation(GameObject *o);
    switch (TALK_POSE) {
    case 1:
        if ((rand() & 0x3f) == 0)
            SETANIM(o, 0x4c);
        if (tickAnimation(o) != 0)
            D_8009B698_GameObjectPtr->animFrame = 0xff;
        break;
    case 2:
        SETANIM(o, 0x4d);
        tickAnimation(o);
        break;
    case 3:
        SETANIM(o, 0x4e);
        tickAnimation(o);
        break;
    case 4:
        SETANIM(o, 0x4f);
        tickAnimation(o);
        break;
    case 5:
        SETANIM(o, 0x4b);
        tickAnimation(o);
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F07D8);
extern u8 *D_8009C650_U8Ptr asm("D_8009C650");
extern u8 *D_8009B698_U8Ptr asm("D_8009B698");
extern u8 D_1F8003CE;
extern u8 D_800A5458;
extern u8 D_8009C36C;
extern s16 D_8009BCAC;
extern s16 D_8009BCAE[];
extern char D_8001096C[];
extern char D_8001152C[];
extern void func_8010E750(GameObject *);
extern void setObjectSpeedPolar2(GameObject *, s32, s32);
extern void applyObjectSpeedXY(GameObject *);
extern s32 func_8010D464(void);

typedef struct { u8 pad[0x28]; u16 w28, w2a, w2c, w2e; } Q_F07D8;
#define PL ((Q_F07D8 *)D_8009B698_U8Ptr)

#define YADJ(o)                                              \
    if (*(u8 *)((u8 *)o + 0xad) == 0) {                                  \
        if (o->subtype) {                                    \
            if ((u16)(o->unkB0 + 5) >= 0xb)         \
                o->y.raw += 0x50000;                         \
            else                                             \
                o->y.raw += 0x30000;                         \
        } else {                                             \
            if ((u16)(o->unkB0 + 5) >= 0xb)         \
                o->y.raw += 0xc0000;                         \
            else                                             \
                o->y.raw += 0x80000;                         \
        }                                                    \
    }

void func_800F07D8(GameObject *o)
{
    extern void func_8010D678(GameObject *, s16);
    u8 c;
    u8 *p;
    s32 t;

    *(u8 *)((u8 *)o + 0xa2) = 0;
    *(u8 *)((u8 *)o + 0xa3) = 0;
    if (*(u8 *)((u8 *)o + 0xac) >= 2) {
        D_8009C650_U8Ptr = (*(u8 **)&D_800A547C);
        (*(u8 **)&D_800A547C)[4] = 2;
        D_8009C650_U8Ptr[5] = 2;
        D_8009C650_U8Ptr[6] = 0;
    }
    *(u8 *)((u8 *)o + 0xac) = 0;
    c = 0;
    if (*(volatile u16 *)&D_8009C9D8 & 0xa0) {
        if (o->unkB2 == 0) {
            if ((u16)(*(u16 *)o->anim - 0x10d) >= 7)
                o->anim = D_8001096C;
            else
                o->anim = D_8001152C;
            readAnimFrameCount(o);
            PL->w2c = 999;
            PL->w2e = 0xffff;
            PL->w28 = 0xffff;
            PL->w2a = 0xffff;
            if (o->animFrame & 1)
                o->h->raw += -0x10000;
            else
                o->h->raw += 0x10000;
        } else {
            func_800EEDE0(o);
        }
        YADJ(o);
        D_8009B698_U8Ptr[0x1e] = 0;
        D_8009B698_U8Ptr[0x1f] = 0;
        o->velX = 0;
        o->subState = 1;
        o->step = 0;
        o->unk7 = 0;
    } else {
        switch (o->step) {
        case 0:
            *(u8 *)((u8 *)o + 0xc3) = 0;
            o->velX = 0;
            PL->w2c = 0;
            PL->w2e = 0xffff;
            o->unk7 = 0;
            o->step++;
        case 1:
            if (TALK_POSE) {
                func_800F0668(o);
            } else {
                c = func_800F01DC(o);
                if (!c)
                    func_800EEDE0(o);
                if (*(u16 *)o->anim || (!D_8009BCA7 && !D_1F8003CE))
                    tickAnimation(o);
            }
            {
                s16 u = o->unkB0;
                if (u < 0)
                    o->unkB6 = (s16)((u << 2) + 0x100) & 0xff;
                else if (u > 0)
                    o->unkB6 = (s16)(u << 2) & 0xff;
                else
                    o->unkB6 = 0;
            }
            func_8010E750(o);
            if (o->velY > 0x400) {
                *(u8 *)((u8 *)o + 0xac) = 1;
                D_8009B698_U8Ptr[0x1e] = 0;
                D_8009B698_U8Ptr[0x1f] = 0;
                t = 0x10;
                o->timer = 10;
                o->unk84 = 0;
                if (o->animFrame & 1)
                    t = 0xf0;
                o->unk88 = t;
                o->unk8C = 0;
                D_8009C618[0] = 0;
                o->subState = 2;
                o->step = 3;
                o->unk7 = 0;
            }
            YADJ(o);
            if (!(D_1F8001FC & ((*(u16 *)&D_1F8003C6) | (*(u16 *)&D_1F8003C8)))) {
                setObjectSpeedPolar2(o, o->unkB6, o->unkB2);
                o->h->raw += D_8009BCAC << 8;
                o->y.raw += D_8009BCAE[0] << 8;
                applyObjectSpeedXY(o);
            }
            break;
        }
    }

    switch (c) {
    case 4:
        if (D_1F8001FC & (*(u16 *)&D_1F8003C4)) {
            o->state = 5;
            o->subState = 0x61;
            o->step = 0;
            o->unk7 = 0;
            o->unkB2 = 0;
            D_8009BCA7 = 1;
            D_8009C618[0] = 2;
            D_8009BCAA = 1;
            o->visible = 1;
            D_8009B698_U8Ptr[0x1e] = 0;
            D_8009B698_U8Ptr[0x1f] = 0;
            D_800A5458 = 1;
        }
        break;
    case 9:
        if (D_1F8001FC & (*(u16 *)&D_1F8003C8)) {
            o->state = 1;
            o->subState = 0x3b;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    case 10:
        if (D_1F8001FC & (*(u16 *)&D_1F8003C8)) {
            o->state = 1;
            o->subState = 0x3c;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    case 12:
        if (D_1F8001FC & (*(u16 *)&D_1F8003C8)) {
            o->state = 5;
            o->subState = 0xb;
            o->step = 6;
            o->unk7 = 0;
        }
        break;
    default:
        if (func_8010D464() == 0)
            func_8010D678(o, 0);
        break;
    }

    if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
        o->unkA4 = 0;
        D_8009B698_U8Ptr[0x1e] = 0;
        D_8009B698_U8Ptr[0x1f] = 0;
        D_8009C618[0] = 0;
        o->unk7 = 0;
        switch (c) {
        case 0:
            o->unk9C = 1;
            if ((D_8009BCEC & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
                o->unkA7 = 1;
            o->state = 1;
            o->subState = 2;
            o->step = 0;
            break;
        case 1:
            o->state = 1;
            o->subState = 0x11;
            o->step = 0;
            break;
        case 2: {
            u16 hx = o->h->p.whole;
            u16 k = D_1F8001C8;
            *(u16 *)((u8 *)o + 0xf2) = o->y.p.whole;
            *(u16 *)((u8 *)o + 0xee) = hx;
            if (k & 1)
                *(u16 *)((u8 *)o + 0xf6) = (o->d->p.whole + 1) / 90 * 90;
            else
                *(u16 *)((u8 *)o + 0xf6) = (o->d->p.whole - 1) / 90 * 90;
            o->state = 1;
            o->subState = 0x12;
            o->step = 0;
            break; }
        case 5:
            o->state = 1;
            o->subState = 0x28;
            o->step = 0;
            break;
        case 6:
            o->state = 1;
            o->subState = 0x29;
            o->step = 0;
            break;
        case 8:
            o->state = 1;
            o->subState = 0x3a;
            o->step = 0;
            break;
        case 13:
            o->state = 5;
            o->subState = 0x65;
            o->step = 0;
            D_8009C36C = 1;
            break;
        }
    } else {
        p = D_8009B698_U8Ptr;
        if (p[0x1e] >= 0x1f) {
            switch (c) {
            case 3:
                p[0x1e] = 0;
                D_8009B698_U8Ptr[0x1f] = 0;
                o->state = 1;
                o->subState = 0x20;
                o->step = 0;
                break;
            case 11:
                p[0x1e] = 0;
                D_8009B698_U8Ptr[0x1f] = 0;
                o->state = 5;
                o->subState = 0xb;
                o->step = 0;
                break;
            }
        } else if (p[0x1f] >= 0x1f) {
            o->unk7 = 0;
            if (c == 7) {
                D_8009B698_U8Ptr[0x1e] = 0;
                D_8009B698_U8Ptr[0x1f] = 0;
                o->state = 1;
                o->subState = 0x31;
                o->step = 0;
            }
        }
    }
}
#undef PL
#undef YADJ

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F10A4);
typedef struct { s16 x, y; } XY;
typedef struct {
    GameObject o;
    char pc0[3];
    u8 c3;
    char pc4[0xcd - 0xc4];
    u8 cd, ce;
    char pcf[0xd5 - 0xcf];
    u8 d5, d6, d7;
} X_F10A4;
extern XY D_80114530[];
extern char D_80010F8C[];
extern void playSFX(s32);
extern s16 func_800EE26C(void);

static __inline__ void setanim_F10A4(GameObject *o, u16 anim)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
}

static __inline__ void dust_F10A4(GameObject *o)
{
    s16 x, y, z;
    GameObject *q;
    XY *t;
    x = o->x.p.whole;
    y = o->y.p.whole;
    z = o->z.p.whole;
    if (func_800EE26C() == 0 && (*(s16 *)&D_1F800238) >= 6 && (q = allocObjectLayer3()) != 0) {
        q->active = 1;
        q->type = 0x31;
        q->subtype = 1;
        t = &D_80114530[D_1F8001F8 & 7];
        q->x.p.whole = x;
        q->y.p.whole = y;
        q->z.p.whole = z;
        q->h->p.whole += t->x;
        q->y.p.whole += t->y;
    }
}

static __inline__ s16 odd_F10A4(void)
{
    if (D_1F8001F8 & 0xf) return 1;
    return 0;
}

void func_800F10A4(GameObject *o)
{
    extern GameObject *D_8009B698;
    u8 mode;
    s16 lim;
    s16 w;
    u16 t;

    if (*(u8 *)((u8 *)o + 0xac) >= 2) {
        D_8009C650_U8Ptr = D_800A547C;
        D_8009C650_U8Ptr[4] = 2;
        D_8009C650_U8Ptr[5] = 2;
        D_8009C650_U8Ptr[6] = 0;
    }
    *(u8 *)((u8 *)o + 0xac) = 0;
    if (D_8009C9D8[0] & 0xa0) {
        switch (o->step) {
        case 0:
            ((X_F10A4 *)o)->cd = 0;
            ((X_F10A4 *)o)->ce = 0;
            *(u8 *)((u8 *)D_8009B698 + 8) = 0;
            ((X_F10A4 *)o)->c3 = 0;
            o->velX = 0;
            o->step++;
        case 1:
            if (D_8009C61B >= 3) o->animTimer = 1;
            tickAnimation(o);
            w = o->unkB0;
            t = w;
            if (w < 0) {
                t = (t << 2) + 0x100;
                o->unkB6 = t & 0xff;
            } else {
                t <<= 2;
                if (w > 0) o->unkB6 = t & 0xff;
                else o->unkB6 = 0;
            }
            func_8010E750(o);
            func_800EEDE0(o);
            setObjectSpeedPolar2(o, o->unkB6, o->unkB2);
            o->h->raw += ((s16 *)&D_8009BCAC)[0] << 8;
            o->y.raw += ((s16 *)&D_8009BCAC)[1] << 8;
            applyObjectSpeedXY(o);
            if (*(u8 *)((u8 *)o + 0xad) == 0) {
                if (o->subtype != 0) {
                    if ((u16)(o->unkB0 + 5) >= 11) o->y.raw += 0x50000;
                    else o->y.raw += 0x30000;
                } else {
                    if ((u16)(o->unkB0 + 5) >= 11) o->y.raw += 0xc0000;
                    else o->y.raw += 0x80000;
                }
            }
            switch (o->unkA6) {
            case 2:
                if (D_8009C9D8[0] & 0x20) {
                    if (o->unkB2 >= 0x200) goto inc;
                    goto clr;
                }
                break;
            case 3:
                if (D_8009C9D8[0] & 0x80) {
                    if (o->unkB2 < -0x1ff) {
                    inc:
                        (*(u8 *)((u8 *)D_8009B698 + 8))++;
                        if (*(u8 *)((u8 *)D_8009B698 + 8) > 20) {
                            ((X_F10A4 *)o)->cd = 0;
                            ((X_F10A4 *)o)->ce = 0;
                            *(u8 *)((u8 *)D_8009B698 + 8) = 0;
                            o->subState = 0x1c;
                            o->step = 0;
                        }
                    } else {
                    clr:
                        *(u8 *)((u8 *)D_8009B698 + 8) = 0;
                    }
                }
                break;
            case 4:
            case 5:
                o->unkB2 = 0;
                break;
            default:
                if ((D_1F8001F8 & 7) == 0) playSFX(odd_F10A4());
                break;
            }
            if ((*(u16 *)&D_8009C978) == 7) {
                s32 f = o->animFrame & 3;
                if ((f == 0 && (((X_F10A4 *)o)->d5 == 3 || ((X_F10A4 *)o)->d6 == 3 || ((X_F10A4 *)o)->d7 == 3 || o->unkBF == 3)) ||
                    (f == 1 && (((X_F10A4 *)o)->d5 == 2 || ((X_F10A4 *)o)->d6 == 2 || ((X_F10A4 *)o)->d7 == 2 || o->unkBF == 2))) {
                    ((X_F10A4 *)o)->cd = 0;
                    ((X_F10A4 *)o)->ce = 0;
                    if ((o->unkA6 & 6) == 0) {
                        o->unkB2 = o->unkBC;
                        setanim_F10A4(o, 0x1a);
                        o->subState = 0x13;
                        o->step = 0;
                    } else {
                        o->unkB2 = 0;
                    }
                }
            } else if ((o->animFrame & 1) ? o->unkB2 > 0x144 : o->unkB2 < -0x144) {
                ((X_F10A4 *)o)->cd = 0;
                ((X_F10A4 *)o)->ce = 0;
                if (o->unkA6 & 6) {
                    o->unkB2 = 0;
                } else {
                    setanim_F10A4(o, 0x1a);
                    o->subState = 0x13;
                    o->step = 0;
                }
            }
            break;
        }
        mode = 0;
        if (D_8009C619 == 1) mode = 1;
        else if (D_8009C619 == 2) mode = 2;
        lim = 0x200;
        if (D_8009BCEC & 0x40) {
            lim = 0x360;
            if (!(D_8009C9D8[0] & (*(u16 *)&D_1F8003C4)) && (u32)(o->subtype - 1) >= 2) lim = 0x200;
        }
        if (mode != 0) {
            if ((u16)(o->unkB2 + lim) >= lim * 2) {
                o->unkB2 = (o->unkB2 < 0) ? -lim : lim;
                if (((X_F10A4 *)o)->cd == 0) {
                    ((X_F10A4 *)o)->cd = 1;
                    ((X_F10A4 *)o)->ce = (rand() % 2) * 45;
                    if (((X_F10A4 *)o)->ce == 0) ((X_F10A4 *)o)->ce = 12;
                } else {
                    ((X_F10A4 *)o)->ce--;
                }
                if (((X_F10A4 *)o)->ce == 0) {
                    u8 st;
                    switch (mode) {
                    case 1: st = 42; break;
                    case 2: st = 43; break;
                    default: goto done;
                    }
                    ((X_F10A4 *)o)->cd = 0;
                    ((X_F10A4 *)o)->ce = 0;
                    o->subState = st;
                    o->step = 0;
                }
            } else {
                ((X_F10A4 *)o)->cd = 0;
                ((X_F10A4 *)o)->ce = 0;
            }
        }
    done:
        if ((D_8009BCEC & 0x40) && (D_8009C9D8[0] & (*(u16 *)&D_1F8003C4))) {
            dust_F10A4(o);
        }
        if (o->subtype != 0) {
            dust_F10A4(o);
        }
    } else {
        func_800EEDE0(o);
        if (o->animFrame & 8) {
            if ((o->animFrame & 2) && (*(u8 *)((u8 *)o + 0xa0) & 2)) {
                D_8009B698->animFrame = 0xffff;
                o->anim = D_80010F40;
                *(u8 *)((u8 *)o + 0xa2) = 1;
            } else if ((o->animFrame & 4) && (*(u8 *)((u8 *)o + 0xa0) & 0x10)) {
                D_8009B698->animFrame = 0xffff;
                o->anim = D_80010F8C;
                *(u8 *)((u8 *)o + 0xa3) = 1;
            }
        }
        ((X_F10A4 *)o)->cd = 0;
        ((X_F10A4 *)o)->ce = 0;
        o->subState = 0;
        o->step = 0;
    }
    func_800EE26C();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F198C);
void func_800F198C(u8 *o)
{
    extern void func_8010E678(void);
    extern u8 *D_8009B698;
    u16 u;

    if (*(s16 *)(o + 0x7e) >= 0) {
        D_8009B698[8] = 1;
        o[6] = 2;
    }
    if ((D_8009C9D8[0] & (*(u16 *)&D_1F8003C6)) != 0) {
        if (D_8009B698[8] != 0)
            return;
        u = *(s16 *)(D_8009B698 + 0x20) + 1;
        *(u16 *)(D_8009B698 + 0x20) = u;
        if (0xd < u) {
            D_8009B698[8] = 1;
            o[6] = 2;
        }
    } else {
        D_8009B698[8] = 1;
        if (4 < *(u16 *)(D_8009B698 + 0x20)) {
            o[6] = 2;
            return;
        }
        *(u16 *)(D_8009B698 + 0x20) = *(u16 *)(D_8009B698 + 0x20) + 1;
    }
    func_8010E678();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F1A84);
typedef struct { s16 x, y; } XY_F1A84;
extern void func_800EDFA0(GameObject *);
extern void func_8010DE48(GameObject *);
extern void func_8010E444(GameObject *);
extern void applyObjectAltSpeedVertical(GameObject *);

void func_800F1A84(GameObject *o)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    GameObject *q;
    s16 x, y, z;
    XY_F1A84 *t;
    p->animTimer = 4;
    if (p->animFrame != 4) {
        p->animTimer = 4;
        ((void (*)(GameObject *, GameObject *))func_800EEF64)(o, p);
        advanceAnimFrame(o, 0);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
    if (o->unkA7 != 0) {
        x = o->x.p.whole;
        y = o->y.p.whole;
        z = o->z.p.whole;
        if (func_800EE26C() == 0 && (*(s16 *)&D_1F800238) >= 6 && (q = allocObjectLayer3()) != 0) {
            q->active = 1;
            q->type = 0x31;
            q->subtype = 1;
            t = &D_80114530[D_1F8001F8 & 7];
            q->x.p.whole = x;
            q->y.p.whole = y;
            q->z.p.whole = z;
            q->h->p.whole += t->x;
            q->y.p.whole += t->y;
        }
    }
    func_800EDFA0(o);
    func_8010DE48(o);
    o->h->raw += o->velX << 8;
    func_8010E444(o);
    applyObjectAltSpeedVertical(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F1C00);
extern char D_80010C48[];
extern void func_8011068C(GameObject *);
extern void func_8011070C(GameObject *);
extern void func_800EDA30(GameObject *);

void func_800F1C00(GameObject *o)
{
    extern GameObject *D_8009B698;
    GameObject *p;
    u16 *q;
    if ((*(u16 *)&GAME) == 3 && D_8009BCAC != 0) {
        p = D_8009B698;
        q = &p->animFrame;
        p->animTimer = 0x35;
        if (*q != 0x35) {
            p->animTimer = 0x35;
            func_800EEF64(o);
            advanceAnimFrame(o, 0);
            D_8009B698->animFrame = D_8009B698->animTimer;
        }
    } else {
        o->anim = D_80010C48;
        advanceAnimFrame(o, 3);
    }
    tickAnimation(o);
    *(volatile s32 *)&o->h->raw += D_8009BCAC * 0x80;
    o->y.raw += (*(s16 *)&D_8009BCAE) * 0x80;
    func_8011068C(o);
    o->h->raw += o->velX * 0x100;
    o->timer--;
    if ((s16)o->timer <= 0) {
        o->timer = 0;
        func_8011070C(o);
        applyObjectAltSpeedVertical(o);
    }
    func_800EDA30(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F1D3C);
void func_800F1D3C(GameObject *o)
{
    extern u8 *D_8009B698;
    s32 v;
    D_8009B698[8] = 1;
    v = 0x10;
    o->velY = 0;
    o->velV = 0;
    o->unk84 = 0;
    if (o->animFrame & 1) {
        v = 0xf0;
    }
    o->timer = 10;
    o->unk9C = 2;
    o->unk88 = v;
    *(u8 *)&o->unkAC = 1;
    o->step = 3;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F1D90);
typedef struct { char p[8]; u8 b8; char q[0x20 - 9]; s16 w20; char r[0x2e - 0x22]; s16 w2e; } G_F1D90;
extern u8 D_80114638[];
extern u8 D_8009C26E_U8Arr[] asm("D_8009C26E");
extern u8 D_8009C1C9;
void setEventComplete(s32, s32);
void func_800F1D90(GameObject *o)
{
    extern G_F1D90 *D_8009B698;
    if (*((u8 *)o + 0xc9)) D_8009B698->w2e = 0xff;
    o->unkA7 = 0;
    D_8009B698->b8 = 0;
    playSFXWithVolume(0x1c, 0x7f);
    o->unk9C = 0;
    if (*(u8 *)&o->unkAC >= 2) {
        D_8009C650 = D_800A547C;
        D_8009C650->state = 2;
        D_8009C650->subState = 2;
        D_8009C650->step = 0;
    }
    *(u8 *)&o->unkAC = 0;
    if (o->velX > 0) {
        o->velX -= 0xd0;
        if (o->velX < 0) o->velX = 0;
    } else {
        o->velX += 0xd0;
        if (o->velX > 0) o->velX = 0;
    }
    o->unkB2 = o->velX;
    o->velX = 0;
    o->velY = 0;
    o->unk8C = D_80114638[o->unkB0];
    o->unkA5 = 0;
    D_8009B698->w20 = 0;
    if (D_8009C26E_U8Arr[0] && o->subtype != 1) {
        o->subtype = 1;
        if (D_8009C1C9 != 0xff) setEventComplete(0xbd, 1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F1EF8);
typedef struct {
    u8 b0;
    u8 p1[3];
    u8 b4, b5;
    u8 p6[2];
    u8 b8;
    u8 p9[0x20 - 9];
    u16 w20;
    u8 p22[0x28 - 0x22];
    u16 w28, w2a, w2c, w2e;
} P800F2B98_F1EF8;
typedef struct {
    u8 p0[0xc3];
    u8 c3;
    u8 p4[0xc9 - 0xc4];
    u8 c9;
    u8 pa[0xcc - 0xca];
    u8 cc;
    u8 pd[0xe4 - 0xcd];
    u8 *e4;
} X800F2B98_F1EF8;
typedef struct { void *p[90]; } T800F2B98;
extern u8 D_8009C619_U8Arr[] asm("D_8009C619");
extern T800F2B98 D_800E7764;
extern s32 clampToCeilingAndProbeSides(GameObject *);
extern void probeCollisionAtDepthA(GameObject *, s16, s16);
extern s32 func_80059B58(GameObject *, s32);

void func_800F1EF8(GameObject *o)
{
    extern s16 fixedMulCos(s32, s32);
    extern P800F2B98_F1EF8 *D_8009B698;
    T800F2B98 tab;
    s16 s;
    s32 d;
    u8 v;
    u16 m;
    u8 bb;

    switch (o->step) {
    case 0:
        d = o->unkB2;
        o->timer = 10;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->touchFlag = 0;
        o->unk9E = 0;
        *(u8 *)&o->unkAA = 0;
        ((X800F2B98_F1EF8 *)o)->c3 = 0;
        o->touchFlag = 0;
        o->unk9C = 1;
        o->unkB0 = 0;
        *(u8 *)&o->unkA0 = 0;
        *((u8 *)&o->unkA0 + 1) = 0;
        o->unkB6 = 0;
        o->velX = fixedMulCos(0, d);
        o->velY = 0;
        D_8009B698->b8 = 0;
        D_8009B698->w2c = 4;
        D_8009B698->w20 = 0;
        D_8009B698->b5 = 0;
        if (*(u8 *)&o->unkAC >= 2) {
            D_8009C650_U8Ptr = (*(u8 **)&D_800A547C);
            (*(u8 **)&D_800A547C)[4] = 2;
            D_8009C650_U8Ptr[5] = 2;
            D_8009C650_U8Ptr[6] = 0;
        }
        *(u8 *)&o->unkAC = 0;
        func_8010E678(o);
        tab = D_800E7764;
        o->anim = tab.p[D_8009B698->w2c];
        readAnimFrameCount(o);
        D_8009B698->w2e = D_8009B698->w2c;
        playSFXWithNote(2, 4);
        o->step = 1;
    case 1:
        if (o->velY >= 0) {
            D_8009B698->b8 = 1;
            o->step = 2;
        }
        if (D_8009C9D8[0] & (*(u16 *)&D_1F8003C6)) {
            if (D_8009B698->b8 != 0) goto common;
            if (++D_8009B698->w20 >= 0xe) {
                D_8009B698->b8 = 1;
                o->step = 2;
            }
        } else {
            D_8009B698->b8 = 1;
            if (D_8009B698->w20 >= 5) {
                o->step = 2;
                goto common;
            }
            D_8009B698->w20++;
        }
        func_8010E678(o);
    case 2:
    common:
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        tickAnimation(o);
        if (o->unkA7 != 0) {
            s16 a = o->x.p.whole, y = o->y.p.whole, b = o->z.p.whole;
            GameObject *q;
            if (func_800EE26C() == 0 && (*(s16 *)&D_1F800238) >= 6 && (q = allocObjectLayer3()) != 0) {
                s16 *t;
                q->active = 1;
                q->type = 0x31;
                q->subtype = 1;
                q->x.p.whole = a;
                q->y.p.whole = y;
                q->z.p.whole = b;
                t = &((s16 *)&D_80114530)[(D_1F8001F8 & 7) * 2];
                q->h->p.whole += t[0];
                q->y.p.whole += t[1];
            }
        }
        func_8010E750(o);
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        if (o->velY >= -899) func_800EDFA0(o);
        if (o->velY > 0) {
            { s32 e;
            D_8009B698->b8 = 1;
            e = 0x10;
            o->velY = 0;
            o->velV = 0;
            o->unk84 = 0;
            if (o->animFrame & 1) e = 0xf0;
            o->timer = 10;
            o->unk9C = 2;
            o->unk88 = e;
            *(u8 *)&o->unkAC = 1;
            o->step = 3; }
        }
        if (clampToCeilingAndProbeSides(o)) {
            { s32 e;
            D_8009B698->b8 = 1;
            e = 0x10;
            o->velY = 0;
            o->velV = 0;
            o->unk84 = 0;
            if (o->animFrame & 1) e = 0xf0;
            o->timer = 10;
            o->unk9C = 2;
            o->unk88 = e;
            *(u8 *)&o->unkAC = 1;
            o->step = 3; }
        }
        probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
        o->touchFlag = 0;
        break;
    case 3:
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        tickAnimation(o);
        if (((X800F2B98_F1EF8 *)o)->c9 != 0) func_800F1C00(o);
        else func_800F1A84(o);
        func_8010E750(o);
        D_8009B698->b8 = 1;
        o->unk9E = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        clampToCeilingAndProbeSides(o);
        if (*(u8 *)&o->unkAC == 2) {
            D_8009C650_U8Ptr = ((X800F2B98_F1EF8 *)o)->e4;
            D_8009B698->b8 = 0;
            o->unkA7 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            *((u8 *)&o->unkAA + 1) &= 0x7f;
        } else if (o->touchFlag == 1) {
            func_800F1D90(o);
            if (*((u8 *)&o->unkAA + 1) & 0x80) {
                o->unkA4 = 0;
                switch (D_8009C619_U8Arr[0]) {
                case 1: o->subState = 0x2a; o->step = 0; break;
                case 2: o->subState = 0x2b; o->step = 0; break;
                default: o->step = 0; break;
                }
            } else if (o->unkBE & 8) {
                D_8009B698->b8 = *(u8 *)&o->animFrame & 1;
                o->subState = 0x1b;
                o->step = 0;
            } else {
                o->unkA4 = 0;
                D_8009B698->w2e = 0xffff;
                D_8009B698->w28 = 0xffff;
                D_8009B698->w2a = 0xffff;
                o->unk8C = D_80114638[o->unkB0];
                o->subState = 1;
                o->step = 0;
                if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
                    (*(u8 *)&D_8009C618) = 0;
                    o->subState = 2;
                    o->step = 0;
                }
            }
        } else if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 4, 0) != 0) {
            func_800F1D90(o);
            if (*((u8 *)&o->unkAA + 1) & 0x80) {
                o->unkA4 = 0;
                o->unkA5 = 0;
                D_8009B698->w20 = 0;
                switch (D_8009C619_U8Arr[0]) {
                case 1: o->subState = 0x2a; o->step = 0; break;
                case 2: o->subState = 0x2b; o->step = 0; break;
                default: o->step = 0; break;
                }
            } else if (o->unkBE != 0) {
                o->subState = 1;
                o->velY = 0;
                o->step = 0;
                if (o->subState == 0x10 || o->subState == 0x17 || o->subState == 0x1b || o->subState == 0x1e) goto l33e8;
                bb = o->unkBE;
                if ((bb & 2) && o->unk9C == 0) {
                    if (bb & 1) {
                        if (o->unkB2 < -0x144) goto l3344;
                    } else if (o->unkB2 > 0x144) {
                    l3344:
                        D_8009B698->b8 = *(u8 *)&o->animFrame & 1;
                        o->subState = 0x10;
                        o->step = 0;
                    }
                } else if (bb & 4) {
                    D_8009B698->b8 = *(u8 *)&o->animFrame & 1;
                    o->subState = 0x17;
                    o->step = 0;
                } else if (bb & 0x10) {
                    if (bb & 1) {
                        if (o->unkB2 < -0x144) goto l33c8;
                    } else if (o->unkB2 > 0x144) {
                    l33c8:
                        D_8009B698->b8 = *(u8 *)&o->animFrame & 1;
                        o->subState = 0x1e;
                        o->step = 0;
                    }
                }
            l33e8:
                if (o->unkBE & 0x20) {
                    D_8009B698->b8 = *(u8 *)&o->animFrame & 1;
                    o->subState = 0x1f;
                    o->step = 0;
                }
            } else {
                o->unkA4 = 0;
                o->unkA5 = 0;
                D_8009B698->w20 = 0;
                D_8009B698->w2e = 0xffff;
                D_8009B698->w28 = 0xffff;
                D_8009B698->w2a = 0xffff;
                o->subState = 1;
                o->step = 0;
                if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
                    (*(u8 *)&D_8009C618) = 0;
                    o->subState = 2;
                    o->step = 0;
                }
            }
        } else {
            if (D_8009BCF8 == 3 && (D_1F8001FC & (*(u16 *)&D_1F8003C6))) {
                (*(u8 *)&D_8009C618) = 0;
                if (((X800F2B98_F1EF8 *)o)->cc == 1) {
                    *(u8 *)&o->unkAC = 0;
                    D_8009B698->b4 = 0;
                    s = o->unkB2;
                    if (s < 0) {
                        s16 t = s;
                        if (!(o->animFrame & 1)) t = -s;
                        o->unkB2 = t;
                    } else {
                        if (o->animFrame & 1) s = -s;
                        o->unkB2 = s;
                    }
                    o->subState = 0x45;
                    o->step = 0;
                    return;
                }
            }
        }
    tail:
        if (o->velY > 0) o->unk9C = 2;
        break;
    }
    if (*(u8 *)&o->unkAC < 2 && (D_8009E454 = func_80059B58(o, 0)) != 0) {
        D_8009B698->b8 = 0;
        D_8009B698->w20 = 0;
        *(u8 *)&o->unkAC = 0;
        o->unkA7 = 0;
        o->unk9C = 0;
        o->unkB2 = 0;
        func_800EEFEC(o, D_8009E454 == 1);
    }
    func_800EE26C();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F2940);
extern void func_800EA16C(s32, s16, s32, s32);

void func_800F2940(GameObject *o)
{
    extern char *D_8009B698;
    playSFXWithVolume(0x1c, 0x7f);
    D_8009B698[8] = 0;
    o->subState = 3;
    o->step = 1;
    o->unkA7 = 0;
    *(char *)&o->unkAC = 0;
    o->unk9C = 0;
    o->unk8C = D_80114638[o->unkB0];
    if (o->unkBE & 0x20) {
        playSFX(0x3e);
        func_800EA16C(o->h->p.whole, o->y.p.whole, o->d->p.whole, 0);
        func_800EA16C(o->h->p.whole, o->y.p.whole, o->d->p.whole, 0);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F29FC);
void func_800F29FC(GameObject *o)
{
    s32 v = 0x10;
    o->timer = 10;
    o->unk84 = 0;
    if (o->animFrame & 1)
        v = 0xf0;
    *(u8 *)&o->unkAC = 1;
    o->unk9C = 2;
    o->unk88 = v;
    o->unk8C = 0;
    o->step = 3;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F2A40);
typedef struct {
    u8 b0;
    u8 p1[6];
    s8 b7;
    u8 b8;
    u8 p9[0x20 - 9];
    u16 w20;
    u8 p22[6];
    u16 w28;
    u16 w2a;
    u16 w2c;
    u16 w2e;
} P800F36E0;
extern P800F36E0 *D_8009B698_P800F36E0Ptr asm("D_8009B698");
extern s16 D_8009BCAE_S16 asm("D_8009BCAE");
extern u8 D_8009C61A_U8 asm("D_8009C61A");
extern s16 D_8007D5D0[];
extern char *D_800A53BC;
extern GameObject *allocObjectLayer1(void);
extern void func_8011032C(GameObject *);

#define SETANIM_IF(n) \
    D_8009B698_P800F36E0Ptr->w2c = n; \
    if (D_8009B698_P800F36E0Ptr->w2e != n) { \
        D_8009B698_P800F36E0Ptr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_P800F36E0Ptr->w2e = D_8009B698_P800F36E0Ptr->w2c; \
    }

void func_800F2A40(GameObject *o)
{
    s32 d;
    s8 c;
    s8 b;
    GameObject *q;

    switch (o->step) {
    case 0:
        d = 0x10;
        o->timer = 10;
        o->unk84 = 0;
        if (o->animFrame & 1) d = 0xf0;
        o->unk9D = 1;
        *(u8 *)((u8 *)o + 0xc8) = 0;
        *(u8 *)((u8 *)o + 0xa0) = 0;
        *(u8 *)((u8 *)o + 0xa1) = 0;
        o->unk9E = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unk88 = d;
        o->unk8C = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        D_8009B698_P800F36E0Ptr->b0 = 2;
        D_8009B698_P800F36E0Ptr->w2e = -1;
        D_8009B698_P800F36E0Ptr->w28 = -1;
        D_8009B698_P800F36E0Ptr->w2a = -1;
        switch (o->animFrame) {
        case 0: case 1: case 2: case 3:
            D_800A53BC = D_80010FE0;
            break;
        case 4: case 5:
            D_800A53BC = D_80011000;
            break;
        case 6: case 7:
            D_800A53BC = D_80011020;
            break;
        }
        advanceAnimFrame(o, 0);
        if (*(u8 *)((u8 *)o + 0xac) == 2) {
            D_8009C650 = *(void **)((u8 *)o + 0xe4);
            D_8009B698_P800F36E0Ptr->b8 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            break;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        c = *(s8 *)((u8 *)o + 0xe3);
        if (c < D_8007D5D0[D_8009C61A_U8]) {
            *(s8 *)((u8 *)o + 0xe3) = c + 1;
            q = allocObjectLayer1();
            if (q != 0) {
                q->active = 1;
                q->type = D_8009C61A_U8;
                q->subState = 0;
                q->step = 0;
            }
        }
        if (D_8009B698_P800F36E0Ptr->b8 != 0) {
            o->step = 2;
        } else {
            o->step = 1;
        }
        break;
    case 1:
        if (o->velY >= 0) {
            D_8009B698_P800F36E0Ptr->b8 = 1;
            o->step = 2;
        }
        if (D_8009C9D8[0] & (*(u16 *)&D_1F8003C6)) {
            if (D_8009B698_P800F36E0Ptr->b8 == 0) {
                if (++D_8009B698_P800F36E0Ptr->w20 >= 0xe) {
                    D_8009B698_P800F36E0Ptr->b8 = 1;
                    o->step = 2;
                }
                func_8010E678(o);
            }
        } else {
            D_8009B698_P800F36E0Ptr->b8 = 1;
            if (D_8009B698_P800F36E0Ptr->w20 >= 5) {
                o->step = 2;
            } else {
                D_8009B698_P800F36E0Ptr->w20++;
                func_8010E678(o);
            }
        }
    case 2:
        *(s32 *)o->h += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE_S16 << 8;
        func_8011032C(o);
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        if (*(u8 *)((u8 *)o + 0xac) == 2) {
            D_8009C650 = *(void **)((u8 *)o + 0xe4);
            D_8009B698_P800F36E0Ptr->b8 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            break;
        }
        if (o->velY > 0) {
            d = 0x10;
            o->timer = 10;
            o->unk84 = 0;
            if (o->animFrame & 1) d = 0xf0;
            *(u8 *)((u8 *)o + 0xac) = 1;
            o->unk9C = 2;
            o->unk88 = d;
            o->unk8C = 0;
            o->step = 3;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
        if (clampToCeilingAndProbeSides(o)) {
            d = 0x10;
            o->timer = 10;
            o->unk84 = 0;
            if (o->animFrame & 1) d = 0xf0;
            *(u8 *)((u8 *)o + 0xac) = 1;
            o->unk9C = 2;
            o->unk88 = d;
            o->unk8C = 0;
            o->step = 3;
            o->velY = 0;
            o->velV = 0;
        }
        if (*(u8 *)((u8 *)o + 0xc8) != 0) {
            D_8009B698_P800F36E0Ptr->b8 = 0;
            *(u8 *)((u8 *)o + 0xac) = 0;
            o->unkA7 = 0;
            o->unk9C = 0;
            o->subState = 0x32;
            o->step = 0;
            break;
        }
        if (D_8009B698_P800F36E0Ptr->b0 != 0) break;
        if (*(u8 *)((u8 *)o + 0xc6) != 0) break;
        *(u8 *)((u8 *)o + 0xac) = 0;
        SETANIM_IF(4);
        d = 0x10;
        o->unk9D = 0;
        o->unk9C = 1;
        o->unk84 = 0;
        if (o->animFrame & 1) d = 0xf0;
        o->unk88 = d;
        o->unk8C = 0;
        o->subState = 2;
        o->step = 2;
        break;
    case 3:
        *(s32 *)o->h += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE_S16 << 8;
        func_8011032C(o);
        o->unk8C = 0;
        D_8009B698_P800F36E0Ptr->b8 = 1;
        if (*(u8 *)((u8 *)o + 0xc9) != 0) {
            tickAnimation(o);
            *(s32 *)o->h += D_8009BCAC << 7;
            o->y.raw += D_8009BCAE_S16 << 7;
            func_8011068C(o);
            o->h->raw += o->velX << 8;
            if (--o->timer <= 0) {
                o->timer = 0;
                func_8011070C(o);
                applyObjectAltSpeedVertical(o);
            }
        } else {
            func_8010DE48(o);
            o->h->raw += o->velX << 8;
            func_8010E444(o);
            applyObjectAltSpeedVertical(o);
        }
        if (*(u8 *)((u8 *)o + 0xac) == 2) {
            D_8009C650 = *(void **)((u8 *)o + 0xe4);
            D_8009B698_P800F36E0Ptr->b8 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            break;
        }
        if (*(u8 *)((u8 *)o + 0xc8) != 0) {
            D_8009B698_P800F36E0Ptr->b8 = 0;
            *(u8 *)((u8 *)o + 0xac) = 0;
            o->unkA7 = 0;
            o->unk9C = 0;
            o->subState = 0x32;
            o->step = 0;
            break;
        }
        if (o->touchFlag == 1 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0) != 0) {
            playSFXWithVolume(0x1c, 0x7f);
            D_8009B698_P800F36E0Ptr->b8 = 0;
            o->subState = 3;
            o->step = 1;
            o->unkA7 = 0;
            *(u8 *)((u8 *)o + 0xac) = 0;
            o->unk9C = 0;
            o->unk8C = D_80114638[o->unkB0];
            if (o->unkBE & 0x20) {
                playSFX(0x3e);
                func_800EA16C(o->h->p.whole, o->y.p.whole, o->d->p.whole, 0);
                func_800EA16C(o->h->p.whole, o->y.p.whole, o->d->p.whole, 0);
            }
            break;
        }
        if (D_8009B698_P800F36E0Ptr->b0 != 0) break;
        if (*(u8 *)((u8 *)o + 0xc6) != 0) break;
        SETANIM_IF(4);
        d = 0x10;
        b = D_8009B698_P800F36E0Ptr->b7;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xac) = 1;
        o->unk84 = 0;
        o->animFrame = b;
        o->unk9C = 2;
        if (o->animFrame & 1) d = 0xf0;
        o->unk88 = d;
        o->unk8C = 0;
        o->subState = 2;
        o->step = 3;
        break;
    }
}
#undef SETANIM_IF

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F324C);
void func_800F324C(GameObject *o)
{
    extern u8 *D_8009B698;
    D_8009B698[8] = 1;
    D_8009B698[7] = o->animFrame;
    o->unk9C = 2;
    o->timer = 10;
    o->subState = 4;
    o->velY = 0;
    *(u8 *)&o->unkAC = 1;
    o->step = 3;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F329C);
typedef struct {
    GameObject t;
    u8 c0[3];
    u8 c3;
    u8 c4[2];
    u8 c6;
    u8 c7;
    u8 c8;
    u8 c9[0xe4 - 0xc9];
    s32 e4;
} P800F3F3C_F329C;

typedef struct {
    u8 b0;
    u8 p1[6];
    u8 b7;
    u8 b8;
    u8 p9[0x20 - 9];
    u16 w20;
    u8 p22[0x2c - 0x22];
    u16 w2c;
    u16 w2e;
} Q800F3F3C_F329C;

void func_800F329C(P800F3F3C_F329C *o)
{
    extern Q800F3F3C_F329C *D_8009B698;
    switch (o->t.step) {
    case 0:
        o->t.unk9E = 0;
        o->t.touchFlag = 0;
        o->t.unk9C = 1;
        *(u8 *)&o->t.unkA0 = 0;
        o->t.unk9E = 0;
        *(u8 *)&o->t.unkAA = 0;
        o->c3 = 0;
        o->t.unk8C = 0;
        o->t.unkB0 = 0;
        o->t.unkB6 = 0;
        o->t.velX = 0;
        D_8009B698->w20 = 0;
        D_8009B698->b8 = 0;
        func_8010E678(o);
        o->t.y.p.whole -= 4;
        playSFXWithNote(2, 4);
        o->t.step = 1;
    case 1:
        if (o->t.velY >= 0) {
            D_8009B698->b8 = 1;
            o->t.step = 2;
        }
        if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C6) {
            if (D_8009B698->b8 != 0) goto common;
            if (++D_8009B698->w20 >= 0xe) {
                D_8009B698->b8 = 1;
                o->t.step = 2;
            }
        } else {
            D_8009B698->b8 = 1;
            if (D_8009B698->w20 >= 5) {
                o->t.step = 2;
                goto common;
            }
            D_8009B698->w20++;
        }
        func_8010E678(o);
    case 2:
    common:
        o->t.h->raw += D_8009BCAC << 8;
        o->t.y.raw += D_8009BCAE[0] << 8;
        func_8010E750(o);
        func_8010DE48(o);
        o->t.h->raw += o->t.velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        if (*(u8 *)&o->t.unkAC == 2) {
            D_8009C650 = o->e4;
            D_8009B698->b8 = 0;
            o->t.unkA5 = 0;
            o->t.subState = 0xe;
            o->t.step = 0;
            break;
        }
        probeCollisionAtDepthA(o, o->t.h->p.whole, (s16)(o->t.y.p.whole + 16));
        if (clampToCeilingAndProbeSides(o)) {
            D_8009B698->b8 = 1;
            D_8009B698->b7 = o->t.animFrame;
            o->t.unk9C = 2;
            o->t.timer = 10;
            o->t.subState = 4;
            o->t.velY = 0;
            *(u8 *)&o->t.unkAC = 1;
            o->t.step = 3;
            o->t.velY = 0;
            o->t.velV = 0;
        }
        if (o->t.velY > 0) {
            D_8009B698->b8 = 1;
            D_8009B698->b7 = o->t.animFrame;
            o->t.unk9C = 2;
            o->t.timer = 10;
            o->t.subState = 4;
            o->t.velY = 0;
            *(u8 *)&o->t.unkAC = 1;
            o->t.step = 3;
        } else if (D_8009B698->b0 == 0 && o->c6 == 0) {
            o->t.animFrame = (s8)D_8009B698->b7;
            D_8009B698->w2c = 4;
            if (D_8009B698->w2e != 4) {
                D_8009B698->w2c = 4;
                func_800EEF64(o);
                advanceAnimFrame(o, 0);
                D_8009B698->w2e = D_8009B698->w2c;
            }
            o->t.unk9D = 0;
            o->t.timer = 0;
            o->t.unk84 = 0;
            o->t.unk88 = (o->t.animFrame & 1) ? 0xf0 : 0x10;
            o->t.unk8C = 0;
            o->t.subState = 2;
        }
        if (o->c8) {
            D_8009B698->b8 = 0;
            *(u8 *)&o->t.unkAC = 0;
            o->t.unkA7 = 0;
            o->t.unk9C = 0;
            o->t.subState = 0x32;
            o->t.step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F36AC);
extern u8 D_80114638[];
extern void playSFXWithVolume(s32 a, s32 b);

void func_800F36AC(GameObject *o)
{
    playSFXWithVolume(0x1c, 0x7f);
    o->unk9C = 0;
    o->unkA7 = 0;
    *(char *)&o->unkAC = 0;
    o->unk9D = 0;
    o->unk8C = D_80114638[o->unkB0];
    if (o->unkBE & 0x20) {
        o->subState = 0x1f;
        o->step = 1;
    } else {
        o->subState = 1;
        o->step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F3730);
typedef struct { char p[7]; s8 b7; } U_F3730;

void func_800F3730(GameObject *o)
{
    extern U_F3730 *D_8009B698;
    switch (D_8009B698->b7) {
    case 0:
    case 2:
        o->h->p.whole += 0x10;
        o->y.p.whole += 4;
        break;
    case 1:
    case 3:
        o->h->p.whole -= 0x10;
        o->y.p.whole += 4;
        break;
    case 4:
        o->h->p.whole -= 0xc;
        o->y.p.whole -= 0xc;
        break;
    case 5:
        o->h->p.whole -= 0xc;
        o->y.p.whole -= 0xc;
        break;
    case 6:
    case 7:
        o->y.p.whole -= 0x10;
        break;
    }
    o->touchFlag = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F3810);
typedef struct {
    u8 b0;
    u8 p1[6];
    s8 b7;
    u8 b8;
    u8 p9[0x28 - 9];
    u16 w28;
    u16 w2a;
    u16 w2c;
    u16 w2e;
} P800F44B0;
extern P800F44B0 *D_8009B698_P800F44B0Ptr asm("D_8009B698");

#define YADJ() \
    if (*(u8 *)((u8 *)o + 0xad) == 0) { \
        if (o->subtype) { \
            if ((u16)(o->unkB0 + 5) >= 0xb) o->y.raw += 0x50000; \
            else o->y.raw += 0x30000; \
        } else { \
            if ((u16)(o->unkB0 + 5) >= 0xb) o->y.raw += 0xc0000; \
            else o->y.raw += 0x80000; \
        } \
    }

#define DROP() \
    switch (D_8009B698_P800F44B0Ptr->b7) { \
    case 0: case 2: \
        o->h->p.whole += 0x10; \
        o->y.p.whole += 4; \
        break; \
    case 1: case 3: \
        o->h->p.whole -= 0x10; \
        o->y.p.whole += 4; \
        break; \
    case 4: \
        o->h->p.whole -= 0xc; \
        o->y.p.whole -= 0xc; \
        break; \
    case 5: \
        o->h->p.whole -= 0xc; \
        o->y.p.whole -= 0xc; \
        break; \
    case 6: case 7: \
        o->y.p.whole -= 0x10; \
        break; \
    } \
    o->touchFlag = 0; \
    D_8009B698_P800F44B0Ptr->b8 = 0; \
    *(u8 *)((u8 *)o + 0xac) = 0; \
    o->unkA7 = 0; \
    o->unk9C = 0; \
    o->subState = 0x32; \
    o->step = 0;

#define LAND() \
    YADJ(); \
    playSFXWithVolume(0x1c, 0x7f); \
    o->unk9C = 0; \
    o->unkA7 = 0; \
    *(u8 *)((u8 *)o + 0xac) = 0; \
    o->unk9D = 0; \
    o->unk8C = D_80114638[o->unkB0]; \
    if (o->unkBE & 0x20) { \
        o->subState = 0x1f; \
        o->step = 1; \
    } else { \
        o->subState = 1; \
        o->step = 0; \
    }

void func_800F3810(GameObject *o)
{
    volatile u16 *k;
    u16 f;
    s32 d;
    s8 c;
    GameObject *q;
    u8 b;
    s16 w;
    s16 x;

    if (o->unk9D == 0) {
        D_8009B698_P800F44B0Ptr->b7 = o->animFrame;
        f = o->animFrame & 1;
        o->animFrame = f;
        k = &D_8009C9D8;
        if (*k & 0x10) {
            if (*k & 0x80) o->animFrame = 5;
            else if (*k & 0x20) o->animFrame = 4;
            else if (f) o->animFrame = 7;
            else o->animFrame = 6;
        } else {
            if (*k & 0x80) o->animFrame = 3;
            else if (*k & 0x20) o->animFrame = 2;
            else if (f) o->animFrame = 3;
            else o->animFrame = 2;
        }
    }
    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->unk9D = 1;
        *(u8 *)((u8 *)o + 0xc8) = 0;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650 = D_800A547C;
            *(u8 *)((u8 *)D_800A547C + 4) = 2;
            *(u8 *)((u8 *)D_8009C650 + 5) = 2;
            *(u8 *)((u8 *)D_8009C650 + 6) = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        *(u8 *)((u8 *)o + 0xc3) = 0;
        o->unk9E = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        *(u8 *)((u8 *)D_8009B698_P800F44B0Ptr + 0) = 2;
        *(u8 *)((u8 *)D_8009B698_P800F44B0Ptr + 7) = o->animFrame;
        D_8009B698_P800F44B0Ptr->w2e = -1;
        D_8009B698_P800F44B0Ptr->w28 = -1;
        D_8009B698_P800F44B0Ptr->w2a = -1;
        switch (o->animFrame) {
        case 0: case 1: case 2: case 3:
            D_800A53BC = D_80010FE0;
            break;
        case 4: case 5:
            D_800A53BC = D_80011000;
            break;
        case 6: case 7:
            D_800A53BC = D_80011020;
            break;
        }
        advanceAnimFrame(o, 0);
        o->step = 1;
        c = *(s8 *)((u8 *)o + 0xe3);
        if (c < D_8007D5D0[D_8009C61A_U8]) {
            *(s8 *)((u8 *)o + 0xe3) = c + 1;
            q = allocObjectLayer1();
            if (q != 0) {
                q->active = 1;
                b = D_8009C61A_U8;
                q->subState = 0;
                q->step = 0;
                q->type = b;
            }
        }
        break;
    case 1:
        w = o->unkB0;
        x = w;
        if (w < 0) { x <<= 2; x += 0x100; o->unkB6 = x & 0xff; }
        else if (w > 0) { x <<= 2; o->unkB6 = x & 0xff; }
        else o->unkB6 = 0;
        func_8011032C(o);
        setObjectSpeedPolar2(o, o->unkB6, o->unkB2);
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        applyObjectSpeedXY(o);
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        if (D_8009B698_P800F44B0Ptr->b0 == 0 && *(u8 *)((u8 *)o + 0xc6) == 0) {
            func_800EEDE0(o);
            o->unk9D = 0;
            if (o->unkBE & 0x20) {
                o->subState = 0x1f;
                o->step = 1;
            } else {
                o->step = 2;
            }
        }
        if (*(u8 *)((u8 *)o + 0xac) == 2) {
            D_8009C650 = *(void **)((u8 *)o + 0xe4);
            D_8009B698_P800F44B0Ptr->b8 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            break;
        }
        if (o->unk9C) {
            d = 0x10;
            o->timer = 10;
            o->unk84 = 0;
            if (o->animFrame & 1) d = 0xf0;
            o->subState = 4;
            o->unk88 = d;
            o->unk8C = 0;
            o->step = 1;
            o->unk9C = 0;
        }
        if (*(u16 *)0x1F8001FC & *(u16 *)0x1F8003C6) {
            (*(u8 *)&D_8009C618) = 0;
            o->unk9C = 1;
            if (D_8009BCEC & 0x40) {
                if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4) {
                    o->unkA7 = 1;
                }
            }
            o->subState = 10;
            o->step = 0;
        }
        if (*(u8 *)((u8 *)o + 0xc8)) {
            DROP();
            break;
        }
        YADJ();
        break;
    case 2:
        func_8011032C(o);
        func_8010E444(o);
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        applyObjectSpeedXY(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (*(u8 *)((u8 *)o + 0xc8)) {
            DROP();
            break;
        }
        if (*(u8 *)((u8 *)o + 0xac) == 2) {
            D_8009C650 = *(void **)((u8 *)o + 0xe4);
            o->unkA7 = 0;
            D_8009B698_P800F44B0Ptr->b8 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            break;
        }
        if (o->touchFlag == 1) {
            LAND();
        } else if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            LAND();
        }
        break;
    }
}
#undef YADJ
#undef DROP
#undef LAND

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F41C8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F41FC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F4230);
typedef struct G_F4230 { char p0[1]; u8 b1; s16 w2; char p1[4]; u8 b8; char p2[5]; s16 we; } G_F4230;
typedef struct H_F4230 { char p0[2]; s16 w2; } H_F4230;
typedef struct O_F4230 {
    char p0[0x16]; s16 y;
    char p1[0x2e - 0x18]; u16 af;
    char p2[0x30 - 0x30]; s32 d30; s32 d34;
    char p3[0x40 - 0x38]; H_F4230 *h;
    char p4[0x84 - 0x44]; s32 d84; s32 d88; s32 d8c;
} O_F4230;
extern G_F4230 *D_8009B698_G_F4230PtrArr[] asm("D_8009B698");
extern s32 fixedMulSin(s32, s32);

void func_800F4230(O_F4230 *o, s16 a, s32 b)
{
    extern G_F4230 *D_8009B698;
    s32 d;
    s32 v;
    s32 s;
    s32 t;
    G_F4230 *g;
    if (o->af & 1) {
        s = 0x1bf;
        s -= b;
        s &= 0xff;
        o->h->w2 = fixedMulCos(s, D_8009B698->b1) + o->d30;
        v = fixedMulSin(s, D_8009B698->b1);
        o->d84 = 0;
        o->d8c = 0x100 - (a << 2);
        v += o->d34;
    } else {
        s = b + 0xc0;
        s &= 0xff;
        o->h->w2 = fixedMulCos(s, D_8009B698->b1) + o->d30;
        v = fixedMulSin(s, D_8009B698->b1);
        o->d84 = 0;
        o->d8c = a << 2;
        v += o->d34;
    }
    o->y = v;
    g = D_8009B698_G_F4230PtrArr[0];
    d = g->we;
    if (g->b8) {
        t = g->w2;
        g->we = d - t;
    } else {
        t = g->w2;
        g->we = d + t;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F4374);
typedef struct { char p[0xa]; char b0a; char b0b; char b0c; } S_F4374;

void func_800F4374(s16 a)
{
    extern S_F4374 *D_8009B698;
    func_80028A74(0, 0, 0xff, 2);
    playSFXWithNote(3, a);
    D_8009B698->b0a = (*(S_F4374 **)&D_8009E454)->b0c;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F43D8);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F5A44);
typedef struct { char pad[8]; u8 b8; char pad2[0x2c - 9]; s16 cur; u16 prev; } Cam_F5A44;

void func_800F5A44(GameObject *o)
{
    extern Cam_F5A44 *D_8009B698;
    Cam_F5A44 *p = D_8009B698;
    p->cur = 4;
    if (p->prev != 4) {
        p->cur = 4;
        func_800EEF64(o);
        advanceAnimFrame(o, 1);
        D_8009B698->prev = D_8009B698->cur;
    }
    *(u8 *)&o->unkAC = 1;
    o->unk9C = 2;
    o->timer = 10;
    D_8009B698->b8 = 1;
    o->velY = 0;
    o->velV = 0;
    o->unk84 = 0;
    o->unk88 = (o->animFrame & 1) ? 0xf0 : 0x10;
    o->unk8C = (o->animFrame & 1) ? 0x18 : 0xe8;
    o->subState = 2;
    o->step = 3;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F5B1C);
extern s16 D_80114710[];
extern void applyObjectAltSpeedXY(GameObject *);

static __inline__ void setanim_F5B1C(GameObject *o, u16 anim, s32 j)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, j);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
}

static __inline__ void land_F5B1C(GameObject *o)
{
    extern GameObject *D_8009B698;
    s32 v, w;
    setanim_F5B1C(o, 4, 1);
    *(u8 *)((u8 *)o + 0xac) = 1;
    o->unk9C = 2;
    o->timer = 10;
    *(u8 *)((u8 *)D_8009B698 + 8) = 1;
    v = 0x10;
    o->velY = 0;
    o->velV = 0;
    o->unk84 = 0;
    if (o->animFrame & 1) v = 0xf0;
    w = 0xe8;
    o->unk88 = v;
    if (o->animFrame & 1) w = 0x18;
    o->unk8C = w;
    o->subState = 2;
    o->step = 3;
}

void func_800F5B1C(GameObject *o)
{
    extern void func_8010E5A4(GameObject *);
    extern GameObject *D_8009B698;
    s32 t;
    GameObject *p;
    s16 k;
    s16 v;
    switch (o->step) {
    case 0:
        o->unk9E = 0;
        o->touchFlag = 0;
        o->unk9C = 1;
        *(u8 *)((u8 *)o + 0xac) = 0;
        p = D_8009B698;
        t = 1;
        o->unk8C = 0;
        o->unkB0 = 0;
        if (o->unkB2 > 8) t = 2;
        *(u8 *)((u8 *)p + 5) = t;
        k = *(u8 *)((u8 *)D_8009B698 + 0xb) * 7;
        if (o->unkB2 < 4) {
            if (o->animFrame & 1) {
                o->velX = -D_80114710[k + 4] / 3;
            } else {
                o->velX = D_80114710[k + 4] / 3;
            }
            o->velY = D_80114710[k + 10] >> 1;
        } else {
            v = D_80114710[k + o->unkB2];
            if (o->animFrame & 1) v = -v;
            o->velX = v;
            o->velY = D_80114710[k + 10];
        }
        D_8009B698->timer = 0xe;
        o->unkB2 = 0;
        o->unkB6 = 0;
        setanim_F5B1C(o, 8, 0);
        playSFXWithNote(2, 4);
        o->step++;
    case 1:
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        func_8010E5A4(o);
        applyObjectAltSpeedXY(o);
        tickAnimation(o);
        if (clampToCeilingAndProbeSides(o)) {
            land_F5B1C(o);
        }
        if (o->velY > 0) {
            land_F5B1C(o);
        }
        break;
    }
    D_8009E454 = func_80059B58(o, 0);
    if (o->unk9E != 0) {
        *(u8 *)((u8 *)D_8009B698 + 8) = 0;
        D_8009B698->timer = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        o->unk9C = 0;
        o->velX = 0;
        o->velY = 0;
        o->unkB2 = 0;
        func_800EEFEC(o, D_8009E454 == (GameObject *)1);
    }
    if (*(u8 *)((u8 *)o + 0xac) != 2 && o->subState == 9 && o->unk9E == 0) {
        func_8010D678(o, 1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F5F94);
void func_800F5F94(GameObject *o)
{
    extern u8 *D_8009B698;
    s32 a;
    s16 s;
    s32 s1;
    u16 u;
    Fix16 *h;
    if (((u16 *)&D_8009C9D8)[0] & (*(u16 *)&D_1F8003C6)) {
        (*(u8 *)&D_8009C618) = 0;
        D_8009B698[9] = 0;
        o->subState = 0xb;
        o->step = 0;
        D_8009E454[0x69] = 0;
    }
    if (((u16 *)&D_8009C9D8)[0] & 0x10) {
        D_8009B698[9] = 0;
        o->subState = 0xb;
        o->step = 0;
        D_8009E454[0x69] = 0;
    }
    if (((u16 *)&D_8009C9D8)[0] & 0x40) {
        D_8009B698[9] = 0;
        *(u8 *)&o->unkAC = 1;
        u = o->animFrame;
        h = o->h;
        o->unk9E = 0;
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        o->unk30 = 0;
        o->unk34 = 0;
        o->velX = 0;
        o->velY = 0;
        s1 = h->p.whole;
        if (u & 1)
            s = s1 + 0xe;
        else
            s = s1 - 0xe;
        h->p.whole = s;
        a = 0x10;
        o->timer = 10;
        o->unk84 = 0;
        if (o->animFrame & 1)
            a = 0xf0;
        o->subState = 2;
        o->step = 3;
        o->unk88 = a;
        o->unk8C = 0;
        D_8009E454[0x69] = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F60E0);
void func_800F60E0(GameObject *o)
{
    extern u8 *D_8009B698;
    s32 v;
    s32 y;
    s32 c;
    D_8009B698[9] = 0;
    v = 0x10;
    *(u8 *)&o->unkAC = 1;
    o->unk9E = 0;
    o->unkB2 = 0;
    o->velH = 0;
    o->velV = 0;
    o->unk30 = 0;
    o->unk34 = 0;
    o->velX = 0;
    o->velY = 0;
    o->timer = 10;
    o->unk84 = 0;
    if (o->animFrame & 1) {
        v = 0xf0;
    }
    o->unk88 = v;
    *(volatile s32 *)&o->unk8C = D_80114638[o->unkB0];
    c = o->animFrame & 1;

    o = (GameObject *)((volatile GameObject *)o)->h;
    y = ((Fix16 *)o)->p.whole;
    if (c) {
        y += 14;
    } else {
        y -= 14;
    }
    ((Fix16 *)o)->p.whole = y;
    D_8009E454[0x69] = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F6188);
extern s32 func_80121FF4(void);
extern s32 func_8011BD20(void);

s16 func_800F6188(char *o)
{
    char *e = D_8009E454;
    s32 r;
    *(s32 *)(o + 0x30) = *(s16 *)(*(char **)(e + 0x40) + 2);
    *(s32 *)(o + 0x34) = *(s16 *)(e + 0x16);
    r = 0;
    switch (*(u8 *)(e + 2)) {
    case 0xe:
        *(s16 *)(o + 0xb8) = *(s32 *)(e + 0x30) - *(u16 *)(*(char **)(e + 0x40) + 2);
        *(s16 *)(o + 0xba) = *(s32 *)(e + 0x34) - *(u16 *)(e + 0x16);
        break;
    case 0x14:
        r = func_80121FF4();
        break;
    case 0x34:
        r = func_8011BD20();
        break;
    case 0x1f:
        if (*(u8 *)(e + 0x6a) != 0) {
            if ((*(u16 *)(e + 0x2e) & 1) == (*(u16 *)(o + 0x2e) & 1)) {
                *(u8 *)(o + 0x69) = 1;
                r = 1;
            }
        }
        break;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F6298);
void func_800F6298(GameObject *o, s32 p)
{
    extern s32 fixedMulSin2(s32, s32);
    extern u8 *D_8009B698;
    s32 s;
    s32 ang;
    s16 r;
    if (o->animFrame & 1) {
        ang = 0x1bf; ang -= p;
        s = fixedMulCos2(ang & 0xff, D_8009B698[1]);
        o->h->p.whole = s + (o->unkB8 + o->unk30);
        s = fixedMulSin2(ang & 0xff, D_8009B698[1]);
        o->unk84 = 0;
        o->unk8C = 0x100 - (u8)p;
        r = s + (o->unkBA + o->unk34);
    } else {
        ang = p + 0xc0;
        s = fixedMulCos2(ang & 0xff, D_8009B698[1]);
        o->h->p.whole = s + (o->unkB8 + o->unk30);
        s = fixedMulSin2(ang & 0xff, D_8009B698[1]);
        o->unk84 = 0;
        o->unk8C = (u8)p;
        r = s + (o->unkBA + o->unk34);
    }
    o->y.p.whole = r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F63BC);
typedef struct {
    u8 b0;
    u8 b1;
    s16 w2;
    char p4[4];
    u8 b8;
    u8 b9;
    char pa[2];
    s16 wc;
    s16 we;
    char p10[0x28 - 0x10];
    u16 w28, w2a;
    u16 w2c, w2e;
} PL705C;
extern PL705C *D_8009B698_PL705CPtr asm("D_8009B698");
extern PL705C *D_8009B698_PL705CPtrArr[] asm("D_8009B698");
extern GameObject *D_8009E454_GameObjectPtr asm("D_8009E454");
extern char D_80011268[];
extern void func_800EE50C(GameObject *);

static __inline__ void setanim_F63BC(GameObject *o, u16 anim)
{
    PL705C *p = D_8009B698_PL705CPtr;
    p->w2c = anim;
    if (p->w2e != anim) {
        p->w2c = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698_PL705CPtr->w2e = D_8009B698_PL705CPtr->w2c;
    }
}

static __inline__ void rot_F63BC(GameObject *o)
{
    PL705C *p = D_8009B698_PL705CPtr;
    o->unkB6 += p->we;
    if ((u16)o->unkB6 < 0x800) p->b8 = 1;
    if ((u32)((u16)o->unkB6 - 0x800) < 0x800) D_8009B698_PL705CPtr->b8 = 0;
    if ((u16)(o->unkB6 + 0x7ff) < 0x800) D_8009B698_PL705CPtr->b8 = 0;
    if ((u16)(o->unkB6 + 0xfff) < 0x800) D_8009B698_PL705CPtr->b8 = 1;
}

static __inline__ void swing_F63BC(GameObject *o, s32 p)
{
    s32 s;
    s32 ang;
    s16 r;
    s32 c = p & 0xff;
    if (o->animFrame & 1) {
        ang = 0x1bf; ang -= p;
        s = fixedMulCos2(ang & 0xff, D_8009B698_PL705CPtr->b1);
        o->h->p.whole = s + (o->unkB8 + o->unk30);
        s = fixedMulSin2(ang & 0xff, D_8009B698_PL705CPtr->b1);
        o->unk84 = 0;
        o->unk8C = 0x100 - c;
        r = s + (o->unkBA + o->unk34);
    } else {
        ang = p + 0xc0;
        s = fixedMulCos2(ang & 0xff, D_8009B698_PL705CPtr->b1);
        o->h->p.whole = s + (o->unkB8 + o->unk30);
        s = fixedMulSin2(ang & 0xff, D_8009B698_PL705CPtr->b1);
        o->unk84 = 0;
        o->unk8C = c;
        r = s + (o->unkBA + o->unk34);
    }
    o->y.p.whole = r;
}

#define ADDWE() { \
    PL705C *p = D_8009B698_PL705CPtrArr[0]; \
    s32 w = p->we; s32 v; \
    if (p->b8) v = w - p->w2; else v = w + p->w2; p->we = v; }

#define CATCH() { \
    s32 d = 0x10; \
    D_8009B698_PL705CPtr->b9 = 0; \
    *(u8 *)((u8 *)o + 0xac) = 1; \
    o->unk9E = 0; \
    o->unkB2 = 0; \
    o->velH = 0; \
    o->velV = 0; \
    o->unk30 = 0; \
    o->unk34 = 0; \
    o->velX = 0; \
    o->velY = 0; \
    o->timer = 10; \
    o->unk84 = 0; \
    if (o->animFrame & 1) d = 0xf0; \
    o->unk88 = d; \
    o->unk8C = D_80114638[o->unkB0]; \
    { Fix16 *h = o->h; s32 pv = h->p.whole; s16 x; \
      if (o->animFrame & 1) x = pv + 14; else x = pv - 14; \
      h->p.whole = x; } \
    D_8009E454_GameObjectPtr->touchFlag = 0; \
    if (r) { o->subState = 2; o->step = 3; o->unk7 = 0; } \
    else { o->subState = 0; o->step = 0; o->unk7 = 0; } }

void func_800F63BC(GameObject *o)
{
    extern u8 D_80114578[][2];
    PL705C *q;
    s16 r;
    s32 t;
    s32 t1;
    char pad[4];

    switch (o->step) {
    case 0:
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650_U8Ptr = D_800A547C;
            D_8009C650_U8Ptr[4] = 2;
            D_8009C650_U8Ptr[5] = 2;
            D_8009C650_U8Ptr[6] = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        D_8009B698_PL705CPtr->b0 = 0;
        D_8009E454_GameObjectPtr->touchFlag = 1;
        {
            PL705C *q = D_8009B698_PL705CPtr;
            o->unkB6 = -0x420;
            q->w2 = 0x10;
            q->we = 0;
            o->unkB2 = 2;
            q->b8 = 0;
        }
        D_8009B698_PL705CPtr->b9 = 0;
        D_8009B698_PL705CPtr->wc = 0;
        D_8009B698_PL705CPtr->w28 = 0xffff;
        D_8009B698_PL705CPtr->w2a = 0xffff;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unk30 = D_8009E454_GameObjectPtr->h->p.whole;
        o->unk34 = D_8009E454_GameObjectPtr->y.p.whole;
        *(u8 *)((u8 *)o + 0xac) = 0;
        if (o->animFrame & 1) {
            o->unk8C = 0x100;
            o->unkB8 -= 6;
        } else {
            o->unk8C = 0;
            o->unkB8 += 6;
        }
        o->unkBA -= 0x10;
        playSFXWithVolume(4, 0x7f);
        o->step++;
    case 1:
        rot_F63BC(o);
        if (o->unkB6 == 0) {
            q = D_8009B698_PL705CPtr;
            if (q->we > 0) {
                u8 *b = D_80114578[--o->unkB2];
                q->we = b[0];
                q->w2 = b[1];
            }
        }
        t1 = (s16)o->unkB6 >> 4;
        D_8009B698_PL705CPtr->w2e = 0xffff;
        o->anim = D_80011268;
        advanceAnimFrame(o, 0);
        D_8009B698_PL705CPtr->b1 = 0x18;
        r = func_800F6188(o);
        func_800F6298(o, t1);
        ADDWE();
        if (o->unkB2 < 2) o->step++;
        if (o->touchFlag) CATCH();
        break;
    case 2:
        rot_F63BC(o);
        if (o->unkB6 == 0) {
            q = D_8009B698_PL705CPtr;
            if (q->we > 0) {
                u8 *b = D_80114578[--o->unkB2];
                q->we = b[0];
                q->w2 = b[1];
            } else {
                q->b9 = 1;
            }
        }
        setanim_F63BC(o, 6);
        tickAnimation(o);
        t = (s16)o->unkB6 >> 4;
        r = func_800F6188(o);
        func_800F6298(o, t);
        swing_F63BC(o, t);
        ADDWE();
        if (o->unkB2 == 0) {
            o->unk8C = 0;
            o->step++;
        }
        if (D_8009B698_PL705CPtr->b9 == 0) break;
        if (o->touchFlag || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) CATCH();
        func_800F5F94(o);
        break;
    case 3:
        r = func_800F6188(o);
        o->h->p.whole = fixedMulCos2(0xc0, D_8009B698_PL705CPtr->b1) + (o->unkB8 + o->unk30);
        o->y.p.whole = fixedMulSin2(0xc0, D_8009B698_PL705CPtr->b1) + (o->unkBA + o->unk34);
        tickAnimation(o);
        if (o->touchFlag) CATCH();
        func_800F5F94(o);
        break;
    }
    func_800EE50C(o);
}
#undef ADDWE
#undef CATCH

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F6D98);
extern char D_80010DB0[];
void func_800F6D98(char *o)
{
    playSFXWithVolume(0x1c, 0x7f);
    *(u8 *)((u8 *)o + 0x9c) = 0;
    *(u8 *)((u8 *)o + 0xaa) = 0;
    *(void **)((u8 *)o + 0x24) = D_80010DB0;
    advanceAnimFrame(o, 4);
    *(s32 *)((u8 *)o + 0x88) = 0;
    *(s32 *)((u8 *)o + 0x8c) = D_80114638[*(s16 *)((u8 *)o + 0xb0)];
    (*(u8 *)((u8 *)o + 6))++;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F6E0C);
static __inline__ void setanim_F6E0C(GameObject *o, u16 anim)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
}

void func_800F6E0C(GameObject *o)
{
    extern GameObject *D_8009B698;
    extern char D_800108A8[];
    u8 b;
    s16 v;
    s32 k;

    switch (o->step) {
    case 0:
        o->unk8C = 0;
        setanim_F6E0C(o, 9);
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkB6 = 0;
        *(s16 *)((char *)D_8009B698 + 2) = 0;
        k = o->unk9E;
        o->unkB2 = 0;
        if (k == 0 || (k >= 3 && k != 11)) {
            Fix16 *h = o->h;
            s32 pv = h->p.whole;
            s16 d;
            if (o->animFrame & 1) d = pv + 8; else d = pv - 8;
            h->p.whole = d;
        }
        {
            s32 hw = o->h->p.whole;
            o->unk34 = o->y.p.whole;
            o->step++;
            o->unk30 = hw;
        }
    case 1:
        tickAnimation(o);
        if (*(u16 *)o->anim == 0x61) {
            if (o->animFrame & 1)
                v = -0x1c0;
            else
                v = 0x1c0;
            o->velY = -0x300;
            o->unk88 = 0x100;
            o->velX = v;
            o->unk9E = 0;
            o->step = 2;
        } else {
            o->h->p.whole = o->unk30;
            o->y.p.whole = ((u16 *)o->anim)[2] + o->unk34;
        }
        break;
    case 2:
        if (o->animFrame & 1) {
            o->unk88 += 0x10;
            if (o->unk88 > 0x170)
                o->unk88 = 0x170;
        } else {
            o->unk88 -= 0x10;
            if (o->unk88 < 0xb0)
                o->unk88 = 0xb0;
        }
        o->unk8C = *(u8 *)((u8 *)o + 0x88);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x80;
        if (o->velY > 0) {
            if (o->animFrame & 1)
                v = -0x100;
            else
                v = 0x100;
            o->unk9C = 2;
            o->velX = v;
            o->unk9E = 0;
            o->step = 3;
        }
        break;
    case 3:
        if (o->animFrame & 1) {
            o->unk88 += 0x20;
            if (o->unk88 <= 0x160) goto skip;
            goto turn;
        } else {
            o->unk88 -= 0x20;
            if (o->unk88 < 0xa0) {
            turn:
                o->anim = D_80010DB0;
                advanceAnimFrame(o, 3);
                o->unk88 = 0x100;
                o->timer = 0xc;
                o->step++;
            }
        }
    skip:
        o->unk8C = *(u8 *)((u8 *)o + 0x88);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x80;
        if (o->touchFlag || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            playSFXWithVolume(0x1c, 0x7f);
            o->unk9C = 0;
            o->anim = D_80010DB0;
            advanceAnimFrame(o, 4);
            o->unk30 = 0;
            o->unk34 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->step = 5;
        }
        break;
    case 4:
        if (o->animFrame & 1) {
            o->unk88 += 0x10;
            if (o->unk88 > 0x130)
                o->unk88 = 0x130;
        } else {
            o->unk88 -= 0x10;
            if (o->unk88 < 0xd0)
                o->unk88 = 0xd0;
        }
        o->unk8C = *(u8 *)((u8 *)o + 0x88);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x80;
        if (o->velY > 0x680)
            o->velY = 0x680;
        if (o->touchFlag || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            playSFXWithVolume(0x1c, 0x7f);
            o->unk9C = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->anim = D_80010DB0;
            advanceAnimFrame(o, 4);
            o->unk88 = 0;
            b = D_80114638[o->unkB0];
            o->step++;
            o->unk8C = b;
        } else if (--o->timer <= 0) {
            s32 d;
            *(u8 *)((u8 *)o + 0xac) = 1;
            o->timer = 10;
            o->unk84 = 0;
            if (o->animFrame & 1)
                d = 0xf0;
            else
                d = 0x10;
            o->subState = 2;
            o->unk88 = d;
            o->unk8C = 0;
            o->step = 3;
        }
        break;
    case 5:
        if (tickAnimation(o)) {
            *(s8 *)&o->unkF = -8;
            *(s16 *)((char *)D_8009B698 + 2) = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->velX = 0;
            o->velY = 0;
            b = D_80114638[o->unkB0];
            o->anim = D_800108A8;
            o->unk8C = b;
            readAnimFrameCount(o);
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F738C);
typedef struct O_F738C { char p0[6]; char st; char p1[0x24 - 7]; s32 anim; char p2[0x88 - 0x28]; s32 a; s32 b; char p3[0x9c - 0x90]; char c; char p4[0xaa - 0x9d]; char d; char p5[0xb0 - 0xab]; s16 idx; } O_F738C;
void func_800F738C(O_F738C *o)
{
    playSFXWithVolume(0x1c, 0x7f);
    o->c = 0;
    o->d = 0;
    o->anim = (s32)D_80010DB0;
    advanceAnimFrame(o, 1);
    o->a = 0;
    {
        s32 v = D_80114638[o->idx];
        o->st = 5;
        o->b = v;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F73FC);
void func_800F73FC(char *o)
{
    u8 b;
    s16 *h;
    s16 d; s32 c; s32 p;
    playSFXWithVolume(0x1c, 0x7f);
    o[0x9c] = 0;
    o[0xaa] = 0;
    *(char **)(o + 0x24) = D_80010DB0;
    advanceAnimFrame(o, 1);
    c = *(u16 *)(o + 0x2e) & 1;
    h = *(s16 **)(o + 0x40);
    p = h[1];
    if (c) d = p - 12; else d = p + 12;
    h[1] = d;
    *(s32 *)(o + 0x88) = 0;
    b = D_80114638[*(s16 *)(o + 0xb0)];
    o[6]++;
    *(u32 *)(o + 0x8c) = b;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F7490);
typedef struct {
    char pad0[2];
    s16 w02;
    char pad4[0x2c - 4];
    u16 w2c;
    u16 w2e;
} G330_F7490;

#define ADJ(a, b) { Fix16 *h = o->h; s32 pv = h->p.whole; s16 d; if (o->animFrame & 1) d = pv + (a); else d = pv + (b); h->p.whole = d; }

void func_800F7490(GameObject *o)
{
    extern G330_F7490 *D_8009B698;
    extern char D_800108A8[];
    u8 b;

    switch (o->step) {
    case 0:
        o->unk8C = 0;
        D_8009B698->w2c = 9;
        o->unkB6 = 0;
        D_8009B698->w02 = 0;
        o->unkB2 = 0;
        ADJ(8, -8);
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole;
        o->step++;
    case 1:
        tickAnimation(o);
        if (*(u16 *)o->anim == 0x87) {
            s16 v;
            if (o->animFrame & 1)
                v = -0x200;
            else
                v = 0x200;
            o->velY = -0x300;
            o->unk88 = 0x100;
            o->velX = v;
            o->unk9E = 0;
            o->step = 2;
        } else {
            o->h->p.whole = o->unk30;
            o->y.p.whole = ((u16 *)o->anim)[2] + o->unk34;
        }
        break;
    case 2:
        if (o->animFrame & 1) {
            o->unk88 += 0x10;
            if (o->unk88 > 0x150)
                o->unk88 = 0x150;
        } else {
            o->unk88 -= 0x10;
            if (o->unk88 < 0xb0)
                o->unk88 = 0xb0;
        }
        o->unk8C = *(u8 *)((u8 *)o + 0x88);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x80;
        if (o->velY > 0) {
            o->unk9C = 2;
            o->unk9E = 0;
            o->step = 3;
        }
        break;
    case 3:
        if (o->animFrame & 1) {
            o->unk88 += 0x20;
            if (o->unk88 > 0x160) {
                o->anim = D_80010DB0;
                advanceAnimFrame(o, 0);
                o->unk88 = 0x100;
                o->step++;
            }
        } else {
            o->unk88 -= 0x20;
            if (o->unk88 < 0xa0) {
                o->anim = D_80010DB0;
                advanceAnimFrame(o, 0);
                o->unk88 = 0x100;
                o->step++;
            }
        }
        o->unk8C = *(u8 *)((u8 *)o + 0x88);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x80;
        if (o->touchFlag || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            playSFXWithVolume(0x1c, 0x7f);
            o->unk9C = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->anim = D_80010DB0;
            advanceAnimFrame(o, 1);
            o->unk88 = 0;
            b = D_80114638[o->unkB0];
            o->step = 5;
            o->unk8C = b;
        }
        break;
    case 4:
        if (o->animFrame & 1) {
            o->unk88 += 0x10;
            if (o->unk88 > 0x120)
                o->unk88 = 0x120;
        } else {
            o->unk88 -= 0x10;
            if (o->unk88 < 0xe0)
                o->unk88 = 0xe0;
        }
        o->unk8C = *(u8 *)((u8 *)o + 0x88);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x80;
        if (o->touchFlag) {
            playSFXWithVolume(0x1c, 0x7f);
            o->unk9C = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->anim = D_80010DB0;
            advanceAnimFrame(o, 1);
            ADJ(-12, 12);
        } else {
            if (!((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0))
                break;
            playSFXWithVolume(0x1c, 0x7f);
            o->unk9C = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->anim = D_80010DB0;
            advanceAnimFrame(o, 1);
            ADJ(-12, 12);
        }
        o->unk88 = 0;
        {
            u8 c = D_80114638[o->unkB0];
            o->step++;
            o->unk8C = c;
        }
        break;
    case 5:
        if (tickAnimation(o)) {
            *(s8 *)&o->unkF = -8;
            D_8009B698->w02 = 0;
            o->unk9E = 0;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->velX = 0;
            o->velY = 0;
            o->animFrame = 0;
            o->timer = 0x46;
            o->unk8C = D_80114638[o->unkB0];
            ADJ(10, -10);
            o->anim = D_800108A8;
            readAnimFrameCount(o);
            o->state = 5;
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}
#undef ADJ

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F79C0);
extern char D_80010E00[];

void func_800F79C0(GameObject *o)
{
    u8 b;
    if (o->subState != 0x49) {
        *((char *)&o->unkA0 + 2) = 1;
    }
    *(char *)&o->unkAC = 0;
    playSFXWithVolume(0x1c, 0x7f);
    *(s8 *)&o->unkF = -8;
    o->anim = D_80010E00;
    advanceAnimFrame(o, 4);
    b = D_80114638[o->unkB0];
    o->step = o->step + 1;
    o->unk8C = b;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F7A48);
typedef struct P_F7A48 { char p0[2]; s16 h02; char p04[4]; u8 b8; char p1[0x20-9]; s16 h20; char p2[0x2c-0x22]; u16 h2c; u16 h2e; } P_F7A48;
typedef struct H_F7A48 { s16 p0; s16 whole; } H_F7A48;
typedef struct O_F7A48 {
    u8 active; char p01[4]; u8 step; u8 state; char p07[0xf-7]; s8 b0f;
    char p10[4]; s32 y; char p18[0x24-0x18]; void *anim; char p28[0x44-0x28]; H_F7A48 *d;
    char p48[0x69-0x48]; u8 b69; char p6a[0x7c-0x6a]; s16 vx; s16 vy; char p80[2]; s16 h82;
    char p84[0x8c-0x84]; s32 d8c; char p90[0x9c-0x90]; u8 b9c; char p9d; u8 b9e; char p9f;
    u8 ba0; char pa1; u8 ba2; char pa3[2]; u8 ba5; char pa6[4]; u8 baa; char pab;
    u8 bac; char pad[3]; s16 hb0; s16 hb2; char pb4[2]; s16 hb6;
    char pb8[0xe0-0xb8]; s16 he0; char pe2[2]; void *de4; char pe8[0xf6-0xe8]; s16 hf6;
} O_F7A48;

void func_800F7A48(O_F7A48 *o)
{
    extern P_F7A48 *D_8009B698;
    switch (o->state) {
    case 0:
        o->ba0 = 0;
        o->active = 4;
        o->b9e = 0;
        o->d8c = 0;
        o->hb6 = 0;
        D_8009B698->h2c = 0x1f;
        if (D_8009B698->h2e != 0x1f) {
            D_8009B698->h2c = 0x1f;
            func_800EEF64(o);
            advanceAnimFrame(o, 0);
            D_8009B698->h2e = D_8009B698->h2c;
        }
        D_8009B698->h02 = 0;
        o->vy = -0x340;
        o->hb2 = 0;
        o->vx = 0;
        if (o->step == 0x49)
            o->vy = -0x580;
        o->hf6 = o->d->whole;
        o->state++;
    case 1:
        tickAnimation(o);
        o->y += o->vy << 8;
        if (o->step == 0x49)
            o->vy += 0x40;
        else
            o->vy += 0x20;
        if (o->step != 0x49 && clampToCeilingAndProbeSides(o) != 0) {
            o->active = 3;
            o->bac = 1;
            o->b9c = 2;
            o->vy = 0;
            o->h82 = 0;
            o->state = 2;
            if (o->step == 0x49) {
                o->ba2 = 0;
                o->b0f = -8;
                if (o->he0 != 0)
                    o->active = 3;
                else
                    o->active = 1;
                o->step = 2;
                o->state = 3;
            }
        }
        if (o->vy > 0) {
            o->active = 3;
            o->bac = 1;
            o->b9c = 2;
            o->state = 2;
        }
        break;
    case 2:
        tickAnimation(o);
        o->y += o->vy << 8;
        o->vy += 0x20;
        if (o->bac == 2) {
            if (o->he0 == 0)
                o->active = 1;
            else
                o->active = 3;
            if (((u8 *)&D_8009BCAA)[0] != 0)
                ((u8 *)&D_8009BCAA)[0] = 0;
            if (D_8009BCA7 != 0)
                D_8009BCA7 = 0;
            D_8009C650 = o->de4;
            o->b0f = -8;
            D_8009B698->b8 = 0;
            D_8009B698->h20 = 0;
            o->ba5 = 0;
            D_8009B698->h02 = 0;
            o->b9e = 0;
            o->ba2 = 0;
            o->vx = 0;
            o->vy = 0;
            o->baa = 0;
            o->step = 0xe;
            o->state = 0;
        } else if (o->b69 == 1 || ((s16 (*)(O_F7A48 *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0) != 0) {
            if (o->step != 0x49)
                o->ba2 = 1;
            o->bac = 0;
            playSFXWithVolume(0x1c, 0x7f);
            o->b0f = -8;
            o->anim = D_80010E00;
            advanceAnimFrame(o, 4);
            o->d8c = D_80114638[o->hb0];
            o->state++;
        } else if (o->step == 0x49 && o->vy > 0x200) {
            o->baa = 0;
            o->ba2 = 0;
            o->b0f = -8;
            if (o->he0 != 0)
                o->active = 3;
            else
                o->active = 1;
            o->step = 2;
            o->state = 3;
        }
        break;
    case 3:
        if (tickAnimation(o) != 0) {
            if (((u8 *)&D_8009BCAA)[0] != 0)
                ((u8 *)&D_8009BCAA)[0] = 0;
            if (D_8009BCA7 != 0)
                D_8009BCA7 = 0;
            o->b0f = -8;
            if (o->he0 != 0)
                o->active = 3;
            else
                o->active = 1;
            o->bac = 0;
            D_8009B698->h02 = 0;
            o->b9e = 0;
            o->baa = 0;
            o->ba2 = 0;
            o->vx = 0;
            o->vy = 0;
            o->d8c = D_80114638[o->hb0];
            o->step = 0;
            o->state = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F7EDC);

void func_800F7EDC(GameObject *o, s32 unused, s32 p3)
{
    extern s32 fixedMulSin2(u8 a, s32 r);
    extern u8 *D_8009B698;
    GameObject *pl = D_8009E454_GameObjectPtr;
    s32 ang;
    s32 s, t;
    u8 *c;
    o->unk30 = pl->h->p.whole + o->unkB8;
    o->unk34 = pl->y.p.whole + o->unkBA;
    if (o->animFrame & 1) {
        ang = (0x1bf - p3) & 0xff;
        o->h->p.whole = ((s32 (*)(u8 a, u8 r))fixedMulCos2)(ang, D_8009B698[1]) + o->unk30;
        s = fixedMulSin2(ang, D_8009B698[1]);
        t = fixedMulSin2((D_8009E454_GameObjectPtr->unk8C >> 4) + 0x70, D_8009E454_GameObjectPtr->hitOffsetX);
        o->unk84 = 0;
        o->unk8C = 0x100 - (u8)p3;
        s += o->unk34;
        o->y.p.whole = t + s;
    } else {
        ang = (p3 + 0xc0) & 0xff;
        o->h->p.whole = ((s32 (*)(u8 a, u8 r))fixedMulCos2)(ang, D_8009B698[1]) + o->unk30;
        s = fixedMulSin2(ang, D_8009B698[1]);
        t = fixedMulSin2((D_8009E454_GameObjectPtr->unk8C >> 4) + 0x10, D_8009E454_GameObjectPtr->hitOffsetX);
        o->unk84 = 0;
        o->unk8C = (u8)p3;
        s += o->unk34;
        o->y.p.whole = t + s;
    }
    c = D_8009B698;
    *(s16 *)(c + 0xe) += c[8] ? -*(s16 *)(c + 2) : *(s16 *)(c + 2);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F808C);
typedef struct {
    u8 b00, b01;
    u16 w02;
    char p04[4];
    u8 b08, b09;
    char p0a[2];
    u16 w0c;
    s16 w0e;
    char p10[0x28 - 0x10];
    u16 w28, w2a, w2c, w2e;
} P;
extern P *D_8009B698_PPtr asm("D_8009B698");
extern u8 D_80114578[];

#define BUTTONS(o) \
    if (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C6)) { \
        D_8009B698_PPtr->b09 = 0; \
        (o)->subState = 0xb; \
        (o)->step = 0; \
        *(u8 *)((u8 *)o + 0xaa) = 0; \
        D_8009E454_GameObjectPtr->touchFlag = 0; \
    } \
    if (*(volatile u16 *)&D_8009C9D8 & 0x10) { \
        D_8009B698_PPtr->b09 = 0; \
        (o)->subState = 0xb; \
        (o)->step = 0; \
        *(u8 *)((u8 *)o + 0xaa) = 0; \
        D_8009E454_GameObjectPtr->touchFlag = 0; \
    }

static __inline__ void nextspd_F808C(GameObject *o, P *pl)
{
    u8 *t = &D_80114578[--o->unkB2 * 2];
    pl->w0e = t[0];
    pl->w02 = t[1];
}

void func_800F808C(GameObject *o)
{
    extern s32 fixedMulSin2(u8, s32);
    u8 *t;
    s32 a;
    s32 v;
    s16 q;
    s16 d;

    switch (o->step) {
    case 0:
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650 = D_800A547C;
            D_8009C650->state = 2;
            D_8009C650->subState = 2;
            D_8009C650->step = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        D_8009B698_PPtr->b00 = 0;
        D_8009E454_GameObjectPtr->touchFlag = 1;
        o->unkB6 = -0x420;
        D_8009B698_PPtr->w02 = 0x10;
        D_8009B698_PPtr->w0e = 0;
        o->unkB2 = 2;
        D_8009B698_PPtr->b08 = 0;
        D_8009B698_PPtr->b09 = 0;
        D_8009B698_PPtr->w0c = 0;
        D_8009B698_PPtr->w28 = 0xffff;
        D_8009B698_PPtr->w2a = 0xffff;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unk30 = D_8009E454_GameObjectPtr->h->p.whole + o->unkB8;
        o->unk34 = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;
        playSFXWithVolume(4, 0x7f);
        *(u8 *)((u8 *)o + 0xaa) = 1;
        o->step++;
    case 1:
        o->unkB6 += D_8009B698_PPtr->w0e;
        if ((u16)o->unkB6 < 0x800)
            D_8009B698_PPtr->b08 = 1;
        if ((u16)(o->unkB6 - 0x800) < 0x800)
            D_8009B698_PPtr->b08 = 0;
        if ((u16)(o->unkB6 + 0x7ff) < 0x800)
            D_8009B698_PPtr->b08 = 0;
        if ((u16)(o->unkB6 + 0xfff) < 0x800)
            D_8009B698_PPtr->b08 = 1;
        if (o->unkB6 == 0) {
            P *pl = D_8009B698_PPtr;
            if (pl->w0e > 0) {
                nextspd_F808C(o, pl);
            }
        }
        a = o->unkB6 >> 4;
        D_8009B698_PPtr->w2e = 0xffff;
        o->anim = D_80011268;
        advanceAnimFrame(o, 0);
        D_8009B698_PPtr->b01 = 0x10;
        func_800F7EDC(o, q, a);
        if (o->unkB2 < 2)
            o->step++;
        break;
    case 2:
        o->unkB6 += D_8009B698_PPtr->w0e;
        if ((u16)o->unkB6 < 0x800)
            D_8009B698_PPtr->b08 = 1;
        if ((u16)(o->unkB6 - 0x800) < 0x800)
            D_8009B698_PPtr->b08 = 0;
        if ((u16)(o->unkB6 + 0x7ff) < 0x800)
            D_8009B698_PPtr->b08 = 0;
        if ((u16)(o->unkB6 + 0xfff) < 0x800)
            D_8009B698_PPtr->b08 = 1;
        if (o->unkB6 == 0) {
            P *pl = D_8009B698_PPtr;
            if (pl->w0e > 0) {
                nextspd_F808C(o, pl);
            } else {
                pl->b09 = 1;
            }
        }
        D_8009B698_PPtr->w2c = 7;
        if (D_8009B698_PPtr->w2e != 7) {
            D_8009B698_PPtr->w2c = 7;
            func_800EEF64(o);
            advanceAnimFrame(o, 0);
            D_8009B698_PPtr->w2e = D_8009B698_PPtr->w2c;
        }
        tickAnimation(o);
        {
            s32 b = o->unkB6 >> 4;
            q = (u32)b >> 2 & 0x3f;
            func_800F7EDC(o, q, b);
        }
        if (o->unkB2 == 0) {
            o->unk8C = 0;
            o->step++;
        }
        if (D_8009B698_PPtr->b09 == 0)
            break;
        BUTTONS(o);
        if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
            v = 0x10;
            D_8009B698_PPtr->b09 = 0;
            *(u8 *)((u8 *)o + 0xac) = 1;
            o->unk9E = 0;
            o->unkB2 = 0;
            o->velH = 0;
            o->velV = 0;
            o->unk30 = 0;
            o->unk34 = 0;
            o->velX = 0;
            o->velY = 0;
            o->timer = 10;
            o->unk84 = 0;
            if (o->animFrame & 1)
                v = 0xf0;
            {
                s32 w; s32 f;
                f = *(volatile u16 *)&o->animFrame;
                *(volatile s32 *)&o->unk88 = v;
                o->unk8C = 0;
                v = (s32)o->h;
                w = ((Fix16 *)v)->p.whole;
                if (f & 1)
                    ((Fix16 *)v)->p.whole = w + 10;
                else
                    ((Fix16 *)v)->p.whole = w - 10;
            }
            o->subState = 2;
            o->step = 3;
            o->y.p.whole += 4;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            D_8009E454_GameObjectPtr->touchFlag = 0;
        }
        break;
    case 3:
        o->unk30 = D_8009E454_GameObjectPtr->h->p.whole + o->unkB8;
        o->unk34 = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;
        o->h->p.whole = o->unk30;
        if (o->animFrame & 1)
            o->y.p.whole = fixedMulSin2((D_8009E454_GameObjectPtr->unk8C >> 4) + 0x70, D_8009E454_GameObjectPtr->hitOffsetX) + o->unk34 + 0x10;
        else
            o->y.p.whole = fixedMulSin2((D_8009E454_GameObjectPtr->unk8C >> 4) + 0x10, D_8009E454_GameObjectPtr->hitOffsetX) + o->unk34 + 0x10;
        tickAnimation(o);
        BUTTONS(o);
        if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
            v = 0x10;
            D_8009B698_PPtr->b09 = 0;
            *(u8 *)((u8 *)o + 0xac) = 1;
            o->timer = 10;
            o->unk9E = 0;
            o->unkB2 = 0;
            o->velH = 0;
            o->velV = 0;
            o->unk30 = 0;
            o->unk34 = 0;
            o->velX = 0;
            o->velY = 0;
            o->unk84 = 0;
            o->y.p.whole += 8;
            if (o->animFrame & 1)
                v = 0xf0;
            o->subState = 2;
            o->step = 3;
            *(u8 *)((u8 *)o + 0xaa) = 0;
            o->unk88 = v;
            o->unk8C = 0;
            D_8009E454_GameObjectPtr->touchFlag = 0;
        }
        break;
    }
}
#undef BUTTONS

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F88A8);
typedef struct G_F88A8 { char p0[2]; s16 w2; char p1[4]; u8 b8; char p2[5]; s16 we; } G_F88A8;
extern G_F88A8 *D_8009B698_G_F88A8PtrArr[] asm("D_8009B698");

void func_800F88A8(GameObject *o, s32 b, s32 p)
{
    extern u8 *D_8009B698;
    s32 s;
    s32 ang;
    s16 r;
    G_F88A8 *g;
    s32 d;
    if (o->animFrame & 1) {
        ang = 0x1bf; ang -= p;
        s = fixedMulCos2(ang & 0xff, D_8009B698[1]);
        o->h->p.whole = s + o->unk30;
        s = fixedMulSin2(ang & 0xff, D_8009B698[1]);
        o->unk84 = 0;
        o->unk8C = 0x100 - (u8)p;
        r = s + o->unk34;
    } else {
        ang = p + 0xc0;
        s = fixedMulCos2(ang & 0xff, D_8009B698[1]);
        o->h->p.whole = s + o->unk30;
        s = fixedMulSin2(ang & 0xff, D_8009B698[1]);
        o->unk84 = 0;
        o->unk8C = (u8)p;
        r = s + o->unk34;
    }
    o->y.p.whole = r;
    g = D_8009B698_G_F88A8PtrArr[0];
    d = g->we;
    if (g->b8) {
        s = g->w2;
        g->we = d - s;
    } else {
        s = g->w2;
        g->we = d + s;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F89E4);
typedef struct { s16 s0, s2; } H_F89E4;
typedef struct O_F89E4 {
    char p0[5]; u8 b5, b6; char p1; u8 b8, b9; char p2[0x16 - 0xa]; u16 w16;
    char p3[0x28 - 0x18]; u16 w28, w2a, w2c, w2e; char p4[0x40 - 0x30]; H_F89E4 *h;
    char p5[0x69 - 0x44]; u8 b69; char p6[0x8c - 0x6a]; u32 a8c; char p7[0x9e - 0x90]; u8 b9e;
    char p8[0xa4 - 0x9f]; u8 ba4; char p9[5]; u8 baa; char pa[5]; s16 sb0; char pb[0xbe - 0xb2]; u8 bbe;
} O_F89E4;
extern void func_800450FC(O_F89E4 *, s32, s32);

static __inline__ void setanim_F89E4(O_F89E4 *o, u16 x)
{
    extern O_F89E4 *D_8009B698;
    O_F89E4 *p = D_8009B698;
    p->w2c = x;
    if (p->w2e != x) {
        p->w2c = x;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->w2e = D_8009B698->w2c;
    }
}

void func_800F89E4(O_F89E4 *o)
{
    extern O_F89E4 *D_8009B698;
    H_F89E4 *h;
    s32 t;
    s16 d;
    if (o->b69 != 0 || ((s16 (*)(O_F89E4 *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
        if (o->bbe & 8) {
            D_8009B698->b8 = o->w2e & 1;
            o->b5 = 0x1b;
            o->b6 = 0;
            if ((o->bbe & 1) != o->w2e) {
                setanim_F89E4(o, 8);
                advanceAnimFrame(o, 2);
            } else {
                setanim_F89E4(o, 0x11);
            }
        } else {
            o->ba4 = 0;
            o->baa = 0;
            o->b9e = 0;
            D_8009B698->w2e = 0xffff;
            D_8009B698->w28 = 0xffff;
            D_8009B698->w2a = 0xffff;
            o->a8c = D_80114638[o->sb0];
            o->b5 = 0;
            o->b6 = 0;
        }
    } else {
        D_8009B698->b9 = 0;
        o->w16 += 9;
        h = o->h;
        t = h->s2;
        if (o->w2e & 1) d = t - 2; else d = t + 2;
        h->s2 = d;
        func_800450FC(o, o->h->s2, (s16)o->w16);
        setanim_F89E4(o, 10);
        o->b5 = 0xd;
        o->b6 = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F8C08);
extern char D_80011268[];
extern u8 D_80114570[][2];

typedef struct { u8 b0; char p1; s16 w2; char p4[8]; s16 wc; s16 we; char p10[0x28 - 0x10]; u16 w28, w2a; } PL_F8C08;

static __inline__ void setanim_F8C08(GameObject *o, u16 anim)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
}

static __inline__ void rot_F8C08(GameObject *o)
{
    extern GameObject *D_8009B698;
    PL_F8C08 *p = (PL_F8C08 *)D_8009B698;
    o->unkB6 += p->we;
    if ((u16)o->unkB6 < 0x800) *(u8 *)((u8 *)p + 8) = 1;
    if ((u32)((u16)o->unkB6 - 0x800) < 0x800) *(u8 *)((u8 *)D_8009B698 + 8) = 0;
    if ((u16)(o->unkB6 + 0x7ff) < 0x800) *(u8 *)((u8 *)D_8009B698 + 8) = 0;
    if ((u16)(o->unkB6 + 0xfff) < 0x800) *(u8 *)((u8 *)D_8009B698 + 8) = 1;
}

#define STEP(o) \
    o->h->p.whole += (o->animFrame & 1) ? -4 : 4; \
    func_800450FC(o, (s16)(o->h->p.whole + ((o->animFrame & 1) ? -8 : 8)), (s16)(o->y.p.whole - 0x10));

void func_800F8C08(GameObject *o)
{
    extern GameObject *D_8009B698;
    PL_F8C08 *p;
    PL_F8C08 *q;
    s16 u;
    s32 t;

    switch (o->step) {
    case 0:
        q = (PL_F8C08 *)D_8009B698;
        o->unkB6 = -0x420;
        q->w2 = 0x10;
        q->we = 0;
        o->unkB2 = 2;
        *(u8 *)((u8 *)q + 8) = 0;
        *(u8 *)((u8 *)D_8009B698 + 9) = 0;
        ((PL_F8C08 *)D_8009B698)->wc = 0;
        ((PL_F8C08 *)D_8009B698)->w28 = 0xffff;
        ((PL_F8C08 *)D_8009B698)->w2a = 0xffff;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650_U8Ptr = D_800A547C;
            D_8009C650_U8Ptr[4] = 2;
            D_8009C650_U8Ptr[5] = 2;
            D_8009C650_U8Ptr[6] = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        *(u8 *)((u8 *)D_8009B698 + 0) = 0;
        o->anim = D_80011268;
        advanceAnimFrame(o, 0);
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole - 4;
        playSFXWithVolume(4, 0x7f);
        o->step++;
    case 1:
        rot_F8C08(o);
        if (o->unkB6 == 0) {
            p = (PL_F8C08 *)D_8009B698;
            if (p->we > 0) {
                u8 *b = D_80114570[--o->unkB2];
                p->we = b[0];
                p->w2 = b[1];
            }
        }
        t = (s16)o->unkB6 >> 4;
        D_8009B698->animFrame = 0xffff;
        *(u8 *)((u8 *)D_8009B698 + 1) = 0x12;
        func_800F88A8(o, u, t);
        if (o->unkB2 < 2) o->step++;
        break;
    case 2:
        rot_F8C08(o);
        if (o->unkB6 == 0) {
            p = (PL_F8C08 *)D_8009B698;
            if (p->we > 0) {
                u8 *b = D_80114570[--o->unkB2];
                p->we = b[0];
                p->w2 = b[1];
            } else {
                *(u8 *)((u8 *)p + 9) = 1;
            }
        }
        setanim_F8C08(o, 7);
        tickAnimation(o);
        {
            u32 v = (s16)o->unkB6 >> 4;
            func_800F88A8(o, (v >> 2) & 0x3f, v);
        }
        if (o->unkB2 == 0) {
            o->unk8C = 0;
            o->h->p.whole = o->unk74 + ((o->animFrame & 1) ? -4 : 4);
            o->y.p.whole = o->unk76 + 0xc;
            o->step++;
        } else if (*(u8 *)((u8 *)D_8009B698 + 9) != 0) {
            func_800F88A8(o, 0, 0);
            if (D_8009C9D8[0] & (*(u16 *)&D_1F8003C6)) {
                *(u8 *)((u8 *)D_8009B698 + 9) = 0;
                o->subState = 0xb;
                o->step = 0;
            }
            if (D_8009C9D8[0] & 0x10) {
                *(u8 *)((u8 *)D_8009B698 + 9) = 0;
                STEP(o);
                o->subState = 0xb;
                o->step = 0;
            }
            if (D_8009C9D8[0] & 0x40) {
                STEP(o);
                func_800F89E4(o);
            }
        }
        break;
    case 3:
        tickAnimation(o);
        if (D_8009C9D8[0] & (*(u16 *)&D_1F8003C6)) {
            *(u8 *)((u8 *)D_8009B698 + 9) = 0;
            o->subState = 0xb;
            o->step = 0;
        }
        if (D_8009C9D8[0] & 0x10) {
            *(u8 *)((u8 *)D_8009B698 + 9) = 0;
            o->subState = 0xb;
            o->step = 0;
        }
        if (D_8009C9D8[0] & 0x40) {
            *(u8 *)((u8 *)D_8009B698 + 9) = 0;
            o->y.p.whole += 9;
            func_800450FC(o, o->h->p.whole, o->y.p.whole);
            setanim_F8C08(o, 10);
            o->subState = 0xd;
            o->step = 0;
        }
        break;
    }
    func_800EE50C(o);
}
#undef STEP

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F937C);

static __inline__ void setanim_F937C(GameObject *o, u16 anim)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
}

typedef struct { u8 b0; char p1; s16 w2; char p4[8]; s16 wc; s16 we; char p10[0x28 - 0x10]; u16 w28, w2a; } PL;

void func_800F937C(GameObject *o)
{
    extern GameObject *D_8009B698;
    PL *p;
    switch (o->step) {
    case 0:
        p = (PL *)D_8009B698;
        o->unkB6 = 0;
        *(u8 *)((u8 *)p + 8) = 0;
        p->we = 0;
        p->w2 = 0;
        *(u8 *)((u8 *)D_8009B698 + 9) = 0;
        ((PL *)D_8009B698)->wc = 0;
        ((PL *)D_8009B698)->w28 = 0xffff;
        ((PL *)D_8009B698)->w2a = 0xffff;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->h->p.whole = o->h->p.whole;
        o->y.p.whole += 4;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650_U8Ptr = D_800A547C;
            D_8009C650_U8Ptr[4] = 2;
            D_8009C650_U8Ptr[5] = 2;
            D_8009C650_U8Ptr[6] = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        *(u8 *)((u8 *)D_8009B698 + 0) = 0;
        setanim_F937C(o, 7);
        playSFXWithVolume(4, 0x7f);
        o->step++;
    case 1:
        tickAnimation(o);
        if ((*(s32 *)&GAME) == 0x30000) break;
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            *(u8 *)((u8 *)D_8009B698 + 9) = 0;
            setanim_F937C(o, 9);
            o->state = 1;
            o->subState = 0xb;
            o->step = 0;
        }
        if (D_1F8001FC & 0x10) {
            *(u8 *)((u8 *)D_8009B698 + 9) = 0;
            setanim_F937C(o, 9);
            o->state = 1;
            o->subState = 0xb;
            o->step = 0;
        }
        if (D_1F8001FC & 0x40) {
            *(u8 *)((u8 *)D_8009B698 + 9) = 0;
            o->y.p.whole += 9;
            o->h->p.whole += (o->animFrame & 1) ? -4 : 4;
            func_800450FC(o, o->h->p.whole, o->y.p.whole);
            o->subState = 0xd;
            o->step = 0;
        }
        break;
    }
    func_800EE50C(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F96BC);
typedef struct {
    u8 p0[8];
    u8 b8;
    u8 p9[0x2c - 9];
    u16 w2c;
    u16 w2e;
} P800FA35C_F96BC;
extern void func_800FE970(GameObject *, s32);

static __inline__ void setanim_F96BC(GameObject *o, u16 x)
{
    extern P800FA35C_F96BC *D_8009B698;
    P800FA35C_F96BC *p = D_8009B698;
    p->w2c = x;
    if (p->w2e != x) {
        p->w2c = x;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->w2e = D_8009B698->w2c;
    }
}

#define TURN() \
    x = D_80114638[o->unkB0]; \
    c = (u8)(x - o->unk8C); \
    d = c; \
    if (d == 0) return; \
    u = c; \
    if (u < 0x80) { \
        if (d >= 4) o->unk8C = o->unk8C + 4; \
        else if (d >= 2) o->unk8C = o->unk8C + 2; \
        else o->unk8C = o->unk8C + 1; \
    } else { \
        if (d < 0xfd) o->unk8C = o->unk8C - 4; \
        else if (d < 0xff) o->unk8C = o->unk8C - 2; \
        else o->unk8C = o->unk8C - 1; \
    }

void func_800F96BC(GameObject *o)
{
    extern P800FA35C_F96BC *D_8009B698;
    s32 t;
    u8 x;
    u32 c;
    s16 d;
    u16 u;

    switch (o->unk7) {
    case 0:
        o->timer = 0x14;
        o->velX = 0;
        o->velY = 0;
        setanim_F96BC(o, 0x10);
        o->unk7++;
        func_800FE970(o, 0);
    case 1:
        if (o->timer != 0) o->timer--;
        tickAnimation(o);
        {
            s32 d0 = o->unk8C;
            if (o->animFrame & 1) t = (d0 - 0x10) & 0xff;
            else t = (d0 + 0x10) & 0xff;
            o->unk8C = t;
        }
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x800;
        if (o->velY > 0x680) o->velY = 0x680;
        if (o->unkA6 != 0 || (o->touchFlag != 0 && (o->velY = 0, o->timer <= 0))) {
            o->unk8C = 0;
            setanim_F96BC(o, 0x2f);
            o->timer = 0x1e;
            o->unk7++;
        } else if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            o->touchFlag = 0;
            o->velY = 0;
            if (o->timer <= 0) {
                o->unk8C = 0;
                setanim_F96BC(o, 0x2f);
                o->timer = 0x1e;
                o->unk7++;
            }
            func_800FE970(o, 0);
        }
        break;
    case 2:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x800;
        if (o->velY > 0x680) o->velY = 0x680;
        if (o->timer != 0 && --o->timer <= 0) o->unk7++;
        if (o->touchFlag != 0 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            o->velY = 0;
            func_800FE970(o, 0);
        }
        TURN();
        o->unk8C = *(u8 *)&o->unk8C;
        break;
    case 3:
        o->touchFlag = 0;
        *(u8 *)&o->unkAC = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        setanim_F96BC(o, 0x30);
        o->unk7++;
        TURN();
        o->unk8C = *(u8 *)&o->unk8C;
        break;
    case 4:
        o->y.raw += o->velY << 8;
        o->velY += 0x800;
        if (o->velY > 0x680) o->velY = 0x680;
        if (o->touchFlag != 0 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            o->velY = 0;
            func_800FE970(o, 0);
        }
        if (tickAnimation(o)) {
            D_8009B698->b8 = 0;
            o->active = 1;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
        }
        TURN();
        o->unk8C = *(u8 *)&o->unk8C;
        break;
    }
}
#undef TURN

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800F9C7C);
extern u8 D_8009BCD8[];

static __inline__ void setanim_F9C7C(GameObject *o, u16 anim)
{
    extern GameObject *D_8009B698;
    GameObject *p = D_8009B698;
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->animFrame = D_8009B698->animTimer;
    }
}

void func_800F9C7C(GameObject *o)
{
    extern GameObject *D_8009B698;
    s32 k;

    switch (o->step) {
    case 0:
        k = o->unk9E;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        o->touchFlag = 0;
        o->unk9F = 0;
        o->animFrame &= 1;
        if (k != 0) {
            if (k == 4 || k == 7)
                D_8009E454[0] = 1;
            if (D_8009E454[2] == 0x21)
                D_8009E454[0xa7] = 0;
            else
                D_8009E454[0x6a] = 0;
        }
        o->unk9E = 0;
        o->unkBE = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkA4 = 0;
        o->unk9D = 0;
        o->unk8C = 0;
        o->unkB0 = 0;
        *(u8 *)((u8 *)D_8009B698 + 8) = 0;
        *(u8 *)((u8 *)D_8009B698 + 9) = 0;
        *(u8 *)((u8 *)D_8009B698 + 0xa) = 0;
        o->velV = 0;
        setanim_F9C7C(o, 0x1e);
        *(u8 *)((u8 *)D_8009B698 + 0xa) = 0;
        *(u8 *)((u8 *)D_8009B698 + 9) = 0xff;
        o->unk7 = 0;
        o->step++;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650_U8Ptr = D_800A547C;
            D_8009C650_U8Ptr[4] = 2;
            D_8009C650_U8Ptr[5] = 2;
            D_8009C650_U8Ptr[6] = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        *(u8 *)((u8 *)D_8009B698 + 0) = 0;
    case 1:
        o->unkB0 = 0;
        o->unkB6 = 0;
        tickAnimation(o);
        if (--*(u8 *)((u8 *)D_8009B698 + 9) != 0) {
            if (D_1F8001FC) {
                if (D_1F8001FC & 0x80)
                    o->animFrame = 1;
                if (D_1F8001FC & 0x20)
                    o->animFrame = 0;
                if (D_1F8001FC & 0xf0)
                    (*(u8 *)((u8 *)D_8009B698 + 0xa))++;
                if (*(u8 *)((u8 *)D_8009B698 + 0xa) > 10) {
                    o->unk9C = 2;
                    playSFXWithNote(2, 4);
                    *(u8 *)((u8 *)D_8009B698 + 0xa) = 0;
                    *(u8 *)((u8 *)D_8009B698 + 9) = 0;
                    o->step = 3;
                    o->timer = 0;
                    o->unk7 = 1;
                }
            }
        } else {
            *(u8 *)((u8 *)D_8009B698 + 0xa) = 0;
            *(u8 *)((u8 *)D_8009B698 + 9) = 0xff;
            o->timer = 0;
        }
        if (o->unk98 != o->unk9A) {
            D_8009BCD8[0] = o->unk98;
            if (o->unk98 <= 0) {
                o->state = 2;
                o->subState = 3;
                o->step = 0;
            } else {
                o->step = 2;
            }
            o->unk9A = o->unk98;
            setanim_F9C7C(o, 0x10);
            *(u8 *)((u8 *)D_8009B698 + 0xa) = 0;
            *(u8 *)((u8 *)D_8009B698 + 9) = 0xff;
            playSFXWithNote(0x23, 0x24);
            func_80028A74(0, 0x81, 0x81, 0x3c);
            o->timer = 0x3c;
        }
        break;
    case 2:
        tickAnimation(o);
        if (--o->timer != 0) break;
        setanim_F9C7C(o, 0);
        *(u8 *)((u8 *)D_8009B698 + 0xa) = 0;
        *(u8 *)((u8 *)D_8009B698 + 9) = 0;
        o->step = 1;
        break;
    case 3:
        tickAnimation(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA14C);
typedef struct { GameObject t; char c0[7]; u8 bc7; u8 bc8; } PO_FA14C;
typedef struct { char pad[8]; u8 b8; char pad2[0x20 - 9]; s16 w20; s16 w22; } P_FA14C;
extern s16 probeCollisionAtDepthB(PO_FA14C *, s32, s32);

static __inline__ s16 cond_FA14C(PO_FA14C *o)
{
    s32 v = 0;
    if (o->t.unkB4 < 0x29) {
        v = (*(volatile u16 *)&D_8009C9D8 >> 4) & 1;
    }
    return v;
}

void func_800FA14C(PO_FA14C *o)
{
    extern P_FA14C *D_8009B698;
    s32 one, s;
    s16 n, k;
    if (*(u16 *)0x1F8001FC & (*(u16 *)0x1F8003C6 | *(u16 *)0x1F8003C8)) {
        one = 1;
        D_8009BC9C = 0;
        o->bc7 = one;
        o->t.unkA4 = 0;
        *(u8 *)&o->t.unkAC = 0;
        o->t.touchFlag = 0;
        o->t.unk9C = 0;
        o->t.unk9D = 0;
        o->bc8 = 0;
        o->t.unkA7 = 0;
        o->t.velH = 0;
        o->t.velV = 0;
        o->t.velX = 0;
        o->t.velY = 0;
        o->t.unk84 = 0;
        o->t.unk88 = 0;
        D_8009B698->b8 = 0;
        D_8009B698->w20 = 0;
        D_8009B698->w22 = 0;
        if (cond_FA14C(o)) {
            o->t.h->p.whole = o->t.unk30;
            o->t.y.p.whole = o->t.unk34 + 0x14;
            k = probeCollisionAtDepthB(o, o->t.h->p.whole, (s16)(o->t.y.p.whole - 0x40)) != 0;
            n = k;
            if (probeCollisionAtDepthB(o, o->t.h->p.whole, (s16)(o->t.y.p.whole - 0x50))) n = k + 1;
            if (probeCollisionAtDepthB(o, o->t.h->p.whole, (s16)(o->t.y.p.whole - 0x60))) n++;
            if (n == 0) {
                *(s8 *)&o->t.unkF = -20;
                *(u8 *)&o->t.unkAA = one;
                o->t.subState = 0x49;
                o->t.step = 0;
            } else {
                o->t.subState = 2;
                o->t.step = 0;
            }
        } else {
            o->t.subState = 0x37;
            o->t.step = 0;
        }
    } else if (o->t.touchFlag == 1) {
        D_8009B698->w20 = 0;
        D_8009B698->w22 = 0;
        D_8009B698->b8 = 0;
        D_8009BC9C = 0;
        playSFXWithVolume(0x1c, 0x7f);
        o->bc7 = 1;
        o->t.unk9C = 0;
        *(u8 *)&o->t.unkAC = 0;
        o->t.unk9D = 0;
        o->bc8 = 0;
        o->t.unk8C = D_80114638[o->t.unkB0];
        o->t.subState = 0;
        o->t.step = 0;
    } else if (((s16 (*)(PO_FA14C *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
        D_8009B698->w20 = 0;
        D_8009B698->w22 = 0;
        D_8009B698->b8 = 0;
        D_8009BC9C = 0;
        playSFXWithVolume(0x1c, 0x7f);
        o->bc7 = 1;
        o->t.unk9C = 0;
        *(u8 *)&o->t.unkAC = 0;
        o->t.unk9D = 0;
        o->bc8 = 0;
        o->t.unk8C = D_80114638[o->t.unkB0];
        o->t.subState = 1;
        o->t.step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA3F4);
void func_800FA3F4(GameObject *o)
{
    if (o->animFrame & 1)
        o->unk84 = 0x100 - o->unk7A;
    else
        o->unk84 = o->unk7A;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA420);
typedef struct P_FA420 { char pad0[0xa]; u8 b0a; char pad1[0x20 - 0xb]; u16 w20, w22; } P_FA420;

void func_800FA420(char *o)
{
    extern P_FA420 *D_8009B698;
    P_FA420 *q;
    s32 t;
#define pad D_8009C9D8
    if (!(*pad & 0x10))
        D_8009B698->w20 = 0;
    if (!(*pad & 0x40))
        D_8009B698->w22 = 0;
    if (D_8009B698->b0a == 0) {
        if ((*pad & 0x10) && clampToCeilingAndProbeSides(o) == 0) {
            q = D_8009B698;
            *(s32 *)(o + 0x38) -= q->w20 << 8;
            if ((q->w20 += 8) > 0x200)
                q->w20 = 0x200;
            if (*(s32 *)(o + 0x38) < 0x280000)
                *(s32 *)(o + 0x38) = 0x280000;
        }
        if (*pad & 0x40) {
            q = D_8009B698;
            *(s32 *)(o + 0x38) += q->w22 << 8;
            if ((q->w22 += 8) > 0x200)
                q->w22 = 0x200;
            if (*(s32 *)(o + 0x38) > 0x780000)
                *(s32 *)(o + 0x38) = 0x780000;
        }
    }
    t = *(s16 *)(o + 0x3a);
    *(s16 *)(o + 0xb4) = t;
    if (t < 0x28)
        *(s16 *)(o + 0xb4) = 0x28;
    if (*(s16 *)(o + 0xb4) > 0x78)
        *(s16 *)(o + 0xb4) = 0x78;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA5E0);
s32 func_800FA5E0(void)
{
    extern char *D_8009B698;
    s32 r = 0;
    switch ((*(s16 *)&D_800A544A)) {
    case 1:
        if (D_800A544C > 80) r = 2;
        else if (D_800A544C > 40) r = 2;
        else if (D_800A544C > 0) r = 3;
        break;
    case 2:
        if (D_800A544C > 80) r = 2;
        else if (D_800A544C > 40) r = 3;
        else if (D_800A544C > 0) r = 3;
        break;
    case 3:
        if (D_800A544C > 80) r = 2;
        else if (D_800A544C > 40) r = 3;
        else if (D_800A544C > 0) r = 3;
        break;
    case 4:
        if (D_800A544C > 80) r = 2;
        else if (D_800A544C > 40) r = 3;
        else if (D_800A544C > 0) r = 3;
        break;
    }
    if (D_8009B698[10] != 0) r = 4;
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA6D0);
void func_800FA6D0(char *o)
{
    extern P *D_8009B698;
    if (*(s16 *)(o + 0xb4) > 0x28) {
        u32 u = (*(s32 *)(o + 0x84) >> 3) & 0xf;
        D_8009B698->w2c = 0x31;
        func_800EEF64(o);
        advanceAnimFrame(o, u);
    } else {
        D_8009B698->w2c = 0x31;
        func_800EEF64(o);
        advanceAnimFrame(o, 0xf);
    }
    D_8009B698->w2e = D_8009B698->w2c;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA774);
void func_800FA774(u8 *o)
{
    *(s32 *)(o + 0x8c) = o[0x88];
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FA780);
typedef struct {
    char p0[2]; s16 w02; char p4[3];
    u8 b7, b8, b9, b0a; char pb;
    s16 w0c; s16 w0e; char p10[0x10];
    s16 w20, w22; char p24[8];
    u16 w2c, w2e;
} P_FA780;
typedef struct { GameObject t; char c0[7]; u8 bc7, bc8; char c9[0xe4 - 0xc9]; s32 de4; } PO_FA780;
extern s16 D_801145B8[][2];
extern void func_80042C20(GameObject *);

static __inline__ void setanim_FA780(GameObject *o, u16 x)
{
    extern P_FA780 *D_8009B698;
    P_FA780 *p = D_8009B698;
    p->w2c = x;
    if (p->w2e != x) {
        p->w2c = x;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->w2e = D_8009B698->w2c;
    }
}

static __inline__ s16 inc3_FA780(s32 q) { if (q < 3) return q + 1; return q; }
static __inline__ s16 dec0_FA780(s32 q) { return (q > 0) ? q - 1 : q; }
static __inline__ void anim31_FA780(GameObject *o)
{
    extern P_FA780 *D_8009B698;
    if (o->unkB4 > 0x28) {
        u32 u = (o->unk84 >> 3) & 0xf;
        D_8009B698->w2c = 0x31;
        func_800EEF64(o);
        advanceAnimFrame(o, u);
        D_8009B698->w2e = D_8009B698->w2c;
    } else {
        D_8009B698->w2c = 0x31;
        func_800EEF64(o);
        advanceAnimFrame(o, 0xf);
        D_8009B698->w2e = D_8009B698->w2c;
    }
}

void func_800FA780(GameObject *o)
{
    extern P_FA780 *D_8009B698;
    P_FA780 *p;
    s32 v;
    s16 f;
    u32 x;
    u16 w;
    s32 a;
    u16 m;
    u16 w2;
#define M m
#define M2 m
    s32 t;

    switch (o->step) {
    case 0:
        o->unkB2 = 3;
        o->unk9C = 0;
        o->unkA4 = 0;
        o->unk9E = 0;
        *(u8 *)&o->unkAA = 0;
        if (*(u8 *)&o->unkAC == 2) {
            D_8009C650 = ((PO_FA780 *)o)->de4;
            D_8009B698->b8 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            break;
        }
        *(u8 *)&o->unkAC = 0;
        if (o->touchFlag) {
            D_8009B698->w20 = 0;
            D_8009B698->w22 = 0;
            D_8009B698->b8 = 0;
            D_8009BC9C = 0;
            playSFXWithVolume(0x1c, 0x7f);
            ((PO_FA780 *)o)->bc7 = 1;
            o->unk9C = 0;
            *(u8 *)&o->unkAC = 0;
            o->unk9D = 0;
            ((PO_FA780 *)o)->bc8 = 0;
            o->unk8C = D_80114638[o->unkB0];
            o->subState = 0;
            o->step = 0;
            break;
        }
        if (o->velX == 0) {
            w = o->unk7A;
            m = o->animFrame;
            a = (w - 0xa0) & 0xff;
            if ((M & 6) == 6) {
                v = 0xc0;
                if (M & 1) v = 0x40;
                o->unk84 = v;
                o->unkB2 = 0;
            } else if (a > 0x40) {
                if (M & 1) o->unk84 = 0x10; else o->unk84 = 0x90;
                o->unkB2 = 4;
            } else {
                if (M & 1) o->unk84 = 0x100 - (s16)w; else o->unk84 = (s16)w;
                o->unkB2 = 2;
            }
        } else if (!((m = o->animFrame) & 4)) {
            w2 = o->unk7A;
            if (((w2 - 0xa0) & 0xff) > 0x40) {
                if (M2 & 1) o->unk84 = 0x10; else o->unk84 = 0x90;
                o->unkB2 = 3;
            } else {
                if (M2 & 1) o->unk84 = 0x100 - (s16)w2; else o->unk84 = (s16)w2;
                o->unkB2 = 3;
                if ((u16)(o->velX + 0x100) < 0x200) o->unkB2 = 3;
                if ((u16)(o->velX + 0x200) < 0x400) o->unkB2 = 3;
            }
        }
        {
            P_FA780 *q = D_8009B698;
            q->b8 = 0;
            q->w20 = 0;
            q->w22 = 0;
        }
        D_8009B698->b9 = 0;
        D_8009B698->b0a = 0;
        D_8009B698->w0c = 0;
        D_8009B698->w02 = 0;
        D_8009B698->w0e = 0;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unk9D = 0;
        playSFXWithVolume(0x26, 0x7f);
        setanim_FA780(o, 0x31);
        D_8009B698->b9 = D_8009B698->b7 & 1;
        if (o->animFrame & 1) o->unk84 = 0x100 - o->unk7A; else o->unk84 = o->unk7A;
        o->unk38 = o->unkB4 << 16;
        o->animFrame = D_8009B698->b9;
        o->timer = 0;
        o->velH = o->h->p.whole;
        o->velV = o->y.p.whole;
        o->step++;
        if (o->unkB2 == 0) {
            setanim_FA780(o, 0x34);
            o->step = 2;
            break;
        }
    case 1:
        if (o->animFrame & 1) {
            f = (u8)o->unk84 - 0x3e;
            if ((u32)f < 4) {
                if (o->unkB2 >= 4) o->unkB2 = 3;
                o->unk84 = 0x41;
                playSFXWithNote(3, 0);
                if (D_8009C9D8[0] & 0x80) o->unkB2 = inc3_FA780(o->unkB2);
                if (D_8009C9D8[0] & 0x20) { s32 q = o->unkB2; if (q > 0) q--; o->unkB2 = q; }
            }
        } else {
            f = (u8)o->unk84 - 0xbe;
            if ((u32)f < 4) {
                if (o->unkB2 >= 4) o->unkB2 = 3;
                o->unk84 = 0xc1;
                playSFXWithNote(3, 0);
                if (D_8009C9D8[0] & 0x20) o->unkB2 = inc3_FA780(o->unkB2);
                if (D_8009C9D8[0] & 0x80) { s32 q = o->unkB2; if (q > 0) q--; o->unkB2 = q; }
            }
        }
        o->unk84 += ((s16 (*)(void))func_800FA5E0)();
        if ((o->unk84 & 0xff) < 0x80) o->animFrame = 1; else o->animFrame = 0;
        p = D_8009B698;
        if (p->b0a == 0) {
            f = 0;
            o->unk88 = (s16)fixedMulCos2((u8)o->unk84, D_801145B8[o->unkB2][0]);
            o->h->p.whole = fixedMulCos2((o->unk88 + 0xc0) & 0xff, o->unkB4) + o->unk30;
            o->y.p.whole = fixedMulSin2((o->unk88 + 0xc0) & 0xff, o->unkB4) + o->unk34;
            func_80042C20(o);
            if (o->unkA6 == 0) f = clampToCeilingAndProbeSides(o) == 0;
            if ((f << 16) == 0) {
                D_8009B698->b0a = 1;
                x = (u8)o->unk84;
                if ((u8)(x - 0x40) < 0x80) {
                    D_8009B698->w0c = (0x100 - x) & 0xff;
                    o->unk84 = *(u8 *)&o->unk84;
                    D_8009B698->b9 = 0;
                } else {
                    D_8009B698->w0c = -x & 0xff;
                    o->unk84 = *(u8 *)&o->unk84;
                    D_8009B698->b9 = 1;
                }
                if (D_8009B698->w0c < o->unk84) o->unk84 |= 0x100;
            }
        } else if (p->b9) {
            if (p->w0c >= o->unk84) p->b9 = 0;
        } else {
            if (o->unk84 >= p->w0c) {
                o->unk84 += 4;
                p->b0a = 0;
            }
        }
        o->unk8C = *(u8 *)&o->unk88;
        anim31_FA780(o);
        func_800FA420(o);
        if (o->unkB2 == 0) {
            setanim_FA780(o, 0x34);
            o->step++;
        }
        func_800FA14C(o);
        o->unk84 = *(u8 *)&o->unk84;
        break;
    case 2:
        o->h->p.whole = fixedMulCos2(0xc0, o->unkB4) + o->unk30;
        o->y.p.whole = fixedMulSin2(0xc0, o->unkB4) + o->unk34;
        func_800FA420(o);
        if (D_1F8001FC & 0xa0) {
            o->unkB2 = 1;
            o->step = 1;
        }
        func_800FA14C(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB04C);
#define PAD (*(volatile u16 *)&D_8009C9D8)

void func_800FB04C(GameObject *o)
{
    if (o->animFrame & 1) {
        o->velX = -0x300;
        o->velY = -0x600;
        if (PAD & 0x80) {
            o->velX = -0x480;
            o->velY = -0x800;
        }
        if (PAD & 0x20) {
            o->velX = -0x200;
            o->velY = -0x400;
        }
    } else {
        o->velX = 0x300;
        o->velY = -0x600;
        if (PAD & 0x80) {
            o->velX = 0x200;
            o->velY = -0x400;
        }
        if (PAD & 0x20) {
            o->velX = 0x480;
            o->velY = -0x800;
        }
    }
}
#undef PAD

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB114);
typedef struct S_FB114 {
    char p0[5]; u8 step, state; char p1[0x20 - 7];
    s16 timer; char p2[0x2c - 0x22]; u16 w2c, frame; char p3[0x69 - 0x30];
    u8 b69; char p4[0x7c - 0x6a]; s16 velX, velY; char p5[0x84 - 0x80];
    s32 d84; s32 d88; s32 d8c; char p6[0x9c - 0x90]; u8 b9c, p9d, b9e; char p7[0xac - 0x9f];
    u8 bac; char p8[0xb0 - 0xad]; s16 wb0, wb2, wb4, wb6;
} S_FB114;
extern s16 D_80114598[];
void func_800FB114(S_FB114 *o)
{
    extern S_FB114 *D_8009B698;
    s32 a;
    char pad8;
    s16 v, k, i, vx;
    S_FB114 *g;
    if (o->state != 0)
        return;
    a = o->d84;
    o->d8c = 0;
    o->b9e = 0;
    o->b69 = 0;
    o->b9c = 1;
    o->wb0 = 0;
    o->bac = 0;
    if ((u16)(a - 0x40) < 0x80) {
        v = a - 0x40;
        if (v < 0x20) k = 4;
        else if (v < 0x40) k = 5;
        else if (v < 0x60) k = 6;
        else if (v < 0x80) k = 7;
    } else {
        v = a;
        if (v < 0x20) k = 0;
        else if (v < 0x40) k = 1;
        else if (v < 0xe0) k = 2;
        else k = 3;
    }
    i = k * 2;
    vx = D_80114598[i];
    if (o->frame & 1)
        vx = -vx;
    o->velX = vx;
    o->velY = D_80114598[i + 1];
    if (o->wb2 == 0) o->velX = 0;
    if (o->wb4 < 0x29) o->velX = 0;
    if (o->frame & 1) {
        o->velX = -0x300;
        o->velY = -0x600;
        if (*(volatile u16 *)&D_8009C9D8 & 0x80) { o->velX = -0x480; o->velY = -0x800; }
        if (*(volatile u16 *)&D_8009C9D8 & 0x20) { o->velX = -0x200; o->velY = -0x400; }
    } else {
        o->velX = 0x300;
        o->velY = -0x600;
        if (*(volatile u16 *)&D_8009C9D8 & 0x80) { o->velX = 0x200; o->velY = -0x400; }
        if (*(volatile u16 *)&D_8009C9D8 & 0x20) { o->velX = 0x480; o->velY = -0x800; }
    }
    g = D_8009B698;
    g->timer = 10;
    o->wb2 = 0;
    o->wb6 = 0;
    g->w2c = 8;
    if (g->frame != 8) {
        g->w2c = 8;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698->frame = D_8009B698->w2c;
    }
    playSFXWithNote(2, 4);
    o->step = 2;
    o->state = 2;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB38C);

void func_800FB38C(u8 *o)
{
    extern u8 *D_8009B698;
    u8 *p;
    o[0x9c] = 1;
    if (o[0xac] >= 2) {
        D_8009C650_U8Ptr = (*(u8 **)&D_800A547C);
        (*(u8 **)&D_800A547C)[4] = 2;
        D_8009C650_U8Ptr[5] = 2;
        D_8009C650_U8Ptr[6] = 0;
    }
    o[0xac] = 0;
    D_8009BC9C = 0;
    o[0xc7] = 1;
    o[0x9d] = 0;
    o[0xc6] = 0;
    o[0xe3] = 0;
    *D_8009B698 = 0;
    *(s32 *)(o + 0x8c) = 0;
    if (o[0x9e] != 0)
        D_8009E454[0x6a] = 0;
    o[0x9e] = 0;
    o[0xaa] = 0;
    o[0xa7] = 0;
    p = D_8009B698;
    *(s16 *)(o + 0xb0) = 0;
    p[8] = 0;
    *(s8 *)(o + 0xf) = -8;
    o[0xa4] = 0;
    o[0x69] = 0;
    *(s16 *)(o + 0x82) = 0;
    o[6]++;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB464);
typedef struct { char pad[8]; u8 b8; } P_FB464;
extern u8 D_8009BCD8[];
extern void stopBgm(s32);
extern void playJingle(s32);

void func_800FB464(GameObject *o)
{
    extern P_FB464 *D_8009B698;
    char pad;
    if (*(u8 *)0x1F8001A4 == 0 && o->unk9A != o->unk98) {
        o->unk9A = o->unk98;
        D_8009B698->b8 = 1;
        D_8009BCD8[0] = o->unk98;
        if (o->unk98 <= 0) {
            D_8009BCAA = 1;
            D_8009BCA0 = 1;
            stopBgm(0);
            playJingle(3);
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB4EC);
extern u8 D_8009C62B;
extern u8 D_8009C1A5;
s32 func_800FB4EC(u8 *o)
{
    s32 r = 0;
    if (D_8009C62B & 0x40) {
        if (*(s16 *)(o + 0x16) > -0x8c) {
            r = 1;
            *(s16 *)(o + 0x56) = -0x8c;
            if (*(s16 *)(o + 0x16) > -0x7c) {
                if (D_8009C1A5 == 0xff) r = 2;
                else *(s16 *)(o + 0x16) = -0x8c;
            }
        }
    } else {
        if (*(s16 *)(o + 0x16) > -0x3c0) {
            r = 1;
            *(s16 *)(o + 0x56) = -0x3c0;
            if (*(s16 *)(o + 0x16) > -0x3b0) {
                if (D_8009C1A5 == 0xff) r = 2;
                else *(s16 *)(o + 0x16) = -0x3c0;
            }
        }
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB5A0);
s32 func_800FB5A0(GameObject *o)
{
    extern u8 *D_8009B698;
    s16 r;

    if (D_8009BCA0 != 0) {
        return 0;
    }
    if (o->velY < 0x680) {
        return 0;
    }
    D_8009B698[8] = 0;
    *((u8 *)o + 0xd1) = 0;
    o->active = 3;
    *(s16 *)((char *)o + 0xe0) = 0x8c;
    *(s16 *)((char *)o + 0xb2) = 0;
    o->state = 1;
    if ((*(s32 *)&GAME) == 0x2000e) {
        o->subState = 0x3e;
        o->step = 0;
            o->unk7 = 0;
    } else if (((*(s32 *)&GAME) & 0x3ffff) == 0x3000a) {
        r = 0;
        if (D_8009C62B & 0x40) {
            if (o->y.p.whole >= -0x8b) {
                r = 1;
                o->unk56 = -0x8c;
                if (o->y.p.whole >= -0x7b) {
                    if (D_8009C1A5 == 0xff) {
                        r = 2;
                    } else {
                        o->y.p.whole = -0x8c;
                    }
                }
            }
        } else {
            if (o->y.p.whole >= -0x3bf) {
                r = 1;
                o->unk56 = -0x3c0;
                if (o->y.p.whole >= -0x3af) {
                    if (D_8009C1A5 == 0xff) {
                        r = 2;
                    } else {
                        o->y.p.whole = -0x3c0;
                    }
                }
            }
        }
        switch (r) {
        case 0:
            o->unk9C = 2;
            *(u8 *)&o->unkAC = 1;
            o->subState = 2;
            o->step = 3;
            o->unk7 = 0;
            break;
        case 1:
            o->subState = 0x3d;
            o->step = 0;
            o->unk7 = 0;
            break;
        case 2:
            o->subState = 0x3e;
            o->step = 0;
            o->unk7 = 0;
            break;
        default:
            return 1;
        }
    } else {
        o->unk9C = 2;
        *(u8 *)&o->unkAC = 1;
        o->subState = 2;
        o->step = 3;
        o->unk7 = 0;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FB774);
typedef struct {
    u8 b0;
    u8 p1[7];
    u8 b8;
    u8 p9[0x20 - 9];
    s16 t20;
    u8 p22[0x2c - 0x22];
    u16 w2c;
    u16 w2e;
} P800FC414;
extern P800FC414 *D_8009B698_P800FC414Ptr asm("D_8009B698");
extern char D_80077214[];

#define SETANIM_IF(n) \
    D_8009B698_P800FC414Ptr->w2c = n; \
    if (D_8009B698_P800FC414Ptr->w2e != n) { \
        D_8009B698_P800FC414Ptr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_P800FC414Ptr->w2e = D_8009B698_P800FC414Ptr->w2c; \
    }

#define ADD7C() \
    if (*(u8 *)((u8 *)o + 0xad) == 0) \
        o->y.raw += 0x7c000;

#define LAND() \
    if (*(u8 *)((u8 *)o + 0xd1) == 1) { \
        SETANIM_IF(0x55); \
    } else { \
        SETANIM_IF(0x3b); \
    }

#define GROUND() \
    func_8010E444(o); \
    applyObjectAltSpeedVertical(o); \
    if (((s16 (*)(GameObject *))func_800FB5A0)(o)) \
        return; \
    if (((s16 (*)(GameObject *, s32, s32))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole)) { \
        o->touchFlag = 1; \
        o->velY = 0; \
        o->unk9C = 0; \
    }

#define TURN() { \
    u8 x; u32 c; s16 d; u16 u; \
    x = D_80114638[o->unkB0]; \
    c = (u8)(x - o->unk8C); \
    d = c; \
    if (d == 0) return; \
    u = c; \
    if (u < 0x80) { \
        if (d >= 4) o->unk8C = o->unk8C + 4; \
        else if (d >= 2) o->unk8C = o->unk8C + 2; \
        else o->unk8C = o->unk8C + 1; \
    } else { \
        if (d < 0xfd) o->unk8C = o->unk8C - 4; \
        else if (d < 0xff) o->unk8C = o->unk8C - 2; \
        else o->unk8C = o->unk8C - 1; \
    } \
    o->unk8C = *(u8 *)&o->unk8C; }

static __inline__ s32 fall_FB774(GameObject *o)
{
    *(u8 *)((u8 *)o + 0xad) = 0;
    ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0);
    if ((o->touchFlag | o->unk9C | o->unk9E | o->unk9F | o->unkBE) == 0) {
        *(u8 *)((u8 *)o + 0xad) = 1;
        o->velY += 0x223;
        o->y.raw += o->velY << 8;
        D_8009B698_P800FC414Ptr->t20 = 0x21;
        if (o->velY >= 0x447) {
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            *(u8 *)((u8 *)o + 0xad) = 0;
            o->velY = 0;
            o->unk9C = 2;
            *(u8 *)((u8 *)o + 0xc3) = 0;
            o->unk8C = 0;
            return 1;
        }
    } else {
        o->velY = 0;
        o->unk9C = 0;
    }
    return 0;
}

void func_800FB774(GameObject *o)
{
    extern char D_800108A8[];
    s32 t, v;
    s16 r;

    switch (o->unk7) {
    case 0:
        o->movetab = D_80077214;
        o->timer = 0x19;
        o->unk8C = 0;
        o->velX = 0;
        o->velY = 0;
        if (*(u8 *)((u8 *)o + 0xd1) == 1) {
            SETANIM_IF(0x57);
        } else {
            SETANIM_IF(0x10);
        }
        o->unk7++;
    case 1:
        if (o->timer != 0)
            o->timer--;
        tickAnimation(o);
        applyAnimVelocityX(o, (o->animFrame & 1) ^ 1);
        {
            s32 d0 = o->unk8C;
            if (o->animFrame & 1)
                t = (d0 - 0x10) & 0xff;
            else
                t = (d0 + 0x10) & 0xff;
        }
        o->unk8C = t;
        if (o->unkA6 != 0) {
            o->unk8C = 0;
            LAND();
            o->timer = 10;
            o->unk7++;
            break;
        }
        if (o->touchFlag == 0) {
            func_8010E444(o);
            applyObjectAltSpeedVertical(o);
            if (o->timer == 0) {
                o->unk8C = 0;
                LAND();
                o->timer = 10;
                o->unk7++;
            }
            if (((s16 (*)(GameObject *))func_800FB5A0)(o))
                return;
            if (((s16 (*)(GameObject *, s32, s32))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole)) {
                o->touchFlag = 1;
                o->velY = 0;
                o->unk9C = 0;
            }
        } else {
            ADD7C();
            if (o->timer == 0) {
                o->unk8C = 0;
                LAND();
                o->timer = 10;
                o->unk7++;
            } else {
                func_800FE970(o, 0);
            }
            fall_FB774(o);
        }
        break;
    case 2:
        tickAnimation(o);
        if (o->timer != 0 && --o->timer <= 0)
            o->unk7++;
        if (o->touchFlag == 0) {
            GROUND();
        } else {
            ADD7C();
            fall_FB774(o);
        }
        TURN();
        break;
    case 3:
        if (o->touchFlag == 0) {
            GROUND();
        } else {
            ADD7C();
            fall_FB774(o);
        }
        if (D_8009BCA0 == 0) {
            *(u8 *)&o->unkAC = 0;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            SETANIM_IF(0x3d);
            o->unk7++;
        } else {
            if (*(u8 *)((u8 *)o + 0xd1) == 1) {
                SETANIM_IF(0x56);
            } else {
                SETANIM_IF(0x3c);
            }
            o->timer = 0xb4;
            o->unk7 = 5;
        }
        TURN();
        break;
    case 4:
        if (o->touchFlag == 0) {
            GROUND();
        } else {
            ADD7C();
            func_8010E444(o);
            if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
                o->touchFlag = 1;
                o->velY = 0;
            }
            if (((s16 (*)(GameObject *))func_800FB5A0)(o))
                return;
            if (tickAnimation(o)) {
                D_8009B698_P800FC414Ptr->b8 = 0;
                o->active = 3;
                *(s16 *)((u8 *)o + 0xe0) = 0x8c;
                *(u8 *)((u8 *)o + 0xd1) = 0;
                *(s16 *)((u8 *)o + 0xb2) = 0;
                o->state = 1;
                if ((*(s32 *)&GAME) == 0x2000e) {
                    o->subState = 0x3e;
                    o->step = 0;
                    o->unk7 = 0;
                } else if (((*(s32 *)&GAME) & 0x3ffff) == 0x3000a) {
                    r = 0;
                    if (D_8009C62B & 0x40) {
                        if (o->y.p.whole > -0x8c) {
                            r = 1;
                            o->unk56 = -0x8c;
                            if (o->y.p.whole > -0x7c) {
                                if (D_8009C1A5 == 0xff)
                                    r = 2;
                                else
                                    o->y.p.whole = -0x8c;
                            }
                        }
                    } else {
                        if (o->y.p.whole > -0x3c0) {
                            r = 1;
                            o->unk56 = -0x3c0;
                            if (o->y.p.whole > -0x3b0) {
                                if (D_8009C1A5 == 0xff)
                                    r = 2;
                                else
                                    o->y.p.whole = -0x3c0;
                            }
                        }
                    }
                    switch (r) {
                    case 1:
                        o->subState = 0x3d;
                        o->step = 0;
                        o->unk7 = 0;
                        break;
                    case 0:
                        goto reset;
                    case 2:
                        o->subState = 0x3e;
                        o->step = 0;
                        o->unk7 = 0;
                        break;
                    }
                } else {
                reset:
                    o->anim = D_800108A8;
                    readAnimFrameCount(o);
                    o->subState = 0;
                    o->step = 0;
                    o->unk7 = 0;
                }
            }
            fall_FB774(o);
        }
        TURN();
        break;
    case 5:
        o->visible = 1;
        tickAnimation(o);
        if (o->touchFlag == 0) {
            GROUND();
        } else {
            func_8010E444(o);
            if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
                o->touchFlag = 1;
                o->velY = 0;
            }
            if (((s16 (*)(GameObject *))func_800FB5A0)(o))
                return;
            ADD7C();
            fall_FB774(o);
        }
        if (--o->timer == 0) {
            ((u8 *)&GAME)[0x951] = 0;
            D_8009C26E = 0;
            if (*(u16 *)((u8 *)&GAME) != 10 || *(u16 *)(((u8 *)&GAME) + 2) != 0)
                D_8009BCA0 = 2;
            o->unk7++;
        }
        TURN();
        break;
    case 6:
        if (o->touchFlag == 0) {
            GROUND();
        } else {
            ADD7C();
            fall_FB774(o);
        }
        break;
    }
}
#undef SETANIM_IF
#undef ADD7C
#undef LAND
#undef GROUND
#undef TURN

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FC6B8);
typedef struct {
    u8 b0;
    u8 p1[7];
    u8 b8;
    u8 p9[0x2c - 9];
    u16 w2c;
    u16 w2e;
} P800FD358;
extern P800FD358 *D_8009B698_P800FD358Ptr asm("D_8009B698");
extern u8 D_1F8001A4;
extern void func_800224FC(s32, s32, s32, s32);

extern char D_80077244[];
extern void func_80033374(s32, s32, s32);

#define SETANIM_IF(n) \
    D_8009B698_P800FD358Ptr->w2c = n; \
    if (D_8009B698_P800FD358Ptr->w2e != n) { \
        D_8009B698_P800FD358Ptr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_P800FD358Ptr->w2e = D_8009B698_P800FD358Ptr->w2c; \
    }

#define BLINK() \
    if (*(u8 *)((u8 *)o + 0xd1) == 0 && D_8009B698_P800FD358Ptr->b8 == 0) \
        o->visible = D_1F8001F8 & 1;

void func_800FC6B8(GameObject *o)
{
    GameObject *q;

    switch (o->step) {
    case 0:
        o->velY = -0x500;
        o->animFrame = ~o->animFrame & 1;
        o->step++;
    case 1:
        o->unk8C = 0;
        if (o->unk9E != 0) {
            if (o->unk9E == 4 || o->unk9E == 7)
                (*(GameObject **)&D_8009E454)->active = 1;
            q = (*(GameObject **)&D_8009E454);
            if (q->type == 0x21)
                q->unkA7 = 0;
            else
                q->unk6A = 0;
        }
        o->unk9E = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkA7 = 0;
        *(u8 *)((u8 *)o + 0xc3) = 0;
        *(u8 *)((u8 *)o + 0xa2) = 0;
        *(u8 *)((u8 *)o + 0xa3) = 0;
        o->unkB0 = 0;
        D_8009B698_P800FD358Ptr->b8 = 0;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650 = D_800A547C;
            D_8009C650->state = 2;
            D_8009C650->subState = 2;
            D_8009C650->step = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        D_8009B698_P800FD358Ptr->b0 = 0;
        *(u8 *)((u8 *)o + 0xa1) = 0;
        *(s8 *)&o->unkF = -8;
        if (D_1F8001A4 == 0 && o->unk9A != o->unk98) {
            o->unk9A = o->unk98;
            D_8009B698_P800FD358Ptr->b8 = 1;
            D_8009BCD8[0] = o->unk98;
            if (o->unk98 <= 0) {
                D_8009BCAA = 1;
                D_8009BCA0 = 1;
                stopBgm(0);
                playJingle(3);
            }
        }
        D_8009B698_P800FD358Ptr->b8 = D_8009BCA0;
        o->unkA4 = 0;
        o->touchFlag = 0;
        o->movetab = D_80077244;
        o->velV = 0;
        o->timer = 0;
        D_8009B698_P800FD358Ptr->w2e = 0xff;
        switch (*(u8 *)((u8 *)o + 0xd1)) {
        case 1:
            SETANIM_IF(0x53);
            func_80033374(9, 0, 0);
            break;
        case 3:
            SETANIM_IF(0x50);
            o->timer = 0x3c;
            break;
        default:
            SETANIM_IF(0x39);
            break;
        }
        o->y.raw += o->velY << 8;
        if (o->active != 1)
            func_800224FC(3, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        playSFXWithNote(0x23, 0x24);
        playSFX(0x1f);
        func_80028A74(0, 0x81, 0x81, 0x3c);
        o->visible = 1;
        o->step++;
    case 2:
        if (*(u8 *)((u8 *)o + 0xd1) == 3) {
            tickAnimation(o);
            if (--o->timer > 0)
                break;
            SETANIM_IF(0x39);
        }
        o->step++;
        break;
    case 3:
        BLINK();
        tickAnimation(o);
        if (o->touchFlag == 0 && !(o->animFrame & 2))
            applyAnimVelocityX(o, o->animFrame ^ 1);
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->velY += 0x40;
        o->y.raw += o->velY << 8;
        if (o->velY > 0) {
            if (*(u8 *)((u8 *)o + 0xd1) == 1) {
                SETANIM_IF(0x54);
            } else {
                SETANIM_IF(0x3a);
            }
            o->unk9C = 2;
            o->step++;
        }
        if (clampToCeilingAndProbeSides(o)) {
            if (*(u8 *)((u8 *)o + 0xd1) == 1) {
                SETANIM_IF(0x54);
            } else {
                SETANIM_IF(0x3a);
            }
            o->unk9C = 2;
            o->velY = 0;
            o->step = 4;
        }
        break;
    case 4:
        BLINK();
        tickAnimation(o);
        if (o->touchFlag == 0 && !(o->animFrame & 2))
            applyAnimVelocityX(o, o->animFrame ^ 1);
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (((s16 (*)(GameObject *))func_800FB5A0)(o) == 0) {
            if (o->touchFlag == 1 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
                if (*(u8 *)((u8 *)o + 0xd1) == 1) {
                    SETANIM_IF(0x55);
                } else {
                    SETANIM_IF(0x3b);
                }
                o->state = 2;
                o->subState = 0;
                o->step = 5;
                o->unk7 = 0;
            }
        }
        break;
    case 5:
        BLINK();
        func_800FB774(o);
        break;
    }
}
#undef SETANIM_IF
#undef BLINK

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FCEDC);
typedef struct {
    u8 b0;
    u8 p1[7];
    u8 b8;
    u8 p9[0x2c - 9];
    u16 w2c;
    u16 w2e;
} P800FDB7C;
extern P800FDB7C *D_8009B698_P800FDB7CPtr asm("D_8009B698");
extern u8 D_1F8001A4;

#define SETANIM_IF(n) \
    D_8009B698_P800FDB7CPtr->w2c = n; \
    if (D_8009B698_P800FDB7CPtr->w2e != n) { \
        D_8009B698_P800FDB7CPtr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_P800FDB7CPtr->w2e = D_8009B698_P800FDB7CPtr->w2c; \
    }

#define BLINK() \
    if (D_8009B698_P800FDB7CPtr->b8 == 0) \
        o->visible = D_1F8001F8 & 1;

void func_800FCEDC(GameObject *o)
{
    GameObject *q;
    s16 vx;

    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->unkB0 = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkA7 = 0;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650 = D_800A547C;
            D_8009C650->state = 2;
            D_8009C650->subState = 2;
            D_8009C650->step = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        D_8009B698_P800FDB7CPtr->b0 = 0;
        D_8009B698_P800FDB7CPtr->b8 = 0;
        *(u8 *)((u8 *)o + 0xc3) = 0;
        if (D_1F8001A4 == 0 && o->unk9A != o->unk98) {
            o->unk9A = o->unk98;
            D_8009B698_P800FDB7CPtr->b8 = 1;
            D_8009BCD8[0] = o->unk98;
            if (o->unk98 <= 0) {
                D_8009BCAA = 1;
                D_8009BCA0 = 1;
                stopBgm(0);
                playJingle(3);
            }
        }
        D_8009B698_P800FDB7CPtr->b8 = D_8009BCA0;
        o->animFrame &= 1;
        if (o->unk9E != 0) {
            if (o->unk9E == 4 || o->unk9E == 7)
                (*(GameObject **)&D_8009E454)->active = 1;
            q = (*(GameObject **)&D_8009E454);
            if (q->type == 0x21)
                q->unkA7 = 0;
            else
                q->unk6A = 0;
        }
        *(u8 *)((u8 *)o + 0xa1) = 0;
        *(s8 *)&o->unkF = -8;
        o->unk9E = 0;
        o->unkA4 = 0;
        o->touchFlag = 0;
        o->velY = 0;
        o->velV = 0;
        SETANIM_IF(0x1e);
        o->step = 1;
        func_800224FC(3, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        playSFXWithNote(0x23, 0x24);
        func_80028A74(0, 0x81, 0x81, 0x3c);
    case 1:
        BLINK();
        SETANIM_IF(0x1e);
        tickAnimation(o);
        break;
    case 2:
        tickAnimation(o);
        vx = 0x200;
        o->unk8C = 0;
        o->velY = -0x400;
        o->velV = 0;
        if (o->animFrame & 1)
            vx = -0x200;
        o->velX = vx;
        o->step++;
        if (D_8009BCA0 == 1) {
            o->state = 2;
            o->subState = 3;
            o->step = 0;
            break;
        }
    case 3:
        BLINK();
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        tickAnimation(o);
        o->velY += 0x20;
        o->y.raw += o->velY << 8;
        if (o->unkA6)
            o->velX = 0;
        if (o->touchFlag == 0)
            o->h->raw += o->velX << 8;
        if (o->velY > 0) {
            o->step = 4;
            o->unk9C = 2;
        }
        if (clampToCeilingAndProbeSides(o)) {
            o->unk9C = 2;
            o->velY = 0;
            o->step = 4;
        }
        break;
    case 4:
        BLINK();
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (((s16 (*)(GameObject *))func_800FB5A0)(o) == 0) {
            if (o->unkA6)
                o->velX = 0;
            if (o->touchFlag == 0) {
                o->h->raw += o->velX << 8;
                if (o->touchFlag == 0 && ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0) == 0)
                    break;
            }
            o->unk7 = 0;
            o->animFrame ^= 1;
            o->step++;
        }
        break;
    case 5:
        BLINK();
        func_800FB774(o);
        break;
    }
}
#undef SETANIM_IF
#undef BLINK

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FD49C);
typedef struct {
    u8 b0;
    u8 p1[7];
    u8 b8;
    u8 p9[5];
    s16 wE;
    u8 p10[0x2c - 0x10];
    u16 w2c;
    u16 w2e;
} P800FE13C;

typedef struct {
    u8 pad[0xe0];
    s16 we0;
    u8 pad2[0xec - 0xe2];
    s16 wec, wee, wf0, wf2;
} X800FE13C_FD49C;
extern u8 D_8009CF06[];
typedef struct { u16 c960, c962; char pad[0x5a2]; u8 cf06; } G960_FD49C;
extern G960_FD49C GAME_G960_FD49C asm("GAME");
extern char D_80010B64[];
extern char D_80011818[];

typedef struct { s32 a[90]; } AnimTable_FD49C;

static __inline__ void SetAnimFromTable_FD49C(GameObject *o)
{
    extern P800FE13C *D_8009B698;
    AnimTable_FD49C t = (*(AnimTable_FD49C *)&D_800E7764);
    o->anim = (void *)t.a[D_8009B698->w2c];
}

void func_800FD49C(GameObject *o)
{
    extern P800FE13C *D_8009B698;
    GameObject *q;
    s16 d;
    s32 a1;
    s32 a2;
    s16 v;
    P800FE13C *p;
    u16 f;
    u8 *cp;
    u8 t;

    switch (o->step) {
    case 0:
        o->timer = 0x40;
        *(s8 *)&o->unkF = -8;
        p = D_8009B698;
        v = -0x10;
        if (o->animFrame & 1)
            v = 0x10;
        p->wE = v;
        o->unk88 = 0x400;
        o->unk8C = 0;
        if (o->unk9E != 0) {
            if (o->unk9E == 4 || o->unk9E == 7)
                (*(GameObject **)&D_8009E454)->active = 1;
            q = (*(GameObject **)&D_8009E454);
            if (q->type == 0x21)
                q->unkA7 = 0;
            else
                q->unk6A = 0;
        }
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkA7 = 0;
        o->unk9E = 0;
        o->unkA4 = 0;
        o->unkB0 = 0;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650 = D_800A547C;
            D_8009C650->state = 2;
            D_8009C650->subState = 2;
            D_8009C650->step = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        D_8009B698->b0 = 0;
        o->animFrame &= 1;
        o->active = 4;
        o->velY = -0x800;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc3) = 0;
        o->visible = 1;
        o->touchFlag = 0;
        o->velV = 0;
        a1 = *(s16 *)((u8 *)o + 0xee) - ((s16 *)o->h)[1];
        d = a1;
        d <<= 2;
        *(s16 *)((u8 *)o + 0x80) = d;
        *(s16 *)((u8 *)o + 0xe0) = 0x8c;
        *(u8 *)((u8 *)o + 0xa1) = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        a2 = *(s16 *)((u8 *)o + 0xf2) - o->y.p.whole;
        d = a2;
        d <<= 2;
        *(s16 *)((u8 *)o + 0x82) = d;
        D_8009B698->w2c = 0x10;
        D_8009B698->w2e = 0x10;
        o->anim = D_80010B64;
        advanceAnimFrame(o, 0);
        func_800224FC(3, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        playSFXWithNote(0x23, 0x24);
        func_80028A74(0, 0x81, 0x81, 0x3c);
        o->step = 1;
        break;
    case 1:
        o->unk8C = (u8)o->unk88;
        o->unk88 += D_8009B698->wE;
        applyObjectSpeedXY(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (o->velY > 0x680)
            o->velY = 0x680;
        clampToCeilingAndProbeSides(o);
        if (--o->timer < 0x10) {
            o->anim = D_80010B64;
            advanceAnimFrame(o, 0);
        }
        if (o->timer == 0) {
            D_8009B698->wE = 0;
            o->h->raw = *(s32 *)((u8 *)o + 0xec);
            o->y.raw = *(s32 *)((u8 *)o + 0xf0);
            if (D_8009B698->b8) {
                *(s16 *)((u8 *)o + 0xe0) = 0x8c;
                o->active = 3;
            }
            if (*(s16 *)((u8 *)o + 0xe0) == 0)
                *(s16 *)((u8 *)o + 0xe0) = 0x8c;
            o->active = 3;
            if (D_8009BCA0) {
                D_8009B698->b8 = 0;
                o->timer = 0xb4;
                o->step = 2;
            } else if (*(u8 *)((u8 *)o + 0xd1) == 2) {
                o->h->p.whole = ((X800FE13C_FD49C *)o)->wee;
                o->timer = 10;
                o->step = 4;
                o->y.p.whole = ((X800FE13C_FD49C *)o)->wf2;
            } else {
                o->step = 9;
            }
            o->touchFlag = 0;
            o->unkB2 = 0;
            o->velH = 0;
            o->velV = 0;
            o->velX = 0;
            o->velY = 0;
        }
        break;
    case 2:
        *(u8 *)((u8 *)o + 0xc7) = 1;
        D_8009B698->w2c = 0x3c;
        SetAnimFromTable_FD49C(o);
        advanceAnimFrame(o, 1);
        if (--o->timer == 0) {
            o->step = 3;
            GAME_G960_FD49C.cf06 = 0;
            D_8009C619_U8Arr[0] = 0;
            if (GAME_G960_FD49C.c960 != 10 || GAME_G960_FD49C.c962 != 0)
                D_8009BCA0 = 2;
        }
        break;
    case 4:
        o->unk8C = (u8)o->unk88;
        o->unk88 += D_8009B698->wE;
        o->y.raw += 0x50000;
        if (o->touchFlag || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            o->unk8C = 0;
            o->step++;
        }
        if (--o->timer <= 0) {
            o->unk8C = 0;
            o->step = 9;
        }
        func_800FE970(o, 0);
        break;
    case 5:
        o->anim = D_80011818;
        advanceAnimFrame(o, 0);
        o->step++;
    case 6:
        o->y.raw += 0x50000;
        if (tickAnimation(o))
            o->step = 9;
        ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0);
        func_800FE970(o, 0);
        break;
    case 9:
        *(u8 *)((u8 *)o + 0xd1) = 0;
        D_8009B698->b8 = 0;
        t = D_80114638[o->unkB0];
        o->state = 1;
        o->subState = 2;
        o->step = 3;
        o->unk8C = t;
        break;
    case 3:
    case 7:
    case 8:
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FDABC);
void func_800FDABC(GameObject *o)
{
    u8 *p;
    switch (o->step) {
    case 0:
        if (o->unk9E != 0 && (o->unk9E == 4 || o->unk9E == 7)) *D_8009E454 = 1;
        p = &D_8009BCA0;
        if (*p != 1) {
            D_8009BCAA = 1;
            *p = 1;
            stopBgm(0);
            playJingle(3);
        }
        o->timer = 0xb4;
        *(s8 *)&o->unkF = -8;
        o->visible = 1;
        o->step++;
        break;
    case 1:
        if (--o->timer == 0) {
            D_8009C619 = 0;
            D_8009C26E = 0;
            if ((*(u16 *)&GAME) != 10 || D_8009BCCA != 0)
                D_8009BCA0 = 2;
            o->step++;
        }
        break;
    case 99:
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FDBEC);
typedef struct {
    u8 active, b1, b2, b3, b04, step, state, substep;
    char p08[0x20 - 8]; s16 timer; char p22[0x2e - 0x22]; u16 frame;
    char p30[0x84 - 0x30]; s32 d84; s32 d88; s32 d8c;
    char p90[0x9c - 0x90]; u8 b9c; char p9d[0xac - 0x9d]; u8 bac;
    char pad[0xd1 - 0xad]; u8 bd1; char pd2[0xe0 - 0xd2]; s16 we0;
} O_FDBEC;
typedef struct { char p[8]; u8 b; } G_FDBEC;
void func_800FDBEC(O_FDBEC *o)
{
    extern G_FDBEC *D_8009B698;
    s32 x;
    D_8009B698->b = 0;
    o->we0 = 0x8c;
    o->active = 3;
    o->b9c = 2;
    o->bac = 1;
    o->bd1 = 0;
    o->timer = 10;
    o->d84 = 0;
    x = 0x10;
    if (o->frame & 1) x = 0xf0;
    o->d88 = x;
    o->d8c = 0;
    o->b04 = 1;
    o->step = 2;
    o->state = 3;
    o->substep = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FDC58);
typedef struct { char pad[8]; u8 b8; } P_FDC58;

void func_800FDC58(GameObject *o)
{
    extern P_FDC58 *D_8009B698;
    o->h->raw += D_8009BCAC << 8;
    o->y.raw += D_8009BCAE[0] << 8;
    if (D_8009B698->b8 == 0) {
        o->visible = *(u8 *)0x1F8001F8 & 1;
    }
    o->h->raw += o->velX << 8;
    o->y.raw += o->velY << 8;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FDCEC);
typedef struct {
    u8 b0;
    u8 p1[7];
    u8 b8;
    u8 p9[0x2c - 9];
    u16 w2c;
    u16 w2e;
} P800FE98C;
extern P800FE98C *D_8009B698_P800FE98CPtr asm("D_8009B698");
extern u8 D_1F8001A4_U8Arr[] asm("D_1F8001A4");

#define SETANIM_IF(n) \
    D_8009B698_P800FE98CPtr->w2c = n; \
    if (D_8009B698_P800FE98CPtr->w2e != n) { \
        D_8009B698_P800FE98CPtr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_P800FE98CPtr->w2e = D_8009B698_P800FE98CPtr->w2c; \
    }

#define BLINK() \
    if (D_8009B698_P800FE98CPtr->b8 == 0) \
        o->visible = D_1F8001F8 & 1;

static __inline__ void move_FDCEC(GameObject *o)
{
    o->h->raw += D_8009BCAC << 8;
    o->y.raw += D_8009BCAE[0] << 8;
    BLINK();
    o->h->raw += o->velX << 8;
    o->y.raw += o->velY << 8;
}

#define LAND() { \
    s32 d = 0x10; s32 c3 = 3; s32 c2 = 2; s32 c1 = 1; \
    D_8009B698_P800FE98CPtr->b8 = 0; \
    o->active = c3; \
    *(s16 *)((u8 *)o + 0xe0) = 0x8c; \
    o->unk9C = c2; \
    *(u8 *)((u8 *)o + 0xac) = c1; \
    *(u8 *)((u8 *)o + 0xd1) = 0; \
    o->timer = 10; \
    o->unk84 = 0; \
    if (o->animFrame & 1) \
        d = 0xf0; \
    o->unk88 = d; \
    o->unk8C = 0; \
    o->state = c1; \
    o->subState = c2; \
    o->step = c3; \
    o->unk7 = 0; }

void func_800FDCEC(GameObject *o)
{
    s16 vx;

    switch (o->step) {
    case 0:
        vx = 0x200;
        if (o->animFrame & 1)
            vx = -0x200;
        o->unk9C = 1;
        o->velX = vx;
        o->velY = 0;
        *(u8 *)((u8 *)o + 0xc3) = 0;
        o->timer = 0x14;
        o->step++;
    case 1:
        o->visible = 1;
        SETANIM_IF(0x2e);
        playSFXWithNote(0x23, 0x24);
        playSFX(0x1f);
        o->unk9C = 1;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650 = D_800A547C;
            D_8009C650->state = 2;
            D_8009C650->subState = 2;
            D_8009C650->step = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        D_8009B698_P800FE98CPtr->b0 = 0;
        o->unk8C = 0;
        if (o->unk9E != 0)
            (*(GameObject **)&D_8009E454)->unk6A = 0;
        o->unk9E = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkA7 = 0;
        o->unkB0 = 0;
        D_8009B698_P800FE98CPtr->b8 = 0;
        *(s8 *)&o->unkF = -8;
        o->unkA4 = 0;
        o->touchFlag = 0;
        o->velV = 0;
        o->step++;
        if (D_1F8001A4_U8Arr[0] == 0 && o->unk9A != o->unk98) {
            o->unk9A = o->unk98;
            D_8009B698_P800FE98CPtr->b8 = 1;
            D_8009BCD8[0] = o->unk98;
            if (o->unk98 <= 0) {
                D_8009BCAA = 1;
                D_8009BCA0 = 1;
                stopBgm(0);
                playJingle(3);
            }
        }
        D_8009B698_P800FE98CPtr->b8 = D_8009BCA0;
        func_800224FC(3, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        func_80028A74(0, 0x81, 0x81, 0x3c);
        break;
    case 2:
        move_FDCEC(o);
        if (tickAnimation(o)) {
            SETANIM_IF(0x10);
            o->step = 3;
        }
        break;
    case 3:
        move_FDCEC(o);
        o->unk8C = (o->unk8C + (o->animFrame & 1 ? 0x10 : -0x10)) & 0xff;
        tickAnimation(o);
        if (--o->timer <= 0)
            o->step++;
        if (D_8009B698_P800FE98CPtr->b8 != 0)
            break;
        if (o->velY > 0) {
            LAND();
        }
        if (clampToCeilingAndProbeSides(o)) {
            LAND();
        }
        break;
    case 4:
        move_FDCEC(o);
        tickAnimation(o);
        o->velY += 0x40;
        if (o->velY > 0x680)
            o->velY = 0x680;
        if (o->touchFlag != 0 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0) != 0) {
            o->unk9C = 0;
            o->unk7 = 0;
            o->animFrame ^= 1;
            o->step++;
        }
        if (D_8009B698_P800FE98CPtr->b8 != 0)
            break;
        if (o->velY > 0) {
            LAND();
        }
        break;
    case 5:
        BLINK();
        func_800FB774(o);
        break;
    }
}
#undef SETANIM_IF
#undef BLINK
#undef LAND

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FE3D4);
extern u8 D_8009C363;
extern u8 D_8009C114;

s32 func_800FE3D4(void)
{
    s16 t = D_8009C363 != 0;
    s16 r;
    r = t;
    if (D_8009C114 == 0xff) r = t + 1;
    if ((*(u16 *)&GAME) == 0 && D_8009BCCA < 2) r = 0;
    if (D_8009BCF8 == 1) r = 0;
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FE448);
extern u8 D_8009C3E0[];

void func_800FE448(GameObject *o)
{
    u8 s = o->subState;
    s16 c;
    if (s == 0x3d || s == 0x3e || s == 0x42 || s == 0x43 || s == 0x44 || s == 0x47 || s == 0x48)
        return;
    switch ((*(u16 *)&GAME)) {
    case 0:
        if (D_8009BCCA == 5) {
            o->unk56 = -0x100;
            if ((u16)(o->h->p.whole - 0xec) < 0x1cc) {
                c = o->y.p.whole < (-0xff);
                goto tail;
            }
        }
        break;
    case 1:
        if (D_8009BCCA == 2) {
            o->unk56 = -0xb1;
            if ((u16)(o->h->p.whole - 0x128) < 0x5e0) {
                c = o->y.p.whole < (-0xb0);
                goto tail;
            }
        }
        break;
    case 4:
    case 12:
        switch (D_8009BCCA) {
        case 4:
            o->unk56 = -0x13;
            if ((u16)(o->h->p.whole - 0x2f) < 0xf9) {
                c = o->y.p.whole < (-0x12);
                goto tail;
            }
            break;
        case 6:
            o->unk56 = -0x39;
            if ((u16)(o->h->p.whole - 0x87) < 0x19f) {
                c = o->y.p.whole < (-0x38);
                goto tail;
            }
            break;
        case 7:
            o->unk56 = -0x1d;
            if ((u16)(o->h->p.whole - 0x97) < 0x1bd) {
                c = o->y.p.whole < (-0x1c);
                goto tail;
            }
            break;
        case 8:
            o->unk56 = -0xa3;
            if ((u16)(o->h->p.whole + 0x10) < 0x94) {
                c = o->y.p.whole < (-0xa2);
                goto tail;
            }
            break;
        case 16:
            c = o->y.p.whole < (-0x15);
            o->unk56 = -0x16;
                goto tail;
            break;
        }
        break;
    case 10:
        switch (D_8009BCCA) {
        case 1:
        case 5:
            o->unk56 = -0xe4;
            if (D_8009C3E0[0] == 4) {
                c = o->y.p.whole < (-0xe3);
                goto tail;
            } else {
                ((u8 *)&o->unkA0)[1] = 0;
            }
            break;
        case 3:
        case 7:
            if ((u16)(o->h->p.whole - 0x71) < 0x726) {
                if (D_8009C62B & 0x40) {
                    c = o->y.p.whole < (-0x8b);
                    o->unk56 = -0x8c;
                goto tail;
                } else {
                    c = o->y.p.whole < (-0x3bf);
                    o->unk56 = -0x3c0;
                goto tail;
                }
            }
            break;
        }
        break;
    tail:
        if (c) {
            D_8009BCAC = 0;
            (*(s16 *)&D_8009BCAE) = 0;
            break;
        }
        goto els;
    case 14:
        if (D_8009BCCA == 2) {
            o->y.p.whole = -0xe4;
        els:
            D_8009BCAC = 0;
            (*(s16 *)&D_8009BCAE) = -0x40;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FE764);
s16 func_800FE764(GameObject *o, s16 r)
{
    switch (D_8009BCF8 & 3) {
    case 0:
        r = 1;
        if ((*(s32 *)&GAME) == 0x20003) r = 2;
        if ((*(s32 *)&GAME) == 10) r = (o->h->p.whole < 0xc80) * 2;
        if ((*(s32 *)&GAME) == 0x3000a) r = 2;
        break;
    case 1:
        r = 2;
        if ((*(s32 *)&GAME) == 0x20000) r = 1;
        if ((*(s32 *)&GAME) == 0x30001) r = 1;
        if ((*(s32 *)&GAME) == 0x20003) r = 0;
        if ((*(s32 *)&GAME) == 10 && o->h->p.whole > 0xc80) r = 0;
        if ((*(s32 *)&GAME) == 0x3000a) r = 2;
        break;
    case 2:
        r = (*(s32 *)&GAME) == 0x20000;
        if ((*(s32 *)&GAME) == 0x30001) r = 1;
        if ((*(s32 *)&GAME) == 0x20003) r = 6;
        if ((*(s32 *)&GAME) == 10 && o->h->p.whole < 0xc80) r = 2;
        if ((*(s32 *)&GAME) == 0x3000a) r = 1;
        break;
    case 3:
        r = 2;
        if ((*(s32 *)&GAME) == 0x20003) r = 4;
        if ((*(s32 *)&GAME) == 10 && o->h->p.whole < 0xc80) r = 4;
        if ((*(s32 *)&GAME) == 0x3000a) r = 4;
        break;
    }
    return r;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FE970);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FF224);
typedef struct {
    u8 b0;
    u8 p1[7];
    u8 b8;
    u8 p9[0x20 - 9];
    s16 w20;
    u8 p22[0x28 - 0x22];
    u16 w28, w2a, w2c, w2e;
} P800FFEC4_FF224;
typedef struct {
    u8 p0[0xc6];
    u8 c6, c7;
    u8 p8[0xcd - 0xc8];
    u8 cd, ce;
    u8 pf[0xd3 - 0xcf];
    u8 d3;
    u8 pd4[0xe0 - 0xd4];
    s16 e0;
    u8 e2, e3;
} X800FFEC4_FF224;
extern P800FFEC4_FF224 *D_8009B698_P800FFEC4_FF224Ptr asm("D_8009B698");
extern u8 D_8009BCA8_U8Arr[] asm("D_8009BCA8");
extern u8 D_8009BCA9;
extern u8 D_8009C1BD;
extern u8 D_8009C1BE;
extern u8 D_8009C1BF;
extern u8 D_8009C24A;
extern u8 D_8009C26B;
extern u8 D_8009C134;
extern void func_800EBBAC(s32);
extern void removeItemFromInventory(s32, s32);
extern void spawnEffectObject(s32, s32, s32, s32);

#define SETANIM_IF(n) \
    D_8009B698_P800FFEC4_FF224Ptr->w2c = n; \
    if (D_8009B698_P800FFEC4_FF224Ptr->w2e != n) { \
        D_8009B698_P800FFEC4_FF224Ptr->w2c = n; \
        func_800EEF64(o); \
        advanceAnimFrame(o, 0); \
        D_8009B698_P800FFEC4_FF224Ptr->w2e = D_8009B698_P800FFEC4_FF224Ptr->w2c; \
    }

static __inline__ void sub_FF224(GameObject *o)
{
    ((X800FFEC4_FF224 *)o)->c7 = 1;
    o->unk9D = 0;
    ((X800FFEC4_FF224 *)o)->c6 = 0;
    ((X800FFEC4_FF224 *)o)->e3 = 0;
    D_8009B698_P800FFEC4_FF224Ptr->b0 = 0;
}

static __inline__ void reset_FF224(GameObject *o)
{
    if (*(u8 *)&o->unkAC >= 2) {
        (*(u8 **)&D_8009C650) = (*(u8 **)&D_800A547C);
        (*(u8 **)&D_800A547C)[4] = 2;
        (*(u8 **)&D_8009C650)[5] = 2;
        (*(u8 **)&D_8009C650)[6] = 0;
    }
    *(u8 *)&o->unkAC = 0;
    D_8009BC9C = 0;
    sub_FF224(o);
}

void func_800FF224(GameObject *o)
{
    extern char D_800108A8[];
    s16 s;
    s32 k;

    switch (o->step) {
    case 0:
        ((X800FFEC4_FF224 *)o)->cd = 0;
        ((X800FFEC4_FF224 *)o)->ce = 0;
        o->unkA4 = 0;
        o->unkA5 = 0;
        o->unkA7 = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        D_8009B698_P800FFEC4_FF224Ptr->w20 = 0;
        o->cooldownTimer = 0;
        reset_FF224(o);
        D_8009B698_P800FFEC4_FF224Ptr->b8 = 0;
        o->unk9C = 0;
        o->visible = 1;
        sub_FF224(o);
        if ((((s32 *)&GAME)[0] & 0x3ffff) != 0x3000a) {
            o->anim = D_800108A8;
            advanceAnimFrame(o, 0);
            D_8009B698_P800FFEC4_FF224Ptr->w2e = 0xffff;
            D_8009B698_P800FFEC4_FF224Ptr->w28 = 0xffff;
            D_8009B698_P800FFEC4_FF224Ptr->w2a = 0xffff;
        }
        o->step++;
    case 1:
        if (((X800FFEC4_FF224 *)o)->e0 == 0) o->active = 1;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        if ((((s32 *)&GAME)[0] & 0x3ffff) == 0x3000a) {
            s = -0x3c0;
            if (D_8009C62B & 0x40) s = -0x8c;
            if (o->y.p.whole > s) {
                o->state = 1;
                o->subState = 0x3e;
                o->step = 0;
            }
        }
        if (((s32 *)&GAME)[0] == 0x2000e) {
            o->state = 1;
            o->subState = 0x3e;
            o->step = 0;
        }
        k = ((X800FFEC4_FF224 *)o)->d3;
        o->unk8C = D_80114638[o->unkB0];
        if (k < 0x65) if (k >= 0x62) {
            func_800EBBAC(k - 0x62);
            ((X800FFEC4_FF224 *)o)->d3 = 0;
            if (*((u8 *)&o->unkA0 + 1) == 2) {
                *((u8 *)&o->unkA0 + 1) = 0;
            } else if (((s32 *)&GAME)[0] != 0x2000e) {
                D_8009BCA7 = 1;
                D_8009BCAA = 1;
                o->state = 1;
                o->subState = 0x30;
                o->step = 3;
                o->timer = 0x50;
            }
        }
        *((u8 *)&o->unkA0 + 1) = 0;
        if (D_8009BCA8_U8Arr[0] == 0) return;
        ((X800FFEC4_FF224 *)o)->e2 = D_8009BCA9;
        switch (D_8009BCA9) {
        case 4:
            D_8009BCA8_U8Arr[0] = 0;
            D_8009BC98[0] = 3;
            SETANIM_IF(0);
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_8009BCA6 = 1;
            break;
        case 0x7d:
            removeItemFromInventory(D_8009BCA9, 1);
            break;
        case 0x75:
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            removeItemFromInventory(D_8009BCA9, 1);
            break;
        case 3:
            if (*(u16 *)((s32 *)&GAME) != 0) break;
            SETANIM_IF(0);
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_8009BCA6 = 1;
            break;
        case 9:
            D_8009BCA8_U8Arr[0] = 0;
            D_8009C619 = 0;
            removeItemFromInventory(D_8009BCA9, 1);
            break;
        case 10:
            D_8009BCA8_U8Arr[0] = 0;
            if (((s32 *)&GAME)[0] == 0x30001 && D_8009C1BD < 3) {
                spawnEffectObject(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            }
            break;
        case 0x12:
            D_8009BCA8_U8Arr[0] = 0;
            if (((s32 *)&GAME)[0] != 1) break;
            if (D_8009C1BD >= 2) break;
            if ((u16)(o->h->p.whole - 0x74b) >= 0xf0) break;
            spawnEffectObject(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_8009BCA6 = 1;
            break;
        case 5: case 0x7c: case 0x97: case 0x98:
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            (*(u8 *)&D_8009C618) = 3;
            o->state = 5;
            o->subState = 5;
            o->step = 0;
            o->unk7 = 1;
            o->buffSize = 1;
            break;
        case 7:
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            (*(u8 *)&D_8009C618) = 3;
            o->state = 5;
            o->subState = 5;
            o->step = 0;
            o->unk7 = 0;
            removeItemFromInventory(D_8009BCA9, 1);
            o->buffSize = 1;
            break;
        case 0x10:
            D_8009BCA8_U8Arr[0] = 0;
            if (D_8009C1BE != 0xff) {
                D_8009BCAA = 1;
                D_8009BCA7 = 1;
                D_8009C24A = 1;
            }
            break;
        case 0x82:
            *((u8 *)&o->unkAA + 1) |= 0x80;
            switch (D_8009C619) {
            case 1: o->subState = 0x2a; break;
            case 2: o->subState = 0x2b; break;
            }
            o->step = 0;
            break;
        case 0x3c:
            SETANIM_IF(0);
            break;
        case 0x11:
            D_8009C1BF = 4;
            removeItemFromInventory(D_8009BCA9, 1);
        case 0x3f: case 0x9a:
        c3f:
            D_8009BCA8_U8Arr[0] = 0;
            break;
        case 0x14:
            func_8002F138();
            goto c3f;
        case 0x8d:
            D_8009BCA8_U8Arr[0] = 0;
            removeItemFromInventory(D_8009BCA9, 1);
            D_8009C26B = 3;
            break;
        case 0xd: case 0x8a:
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_8009BCA6 = 1;
            break;
        case 0x5c:
            SETANIM_IF(0);
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            break;
        case 0xc:
            D_8009BCA8_U8Arr[0] = 0;
            if (((s32 *)&GAME)[0] == 9 && D_8009C134 != 0xff) {
                spawnEffectObject(0, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            }
            break;
        case 0xe:
            o->unkA4 = 0;
            o->unkA5 = 0;
            o->unk9C = 1;
            o->visible = 1;
            o->unkA7 = 0;
            o->active = 4;
            o->buffSize = 1;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            D_8009B698_P800FFEC4_FF224Ptr->w20 = 0;
            o->unk8C = 0;
            o->timer = 0x1e;
            o->cooldownTimer = 0;
            reset_FF224(o);
            (*(u8 *)&D_8009C618) = 3;
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            o->subState = 0x30;
            o->unk8C = 0;
            o->state = 1;
            o->step = 2;
            break;
        }
        break;
    case 2:
        break;
    case 3:
        if (--o->timer > 0) break;
        D_8009BCA7 = 0;
        D_8009BCAA = 0;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        break;
    }
}
#undef SETANIM_IF

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_800FFAE8);
extern void func_8010B384(GameObject *);
extern void func_80108D08(GameObject *);
extern void func_80105A14(GameObject *);
extern void func_80106928(GameObject *);
extern void func_80107A58(GameObject *);
extern void func_8010633C(GameObject *);
extern void func_801091A0(GameObject *);
extern void func_80122258(GameObject *);
extern void func_80106F50(GameObject *);
extern void func_80108B3C(GameObject *);
extern void func_80122B1C(GameObject *);
extern void func_80120E90(GameObject *);
extern void func_8010731C(GameObject *);
extern void func_80120AC8(GameObject *);
extern void func_80121748(GameObject *);
extern void func_8010BD68(GameObject *);
extern void func_8011CB24(GameObject *);
extern void func_8011D9CC(GameObject *);
extern void func_8011D1A8(GameObject *);
extern void func_8011D41C(GameObject *);
extern void func_801210A4(GameObject *);
extern void func_8012137C(GameObject *);
extern void func_80105EA0(GameObject *);
extern void func_80106100(GameObject *);
extern void func_80101D58(GameObject *);
extern void func_80107E20(GameObject *);
extern void func_8011D6A8(GameObject *);
extern void func_8011DA00(GameObject *);
extern void func_80121F54(GameObject *);
extern void func_8011DE38(GameObject *);
extern void func_8011CF50(GameObject *);
extern void func_8011CCE8(GameObject *);
extern void func_801062E8(GameObject *);
extern void func_8010C6E0(GameObject *);
extern void func_8010CBD8(GameObject *);
extern void func_8011A650(GameObject *);
extern void func_8011AAF4(GameObject *);
extern void func_8010CE5C(GameObject *);
extern void func_8010D0DC(GameObject *);
extern void func_8010D9BC(GameObject *);
extern void func_8011B1CC(GameObject *);
extern void func_8011A4B4(GameObject *);
extern void probeTileShapeThreePoints(GameObject *, s32);

static __inline__ void dirA_FFAE8(GameObject *o)
{
    u16 f = o->animFrame & 1;
    volatile u16 *k = &D_8009C9D8;
    u16 v;
    o->animFrame = f;
    if (*k & 0x20) {
        o->animFrame = 0;
    } else {
        if (*k & 0x80) v = 1; else v = f | 2;
        o->animFrame = v;
    }
}

static __inline__ void dirF_FFAE8(GameObject *o)
{
    volatile u16 *k = &D_8009C9D8;
    if (*k & 0x10) o->animFrame |= 8;
    if (*k & 0x40) o->animFrame |= 4;
}

static __inline__ void dirC_FFAE8(GameObject *o)
{
    volatile u16 *k = &D_8009C9D8;
    u16 f = o->animFrame & 1;
    o->animFrame = f;
    if (*k & 0x10) {
        if (*k & 0x80) o->animFrame = 5;
        else if (*k & 0x20) o->animFrame = 4;
        else if (f) o->animFrame = 7;
        else o->animFrame = 6;
    } else {
        if (*k & 0x80) o->animFrame = 3;
        else if (*k & 0x20) o->animFrame = 2;
        else if (f) o->animFrame = 3;
        else o->animFrame = 2;
    }
}

static __inline__ void dirD_FFAE8(GameObject *o)
{
    volatile u16 *k = &D_8009C9D8;
    u16 f = o->animFrame & 1;
    o->animFrame = f;
    if (*k & 0x10) {
        if (*k & 0x80) o->animFrame = 5;
        else if (*k & 0x20) o->animFrame = 4;
        else if (f) o->animFrame = 7;
        else o->animFrame = 6;
    } else {
        if (*k & 0x80) o->animFrame = 1;
        else if (*k & 0x20) o->animFrame = 0;
        else if (f) o->animFrame = 3;
        else o->animFrame = 2;
    }
}

static __inline__ void turn_FFAE8(GameObject *o)
{
    s32 a = o->unk8C;
    u32 c = (u8)(D_80114638[o->unkB0] - a);
    s16 s = c;
    u16 u = c;
    if (s != 0) {
        if (u < 0x80) {
            if (s >= 4) { o->unk8C = a + 4; o->unk8C = *(u8 *)((u8 *)o + 0x8c); }
            else if (s < 2) { o->unk8C = a + 1; o->unk8C = *(u8 *)((u8 *)o + 0x8c); }
            else { o->unk8C = a + 2; o->unk8C = *(u8 *)((u8 *)o + 0x8c); }
        } else {
            if (s < 0xfd) { o->unk8C = a - 4; o->unk8C = *(u8 *)((u8 *)o + 0x8c); }
            else if (s < 0xff) { o->unk8C = a - 2; o->unk8C = *(u8 *)((u8 *)o + 0x8c); }
            else { o->unk8C = a - 1; o->unk8C = *(u8 *)((u8 *)o + 0x8c); }
        }
    }
}

#define chk(o, n) \
    if (*(u8 *)((u8 *)o + 0xac) != 2 && o->subState == n) { \
        if (o->unk9E == 0) func_8010D678(o, 1); \
    }

void func_800FFAE8(GameObject *o, s32 p2)
{
    extern void func_8010C398(GameObject *);
    extern void func_8010ABD0(GameObject *);
    extern void func_80108388(GameObject *);
    extern void func_80105D68(GameObject *);
    extern void func_801039E8(GameObject *);
    extern u8 *D_8009B698;
    s16 c;

    switch (o->subState) {
    case 0:
        D_8009C618[0] = 1;
        dirA_FFAE8(o);
        dirF_FFAE8(o);
        func_800F07D8(o);
        turn_FFAE8(o);
        func_800EF40C(o);
        break;
    case 1:
        D_8009C618[0] = 1;
        dirA_FFAE8(o);
        dirF_FFAE8(o);
        func_800F10A4(o);
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            D_8009C618[0] = 0;
            o->unk9C = 1;
            o->unkA4 = 0;
            *(u8 *)((u8 *)o + 0xcd) = 0;
            *(u8 *)((u8 *)o + 0xce) = 0;
            if ((D_8009BCEC & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
                o->unkA7 = 1;
            o->subState = 2;
            o->step = 0;
        }
        func_8010D678(o, 0);
        turn_FFAE8(o);
        func_800EF40C(o);
        break;
    case 2:
        dirA_FFAE8(o);
        func_800F1EF8(o);
        chk(o, 2);
        break;
    case 3:
        func_800F3810(o);
        turn_FFAE8(o);
        if (*(u8 *)((u8 *)o + 0xac) < 2) func_800EF40C(o);
        break;
    case 4:
        if (o->unk9D == 0) {
            dirC_FFAE8(o);
            D_8009B698[7] = o->animFrame;
        }
        func_800F2A40(o);
        turn_FFAE8(o);
        break;
    case 5:
        func_800F43D8(o);
        break;
    case 6:
        func_800F63BC(o);
        break;
    case 7:
        func_800F808C(o);
        break;
    case 8:
        func_8010B384(o);
        break;
    case 9:
        func_800F5B1C(o);
        break;
    case 10:
        dirD_FFAE8(o);
        func_800F329C(o);
        break;
    case 11:
        func_800F6E0C(o);
        break;
    case 12:
        func_800F8C08(o);
        break;
    case 13:
        func_80108D08(o);
        break;
    case 14:
        func_801039E8(o);
        break;
    case 15:
        func_80105A14(o);
        break;
    case 16:
        func_80106928(o);
        break;
    case 17:
        func_80107A58(o);
        break;
    case 18:
        func_80108388(o);
        break;
    case 19:
        D_8009C618[0] = 1;
        func_8010633C(o);
        turn_FFAE8(o);
        break;
    case 0x15:
        func_801091A0(o);
        break;
    case 0x17:
        func_80122258(o);
        break;
    case 0x18:
        func_8010ABD0(o);
        turn_FFAE8(o);
        break;
    case 0x1b:
        func_80106F50(o);
        break;
    case 0x1c:
        D_8009C618[0] = 1;
        dirA_FFAE8(o);
        dirF_FFAE8(o);
        func_80108B3C(o);
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            D_8009C618[0] = 0;
            o->unk9C = 1;
            *(u8 *)((u8 *)o + 0xc3) = 0;
            o->subState = 2;
            o->step = 0;
        }
        func_8010D678(o, 0);
        turn_FFAE8(o);
        func_800EF40C(o);
        break;
    case 0x1d:
        func_800F937C(o);
        break;
    case 0x1e:
        func_80122B1C(o);
        break;
    case 0x1f:
        D_8009C618[0] = 1;
        func_80120E90(o);
        func_8010D678(o, 0);
        break;
    case 0x20:
        func_8010731C(o);
        break;
    case 0x21:
        func_80120AC8(o);
        break;
    case 0x22:
        func_80121748(o);
        break;
    case 0x24:
        func_8011CB24(o);
        break;
    case 0x25:
        func_8011D9CC(o);
        break;
    case 0x26:
        func_8011D1A8(o);
        break;
    case 0x27:
        func_8011D41C(o);
        break;
    case 0x28:
        func_801210A4(o);
        break;
    case 0x29:
        func_8012137C(o);
        break;
    case 0x2a:
        func_80105EA0(o);
        turn_FFAE8(o);
        func_800EF40C(o);
        break;
    case 0x2b:
        func_80106100(o);
        turn_FFAE8(o);
        func_800EF40C(o);
        break;
    case 0x2e:
        func_80101D58(o);
        break;
    case 0x23:
    case 0x2f:
        func_8010BD68(o);
        break;
    case 0x30:
        func_800FF224(o);
        break;
    case 0x31:
        func_80107E20(o);
        break;
    case 0x32:
        func_800FA780(o);
        break;
    case 0x33:
        func_8011D6A8(o);
        break;
    case 0x34:
        func_8011DA00(o);
        break;
    case 0x35:
        func_80121F54(o);
        break;
    case 0x36:
        func_8011DE38(o);
        break;
    case 0x37:
        ((void (*)(GameObject *, s32))func_800FB114)(o, p2);
        chk(o, 0x37);
        break;
    case 0x3a:
        func_8011CF50(o);
        break;
    case 0x3b:
        func_8011CCE8(o);
        break;
    case 0x3c:
        func_801062E8(o);
        break;
    case 0x3d:
        D_8009C618[0] = 1;
        func_8010C6E0(o);
        break;
    case 0x3e:
        D_8009C618[0] = 1;
        func_8010C398(o);
        func_8010CBD8(o);
        break;
    case 0x3f:
        dirA_FFAE8(o);
        func_8011A650(o);
        break;
    case 0x40:
        func_800F9C7C(o);
        break;
    case 0x41:
        dirD_FFAE8(o);
        func_8011AAF4(o);
        break;
    case 0x43:
        dirA_FFAE8(o);
        func_8010CE5C(o);
        chk(o, 0x43);
        break;
    case 0x44:
        func_8010D0DC(o);
        break;
    case 0x45:
        func_8010D9BC(o);
        break;
    case 0x46:
        func_8011B1CC(o);
        break;
    case 0x47:
        func_8011A4B4(o);
        break;
    case 0x48:
        func_80105D68(o);
        break;
    case 0x49:
    case 0x16:
        func_800F7A48(o);
        break;
    case 0x63:
        switch (o->step) {
        case 0:
            o->timer = 0x3c;
            o->step++;
        case 1:
            if (--o->timer <= 0) {
                o->state = 1;
                o->subState = 0;
                o->step = 0;
                o->unk7 = 0;
                o->active = 1;
                D_8009C618[0] = 0;
                D_8009BCA2 = 1;
            }
            break;
        }
        break;
    }
    c = 0;
    *(u8 *)&o->unkA8 = 0;
    o->unkA6 = 0;
    if (o->unk9E == 0 && o->state == 5) {
        c = o->subState == 0x40;
        if (o->subState == 0x41) c++;
        if (o->subState == 0x65) c++;
    }
    if (c == 0) func_80042C20(o);
    if (D_1F8001A4 == 0) func_800FE970(o, 1);
    probeTileShapeThreePoints(o, 4);
}
#undef chk

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80100AE0);
typedef struct O_00AE0 {
    char pad0[4];
    u8 b04;
    u8 step;
    char pad1[0x9e - 6];
    u8 b9e;
    char pad2[0xa6 - 0x9f];
    u8 ba6;
    char pad3;
    u8 wa8;
} O_00AE0;
extern void func_800FC6B8();
extern void func_800FCEDC();
extern void func_800FD49C();
extern void func_800FDABC();
extern void func_800FDCEC();
extern void func_80042C20();

void func_80100AE0(O_00AE0 *o)
{
    register char r;
    switch (o->step) {
    case 0: func_800FC6B8(o); break;
    case 1: func_800FCEDC(o); break;
    case 2: func_800FD49C(o); break;
    case 3: func_800FDABC(o); break;
    case 4: func_800FDCEC(o); break;
    }
    r = 0;
    o->wa8 = 0;
    o->ba6 = 0;
    if (o->b9e == 0 && o->b04 == 5) {
        r = o->step == 0x40;
        if (o->step == 0x65)
            r++;
    }
    if (!r)
        func_80042C20(o);
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80100BCC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80100C98);
typedef struct P_00C98 { u8 b0; char p0[7]; u8 b8; char p1[0x20-9]; s16 h20; char p2[0x28-0x22]; u16 h28; u16 h2a; u16 h2c; u16 h2e; } P_00C98;
typedef struct O_00C98 {
    u8 active; u8 visible; u8 type; char p00[3]; u8 state; char p07[0x16-7];
    s16 y; char p18[0x22-0x18]; s16 w22; void *anim; char p2[0x68-0x28];
    u8 b68; u8 b69; u8 b6a; char p6b[0x7c-0x6b]; s16 vx; s16 vy;
    char p3[0x8c-0x80]; s32 d8c; char p4[0x9c-0x90]; u8 b9c; u8 b9d; u8 b9e; char p9f[0xa4-0x9f];
    u8 ba4; u8 ba5; char pa6; u8 ba7;
    char p6[0xac-0xa8]; u8 bac; char p7[0xb0-0xad]; s16 hb0; s16 hb2; char pb4[2]; s16 hb6;
    char pb8[0xc6-0xb8]; u8 bc6; u8 bc7; char pc8[0xe0-0xc8]; s16 he0; char pe2; u8 be3;
} O_00C98;
typedef struct E_00C98 { char p0[4]; u8 b4, b5, b6; } E_00C98;
extern u8 D_8009C617_U8Arr[] asm("D_8009C617");
extern E_00C98 *D_8009C650_E_00C98Ptr asm("D_8009C650");

static __inline__ void land_00C98(O_00C98 *o)
{
    extern P_00C98 *D_8009B698;
    extern char D_800108A8[];
    D_8009B698->b8 = 0;
    o->ba4 = 0;
    o->ba5 = 0;
    o->b9c = 0;
    o->bac = 0;
    o->hb2 = 0;
    o->vx = 0;
    o->vy = 0;
    o->d8c = D_80114638[o->hb0];
    D_8009B698->h20 = 0;
    o->anim = D_800108A8;
    advanceAnimFrame(o, 0);
    D_8009B698->h2e = 0xffff;
    D_8009B698->h28 = 0xffff;
    D_8009B698->h2a = 0xffff;
}

void func_80100C98(O_00C98 *o)
{
    extern P_00C98 *D_8009B698;
    extern char D_800108A8[];
    P_00C98 *p;
    O_00C98 *q;

    switch (o->state) {
    case 0:
        o->ba4 = 0;
        o->ba5 = 0;
        o->b9c = 2;
        o->ba7 = 0;
        p = D_8009B698;
        o->hb2 = 0;
        o->vx = 0;
        o->vy = 0;
        p->h20 = 0;
        o->visible = 1;
        if (o->active == 2)
            o->he0 = 0x8c;
        o->w22 = 0;
        if (o->bac >= 2) {
            D_8009C650_E_00C98Ptr = D_800A547C;
            D_8009C650_E_00C98Ptr->b4 = 2;
            D_8009C650_E_00C98Ptr->b5 = 2;
            D_8009C650_E_00C98Ptr->b6 = 0;
        }
        o->bac = 0;
        D_8009BC9C = 0;
        o->bc7 = 1;
        o->b9d = 0;
        o->bc6 = 0;
        o->be3 = 0;
        D_8009B698->b0 = 0;
        q = D_8009E454;
        if (q != 0 && q != (O_00C98 *)1) {
            switch (q->type) {
            case 5:
                q->b6a = 0;
                break;
            case 0x21:
                q->b68 = 0;
                break;
            }
        }
        o->state++;
        if (o->b69 == 1 || ((s16 (*)(O_00C98 *, s32, s32))probeSidesAndApplyTileResponse)(o, 4, 0) != 0) {
            land_00C98(o);
            if (D_8009C617_U8Arr[0] == 0) {
                D_8009C617 = 1;
                D_8009BCA2 = 1;
            }
            o->state = 2;
        }
        break;
    case 1:
        func_800EDFA0(o);
        tickAnimation(o);
        D_8009B698->b8 = 1;
        o->b9e = 0;
        o->hb0 = 0;
        o->hb6 = 0;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        D_8009B698->h2c = 4;
        if (D_8009B698->h2e != 4) {
            D_8009B698->h2c = 4;
            func_800EEF64(o);
            advanceAnimFrame(o, 0);
            D_8009B698->h2e = D_8009B698->h2c;
        }
        if (o->b69 == 1 || ((s16 (*)(O_00C98 *, s32, s32))probeSidesAndApplyTileResponse)(o, 4, 0) != 0) {
            playSFXWithVolume(0x1c, 0x7f);
            land_00C98(o);
            if (D_8009C617_U8Arr[0] == 0) {
                D_8009C617 = 1;
                D_8009BCA2 = 1;
            }
            o->state++;
        }
        break;
    case 2:
        if (TALK_POSE != 0) {
            func_800F0668(o);
        } else {
            D_8009B698->h2c = 0;
            o->anim = D_800108A8;
            advanceAnimFrame(o, 0);
        }
        if (o->b69 != 0)
            o->y += 2;
        ((s16 (*)(O_00C98 *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801010D4);
extern u8 D_1F8003CE;
extern void func_801087E4(GameObject *);
extern void func_80122538(GameObject *);
extern void func_80109D44(GameObject *);
extern void func_80109FE0(GameObject *);
extern void func_801074B8(GameObject *);
extern void func_80107688(GameObject *);
extern void func_8010810C(GameObject *);
extern void func_8011D098(GameObject *);
extern void func_8010A1E4(GameObject *);
void func_801010D4(GameObject *o)
{
    extern void func_8010D2D4(GameObject *);
    extern GameObject *D_8009B698;
    extern char D_800108A8[];
    s16 c;
    s32 v;
    switch (o->subState) {
    case 1:
        if (--o->timer > 0) goto common;
        if ((*(s32 *)&GAME) == 0x40000) {
            *(s8 *)((u8 *)o + 0xf) = 8;
        } else if ((*(s32 *)&GAME) == 0x50000) {
            *(s8 *)((u8 *)o + 0xf) = -5;
        } else {
            *(s8 *)((u8 *)o + 0xf) = -8;
        }
        v = D_80114638[o->unkB0];
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        o->unk7 = 0;
        o->timer = 0;
        o->unk8C = v;
        D_8009BCA2_U8Arr[0] = 1;
        break;
    case 2:
        func_801087E4(o);
        break;
    case 3:
        func_80122538(o);
        break;
    case 4:
        func_80109D44(o);
        break;
    case 5:
        func_80109FE0(o);
        break;
    case 0:
    case 6:
        func_80100C98(o);
        break;
    case 7:
        func_801074B8(o);
        break;
    case 8:
        func_80107688(o);
        break;
    case 9:
        func_8010810C(o);
        break;
    case 10:
        if (--o->timer <= 0) goto anim;
    common:
        o->animFrame &= 1;
        if (*(u8 *)((u8 *)o + 0xac) >= 2) {
            D_8009C650_U8Ptr = D_800A547C;
            D_8009C650_U8Ptr[4] = 2;
            D_8009C650_U8Ptr[5] = 2;
            D_8009C650_U8Ptr[6] = 0;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        D_8009BC9C = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        *(u8 *)((u8 *)D_8009B698 + 0) = 0;
        v = 0x128;
        if (o->animFrame & 1) {
            v = -0x128;
        }
        o->unkB2 = v;
        func_8010D2D4(o);
        if (o->touchFlag != 0) {
            o->y.p.whole += 2;
        }
        probeSidesAndApplyTileResponse(o, 0, 0);
        o->unk8C = D_80114638[o->unkB0];
        break;
    case 11:
        func_8011D098(o);
        break;
    case 12:
        func_8010A1E4(o);
        break;
    case 0x40:
        o->visible = 0;
        break;
    case 0x61:
        *(u8 *)((u8 *)o + 0xa2) = 0;
        *(u8 *)((u8 *)o + 0xa3) = 0;
        tickAnimation(o);
        o->unk8C = 0;
        break;
    case 0x62:
        o->anim = D_800108A8;
        readAnimFrameCount(o);
        o->subState++;
    case 0x63:
        o->anim = D_800108A8;
        readAnimFrameCount(o);
        o->unk8C = 0;
        break;
    case 0x64:
        o->unk8C = 0;
    case 0x65:
        if (TALK_POSE != 0) {
            func_800F0668(o);
        } else if (D_1F8003CE == 0 || *(u16 *)o->anim != 0) {
        anim:
            tickAnimation(o);
        }
        break;
    }
    c = 0;
    *(u8 *)((u8 *)o + 0xa8) = 0;
    o->unkA6 = 0;
    if (o->unk9E == 0 && o->state == 5) {
        c = o->subState == 0x40;
        if (o->subState == 0x41) c++;
        if (o->subState == 0x65) c++;
    }
    if (c == 0) func_80042C20(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80101470);
typedef struct { char p0[4]; u8 b4, step, state; char p1[0x2e - 7]; u16 af; char p2[0x69 - 0x30]; u8 b69; char p3[0x8c - 0x6a]; s32 d8c; char p4[0x9e - 0x90]; u8 b9e; char p5[7]; u8 ba6; char p6; u8 ba8; } O_01470;

void func_80101470(O_01470 *o)
{
    extern void func_8010A794(O_01470 *);
    extern void func_8010A3A0(O_01470 *);
    extern void func_80108C70(O_01470 *);
    switch (o->step) {
    case 0:
        func_800F937C(o);
        break;
    case 3:
        o->af = o->af & 1;
        func_80108C70(o);
        break;
    case 4:
        o->af = o->af & 1;
        func_8010A794(o);
        break;
    case 5:
        o->af = o->af & 1;
        func_8010A3A0(o);
        o->d8c = 0;
        break;
    case 6:
        func_800F7490(o);
        break;
    case 7:
        o->d8c = 0;
        func_8010A3A0(o);
        if (o->b69 != 0) {
            o->b4 = 1;
            o->step = 0;
            o->state = 0;
        }
        break;
    }
    o->ba8 = 0;
    o->ba6 = 0;
    if (o->b9e == 0)
        func_80042C20(o);
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80101574);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80101D58);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80101DAC);
typedef struct O_01DAC { char p0[0x12]; s16 x; char p1[2]; s16 y; char p2[2]; s16 z; char p3[4]; s16 t; } O_01DAC;
void func_80101DAC(O_01DAC *o)
{
    extern void func_800EDEBC(O_01DAC *, s32);
    o->t = 0;
    func_800EDEBC(o, 0xd);
    func_800224FC(2, o->x, o->y, o->z);
    if ((*(char **)&D_8009C650)[2] == 2)
        (*(char **)&D_8009C650)[6] = 2;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80101E10);
extern void func_800ED9E0(GameObject *);

void func_80101E10(GameObject *o)
{
    s16 f;
    volatile u16 *k;

    switch (o->step) {
    case 1:
        o->timer++;
        func_800ED9E0(o);
        D_8009C650->animFrame = o->animFrame & 1;
        f = 0;
        o->y.p.whole += 8;
        if (D_8009C650->y.p.whole < o->y.p.whole + 8) {
            o->y.p.whole = D_8009C650->y.p.whole - 8;
            f = 1;
        }
        if (o->velX < 0) {
            o->h->p.whole -= 8;
            if (o->h->p.whole <= D_8009C650->h->p.whole) {
                o->h->p.whole = D_8009C650->h->p.whole;
                if (f) {
                    o->timer = 0;
                    func_800EDEBC(o, 0xd);
                    func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
                    if (D_8009C650->type == 2) D_8009C650->step = 2;
                }
            }
        } else {
            o->h->p.whole += 8;
            if (o->h->p.whole >= D_8009C650->h->p.whole) {
                o->h->p.whole = D_8009C650->h->p.whole;
                if (f) {
                    o->timer = 0;
                    func_800EDEBC(o, 0xd);
                    func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
                    if (D_8009C650->type == 2) D_8009C650->step = 2;
                }
            }
        }
        if (D_8009C650->type == 0x21) {
            D_8009C650->h->p.whole = o->h->p.whole;
            D_8009C650->y.p.whole = o->y.p.whole + 8;
            func_800EDEBC(o, 0xd);
            func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            o->step = 2;
        } else if (o->touchFlag != 0 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 1)) {
            D_8009C650->h->p.whole = o->h->p.whole;
            D_8009C650->y.p.whole = o->y.p.whole + 8;
            func_800EDEBC(o, 0xd);
            func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            if (D_8009C650->type == 2) D_8009C650->step = 2;
            o->step = 2;
        } else if (o->timer >= 11) {
            D_8009C650->h->p.whole = o->h->p.whole;
            D_8009C650->y.p.whole = o->y.p.whole + 8;
            o->timer = 0;
            func_800EDEBC(o, 0xd);
            func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            if (D_8009C650->type == 2) D_8009C650->step = 2;
            o->step = 2;
        }
        break;
    case 2:
        func_800EDEBC(o, 0xd);
        o->unk9C = 0;
        o->velX = 0;
        o->velY = 0;
        o->step++;
    case 3:
        k = &D_8009C9D8;
        if (*k & 0x80) o->animFrame = 1;
        if (*k & 0x20) o->animFrame = 0;
        D_8009C650->animFrame = o->animFrame & 1;
        o->h->p.whole = D_8009C650->h->p.whole;
        o->y.p.whole = D_8009C650->y.p.whole - D_8009C650->hitOffsetY;
        o->unk8C = D_8009C650->unk8C;
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            (*(u8 *)&D_8009C618) = 0;
            o->unk9C = 1;
            o->touchFlag = 0;
            *(u8 *)&o->unkAC = 3;
            o->unkB2 = 0;
            if (D_8009C650->type == 2) {
                D_8009C650->active = 2;
                D_8009C650->step = 6;
            }
            o->subState = 0xf;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80102204);
typedef struct O_02204 {
    char pad0[6];
    u8 state;
    char pad1[0x16 - 7];
    u16 y;
    char pad2[0x20 - 0x18];
    s16 timer;
    char pad3[0x2e - 0x22];
    u16 animFrame;
    char pad4[0x40 - 0x30];
    struct H_02204 { s16 pad; u16 w; } *h;
    char pad5[0x7c - 0x44];
    s16 velX;
    s16 velY;
    char pad6[0x9c - 0x80];
    char b9c;
    char pad7[0xac - 0x9d];
    char wac;
    char pad8[0xba - 0xad];
    u16 wba;
} O_02204;
extern void func_800ED840();

void func_80102204(O_02204 *o)
{
    O_02204 *p;
    o->timer = 0;
    func_800EDEBC(o, 0x23);
    o->wac = 3;
    o->b9c = 0;
    p = D_8009C650;
    o->velX = 0;
    o->velY = 0;
    *(u16 *)((char *)p + 0x2e) = o->animFrame & 1;
    o->h->w = p->h->w;
    p->y = o->y + o->wba;
    func_800ED840(o, 0);
    o->state = 2;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80102290);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010254C);
typedef struct H_0254C { s16 pad; u16 w; } H_0254C;
typedef struct O_0254C {
    char pad0[6];
    u8 state;
    char pad1[0x12 - 7];
    s16 a;
    char pad1b[2];
    s16 y;
    char pad1c[2];
    s16 b;
    char pad2[0x20 - 0x1c];
    s16 timer;
    char pad3[0x40 - 0x22];
    H_0254C *h;
    char pad4[0x70 - 0x44];
    u16 w70;
    u16 w72;
    char pad5[0x7c - 0x74];
    s16 velX;
    s16 velY;
    char pad6[0x9c - 0x80];
    char b9c;
    char pad7[0xac - 0x9d];
    char wac;
} O_0254C;

void func_8010254C(O_0254C *o)
{
    O_0254C *p;
    u16 s1, s2, s3;
    o->timer = 0;
    func_800EDEBC(o, 0xd);
    func_800224FC(2, o->a, o->y, o->b);
    o->wac = 3;
    o->b9c = 0;
    p = D_8009C650;
    o->velX = 0;
    o->velY = 0;
    o->h->w = p->h->w;
    s1 = p->w72;
    s2 = p->w70;
    s3 = p->y;
    o->state = 2;
    o->y = s3 - (s1 - s2);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801025E0);
s32 func_80135A94(s16, s16, s16, s16, s16, s16);
#define BLOCK()                                                                     \
    {                                                                               \
        o->timer = 0;                                                               \
        func_800EDEBC(o, 0xd);                                             \
        func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);                  \
        *(u8 *)&o->unkAC = 3;                                              \
        o->unk9C = 0;                                                                 \
        o->velX = 0;                                                                \
        o->velY = 0;                                                                \
        o->h->p.whole = D_8009C650->h->p.whole;                                     \
        o->y.p.whole = D_8009C650->y.p.whole - (D_8009C650->hitHeight - D_8009C650->hitOffsetY); \
        o->step = 2;                                                               \
    }
void func_801025E0(GameObject *o)
{
    s16 f;
    GameObject *e;
    volatile u16 *k;
    switch (o->step) {
    case 1:
        o->timer++;
        func_800ED9E0(o);
        f = 0;
        o->y.p.whole += 8;
        if (o->y.p.whole + D_8009C650->hitOffsetY >= D_8009C650->y.p.whole) {
            o->y.p.whole = D_8009C650->y.p.whole - D_8009C650->hitOffsetY;
            f = 1;
        }
        if (o->velX < 0) {
            o->h->p.whole -= 8;
            if (o->h->p.whole <= D_8009C650->h->p.whole) {
                o->h->p.whole = D_8009C650->h->p.whole;
                if (f) BLOCK();
            }
        } else {
            o->h->p.whole += 8;
            if (o->h->p.whole >= D_8009C650->h->p.whole) {
                o->h->p.whole = D_8009C650->h->p.whole;
                if (f) BLOCK();
            }
        }
        if ((o->touchFlag | ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 1)) || o->timer >= 11) BLOCK();
        break;
    case 2:
        k = &D_8009C9D8;
        if (*k & 0x80) o->animFrame = 1;
        if (*k & 0x20) o->animFrame = 0;
        o->h->p.whole = D_8009C650->h->p.whole;
        if (D_8009C650->type == 0xb) {
            if (D_8009C650->subtype == 0) o->y.p.whole = D_8009C650->y.p.whole - (D_8009C650->hitHeight - D_8009C650->hitOffsetY) + 8;
            else o->y.p.whole = D_8009C650->y.p.whole - (D_8009C650->hitHeight - D_8009C650->hitOffsetY);
        }
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            D_8009C618[0] = 0;
            o->unk9C = 1;
            o->touchFlag = 0;
            o->unkB2 = 0;
            e = D_8009C650;
            if (e->type == 0xb) {
                if (e->unkC)
                    *(s32 *)((char *)o + 0x90) = func_80135A94(6, 0, e->unkC, e->x.p.whole, e->y.p.whole, e->z.p.whole);
                D_8009C650->step = 1;
            }
            o->subState = 0xf;
            o->step = 0;
        }
        break;
    }
}
#undef BLOCK

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80102978);
extern char *D_8009C650_CharPtr asm("D_8009C650");

void func_80102978(GameObject *o)
{
    char *p = D_8009C650_CharPtr, *q, *r, k;
    o->h->p.whole = *(s16 *)(*(char **)(p + 0x40) + 2);
    o->y.p.whole = *(u16 *)(p + 0x16) - *(u16 *)(p + 0x70);
    o->timer = 0;
    func_800EDEBC(o, 0xd);
    o->velH = 0;
    o->velV = 0;
    o->unkB2 = 0;
    switch (D_8009C650_CharPtr[2]) {
    case 0:
    case 0x3a:
        *(char *)&o->unkAC = 3;
        r = D_8009C650_CharPtr;
        r[6] = 2;
        o->step = 2;
        goto sw2;
    case 10:
    case 0x28:
        goto sw2;
    case 0x13:
        *(char *)&o->unkAC = 3;
        break;
    case 0x38:
        o->unk9C = 0;
    case 0x42:
    default:
        *(char *)&o->unkAC = 3;
        r = D_8009C650_CharPtr;
        r[6] = 3;
    }
    o->step = 2;
sw2:
    switch (D_8009C650_CharPtr[2]) {
    case 0:
    case 8:
    case 0x13:
    case 0x1e:
    case 0x1f:
    case 0x3a:
        *(s32 *)(D_8009C650_CharPtr + 0x8c) = 0;
    }
    q = D_8009C650_CharPtr;
    o->unk8C = (u8)q[0x8c];
    *(u16 *)(q + 0x2e) = o->animFrame & 1;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80102AC4);
void func_80102AC4(char *o)
{
    o[0x69] = 0;
    o[0xac] = 3;
    o[0x9c] = 0;
    *(s16 *)(o + 0x7c) = 0;
    *(s16 *)(o + 0x7e) = 0;
    *(s16 *)(o + 0x80) = 0;
    *(s16 *)(o + 0x82) = 0;
    *(s16 *)(o + 0xb2) = 0;
    func_800ED840(o, 0);
    *(u32 *)((*(char **)&D_8009C650) + 0x8c) = *(u8 *)(o + 0x8c);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80102B28);
typedef struct { s16 s0, s2; } H_02B28;
typedef struct O_02B28 {
    char p0[2]; u8 b2, b3; char p0b; u8 b5, b6; char p1[0x12 - 7]; s16 x12; char p2[2]; s16 y16; char p3[2]; s16 z1a;
    char p4a[4]; s16 s20; char p4b[0x2e - 0x22]; u16 w2e; char p4[0x40 - 0x30]; H_02B28 *h;
    char p5[0x69 - 0x44]; u8 b69; char p5b[0x70 - 0x6a]; s16 s70, s72; char p6[0x7c - 0x74]; s16 vx, vy, s80, s82;
    char p7[0x8c - 0x84]; s32 a8c; char p7b[0x9c - 0x90]; u8 b9c; char p8[0xac - 0x9d]; u8 bac;
    char p9[0xb2 - 0xad]; u16 wb2;
} O_02B28;
extern O_02B28 *D_8009C650_O_02B28Ptr asm("D_8009C650");
extern u16 D_8009C9D8_U16 asm("D_8009C9D8");

#define PADCHK() { volatile u16 *pad = &D_8009C9D8_U16; if (*pad & 0x80) o->w2e = 1; if (*pad & 0x20) o->w2e = 0; }

void func_80102B28(O_02B28 *o)
{
    s16 flag;
    O_02B28 *p;

    o->vy += 8;
    if (o->vy > 0x680) o->vy = 0x680;
    if (o->vy < -0x680) o->vy = -0x680;
    switch (o->b6) {
    case 1:
        o->s20++;
        applyObjectAltSpeedVertical(o);
        func_8010DE48(o);
        *(s32 *)o->h += o->vx << 8;
        flag = 0;
        o->y16 += 8;
        if (o->y16 + D_8009C650_O_02B28Ptr->s70 > D_8009C650_O_02B28Ptr->y16) {
            o->y16 = D_8009C650_O_02B28Ptr->y16 - D_8009C650_O_02B28Ptr->s70;
            flag = 1;
        }
        if (o->vx < 0) {
            o->h->s2 -= 8;
            if (o->h->s2 <= D_8009C650_O_02B28Ptr->h->s2) {
                o->h->s2 = D_8009C650_O_02B28Ptr->h->s2;
                if (flag) func_80102978(o);
            }
        } else {
            o->h->s2 += 8;
            if (o->h->s2 >= D_8009C650_O_02B28Ptr->h->s2) {
                o->h->s2 = D_8009C650_O_02B28Ptr->h->s2;
                if (flag) func_80102978(o);
            }
        }
        if (o->b69 != 0 || ((s16 (*)(O_02B28 *, s32, s32))probeSidesAndApplyTileResponse)(o, (s16)(D_8009C650_O_02B28Ptr->y16 - o->y16 - o->s70 + (D_8009C650_O_02B28Ptr->s72 - D_8009C650_O_02B28Ptr->s70)), 1) || o->s20 > 10) {
            func_80102978(o);
        }
        return;
    case 2:
        switch (D_8009C650_O_02B28Ptr->b2) {
        case 0x38:
            PADCHK();
            {
                O_02B28 *q = D_8009C650_O_02B28Ptr;
                o->h->s2 = q->h->s2;
                o->y16 = q->y16 - q->s70;
            }
            break;
        case 10:
            o->h->s2 = D_8009C650_O_02B28Ptr->h->s2;
            o->y16 = D_8009C650_O_02B28Ptr->y16 - D_8009C650_O_02B28Ptr->s70;
            o->b9c = 0;
            PADCHK();
            break;
        default:
            PADCHK();
            p = D_8009C650_O_02B28Ptr;
            p->w2e = o->w2e & 1;
            p->h->s2 = o->h->s2;
            p->y16 = o->y16 + p->s70;
            applyObjectAltSpeedVertical(o);
            if (o->b69 != 0 || ((s16 (*)(O_02B28 *, s32, s32))probeSidesAndApplyTileResponse)(o, (s16)(D_8009C650_O_02B28Ptr->y16 - o->y16 - o->s70 + (D_8009C650_O_02B28Ptr->s72 - D_8009C650_O_02B28Ptr->s70)), 1)) {
                o->b69 = 0;
                o->bac = 3;
                o->b9c = 0;
                o->vx = 0;
                o->vy = 0;
                o->s80 = 0;
                o->s82 = 0;
                o->wb2 = 0;
                func_800ED840(o, 0);
                D_8009C650_O_02B28Ptr->a8c = ((u8 *)o)[0x8c];
            }
            break;
        }
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            o->b9c = 1;
            o->b69 = 0;
            o->wb2 = 0;
            o->vx = 0;
            o->vy = 0;
            switch (D_8009C650_O_02B28Ptr->b2) {
            case 0: case 0x13: case 0x1f: case 0x28:
            case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x41: case 0x42:
                D_8009C650_O_02B28Ptr->b6 = 7;
                break;
            case 10:
                D_8009C650_O_02B28Ptr->b6 = D_8009C650_O_02B28Ptr->b6 + 1;
                break;
            case 0x38:
                if (D_8009C650_O_02B28Ptr->b3 != 0) {
                    D_8009C650_O_02B28Ptr->b6 = 6;
                    break;
                }
            default:
                D_8009C650_O_02B28Ptr->b6 = 4;
                break;
            }
            o->b5 = 0xf;
            o->b6 = 0;
        }
        break;
    }
}
#undef PADCHK

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010300C);
typedef struct { char p0[2]; u16 s2; } H_0300C;
typedef struct R_0300C {
    char p0[6]; char b6; char p1[0x16 - 7]; u16 s16; char p2[0x20 - 0x18]; s16 s20;
    char p3[0x40 - 0x22]; H_0300C *h; char p4[0x70 - 0x44]; u16 s70; char p5[0x7c - 0x72];
    s16 s7c, s7e; char p6[0x8c - 0x80]; u8 b8c;
} R_0300C;
typedef struct {
    char p0[6]; char b6; char p1[0x16 - 7]; u16 s16; char p2[0x20 - 0x18]; s16 s20;
    char p3[0x40 - 0x22]; H_0300C *h; char p4[0x7c - 0x44];
    s16 s7c, s7e; char p6[0x8c - 0x80]; u32 w8c; char p7[0x9c - 0x90]; char b9c; char p8[0xac - 0x9d]; char bac;
} TO_0300C;

void func_8010300C(TO_0300C *o)
{
    o->s20 = 0;
    func_800EDEBC(o, 0xd);
    o->bac = 3;
    o->b9c = 0;
    {
        R_0300C *r = D_8009C650;
        o->s7c = 0;
        o->s7e = 0;
        o->h->s2 = r->h->s2;
        o->s16 = r->s16 - r->s70;
        o->w8c = r->b8c;
        o->b6 = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80103090);
typedef struct { s16 s0, s2; } H_03090;
typedef struct O_03090 {
    char p0[5]; u8 b5, b6; char p1[0x12 - 7]; s16 x12; char p2[2]; s16 y16; char p3[2]; s16 z1a;
    char p4a[4]; s16 s20; char p4b[0x2e - 0x22]; u16 w2e; char p4[0x40 - 0x30]; H_03090 *h;
    char p5[0x69 - 0x44]; u8 b69; char p5b[0x70 - 0x6a]; s16 s70; char p6[0x7c - 0x72]; s16 vx, vy;
    char p7[0x8c - 0x80]; s32 a8c; char p7b[0x9c - 0x90]; u8 b9c; char p8[0xac - 0x9d]; u8 bac;
    char p9[0xb2 - 0xad]; u16 wb2;
} O_03090;
extern O_03090 *D_8009C650_O_03090Ptr asm("D_8009C650");

void func_80103090(O_03090 *o)
{
    extern void func_800EDDDC(O_03090 *, s32, s32);
    extern O_03090 *D_8009B698;
    s16 flag;
    O_03090 *p;
    volatile u16 *pad;
    switch (o->b6) {
    case 1:
        o->s20++;
        func_8010DE48(o);
        *(s32 *)o->h += o->vx << 8;
        o->vy += 8;
        if (o->vy > 0x680) o->vy = 0x680;
        if (o->vy < -0x680) o->vy = -0x680;
        applyObjectAltSpeedVertical(o);
        flag = 0;
        o->y16 += 8;
        if (o->y16 + D_8009C650_O_03090Ptr->s70 >= D_8009C650_O_03090Ptr->y16) {
            o->y16 = D_8009C650_O_03090Ptr->y16 - D_8009C650_O_03090Ptr->s70;
            flag = 1;
        }
        if (o->vx < 0) {
            o->h->s2 -= 8;
            if (o->h->s2 <= D_8009C650_O_03090Ptr->h->s2) {
                o->h->s2 = D_8009C650_O_03090Ptr->h->s2;
                if (flag) {
                    func_800EDDDC(o, 0xd, 0);
                    D_8009B698->w2e = 0xff;
                }
            }
        } else {
            o->h->s2 += 8;
            if (o->h->s2 >= D_8009C650_O_03090Ptr->h->s2) {
                o->h->s2 = D_8009C650_O_03090Ptr->h->s2;
                if (flag) {
                    func_800EDDDC(o, 0xd, 0);
                    D_8009B698->w2e = 0xff;
                }
            }
        }
        if (o->b69 != 0 || ((s16 (*)(O_03090 *, s32, s32))probeSidesAndApplyTileResponse)(o, (s16)(D_8009C650_O_03090Ptr->y16 - o->y16 - o->s70), 1) || o->s20 > 10) {
            o->s20 = 0;
            func_800EDEBC(o, 0xd);
            o->bac = 3;
            o->b9c = 0;
            o->vx = 0;
            o->vy = 0;
            p = D_8009C650_O_03090Ptr;
            o->h->s2 = p->h->s2;
            o->y16 = p->y16 - p->s70;
            o->a8c = ((u8 *)p)[0x8c];
            o->b6 = 2;
        }
        break;
    case 2:
        pad = &D_8009C9D8_U16;
        if (*pad & 0x80) o->w2e = 1;
        if (*pad & 0x20) o->w2e = 0;
        p = D_8009C650_O_03090Ptr;
        o->h->s2 = p->h->s2;
        o->y16 = p->y16 - p->s70;
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            o->b9c = 1;
            o->b69 = 0;
            o->wb2 = 0;
            o->b5 = 0xf;
            o->b6 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80103390);
void func_80103390(GameObject *o)
{
    GameObject *p;
    o->timer = 0;
    func_800EDEBC(o, 0xd);
    func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
    *(char *)((char *)o + 0xac) = 3;
    o->unk9C = 0;
    p = D_8009C650;
    o->velX = 0;
    o->velY = 0;
    p->h->p.whole = o->h->p.whole;
    *(s16 *)((char *)p + 0x16) = o->y.p.whole + *(s16 *)((char *)p + 0x70);
    o->step = 2;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80103420);
#define LAND(o)                                                         \
    do {                                                                \
        o->timer = 0;                                                   \
        func_800EDEBC(o, 0xd);                                 \
        func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);      \
        ((u8 *)o)[0xac] = 3;                                                 \
        o->unk9C = 0;                                                     \
        o->velX = 0;                                                    \
        o->velY = 0;                                                    \
        D_8009C650->h->p.whole = o->h->p.whole;                         \
        D_8009C650->y.p.whole = o->y.p.whole + D_8009C650->hitOffsetY;        \
        o->step = 2;                                                   \
    } while (0)

void func_80103420(GameObject *o)
{
    s16 hit;

    switch (o->step) {
    case 1:
        o->timer++;
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        o->velY += 8;
        if (o->velY > 0x680)
            o->velY = 0x680;
        if (o->velY < -0x680)
            o->velY = -0x680;
        applyObjectAltSpeedVertical(o);
        hit = 0;
        o->y.p.whole += 8;
        if (o->y.p.whole + D_8009C650->hitOffsetY >= D_8009C650->y.p.whole) {
            o->y.p.whole = D_8009C650->y.p.whole - D_8009C650->hitOffsetY;
            hit = 1;
        }
        if (o->velX < 0) {
            o->h->p.whole -= 8;
            if (D_8009C650->h->p.whole >= o->h->p.whole) {
                o->h->p.whole = D_8009C650->h->p.whole;
                if (hit)
                    LAND(o);
            }
        } else {
            o->h->p.whole += 8;
            if (o->h->p.whole >= D_8009C650->h->p.whole) {
                o->h->p.whole = D_8009C650->h->p.whole;
                if (hit)
                    LAND(o);
            }
        }
        if (o->timer >= 0xb)
            LAND(o);
        break;
    case 2:
        if (((u16 *)&D_8009C9D8)[0] & 0x80)
            o->animFrame = 1;
        if (((u16 *)&D_8009C9D8)[0] & 0x20)
            o->animFrame = 0;
        D_8009C650->h->p.whole = o->h->p.whole;
        D_8009C650->y.p.whole = o->y.p.whole + D_8009C650->hitOffsetY;
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            o->unk9C = 1;
            o->touchFlag = 0;
            o->unkB2 = 0;
            D_8009C650->step = 4;
            o->subState = 0xf;
            o->step = 0;
        }
        break;
    }
}
#undef LAND

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80103744);
extern void playSFX(s32);
extern void func_800EDEBC(void *o, s32 a);
extern void func_800224FC(s32 a, s32 b, s32 c, s32 d);

void func_80103744(char *o)
{
    *(s16 *)(o + 0x20) = 0;
    playSFX(9);
    func_800EDEBC(o, 0xd);
    func_800224FC(2, *(s16 *)(o + 0x12), *(s16 *)(o + 0x16), *(s16 *)(o + 0x1a));
    o[6]++;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801037A4);
typedef struct { s16 s0, s2; } H_037A4;
typedef struct O_037A4 {
    char p0[6]; u8 b6; char p1[0x12 - 7]; s16 x12; char p2[2]; s16 y16; char p3[2]; s16 z1a;
    char p4a[4]; s16 s20; char p4[0x40 - 0x22]; H_037A4 *h; char p5[0x70 - 0x44]; s16 s70; char p6[0x7c - 0x72]; s16 vx, vy;
    char p7[0x9c - 0x80]; u8 b9c; char p8[0xac - 0x9d]; u8 bac;
} O_037A4;
extern O_037A4 *D_8009C650_O_037A4Ptr asm("D_8009C650");

void func_801037A4(O_037A4 *o)
{
    s16 flag;
    if (o->b6 != 1) return;
    o->s20++;
    ((void (*)(void))func_8010DE48)();
    *(s32 *)o->h += o->vx << 8;
    o->vy += 8;
    if (o->vy > 0x680) o->vy = 0x680;
    if (o->vy < -0x680) o->vy = -0x680;
    applyObjectAltSpeedVertical(o);
    flag = 0;
    o->y16 += 8;
    if (o->y16 + D_8009C650_O_037A4Ptr->s70 >= D_8009C650_O_037A4Ptr->y16) {
        o->y16 = D_8009C650_O_037A4Ptr->y16 - D_8009C650_O_037A4Ptr->s70;
        flag = 1;
    }
    if (o->vx < 0) {
        o->h->s2 -= 8;
        if (o->h->s2 <= D_8009C650_O_037A4Ptr->h->s2) {
            o->h->s2 = D_8009C650_O_037A4Ptr->h->s2;
            if (flag) {
                o->s20 = 0;
                playSFX(9);
                func_800EDEBC(o, 0xd);
                func_800224FC(2, o->x12, o->y16, o->z1a);
                o->b6++;
            }
        }
    } else {
        o->y16 += 8;
        if (o->y16 + D_8009C650_O_037A4Ptr->s70 >= D_8009C650_O_037A4Ptr->y16) {
            o->y16 = D_8009C650_O_037A4Ptr->y16 - D_8009C650_O_037A4Ptr->s70;
            flag++;
        }
        o->h->s2 += 8;
        if (o->h->s2 >= D_8009C650_O_037A4Ptr->h->s2) {
            o->h->s2 = D_8009C650_O_037A4Ptr->h->s2;
            if (flag) {
                o->s20 = 0;
                playSFX(9);
                func_800EDEBC(o, 0xd);
                func_800224FC(2, o->x12, o->y16, o->z1a);
                o->b6++;
            }
        }
    }
    if (o->s20 > 10) {
        o->s20 = 0;
        playSFX(9);
        func_800EDEBC(o, 0xd);
        func_800224FC(2, o->x12, o->y16, o->z1a);
        o->b6++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801039E8);
typedef struct P_039E8 { s16 x; s16 y; } P_039E8;
typedef struct S_039E8 {
    u8 b00, b01, type, b03, b04, step, state, substep; char p0[0xf - 8];
    u8 b0f; char p1[2]; s16 x; char p2[2]; u16 y; char p3[2]; s16 z; char p4[0x20 - 0x1c];
    s16 timer; char p5[0x2e - 0x22]; u16 frame; char p6[0x40 - 0x30];
    P_039E8 *h; char p7[0x69 - 0x44]; u8 b69, b6a; char p8[0x70 - 0x6b]; u16 w70; char p9[0x7e - 0x72];
    s16 velY; char pa[0x8c - 0x80]; s32 d8c; char pb[0x9d - 0x90]; u8 b9d; char pc[0xb0 - 0x9e];
    s16 wb0, wb2, wb4, wb6, wb8, wba; char pd[0xc6 - 0xbc]; u8 bc6, bc7; char pe[0xe3 - 0xc8]; u8 be3;
} S_039E8;
extern S_039E8 *D_8009C650_S_039E8Ptr asm("D_8009C650");
extern void func_80121D5C(S_039E8 *);
void func_801039E8(S_039E8 *o)
{
    extern S_039E8 *D_8009B698;
    if (o->state == 0) {
        D_8009B698->frame = 0xff;
        D_8009B698->timer = 0;
        o->bc7 = 1;
        o->b9d = 0;
        o->bc6 = 0;
        o->be3 = 0;
        o->timer = 0;
        o->wb2 = 0;
        o->wb6 = 0;
        o->wb0 = 0;
        o->d8c = 0;
        o->frame &= 1;
        D_8009B698->b00 = 0;
        switch (D_8009C650_S_039E8Ptr->type) {
        case 0x1f:
            o->d8c = 0;
            D_8009C650_S_039E8Ptr->d8c = 0;
            o->y = D_8009C650_S_039E8Ptr->y - D_8009C650_S_039E8Ptr->w70;
            clampToCeilingAndProbeSides(o);
            D_8009C650_S_039E8Ptr->y = o->y + D_8009C650_S_039E8Ptr->w70;
            break;
        case 0x3: case 0x12: case 0x2b:
            o->wba = 0;
            o->d8c = 0;
            D_8009C650_S_039E8Ptr->d8c = 0;
            o->b69 = 0;
            D_8009C650_S_039E8Ptr->b0f = o->b0f + 1;
            func_800224FC(2, o->x, (s16)o->y, o->z);
            break;
        case 0x4: case 0x29:
            o->d8c = 0;
            D_8009C650_S_039E8Ptr->b0f = o->b0f + 1;
            D_8009C650_S_039E8Ptr->frame = 1;
            o->h->y = D_8009C650_S_039E8Ptr->h->y;
            o->y = D_8009C650_S_039E8Ptr->y - D_8009C650_S_039E8Ptr->w70;
            break;
        case 0x8: case 0x1e:
            o->d8c = 0;
            D_8009C650_S_039E8Ptr->state = 2;
        case 0x0: case 0xa:
            o->y = D_8009C650_S_039E8Ptr->y - D_8009C650_S_039E8Ptr->w70;
            clampToCeilingAndProbeSides(o);
            D_8009C650_S_039E8Ptr->y = o->y + D_8009C650_S_039E8Ptr->w70;
        case 0x28:
            D_8009C650_S_039E8Ptr->b0f = o->b0f + 1;
            o->velY = 0x100;
            break;
        case 0xe:
            func_800EDEBC(o, 0xd);
            break;
        case 0x42:
            break;
        }
        func_800EDEBC(o, 0xd);
        o->substep = 0;
        func_80028A74(0, 0, 0xff, 4);
        o->state++;
    } else {
        switch (D_8009C650_S_039E8Ptr->type) {
        case 0x2: case 0x21:
            func_80101E10(o);
            break;
        case 0x3: case 0x12: case 0x2b:
            func_80102290(o);
            break;
        case 0x29:
            if (D_8009C650_S_039E8Ptr->b6a == 1) {
                func_80103090(o);
                break;
            }
        case 0x4:
            func_80103420(o);
            break;
        case 0x0: case 0x8: case 0xa: case 0x13: case 0x1a: case 0x1e: case 0x1f: case 0x27: case 0x28:
        case 0x38: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x41: case 0x42:
            func_80102B28(o);
            break;
        case 0xb: case 0x1c:
            func_801025E0(o);
            break;
        case 0xe:
            func_80103090(o);
            break;
        case 0x15:
            func_80121D5C(o);
            break;
        case 0x18:
            func_801037A4(o);
            break;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80103D10);
typedef struct { char p[8]; u8 b; } G_03D10;
extern G_03D10 *D_8009B698;
extern u8 D_80114638[];
void func_80103D10(GameObject *o)
{
    D_8009B698->b = 0;
    o->unk9C = 0;
    o->unkA7 = 0;
    o->unkB2 = 0;
    o->velY = 0;
    *(u8 *)&o->unkAC = 0;
    o->unk8C = D_80114638[o->unkB0];
    o->subState = 0;
    o->step = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80103D54);
typedef struct { char p[8]; u8 b8; char q[0x20 - 9]; s16 w20; } G_03D54;
extern G_03D54 *D_8009B698_G_03D54Ptr asm("D_8009B698");
extern s32 D_8009BCEC_S32Arr[] asm("D_8009BCEC");
void func_800EE7F0(GameObject *o);
void func_800ED788(GameObject *o);
void func_80103D54(GameObject *o)
{
    o->h->raw += D_8009BCAC << 8;
    o->y.raw += D_8009BCAE[0] << 8;
    func_800EE7F0(o);
    func_800ED9E0(o);
    if (*(u8 *)&o->unkAC == 2) {
        D_8009C650 = *(s32 *)((char *)o + 0xe4);
        D_8009B698_G_03D54Ptr->b8 = 0;
        D_8009B698_G_03D54Ptr->w20 = 0;
        o->unk8C = 0;
        o->unkA7 = 0;
        o->unkA5 = 0;
        o->subState = 0xe;
        o->step = 0;
        return;
    }
    if (o->touchFlag == 1) {
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        D_8009B698_G_03D54Ptr->b8 = 0;
        goto reset;
    }
    if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0) != 0) {
        D_8009B698_G_03D54Ptr->b8 = 0;
        o->unk84 = 0;
        D_8009B698_G_03D54Ptr->b8 = 0;
    reset:
        o->unk9C = 0;
        o->unkA7 = 0;
        o->unkB2 = 0;
        o->velY = 0;
        *(u8 *)&o->unkAC = 0;
        o->unk8C = D_80114638[o->unkB0];
        o->subState = 0;
        o->step = 0;
        return;
    }
    if (o->animFrame & 1) {
        o->unk8C += 0x10;
        if (o->unk8C >= 0x300) {
            o->unk8C = 0x300;
            D_8009B698_G_03D54Ptr->b8 = 0;
            *((u8 *)o + 0xad) = 0;
            o->unk9C = 2;
            o->unkB2 = 0;
            D_8009B698_G_03D54Ptr->w20 = 0xe;
            if ((D_8009BCEC_S32Arr[0] & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
                o->unkA7 = 1;
            o->subState = 2;
            o->step = 3;
            func_800ED788(o);
        }
    } else {
        o->unk8C -= 0x10;
        if (o->unk8C <= 0x100) {
            o->unk8C = 0x100;
            D_8009B698_G_03D54Ptr->b8 = 0;
            *((u8 *)o + 0xad) = 0;
            o->unk9C = 2;
            o->unkB2 = 0;
            D_8009B698_G_03D54Ptr->w20 = 0xe;
            if ((D_8009BCEC_S32Arr[0] & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
                o->unkA7 = 1;
            o->subState = 2;
            o->step = 3;
            func_800ED788(o);
        }
    }
    if (*(u8 *)&o->unkAC < 2) {
        if ((D_8009E454 = func_80059B58(o, 0)) != 0) {
            D_8009B698_G_03D54Ptr->b8 = 0;
            D_8009B698_G_03D54Ptr->w20 = 0;
            *(u8 *)&o->unkAC = 0;
            o->unkA7 = 0;
            o->unk9C = 0;
            o->unkB2 = 0;
            func_800EEFEC(o, D_8009E454 == 1);
        }
    }
    if (o->subState == 0xf && !o->unk9E) func_8010D678(o, 1);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80104028);
typedef struct { char p00[0x16]; s16 s16; char p18[0x2e - 0x18]; u16 s2e; char p30[0x40 - 0x30]; s16 *p40; char p44[0x70 - 0x44]; u16 s70; char p72[0x8c - 0x72]; u32 d8c; } PL_04028;
extern PL_04028 *D_8009C650_PL_04028Ptr asm("D_8009C650");
extern s32 fixedMulCos(s32 a, s32 b);
extern s32 fixedMulSin(s32 a, s32 b);

void func_80104028(GameObject *o)
{
    s32 u = *(u16 *)((char *)o->anim + 4);
    s32 t;
    s16 r;
    PL_04028 *pl;
    o->unk88 = u;
    if (o->animFrame & 1) {
        o->unk88 = ((0x40 < u && 0xbf < u) ? 0x180 : 0x80) - u;
    }
    D_8009C650_PL_04028Ptr->s2e = o->animFrame & 1;
    r = fixedMulCos((u8)o->unk88, (s16)(D_8009C650_PL_04028Ptr->s70 + 0x10));
    D_8009C650_PL_04028Ptr->p40[1] = o->h->p.whole + r;
    pl = D_8009C650_PL_04028Ptr;
    r = fixedMulSin((u8)o->unk88, (s16)(pl->s70 + 0x10));
    pl = D_8009C650_PL_04028Ptr;
    pl->s16 = o->y.p.whole + r;
    pl->d8c = (o->unk88 - 0xc0) & 0xff;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80104118);
extern s32 clampToCeilingAndProbeSides(GameObject *);

void func_80104118(GameObject *o)
{
    GameObject *p = D_8009C650;

    p->h->p.whole = o->h->p.whole;
    p->y.p.whole = o->y.p.whole + p->hitOffsetY;
    func_800EE7F0(o);
    func_8010E444(o);
    applyObjectAltSpeedVertical(o);
    tickAnimation(o);
    if (o->velY > 0) {
        o->unk9C = 2;
        o->unk84 = 0;
        o->velY = 0;
        o->unk7 = 1;
    }
    probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
    if (clampToCeilingAndProbeSides(o) != 0) {
        o->unk9C = 2;
        o->unk84 = 0;
        o->velY = 0;
        o->unk7 = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801041F0);
void func_801041F0(GameObject *o)
{
    u16 m = *(u16 *)0x1f8001fc;
    if ((m & *(u16 *)0x1f8003c8) || (m & *(u16 *)0x1f8003c6)) {
        if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
            (*(GameObject **)&D_8009B698)->animTimer = 15;
        } else {
            (*(GameObject **)&D_8009B698)->animTimer = 14;
        }
        o->unk9C = 0;
        o->velY = 0;
        o->unk7 = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010427C);
void func_8010427C(GameObject *o)
{
    u16 m = *(u16 *)0x1F8001FC;
    if ((m & *(u16 *)0x1F8003C8) || (m & *(u16 *)0x1F8003C6)) {
        (*(P **)&D_8009B698)->w2c = 0xf;
        o->velY = 0;
        o->unk7 = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801042D8);
extern s16 func_80045310(GameObject *o, s32 x, s32 y);

void func_801042D8(GameObject *o)
{
    GameObject *p;
    GameObject *q;
    u16 t;

    switch (o->unk7) {
    case 0:
        D_8009C650->animFrame = o->animFrame & 1;
        D_8009C650->unk8C = o->unk88 - 0xc0;
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        D_8009C650->h->p.whole = o->h->p.whole;
        D_8009C650->y.p.whole = o->y.p.whole + D_8009C650->hitOffsetY;
        func_800EE7F0(o);
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->velY > 0) {
            o->unk9C = 2;
            o->unk84 = 0;
            o->velY = 0;
            o->unk7 = 1;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
        if (clampToCeilingAndProbeSides(o)) {
            o->unk9C = 2;
            o->unk84 = 0;
            o->velY = 0;
            o->unk7 = 1;
        }
        if ((D_1F8001FC & (*(u16 *)&D_1F8003C8)) || (D_1F8001FC & (*(u16 *)&D_1F8003C6))) {
            if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
                D_8009B698_GameObjectPtr->animTimer = 0xf;
            } else {
                D_8009B698_GameObjectPtr->animTimer = 0xe;
            }
            o->unk9C = 0;
            o->velY = 0;
            o->unk7 = 2;
        }
        break;
    case 1:
        func_800EE7F0(o);
        p = D_8009C650;
        p->animFrame = o->animFrame & 1;
        p->h->p.whole = o->h->p.whole;
        p->y.p.whole = o->y.p.whole + p->hitOffsetY;
        p->unk8C = o->unk88 - 0xc0;
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        func_800ED9E0(o);
        tickAnimation(o);
        if (o->touchFlag != 0 || func_80045310(o, o->h->p.whole, (s16)(o->y.p.whole + 0x30)) != 0 ||
            (D_1F8001FC & (*(u16 *)&D_1F8003C8)) || (D_1F8001FC & (*(u16 *)&D_1F8003C6)) || ((s16 (*)(GameObject *o, s32 a, s32 b))probeSidesAndApplyTileResponse)(o, 4, 0) != 0) {
            if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
                D_8009B698_GameObjectPtr->animTimer = 0xf;
            } else {
                D_8009B698_GameObjectPtr->animTimer = 0xe;
            }
            o->unk9C = 0;
            o->velY = 0;
            o->unk7 = 2;
        }
        break;
    case 2:
        if (D_8009B698_GameObjectPtr->animFrame != D_8009B698_GameObjectPtr->animTimer) {
            D_8009C650->step = 7;
            func_800EEF64(o);
            readAnimFrameCount(o);
            D_8009B698_GameObjectPtr->animFrame = D_8009B698_GameObjectPtr->animTimer;
        }
        if (tickAnimation(o)) {
            playSFXWithNote(0x22, 0x23);
            switch (D_8009C650->type) {
            case 0x21:
            case 0x3b: case 0x3c: case 0x3d: case 0x3e:
            case 0x3f: case 0x40: case 0x41: case 0x42:
                break;
            default:
                {GameObject *q = allocObjectLayer1();
                if (q) {
                    q->active = 1;
                    q->type = 1;
                    switch (D_8009C650->type) {
                    case 0:
                        q->subtype = 3;
                        break;
                    case 2:
                        switch ((*(u16 *)&GAME)) {
                        case 0: case 1: case 2:
                            q->subtype = 0;
                            break;
                        case 3:
                            q->subtype = 8;
                            break;
                        }
                        break;
                    case 0x3a:
                        q->subtype = 0xc;
                        break;
                    case 0x1a:
                        q->type = 4;
                        q->subtype = 0;
                        break;
                    case 0x27:
                        q->subtype = 0xd;
                        break;
                    case 8:
                        q->subtype = 1;
                        break;
                    case 0x1e:
                        q->subtype = 9;
                        break;
                    case 0xa:
                        q->subtype = 4;
                        q->unkD = D_8009C650->unkD;
                        break;
                    case 0x13:
                        q->subtype = 5;
                        break;
                    case 0x28:
                        q->subtype = 7;
                        break;
                    case 0xb:
                        q->subtype = D_8009C650->subtype << 1;
                        break;
                    case 0x38:
                        q->subtype = D_8009C650->subtype + 10;
                        break;
                    }
                    t = o->animFrame & 1;
                    q->animFrame = t;
                    if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
                        q->animFrame = t | 2;
                    }
                    q->x.p.whole = o->x.p.whole;
                    q->y.p.whole = o->y.p.whole;
                    q->z.p.whole = o->z.p.whole;
                    {
s32 c = o->animFrame & 1; Fix16 *h = q->h; s32 w = h->p.whole; s32 r;
                        if (c) r = w - 0x10; else r = w + 0x10; h->p.whole = r;
                    }
                }}
                break;
            }
            o->velY = 0;
            func_800EDEBC(o, 0x1d);
            o->unk8C = 0x200;
            o->unk7 = 3;
        } else {
            func_80104028(o);
        }
        break;
    case 3: {
        GameObject *p = D_8009C650;
        switch (p->type) {
        case 0x13:
            for (q = (GameObject *)p->unk90; q != 0; q = (GameObject *)q->unk90) {
                q->state = 3;
            }
            for (q = (GameObject *)D_8009C650->unk94; q != 0; q = (GameObject *)q->unk94) {
                q->state = 3;
            }
            break;
        case 0x21:
            p->state = 2;
            D_8009C650->subState = 2;
            D_8009C650->step = 0;
            break;
        case 0x3b: case 0x3c: case 0x3d: case 0x3e:
        case 0x3f: case 0x40: case 0x41: case 0x42:
            D_8009C650->state = 2;
            D_8009C650->subState = 3;
            D_8009C650->step = 0;
            {GameObject *q = D_8009C650; u16 t;
            t = o->animFrame & 1;
            q->animFrame = t;
            if (*(volatile u16 *)&D_8009C9D8 & 0x40) {
                q->animFrame = t | 2;
            }}
            break;
        default:
            D_8009C650->state = 3;
            break;
        }
        o->unkB2 = 0x100;
        o->unk9C = 2;
        *(u8 *)&o->unkAC = 1;
        o->velY = 0;
        o->unk7 = 4;
        break; }
    case 4:
        func_80103D54(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801049E4);
extern s16 func_80045310(GameObject *o, s32 x, s32 y);

void func_801049E4(GameObject *o)
{
    GameObject *p;
    switch (o->unk7) {
    case 0:
        p = D_8009C650;
        p->unk8C = o->unk88 - 0xc0;
        p->h->p.whole = o->h->p.whole;
        p->y.p.whole = o->y.p.whole + p->hitOffsetY;
        func_800EE7F0(o);
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->velY > 0) {
            o->unk9C = 2;
            o->unk84 = 0;
            o->velY = 0;
            o->unk7 = 1;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
        if (clampToCeilingAndProbeSides(o)) {
            o->unk9C = 2;
            o->unk84 = 0;
            o->velY = 0;
            o->unk7 = 1;
        }
        if ((D_1F8001FC & (*(u16 *)&D_1F8003C8)) || (D_1F8001FC & (*(u16 *)&D_1F8003C6))) {
            (*(GameObject **)&D_8009B698)->animTimer = 0xf;
            o->velY = 0;
            o->unk7 = 2;
            break;
        }
        break;
    case 1:
        func_800EE7F0(o);
        p = D_8009C650;
        p->h->p.whole = o->h->p.whole;
        p->y.p.whole = o->y.p.whole + p->hitOffsetY;
        p->unk8C = o->unk88 - 0xc0;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->touchFlag != 0 || func_80045310(o, o->h->p.whole, (s16)(o->y.p.whole + 0x40)) != 0 ||
            (D_1F8001FC & (*(u16 *)&D_1F8003C8)) || (D_1F8001FC & (*(u16 *)&D_1F8003C6)) || ((s16 (*)(GameObject *o, s32 a, s32 b))probeSidesAndApplyTileResponse)(o, 4, 0) != 0) {
            o->unk9C = 0;
            o->velY = 0;
            o->unk7 = 2;
            break;
        }
        break;
    case 2:
        func_800EDEBC(o, 0xf);
        if (tickAnimation(o)) {
            GameObject *q;
            playSFXWithNote(0x22, 0x23);
            q = allocObjectLayer1();
            if (q) {
                GameObject *r;
                q->active = 1;
                q->type = 2;
                r = D_8009C650;
                q->animFrame = (o->animFrame & 1) | 2;
                q->x.p.whole = o->x.p.whole;
                q->y.p.whole = o->y.p.whole + r->hitOffsetY;
                q->z.p.whole = o->z.p.whole;
                q->objectIndex = r->objectIndex;
                q->unk1D = D_8009C650->unk1D;
                q->subtype = D_8009C650->subtype;
                q->unkC = D_8009C650->unkC;
            }
            D_8009C650->state = 3;
            *(u8 *)&o->unkAC = 1;
            o->velY = 0;
            o->unk7 = 3;
        } else {
            func_80104028(o);
        }
        break;
    case 3:
        func_800EDEBC(o, 0x1d);
        o->unk8C = 0x200;
        o->unkB2 = 0x100;
        o->unk9C = 2;
        o->velY = 0;
        o->unk7 = 4;
        break;
    case 4:
        func_80103D54(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80104D84);
typedef struct {
    char p0[5];
    u8 step;
    u8 state;
    char p7[0x7e - 7];
    s16 w7e;
    char p80[4];
    s32 d84;
    char p88[4];
    s32 d8c;
    char p90[0x9c - 0x90];
    u8 b9c;
    char p9d[0xa7 - 0x9d];
    u8 ba7;
    char pa8[0xab - 0xa8];
    u8 bab;
    u8 bac;
    char pad[0xb0 - 0xad];
    s16 wb0;
    s16 wb2;
} S_04D84;
typedef struct { char p[8]; u8 b8; } U_04D84;

void func_80104D84(S_04D84 *o)
{
    o->d8c = D_80114638[o->wb0];
    (*(U_04D84 **)&D_8009B698)->b8 = 0;
    o->b9c = 0;
    o->ba7 = 0;
    o->bac = 0;
    o->d84 = 0;
    o->wb2 = 0;
    o->w7e = 0;
    if (D_8009C650->type == 0x1c) {
        switch (D_8009C619) {
        case 1:
            o->bac = 0;
            o->step = 0x2a;
            o->state = 0;
            o->bab |= 0x80;
            return;
        case 2:
            o->bac = 0;
            o->step = 0x2b;
            o->state = 0;
            o->bab |= 0x80;
            return;
        }
        o->bac = 0;
    }
    o->step = 0;
    o->state = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80104E34);
extern char *D_8009B698_CharPtr asm("D_8009B698");

void func_80104E34(GameObject *o)
{
    char *p, *q;
    s32 t;
    volatile u16 *r;
    D_8009B698_CharPtr[8] = 0;
    *((u8 *)o + 0xad) = 0;
    p = D_8009B698_CharPtr;
    q = D_8009C650;
    *(s16 *)((char *)o + 0xb2) = 0;
    *(s16 *)(p + 0x20) = 0xe;
    if (q[2] == 0x1c && (t = D_8009C619) < 3 && t != 0)
        *((u8 *)o + 0xab) |= 0x80;
    if ((D_8009BCEC & 0x40) && (*(r = &D_8009C9D8) & (*(u16 *)&D_1F8003C4)))
        *((u8 *)o + 0xa7) = 1;
    func_800ED788(o);
    o->subState = 2;
    o->step = 3;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80104F1C);

#define LAND() \
    o->unk8C = D_80114638[o->unkB0]; \
    *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = 0; \
    o->unk9C = 0; \
    o->unkA7 = 0; \
    *(u8 *)((u8 *)o + 0xac) = 0; \
    o->unk84 = 0; \
    o->unkB2 = 0; \
    o->velY = 0; \
    if (D_8009C650->type == 0x1c) { \
        switch (D_8009C619) { \
        case 1: \
            *(u8 *)((u8 *)o + 0xac) = 0; \
            o->subState = 0x2a; \
            o->step = 0; \
            *(u8 *)((u8 *)o + 0xab) |= 0x80; \
            return; \
        case 2: \
            *(u8 *)((u8 *)o + 0xac) = 0; \
            o->subState = 0x2b; \
            o->step = 0; \
            *(u8 *)((u8 *)o + 0xab) |= 0x80; \
            return; \
        default: \
            *(u8 *)((u8 *)o + 0xac) = 0; \
        } \
    } \
    o->subState = 0; \
    o->step = 0;

#define TURN() \
    *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = 0; \
    *(u8 *)((u8 *)o + 0xad) = 0; \
    o->unkB2 = 0; \
    D_8009B698_GameObjectPtr->timer = 0xe; \
    if (D_8009C650->type == 0x1c && (t = D_8009C619) < 3 && t != 0) \
        *(u8 *)((u8 *)o + 0xab) |= 0x80; \
    if ((D_8009BCEC & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4))) \
        o->unkA7 = 1; \
    func_800ED788(o); \
    o->subState = 2; \
    o->step = 3;

void func_80104F1C(GameObject *o)
{
    GameObject *p;
    s32 t;

    switch (o->unk7) {
    case 0:
        D_8009C650->animFrame = o->animFrame & 1;
        D_8009C650->d->p.whole = o->d->p.whole;
        D_8009C650->subState = 1;
        D_8009C650->step = 6;
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        func_8010DE48(o);
        if (D_8009C650->type != 0x1c)
            o->h->raw += o->velX << 8;
        p = D_8009C650;
        p->h->p.whole = o->h->p.whole;
        p->y.p.whole = o->y.p.whole + p->hitOffsetY;
        func_800EE7F0(o);
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->velY > 0) {
            o->unk84 = 0;
            o->unk9C = 2;
            o->velY = 0;
            o->unk7 = 1;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
        if (clampToCeilingAndProbeSides(o)) {
            o->unk84 = 0;
            o->unk9C = 2;
            o->velY = 0;
            o->unk7 = 1;
        }
        if ((D_1F8001FC & (*(u16 *)&D_1F8003C8)) || (D_1F8001FC & (*(u16 *)&D_1F8003C6))) {
            D_8009B698_GameObjectPtr->animTimer = 0xf;
            o->velY = 0;
            o->unk7 = 2;
        }
        break;
    case 1:
        func_800EE7F0(o);
        p = D_8009C650;
        p->animFrame = o->animFrame & 1;
        p->h->p.whole = o->h->p.whole;
        p->y.p.whole = o->y.p.whole + p->hitOffsetY;
        p->unk8C = o->unk88 - 0xc0;
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        func_8010DE48(o);
        if (D_8009C650->type != 0x1c)
            o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->touchFlag != 0 || func_80045310(o, o->h->p.whole, (s16)(o->y.p.whole + 0x30)) != 0 ||
            (D_1F8001FC & (*(u16 *)&D_1F8003C8)) || (D_1F8001FC & (*(u16 *)&D_1F8003C6)) || ((s16 (*)(GameObject *o, s32 a, s32 b))probeSidesAndApplyTileResponse)(o, 4, 0) != 0) {
            o->velY = 0;
            o->unk7 = 2;
        }
        break;
    case 2:
        func_800EDEBC(o, 0xf);
        if (tickAnimation(o)) {
            playSFXWithNote(0x22, 0x23);
            o->velY = 0;
            D_8009B698_GameObjectPtr->animTimer = 0x1d;
            o->unk7 = 3;
        } else {
            func_80104028(o);
        }
        break;
    case 3:
        switch (D_8009C650->type) {
        case 0x1f:
            D_8009C650->state = 2;
            D_8009C650->subState = 1;
            break;
        case 3:
        case 0x2b:
            D_8009C650->state = 2;
            D_8009C650->subState = 2;
            break;
        case 0x12:
            D_8009C650->state = 2;
            D_8009C650->subState = 3;
            break;
        case 0x1c:
            *(u8 *)((u8 *)o + 0xab) = 0;
            switch (D_8009C650->subtype) {
            case 0 ... 2:
                D_8009C619 = D_8009C650->subtype;
                break;
            case 4:
                D_8009C26E = 1;
                break;
            }
            D_8009C650->subState = 3;
            D_8009C650->step = 0;
            goto anim;
        default:
            t = (s32)D_8009C650;
            ((GameObject *)t)->state = 3;
            D_8009C650->subState = 0;
            break;
        }
        D_8009C650->step = 0;
    anim:
        func_800EEF64(o);
        readAnimFrameCount(o);
        D_8009B698_GameObjectPtr->animFrame = D_8009B698_GameObjectPtr->animTimer;
        o->unk8C = 0x200;
        o->unkB2 = 0x100;
        o->unk9C = 2;
        *(u8 *)((u8 *)o + 0xac) = 1;
        o->velY = 0;
        o->unk7 = 4;
        break;
    case 4:
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        func_800EE7F0(o);
        func_800ED9E0(o);
        if (*(u8 *)((u8 *)o + 0xac) == 2) {
            D_8009C650 = (GameObject *)*(s32 *)((u8 *)o + 0xe4);
            *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = 0;
            D_8009B698_GameObjectPtr->timer = 0;
            o->unkA7 = 0;
            o->unkA5 = 0;
            o->subState = 0xe;
            o->step = 0;
            *(u8 *)((u8 *)o + 0xab) &= 0x7f;
            break;
        }
        if (o->touchFlag == 1) {
            LAND();
            break;
        }
        if (((s16 (*)(GameObject *o, s32 a, s32 b))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            LAND();
            break;
        }
        if (o->animFrame & 1) {
            o->unk8C += 0x10;
            if (o->unk8C >= 0x300) {
                o->unk8C = 0x300;
                TURN();
            }
        } else {
            o->unk8C -= 0x10;
            if (o->unk8C <= 0x100) {
                o->unk8C = 0x100;
                TURN();
            }
        }
        if (*(u8 *)((u8 *)o + 0xac) < 2) {
            D_8009E454 = func_80059B58(o, 0);
            if (D_8009E454) {
                *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = 0;
                D_8009B698_GameObjectPtr->timer = 0;
                *(u8 *)((u8 *)o + 0xac) = 0;
                o->unkA7 = 0;
                o->unk9C = 0;
                o->unkB2 = 0;
                func_800EEFEC(o, D_8009E454 == (GameObject *)1);
            }
        }
        if (o->subState == 0xf && o->unk9E == 0)
            func_8010D678(o, 1);
        break;
    }
}
#undef LAND
#undef TURN

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80105820);
void func_80105820(u8 *o)
{
    u8 *q;
    switch (o[7]) {
    case 0:
        q = D_8009C650;
        *(s16 *)(o + 0x7c) = 0;
        if (q[2] == 0x29)
            q[5] = 3;
        else {
            q[5] = 1;
            o[0xac] = 0;
        }
        playSFXWithNote(0x22, 0x23);
        o[7] = o[7] + 1;
    case 1:
        **(s32 **)(o + 0x40) += D_8009BCAC << 8;
        *(s32 *)(o + 0x14) += (*(s16 *)&D_8009BCAE) << 8;
        func_800ED9E0(o);
        tickAnimation(o);
        if (*(s16 *)(o + 0x7e) > 0) {
            *(s32 *)(o + 0x84) = 0;
            o[0x9c] = 2;
            *(s16 *)(o + 0x7e) = 0;
            o[0xac] = 1;
            if ((D_8009BCEC & 0x40) != 0 && (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1f8003c4) != 0)
                o[0xa7] = 1;
            func_800ED788(o);
            o[5] = 2;
            o[6] = 3;
            o[7] = 0;
        }
        probeCollisionAtDepthA(o, (*(s16 **)(o + 0x40))[1], (s16)(*(u16 *)(o + 0x16) + 0x10));
        if (clampToCeilingAndProbeSides(o) != 0) {
            *(s32 *)(o + 0x84) = 0;
            o[0x9c] = 2;
            o[0xac] = 1;
            *(s16 *)(o + 0x7e) = 0;
            if ((D_8009BCEC & 0x40) != 0 && (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1f8003c4) != 0)
                o[0xa7] = 1;
            func_800ED788(o);
            o[5] = 2;
            o[6] = 3;
            o[7] = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80105A14);
typedef struct { char pad[9]; u8 b9; char pad2[0x20 - 10]; s16 w20; } P_05A14;
extern void func_8011C730(GameObject *);
extern void func_80120708(GameObject *);

void func_80105A14(GameObject *o)
{
    GameObject *q;
    switch (o->step) {
    case 0:
        switch (D_8009C650->type) {
        case 19:
            (*(P_05A14 **)&D_8009B698)->w20 = 0;
            D_8009C650->unk84 = 0;
            func_8010E678(o);
            break;
        case 0: case 2: case 8: case 10: case 11: case 18: case 30: case 33: case 40:
        case 56: case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66:
            D_8009C650->animFrame = o->animFrame & 1;
        case 4: case 26:
            q = D_8009C650;
            (*(P_05A14 **)&D_8009B698)->w20 = 0;
            {
            s32 t;
            Fix16 *dst = q->h;
            t = o->h->p.whole;
            dst->p.whole = (o->animFrame & 1) ? t + 8 : t - 8;
            }
            goto tail;
        case 3: case 28: case 31: case 43:
            (*(P_05A14 **)&D_8009B698)->w20 = 0;
            D_8009C650->animFrame = o->animFrame & 1;
            {
            s32 t = o->h->p.whole;
            D_8009C650->h->p.whole = (o->animFrame & 1) ? t + 8 : t - 8;
            }
            goto tail;
        case 41:
            if (D_8009C650->unk6A != 1) goto e41;
        case 14:
            (*(P_05A14 **)&D_8009B698)->w20 = 13;
            o->velY = -0x600;
            break;
        e41:
            (*(P_05A14 **)&D_8009B698)->w20 = 0;
            {
            s32 t = o->h->p.whole;
            D_8009C650->h->p.whole = (o->animFrame & 1) ? t + 8 : t - 8;
            }
        tail:
            D_8009C650->y.p.whole = o->y.p.whole + 8;
            D_8009C650->unk8C = o->unk88 - 0xc0;
            func_8010E678(o);
            break;
        }
        func_800EE7F0(o);
        o->unk88 = 0x1c0;
        o->unk8C = 0;
        o->unkB2 = 0;
        o->unkB0 = 0;
        (*(P_05A14 **)&D_8009B698)->b9 = D_8009C650->type;
        o->touchFlag = 0;
        o->velV = 0;
        func_800EDEBC(o, 13);
        if ((D_8009BCEC & 0x40) && (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4)) {
            o->unkA7 = 1;
        } else {
            o->unkA7 = 0;
        }
        o->step = 1;
        o->unk7 = 0;
    case 1:
        if ((*(P_05A14 **)&D_8009B698)->b9 != 14) {
            func_800F198C(o);
        }
    case 2:
        switch ((*(P_05A14 **)&D_8009B698)->b9) {
        case 0: case 2: case 8: case 10: case 11: case 30: case 33: case 40:
        case 56: case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66:
            func_801042D8(o);
            break;
        case 3: case 18: case 28: case 31: case 43:
            func_80104F1C(o);
            break;
        case 41:
            if (D_8009C650->unk6A == 1) {
                func_80105820(o);
                break;
            }
        case 4:
            func_801049E4(o);
            break;
        case 14:
            func_80105820(o);
            break;
        case 26:
            func_8011C730(o);
            break;
        case 19:
            func_80120708(o);
            break;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80105D68);
typedef struct {
    char p0[5]; u8 a5, a6, a7; char p1[0x20 - 8]; s16 s20; char p2[0x2e - 0x22]; u16 af;
    char p3[0x69 - 0x30]; u8 b69; char p4[0x8c - 0x6a]; s32 d8c; char p5[0x9c - 0x90]; u8 b9c, b9d;
    char p6[0xac - 0x9e]; u8 bac; char p7[3]; s16 wb0, wb2; char p8[2]; s16 wb6; char p9[0xc6 - 0xb8];
    u8 bc6, bc7; char pa[0xe3 - 0xc8]; u8 be3;
} O_05D68;
typedef struct { u8 z; char p[0x1f]; s16 s20; } P_05D68;
typedef struct { char p[2]; u8 k; } K_05D68;
extern P_05D68 *D_8009B698_P_05D68Ptr asm("D_8009B698");
extern void func_800EE1F0(O_05D68 *);
extern void func_8011BA78(O_05D68 *);
extern void func_8011C914(O_05D68 *);
extern void func_8011A7C0(O_05D68 *);

void func_80105D68(O_05D68 *o)
{
    if (o->a6 == 0) {
        D_8009B698_P_05D68Ptr->s20 = 0;
        o->bc7 = 1;
        o->b9d = 0;
        o->bc6 = 0;
        o->be3 = 0;
        o->s20 = 0;
        o->wb2 = 0;
        o->wb6 = 0;
        o->wb0 = 0;
        o->d8c = 0;
        o->af = o->af & 1;
        D_8009B698_P_05D68Ptr->z = 0;
        func_800EDEBC(o, 13);
        o->a7 = 0;
        o->a6 = o->a6 + 1;
    } else {
        switch ((*(K_05D68 **)&D_8009C650)->k) {
        case 0xe:
            func_8011BA78(o);
            break;
        case 0x27:
            func_8011C914(o);
            break;
        case 0x3d:
            func_8011A7C0(o);
            break;
        default:
            func_800EE1F0(o);
            o->b9c = 0;
            o->b69 = 0;
            o->bac = 0;
            o->wb2 = 0;
            o->a5 = 0x3e;
            o->a6 = 0;
            break;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80105EA0);
extern void func_800EDD9C(GameObject *);
extern void func_800EDBEC(GameObject *);
extern void func_801104BC(GameObject *);
extern void func_800EDD2C(GameObject *);

void func_80105EA0(GameObject *o)
{
    s32 t;
    u8 u;
    switch (o->step) {
    case 0:
        o->unkB2 = 0;
        func_800EDEBC(o, 0x28);
        playSFX(0x20);
        if (*((u8 *)o + 0xab) & 0x80) {
            o->active = 3;
            o->timer = 0x3c;
            o->step++;
        } else {
            o->timer = 0x28;
            o->step = 2;
        }
        break;
    case 1:
        func_800EDD9C(o);
        if (o->velY > 0x400) {
            *((u8 *)o + 0xac) = 1;
            D_8009B698_U8Ptr[0x1e] = 0;
            D_8009B698_U8Ptr[0x1f] = 0;
            func_800ED788(o);
            o->subState = 2;
            o->step = 3;
        }
        func_800EDBEC(o);
        func_801104BC(o);
        func_800EDD2C(o);
        tickAnimation(o);
        if (--o->timer <= 0) {
            o->active = 1;
            o->unkB2 = 0;
            *((u8 *)o + 0xac) = 0;
            *((u8 *)o + 0xab) = 0;
            u = D_80114638[o->unkB0];
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk8C = u;
            break;
        }
        break;
        {
            o->subState = 0;
            o->step = 0;
            o->unk8C = t;
        }
        break;
    case 2:
        *((u8 *)o + 0xab) = 1;
        o->animFrame = (o->animFrame & 1) | 2;
        o->step++;
    case 3:
        func_800EDD9C(o);
        if (o->velY > 0x400) {
            *((u8 *)o + 0xac) = 1;
            D_8009B698_U8Ptr[0x1e] = 0;
            D_8009B698_U8Ptr[0x1f] = 0;
            func_800ED788(o);
            o->subState = 2;
            o->step = 3;
        }
        func_800EDBEC(o);
        func_801104BC(o);
        func_800EDD2C(o);
        tickAnimation(o);
        if (--o->timer <= 0) {
            t = D_80114638[o->unkB0];
            *((u8 *)o + 0xab) = 0;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk8C = t;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80106100);
void func_80106100(GameObject *o)
{
    u16 t, f;
    s32 b, c;
    s16 sv;
    switch (o->step) {
    case 0:
        o->unkB2 = 0;
        func_800EDEBC(o, 0x29);
        playSFXWithNote(0x25, 0x28);
        if (*((u8 *)o + 0xab) & 0x80) {
            o->active = 3;
            o->timer = 0x3c;
            o->step = o->step + 1;
        } else {
            o->timer = 0x1e;
            o->step = 2;
            func_800EDEBC(o, 0x36);
        }
        break;
    case 1:
        func_800EDD9C(o);
        func_800EDBEC(o);
        func_800EDD2C(o);
        tickAnimation(o);
        t = o->timer - 1;
        o->timer = t;
        if ((s16)t <= 0) {
            o->active = 1;
            b = D_80114638[o->unkB0];
            o->unkB2 = 0;
            *((u8 *)o + 0xac) = 0;
            *((u8 *)o + 0xab) = 0;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk8C = b;
        }
        break;
    case 2:
        f = o->animFrame;
        *((u8 *)o + 0xab) = 2;
        *((u8 *)o + 0xac) = 2;
        f = f & 1;
        o->animFrame = f;
        sv = 0x280;
        if (f != 0)
            sv = -0x280;
        o->unkB2 = sv;
        o->step = o->step + 1;
    case 3:
        func_800EDD9C(o);
        func_800EDBEC(o);
        func_800EDD2C(o);
        tickAnimation(o);
        t = o->timer - 1;
        o->timer = t;
        if ((s16)t <= 0) {
            c = D_80114638[o->unkB0];
            o->unkB2 = 0;
            *((u8 *)o + 0xac) = 0;
            *((u8 *)o + 0xab) = 0;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk8C = c;
        }
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801062E8);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010633C);
typedef struct { char p[0x2c]; u16 w2c; u16 w2e; } G_0633C;
extern G_0633C *D_8009B698_G_0633CPtr asm("D_8009B698");
void func_800EE844(GameObject *o);
void func_8010F1C0(GameObject *o);
void func_8010633C(GameObject *o)
{
    G_0633C *g;
    switch (o->step) {
    case 0:
        *((u8 *)o + 0xd5) = 0;
        *((u8 *)o + 0xd6) = 0;
        *((u8 *)o + 0xd7) = 0;
        *((u8 *)o + 0xbf) = 0;
        g = D_8009B698_G_0633CPtr;
        o->velX = 0;
        o->velY = 0;
        g->w2c = 0x1a;
        if ((D_8009BCEC_S32Arr[0] & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
            g->w2c = 0x2a;
        if (D_8009B698_G_0633CPtr->w2e != D_8009B698_G_0633CPtr->w2c) {
            func_800EEF64(o);
            readAnimFrameCount(o);
            D_8009B698_G_0633CPtr->w2e = D_8009B698_G_0633CPtr->w2c;
        }
        o->step++;
    case 1:
        func_800EE844(o);
        func_800EDD9C(o);
        func_8010F1C0(o);
        if (o->touchFlag & 2) {
            tickAnimation(o);
            func_8010F1C0(o);
            o->touchFlag = 1;
        }
        func_800EDD2C(o);
        func_800EDBEC(o);
        func_800EF40C(o);
        if (tickAnimation(o)) goto stop;
        if ((o->animFrame & 1) && o->unkB2 < 0) {
            o->subState = 1;
            o->step = 0;
        }
        if (!(o->animFrame & 1) && o->unkB2 > 0) {
            o->subState = 1;
            o->step = 0;
        }
        if ((o->animFrame & 2) && o->animFrame < 4) {
            D_8009B698_G_0633CPtr->w2e = 0xffff;
            o->subState = 0;
            o->step = 0;
        }
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            D_8009C618[0] = 0;
            o->unk9C = 1;
            if ((D_8009BCEC_S32Arr[0] & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
                o->unkA7 = 1;
            o->subState = 2;
            o->step = 0;
        }
        func_8010D678(o, 0);
        break;
    case 2:
        tickAnimation(o);
        func_800EDD9C(o);
        applyObjectAltSpeedVertical(o);
        o->velY += 0x30;
        if (o->velY > 0) o->unk9C = 2;
        if (o->touchFlag != 0) break;
        if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0) == 0) break;
    stop:
        o->unk9C = 0;
        o->velX = 0;
        o->velY = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010664C);
void func_8010664C(GameObject *o)
{
    ((u8 *)o)[0xc7] = 1;
    o->unk9D = 0;
    ((u8 *)o)[0xc6] = 0;
    ((u8 *)o)[0xe3] = 0;
    D_8009B698_U8Ptr[0] = 0;
    o->movetab = ((char *)&D_8007722C);
    *(u8 *)&o->unkAC = 0;
    o->objectIndex = 0;
    o->unkA4 = 0;
    o->unk84 = 0;
    o->unk88 = 0;
    o->unk8C = 0;
    D_8009B698_U8Ptr[8] = o->unkBE & 1;
    if (D_8009B698_U8Ptr[8] == 0) {
        if (o->unkB2 < -0x144) o->unkB2 = -0x144;
    } else {
        if (o->unkB2 > 0x144) o->unkB2 = 0x144;
    }
    o->step = 1;
    o->animFrame = o->unkBE & 1;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80106710);
extern void tickAnimation(GameObject *);

void func_80106710(GameObject *o)
{
    P *p;
    u8 b;
    s32 a;
    u32 d;
    if ((u16)(o->unkB2 + 0x144) >= 0x289) {
        p = D_8009B698_PPtr;
        p->w2c = 0x11;
        if (p->w2e != 0x11) {
            o->unk84 = 0;
            ((void (*)())func_800EEF64)();
            readAnimFrameCount(o);
            D_8009B698_PPtr->w2e = D_8009B698_PPtr->w2c;
        }
        b = o->objectIndex;
        o->unkA4 = 1;
        if (b < 0xff)
            b += 2;
        o->objectIndex = b;
        if (o->animFrame & 1)
            d = (0x100 - (b >> 2)) & 0xff;
        else
            d = b >> 2;
        o->unk8C = d;
        if ((D_1F8001F8 & 0x1f) == 0) {
            switch ((*(u16 *)&GAME)) {
            case 0:
                a = 0x37;
                break;
            case 1:
                switch (D_8009BCCA) {
                case 0:
                case 1:
                    a = 0x3f;
                    break;
                case 3:
                    a = 0x59;
                    break;
                case 5:
                    a = 0x90;
                    break;
                default:
                    goto end;
                }
                break;
            default:
                goto end;
            }
            playSFXWithNote(a, 2);
        }
    } else {
        func_800EEDE0(o);
        func_800EE844(o);
        D_8009B698_PPtr->b08 = 0;
        o->unk9C = 0;
        o->unk88 = 0;
        o->unkA4 = 0;
        o->subState = 1;
        o->step = 0;
    }
end:
    tickAnimation(o);
    func_800EDD9C(o);
    o->y.raw += 0x120000;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801068E0);
void func_801068E0(GameObject *o)
{
    o->unk9C = 1;
    o->unk88 = -0x100;
    o->unkA4 = 0;
    if (o->unkA6 & 6) {
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
    }
    o->subState = 0x10;
    o->step = 2;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80106928);
extern void func_8010F604(GameObject *);
extern void applyFrameVelocityX(GameObject *);

void func_80106928(GameObject *o)
{
    u8 *g;
    u8 b;

    switch (o->step) {
    case 0:
        ((u8 *)o)[0xc7] = 1;
        o->unk9D = 0;
        ((u8 *)o)[0xc6] = 0;
        ((u8 *)o)[0xe3] = 0;
        D_8009B698_U8Ptr[0] = 0;
        o->movetab = ((char *)&D_8007722C);
        *(u8 *)&o->unkAC = 0;
        o->objectIndex = 0;
        o->unkA4 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        D_8009B698_U8Ptr[8] = o->unkBE & 1;
        if (D_8009B698_U8Ptr[8] == 0) {
            if (o->unkB2 < -0x144) o->unkB2 = -0x144;
        } else {
            if (o->unkB2 > 0x144) o->unkB2 = 0x144;
        }
        o->step = 1;
        o->animFrame = o->unkBE & 1;
    case 1:
        func_80106710(o);
        func_8010F604(o);
        func_800EDD2C(o);
        if (o->unkBE == 0) {
            g = D_8009B698_U8Ptr;
            if (g[8] == o->animFrame) goto L;
            g[8] = 0;
            o->unk9C = 0;
            o->unk88 = 0;
            b = D_80114638[o->unkB0];
            o->unkA4 = 0;
            o->subState = 1;
            o->step = 0;
            o->unk8C = b;
        } else if (o->unkA6 >= 2) {
        L:
            o->unk9C = 1;
            o->unk88 = -0x100;
            o->unkA4 = 0;
            if (o->unkA6 & 6) {
                o->unkB2 = 0;
                o->velH = 0;
                o->velV = 0;
                o->velX = 0;
                o->velY = 0;
            }
            o->subState = 0x10;
            o->step = 2;
        }
        func_800EF40C(o);
        if (*(u16 *)0x1F8001FC & *(u16 *)0x1F8003C6) {
            D_8009C618[0] = 0;
            if (o->unkB2 > 0x200) o->unkB2 = 0x200;
            if (o->unkB2 < -0x200) o->unkB2 = -0x200;
            o->unkA4 = 0;
            o->unk9C = 1;
            if (((s32 *)&D_8009BCEC)[0] & 0x40) {
                if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4) {
                    o->unkA7 = 1;
                }
            }
            o->subState = 2;
            o->step = 0;
        }
        if (*(u16 *)(D_8009B698_U8Ptr + 0x2c) < 4) {
            o->unk8C = (-o->unkB0 << 2) & 0xff;
        }
        if (o->unkA4) {
            if ((D_1F8001F8 & 3) == 0) func_80028A74(0, 0, 0xff, 2);
            if ((D_1F8001F8 & 0xf) == 0) func_800EA16C(o->h->p.whole, o->y.p.whole, o->d->p.whole, 0);
        }
        break;
    case 2:
        if (o->objectIndex + 0x20 < 0x100) o->objectIndex = o->objectIndex + 0x20; else o->objectIndex = 0xff;
        o->h->raw += ((s16 *)&D_8009BCAC)[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        applyFrameVelocityX(o);
        ((s32 (*)(GameObject *))tickAnimation)(o);
        o->unk8C = (o->animFrame & 1) ? 0x100 - (o->objectIndex >> 2) : o->objectIndex >> 2;
        o->y.raw += o->unk88 << 8;
        o->unk88 += 0x20;
        if (o->unk88 > 0) {
            o->timer = 4;
            o->step = 3;
        }
        break;
    case 3:
        if (--o->timer == 0) {
            o->unk9C = 2;
            func_800EDEBC(o, 0x12);
            o->step++;
        }
        break;
    case 4:

        if (o->objectIndex - 0x20 < 0) o->objectIndex = 0; else o->objectIndex -= 0x20;
        applyFrameVelocityX(o);
        o->unk8C = (o->animFrame & 1) ? 0x100 - (o->objectIndex >> 2) : o->objectIndex >> 2;
        o->y.raw += o->unk88 << 8;
        o->unk88 += 0x20;
        if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            if (((s32 (*)(GameObject *))tickAnimation)(o)) {
                o->unkA7 = 0;
                D_8009B698_U8Ptr[8] = 0;
                o->unk9C = 0;
                o->unk88 = 0;
                b = D_80114638[o->unkB0];
                o->unkA4 = 0;
                o->unk8C = b;
                if (((o->animFrame & 1) ? (*(volatile u16 *)&D_8009C9D8 & 0x80) : (*(volatile u16 *)&D_8009C9D8 & 0x20)) == 0) o->unkB2 = 0;
                o->subState = 0;
                o->step = 0;
            }
            if (*(u16 *)0x1F8001FC & *(u16 *)0x1F8003C6) {
                D_8009C618[0] = 0;
                if (o->unkB2 > 0x200) o->unkB2 = 0x200;
                if (o->unkB2 < -0x200) o->unkB2 = -0x200;
                o->unk9C = 1;
                o->unkA4 = 0;
                if (((s32 *)&D_8009BCEC)[0] & 0x40) {
                    if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4) {
                        o->unkA7 = 1;
                    }
                }
                o->subState = 2;
                o->step = 0;
            }
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80106F50);
void func_8011023C(GameObject *o);

void func_80106F50(GameObject *o)
{
    volatile u16 *k;
    switch (o->step) {
    case 0:
        D_8009B698_U8Ptr[0xb] = o->animFrame;
        if ((o->animFrame &= 1) != 0) {
            if (o->unkB2 > 0) o->unkB2 = -o->unkB2;
        } else {
            if (o->unkB2 < 0) o->unkB2 = -o->unkB2;
        }
        *(u8 *)((u8 *)o + 0xac) = 0;
        o->unk9C = 0;
        o->objectIndex = 0;
        *(u8 *)((u8 *)o + 0xc7) = 1;
        o->unk9D = 0;
        *(u8 *)((u8 *)o + 0xc6) = 0;
        *(u8 *)((u8 *)o + 0xe3) = 0;
        o->unk8C = 0;
        o->velX = 0;
        o->velY = 0;
        o->unkB2 = 0;
        D_8009B698_U8Ptr[0] = 0;
        o->unkA4 = 1;
        func_800EDD9C(o);
        o->step++;
    case 1:
        k = &D_8009C9D8;
        if (*k & 0xa0) {
            if (*k & 0x80) o->animFrame = 1;
            if (*k & 0x20) o->animFrame = 0;
        }
        if (o->unkBE & 1) {
            if (!(o->animFrame & 1)) {
                func_800EDDDC(o, 8, 2);
                o->unk8C = 0xe0;
            } else {
                func_800EDDDC(o, 0x11, 0);
                o->unk8C = 0;
            }
        } else {
            if (o->animFrame & 1) {
                func_800EDDDC(o, 8, 2);
                o->unk8C = 0x20;
            } else {
                func_800EDDDC(o, 0x11, 0);
                o->unk8C = 0;
            }
        }
        o->y.raw += 0x80000;
        func_8011023C(o);
        func_800EDD2C(o);
        if (o->unkBE & 2) {
            o->subState = 0x13;
            o->step = 0;
            o->unk7 = 0;
        }
        if (o->unkBE == 0) {
            if (*(u16 *)(D_8009B698_U8Ptr + 0x2c) == 8 && *(u8 *)((u8 *)o + 0xac) < 2) {
                D_8009E454 = func_80059B58(o, 1);
                if (D_8009E454) {
                    D_8009B698_U8Ptr[8] = 0;
                    *(s16 *)(D_8009B698_U8Ptr + 0x20) = 0;
                    *(u8 *)((u8 *)o + 0xac) = 0;
                    o->unk9C = 0;
                    o->unkB2 = 0;
                    func_800EEFEC(o, D_8009E454 == 1);
                }
            }
            if (o->animFrame != (o->unkBE & 1)) o->unkB2 = 0;
            o->unkA4 = 0;
            o->unkB6 = 0;
            func_800EDEBC(o, 4);
            if (D_8009B698_U8Ptr[0] == 0) {
                o->velX = 0;
                o->velY = 0;
                *(u8 *)((u8 *)o + 0xac) = 1;
                o->y.p.whole -= 4;
                func_800ED788(o);
                k = &D_8009C9D8;
                if (*k & 0x80) o->animFrame = 1;
                if (*k & 0x20) o->animFrame = 0;
                o->anim = D_80010C48;
                advanceAnimFrame(o, 3);
                o->subState = 2;
                o->step = 3;
                o->unk7 = 0;
                break;
            }
            o->velX = 0;
            o->velY = 0;
            func_800ED788(o);
            k = &D_8009C9D8;
            if (*k & 0x80) o->animFrame = 1;
            if (*k & 0x20) o->animFrame = 0;
            o->subState = 4;
            o->step = 3;
            o->unk7 = 0;
        }
        o->velX = 0;
        o->velY = 0;
        func_800EF40C(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010731C);
void func_8010731C(GameObject *o)
{
    u16 f;
    switch (o->step) {
    case 0:
        *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = o->active;
        f = o->animFrame;
        o->velX = 0x78;
        o->active = 2;
        o->unk8C = 0;
        o->velY = 0;
        o->unk9C = 0;
        o->unk9D = 0;
        o->unk9E = 0;
        o->unk9F = 0;
        *(u8 *)((u8 *)o + 0xad) = 0;
        o->touchFlag = 0;
        *(s8 *)((u8 *)o + 0xf) = -20;
        *(u8 *)((u8 *)o + 0xa2) = 2;
        o->animFrame = f & 1;
        func_800EDEBC(o, 0x2b);
        o->step++;
    case 1:
        tickAnimation(o);
        if (D_8009C10A == 0) {
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        if (D_1F8001C8 & 1) {
            o->d->p.whole = o->d->p.whole - 5;
        } else {
            o->d->p.whole = o->d->p.whole + 5;
        }
        if ((o->velX -= 5) == 0) {
            *(s8 *)((u8 *)o + 0xf) = -8;
            *(u8 *)((u8 *)o + 0) = *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8);
            o->unk9C = 0;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            D_8009B698_GameObjectPtr->timer = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801074B8);
extern s32 GAME_S32Arr[] asm("GAME");

void func_801074B8(GameObject *o)
{
    u8 t;
    u16 u;
    switch (o->step) {
    case 0:
        *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = o->active;

        u = o->animFrame;
        o->velX = 0x5a;
        o->active = 2;
        o->unk8C = 0;
        o->velY = 0;
        o->unk9C = 0;
        o->unk9D = 0;
        o->unk9E = 0;
        o->unk9F = 0;
        *(u8 *)((u8 *)o + 0xad) = 0;
        o->touchFlag = 0;
        *(s8 *)((char*)o+0xf) = -20;
        *(u8 *)((u8 *)o + 0xa2) = 2;
        o->animFrame = u & 1;
        func_800EDEBC(o, 0x2b);
        o->step++;
    case 1:
        tickAnimation(o);
        if (D_8009C10A == 0)
            o->step++;
        break;
    case 2:
        tickAnimation(o);
        o->d->p.whole += 5;
        o->velX -= 5;
        if (GAME_S32Arr[0] == 0x40001) {
            o->y.raw += -0x60000;
            if (o->y.p.whole < -0x20f)
                o->y.p.whole = -0x20f;
        }
        if (o->velX == 0) {
            *(s8 *)&o->unkF = -8;
            t = *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8);
            o->unk9C = 0;
            o->active = t;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            D_8009B698_GameObjectPtr->timer = 0;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            o->timer = 0;
            D_8009BCA2 = 1;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80107688);
extern u16 GAME_U16Arr[] asm("GAME");
extern s16 D_8009BCAC_S16Arr[] asm("D_8009BCAC");

void func_80107688(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->active = 4;
        o->velH = 0;
        o->velV = 0;
        if ((GAME_U16Arr[0] == 2 || GAME_U16Arr[0] == 0x13) && D_8009BCCA == 1) {
            s16 v = 0x100;
            if (o->animFrame & 1)
                v = -0x100;
            o->velX = v;
            o->velY = -0xa00;
        } else {
            if (GAME_U16Arr[0] != 4) {
                o->active = 1;
                o->velX = 0;
                o->velY = 0;
                D_8009B698_CharPtr[8] = 0;
                o->unkA5 = 0;
                o->unk9C = 0;
                *(u8 *)&o->unkAC = 0;
                *(s8 *)&o->unkF = -8;
                o->unkB2 = 0;
                *(s16 *)(D_8009B698_CharPtr + 0x20) = 0;
                o->subState = 2;
                o->state = 1;
                o->step = 3;
                o->unk7 = 0;
                o->timer = 0;
                (*(u8 *)&D_8009C618) = 0;
                D_8009BCA2 = 1;
                return;
            }
            o->velX = 0;
            o->velY = 0;
        }
        o->touchFlag = 0;
        o->unk9E = 0;
        o->unk9C = 1;
        o->unkB2 = 0;
        o->unk8C = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        D_8009B698_CharPtr[8] = 0;
        *(s16 *)(D_8009B698_CharPtr + 0x20) = 0;
        *(u8 *)&o->unkAC = 0;
        func_800EDEBC(o, 4);
        playSFXWithNote(2, 4);
        o->step = 1;
    case 1:
        func_800EDFA0(o);
        tickAnimation(o);
        o->h->raw += D_8009BCAC_S16Arr[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (o->velY > 0) {
            o->active = 3;
            o->unk9C = 2;
            o->step++;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
        if (clampToCeilingAndProbeSides(o)) {
            o->active = 3;
            o->unk9C = 2;
            o->velY = 0;
            o->velV = 0;
            o->step = 2;
        }
        o->touchFlag = 0;
        break;
    case 2:
        func_800EDFA0(o);
        tickAnimation(o);
        o->unk9E = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        o->h->raw += D_8009BCAC_S16Arr[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (o->velY > 0x680)
            o->velY = 0x680;
        if (o->touchFlag == 0 && ((s16 (*)(GameObject *o, s32 a, s32 b))probeSidesAndApplyTileResponse)(o, 0, 0) == 0)
            return;
        o->active = 1;
        D_8009B698_CharPtr[8] = 0;
        o->unkA5 = 0;
        o->unk9C = 0;
        *(u8 *)&o->unkAC = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        *(s16 *)(D_8009B698_CharPtr + 0x20) = 0;
        *(s8 *)&o->unkF = -8;
        *(s16 *)(D_8009B698_CharPtr + 0x20) = 0;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        o->unk7 = 0;
        o->timer = 0;
        D_8009BCA2 = 1;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80107A58);
extern s16 func_800458B0(s32, s32, s32);
void func_80107A58(GameObject *o)
{
    u16 f;
    s16 r;
    switch (o->step) {
    case 0:
        *(u8 *)((u8 *)(*(GameObject **)&D_8009B698) + 8) = o->active;
        f = o->animFrame;
        o->velX = 0x5a;
        o->velY = -0x200;
        o->active = 2;
        o->unk8C = 0;
        o->unk9C = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        o->unk9D = 0;
        o->unk9E = 0;
        o->unk9F = 0;
        *(u8 *)((u8 *)o + 0xad) = 0;
        o->touchFlag = 0;
        *(s8 *)((u8 *)o + 0xf) = -20;
        *(u8 *)((u8 *)o + 0xa2) = 2;
        o->animFrame = f & 1;
        func_800EDEBC(o, 0x15);
        o->step++;
        if ((*(u16 *)&GAME) == 10 && (D_8009BCCA == 1 || D_8009BCCA == 5)) {
            o->velY = -0x300;
            o->step = 2;
        }
    case 1:
        tickAnimation(o);
        if (D_1F8001C8 & 1) {
            o->d->p.whole = o->d->p.whole - 5;
        } else {
            o->d->p.whole = o->d->p.whole + 5;
        }
        o->y.raw += o->velY << 8;
        o->velX -= 5;
        o->velY += 0x10;
        if (o->velX == 0) {
            *(s8 *)((u8 *)o + 0xf) = -8;
            func_800EDEBC(o, 0x16);
            o->d->p.whole = (s16)(o->d->p.whole / 90) * 90;
            if (*(s16 *)((u8 *)o + 0xe0) != 0) {
                o->active = 3;
            } else {
                o->active = 1;
            }
            o->unk9C = 2;
            o->unkB2 = 0;
            (*(GameObject **)&D_8009B698)->timer = 0;
            func_800ED788(o);
            o->state = 1;
            *(u8 *)((u8 *)o + 0xa2) = 0;
            o->subState = 2;
            o->step = 3;
        } else {
            r = func_800458B0(o->h->p.whole, o->y.p.whole,
                             (s16)(o->d->p.whole + ((D_1F8001C8 & 1) ? -5 : 5)));
            if (r != 0) {
                *(u8 *)((u8 *)o + 0xaa) = 1;
                if (r == 1) {
                    o->d->p.whole += (D_1F8001C8 & 1) ? -5 : 5;
                    o->d->p.whole = (s16)(o->d->p.whole / 90) * 90;
                    *(u8 *)((u8 *)o + 0xa2) = 3;
                    o->unkB2 = 0;
                    o->subState = 0x15;
                    o->step = 0;
                }
            }
        }
        break;
    case 2:
        tickAnimation(o);
        if (D_1F8001C8 & 1) {
            o->d->p.whole = o->d->p.whole - 5;
        } else {
            o->d->p.whole = o->d->p.whole + 5;
        }
        o->y.raw += o->velY << 8;
        o->velY += 0x10;
        if (o->velY > 0x680) {
            o->velY = 0x680;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80107E20);

void func_80107E20(GameObject *o)
{
    u16 f;
    switch (o->step) {
    case 0:
        ((u8 *)D_8009B698_GameObjectPtr)[8] = o->active;
        ((u8 *)D_8009B698_GameObjectPtr)[9] = 0;
        o->velX = 0xb4;
        o->step++;
        if (((s32 *)&GAME)[0] == 0x40001) {
            ((u8 *)D_8009B698_GameObjectPtr)[9] = 1;
            o->velX = 0x78;
            o->step = 2;
        }
        if (*(u16 *)((s32 *)&GAME) == 8) {
            o->velX = 0x12c;
            o->step = 1;
        }
        f = o->animFrame;
        o->active = 2;
        o->unk8C = 0;
        o->velY = 0;
        o->unk9C = 0;
        o->unk9D = 0;
        o->unk9E = 0;
        o->unk9F = 0;
        ((u8 *)o)[0xad] = 0;
        o->touchFlag = 0;
        *(s8 *)&o->unkF = -20;
        ((u8 *)o)[0xa3] = 2;
        o->animFrame = f & 1;
        func_800EDEBC(o, 0x2c);
    case 1:
        tickAnimation(o);
        if (D_1F8001C8 & 1)
            o->d->p.whole += 2;
        else
            o->d->p.whole -= 2;
        o->velX -= 2;
        if (o->velX <= 0)
            o->step = 9;
        break;
    case 2:
        tickAnimation(o);
        o->d->p.whole -= 1;
        o->velX -= 1;
        if (o->velX <= 0) {
            o->velX = 0x18;
            o->step = 3;
        }
        break;
    case 3:
        tickAnimation(o);
        o->y.p.whole += 2;
        o->velX -= 2;
        if (o->velX <= 0) {
            o->velX = 0x18;
            o->step = 4;
        }
        break;
    case 4:
        tickAnimation(o);
        o->d->p.whole -= 1;
        o->velX -= 1;
        if (o->velX <= 0) {
            o->velX = 0x18;
            o->step = 3;
        }
        if (o->d->p.whole < 2000)
            o->step = 8;
        break;
    case 8:
        tickAnimation(o);
        o->d->p.whole -= 1;
        break;
    case 9:
        tickAnimation(o);
        *(s8 *)&o->unkF = -8;
        o->active = ((u8 *)D_8009B698_GameObjectPtr)[8];
        o->unk9C = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        D_8009B698_GameObjectPtr->timer = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010810C);

void func_8010810C(GameObject *o)
{
    switch (o->step) {
    case 0:
        *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 8) = o->active;
        *(u8 *)((u8 *)D_8009B698_GameObjectPtr + 9) = 0;
        o->velX = 0x5a;
        o->active = 3;
        *(u8 *)((u8 *)o + 0xa3) = 2;
        o->unk8C = 0;
        o->velY = 0;
        o->unk9C = 0;
        o->unk9D = 0;
        o->unk9E = 0;
        o->unk9F = 0;
        *(u8 *)((u8 *)o + 0xad) = 0;
        o->touchFlag = 0;
        o->step++;
        o->animFrame &= 1;
        func_800EDEBC(o, 0x2c);
    case 1:
        tickAnimation(o);
        if (D_1F8001C8 & 1)
            o->d->p.whole += 2;
        else
            o->d->p.whole -= 2;
        if ((o->velX -= 2) == 0)
            o->step = 9;
        break;
    case 9:
        D_8009BCA2 = 1;
        *(s8 *)((u8 *)o + 0xf) = -8;
        o->unkA5 = 0;
        o->unk9C = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        D_8009B698_GameObjectPtr->timer = 0;
        o->active = 1;
        o->unk8C = D_80114638[o->unkB0];
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801082B0);
extern char D_80010F94[];
void func_801082B0(char *o)
{
    s32 t;
    playSFXWithVolume(0x1c, 0x7f);
    *(u8 *)((u8 *)o + 0xa3) = 1;
    *(void **)((u8 *)o + 0x24) = D_80010F94;
    advanceAnimFrame(o, 2);
    *(s16 *)((u8 *)(*(char **)(o + 0x44)) + 2) = *(u16 *)((u8 *)o + 0xf6);
    t = D_80114638[*(s16 *)((u8 *)o + 0xb0)];
    *(u8 *)((u8 *)o + 0xac) = 0;
    *(u8 *)((u8 *)o + 6) = 3;
    *(s32 *)((u8 *)o + 0x8c) = t;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80108330);
void func_80108330(GameObject *o)
{
    *(s8 *)&o->unkF = -8;
    o->unkA5 = 0;
    ((u8 *)&o->unkA0)[3] = 0;
    o->unk9C = 0;
    *(u8 *)&o->unkAC = 0;
    o->unkB2 = 0;
    o->velX = 0;
    o->velY = 0;
    o->unk8C = D_80114638[o->unkB0];
    (*(GameObject **)&D_8009B698)->timer = 0;
    o->state = 1;
    o->subState = 0;
    o->step = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80108388);
typedef struct { GameObject t; char c0[0x20]; s16 we0; s16 we2; s32 de4; char e8[0xe]; s16 wf6; } PO_08388;
typedef struct { char pad[0x20]; s16 w20; } P_08388;

void func_80108388(PO_08388 *o)
{
    switch (o->t.step) {
    case 0:
        o->t.active = 3;
        o->t.unk9C = 1;
        o->t.unk8C = 0;
        o->t.touchFlag = 0;
        o->t.unk9E = 0;
        o->t.touchFlag = 0;
        *(u8 *)&o->t.unkAC = 0;
        o->t.unkB0 = 0;
        ((u8 *)&o->t.unkA0)[3] = 2;
        o->t.unkB6 = 0;
        o->t.animFrame &= 1;
        o->t.velX = fixedMulCos(0, o->t.unkB2);
        o->t.velY = -0x570;
        (*(P_08388 **)&D_8009B698)->w20 = 5;
        func_800EDEBC(o, 0x19);
        if (*(u16 *)0x1F8001C8 & 1)
            o->wf6 = (o->t.d->p.whole + 90) / 90 * 90;
        else
            o->wf6 = (o->t.d->p.whole - 90) / 90 * 90;
        o->t.step = 1;
    case 1:
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        ((s32 (*)(PO_08388 *))tickAnimation)(o);
        if (o->t.velY > 0) {
            o->t.unk9C = 2;
            o->t.step = 2;
        }
        if (clampToCeilingAndProbeSides(o)) {
            o->t.unk9C = 2;
            o->t.velY = 0;
            o->t.velV = 0;
            o->t.step = 2;
        }
        if (*(u16 *)0x1F8001C8 & 1) {
            o->t.d->raw += 0x28000;
            if (o->wf6 < o->t.d->p.whole) o->t.d->p.whole = o->wf6;
        } else {
            o->t.d->raw += -0x28000;
            if (o->t.d->p.whole < o->wf6) o->t.d->p.whole = o->wf6;
        }
        break;
    case 2:
        o->t.unkB0 = 0;
        o->t.unkB6 = 0;
        func_8010E444(o);
        if (*(u16 *)0x1F8001C8 & 1) {
            o->t.d->raw += 0x28000;
            if (o->wf6 < o->t.d->p.whole) {
                o->t.d->p.whole = o->wf6;
                if (*(u8 *)&o->t.unkAC == 0) *(u8 *)&o->t.unkAC = 1;
            }
        } else {
            o->t.d->raw += -0x28000;
            if (o->t.d->p.whole < o->wf6) {
                o->t.d->p.whole = o->wf6;
                if (*(u8 *)&o->t.unkAC == 0) *(u8 *)&o->t.unkAC = 1;
            }
        }
        applyObjectAltSpeedVertical(o);
        ((s32 (*)(PO_08388 *))tickAnimation)(o);
        if (*(u8 *)&o->t.unkAC == 2) {
            D_8009C650 = o->de4;
            if (o->we0) o->t.active = 3;
            else o->t.active = 1;
            *(s8 *)&o->t.unkF = -8;
            o->t.state = 1;
            ((u8 *)&o->t.unkA0)[3] = 0;
            o->t.subState = 0xe;
            o->t.step = 0;
        } else if (o->t.touchFlag == 1) {
            *(s8 *)&o->t.unkF = -8;
            playSFXWithVolume(0x1c, 0x7f);
            ((u8 *)&o->t.unkA0)[3] = 1;
            o->t.anim = D_80010F94;
            advanceAnimFrame(o, 2);
            o->t.d->p.whole = o->wf6;
            o->t.unk8C = D_80114638[o->t.unkB0];
            *(u8 *)&o->t.unkAC = 0;
            o->t.step = 3;
        } else if (((s16 (*)(PO_08388 *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            playSFXWithVolume(0x1c, 0x7f);
            ((u8 *)&o->t.unkA0)[3] = 1;
            o->t.anim = D_80010F94;
            advanceAnimFrame(o, 2);
            o->t.d->p.whole = o->wf6;
            o->t.unk8C = D_80114638[o->t.unkB0];
            *(u8 *)&o->t.unkAC = 0;
            o->t.step = 3;
        }
        break;
    case 3:
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        ((s16 (*)(PO_08388 *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0);
        if (((s32 (*)(PO_08388 *))tickAnimation)(o)) {
            if (o->we0) o->t.active = 3;
            else o->t.active = 1;
            *(s8 *)&o->t.unkF = -8;
            o->t.unkA5 = 0;
            ((u8 *)&o->t.unkA0)[3] = 0;
            o->t.unk9C = 0;
            *(u8 *)&o->t.unkAC = 0;
            o->t.unkB2 = 0;
            o->t.velX = 0;
            o->t.velY = 0;
            o->t.unk8C = D_80114638[o->t.unkB0];
            (*(P_08388 **)&D_8009B698)->w20 = 0;
            o->t.state = 1;
            o->t.subState = 0;
            o->t.step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801087E4);
typedef struct {
    char pad0[0x20];
    s16 w20;
} G330_087E4;
extern u8 D_8009C481;
extern void playSFXWithPitchSlide(s32, s32, s32, s32);
extern void startAreaBgm(void);
extern void setEventStarted(s32, s32, s32);

void func_801087E4(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->touchFlag = 0;
        o->unk9E = 0;
        o->touchFlag = 0;
        o->unk9C = 1;
        o->unkB0 = 0;
        ((u8 *)o)[0xa3] = 2;
        o->unkB6 = 0;
        o->animFrame &= 1;
        o->velX = fixedMulCos(0, o->unkB2);
        o->velY = -0x570;
        (*(G330_087E4 **)&D_8009B698)->w20 = 5;
        func_800EDEBC(o, 0x19);
        if ((*(u16 *)&GAME) == 0) {
            playSFXWithPitchSlide(0xd, 1, -8, 0x96);
            startAreaBgm();
        }
        o->step = 1;
    case 1:
        func_8010E444(o);
        if ((*(u16 *)&GAME) == 0)
            o->d->raw -= 0x80000;
        else
            o->d->raw -= 0x50000;
        if (o->d->p.whole < *(s16 *)((u8 *)o + 0xf6))
            o->d->p.whole = *(s16 *)((u8 *)o + 0xf6);
        applyObjectAltSpeedVertical(o);
        ((s32 (*)(GameObject *))tickAnimation)(o);
        if (o->velY > 0) {
            o->unk9C = 2;
            o->step = 2;
        }
        if (clampToCeilingAndProbeSides(o)) {
            o->unk9C = 2;
            o->velY = 0;
            o->velV = 0;
            o->step = 2;
        }
        break;
    case 2:
        o->unkB0 = 0;
        o->unkB6 = 0;
        func_8010E444(o);
        o->d->raw -= 0x28000;
        if (o->d->p.whole < *(s16 *)((u8 *)o + 0xf6))
            o->d->p.whole = *(s16 *)((u8 *)o + 0xf6);
        applyObjectAltSpeedVertical(o);
        ((s32 (*)(GameObject *))tickAnimation)(o);
        if (o->touchFlag == 1 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            playSFXWithVolume(0x1c, 0x7f);
            ((u8 *)o)[0xa3] = 1;
            o->anim = D_80010F94;
            advanceAnimFrame(o, 2);
            o->d->p.whole = *(s16 *)((u8 *)o + 0xf6);
            o->unk8C = D_80114638[o->unkB0];
            ((u8 *)o)[0xac] = 0;
            o->step = 3;
            ((u8 *)o)[0xa3] = 0;
        }
        break;
    case 3:
        o->velY = 0x780;
        applyObjectAltSpeedVertical(o);
        ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0);
        if (((s32 (*)(GameObject *))tickAnimation)(o)) {
            D_8009BCA2_U8Arr[0] = 1;
            *(s8 *)&o->unkF = -8;
            ((u8 *)o)[0xa5] = 0;
            ((u8 *)o)[0xa3] = 0;
            o->unk9C = 0;
            ((u8 *)o)[0xac] = 0;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            o->unk8C = D_80114638[o->unkB0];
            (*(G330_087E4 **)&D_8009B698)->w20 = 0;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->active = 1;
            if (D_8009C1C9 == 0 && D_8009C481 != 0)
                setEventStarted(0xbd, 0, 1);
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80108B3C);
void func_80108B3C(GameObject *o)
{
    s16 s;
    if (D_8009C9D8[0] & 0xa0) {
        if ((D_1F8001F8 & 0xf) == 0)
            playSFXWithNote(0x24, 0x24);
        switch (o->step) {
        case 0:
            s = 0x200;
            if (o->animFrame & 1)
                s = -0x200;
            o->unkB2 = s;
            o->velH = 0;
            o->velV = 0;
            o->velX = 0;
            o->velY = 0;
            func_800EDEBC(o, 0x20);
            ((u8 *)o)[0xc3] = 1;
            o->step++;
        case 1:
            tickAnimation(o);
            func_800EDD9C(o);
            func_8010E750(o);
            func_800EDD2C(o);
            func_800EDBEC(o);
            if (o->unkA6 == 0) {
                ((u8 *)o)[0xc3] = 0;
                o->subState = 1;
                o->step = 0;
            }
        }
    } else {
        u8 b = D_80114638[o->unkB0];
        ((u8 *)o)[0xc3] = 0;
        o->unkB2 = 0;
        o->subState = 0;
        o->step = 0;
        o->unk8C = b;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80108C70);
extern void PlayerSetAnimIfChanged(GameObject *, s32);
extern void tickAnimation(GameObject *);

void func_80108C70(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->unkB0 = 0;
        (*(char **)&D_8009B698)[8] = 0;
        o->touchFlag = 0;
        o->velY = 0;
        o->velV = 0;
        *(char *)&o->unkAC = 0;
        o->animFrame = o->animFrame & 1;
        func_800EDEBC(o, 0x1e);
        o->step++;
    case 1:
        tickAnimation(o);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80108D08);
extern s16 func_80043D2C(GameObject *, s16, s32);
extern void applyCollisionTileResponse(GameObject *);

void func_80108D08(GameObject *o)
{
    volatile u16 *k;
    s16 r;
    s16 x;
    s16 y;

    switch (o->step) {
    case 0:
        func_800EDEBC(o, 10);
        *(u8 *)&o->unkA0 = 0;
        o->unkBE = 0;
        o->unk9E = 6;
        o->unk8C = 0;
        o->unkB6 = 0;
        *(s16 *)((*(u8 **)&D_8009B698) + 2) = 0;
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        *(u8 *)&o->unkAA = 1;
        o->step++;
    case 1:
        tickAnimation(o);
        k = &D_8009C9D8;
        if ((*k & 0x50) == 0) {
            func_800EDEBC(o, 10);
        } else if (*k & 0x10) {
            func_800EDEBC(o, 0xb);
            if ((*(u16 *)0x1F8001F8 & 0xf) == 0) playSFXWithNote(0x1d, 0);
            o->y.raw -= 0x18000;
            func_80043D2C(o, o->h->p.whole + ((o->animFrame & 1) ? (-4) : 4), (s16)(o->y.p.whole - 0x15));
        } else if (*k & 0x40) {
            func_800EDEBC(o, 0xc);
            if ((*(u16 *)0x1F8001F8 & 0xf) == 0) playSFXWithNote(0x1d, 0);
            o->y.raw += 0x28000;
            if (o->touchFlag) {
                *(u8 *)&o->unkAA = 0;
                o->unk9E = 0;
                if (o->unkBE & 8) {
                    (*(u8 **)&D_8009B698)[8] = o->animFrame & 1;
                    if ((o->unkBE & 1) != o->animFrame) {
                        func_800EDEBC(o, 8);
                        advanceAnimFrame(o, 2);
                        o->subState = 0x1b;
                        o->step = 0;
                    } else {
                        func_800EDEBC(o, 0x11);
                        o->subState = 0x1b;
                        o->step = 0;
                    }
                    break;
                }
                goto reset;
            }
            if ((s16)((s32 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole + ((o->animFrame & 1) ? 2 : (-2)), (s16)(o->y.p.whole + 0x10)) > 0) {
                applyCollisionTileResponse(o);
                *(u8 *)&o->unkAA = 0;
                o->unk9E = 0;
                if (o->unkBE & 8) {
                    (*(u8 **)&D_8009B698)[8] = o->animFrame & 1;
                    if ((o->unkBE & 1) != o->animFrame) {
                        func_800EDEBC(o, 8);
                        advanceAnimFrame(o, 2);
                        o->subState = 0x1b;
                        o->step = 0;
                    } else {
                        func_800EDEBC(o, 0x11);
                        o->subState = 0x1b;
                        o->step = 0;
                    }
                    break;
                }
            reset:
                o->unk8C = D_80114638[o->unkB0];
                o->subState = 0;
                o->step = 0;
                break;
            }
        }
        o->h->p.whole += (o->animFrame & 1) ? -2 : 2;
        x = o->h->p.whole + ((o->animFrame & 1) ? (-8) : 8);
        y = o->y.p.whole - 0x10;
        r = ((s16 (*)(GameObject *, s16, s32))func_800450FC)(o, x, y);
        switch (r) {
        case 0:
            o->h->p.whole += (o->animFrame & 1) ? 4 : -4;
            *(u8 *)&o->unkAA = 0;
            *(u8 *)&o->unkAC = 1;
            o->velX = 0;
            o->velY = 0;
            o->unkB2 = 0;
            o->velH = 0;
            o->velV = 0;
            (*(u8 **)&D_8009B698)[8] = 1;
            func_800ED788(o);
            o->subState = 2;
            o->step = 3;
            break;
        case 2:
            o->unk9E = 5;
            o->subState = 0x1d;
            o->step = 0;
            break;
        }
        break;
    }
    if (*(u16 *)0x1F8001FC & *(u16 *)0x1F8003C6) {
        (*(u8 *)&D_8009C618) = 0;
        o->unk9C = 1;
        *(u8 *)&o->unkAA = 0;
        o->unk9E = 0;
        o->h->p.whole += (o->animFrame & 1) ? 0x10 : -0x10;
        if (D_8009BCEC_S32Arr[0] & 0x40) {
            if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4) {
                o->unkA7 = 1;
            }
        }
        o->subState = 2;
        o->step = 0;
    }
    func_800EE50C(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801091A0);
extern s32 func_80045780(s16, s16, s16);

void func_801091A0(GameObject *o)
{
    s16 v;
    s16 a;
    u16 hx;

    switch (o->step) {
    case 0:
        *(u8 *)((u8 *)o + 0xa0) = 0;
        func_800EDEBC(o, 0x1b);
        o->unkB6 = 0;
        *(s16 *)((u8 *)D_8009B698 + 2) = 0;
        *(u8 *)((u8 *)o + 0xa2) = 3;
        *(u8 *)((u8 *)o + 0xaa) = 1;
        o->unkB0 = 0;
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        o->unk8C = 0;
        o->timer = 0xf;
        playSFXWithVolume(4, 0x7f);
        o->step++;
    case 1:
        tickAnimation(o);
        if (--o->timer == 0) {
            o->timer = 8;
            func_800EDEBC(o, 0x17);
            o->step++;
        }
        break;
    case 2:
        if (clampToCeilingAndProbeSides(o) == 0) o->y.raw -= 0x18000;
        tickAnimation(o);
        if ((D_1F8001F8 & 0xf) == 0) playSFXWithNote(0x1d, 0);
        v = o->y.p.whole - 8;
        hx = o->h->p.whole + 8;
        a = (s16)(o->d->p.whole / 90) * 90;
        if ((func_80045780(o->h->p.whole - 8, v, a) & 2) || (func_80045780(hx, v, a) & 2)) {
            o->d->p.whole = (s16)(o->d->p.whole / 90) * 90;
            o->state = 1;
            o->subState = 0x16;
            o->step = 0;
        }
        break;
    case 3:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x10;
        v = o->y.p.whole - 8;
        hx = o->h->p.whole + 8;
        a = (s16)(o->d->p.whole / 90) * 90;
        if ((func_80045780(o->h->p.whole - 8, v, a) & 2) || (func_80045780(hx, v, a) & 2)) {
            o->d->p.whole = (s16)(o->d->p.whole / 90) * 90;
            o->state = 1;
            o->subState = 0x16;
            o->step = 0;
        }
        break;
    }
}

const u32 D_800E8BFC_ro[5] asm("D_800E8BFC") = { 0x08000800, 0x00000800, 0x02000000, 0x06000400, 0x00000400 };

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_801094B8);
typedef struct { s16 v[9]; } T9_094B8;
extern T9_094B8 D_800E8BFC;

void func_801094B8(GameObject *o)
{
    T9_094B8 t = D_800E8BFC;
    volatile u16 *k;
    D_8009B698_U8Ptr[0xb] = 8;
    if (o->animFrame & 1) {
        k = &D_8009C9D8;
        if (*k & 0x10) {
            D_8009B698_U8Ptr[0xb] = 0;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 7;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 1;
        } else if (*k & 0x80) {
            D_8009B698_U8Ptr[0xb] = 6;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 7;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 5;
        } else if (*k & 0x40) {
            D_8009B698_U8Ptr[0xb] = 4;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 5;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 3;
        } else if (*k & 0x20) {
            D_8009B698_U8Ptr[0xb] = 2;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 1;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 3;
        }
    } else {
        k = &D_8009C9D8;
        if (*k & 0x10) {
            D_8009B698_U8Ptr[0xb] = 0;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 1;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 7;
        } else if (*k & 0x80) {
            D_8009B698_U8Ptr[0xb] = 2;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 1;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 3;
        } else if (*k & 0x40) {
            D_8009B698_U8Ptr[0xb] = 4;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 3;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 5;
        } else if (*k & 0x20) {
            D_8009B698_U8Ptr[0xb] = 6;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 7;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 5;
        }
    }
    o->unk88 = t.v[D_8009B698_U8Ptr[0xb]];
}

const u32 D_800E8C10_ro[5] asm("D_800E8C10") = { 0x00000000, 0x00000000, 0x008C0000, 0x008C0118, 0x00000118 };
const u32 D_800E8C24_ro[5] asm("D_800E8C24") = { 0x00000000, 0x00000000, 0x02000000, 0x05500400, 0x00000400 };
const u32 D_800E8C38_ro[5] asm("D_800E8C38") = { 0x00000000, 0x00000000, 0x02000000, 0x07300400, 0x00000400 };

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80109868);
typedef struct { s16 v[9]; } T9_09868;
extern T9_09868 D_800E8C10;
extern T9_09868 D_800E8C24;
extern T9_09868 D_800E8C38;

void func_80109868(GameObject *o)
{
    T9_09868 t1 = D_800E8C10;
    T9_09868 t2 = D_800E8C24;
    T9_09868 t3 = D_800E8C38;
    volatile u16 *k;
    D_8009B698_U8Ptr[0xb] = 8;
    if (o->animFrame & 1) {
        k = &D_8009C9D8;
        if (*k & 0x10) {
            D_8009B698_U8Ptr[0xb] = 0;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 7;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 1;
        } else if (*k & 0x80) {
            D_8009B698_U8Ptr[0xb] = 6;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 7;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 5;
        } else if (*k & 0x40) {
            D_8009B698_U8Ptr[0xb] = 4;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 5;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 3;
        } else if (*k & 0x20) {
            D_8009B698_U8Ptr[0xb] = 2;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 1;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 3;
        }
    } else {
        k = &D_8009C9D8;
        if (*k & 0x10) {
            D_8009B698_U8Ptr[0xb] = 0;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 1;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 7;
        } else if (*k & 0x80) {
            D_8009B698_U8Ptr[0xb] = 2;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 1;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 3;
        } else if (*k & 0x40) {
            D_8009B698_U8Ptr[0xb] = 4;
            if (*k & 0x80) D_8009B698_U8Ptr[0xb] = 3;
            if (*k & 0x20) D_8009B698_U8Ptr[0xb] = 5;
        } else if (*k & 0x20) {
            D_8009B698_U8Ptr[0xb] = 6;
            if (*k & 0x10) D_8009B698_U8Ptr[0xb] = 7;
            if (*k & 0x40) D_8009B698_U8Ptr[0xb] = 5;
        }
    }
    switch (o->unkB2) {
    case 1:
        o->unk88 = t1.v[D_8009B698_U8Ptr[0xb]];
        break;
    case 2:
        o->unk88 = t2.v[D_8009B698_U8Ptr[0xb]];
        break;
    case 3:
        o->unk88 = t3.v[D_8009B698_U8Ptr[0xb]];
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80109D44);
extern void func_8002F804(GameObject *, s32, s32);
extern GameObject *allocObjectLayer2(void);
extern u8 D_8009BCAA_U8Arr[] asm("D_8009BCAA");
extern u8 D_8009BCA7_U8Arr[] asm("D_8009BCA7");

void func_80109D44(GameObject *o)
{
    extern char D_800108A8[];
    GameObject *p;
    GameObject *q;

    switch (o->step) {
    case 0:
        o->active = 5;
        o->unk8C = 0;
        D_8009B698_GameObjectPtr->timer = 0;
        *(u8 *)&D_8009B698_GameObjectPtr->clut = 0;
        D_8009B698_GameObjectPtr->animFrame = 0xffff;
        *(u16 *)&D_8009B698_GameObjectPtr->movetab = 0xffff;
        *((u16 *)&D_8009B698_GameObjectPtr->movetab + 1) = 0xffff;
        o->unkA4 = 0;
        o->unkA5 = 0;
        o->unk9C = 2;
        *(u8 *)&o->unkAC = 0;
        o->unkA7 = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0x1000;
        D_8009B698_GameObjectPtr->timer = 0;
        o->unkB2 = 0;
        o->velX = 0;
        o->unk8C = 0;
        o->visible = 1;
        o->cooldownTimer = 0;
        func_800EE1F0(o);
        o->anim = D_80010C48;
        advanceAnimFrame(o, 3);
        D_8009BCAA = 1;
        D_8009BCA7 = 1;
        if (((s32 *)&GAME)[0] == 0x30000) func_8002F804(o, 0, 0);
        o->step++;
        if (D_8009C361 != 0) {
            p = allocObjectLayer2();
            if (p != 0) {
                p->active = 2;
                p->type = 0x54;
                p->subtype = 1;
            }
            o->step = 3;
        }
        break;
    case 1:
        tickAnimation(o);
        *(u8 *)&D_8009B698_GameObjectPtr->clut = 1;
        o->unk9E = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        o->velY -= 0x3000;
        if (o->velY < 0x200) o->velY = 0x200;
        applyObjectAltSpeedVertical(o);
        if (o->y.p.whole >= *(s16 *)((char *)o + 0xf2)) {
            o->y.p.whole = *(s16 *)((char *)o + 0xf2);
            o->velX = 0;
            o->velY = 0;
            o->active = 4;
            probeSidesAndApplyTileResponse(o, 4, 0);
            o->anim = D_800108A8;
            advanceAnimFrame(o, 0);
            playSFXWithVolume(0x1c, 0x7f);
            o->step++;
        }
        break;
    case 2:
        o->unk8C = 0;
        o->active = 1;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        o->unk8C = D_80114638[o->unkB0];
        D_8009BCA2_U8Arr[0] = 1;
        D_8009C618[0] = 0;
        D_8009BCAA_U8Arr[0] = 0;
        D_8009BCA7_U8Arr[0] = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_80109FE0);
extern u8 D_8009BCDD_U8Arr[] asm("D_8009BCDD");

void func_80109FE0(GameObject *o)
{
    char pad;

    switch (o->step) {
    case 0:
        o->unkA4 = 0;
        o->unkA5 = 0;
        o->unk9C = 1;
        o->visible = 1;
        o->unkA7 = 0;
        o->active = 4;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        (*(GameObject **)&D_8009B698)->timer = 0;
        o->unk8C = 0;
        o->timer = 0x1e;
        o->cooldownTimer = 0;
        func_800EE1F0(o);
        D_8009BCA7 = 1;
        D_8009BCAA = 1;
        (*(u8 *)&D_8009C618) = 3;
        o->unk8C = 0;
        o->step++;
        break;
    case 1:
        if (o->unk7 != 0 && (D_1F8001F8 & 3) == 0) playSFX(0x16);
        tickAnimation(o);
        func_800EDFA0(o);
        o->y.raw += o->velY << 8;
        o->velY -= 0x30;
        func_800EDEBC(o, 4);
        if (--o->timer <= 0) {
            o->timer = 0x3c;
            D_8009BCDD_U8Arr[0] = 3;
            ((u8 *)&D_8009BCA4)[0] = 0;
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        func_800EDFA0(o);
        o->y.raw += o->velY << 8;
        o->velY -= 0x30;
        func_800EDEBC(o, 4);
        if (o->timer != 0) {
            if (--o->timer <= 0) {
                (*(GameObject **)&D_1F8001D4)->unk4C = 7;
                (*(GameObject **)&D_1F8001D4)->unk4E = 0;
            }
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010A1E4);
extern void setEventComplete(s32, s32);

void func_8010A1E4(GameObject *o)
{
    s16 s1;
    s16 s3;
    u8 *g;

    switch (o->step) {
    case 0:
        o->unk9C = 1;
        o->visible = 1;
        o->unkA4 = 0;
        o->unkA5 = 0;
        o->unkA7 = 0;
        o->active = 4;
        g = D_8009B698;
        o->unkB2 = 0;
        o->velX = 0;
        o->velY = 0;
        *(s16 *)(g + 0x20) = 0;
        o->unk8C = 0;
        o->timer = 0x1e;
        o->cooldownTimer = 0;
        func_800EE1F0(o);
        o->unk8C = 0;
        o->step = o->step + 1;
        break;
    case 1:
        tickAnimation(o);
        func_800EDFA0(o);
        o->y.raw = o->y.raw + o->velY * 0x100;
        o->velY = o->velY - 0x30;
        if (o->velY < -0x570)
            o->velY = -0x570;
        func_800EDEBC(o, 4);
        if (o->y.p.whole < -0x20c) {
            setEventComplete(0xa4, 0);
            o->state = 5;
            *(s16 *)((char *)o + 0xf6) = 0;
            o->subState = 2;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010A314);
typedef struct D_0A314 { char pad0[8]; char a; char pad1[0x20-9]; s16 b; char pad2[0x2c-0x22]; s16 c; s16 d; } D_0A314;
typedef struct O_0A314 { char pad0[6]; u8 n; char pad1[0x24-7]; void *fn; char pad2[0x7c-0x28]; s16 s7c; s16 s7e; char pad3[0x8c-0x80]; s32 v8c; char pad4[0x9c-0x90]; char c9c; char pad5[0xa5-0x9d]; char ca5; char pad6[0xac-0xa6]; char cac; char pad7[0xb0-0xad]; s16 sb0; s16 sb2; } O_0A314;
extern D_0A314 *D_8009B698_D_0A314Ptr asm("D_8009B698");
extern void readAnimFrameCount__0A314(void);
extern void D_800108A8(void);
void func_8010A314(O_0A314 *o)
{
D_8009B698_D_0A314Ptr->a = 0;
o->ca5 = 0;
o->c9c = 0;
o->cac = 0;
o->sb2 = 0;
o->s7c = 0;
o->s7e = 0;
D_8009B698_D_0A314Ptr->b = 0;
D_8009B698_D_0A314Ptr->c = 0;
D_8009B698_D_0A314Ptr->d = 0;
o->fn = D_800108A8;
readAnimFrameCount__0A314();
o->v8c = D_80114638[o->sb0];
o->n++;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010A3A0);
typedef struct { char p[8]; u8 b8; u8 b9; char q[0x20 - 0xa]; u16 w20; char r[0x2c - 0x22]; s16 w2c; s16 w2e; } G_0A3A0;
extern G_0A3A0 *D_8009B698_G_0A3A0Ptr asm("D_8009B698");
extern GameObject *D_800A547C_GameObjectPtrArr[] asm("D_800A547C");
void func_8010A3A0(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->touchFlag = 0;
        o->unk9E = 0;
        o->unk9C = 1;
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        o->unk8C = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        D_8009B698_G_0A3A0Ptr->b8 = 0;
        D_8009B698_G_0A3A0Ptr->w20 = 0;
        switch (D_800A547C_GameObjectPtrArr[0]->type) {
        case 0x15:
        case 0x18:
        case 0x4e:
            break;
        default:
            func_800EE1F0(o);
            break;
        }
        *(u8 *)&o->unkAC = 0;
        func_8010E678(o);
        func_800EDEBC(o, 0x2e);
        o->step = 1;
    case 1:
        if (--D_8009B698_G_0A3A0Ptr->b9 != 0) {
            if (D_8009B698_G_0A3A0Ptr->b8 == 0) {
                D_8009B698_G_0A3A0Ptr->w20++;
                func_8010E678(o);
            }
        } else {
            D_8009B698_G_0A3A0Ptr->b8 = 1;
            if (D_8009B698_G_0A3A0Ptr->w20 >= 5) {
                D_8009B698_G_0A3A0Ptr->b8 = 0;
                o->step = 2;
            } else {
                D_8009B698_G_0A3A0Ptr->w20++;
                func_8010E678(o);
            }
        }
    case 2:
        o->h->raw += D_8009BCAC_S16Arr[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->velY > 0) {
            o->unk9C = 2;
            o->step = 3;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
        if (clampToCeilingAndProbeSides(o)) {
            o->unk9C = 2;
            o->velY = 0;
            o->velV = 0;
            o->step = 3;
        }
        o->touchFlag = 0;
        break;
    case 3:
        o->unk9E = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        o->h->raw += D_8009BCAC_S16Arr[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        tickAnimation(o);
        if (o->touchFlag == 1 || ((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            D_8009B698_G_0A3A0Ptr->b8 = 0;
            o->unkA5 = 0;
            o->unk9C = 0;
            *(u8 *)&o->unkAC = 0;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            D_8009B698_G_0A3A0Ptr->w20 = 0;
            D_8009B698_G_0A3A0Ptr->w2c = 0;
            D_8009B698_G_0A3A0Ptr->w2e = 0;
            o->anim = D_800108A8;
            readAnimFrameCount(o);
            o->unk8C = D_80114638[o->unkB0];
            o->step++;
        }
        break;
    case 4:
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010A708);
extern GameObject *D_8009B698_GameObjectPtrArr[] asm("D_8009B698");

void func_8010A708(GameObject *o)
{
    GameObject *p;
    *(char *)&D_8009B698_GameObjectPtrArr[0]->clut = 0;
    o->unkA5 = 0;
    o->unk9C = 0;
    *(char *)&o->unkAC = 0;
    p = D_8009B698_GameObjectPtrArr[0];
    o->unkB2 = 0;
    o->velX = 0;
    o->velY = 0;
    p->animFrame = 0xffff;
    p->timer = 0;
    p->animTimer = 0;
    o->anim = D_800108A8;
    readAnimFrameCount(o);
    o->unk8C = D_80114638[o->unkB0];
    o->step = 4;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010A794);
#define G D_8009B698_U8Ptr

void func_8010A794(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->touchFlag = 0;
        *(u8 *)((u8 *)o + 0x9e) = 0;
        o->unk9C = 1;
        o->unkB2 = 0;
        o->unk8C = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        G[8] = 0;
        *(s16 *)(G + 0x20) = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        func_8010E678(o);
        func_800EDEBC(o, 4);
        playSFXWithNote(2, 4);
        o->step = 1;
    case 1:
        if (--G[9] != 0) {
            if (G[8] == 0) {
                (*(u16 *)(G + 0x20))++;
                func_8010E678(o);
            }
        } else {
            G[8] = 1;
            if (*(u16 *)(G + 0x20) >= 5) {
                G[8] = 0;
                o->step = 2;
            } else {
                (*(u16 *)(G + 0x20))++;
                func_8010E678(o);
            }
        }
    case 2:
        func_800EDFA0(o);
        tickAnimation(o);
        o->h->raw += D_8009BCAC_S16Arr[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        if (o->velY > 0) {
            o->unk9C = 2;
            o->step = 3;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
        if (clampToCeilingAndProbeSides(o)) {
            o->unk9C = 2;
            o->velY = 0;
            *(s16 *)((char *)o + 0x82) = 0;
            o->step = 3;
        }
        o->touchFlag = 0;
        break;
    case 3:
        func_800EDFA0(o);
        tickAnimation(o);
        *(u8 *)((u8 *)o + 0x9e) = 0;
        o->unkB0 = 0;
        o->unkB6 = 0;
        o->h->raw += D_8009BCAC_S16Arr[0] << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        o->h->raw += o->velX << 8;
        func_8010E444(o);
        applyObjectAltSpeedVertical(o);
        if (o->touchFlag == 1 || ((s16 (*)(GameObject *o, s32 a, s32 b))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            G[8] = 0;
            *(u8 *)((u8 *)o + 0xa5) = 0;
            o->unk9C = 0;
            *(u8 *)((u8 *)o + 0xac) = 0;
            o->unkB2 = 0;
            o->velX = 0;
            o->velY = 0;
            *(s16 *)(G + 0x20) = 0;
            *(u16 *)(G + 0x2e) = 0xffff;
            *(s16 *)(G + 0x2c) = 0;
            o->anim = D_800108A8;
            readAnimFrameCount(o);
            o->unk8C = D_80114638[o->unkB0];
            o->step = 4;
        }
        break;
    case 4:
        break;
    }
}
#undef G

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010AAD4);
typedef struct N_0AAD4 { u8 active; u8 b1; u8 type; char p[0x91]; struct N_0AAD4 *next; } N_0AAD4;
extern N_0AAD4 *D_8009E454_N_0AAD4Ptr asm("D_8009E454");

void func_8010AAD4(void)
{
    N_0AAD4 *p;
    switch (D_8009E454_N_0AAD4Ptr->type) {
    case 11:
        if (D_8009E454_N_0AAD4Ptr->next)
            D_8009E454_N_0AAD4Ptr->active = 3;
        else
            D_8009E454_N_0AAD4Ptr->active = 1;
    case 21:
        if (D_8009E454_N_0AAD4Ptr->next) {
            D_8009E454_N_0AAD4Ptr->active = 3;
            p = D_8009E454_N_0AAD4Ptr->next;
            if (!p->next) {
                p->active = 1;
            } else {
            loop:
                p->active = 3;
                p = p->next;
                if (p->next) goto loop;
                p->active = 1;
            }
        } else {
            D_8009E454_N_0AAD4Ptr->active = 1;
        }
        break;
    case 29:
    case 49:
        D_8009E454_N_0AAD4Ptr->active = 1;
        break;
    case 12:
    default:
        D_8009E454_N_0AAD4Ptr->active = 3;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010ABD0);
typedef struct { char p0[2]; s16 s2; } H_0ABD0;
typedef struct PO_0ABD0 {
    u8 b0; char p1; u8 b2; char p3[3]; u8 b6;
    char p7[0x16 - 7]; s16 s16;
    char p18[0x28 - 0x18]; u16 s28, s2a; char p2c[2]; u16 s2e;
    s32 d30; char p34[0x40 - 0x34]; H_0ABD0 *h40;
    char p44[0x94 - 0x44]; struct PO_0ABD0 *d94;
} PO_0ABD0;
typedef struct {
    char p0[5]; u8 step, state;
    char p7[0x16 - 7]; s16 s16;
    char p18[0x24 - 0x18]; void *anim;
    char p28[0x2e - 0x28]; u16 s2e;
    char p30[0x40 - 0x30]; H_0ABD0 *h40;
    char p44[0x8c - 0x44]; s32 d8c;
    char p90[0x9d - 0x90]; u8 b9d;
    char p9e[0xb8 - 0x9e]; s16 sb8, sba;
    char pbc[0xc6 - 0xbc]; u8 bc6; char pc7; u8 bc8;
} TO_0ABD0;
extern PO_0ABD0 *D_8009E454_PO_0ABD0Ptr asm("D_8009E454");
extern PO_0ABD0 *D_8009B698_PO_0ABD0Ptr asm("D_8009B698");
extern char D_80010EC8[];
extern void func_800EEA38(void);
extern void func_800EDCA8(TO_0ABD0 *, s32);

static __inline__ void attach_0ABD0(TO_0ABD0 *o)
{
    if (D_8009E454_PO_0ABD0Ptr->b2 == 0x15 || D_8009E454_PO_0ABD0Ptr->b2 == 0x31)
        o->h40->s2 = o->sb8 + (D_8009E454_PO_0ABD0Ptr->h40->s2 + D_8009E454_PO_0ABD0Ptr->d30);
    else
        o->h40->s2 = D_8009E454_PO_0ABD0Ptr->h40->s2 + o->sb8;
    if (D_8009E454_PO_0ABD0Ptr->b2 == 0x24)
        o->s16 = D_8009E454_PO_0ABD0Ptr->s16 + o->sba + 0x10;
    else
        o->s16 = D_8009E454_PO_0ABD0Ptr->s16 + o->sba;
}

void func_8010ABD0(TO_0ABD0 *o)
{
    PO_0ABD0 *p;
    s32 x, s;

    if (o->b9d == 0) func_800EEA38();
    switch (o->state) {
    case 0:
        o->b9d = 1;
        o->bc8 = 0;
        o->d8c = 0;
        *(u8 *)D_8009B698_PO_0ABD0Ptr = 2;
        D_8009B698_PO_0ABD0Ptr->s2e = 0xffff;
        D_8009B698_PO_0ABD0Ptr->s28 = 0xffff;
        D_8009B698_PO_0ABD0Ptr->s2a = 0xffff;
        D_8009B698_PO_0ABD0Ptr->b6 = D_8009E454_PO_0ABD0Ptr->b0;
        switch (o->s2e) {
        case 0: case 1: case 2: case 3:
            o->anim = D_80011070;
            break;
        case 4: case 5:
            o->anim = D_80011090;
            break;
        case 6: case 7:
            o->anim = D_800110B0;
            break;
        }
        readAnimFrameCount(o);
        func_800EDCA8(o, 1);
        attach_0ABD0(o);
        switch (D_8009E454_PO_0ABD0Ptr->b2) {
        case 0xb: case 0x15:
            if (D_8009E454_PO_0ABD0Ptr->d94 != 0) {
                p = D_8009E454_PO_0ABD0Ptr->d94;
                if (p->d94 == 0) {
                    *(u8 *)p = 2;
                } else {
                loop0:
                    *(u8 *)p = 2;
                    p = p->d94;
                    if (p->d94 != 0) goto loop0;
                    *(u8 *)p = 2;
                }
            }
            break;
        case 0x1d:
            *(u8 *)D_8009E454_PO_0ABD0Ptr = 3;
            break;
        case 0x31:
            *(u8 *)D_8009E454_PO_0ABD0Ptr = 5;
            break;
        }
        o->state = 1;
        break;
    case 1:
        attach_0ABD0(o);
        if (*(u8 *)D_8009B698_PO_0ABD0Ptr != 0) return;
        if (o->bc6 != 0) return;
        switch (D_8009E454_PO_0ABD0Ptr->b2) {
        case 0xb:
            p = D_8009E454_PO_0ABD0Ptr;
            if (p->d94 == 0)
                *(u8 *)p = 1;
            else
                *(u8 *)p = 3;
        case 0x15:
            p = D_8009E454_PO_0ABD0Ptr;
            if (p->d94 != 0) {
                *(u8 *)p = 3;
                p = D_8009E454_PO_0ABD0Ptr->d94;
                if (p->d94 == 0) {
                    *(u8 *)p = 1;
                } else {
                loop1:
                    *(u8 *)p = 3;
                    p = p->d94;
                    if (p->d94 != 0)
                        goto loop1;
                    *(u8 *)p = 1;
                }
            } else {
                *(u8 *)p = 1;
            }
            break;
        case 0x1d: case 0x31:
            *(u8 *)D_8009E454_PO_0ABD0Ptr = 1;
            break;
        case 0xc: case 0xd: case 0xe:
        default:
            *(u8 *)D_8009E454_PO_0ABD0Ptr = 3;
            break;
        }
        o->anim = D_80010EC8;
        advanceAnimFrame(o, 0);
        o->b9d = 0;
        switch (D_8009E454_PO_0ABD0Ptr->b2) {
        case 0x15:
            s = 0x22;
            break;
        case 0x31:
            s = 0x46;
            break;
        default:
            s = 8;
            break;
        }
        o->step = s;
        o->state = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010B058);

void func_8010B058(GameObject *o)
{
    GameObject *q;
    Fix16 *h;
    s32 x;
    (*(GameObject **)&D_8009B698)->state = 0;
    o->timer = 6;
    o->velH = 0;
    o->velV = 0;
    o->velX = 0;
    o->velY = 0;
    switch (D_8009E454_GameObjectPtr->type) {
    case 5:
        D_8009E454_GameObjectPtr->unk6A = 0;
        break;
    case 0x21:
        D_8009E454_GameObjectPtr->unkA7 = 0;
        break;
    }
    if ((*(u8 *)&D_8009C61A) - 5 >= 4) {
        D_8009E454_GameObjectPtr->active = (*(GameObject **)&D_8009B698)->step;
    } else {
        switch (D_8009E454_GameObjectPtr->type) {
        case 11:
            if (D_8009E454_GameObjectPtr->unk94)
                D_8009E454_GameObjectPtr->active = 3;
            else
                D_8009E454_GameObjectPtr->active = 1;
        case 21:
            if (D_8009E454_GameObjectPtr->unk94 != 0) {
            D_8009E454_GameObjectPtr->active = 3;
            q = (GameObject *)D_8009E454_GameObjectPtr->unk94;
            if (q->unk94) goto loop;
            q->active = 1;
            break;
        loop:
            q->active = 3;
            q = (GameObject *)q->unk94;
            if (q->unk94) goto loop;
            q->active = 1;
            } else {
                D_8009E454_GameObjectPtr->active = 1;
            }
            break;
        case 29:
        case 49:
            D_8009E454_GameObjectPtr->active = 1;
            break;
        case 48:
        default:
            D_8009E454_GameObjectPtr->active = 3;
            break;
        }
    }
    h = o->h;
    x = h->p.whole;
    h->p.whole = !(o->animFrame & 1) ? x - 0x10 : x + 0x10;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010B208);
extern s32 D_8009BCEC;

s16 func_8010B208(GameObject *o)
{
    s16 r = 0;

    if (*(u16 *)0x1F8001FC & *(u16 *)0x1F8003C6) {
        (*(u8 *)&D_8009C618) = 0;
        ((void (*)())func_8010B058)();
        if (D_8009BCEC & 0x40) {
            if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4) {
                o->unkA7 = 1;
            }
        }
        r++;
        o->unk9C = 1;
        o->subState = 2;
        o->step = 0;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010B2C0);
typedef struct O_0B2C0 {
    char pad0[6];
    u8 state;
    char pad1[0x24 - 7];
    void *anim;
    char pad2[0x2e - 0x28];
    u16 animFrame;
    char pad3[0x88 - 0x30];
    s32 d88;
} O_0B2C0;
typedef struct P_0B2C0 { char pad[4]; char b4; char pad1[0xb]; s16 s10; } P_0B2C0;
extern P_0B2C0 *D_8009B698_P_0B2C0Ptr asm("D_8009B698");

void func_8010B2C0(O_0B2C0 *o)
{
    P_0B2C0 *p; s16 v;
    o->anim = (void *)D_80010F0C;
    advanceAnimFrame(o, 0);
    D_8009B698_P_0B2C0Ptr->b4 = 1;
    D_8009E454[0x69] = 4;
    playSFXWithNote(0x1e, 8);
    p = D_8009B698_P_0B2C0Ptr;
    v = (*(s16 *)(D_8009E454 + 0x6e) << 8) / 0x18;
    if (o->animFrame & 1)
        v = -v;
    p->s10 = v;
    o->d88 = 0;
    o->state++;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010B384);
typedef struct {
    char pad0[2];
    s16 w02;
    u8 b4;
    char pad5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    char pada[2];
    s16 w0c;
    s16 w0e;
    s16 w10;
    s16 w12;
    char pad14[0x14];
    u16 w28;
    u16 w2a;
} G330_0B384;
extern G330_0B384 *D_8009B698_G330_0B384Ptr asm("D_8009B698");

#define SETPOS(o) \
    o->h->p.whole = D_8009E454_GameObjectPtr->h->p.whole + o->unkB8; \
    if (D_8009E454_GameObjectPtr->type == 0x24) o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA + 0x10; \
    else o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;

static __inline__ s16 chk_0B384(GameObject *o)
{
    s16 r = 0;

    if (*(u16 *)0x1F8001FC & *(u16 *)0x1F8003C6) {
        (*(u8 *)&D_8009C618) = 0;
        func_8010B058(o);
        if (D_8009BCEC & 0x40) {
            if (*(volatile u16 *)&D_8009C9D8 & *(u16 *)0x1F8003C4) {
                o->unkA7 = 1;
            }
        }
        r++;
        o->unk9C = 1;
        o->subState = 2;
        o->step = 0;
    }
    return r;
}

static __inline__ void turn_0B384(GameObject *o)
{
    G330_0B384 *p;
    s16 v;
    o->anim = (void *)D_80010F0C;
    advanceAnimFrame(o, 0);
    D_8009B698_G330_0B384Ptr->b4 = 1;
    D_8009E454_GameObjectPtr->touchFlag = 4;
    playSFXWithNote(0x1e, 8);
    p = D_8009B698_G330_0B384Ptr;
    v = (D_8009E454_GameObjectPtr->hitWidth << 8) / 0x18;
    if (o->animFrame & 1)
        v = -v;
    p->w10 = v;
    o->unk88 = 0;
    o->step++;
}

void func_8010B384(GameObject *o)
{
    s16 tbl[12] = { 1, 1, 2, 2, 3, 3, 3, 3, 2, 2, 1, 1 };
    s16 y;
    u16 u;

    D_8009B698_G330_0B384Ptr->b7 = o->animFrame;
    switch (o->step) {
    case 0:
        o->unkB6 = -0x420;
        D_8009B698_G330_0B384Ptr->w0e = 0;
        D_8009B698_G330_0B384Ptr->w02 = 0x10;
        o->unkB2 = D_8009E454_GameObjectPtr->hitWidth;
        o->animFrame &= 1;
        D_8009B698_G330_0B384Ptr->b6 = D_8009E454_GameObjectPtr->active;
        D_8009B698_G330_0B384Ptr->b9 = 0;
        D_8009B698_G330_0B384Ptr->w0c = 0;
        D_8009B698_G330_0B384Ptr->w28 = 0xffff;
        D_8009B698_G330_0B384Ptr->w2a = 0xffff;
        o->h->p.whole = o->unkB8 + (D_8009E454_GameObjectPtr->h->p.whole + D_8009E454_GameObjectPtr->unk30);
        y = D_8009E454_GameObjectPtr->y.p.whole;
        o->velH = 0;
        o->velV = 0;
        o->unkB0 = 0;
        o->unkA4 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->y.p.whole = y + o->unkBA;
        o->unk8C = 0;
        o->velX = o->unkB8;
        D_8009B698_G330_0B384Ptr->w10 = D_8009E454_GameObjectPtr->h->p.whole + o->unkB8;
        D_8009B698_G330_0B384Ptr->w12 = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;
        o->anim = (void *)D_80010EC8;
        advanceAnimFrame(o, 0);
        o->timer = 10;
        o->step++;
    case 1:
        SETPOS(o);
        if (--o->timer == 0) o->step++;
        goto tail;
    case 2:
        o->h->p.whole = D_8009E454_GameObjectPtr->h->p.whole + o->unkB8;
        switch (D_8009E454_GameObjectPtr->type) {
        case 0x24:
            o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA + 0x10;
            break;
        case 0x1d:
            o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;
            if (D_8009E454_GameObjectPtr->subState == 3) {
                D_8009E454_GameObjectPtr->unk6A = 0;
                D_8009B698_G330_0B384Ptr->b4 = 0;
                o->timer = 6;
                o->unk9C = 2;
                o->velH = 0;
                o->velV = 0;
                o->velX = 0;
                o->velY = 0;
                {
                    Fix16 *p = o->h; s32 t = o->animFrame & 1; s32 h = p->p.whole;
                    if (t) t = h + 0x10; else t = h - 0x10;
                    p->p.whole = t;
                }
                o->subState = 2;
                o->step = 3;
            }
            break;
        case 0x21:
            o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;
            if (D_8009E454_GameObjectPtr->unk98 == 0 || *(u16 *)&D_8009E454_GameObjectPtr->state == 0x502) {
                func_8010B058(o);
                o->unk9C = 2;
                o->subState = 2;
                o->step = 3;
            }
            break;
        default:
            o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA;
            break;
        }
        tickAnimation(o);
        if (o->animFrame & 1) u = *(u16 *)0x1F8001FC & 0x80;
        else u = *(u16 *)0x1F8001FC & 0x20;
        if (u) {
            turn_0B384(o);
        }
    tail:
        if (!chk_0B384(o)) func_8010D678(o, 2);
        break;
    case 3:
        tickAnimation(o);
        SETPOS(o);
        o->unkB8 += (D_8009B698_G330_0B384Ptr->w10 * tbl[o->unk88 % 12]) >> 8;
        if (++o->unk88 < 12) return;
        o->animFrame ^= 1;
        if (o->animFrame & 1) {
            o->unkB8 = o->velX + o->unkB2;
            SETPOS(o);
        } else {
            o->unkB8 = o->velX - o->unkB2;
            SETPOS(o);
        }
        o->anim = (void *)D_80010EC8;
        advanceAnimFrame(o, 0);
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        D_8009B698_G330_0B384Ptr->b4 = 0;
        o->step = 0;
        break;
    }
}
#undef SETPOS

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010BB00);
typedef struct { GameObject b; char pad[0xe8 - 0xc0]; s16 e8, ea; } OX_0BB00;
extern GameObject *func_80059A40(GameObject *, GameObject *);

void func_8010BB00(GameObject *o)
{
    GameObject *n;
    s32 h, t, f;
    Fix16 *p;
    {
        s32 t1, h1;
        t1 = o->animFrame & 1;
        h1 = o->h->p.whole;
        if (t1) t1 = h1 - 6; else t1 = h1 + 6;
        ((OX_0BB00 *)o)->e8 = t1;
    }
    ((OX_0BB00 *)o)->ea = o->y.p.whole - 8;
    n = func_80059A40(o, D_8009E454);
    if (n == 0) {
        *(s8 *)&o->unkF = -8;
        p = o->h;
        {
            s32 t2, h2;
            t2 = o->animFrame & 1;
            h2 = p->p.whole;
            if (t2) t2 = h2 + 8; else t2 = h2 - 8;
            p->p.whole = t2;
        }
        o->velX = 0;
        o->velY = 0;
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        o->unk9E = 0;
        *(char *)&o->unkAA = 0;
        *(char *)&o->unkAC = 1;
        func_800ED788(o);
        o->subState = 2;
        o->step = 3;
    } else {
        o->h->p.whole = n->h->p.whole + o->unkB8;
        D_8009E454 = n;
        o->y.p.whole = n->y.p.whole + o->unkBA + 8;
        if (o->unk9E == 11) {
            *(s8 *)&o->unkF = -8;
            o->subState = 11;
            o->step = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010BC24);
static __inline__ void turn_0BC24(GameObject *o)
{
    Fix16 *p = o->h; s32 t = o->animFrame & 1; s32 h = p->p.whole; if (t) t = h + 0x10; else t = h - 0x10; p->p.whole = t;
}

void func_8010BC24(GameObject *o)
{
    volatile u16 *k;
    Fix16 *p;
    s32 h, t;
    char *c = (char *)o;
    *(s8 *)(c + 0xf) = -8;
    c[0xa9] = 0;
    *D_8009E454 = 1;
    *(s16 *)(c + 0x20) = 6;
    c[0x9c] = 1;
    *(s16 *)(c + 0x80) = 0;
    *(s16 *)(c + 0x82) = 0;
    *(s16 *)(c + 0x7c) = 0;
    *(s16 *)(c + 0x7e) = 0;
    if ((*(s32 *)&GAME) == 0x30000) {
        turn_0BC24(o);
    } else {
        k = &D_8009C9D8;
        if (*k & 0x80) {
            h = o->h->p.whole; o->h->p.whole = h - 0x10;
        } else if (*k & 0x20) {
            h = o->h->p.whole; o->h->p.whole = h + 0x10;
        } else {
            turn_0BC24(o);
        }
    }
    if ((D_8009BCEC & 0x40) && (*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C4)))
        o->unkA7 = 1;
    o->subState = 2;
    o->step = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010BD68);
typedef struct {
    char pad0[2];
    s16 w02;
    char pad4[3];
    u8 b7;
    u8 b8;
    u8 b9;
    char pada[2];
    s16 w0c;
    s16 w0e;
    char pad10[0x18];
    u16 w28;
    u16 w2a;
    char pad2c[2];
    u16 w2e;
} G330_0BD68;
extern G330_0BD68 *D_8009B698_G330_0BD68Ptr asm("D_8009B698");

void func_8010BD68(GameObject *o)
{
    volatile u16 *pad;
    s32 t;
    Fix16 *h;
    s32 v;
    D_8009B698_G330_0BD68Ptr->b7 = o->animFrame;
    switch (o->step) {
    case 0:
        o->unkB6 = -0x420;
        D_8009B698_G330_0BD68Ptr->w0e = 0;
        D_8009B698_G330_0BD68Ptr->w02 = 0x10;
        o->unkB2 = D_8009E454_GameObjectPtr->hitWidth;
        ((u8 *)o)[0xa9] = 1;
        o->animFrame &= 1;
        D_8009B698_G330_0BD68Ptr->b8 = 0;
        D_8009B698_G330_0BD68Ptr->b9 = 0;
        D_8009B698_G330_0BD68Ptr->w0c = 0;
        D_8009B698_G330_0BD68Ptr->w2e = 0xffff;
        D_8009B698_G330_0BD68Ptr->w28 = 0xffff;
        D_8009B698_G330_0BD68Ptr->w2a = 0xffff;
        o->velH = D_8009E454_GameObjectPtr->h->p.whole - o->h->p.whole;
        o->velV = D_8009E454_GameObjectPtr->y.p.whole - o->y.p.whole;
        o->unkB0 = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->velX = o->unkB8;
        o->h->p.whole = D_8009E454_GameObjectPtr->h->p.whole + o->unkB8;
        o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + o->unkBA + 8;
        o->anim = D_800112A8;
        advanceAnimFrame(o, 0);
        o->timer = 10;
        o->step++;
    case 1:
        func_8010BB00(o);
        if (--o->timer == 0)
            o->step = 2;
        break;
    case 2:
        if (D_8009E454_GameObjectPtr->type == 0x35)
            goto up;
        pad = &D_8009C9D8_U16;
        if (*pad & 0x10) {
            func_800EDEBC(o, 0x26);
            ((s32 (*)(GameObject *))tickAnimation)(o);
            if (o->unk9E != 0xc)
                o->y.raw -= 0x18000;
        } else if (*pad & 0x40) {
        up:
            func_800EDEBC(o, 0x27);
            ((s32 (*)(GameObject *))tickAnimation)(o);
            o->y.raw += 0x28000;
        }
        if (*(u16 *)o->anim == 0xda)
            *(s8 *)&o->unkF = 1;
        else
            *(s8 *)&o->unkF = -8;
        func_8010BB00(o);
        if ((*(s32 *)&GAME) == 0x30000)
            break;
        if (o->animFrame & 1)
            t = D_1F8001FC & 0x80;
        else
            t = D_1F8001FC & 0x20;
        if (t) {
            playSFXWithNote(0x1e, 8);
            D_8009B698_G330_0BD68Ptr->w2e = 0xff;
            func_800EDEBC(o, 0x38);
            o->step = 3;
        }
        break;
    case 3:
        if (((s32 (*)(GameObject *))tickAnimation)(o)) {
            h = o->h;
            v = h->p.whole;
            if (o->animFrame & 1)
                t = v - 0xc;
            else
                t = v + 0xc;
            h->p.whole = t;
            o->anim = D_800112A8;
            o->animFrame ^= 1;
            advanceAnimFrame(o, 0);
            o->timer = 10;
            o->step = 1;
        }
        break;
    default:
        return;
    }
    if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
        (*(u8 *)&D_8009C618) = 0;
        func_8010BC24(o);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010C0F8);

void func_8010C0F8(GameObject *o)
{
    char pad;
    volatile u16 *p;
    if (D_8009C1A5 != 0xff) {
        p = &D_8009C9D8_U16;
        if (*p & 0x20) {
            o->unk76 = 0;
            o->unkB6 = 0;
        }
        if (*p & 0x80) {
            o->unk76 = 4;
            o->unkB6 = 0x80;
        }
    } else if (p = &D_8009C9D8_U16, !(*p & 0xe0)) {
        if (o->timer != 0) {
            if (--o->timer <= 0) {
                if ((u32)((u16)o->unkB6 - 0x40) < 0x80)
                    o->unk76 = 4;
                else
                    o->unk76 = 0;
                o->unk76 |= 8;
            }
        }
    } else {
        o->timer = 10;
        if (*p & 0x20) {
            if (*p & 0x40) {
                if ((u32)((u16)o->unkB6 - 0x50) <= 0x20)
                    o->unkB6 = 0xe0;
                o->unk76 = 7;
            } else {
                if (o->unk76 == 4 && o->unkB6 == 0x80)
                    o->unkB6 = 0;
                o->unk76 = 0;
            }
        } else if (*p & 0x80) {
            if (*p & 0x40) {
                if ((u32)((u16)o->unkB6 - 0x10) <= 0x20)
                    o->unkB6 = 0xa0;
                o->unk76 = 5;
            } else {
                if (o->unk76 == 0 && o->unkB6 == 0)
                    o->unkB6 = 0x80;
                o->unk76 = 4;
            }
        } else if (*p & 0x40) {
            if ((u32)((u16)o->unkB6 - 0x30) <= 0x20)
                o->unkB6 = 0xc0;
            o->unk76 = 6;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010C300);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010C398);
typedef struct {
    char p0[0x20]; s16 s20; char p1[0x76 - 0x22]; u16 w76; char p2[0xb6 - 0x78]; u16 wb6;
} O_0C398;

void func_8010C398(O_0C398 *o)
{
    char pad;
    volatile u16 *p = &D_8009C9D8_U16;
    if (!(*p & 0xf0)) {
        if (o->s20 != 0) {
            if (--o->s20 <= 0) {
                if ((u16)(o->wb6 - 0x40) < 0x80) o->w76 = 4;
                else o->w76 = 0;
                o->w76 |= 8;
            }
        }
        return;
    }
    o->s20 = 10;
    if (*p & 0x20) {
        if (*p & 0x10) {
            if ((u16)(o->wb6 - 0x90) <= 0x20) o->wb6 = 0x20;
            o->w76 = 1;
            return;
        }
        if (*p & 0x40) {
            if ((u16)(o->wb6 - 0x50) <= 0x20) o->wb6 = 0xe0;
            o->w76 = 7;
            return;
        }
        if ((s16)o->wb6 == 0x80) o->wb6 = 0;
        o->w76 = 0;
        return;
    }
    if (*p & 0x80) {
        if (*p & 0x10) {
            if ((u16)(o->wb6 - 0xd0) <= 0x20) o->wb6 = 0x60;
            o->w76 = 3;
            return;
        }
        if (*p & 0x40) {
            if ((u16)(o->wb6 - 0x10) <= 0x20) o->wb6 = 0xa0;
            o->w76 = 5;
            return;
        }
        if ((s16)o->wb6 == 0) o->wb6 = 0x80;
        o->w76 = 4;
        return;
    }
    if (*p & 0x10) {
        if ((u16)(o->wb6 - 0xb0) <= 0x20) o->wb6 = 0x40;
        o->w76 = 2;
        return;
    }
    if (*p & 0x40) {
        if ((u16)(o->wb6 - 0x30) <= 0x20) o->wb6 = 0xc0;
        o->w76 = 6;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010C5D0);
extern s16 fixedMulSin2(s32, s32);
extern void func_80043AB0(GameObject *, s32, s32, s32);
void func_8010C5D0(GameObject *o)
{
    if (o->unkB2 > 0x400) o->unkB2 = 0x400;
    if (o->unkB2 < 0) o->unkB2 = 0;
    o->h->raw += D_8009BCAC * 0x100;
    o->y.raw += (*(s16 *)&D_8009BCAE) * 0x100;
    o->velH = fixedMulCos2(o->unkB6, o->unkB2);
    o->velV = fixedMulSin2(o->unkB6, o->unkB2);
    o->h->raw += o->velH * 0x100;
    o->y.raw += o->velV * 0x100;
    clampToCeilingAndProbeSides(o);
    probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
    func_80043AB0(o, o->h->p.whole, o->y.p.whole, (s16)o->animFrame);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010C6E0);
typedef struct {
    char pad0[8];
    u8 b8;
    char pad9[0x2c - 9];
    u16 w2c;
    u16 w2e;
} G330;
extern void func_8010C0F8(GameObject *);

void func_8010C6E0(GameObject *o)
{
    u32 d;
    u16 dd;
    s16 flag;
    s16 w;
    u16 h;

    func_8010C0F8(o);
    switch (o->step) {
    case 0:
        o->unk9E = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unkA7 = 0;
        *(u8 *)((u8 *)o + 0xc3) = 0;
        o->unk8C = 0;
        o->unkB0 = 0;
        (*(G330 **)&D_8009B698)->b8 = 0;
        *(u8 *)((u8 *)o + 0xca) = 1;
        o->timer = 10;
        func_800EE1F0(o);
        o->unkA4 = 0;
        o->touchFlag = 0;
        if (o->animFrame & 1) {
            o->unk76 = 4;
            o->unkB6 = 0x80;
        } else {
            o->unk76 = 0;
            o->unkB6 = 0;
        }
        o->unkB2 = 0;
        func_800EDEBC(o, 0x43);
        o->step++;
    case 1:
        break;
    default:
        return;
    }
    if (((s32 (*)(GameObject *))tickAnimation)(o)) {
        (*(G330 **)&D_8009B698)->w2c = 0x47;
        if ((*(G330 **)&D_8009B698)->w2e != 0x47)
            func_800EDEBC(o, 0x47);
    }
    switch (o->unk76 & 7) {
    case 0: o->unk7A = 0; break;
    case 1: o->unk7A = 0x20; break;
    case 2: o->unk7A = 0x40; break;
    case 3: o->unk7A = 0x60; break;
    case 4: o->unk7A = 0x80; break;
    case 5: o->unk7A = 0xa0; break;
    case 6: o->unk7A = 0xc0; break;
    case 7: o->unk7A = 0xe0; break;
    }
    if (o->unk76 & 8)
        o->unk74 = 0;
    else
        o->unk74 = 0x200;
    d = ((u16)o->unk7A - (u16)o->unkB6) & 0xff;
    dd = d;
    if (d) {
        if (dd < 0x80)
            o->unkB6 += 4;
        else
            o->unkB6 -= 4;
    }
    o->unkB6 = (u8)o->unkB6;
    if (((o->unkB6 - 0x40) & 0xff) < 0x80) {
        o->animFrame = 1;
        o->unk8C = (o->unkB6 + 0x80) & 0xff;
    } else {
        o->animFrame = 0;
        o->unk8C = o->unkB6;
    }
    if ((s16)(o->unk74 - o->unkB2) > 0)
        o->unkB2 += 8;
    else
        o->unkB2 -= 8;
    if (D_1F8001FC & (*(u16 *)&D_1F8003C4)) {
        (*(G330 **)&D_8009B698)->w2c = 0x43;
        if ((*(G330 **)&D_8009B698)->w2e != 0x43) {
            func_800EDEBC(o, 0x43);
            o->unkB2 = 0x400;
        }
    }
    func_8010C5D0(o);
    if (o->y.p.whole < o->unk56)
        o->y.p.whole = o->unk56;
    w = o->unk56;
    if (w + 0x10 < o->y.p.whole) {
        if (D_8009C1A5 == 0xff || D_8009C363) {
            flag = 0;
            if ((*(u16 *)&GAME) == 10 && (D_8009BCCA == 1 || D_8009BCCA == 5)) {
                o->y.p.whole = w + 0x10;
                flag = 1;
            }
            if (!flag) {
                func_800EDDDC(o, 0x44, 0);
                o->subState = 0x3e;
                o->step = 0;
            }
        } else {
            o->y.p.whole = w + 0x10;
        }
    }
    if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
        *(u8 *)((u8 *)o + 0xca) = 0;
        flag = 0;
        if ((*(volatile u16 *)&D_8009C9D8 & 0x10) && (*(u16 *)&GAME) == 10
            && (D_8009BCCA == 1 || D_8009BCCA == 5) && o->d->p.whole == 0 && o->y.p.whole < -0xe3) {
            h = o->h->p.whole;
            if ((u16)(h - 0x1cd) < 0x20)
                flag = 1;
            if ((u16)(h - 0x33f) < 0x20)
                flag++;
        }
        if (flag) {
            *(u8 *)((u8 *)o + 0xa1) = 0;
            o->subState = 0x11;
        } else {
            func_800EDDDC(o, 4, 0);
            (*(G330 **)&D_8009B698)->w2e = 0xff;
            o->subState = 0x43;
        }
        o->step = 0;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010CB40);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010CBD8);
typedef struct { GameObject t; char pad[10]; u8 bca; } PObj_0CBD8;

void func_8010CBD8(GameObject *o)
{
    u16 d;
    switch (o->step) {
    case 0:
        func_800EDDDC(o, 0x44, 0);
        o->timer = 10;
        ((PObj_0CBD8 *)o)->bca = 1;
        (*(GameObject **)&D_8009B698)->animFrame = 0xff;
        o->step++;
    case 1:
        if (((s32 (*)(GameObject *))tickAnimation)(o) && (u16)(*(u16 *)o->anim - 0x136) >= 4)
            func_800EDEBC(o, 0x44);
        d = o->unk76 & 7;
        switch (d) {
        case 0: o->unk7A = 0; break;
        case 1: o->unk7A = 0x20; break;
        case 2: o->unk7A = 0x40; break;
        case 3: o->unk7A = 0x60; break;
        case 4: o->unk7A = 0x80; break;
        case 5: o->unk7A = 0xa0; break;
        case 6: o->unk7A = 0xc0; break;
        case 7: o->unk7A = 0xe0; break;
        }
        if (o->unk76 & 8)
            o->unk74 = 0;
        else
            o->unk74 = 0x200;
        if ((d = (o->unk7A - o->unkB6) & 0xff)) {
            if (d < 0x80)
                o->unkB6 = o->unkB6 + 4;
            else
                o->unkB6 = o->unkB6 - 4;
        }
        o->unkB6 = (u8)o->unkB6;
        if (((o->unkB6 - 0x40) & 0xff) < 0x80) {
            o->animFrame = 1;
            o->unk8C = (o->unkB6 + 0x80) & 0xff;
        } else {
            o->animFrame = 0;
            o->unk8C = o->unkB6;
        }
        if ((s16)(o->unk74 - o->unkB2) > 0)
            o->unkB2 += 8;
        else
            o->unkB2 -= 8;
        if (D_1F8001FC & (*(u16 *)&D_1F8003C4)) {
            if ((u16)(*(u16 *)o->anim - 0x136) < 4) {
                func_800EDEBC(o, 0x45);
                o->unkB2 = 0x400;
            }
        }
        func_8010C5D0(o);
        if (D_1F8001FC & (*(u16 *)&D_1F8003C6)) {
            ((PObj_0CBD8 *)o)->bca = 0;
            o->subState = 0x44;
            o->step = 0;
        }
        if (o->y.p.whole < o->unk56 + 8) {
            o->subState = 0x3d;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010CE5C);
typedef struct {
    char pad0[8];
    u8 b8;
    char pad9[0x17];
    s16 w20;
    char pad22[0xa];
    s16 w2c;
} G330_0CE5C;
extern G330_0CE5C *D_8009B698_G330_0CE5CPtr asm("D_8009B698");
extern void func_800EE3BC(s32, s32, s32, s32);
extern s32 func_80059B58(GameObject *, s32);

void func_8010CE5C(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unk9E = 0;
        o->touchFlag = 0;
        o->unk9C = 1;
        ((u8 *)o)[0xca] = 0;
        ((u8 *)o)[0xac] = 0;
        o->velY = -0x780;
        o->unk8C = 0;
        o->unkB0 = 0;
        o->velX = 0;
        D_8009B698_G330_0CE5CPtr->w20 = 0xe;
        playSFXWithNote(2, 4);
        playSFXWithVolume(0xe, 0x7f);
        o->step++;
        break;
    case 1:
        o->h->raw += ((s16 *)&D_8009BCAC)[0] << 8;
        o->y.raw += ((s16 *)&D_8009BCAC)[1] << 8;
        tickAnimation(o);
        if (o->unkA7)
            func_800EE3BC(0, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        func_800ED9E0(o);
        if (o->velY >= -0x383)
            func_800EDFA0(o);
        clampToCeilingAndProbeSides(o);
        if (o->velY > 0) {
            D_8009B698_G330_0CE5CPtr->w2c = 4;
            func_800EDDDC(o, 4, 1);
            ((u8 *)o)[0xac] = 1;
            D_8009B698_G330_0CE5CPtr->b8 = 1;
            o->velY = 0;
            o->velV = 0;
            o->unk9C = 2;
            o->timer = 10;
            o->unk84 = 0;
            o->unk88 = (o->animFrame & 1) ? 0xf0 : 0x10;
            o->unk8C = (o->animFrame & 1) ? 0x40 : 0xc0;
            o->subState = 2;
            o->step = 3;
        }
        break;
    }
    D_8009E454 = func_80059B58(o, 0);
    if (o->unk9E) {
        D_8009B698_G330_0CE5CPtr->b8 = 0;
        D_8009B698_G330_0CE5CPtr->w20 = 0;
        ((u8 *)o)[0xac] = 0;
        o->unk9C = 0;
        o->velX = 0;
        o->velY = 0;
        o->unkB2 = 0;
        func_800EEFEC(o, D_8009E454 == 1);
    }
    func_800EE26C();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D094);
typedef struct { char p0[5]; char b5; char b6; char p1[0x69-7]; char b69; char p2[0x9c-0x6a]; char b9c; char p3[0xac-0x9d]; char bac; } TO_0D094;
extern void func_800EDDDC(TO_0D094 *o, s32 a, s32 b);

void func_8010D094(TO_0D094 *o)
{
    func_800EDDDC(o, 0x44, 0);
    o->b69 = 0;
    o->b9c = 0;
    o->bac = 0;
    o->b5 = 0x3e;
    o->b6 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D0DC);
void func_8010D0DC(GameObject *o)
{
    s16 r, w;
    s16 v;
    s16 u;
    s32 d;

    switch (o->step) {
    case 0:
        o->velY = 0x300;
        o->unk9C = 2;
        *(u8 *)((u8 *)o + 0xac) = 1;
        o->touchFlag = 0;
        o->unkB2 = 0x200;
        *(u8 *)((u8 *)o + 0xca) = 0;
        func_800EDEBC(o, 0x1d);
        o->timer = 0x78;
        o->step++;
    case 1:
        break;
    default:
        return;
    }
    d = o->unk8C;
    o->unk8C = (o->animFrame & 1) ? d + 0x10 : d - 0x10;
    r = fixedMulCos2(o->unkB6, o->unkB2);
    o->velH = r;
    o->h->raw += r << 8;
    o->y.raw += o->velY << 8;
    w = o->unkB2 - 0x10;
    o->unkB2 = w;
    if (w < 0)
        o->unkB2 = 0;
    *(volatile s16 *)&o->velY = o->velY - 0x10;
    o->timer--;
    if (*(u8 *)((u8 *)o + 0xac) == 2) {
        D_8009C650 = *(s32 *)((u8 *)o + 0xe4);
        *(u8 *)((u8 *)D_8009B698 + 8) = 0;
        o->unkA7 = 0;
        o->unkA5 = 0;
        o->subState = 0x48;
        o->step = 0;
        o->unk7 = 0;
        *(u8 *)((u8 *)o + 0xab) &= 0x7f;
        return;
    }
    v = o->velY;
    u = v;
    if (v >= 0) {
        if (o->touchFlag) {
            o->velY = u - 0x10;
            o->touchFlag = 0;
            return;
        }
        if (((s16 (*)(GameObject *, s32, s32))probeSidesAndApplyTileResponse)(o, 0, 0)) {
            o->touchFlag = 0;
            o->velY -= 0x10;
            return;
        }
        if (o->timer > 0)
            return;
    }
    func_800EDDDC(o, 0x44, 0);
    o->touchFlag = 0;
    o->unk9C = 0;
    *(u8 *)((u8 *)o + 0xac) = 0;
    o->subState = 0x3e;
    o->step = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D2D4);
typedef struct { char p0[0x2e]; u16 af; } P_0D2D4;
typedef struct { char p0[8]; u8 b8; } Q_0D2D4;
typedef struct {
    char p0[5]; u8 step, state; char p1[0x24 - 7]; s32 anim; char p2[4]; union { u32 fl; struct { u16 t, af; } s; } u;
    char p3[0x8c - 0x30]; s32 d8c; char p4[0xa0 - 0x90]; u8 da0, pa1, da2, da3; char p5[0xac - 0xa4]; u8 wac;
} O_0D2D4;
extern Q_0D2D4 *DAT_8009c330q;
extern char D_80010F40[];
extern char D_80010F8C[];

void func_8010D2D4(O_0D2D4 *o)
{
    o->wac = 0;
    if (o->u.s.af < 2) {
        switch (o->state) {
        case 0:
            o->d8c = 0;
            ((Q_0D2D4 *)(*(P_0D2D4 **)&D_8009B698))->b8 = 0;
            o->state = o->state + 1;
        case 1:
            break;
        default:
            return;
        }
        tickAnimation(o);
        func_800EDD9C(o);
        func_800EEDE0(o);
        func_800EDD2C(o);
        func_800EDBEC(o);
        if ((D_1F8001F8 & 7) == 0) {
            if ((D_1F8001F8 & 0xf) == 0)
                playSFX(0);
            else
                playSFX(1);
        }
    } else {
        if ((o->u.fl & 0xa0000) == 0xa0000 && (o->da0 & 2)) {
            (*(P_0D2D4 **)&D_8009B698)->af = 0xffff;
            o->anim = (s32)D_80010F40;
            o->da2 = 1;
        } else if ((o->u.fl & 0xc0000) == 0xc0000 && (o->da0 & 1)) {
            (*(P_0D2D4 **)&D_8009B698)->af = 0xffff;
            o->anim = (s32)D_80010F8C;
            o->da3 = 1;
        } else {
            func_800EEDE0(o);
        }
        o->step = 0;
        o->state = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D464);
typedef struct P_0D464 { s16 x; s16 y; } P_0D464;
typedef struct S_0D464 {
    u8 b0; char p0; u8 type; char p1[0x16 - 3];
    u16 w16; char p2[0x40 - 0x18]; P_0D464 *pos; P_0D464 *pos2; char p3[0x68 - 0x48];
    u8 b68; char p4[0x6e - 0x69]; u16 w6e; char p5[2]; u16 w72;
} S_0D464;
extern S_0D464 **D_1F800260;
extern u16 D_1F800250;
extern s32 D_800A53F4;
s32 func_8010D464(void)
{
    S_0D464 **list = D_1F800260;
    S_0D464 *p;
    s32 r; s16 c;
    u32 f;
    u16 h, w, d;
    u16 n = D_1F800250;
    D_1F80019E = n;
    r = 0;
    if ((D_1F8001FC & (*(u16 *)&D_1F8003C4)) == 0) return 0;
    if (n != 0)
    do {
        p = list[0];
        D_1F80019E--;
        list++;
        if (!(p->b0 & 2))
            continue;
        switch (p->type) {
        case 0x18: case 0x23: case 0x32: case 0x37: case 0x4d: case 0x55: case 0x58: case 0x59: case 0x5a:
            if (p->b68 != 0)
                break;
            if (D_8009BCA2_U8Arr[0] == 0 || D_8009BCA2_U8Arr[8] != 0 || p->pos2->y != (*(P_0D464 **)&D_800A53DC)->y) {
                p->b68 = r;
                r = p->b68;
                break;
            }
            h = p->w72 + 10;
            c = (u16)(h + (D_800A53AE[0] - p->w16)) < (s16)h * 2;
            w = p->w6e + 10;
            if (c) {
                d = w + ((*(P_0D464 **)&D_800A53D8)->y - p->pos->y);
                if (d < (s16)w * 2) {
                    f = D_800A53AE[12] & 1;
                    if ((s16)w < (s16)d) {
                        if ((f ^ 1) != 0)
                            goto done;
                    } else {
                        if (f)
                            goto done;
                    }
                    if ((s16)d < (s16)w)
                        r = 5;
                    else
                        r = 4;
                }
            }
        done:
            D_800A53F4 = 1;
            p->b68 = r;
            if (r != 0)
                D_1F80019E = 0;
            break;
        }
    } while (D_1F80019E != 0);
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D678);
typedef struct {
    GameObject o;
    u8 bc0, bc1, bc2, bc3;
    char pc4[0xcc - 0xc4];
    u8 bcc, bcd, bce;
    char pcf[0xe3 - 0xcf];
    s8 be3;
} S_0D678;
typedef struct { u8 b0, b1, b2, b3, b4, b5, b6, b7; } P_0D678;
extern void func_80033488(s32);

void func_8010D678(S_0D678 *s, s16 mode)
{
    P_0D678 *p;
    P_0D678 *q;
    s16 v, t;

    if ((D_1F8001FC & (*(u16 *)&D_1F8003C8)) == 0) return;
    (*(u8 *)&D_8009C618) = 0;
    s->bcd = 0;
    s->bce = 0;
    switch (D_8009BCF8) {
    case 1:
        if (s->bcc == 1) func_80033488(0);
        ((s16 (*)(void))func_8010D464)();
        return;
    case 2:
        if (s->bcc == 1) func_80033488(1);
        ((s16 (*)(void))func_8010D464)();
        return;
    }
    s->bc3 = 0;
    if (s->be3 >= D_8007D5D0[(*(u8 *)&D_8009C61A)]) return;
    switch (mode) {
    case 0:
        switch (D_8009C619) {
        case 1:
            s->o.subState = 0x2a;
            s->o.step = 0;
            return;
        case 2:
            s->o.subState = 0x2b;
            s->o.step = 0;
            return;
        }
        if (((s16 (*)(void))func_8010D464)() != 0) return;
        if ((*(P_0D678 **)&D_8009B698)->b0 != 0) return;
        if (s->bc0 != 0) return;
        s->o.subState = 3;
        s->o.step = 0;
        return;
    case 1:
        if (D_8009C619 == 1 || D_8009C619 == 2) return;
        p = (*(P_0D678 **)&D_8009B698);
        if (p->b0 != 0) return;
        if (s->bc0 != 0) return;
        if (*(u8 *)&s->o.unkAC == 2) return;
        p->b7 = s->o.animFrame;
        v = s->o.unkB2;
        if (v < 0) {
            t = v;
            if (!(s->o.animFrame & 1))
                t = -v;
            s->o.unkB2 = t;
        } else {
            if (s->o.animFrame & 1)
                v = -v;
            s->o.unkB2 = v;
        }
        s->o.subState = 4;
        s->o.step = 0;
        return;
    case 2:
        if (D_8009C619 == 1 || D_8009C619 == 2) return;
        if ((*(P_0D678 **)&D_8009B698)->b0 != 0) return;
        if (s->bc0 != 0) return;
        (*(P_0D678 **)&D_8009B698)->b4 = 0;
        (*(GameObject **)&D_8009E454)->touchFlag = 4;
        s->o.velH = 0;
        s->o.velV = 0;
        s->o.velX = 0;
        s->o.velY = 0;
        s->o.subState = 0x18;
        s->o.step = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D934);
void func_8010D934(GameObject *o)
{
    o->velY -= 0x10;
    if (o->velY < -0x800) {
        o->velY = -0x800;
    }
    if (((u8 *)o)[0xcc] == 3) {
        o->step = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D978);
void func_8010D978(GameObject *o)
{
    s32 v;
    o->unk84 = 0;
    v = 0x10;
    if (o->animFrame & 1) v = 0xf0;
    o->unk88 = v;
    *(u8 *)&o->unkAC = 1;
    o->unk9C = 2;
    o->timer = 10;
    o->subState = 2;
    o->step = 3;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010D9BC);
extern void func_80033488(s32);

void func_8010D9BC(GameObject *o)
{
    s32 v;
    switch (o->step) {
    case 0:
        o->timer = 0x31;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->touchFlag = 0;
        o->unk9E = 0;
        ((u8 *)o)[0xc3] = 0;
        o->touchFlag = 0;
        o->unk9C = 1;
        o->unkB0 = 0;
        ((u8 *)o)[0xa0] = 0;
        ((u8 *)o)[0xa1] = 0;
        o->unkB6 = 0;
        o->velX = fixedMulCos(0, o->unkB2);
        o->velY = -10;
        ((u8 *)D_8009B698_GameObjectPtr)[8] = 0;
        D_8009B698_GameObjectPtr->animTimer = 4;
        D_8009B698_GameObjectPtr->timer = 0;
        D_8009B698_GameObjectPtr->subState = 0;
        D_8009B698_GameObjectPtr->unk1D = 0;
        ((u8 *)o)[0xac] = 0;
        func_800EEF64(o);
        readAnimFrameCount(o);
        D_8009B698_GameObjectPtr->animFrame = D_8009B698_GameObjectPtr->animTimer;
        playSFXWithNote(2, 4);
        func_80033488(2);
        o->step = 1;
    case 1:
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        tickAnimation(o);
        func_8010E750(o);
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        o->velY -= 0x10;
        if (o->velY < -0x800)
            o->velY = -0x800;
        if (((u8 *)o)[0xcc] == 3)
            o->step = 2;
        applyObjectAltSpeedVertical(o);
        break;
    case 2:
        o->h->raw += D_8009BCAC << 8;
        o->y.raw += D_8009BCAE[0] << 8;
        tickAnimation(o);
        func_8010E750(o);
        func_800ED9E0(o);
        break;
    default:
        return;
    }
    probeSidesAndApplyTileResponse(o, 0, 0);
    if (o->velY >= -0x383)
        func_800EDFA0(o);
    if (clampToCeilingAndProbeSides(o) || o->velY > 0) {
        o->unk84 = 0;
        v = 0x10;
        if (o->animFrame & 1)
            v = 0xf0;
        o->unk88 = v;
        ((u8 *)o)[0xac] = 1;
        o->unk9C = 2;
        o->timer = 10;
        o->subState = 2;
        o->step = 3;
    }
    o->touchFlag = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010DC68);
extern u8 D_8009C61B;
extern u8 D_8009BCF8;
extern u8 D_8009C26E;
extern u8 D_8009C36E;
typedef struct { char p[0xc1]; u8 c1; } O_0DC68;
s32 func_8010DC68(O_0DC68 *o)
{
    s32 b = o->c1;
    s32 u = D_8009C61B + b * 4;
    if ((D_8009BCF8 & 3) != 0)
        u = (u8)b << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    return u;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010DCCC);
typedef struct S_0DCCC { char p[0xb2]; s16 wb2; char q[0xc1 - 0xb4]; u8 bC1; } S_0DCCC;
void func_8010DCCC(S_0DCCC *o)
{
    S_0DCCC *p = o;
    u16 u;
    s16 v;
    if (o->bC1 & 1) {
        u = o->wb2;
        if ((u16)(u + 8) < 0x11) {
            o->wb2 = 0;
        } else {
            v = u;
            if (v > 0x200) o->wb2 = u - 0x20;
            else if (v > 0x144) o->wb2 = u - 0x10;
            else if (v > 0x84) o->wb2 = u - 0xc;
            else if (v > 0) o->wb2 = u - 8;
            else if (v < -0x200) o->wb2 = u + 0x20;
            else if (v < -0x144) o->wb2 = u + 0x10;
            else if (v < -0x84) o->wb2 = u + 0xc;
            else if (v < 0) o->wb2 = u + 8;
        }
    } else {
        u = o->wb2;
        if ((u16)(u + 8) < 0x11) {
            o->wb2 = 0;
        } else {
            v = u;
            if (v > 0x200) o->wb2 = u - 8;
            else if (v > 0x144) o->wb2 = u - 4;
            else if (v > 0x84) o->wb2 = u - 6;
            else if (v > 0) o->wb2 = u - 7;
            else if (v < -0x200) o->wb2 = u + 8;
            else if (v < -0x144) o->wb2 = u + 4;
            else if (v < -0x84) o->wb2 = u + 6;
            else if (v < 0) p->wb2 = u + 7;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010DE48);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010E444);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010E5A4);
typedef struct T_0E5A4 { s16 lim; u16 inc; char pad[16]; } T_0E5A4;
typedef struct O_0E5A4 {
    char p0[0x7e]; s16 w7e;
    char p1[0xb2 - 0x80]; s16 wb2;
    char p2[0xc1 - 0xb4]; u8 bc1;
} O_0E5A4;
typedef struct G_0E5A4 { char p0[0x20]; u16 w20; } G_0E5A4;
extern T_0E5A4 D_801147B6[];

void func_8010E5A4(O_0E5A4 *o)
{
    s16 a; s16 k;
    a = o->wb2 < 0 ? -o->wb2 : o->wb2;
    k = 0;
    switch ((*(G_0E5A4 **)&D_8009B698)->w20) {
    case 0 ... 12:
        o->w7e += D_801147B6[k].inc;
        break;
    default:
        o->w7e += D_801147B6[k].inc - (a >> 7) - 8;
        break;
    }
    if (D_801147B6[k].lim < o->w7e)
        o->w7e = D_801147B6[k].lim;
    if (o->w7e < -D_801147B6[k].lim)
        o->w7e = -D_801147B6[k].lim;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_2", func_8010E678);
extern u16 D_801147B8[][10];

void func_8010E678(GameObject *o)
{
    s32 b = ((u8 *)o)[0xc1];
    s32 u = D_8009C61B + b * 4;
    if ((D_8009BCF8 & 3) != 0)
        u = (u8)b << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    switch ((u16)(*(GameObject **)&D_8009B698)->timer) {
    case 0 ... 12:
        o->velY = D_801147B8[u][2];
        break;
    case 13:
        o->velY = D_801147B8[u][1];
        break;
    }
}
