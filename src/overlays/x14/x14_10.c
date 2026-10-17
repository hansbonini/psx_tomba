#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011F7E0);
typedef struct GV2Block_1F7E0 {
    u8 _pad00[0x6];
    u16 sa6;
    u8 _pad08[0x6];
    u8 bae;
    u8 baf;
    u8 bb0;
    u8 bb1;
    u8 bb2;
    u8 bb3;
    u8 _pad14[0xc];
    u16 sc0;
    u8 bc2;
    u8 bc3;
    u8 _pad24[0x16];
    u16 sda;
    u8 _pad3c[0x4];
} GV2Block_1F7E0;
extern GV2Block_1F7E0 D_8009C608;

typedef struct GVars_1F7E0 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_1F7E0;

typedef struct { s32 a; s16 t; s16 b; } E8_1F7E0;
typedef struct { s16 w[8]; } B4_1F7E0;

extern s32 tickAnimation(GameObject *o);
extern void func_8011CBD0(GameObject *o, s32 n);
extern void func_8011CC8C(GameObject *o);
extern void func_80115FEC(GameObject *o);
extern void func_80116778(GameObject *o);
extern void func_8011EB94(void);
extern void func_8011EBCC(void);

void func_8011F7E0(GameObject *o)
{
    B4_1F7E0 *b = (B4_1F7E0 *)&o->unkB4;

    switch (o->unk7) {
    case 0:
        o->active = 2;
        D_8009C608.bb0 = 0;
        (*(GVars_1F7E0 *)&D_8009BC98).b3e = 1;
        (*(GVars_1F7E0 *)&D_8009BC98).b42 = 1;
        func_8011CBD0(o, 0x14);
        o->unk7++;
        func_8011EB94();
        break;
    case 1:
        if (tickAnimation(o)) {
            func_8011CBD0(o, 0x15);
            o->unk7++;
        }
        break;
    case 2:
        if (tickAnimation(o)) {
            func_80116778(o);
            (*(GVars_1F7E0 *)&D_8009BC98).b58 = 0;
            func_8011CC8C(o);
            func_80115FEC(o);
            o->unk7++;
            func_8011EBCC();
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            E8_1F7E0 *e = (E8_1F7E0 *)o->unk94;
            o->unk7++;
            e += o->unkAE;
            o->timer = e->t;
            func_8011CBD0(o, 0x12);
        }
        break;
    case 4:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            b->w[7] = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011F97C);
extern GameObject *allocObjectLayer2(void);

s32 func_8011F97C(GameObject *o)
{
    GameObject *n = allocObjectLayer2();

    if (n) {
        n->active = 1;
        n->type = 0x43;
        n->subtype = o->animFrame & 1;
        n->unkB4 = o->animFrame & 1;
        n->x.p.whole = o->x.p.whole;
        n->y.p.whole = o->y.p.whole;
        n->z.p.whole = o->z.p.whole;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011FA04);
typedef struct GVars_1FA04 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_1FA04;
extern s32 D_1F8002DC[];
extern void *D_80129344[];
extern s16 D_800A38E4;
extern s16 D_800A38E6;
extern void readAnimFrameCount(GameObject *);
extern s16 probeCollisionAtDepthB(GameObject *, s16, s16);
extern void func_800230BC(GameObject *, s32);
extern void freeObjectLayer2(GameObject *);

static __inline__ s32 touch_1FA04(GameObject *o, GameObject *p)
{
    if ((u16)(p->h->p.whole - o->h->p.whole + (o->hitOffsetX + p->hitOffsetX)) > o->hitWidth + p->hitWidth)
        return 0;
    return !((u16)(p->y.p.whole - o->y.p.whole + (o->hitOffsetY + p->hitOffsetY)) > p->hitHeight + o->hitHeight + 0x40);
}

static __inline__ s32 out_1FA04(GameObject *o)
{
    if (o->h->p.whole < D_800A38E4 - 0xa0)
        return 1;
    if (D_800A38E6 + 0xa0 < o->h->p.whole)
        return 1;
    if (D_800A38EA + 0x78 < o->y.p.whole)
        return 1;
    return o->y.p.whole < D_800A38E8 - 0x78;
}

void func_8011FA04(GameObject *o)
{
    GameObject *p = &PLAYER;
    s16 d, v;
    s32 t;

    switch (o->state) {
    case 0:
        o->state++;
        o->hitOffsetX = 0x18;
        o->hitWidth = 0x30;
        o->hitOffsetY = 0x40;
        o->hitHeight = 0x70;
        *(s8 *)&o->unkF = -0x10;
        o->velX = 0x80;
        o->unkA = 0xa;
        o->tpage = 1;
        o->unkD = 0x80;
        o->unk6A = 0;
        o->unkA5 = 0;
        o->unkA6 = 0;
        o->unkA7 = 0;
        o->animFrame = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->spriteBank = D_1F8002DC[0];
        o->anim = D_80129344[o->subtype];
        readAnimFrameCount(o);
        o->timer = 20;
        if (*(u16 *)&o->unkB4)
            o->velH = -0x200;
        else
            o->velH = 0x200;
        o->velV = 0;
        o->cooldownTimer = 0;
        break;
    case 1:
        if ((*(GVars_1FA04 *)&D_8009BC98).b42 == 1) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        tickAnimation(o);
        if (o->subState != 0)
            break;
        if (o->timer == 0) {
            o->unkA5 += 2;
            if (o->unkA5 >= 0xc0)
                *(s8 *)&o->unkA5 = -0x40;
            v = o->velV + 8;
            o->velV = v;
            t = o->unkA5;
            *((u8 *)o + 0xa5) = t;
            *((u8 *)o + 0xa6) = t;
            if (v > 0x100)
                o->velV = 0x100;
            if (o->velH < 0) {
                o->velH += 8;
                if (o->velH >= -0x100)
                    o->velH = -0x100;
            } else {
                o->velH -= 8;
                if (o->velH <= 0x100)
                    o->velH = 0x100;
            }
        } else {
            o->timer--;
        }
        o->h->raw += o->velH << 8;
        o->y.raw -= o->velV << 8;
        if (probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole)) {
            o->active = 2;
            o->state = 2;
            o->subState = 0;
            o->step = 0;
        } else {
            if (out_1FA04(o)) {
                o->active = 2;
                o->state = 3;
            }
        }
        if (o->unk6A == 0)
            break;
        p->h->raw += o->velH << 8;
        p->y.raw -= o->velV << 8;
        p->active = 6;
        if (o->subtype)
            p->unk8C += 0x14;
        else
            p->unk8C -= 0x14;
        p->unk8C = (u8)p->unk8C;
        if (o->h->p.whole != p->h->p.whole) {
            if (p->h->p.whole < o->h->p.whole) {
                t = (s16)(o->h->p.whole - p->h->p.whole);
                if (t >= 4)
                    d = 3;
                else
                    d = t;
            } else {
                t = (s16)(o->h->p.whole - p->h->p.whole);
                d = (t < -3) ? -3 : t;
            }
        } else
            d = 0;
        p->h->p.whole += d;
        p->y.p.whole += 6;
        if (probeCollisionAtDepthB(p, p->h->p.whole, p->y.p.whole)) {
            p->y.p.whole -= 6;
            o->state = 2;
        }
        if (touch_1FA04(o, p) && o->state == 1)
            break;
        p->active = 1;
        p->state = 1;
        p->subState = 0x3e;
        p->step = 0;
        o->active = 2;
        o->state = 2;
        o->subState = 0;
        o->step = 0;
        o->unk6A = 0;
        break;
    case 2:
        if ((*(GVars_1FA04 *)&D_8009BC98).b42 == 1) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        tickAnimation(o);
        o->velX -= 4;
        if (o->velX < 0) {
            o->velX = 0;
            o->state++;
        } else {
            func_800230BC(o, 0x50);
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011FF98);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801200E4);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801204B4);

s32 func_801204B4(GameObject *o)
{
    GameObject *n = allocObjectLayer2();
    if (n) {
        n->active = 1;
        n->type = 0x46;
        n->subtype = 0;
        n->unkC = 0;
        n->x.p.whole = (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) + 0xa0;
        n->y.p.whole = (u16)SCRATCHPAD.unk168[4].p.whole - 0xf0;
        n->z.p.whole = o->z.p.whole;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120534);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801205D8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120708);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120738);

extern u8 D_80125900[];

void func_80120738(GameObject *o)
{
    s16 v;

    switch (o->subState) {
    case 0:
        o->timer = (nextRandom() & 0x30) + 0x5a;
        o->subState++;
        o->velY = D_80125900[o->subtype];
        if (o->unkC) {
            v = o->velH;
            if (v < 0) o->velH = v - 0x80;
            else o->velH = v + 0x80;
        }
        break;
    case 1:
        o->visible = 1;
        o->h->raw += o->velH << 8;
        o->velV += o->velY;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->animFrame) o->unk8C = (o->unk8C + 0x80) & 0xfff;
        else o->unk8C = (o->unk8C - 0x80) & 0xfff;
        if (o->timer < 0x28) {
            if ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1) o->visible = 1;
            else o->visible = 0;
        }
        if (--o->timer == -1) o->state++;
        break;
    }
    if (o->visible) func_80022E44(o);
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801208F4);

typedef struct GVars_208F4 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_208F4;

struct GSInventory_208F4 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_208F4 { u8 weapon; u8 pants; };
typedef struct GameState_208F4 {
    u16 selectedArea;
    u16 selectedSection;
    u8 selectedPlane;
    u8 area00_fogControl;
    u8 unk6;
    u8 keepBgm;
    s32 totalTimePlayed;
    unsigned long playerAP;
    u8 playerHealth;
    u8 playerHealthDisplayed;
    char unk12;
    char unk13;
    u8 areaTransition;
    u8 fadeScreenControl;
    u8 fadeScreenAmount;
    u8 saveSlot;
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 playerLives;
    u8 unk21;
    u16 selectedSpawnPoint;
    s32 area00_eventControl;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    u8 unk2f;
    u8 displayExpBar;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 area00_pickedItems[32];
    u8 area01_pickedItems[32];
    u8 area02_pickedItems[32];
    u8 area03_pickedItems[32];
    u8 area04_pickedItems[32];
    u8 area05_pickedItems[32];
    u8 area06_pickedItems[32];
    u8 area07_pickedItems[32];
    u8 area08_pickedItems[32];
    u8 area09_pickedItems[32];
    u8 area10_pickedItems[32];
    u8 area11_pickedItems[32];
    u8 area12_pickedItems[32];
    u8 area13_pickedItems[32];
    u8 area14_pickedItems[32];
    u8 area15_pickedItems[32];
    u8 area16_pickedItems[32];
    u8 area17_pickedItems[32];
    u8 area18_pickedItems[32];
    u8 area19_pickedItems[32];
    u8 unk2b4;
    u8 unk2b5;
    u8 unk2b6;
    u8 unk2b7;
    u8 unk2b8;
    u8 unk2b9;
    u8 unk2ba;
    u8 unk2bb;
    u8 unk2bc;
    u8 unk2bd;
    u8 unk2be;
    u8 unk2bf;
    u8 unk2c0;
    u8 unk2c1;
    u8 unk2c2;
    u8 unk2c3;
    u8 unk2c4;
    u8 unk2c5;
    u8 unk2c6;
    u8 unk2c7;
    u8 unk2c8;
    u8 unk2c9;
    u8 unk2ca;
    u8 unk2cb;
    u8 unk2cc;
    u8 unk2cd;
    u8 unk2ce;
    u8 unk2cf;
    u8 unk2d0;
    u8 unk2d1;
    u8 unk2d2;
    u8 unk2d3;
    u8 unk2d4;
    u8 unk2d5;
    u8 unk2d6;
    u8 unk2d7;
    u8 unk2d8;
    u8 unk2d9;
    u8 unk2da;
    u8 unk2db;
    u8 unk2dc;
    u8 unk2dd;
    u8 unk2de;
    u8 unk2df;
    u8 unk2e0;
    u8 unk2e1;
    u8 unk2e2;
    u8 unk2e3;
    u8 unk2e4;
    u8 unk2e5;
    u8 unk2e6;
    u8 unk2e7;
    u8 unk2e8;
    u8 unk2e9;
    u8 unk2ea;
    u8 unk2eb;
    u8 unk2ec;
    u8 unk2ed;
    u8 unk2ee;
    u8 unk2ef;
    u8 unk2f0;
    u8 unk2f1;
    u8 unk2f2;
    u8 unk2f3;
    u8 unk2f4;
    u8 unk2f5;
    u8 unk2f6;
    u8 unk2f7;
    u8 unk2f8;
    u8 unk2f9;
    u8 unk2fa;
    u8 unk2fb;
    u8 unk2fc;
    u8 unk2fd;
    u8 unk2fe;
    u8 unk2ff;
    u8 unk300;
    u8 unk301;
    u8 unk302;
    u8 unk303;
    u8 unk304;
    u8 unk305;
    u8 unk306;
    u8 unk307;
    u8 unk308;
    u8 unk309;
    u8 unk30a;
    u8 unk30b;
    u8 unk30c;
    u8 unk30d;
    u8 unk30e;
    u8 unk30f;
    u8 unk310;
    u8 unk311;
    u8 unk312;
    u8 unk313;
    u8 unk314;
    u8 unk315;
    u8 unk316;
    u8 unk317;
    u8 unk318;
    u8 unk319;
    u8 unk31a;
    u8 unk31b;
    u8 unk31c;
    u8 unk31d;
    u8 unk31e;
    u8 unk31f;
    u8 unk320;
    u8 unk321;
    u8 unk322;
    u8 unk323;
    u8 unk324;
    u8 unk325;
    u8 unk326;
    u8 unk327;
    u8 unk328;
    u8 unk329;
    u8 unk32a;
    u8 unk32b;
    u8 unk32c;
    u8 unk32d;
    u8 unk32e;
    u8 unk32f;
    u8 unk330;
    u8 unk331;
    u8 unk332;
    u8 unk333;
    u8 unk334;
    u8 unk335;
    u8 unk336;
    u8 unk337;
    u8 unk338;
    u8 unk339;
    u8 unk33a;
    u8 unk33b;
    u8 unk33c;
    u8 unk33d;
    u8 unk33e;
    u8 unk33f;
    u8 unk340;
    u8 unk341;
    u8 unk342;
    u8 unk343;
    u8 unk344;
    u8 unk345;
    u8 unk346;
    u8 unk347;
    u8 unk348;
    u8 unk349;
    u8 unk34a;
    u8 unk34b;
    u8 unk34c;
    u8 unk34d;
    u8 unk34e;
    u8 unk34f;
    u8 unk350;
    u8 unk351;
    u8 unk352;
    u8 unk353;
    u8 unk354;
    u8 unk355;
    u8 unk356;
    u8 unk357;
    u8 unk358;
    u8 unk359;
    u8 unk35a;
    u8 unk35b;
    u8 unk35c;
    u8 unk35d;
    u8 unk35e;
    u8 unk35f;
    u8 unk360;
    u8 unk361;
    u8 unk362;
    u8 unk363;
    u8 unk364;
    u8 unk365;
    u8 unk366;
    u8 unk367;
    u8 unk368;
    u8 unk369;
    u8 unk36a;
    u8 unk36b;
    u8 unk36c;
    u8 unk36d;
    u8 unk36e;
    u8 unk36f;
    u8 unk370;
    u8 unk371;
    u8 unk372;
    u8 unk373;
    u8 unk374;
    u8 unk375;
    u8 unk376;
    u8 unk377;
    u8 unk378;
    u8 unk379;
    u8 unk37a;
    u8 unk37b;
    u8 unk37c;
    u8 unk37d;
    u8 unk37e;
    u8 unk37f;
    u8 unk380;
    u8 unk381;
    u8 unk382;
    u8 unk383;
    u8 unk384;
    u8 unk385;
    u8 unk386;
    u8 unk387;
    u8 unk388;
    u8 unk389;
    u8 unk38a;
    u8 unk38b;
    u8 unk38c;
    u8 unk38d;
    u8 unk38e;
    u8 unk38f;
    u8 unk390;
    u8 unk391;
    u8 unk392;
    u8 unk393;
    u8 unk394;
    u8 unk395;
    u8 unk396;
    u8 unk397;
    u8 unk398;
    u8 unk399;
    u8 unk39a;
    u8 unk39b;
    u8 unk39c;
    u8 unk39d;
    u8 unk39e;
    u8 unk39f;
    u8 unk3a0;
    u8 unk3a1;
    u8 unk3a2;
    u8 unk3a3;
    u8 unk3a4;
    u8 unk3a5;
    u8 unk3a6;
    u8 unk3a7;
    u8 unk3a8;
    u8 unk3a9;
    u8 unk3aa;
    u8 unk3ab;
    u8 unk3ac;
    u8 unk3ad;
    u8 unk3ae;
    u8 unk3af;
    u8 unk3b0;
    u8 unk3b1;
    u8 unk3b2;
    u8 unk3b3;
    u8 unk3b4;
    u8 unk3b5;
    u8 unk3b6;
    u8 unk3b7;
    u8 unk3b8;
    u8 unk3b9;
    u8 unk3ba;
    u8 unk3bb;
    u8 unk3bc;
    u8 unk3bd;
    u8 unk3be;
    u8 unk3bf;
    u8 unk3c0;
    u8 unk3c1;
    u8 unk3c2;
    u8 unk3c3;
    u8 unk3c4;
    u8 unk3c5;
    u8 unk3c6;
    u8 unk3c7;
    u8 unk3c8;
    u8 unk3c9;
    u8 unk3ca;
    u8 unk3cb;
    u8 unk3cc;
    u8 unk3cd;
    u8 unk3ce;
    u8 unk3cf;
    u8 unk3d0;
    u8 unk3d1;
    u8 unk3d2;
    u8 unk3d3;
    u8 unk3d4;
    u8 unk3d5;
    u8 unk3d6;
    u8 unk3d7;
    u8 unk3d8;
    u8 unk3d9;
    u8 unk3da;
    u8 unk3db;
    u8 unk3dc;
    u8 unk3dd;
    u8 unk3de;
    u8 unk3df;
    u8 unk3e0;
    u8 unk3e1;
    u8 unk3e2;
    u8 unk3e3;
    u8 unk3e4;
    u8 unk3e5;
    u8 unk3e6;
    u8 unk3e7;
    u8 unk3e8;
    u8 unk3e9;
    u8 unk3ea;
    u8 unk3eb;
    u8 unk3ec;
    u8 unk3ed;
    u8 unk3ee;
    u8 unk3ef;
    u8 unk3f0;
    u8 unk3f1;
    u8 unk3f2;
    u8 unk3f3;
    u8 unk3f4;
    u8 unk3f5;
    u8 unk3f6;
    u8 unk3f7;
    u8 unk3f8;
    u8 unk3f9;
    u8 unk3fa;
    u8 unk3fb;
    u8 unk3fc;
    u8 unk3fd;
    u8 unk3fe;
    u8 unk3ff;
    u8 unk400;
    u8 unk401;
    u8 unk402;
    u8 unk403;
    u8 unk404;
    u8 unk405;
    u8 unk406;
    u8 unk407;
    u8 unk408;
    u8 unk409;
    u8 unk40a;
    u8 unk40b;
    u8 unk40c;
    u8 unk40d;
    u8 unk40e;
    u8 unk40f;
    u8 unk410;
    u8 unk411;
    u8 unk412;
    u8 unk413;
    u8 unk414;
    u8 unk415;
    u8 unk416;
    u8 unk417;
    u8 unk418;
    u8 unk419;
    u8 unk41a;
    u8 unk41b;
    u8 unk41c;
    u8 unk41d;
    u8 unk41e;
    u8 unk41f;
    u8 unk420;
    u8 unk421;
    u8 unk422;
    u8 unk423;
    u8 unk424;
    u8 unk425;
    u8 unk426;
    u8 unk427;
    u8 unk428;
    u8 unk429;
    u8 unk42a;
    u8 unk42b;
    u8 unk42c;
    u8 unk42d;
    u8 unk42e;
    u8 unk42f;
    u8 unk430;
    u8 unk431;
    u8 unk432;
    u8 unk433;
    u16 nextArea;
    u16 nextSection;
    u8 redExpLevel;
    u8 greenExpLevel;
    u8 blueExpLevel;
    u8 redExpBar;
    u8 greenExpBar;
    u8 blueExpBar;
    u8 unk43e;
    u8 unk43f;
    u16 nextSpawnPoint;
    u8 disableSelectMenu;
    u8 inventoryScreen;
    u8 event[256];
    u8 unk544;
    u8 unk545;
    u8 unk546;
    u8 unk547;
    u8 unk548;
    u8 unk549;
    u8 unk54a;
    u8 baronState;
    u8 unk54c;
    u8 unk54d;
    u8 unk54e;
    char unk54f;
    u8 unk550;
    u8 unk551;
    u8 unk552;
    u8 unk553;
    u8 unk554;
    u8 unk555;
    u8 unk556;
    u8 unk557;
    u8 unk558;
    u8 unk559;
    u8 unk55a;
    u8 unk55b;
    u8 unk55c;
    u8 unk55d;
    u8 unk55e;
    u8 unk55f;
    u8 unk560;
    u8 unk561;
    u8 unk562;
    u8 unk563;
    u8 unk564;
    u8 unk565;
    u8 unk566;
    u8 unk567;
    u8 unk568;
    u8 unk569;
    u8 unk56a;
    u8 unk56b;
    u8 unk56c;
    u8 unk56d;
    u8 unk56e;
    u8 unk56f;
    u8 unk570;
    u8 unk571;
    u8 unk572;
    u8 unk573;
    u8 unk574;
    u8 unk575;
    u8 unk576;
    u8 unk577;
    u8 unk578;
    u8 unk579;
    u8 unk57a;
    u8 unk57b;
    u8 unk57c;
    u8 unk57d;
    u8 unk57e;
    u8 unk57f;
    u8 unk580;
    u8 unk581;
    u8 unk582;
    u8 unk583;
    u8 unk584;
    u8 unk585;
    u8 unk586;
    u8 unk587;
    u8 unk588;
    u8 unk589;
    u8 unk58a;
    u8 unk58b;
    u8 unk58c;
    u8 unk58d;
    u8 unk58e;
    u8 unk58f;
    u8 unk590;
    u8 unk591;
    u8 unk592;
    u8 unk593;
    u8 unk594;
    u8 unk595;
    u8 unk596;
    u8 unk597;
    u8 unk598;
    u8 unk599;
    u8 unk59a;
    u8 unk59b;
    u8 unk59c;
    u8 unk59d;
    u8 unk59e;
    u8 unk59f;
    u8 unk5a0;
    u8 pipeState;
    u8 unk5a2;
    u8 unk5a3;
    u8 unk5a4;
    u8 unk5a5;
    u8 unk5a6;
    u8 unk5a7;
    u8 unk5a8;
    u8 unk5a9;
    u8 unk5aa;
    u8 unk5ab;
    u8 unk5ac;
    u8 unk5ad;
    u8 unk5ae;
    u8 unk5af;
    u8 unk5b0;
    u8 unk5b1;
    u8 unk5b2;
    u8 unk5b3;
    u8 unk5b4;
    u8 unk5b5;
    u8 unk5b6;
    u8 unk5b7;
    u8 unk5b8;
    u8 unk5b9;
    u8 unk5ba;
    u8 unk5bb;
    u8 unk5bc;
    u8 unk5bd;
    u8 unk5be;
    u8 unk5bf;
    u8 unk5c0;
    u8 unk5c1;
    u8 unk5c2;
    u8 unk5c3;
    u8 unk5c4;
    u8 unk5c5;
    u8 unk5c6;
    u8 unk5c7;
    u8 unk5c8;
    u8 unk5c9;
    u8 unk5ca;
    u8 unk5cb;
    u8 unk5cc;
    u8 unk5cd;
    u8 unk5ce;
    u8 unk5cf;
    u8 unk5d0;
    u8 unk5d1;
    u8 unk5d2;
    u8 unk5d3;
    u8 unk5d4;
    u8 unk5d5;
    u8 unk5d6;
    u8 unk5d7;
    u8 unk5d8;
    u8 unk5d9;
    u8 unk5da;
    u8 unk5db;
    u8 unk5dc;
    u8 unk5dd;
    u8 unk5de;
    u8 unk5df;
    u8 unk5e0;
    u8 unk5e1;
    u8 unk5e2;
    u8 unk5e3;
    u8 unk5e4;
    u8 unk5e5;
    u8 unk5e6;
    u8 unk5e7;
    u8 unk5e8;
    u8 unk5e9;
    u8 unk5ea;
    u8 unk5eb;
    u8 unk5ec;
    u8 unk5ed;
    u8 unk5ee;
    u8 unk5ef;
    u8 unk5f0;
    u8 unk5f1;
    u8 unk5f2;
    u8 unk5f3;
    u8 unk5f4;
    u8 unk5f5;
    u8 unk5f6;
    u8 unk5f7;
    u8 unk5f8;
    u8 unk5f9;
    u8 unk5fa;
    u8 unk5fb;
    u8 unk5fc;
    u8 unk5fd;
    u8 unk5fe;
    u8 unk5ff;
    u8 unk600;
    u8 unk601;
    u8 unk602;
    u8 unk603;
    u8 unk604;
    u8 unk605;
    u8 unk606;
    u8 unk607;
    u8 unk608;
    u8 unk609;
    u8 unk60a;
    u8 unk60b;
    u8 unk60c;
    u8 unk60d;
    u8 unk60e;
    u8 unk60f;
    u8 unk610;
    u8 unk611;
    u8 unk612;
    u8 unk613;
    u8 unk614;
    u8 unk615;
    u8 unk616;
    u8 unk617;
    u8 unk618;
    u8 unk619;
    u8 unk61a;
    u8 unk61b;
    u8 unk61c;
    u8 unk61d;
    u8 unk61e;
    u8 unk61f;
    u8 unk620;
    u8 unk621;
    u8 unk622;
    u8 unk623;
    u8 unk624;
    u8 unk625;
    u8 unk626;
    u8 unk627;
    u8 unk628;
    u8 unk629;
    u8 unk62a;
    u8 unk62b;
    u8 unk62c;
    u8 unk62d;
    u8 unk62e;
    u8 unk62f;
    u8 unk630;
    u8 unk631;
    u8 unk632;
    u8 unk633;
    u8 unk634;
    u8 unk635;
    u8 unk636;
    u8 unk637;
    u8 unk638;
    u8 unk639;
    u8 unk63a;
    u8 unk63b;
    u8 unk63c;
    u8 unk63d;
    u8 unk63e;
    u8 unk63f;
    u8 unk640;
    u8 unk641;
    u8 unk642;
    u8 unk643;
    u8 unk644;
    u8 unk645;
    u8 unk646;
    u8 unk647;
    u8 unk648;
    u8 unk649;
    u8 unk64a;
    u8 unk64b;
    u8 unk64c;
    u8 unk64d;
    u8 unk64e;
    u8 unk64f;
    u8 unk650;
    u8 unk651;
    u8 unk652;
    u8 unk653;
    u8 unk654;
    u8 unk655;
    u8 unk656;
    u8 unk657;
    u8 unk658;
    u8 unk659;
    u8 unk65a;
    u8 unk65b;
    u8 unk65c;
    u8 unk65d;
    u8 unk65e;
    u8 unk65f;
    u8 unk660;
    u8 unk661;
    u8 unk662;
    u8 unk663;
    u8 unk664;
    u8 unk665;
    u8 unk666;
    u8 unk667;
    u8 unk668;
    u8 unk669;
    u8 unk66a;
    u8 unk66b;
    u8 unk66c;
    u8 unk66d;
    u8 unk66e;
    u8 unk66f;
    s16 unk670;
    s16 unk672;
    s16 unk674;
    u8 unk676;
    u8 unk677;
    u8 unk678;
    u8 unk679;
    u8 unk67a;
    u8 unk67b;
    u8 unk67c;
    u8 unk67d;
    u8 unk67e;
    u8 unk67f;
    u8 unk680;
    u8 unk681;
    u8 unk682;
    u8 unk683;
    u8 goldenFlowerState;
    u8 unk685;
    u8 unk686;
    u8 unk687;
    u8 unk688;
    u8 unk689;
    u8 unk68a;
    u8 unk68b;
    u8 unk68c;
    u8 unk68d;
    u8 unk68e;
    u8 unk68f;
    u8 unk690;
    u8 unk691;
    u8 unk692;
    u8 unk693;
    u8 unk694;
    u8 unk695;
    u8 unk696;
    u8 unk697;
    u8 unk698;
    u8 unk699;
    u8 unk69a;
    u8 unk69b;
    u8 unk69c;
    u8 unk69d;
    u8 unk69e;
    u8 unk69f;
    u8 unk6a0;
    u8 unk6a1;
    u8 unk6a2;
    u8 unk6a3;
    u8 unk6a4;
    u8 unk6a5;
    u8 unk6a6;
    u8 unk6a7;
    u8 unk6a8;
    u8 unk6a9;
    u8 unk6aa;
    u8 unk6ab;
    u8 unk6ac;
    u8 unk6ad;
    u8 unk6ae;
    u8 playerIdleState;
    u8 unk6b0;
    u8 unk6b1;
    u8 unk6b2;
    u8 unk6b3;
    u8 unk6b4;
    u8 unk6b5;
    u8 unk6b6;
    u8 unk6b7;
    u8 unk6b8;
    u8 unk6b9;
    u8 unk6ba;
    u8 unk6bb;
    u8 unk6bc;
    u8 unk6bd;
    u8 unk6be;
    u8 unk6bf;
    u8 unk6c0;
    u8 unk6c1;
    u8 unk6c2;
    u8 unk6c3;
    u8 unk6c4;
    u8 unk6c5;
    u8 unk6c6;
    u8 unk6c7;
    u8 unk6c8;
    u8 unk6c9;
    u8 unk6ca;
    u8 unk6cb;
    u8 unk6cc;
    u8 unk6cd;
    u8 unk6ce;
    u8 unk6cf;
    u8 unk6d0;
    u8 unk6d1;
    u8 unk6d2;
    u8 unk6d3;
    u8 unk6d4;
    u8 unk6d5;
    u8 unk6d6;
    u8 unk6d7;
    u8 unk6d8;
    u8 unk6d9;
    u8 unk6da;
    u8 unk6db;
    u8 unk6dc;
    u8 unk6dd;
    u8 unk6de;
    u8 unk6df;
    u8 unk6e0;
    u8 unk6e1;
    u8 unk6e2;
    u8 unk6e3;
    u8 unk6e4;
    u8 unk6e5;
    u8 unk6e6;
    u8 unk6e7;
    u8 unk6e8;
    u8 unk6e9;
    u8 unk6ea;
    u8 unk6eb;
    u8 unk6ec;
    u8 unk6ed;
    u8 unk6ee;
    u8 unk6ef;
    u8 unk6f0;
    u8 unk6f1;
    u8 unk6f2;
    u8 unk6f3;
    u8 unk6f4;
    u8 unk6f5;
    u8 unk6f6;
    u8 unk6f7;
    u8 unk6f8;
    u8 unk6f9;
    u8 unk6fa;
    u8 unk6fb;
    u8 unk6fc;
    u8 unk6fd;
    u8 unk6fe;
    u8 unk6ff;
    u8 unk700;
    u8 unk701;
    u8 unk702;
    u8 unk703;
    u8 unk704;
    u8 unk705;
    u8 unk706;
    u8 unk707;
    u8 unk708;
    u8 unk709;
    u8 unk70a;
    u8 unk70b;
    u8 unk70c;
    u8 unk70d;
    u8 unk70e;
    u8 unk70f;
    u8 unk710;
    u8 unk711;
    u8 unk712;
    u8 unk713;
    u8 unk714;
    u8 unk715;
    u8 unk716;
    u8 unk717;
    u8 unk718;
    u8 unk719;
    u8 unk71a;
    u8 bittingPlantFlowerState;
    u8 unk71c;
    u8 unk71d;
    u8 unk71e;
    u8 goldenBowlState;
    u8 bonusHealth;
    u8 unk721;
    u8 unk722;
    u8 unk723;
    u8 unk724;
    u8 unk725;
    u8 unk726;
    u8 unk727;
    u8 unk728;
    u8 unk729;
    u8 unk72a;
    u8 unk72b;
    u8 unk72c;
    u8 unk72d;
    u8 unk72e;
    u8 unk72f;
    u8 unk730;
    u8 unk731;
    u8 unk732;
    u8 unk733;
    u8 unk734;
    u8 unk735;
    char unk736;
    u8 unk737;
    u8 unk738;
    u8 unk739;
    u8 unk73a;
    u8 unk73b;
    u8 unk73c;
    u8 unk73d;
    u8 unk73e;
    u8 unk73f;
    u8 unk740;
    u8 unk741;
    u8 unk742;
    u8 unk743;
    u8 item[256];
    struct GSInventory_208F4 inventory;
    u16 currentArea;
    u16 currentSection;
    u16 currentSpawnPoint;
    u8 inventoryButton;
    u8 playerState;
    struct GSEquips_208F4 playerEquips;
    u8 unk952;
    u8 unk953;
    u8 unk954;
    u8 unk955;
    u8 unk956;
    u8 unk957;
    u8 unk958;
    u8 unk959;
    u8 unk95a;
    u8 unk95b;
    u8 unk95c;
    u8 unk95d;
    u8 unk95e;
    u8 unk95f;
    u8 unk960;
    u8 unk961;
    u8 unk962;
    u8 purifiedAreas;
    u8 unk964;
    u8 unk965;
    u8 unk966;
    u8 unk967;
    u8 unk968;
    u8 unk969;
    u8 unk96a;
    u8 unk96b;
    u8 unk96c;
    u8 unk96d;
    u8 unk96e;
    u8 unk96f;
    u8 unk970;
    u8 unk971;
    u8 unk972;
    u8 unk973;
    u8 unk974;
    u8 unk975;
    u8 unk976;
    u8 unk977;
    u8 unk978;
    u8 unk979;
    u8 unk97a;
    u8 unk97b;
    u8 unk97c;
    u8 unk97d;
    u8 unk97e;
    u8 unk97f;
    u8 unk980;
    u8 unk981;
    u8 unk982;
    u8 unk983;
    u8 unk984;
} GameState_208F4;

void func_801208F4(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (o->subtype == 0) {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->unkA0 = *pp + q[2];
            else o->unkA0 = *pp + q[1];
            o->unkA4 = 1;
            o->hitOffsetX = 0x1c;
            o->hitWidth = 0x38;
            o->hitOffsetY = 0x1c;
            o->hitHeight = 0x38;
        } else {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->unkA0 = *pp + q[1];
            else o->unkA0 = *pp + q[0];
            o->unkA4 = 1;
            o->hitOffsetX = 6;
            o->hitWidth = 0xc;
            o->hitOffsetY = 6;
            o->hitHeight = 0xc;
        }
        o->unkA = 0x11;
        o->unkF = 0;
        o->unkC = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->state++;
        break;
    case 1:
        if ((*(GVars_208F4 *)&D_8009BC98).b42 == 1) {
            func_80022E44(o);
        } else if (o->subtype == 0) {
            func_80022E44(o);
            func_80120534(o);
        } else {
            func_80120738(o);
        }
        break;
    case 2:
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120AB0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120AC8);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120BA0);
extern GameObject *allocObjectLayer2(void);

void func_80120BA0(GameObject *o, s32 sub)
{
    s32 i;
    GameObject *e;

    for (i = 0; i < 6; i++) {
        e = allocObjectLayer2();
        if (e) {
            e->type = 0x47;
            e->active = 2;
            e->subtype = sub;
            e->unkC = i + 1;
            e->state = 2;
            e->unkA = o->unkA;
            e->tpage = o->tpage;
            e->unkD = o->unkD;
            e->spriteBank = o->spriteBank;
            e->unkF = o->unkF;
            e->x.raw = o->x.p.whole << 16;
            e->y.raw = o->y.p.whole << 16;
            e->z.raw = o->z.p.whole << 16;
        }
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120C90);
extern GameObject *allocObjectLayer4(void);

#define SPAWN(o, X, Y, Z) { \
    e = allocObjectLayer4(); \
    if (e) { \
        e->active = 1; \
        e->type = 0x43; \
        e->unk30 = X; \
        e->unk34 = Y; \
        e->subtype = 0; \
        e->unk38 = Z; \
        e->h->raw = o->h->raw + e->unk30; \
        e->y.raw = o->y.raw + e->unk34; \
        e->d->raw = o->d->raw + e->unk38; \
        e->unk90 = (s32)o; \
    } }

void func_80120C90(GameObject *o, s16 n)
{
    GameObject *e;

    switch (n) {
    case 0:
        SPAWN(o, -0x350000, -0x190000, -0x5a0000);
        SPAWN(o, -0x30000, 0x440000, -0x5a0000);
        break;
    case 1:
        SPAWN(o, 0x130000, -0x2b0000, -0x5a0000);
        SPAWN(o, -0x120000, 0x2a0000, -0x5a0000);
        break;
    }
}
#undef SPAWN

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120E90);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120ECC);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8012104C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801210A4);
