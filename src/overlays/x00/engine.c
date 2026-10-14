#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E9120);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E91F8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E92D4);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E94C8);
typedef struct { char p0[4]; u8 b4, b5; char p1[0x2e - 6]; s16 s2e; } TO_E94C8;
extern void freeObjectLayer3(TO_E94C8 *o);

void func_800E94C8(TO_E94C8 *o)
{
    extern void func_800E9580(TO_E94C8 *o);
    switch (o->b4) {
    case 0:
        func_800E9580(o);
        o->s2e = 0;
        o->b4++;
    case 1:
        func_80022E44(o);
        if (o->b5 == 0) o->b5++;
        break;
    case 2:
        o->b4++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E9580);
extern s32 D_1F8002D4;
extern void *D_8013A458[];
extern void readAnimFrameCount(GameObject *o);

void func_800E9580(GameObject *o)
{
    s32 v;
    v = -10;
    o->tpage = 10;
    o->unkD = 0;
    o->unkA = 0;
    if (o->subtype == 0) v = 1;
    *(s8 *)&o->unkF = v;
    o->spriteBank = D_1F8002D4;
    o->anim = D_8013A458[o->subtype];
    readAnimFrameCount(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E95E4);
typedef struct { s16 x, y; } V2_E95E4;
extern void *D_8013A434[];
extern void *D_80134000[];
extern V2_E95E4 D_80113DB8[];
void func_80023020(GameObject *o);
s16 probeCollisionAtDepthB(GameObject *o, s32 x, s32 y);

void func_800E95E4(GameObject *o)
{
    s16 *v = &o->unkB4;
    char pad[8];
    switch (o->state) {
    case 0:
        if ((*(u16 *)&GAME) == 0) o->anim = D_8013A434[o->subtype];
        else o->anim = D_80134000[o->subtype];
        v[1] = -0x400;
        readAnimFrameCount(o);
        o->state++;
        break;
    case 1:
        if (func_80022E44(o) == 0) func_80023020(o);
        switch (o->subState) {
        case 0:
            o->unkB4 = D_80113DB8[o->unkB8].x;
            o->unkB6 = D_80113DB8[*(s16 *)((char *)o + 0xb8)].y;
            o->subState++;
        case 1:
            o->h->raw += v[0] << 8;
            o->y.raw += v[1] << 8;
            v[1] += 0x20;
            if (o->animFrame & 1) o->unk8C = (o->unk8C - 4) & 0xfff;
            else o->unk8C = (o->unk8C + 8) & 0xfff;
            if (v[1] > 0) o->subState++;
            break;
        case 2:
            o->h->raw += o->unkB4 << 8;
            o->y.raw += o->unkB6 << 8;
            o->unkB6 += 0x20;
            if (o->animFrame & 1) o->unk8C = (o->unk8C - 4) & 0xfff;
            else o->unk8C = (o->unk8C + 8) & 0xfff;
            if (probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole)) {
                o->state = 2;
                o->subState = 0;
            }
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E98A4);
extern s8 D_80113DD0[];

void func_800E98A4(GameObject *a, s16 x, s16 y, s16 z)
{
    GameObject *o;
    s8 *p;
    s32 i;
    for (i = 0; i < 6; i++) {
        o = allocObjectLayer3();
        if (o != 0) {
            p = &D_80113DD0[i * 4];
            o->active = 2;
            o->type = 5;
            o->animFrame = 0;
            o->x.raw = (x + *p++) << 16;
            o->y.raw = (y + *p++) << 16;
            o->z.raw = (z + *p++) << 16;
            o->unkB8 = (s8)*(u8 *)p;
            *(s8 *)&o->unkF = -2;
            o->unkD = 0;
            o->unkA = 2;
            o->subtype = i;
            o->unk8C = 0x1000;
            o->spriteBank = a->spriteBank;
            o->tpage = a->tpage;
            o->unk1D = a->unk1D;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800E99DC);
extern s32 D_1F8002D4_S32Arr[] asm("D_1F8002D4");
extern void *D_8013A4EC[];
extern void *D_8013D8FC[];
extern void *D_8012D3D8[];
extern s16 D_80113DE8[];
extern s16 D_80113DF8[];

void func_800E99DC(GameObject *o)
{
    GameObject *c;
    s16 v;
    s32 t;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            if (--o->cooldownTimer == -1) {
                o->cooldownTimer = nextRandom() & 0xf;
                c = allocObjectLayer3();
                if (c) {
                    c->active = 1;
                    c->type = 0xc;
                    c->subtype = 1;
                    c->unkAC = (D_1F8001F8 + D_1F800198) & 1;
                    c->unkC = nextRandom() & 7;
                    *c->h = *o->h;
                    c->h->p.whole += o->timer * 2 - 8;
                    c->y = o->y;
                    *c->d = *o->d;
                }
                if (--o->timer == 0) {
                    o->subtype = 1;
                    o->unkAC = 0;
                    o->unkC = nextRandom() & 7;
                }
            }
            break;
        case 1:
            o->state++;
            if ((D_1F8001F8 + D_1F800198) & 1) o->timer = 0x32; else o->timer = 0x1e;
            o->unkD = 0;
            *(s8 *)&o->unkF = -12;
            if ((*(u16 *)&GAME) == 0) {
                o->tpage = 9;
                o->anim = D_8013A4EC[o->unkAC];
            } else if ((*(u16 *)&GAME) == 1 || (*(u16 *)&GAME) == 7) {
                o->tpage = 8;
                o->anim = D_8013D8FC[o->unkAC];
            } else if ((*(u16 *)&GAME) == 9) {
                o->tpage = 9;
                o->anim = D_8012D3D8[o->unkAC];
            }
            o->spriteBank = D_1F8002D4_S32Arr[0];
            switch (o->unkC) {
            case 0:
            case 1:
                o->velV = -0x180;
                o->unkA = 0;
                o->velY = 0x10;
                break;
            case 2:
            case 7:
                o->unkA = 2;
                o->velV = -0x180;
                o->velY = 0xc;
                o->unk8C = -0x10;
                o->unk84 = 4;
                break;
            case 3:
                o->unkA = 2;
                o->velV = -0x200;
                o->velY = 0x10;
                o->unk8C = -0x18;
                o->unk84 = 6;
                break;
            case 4:
                o->unkA = 2;
                o->velV = -0x80;
                o->unk8C = -0x10;
                o->unk84 = 4;
                break;
            case 5:
                o->unkA = 2;
                o->velV = -0x80;
                o->velH = -0x80;
                o->unk8C = 0;
                break;
            case 6:
                o->unkA = 2;
                o->velV = -0x80;
                o->velH = 0x80;
                o->unk8C = 0;
                break;
            }
            break;
        case 2:
            c = allocObjectLayer3();
            if (c) {
                c->active = 1;
                c->type = 0xc;
                c->subtype = 3;
                c->unkAC = (D_1F8001F8 + D_1F800198) & 1;
                c->unkC = o->timer + 7;
                *c->h = *o->h;
                c->y = o->y;
                *c->d = *o->d;
            }
            goto dec;
        case 3:
            o->state++;
            o->timer = 0x3c;
            *(s8 *)&o->unkF = -12;
            o->unkD = 0;
            o->tpage = 8;
            o->anim = D_8013D8FC[o->unkAC];
            o->spriteBank = D_1F8002D4_S32Arr[0];
            o->unkA = 2;
            o->unk8C = (nextRandom() & 3) << 4;
            if (!((o->unkC - 8) & 1))
                o->animFrame = 1;
            else
                o->animFrame = 0;
            o->velH = D_80113DE8[nextRandom() & 7];
            v = D_80113DF8[nextRandom() & 7];
            o->velY = 0x10;
            o->velV = v;
            break;
        }
        break;
    case 1:
        if (func_80022E44(o) == 0)
            goto set3;
        switch (o->unkC) {
        case 0:
            o->velV += o->velY;
            o->y.raw += o->velV << 8;
            o->d->p.whole -= 2;
            break;
        case 1:
            o->velV += o->velY;
            o->y.raw += o->velV << 8;
            o->d->p.whole += 2;
            break;
        case 2:
        case 7:
            o->velV += o->velY;
            o->y.raw += o->velV << 8;
            o->unk8C += o->unk84;
            if (!((u32)(o->unk8C + 0xf) < 0x1f))
                o->unk84 = -o->unk84;
            break;
        case 3:
            o->velV += o->velY;
            o->y.raw += o->velV << 8;
            o->unk8C += o->unk84;
            if (!((u32)(o->unk8C + 0xf) < 0x1f))
                o->unk84 = -o->unk84;
            break;
        case 4:
            o->y.raw += o->velV << 8;
            t = o->unk8C + o->unk84;
            o->unk8C = t;
            if ((u32)(t + 0xf) >= 0x1f)
                o->unk84 = -o->unk84;
            break;
        case 5:
            o->y.raw += o->velV << 8;
            o->h->raw += o->velH << 8;
            o->unk8C += 4;
            break;
        case 6:
            o->y.raw += o->velV << 8;
            o->h->raw += o->velH << 8;
            o->unk8C -= 4;
            break;
        default:
            if ((o->velV += o->velY) == 0)
                o->velY /= 2;
            o->y.raw += o->velV << 8;
            if (o->velV > 0) {
                o->h->raw += o->velH << 8;
                o->unk8C = (o->unk8C + 4) & 0xff;
            } else {
                o->h->raw += o->velH << 7;
                o->unk8C = (o->unk8C + 2) & 0xff;
            }
            break;
        }
    dec:
        if (--o->timer == 0) {
        set3:
            o->state = 3;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EA16C);
extern u8 D_8009C217;
extern u8 D_8009C41C;
extern u8 D_8009C272;
extern u8 D_8009BCC1;
extern void func_80113CB8(GameObject *, s32, s32, s32, s32);

void func_800EA16C(s16 x, s16 y, s16 z, u8 f)
{
    GameObject *o;
    s32 t;
    u16 *g = &(*(u16 *)&GAME);

    if (*g < 2 || *(s32 *)g == 9) {
        if (*g != 1 || !(D_8009C62B & 1)) {
            o = allocObjectLayer3();
            if (o) {
                o->active = 1;
                o->type = 0xc;
                o->subtype = 0;
                o->h->raw = x << 16;
                o->y.raw = y << 16;
                o->d->raw = z << 16;
                o->timer = 4;
                o->cooldownTimer = nextRandom() & 0xf;
            }
        }
        if (f == 0 && D_8009BC9B == 0 && (*(u16 *)&GAME) == 1 && D_8009BCCA < 2) {
            t = D_8009C217;
            if (D_8009C41C + t >= 0x1e) return;
            t = 0x19 - D_8009C272;
            if (t > 0 && D_8009BCC1 < t && (nextRandom() & 0xf) == 0)
                func_80113CB8(o, 0, x, y, z);
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EA35C);
typedef struct Q_EA35C {
    u8 b0, b1, b2, b3;
    char pad4[0x10];
    s32 w14;
    char pad5[8];
    s16 s20;
    char pad6[0x40 - 0x22];
    s32 *p40;
    s32 *p44;
} Q_EA35C;

void func_800EA35C(s32 a, s32 b, s32 c)
{
    Q_EA35C *q;
    if ((*(u16 *)&GAME) == 1 && D_8009BCCA < 2 && (D_8009C62B & 1) == 0 && (q = allocObjectLayer3()) != 0) {
        q->b0 = 1;
        q->b2 = 0xc;
        q->b3 = 2;
        *q->p40 = a << 16;
        q->w14 = b << 16;
        *q->p44 = c << 16;
        q->s20 = 8;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EA428);
extern s32 D_1F8002D0;
extern u8 D_80113E08[];
extern u8 D_80113E10[];
extern void **D_80113E18[];
extern void playSFX(s32);
extern s32 tickAnimation(GameObject *);
extern void applyAnimVelocityX(GameObject *, u16);

void func_800EA428(GameObject *o)
{
    s32 a, v;
    switch (o->state) {
    case 0:
        o->state = o->state + 1;
        v = D_1F8002D0;
        o->tpage = 1;
        *(s8 *)&o->unkF = -30;
        o->unkA = 0;
        o->movetab = ((char *)&D_800771FC);
        o->spriteBank = v;
        if (o->subtype == 0) {
            a = 0x10;
            o->unkC = D_80113E08[(*(u16 *)&GAME)];
            o->timer = 0x5a;
        } else {
            a = 0x27;
            o->unkC = D_80113E10[(*(u16 *)&GAME)];
        }
        playSFX(a);
        o->anim = D_80113E18[(*(u16 *)&GAME)][o->unkC];
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->subtype == 0) {
            if (tickAnimation(o) != 0)
                o->state = 3;
            applyAnimVelocityX(o, 1 - o->animFrame);
            o->timer = o->timer - 1;
            if (o->timer == -1)
                o->state = 3;
        } else {
            if (tickAnimation(o) != 0)
                o->state = 3;
        }
        if (func_80022E44(o) == 0)
            o->state = 3;
        break;
    case 2:
        o->state = o->state + 1;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EA5FC);
void func_800EA5FC(char *o)
{
    switch (*(u8 *)((u8 *)o + 3)) {
    case 0:
        switch (*(u8 *)((u8 *)o + 6)) {
        case 0:
            (*(u8 *)((u8 *)o + 6))++;
            break;
        case 1:
            tickAnimation(o);
            break;
        }
        break;
    case 1:
        switch (*(u8 *)((u8 *)o + 6)) {
        case 0:
            playSFXWithNote(0xe, 4);
            (*(u8 *)((u8 *)o + 6))++;
            break;
        case 1:
            if (tickAnimation(o)) *(u8 *)((u8 *)o + 4) = 2;
            break;
        }
        break;
    case 2:
        switch (*(u8 *)((u8 *)o + 6)) {
        case 0:
            playSFXWithNote(0xe, 0);
            (*(u8 *)((u8 *)o + 6))++;
            break;
        case 1:
            if (tickAnimation(o)) *(u8 *)((u8 *)o + 4) = 2;
            break;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EA6F4);
void func_800EA6F4(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        if (o->visible) {
            switch (o->subtype) {
            case 0:
                switch (o->step) {
                case 0:
                    o->step++;
                    break;
                case 1:
                    tickAnimation(o);
                    break;
                }
                break;
            case 1:
                switch (o->step) {
                case 0:
                    playSFXWithNote(0xe, 4);
                    o->step++;
                    break;
                case 1:
                    if (tickAnimation(o))
                        o->state = 2;
                    break;
                }
                break;
            case 2:
                switch (o->step) {
                case 0:
                    playSFXWithNote(0xe, 0);
                    o->step++;
                    break;
                case 1:
                    if (tickAnimation(o))
                        o->state = 2;
                    break;
                }
                break;
            }
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EA86C);
typedef struct { char p[0x1e]; u16 w1e; } NN_EA86C;
typedef struct { u16 w; s16 idx; void **ptrs; s32 pad; } E_EA86C;
extern E_EA86C D_80113E34[];
extern u16 GAME_U16Arr[] asm("GAME");
extern u8 D_800A53A7;

void func_800EA86C(s16 a, s32 x, s32 y, s32 z)
{
    char *n;
    n = allocObjectLayer3();
    if (n != 0) {
        n[0] = 1;
        n[2] = 0x1b;
        *(s32 *)(n + 0x10) = x << 16;
        *(s32 *)(n + 0x14) = y << 16;
        n[3] = a;
        *(s32 *)(n + 0x18) = z << 16;
        ((NN_EA86C *)n)->w1e = D_80113E34[GAME_U16Arr[0]].w;
        *(s32 *)(n + 0x3c) = SPR_DATA[D_80113E34[GAME_U16Arr[0]].idx];
        if (a == 2 && *(s32 *)GAME_U16Arr == 0x50000) a = 3;
        *(void **)(n + 0x24) = D_80113E34[GAME_U16Arr[0]].ptrs[a];
        readAnimFrameCount(n);
        n[0xd] = 0;
        n[0xa] = 2;
        n[0x68] = 0;
        n[0x1c] |= 0x80;
        n[0xf] = D_800A53A7 - 1;
        if (a == 0) D_800A547C = n;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EAA0C);
extern u16 D_80113F2C[];
extern void **D_80114D58[];
extern void **D_80114C98[];

void func_800EAA0C(GameObject *o)
{
    u16 *p;
    u16 *g;

    switch (o->state) {
    case 0:
        o->state++;
        o->timer = 0x3c;
        o->movetab = &D_800771FC;
        p = &D_80113F2C[o->subtype * 4];
        o->unk8C = 0;
        o->unkD = 0;
        o->animFrame = 0;
        o->cooldownTimer = *p++;
        o->objectIndex = *p++;
        g = &GAME;
        if (*(s32 *)g == 0x30009)
            o->anim = D_80114D58[o->unkC][o->objectIndex];
        else
            o->anim = D_80114C98[*g * 4 + o->unkC][o->objectIndex];
        o->velV = *p;
        readAnimFrameCount(o);
        break;
    case 1:
        o->velV += 0x28;
        if (o->velV > 0x400)
            o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->cooldownTimer & 1)
            o->unk8C = (o->unk8C + 8) & 0xff;
        else
            o->unk8C = (o->unk8C - 8) & 0xff;
        applyAnimVelocityX(o, (u16)o->cooldownTimer);
        if (o->timer >= 0x1e || ((D_1F8001F8 + D_1F800198) & 1))
            func_80022E44(o);
        if (--o->timer == -1)
            o->state = 2;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EAC50);
typedef struct N_EAC50 {
    u8 b0, b1, b2, b3;
    char pad4[6];
    u8 ba;
    char padb;
    u8 bc;
    char padd[2];
    u8 bf;
    s32 x, y, z;
    char pad1c[2];
    s16 h1e;
    char pad20[0x1c];
    s32 w3c;
} N_EAC50;
extern s16 D_80113F58[];
extern N_EAC50 *allocObjectLayer3(void);

void func_800EAC50(N_EAC50 *o, s16 x, s16 y, s16 z)
{
    s16 *p;
    s32 i;
    N_EAC50 *n;

    p = D_80113F58;
    i = 0;
    do {
        n = allocObjectLayer3();
        if (n != 0) {
            n->b0 = 1;
            n->b2 = 0x1e;
            n->bc = o->bc & 0x7f;
            n->x = (x + *p++) << 16;
            n->y = (y + *p++) << 16;
            n->z = z << 16;
            n->h1e = o->h1e;
            n->ba = 2;
            n->b3 = i;
            n->w3c = o->w3c;
            n->bf = o->bf;
        }
        i++;
    } while (i < 5);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EAD50);
void func_800EAD50(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0x14;
        *(s8 *)&o->unkF = -0x14;
        o->animFrame = 1;
        o->unkD = 0;
        o->spriteBank = D_1F8002D8[0];
        o->anim = ((void **)&D_800122B0)[o->unkC];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        switch (o->subState) {
        case 0:
            o->timer = 0x1e;
            o->subState++;
            break;
        case 1:
            if ((D_1F8001F8 >> 2) & 1)
                func_80022E44(o);
            if (--o->timer == -1)
                o->state = 3;
            break;
        }
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EAEA8);
void func_800EAEA8(GameObject *o)
{
    GameObject *a = (GameObject *)o->unk90;
    GameObject *b = (GameObject *)o->unk94;
    s32 s;
    switch (o->state) {
    case 0:
        if ((a->active != 0 && a->state == 1) || a->state == 2) {
            b->x.p.whole = a->x.p.whole;
            b->y.p.whole = a->y.p.whole;
            b->z.p.whole = a->z.p.whole;
            s = a->step;
            if (s < 7) if (s > 1) {
                if (b->active != 0) return;
                if (b->state == 1) return;
                goto L;
            }
        }
        if (b->active != 0 && b->state == 1) {
            b->unk68 = 1;
            b->animFrame = 2;
        }
    L:
        o->state = o->state + 1;
        break;
    case 1:
        ((void (*)(void))freeObjectLayer3)();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EAFC4);
extern u16 D_800A53C6;
extern s32 SPR_DATA[];
extern char D_80113F70[];
extern char D_80113F74[];
extern void readAnimFrameCount(GameObject *);

void func_800EAFC4(GameObject *o)
{
    u16 u;
    o->tpage = 0x13;
    o->spriteBank = SPR_DATA[*(s16 *)(D_80113F70 + o->subtype * 12)];
    o->anim = *(void **)(*(s32 *)(D_80113F74 + o->subtype * 12) + o->unkC * 4);
    readAnimFrameCount(o);
    u = D_800A53C6;
    o->unkA = 2;
    o->unkD = 0x80;
    *(s8 *)&o->unkF = -7;
    o->unk8C = 0;
    o->objectIndex = 0;
    o->animFrame = u & 1;
    o->category |= 0x80;
    o->state++;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EB0A0);
typedef struct T12_EB0A0 { void **p; s32 a, b; } T12_EB0A0;

void func_800EB0A0(GameObject *o)
{
    extern u8 D_800A5399[];
    s32 dx;
    s16 dy;
    s32 w;
    Fix16 *hp;
    GameObject *q;
    switch (o->step) {
    case 0:
        o->anim = *((T12_EB0A0 *)&D_80113F74)[o->subtype].p;
        readAnimFrameCount(o);
        o->visible = D_800A5399[0];
        o->unkF = D_800A53A7 - 1;
        o->step++;
    case 1:
        q = (GameObject *)o->unk90;
        switch (D_800A53C6) {
        case 0:
        case 1:
        case 2:
        case 3:
            dx = -0x16;
            dy = -4;
            break;
        case 4:
        case 5:
            dx = -0x18;
            dy = 0;
            break;
        case 6:
        case 7:
            dx = -0x16;
            dy = 6;
            break;
        }
        tickAnimation(o);
        o->animFrame = ((volatile u16 *)&D_800A53C6)[0] & 1;
        w = (*(Fix16 **)&D_800A53D8)->p.whole;
        hp = o->h;
        if (((volatile u16 *)&D_800A53C6)[0] & 1) hp->p.whole = w - (dx << 16 >> 16); else hp->p.whole = w + (dx << 16 >> 16);
        o->y.p.whole = D_800A53AE[0] + dy;
        o->d->p.whole = (*(Fix16 **)&D_800A53DC)->p.whole;
        switch (o->subtype) {
        case 0:
            if (q->step == 7)
                break;
            if (q->step == 8) {
                o->animTimer = 1;
                break;
            }
            o->state = 2;
            break;
        case 1 ... 2:
            if (q->step == 6)
                break;
            if (q->step == 7) {
                o->animTimer = 1;
                break;
            }
            o->state = 2;
            break;
        }
        if (q->subState >= 2)
            o->state = 2;
        if (q->state != 1)
            o->state = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EB2C8);
typedef struct T12_EB2C8 { void **p; s32 a, b; } T12_EB2C8;
extern u8 D_800A5399;
extern u8 D_800A53A7_U8Arr[] asm("D_800A53A7");
#define DAT_800a6047 D_800A53A7_U8Arr[0]
extern s32 fixedMulSin2(s16, s16);
extern s32 fixedMulSin(s16, s16);
extern s32 fixedMulCos(s16, s16);

void func_800EB2C8(GameObject *o)
{
    extern void func_800EB954(GameObject *o, s32 a, s32 b, s32 c);
    GameObject *q;
    s16 d;
    s32 r;
    s16 c;
    s32 b;
    s32 v;
    s32 x;
    s16 a;

    switch (o->step) {
    case 0:
        o->anim = *((T12_EB2C8 *)&D_80113F74)[o->subtype].p;
        readAnimFrameCount(o);
        o->visible = D_800A5399;
        o->unkF = DAT_800a6047 - 1;
        {
            s16 t = 8;
            if (o->unkC & 2) t = 4;
            q = (GameObject *)o->unk90;
            o->velX = t;
        }
        o->velY = 0;
        switch (q->animFrame) {
        case 0:
        case 2:
            o->unk74 = 0;
            break;
        case 1:
        case 3:
            o->unk74 = 0x7f;
            break;
        case 4:
            o->unk74 = 0x20;
            break;
        case 5:
            o->unk74 = 0x60;
            break;
        case 6:
        case 7:
            o->unk74 = 0x40;
            break;
        }
        o->step++;
    case 1:
        tickAnimation(o);
        q = (GameObject *)o->unk90;
        switch (q->step) {
        case 0:
            o->state = 2;
        case 1:
            o->visible = 0;
            break;
        case 2:
        case 3:
        case 4:
            o->visible = 0;
            o->unkF = DAT_800a6047 - 1;
            a = q->unkAA - o->unk74;
            if (a != 0) {
                if ((u16)a < 0x80)
                    o->unk74 = (o->unk74 + 0x10) & 0xff;
                else
                    o->unk74 = (o->unk74 - 0x10) & 0xff;
            }
            r = 8;
            a = (o->unk74 + 0x80) & 0xff;
            if (o->unkC & 2) r = 4;
            o->velH = fixedMulCos2(a, r);
            o->velV = fixedMulSin2(a, r);
            a = (o->unkC & 1 ? o->unk74 + 0x40 : o->unk74 + 0xc0) & 0xff;
            r = fixedMulSin(o->velY, o->velX);
            o->velY = (o->velY + 0x10) & 0xff;
            x = fixedMulCos2(a, r);
            v = fixedMulSin2(a, r);
            o->h->p.whole = x + (q->h->p.whole + o->velH);
            o->y.p.whole = v + (q->y.p.whole + o->velV);
            o->d->p.whole = q->d->p.whole;
            o->animTimer = 6;
            func_800EB954(o, 0, 0, 0);
            if (q->unkA8 < 0x600) {
                o->animTimer = 6;
                if (nextRandom() & 1)
                    func_800EB954(o, 4, 4, 0);
                else
                    func_800EB954(o, -4, -4, 0);
            }
            break;
        case 7:
        case 8:
            c = (o->unk76 + 0x10) & 0xff;
            o->visible = D_800A5399;
            o->unkF = DAT_800a6047 - 1;
            o->unk76 = c;
            if (o->unkC & 1) {
                v = fixedMulCos(c, 8);
                o->h->p.whole = q->h->p.whole + v;
                v = fixedMulSin(c, 0x10);
                o->y.p.whole = q->y.p.whole + v;
                v = fixedMulSin(c, 8);
                o->d->p.whole = q->d->p.whole + v;
            } else {
                v = fixedMulCos(c, 8);
                o->h->p.whole = q->h->p.whole + v;
                v = fixedMulSin((c + 0x80) & 0xff, 0x10);
                o->y.p.whole = q->y.p.whole + v;
                v = fixedMulSin(c, 8);
                o->d->p.whole = q->d->p.whole + v;
            }
            break;
        }
        switch (q->subState) {
        case 0 ... 6:
            break;
        default:
            o->state = 2;
        }
        if (q->state != 1)
            o->state = 2;
        break;
    }
}
#undef DAT_800a6047

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EB6D8);
extern u8 D_800A5399;
extern u8 D_800A53A7;

void func_800EB6D8(GameObject *o)
{
    ((void (*)(void))func_80022E44)();
    switch (o->subtype) {
    case 0:
    case 1:
    case 2:
        func_800EB0A0(o);
        break;
    case 3:
    case 4:
        func_800EB2C8(o);
        break;
    case 9:
        o->visible = D_800A5399;
        o->unkF = D_800A53A7 - 1;
        if (tickAnimation(o) != 0) {
            o->state = 3;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EB780);
typedef struct { s16 k; s16 pad; void **anims; s32 pad2; } T12_EB780;
extern T12_EB780 D_80113F70_T12_EB780Arr[] asm("D_80113F70");
typedef struct G_EB780 { char p0; u8 b1; char p1[0xf - 2]; u8 b0f; } G_EB780;

void func_800EB780(GameObject *o)
{
    u8 s = o->state;
    u16 v;
    switch (s) {
    case 0:
        if (o->subtype == 9)
            goto inc;
        o->tpage = 0x13;
        o->spriteBank = SPR_DATA[D_80113F70_T12_EB780Arr[o->subtype].k];
        o->anim = D_80113F70_T12_EB780Arr[o->subtype].anims[o->unkC];
        readAnimFrameCount(o);
        v = D_800A53C6;
        o->unkA = 2;
        o->unkD = 0x80;
        *(s8 *)&o->unkF = -7;
        o->unk8C = 0;
        o->objectIndex = 0;
        o->animFrame = v & 1;
        o->category |= 0x80;
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
        case 1:
        case 2:
            func_800EB0A0(o);
            break;
        case 3:
        case 4:
            func_800EB2C8(o);
            break;
        case 9:
            o->visible = (*(G_EB780 *)&PLAYER).b1;
            o->unkF = (*(G_EB780 *)&PLAYER).b0f - 1;
            if (tickAnimation(o) != 0)
                o->state = 3;
            break;
        }
        break;
    case 2:
    inc:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EB954);
void func_800EB954(char *o, s32 a, s32 b, s32 c)
{
    char *p = allocObjectLayer3();
    if (p != 0) {
        *p = 1;
        p[2] = 0x5c;
        p[3] = 9;
        *(s32 *)(p + 0x10) = *(s32 *)(o + 0x10);
        *(s32 *)(p + 0x14) = *(s32 *)(o + 0x14);
        *(s32 *)(p + 0x18) = *(s32 *)(o + 0x18);
        *(s16 *)(*(char **)(p + 0x40) + 2) += a;
        *(s16 *)(p + 0x16) += b;
        *(s16 *)(*(char **)(p + 0x44) + 2) += c;
        *(s16 *)(p + 0x1e) = *(s16 *)(o + 0x1e);
        *(s32 *)(p + 0x3c) = *(s32 *)(o + 0x3c);
        *(s32 *)(p + 0x24) = *(s32 *)(o + 0x24);
        *(s16 *)(p + 0x2c) = *(s16 *)(o + 0x2c);
        {
            u16 u = *(u16 *)(o + 0x2e);
            p[10] = 2;
            p[0xd] = 0x80;
            *(s32 *)(p + 0x8c) = 0;
            p[0x6b] = 0;
            *(s8 *)(p + 0xf) = -7;
            *(u16 *)(p + 0x2e) = u;
            p[0x1c] |= 0x80;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EBA70);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EBBAC);
void func_800EBBAC(s32 type)
{
    GameObject *o;
    s32 i;
    u8 r, g, b;

    switch (type) {
    case 0:
        r = 0xff;
        g = 0x30;
        b = 0x30;
        break;
    case 1:
        r = 0x30;
        g = 0x30;
        b = 0xff;
        break;
    case 2:
        r = 0x30;
        g = 0xff;
        b = 0x30;
        break;
    }
    for (i = 0; i < 8; i++) {
        o = allocObjectLayer3();
        if (o) {
            o->type = 0x5f;
            o->unkA = 0x13;
            o->timer = 0x5a;
            o->active = 1;
            o->subtype = type;
            o->unkC = i;
            o->objectIndex = 0;
            o->unkA5 = 0xc;
            o->animFrame = i << 5;
            o->unk84 = 0xb0;
            switch (D_1F8001C8 & 1) {
            case 0:
                o->unk88 = ((o->animFrame - 0x40) & 0xff) << 4;
                break;
            case 1:
                o->unk88 = ((o->animFrame - 0x80) & 0xff) << 4;
                break;
            }
            o->unk30 = r;
            o->unk34 = g;
            o->unk8C = 0;
            o->unk38 = b;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EBD20);
typedef struct { s16 vx, vy, vz, pad; } SVec_EBD20;
extern u16 D_1F80016E;

void func_800EBD20(GameObject *o)
{
    SVec_EBD20 *p = &((SVec_EBD20 *)((u8 *)o + 0xb4))[0];
    SVec_EBD20 *q = &((SVec_EBD20 *)((u8 *)o + 0xb4))[1];
    s16 t;
    s32 k;
    switch (o->state) {
    case 0:
        o->state++;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[0]).vx = -4;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[0]).vy = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[0]).vz = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[1]).vx = 4;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[1]).vy = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[1]).vz = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[2]).vx = -4;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[2]).vy = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[2]).vz = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[3]).vx = 4;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[3]).vy = 0;
        (((SVec_EBD20 *)((u8 *)o + 0xb4))[3]).vz = 0;
        break;
    case 1:
        switch (D_1F8001C8 & 1) {
        case 0:
            o->animFrame = (o->animFrame + 3) & 0xff;
            o->unk88 = ((o->animFrame - 0x40) & 0xff) << 4;
            k = (D_8007D988[(u8)o->animFrame] * 3 >> 11) - 0x10;
            o->y.p.whole = D_1F80016E - k;
            break;
        case 1:
            o->animFrame = (o->animFrame - 3) & 0xff;
            o->unk88 = ((o->animFrame - 0x80) & 0xff) << 4;
            k = (D_8007D988[(u8)o->animFrame] * 3 >> 11) + 0x10;
            o->y.p.whole = D_1F80016E + k;
            break;
        }
        o->h->p.whole = (*(u16 *)&D_1F80016A) + (D_8007DB88[(u8)o->animFrame] * *(s8 *)&o->unkA5 >> 12);
        o->d->p.whole = (*(u16 *)&D_1F800172) + (D_8007D988[(u8)o->animFrame] * *(s8 *)&o->unkA5 >> 12);
        o->unkF = D_800A53A7 - 1;
        t = o->timer;
        if (t >= 0x32) {
            if (t % 7 == 0)
                o->unkA5++;
            p->vy -= 2;
            q->vy -= 2;
        } else {
            switch (o->subtype) {
            case 0:
                o->unk30 -= 6;
                o->unk34 -= 1;
                o->unk38 -= 1;
                break;
            case 1:
                o->unk30 -= 1;
                o->unk34 -= 1;
                o->unk38 -= 6;
                break;
            case 2:
                o->unk30 -= 1;
                o->unk34 -= 6;
                o->unk38 -= 1;
                break;
            }
            if (o->unk30 < 0)
                o->unk30 = 0;
            if (o->unk34 < 0)
                o->unk34 = 0;
            if (o->unk38 < 0)
                o->unk38 = 0;
        }
        func_80022E44(o);
        if (--o->timer == -1)
            o->state = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EC0E8);
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");
extern void getBaseMatrix(MATRIX *);
extern s32 insertPrimWithBias(void *, s32, s32, s32, u32);

#define gte_ldv3(r0, r1, r2) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 0( %1 );lwc2 $3, 4( %1 );lwc2 $4, 0( %2 );lwc2 $5, 4( %2 )" : : "r"(r0), "r"(r1), "r"(r2))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")

void func_800EC0E8(GameObject *o)
{
    s32 m;
    char *vb4;
    char *vbc;
    char *vc4;
    char *vcc;
    u8 *p;
    u8 *q;

    getBaseMatrix(&D_1F800020);
    RotMatrixZ(o->unk8C, &D_1F800020);
    RotMatrixX(o->unk84, &D_1F800020);
    RotMatrixY(o->unk88, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(&(*(MATRIX *)&D_1F8000C0), &D_1F800020, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800068, (*(MATRIX *)&SCRATCHPAD).t);
    (*(MATRIX *)&SCRATCHPAD).t[0] += (*(MATRIX *)&D_1F8000C0).t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += (*(MATRIX *)&D_1F8000C0).t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += (*(MATRIX *)&D_1F8000C0).t[2];
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    p = (u8 *)D_1F800164;
    p[7] = 0x3b;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[0xc] = 0;
    p[0xd] = 0;
    p[0xe] = 0;
    vb4 = (char *)o + 0xb4;
    vbc = (char *)o + 0xbc;
    vcc = (char *)o + 0xcc;
    vc4 = (char *)o + 0xc4;
    p[0x14] = p[0x1c] = o->unk30;
    p[0x15] = p[0x1d] = o->unk34;
    p[0x16] = p[0x1e] = o->unk38;
    gte_ldv3(vb4, vbc, vc4);
    gte_rtpt();
    gte_stsxy3_g4(p);
    gte_ldv0(vcc);
    gte_rtps();
    gte_avsz4();
    gte_stotz(&LZ_FILE_CTRL_Long);
    gte_stsxy(p + 0x20);
    insertPrimWithBias(p, D_1F8001E0 + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x8000000);
    D_1F800164 += 0x24;
    q = (u8 *)D_1F800164;
    if (GetGraphType() == 1) m = 0x80;
    else if (GetGraphType() == 2) m = 0x80;
    else m = 0x20;
    SetDrawMode(q, 0, 0, m, 0);
    AddPrim((s32 *)D_1F8001E0 + (LZ_FILE_CTRL_Long + 4) + (s8)o->unkF, q);
    D_1F800164 += 0xc;
}
#undef gte_ldv3
#undef gte_rtpt
#undef gte_stsxy3_g4
#undef gte_ldv0
#undef gte_rtps
#undef gte_avsz4
#undef gte_stotz
#undef gte_stsxy

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EC384);
extern void freeObjectLayer4(GameObject *);
extern u32 D_8009BCE0[];
extern void (*D_80113FA8[])(GameObject *);

void func_800EC384(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->hitOffsetX = 0x15;
        o->unkA4 = 0;
        o->hitWidth = 0x2a;
        o->unk68 = 0;
        o->touchFlag = 0;
        o->subState = 0;
        o->step = 0;
        o->state++;
        o->hitOffsetY = 0x36;
        o->hitHeight = 0x36;
        o->tpage = o->objectIndex;
        switch ((*(s16 *)&D_1F8001C8)) {
        case 0:
            o->unkA7 = 0x10;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            break;
        case 1:
            o->unkA7 = 0x11;
            o->unk84 = 0;
            o->unk88 = -0x400;
            o->unk8C = 0;
            break;
        case 2:
            o->unkA7 = 0x11;
            o->unk84 = 0;
            o->unk88 = 0x800;
            o->unk8C = 0;
            break;
        case 3:
            o->unkA7 = 0x11;
            o->unk84 = 0;
            o->unk88 = 0x400;
            o->unk8C = 0;
            break;
        }
        o->unkF = 0;
        o->unkA = o->unkA7;
        if (o->subtype < 32 ? (D_8009BCE0[0] & (1 << o->subtype)) : (D_8009BCE0[1] & (1 << (o->subtype - 32)))) {
            o->unkE = 1;
            o->unkD = 0x20;
        } else {
            o->unkE = 0;
        }
        o->unk98 = 0;
        break;
    case 1:
        if (func_80022E44(o) && o->step == 0) {
            if (o->touchFlag != 0) o->subState = 1;
            else if (o->unk68 != 0) o->subState = 2;
        }
        if (o->subState != 0) D_80113FA8[o->subState](o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800EC5B8);
typedef struct {
    u8 active, visible, type, subtype, b04, step, state, substep;
    char p08[2];
    u8 b0a, b0b, b0c, b0d, b0e, b0f;
    s16 ax, aw, yx, yw, bx, bw;
    char p1c[4];
    s16 timer, w22;
    char p24[0x30 - 0x24];
    s32 d30;
    char p34[0x68 - 0x34];
    u8 b68, b69, b6a, b6b;
    s16 box0, box1, box2, box3;
    char p74[0x7e - 0x74];
    s16 velY, velH, velV;
    char p84[0xa0 - 0x84];
    s32 da0;
    char pa4[3];
    u8 ba7;
    s32 da8;
    s16 wac;
    char pae[0xb4 - 0xae];
    s32 db4;
    s32 db8;
    s32 dbc;
    char pc0[0xcc - 0xc0];
    s16 wcc;
} S_EC5B8;
typedef struct { s32 d0; s32 b8; s32 bc; char p0c[0xc]; s16 wcc; } E_EC5B8;
extern s16 D_800A53AE_S16 asm("D_800A53AE");
extern s32 DAT_8009c978;
extern s32 DAT_8009c97c;
extern u8 D_8009C3E1;
extern s32 *D_80113FB4[];
extern char D_800E3188[];
extern void queueSfxKeyOff(s32);
extern void spawnLayer3Object(s32, s32, s32, s32);
extern void setEventComplete(s32, s32);

void func_800EC5B8(S_EC5B8 *o)
{
    extern void subtractScaledVertices(s32, s32, s32);
    extern void func_80028638(s32, s32);
    E_EC5B8 *e;
    s32 *p;
    s16 v, t, n;
    u32 k;
    u16 w;
    s16 r;
    u8 c;

    if (D_8009BCA6 != 0)
        return;
    e = (E_EC5B8 *)&o->db4;
    switch (o->state) {
    case 0:
        o->timer = 0;
        o->w22 = 0;
        o->velV = 0;
        o->velY = 0x4b0;
        p = D_80113FB4[o->b0c];
        p = (s32 *)(*p + ((s32 *)*(s32 *volatile *)p)[1]);
        e->bc = (s32)p;
        e->b8 = (s32)(D_800E3188 + o->b0c * 0x1600);
        o->da8 = e->b8;
        func_80028638(o->da0, e->b8);
        o->state = 1;
        o->b69 = 0;
        o->b0a = 0x12;
        break;
    case 1:
        if (o->visible == 0)
            goto set4;
        if (o->velV < 0x1000) {
            func_80028638(o->da0, e->b8);
            r = o->velV;
            w = r;
            if (r < 0x1000) {
                e->wcc = w;
                if (o->timer == 0)
                    o->wac = ((s16 (*)(s32))playSFX)(0x17);
            } else {
                e->wcc = 0x1000;
            }
            t = (e->wcc * 9 >> 10) - 0x36;
            if ((o->b69 & 1) && D_800A5434 == 0)
                D_800A53AE_S16 += t + o->box2;
            o->box2 = -t;
            o->box3 = -t;
            subtractScaledVertices(e->b8, e->bc, e->wcc);
            o->timer++;
            o->velV += o->velY / o->timer;
            if (o->subtype == 0 && *(s16 *)((char *)o + 0x20) == 4)
                spawnLayer3Object(6, o->aw, (s16)(o->yw - 10), o->bw);
        } else {
            o->state = 2;
            o->b6b = 0;
            if (o->b0e != 1 && (o->b69 & 1)) {
                k = o->subtype;
                o->b0e = 1;
                o->b0d = 0x20;
                if (k < 0x20)
                    D_8009BCE0[0] |= 1 << k;
                else
                    D_8009BCE0[1] |= 1 << (k - 0x20);
                c = *(volatile u8 *)&D_8009C3E1 + 1;
                *(volatile u8 *)&D_8009C3E1 = c;
                if (c == 0x18)
                    setEventComplete(0x3f, 0);
            }
        }
        if (o->b69 == 0) {
            o->state = 3;
            o->w22 = 0;
            o->d30 = o->timer;
            queueSfxKeyOff(o->wac);
            o->wac = ((s16 (*)(s32))playSFX)(0x1b);
            break;
        }
        o->b69 = 0;
        break;
    case 2:
        if (o->b6b < 5) {
            o->b6b++;
            break;
        }
        if (o->b69 == 0) {
            o->state = 3;
            o->w22 = 0;
            o->wac = ((s16 (*)(s32))playSFX)(0x1b);
            break;
        }
        o->b69 = 0;
        o->b6b = 0;
        break;
    case 3:
        if (o->visible == 0) {
        set4:
            o->state = 4;
            break;
        }
        func_80028638(o->da0, e->b8);
        v = o->velV;
        if (o->velV < 0)
            v = 0;
        e->wcc = v;
        t = (v * 9 >> 10) - 0x36;
        o->box2 = -t;
        o->box3 = -t;
        subtractScaledVertices(e->b8, e->bc, e->wcc);
        if (o->velV > 0) {
            o->w22++;
            if (o->timer > 2)
                n = o->timer - 2;
            else
                n = 0;
            o->velV -= o->velY / (o->w22 + 1);
            o->timer = n;
        } else {
            o->state = 4;
        }
        if (o->b69 != 0) {
            o->state = 1;
            o->b69 = 0;
            queueSfxKeyOff(o->wac);
        }
        break;
    case 4:
        o->box2 = 0x36;
        o->box3 = 0x36;
        o->step = 0;
        o->state = 0;
        o->b68 = 0;
        o->b0a = o->ba7;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800ECAB0);
typedef struct { s16 spd[2]; s16 pos[2]; s16 cnt[2]; } B_ECAB0;
typedef struct { s32 n; char *b8; s32 tab[4]; s16 val[2]; } E_ECAB0;
extern s32 **D_80113FC0[];
extern char D_80113FCC[];
extern char D_800E3188[];
extern void func_80028638(s32, char *);
extern void subtractScaledVertices(char *, s32, s32);
extern void applyItemEffect(void *d, void *arg, s16 x, s16 y, s32 flag);

#define INIT(o, b)                       \
    if (o->animFrame == 0) {             \
        o->timer = -10;                  \
        o->cooldownTimer = 0;                      \
    } else if (o->animFrame == 1) {      \
        o->timer = 0;                    \
        o->cooldownTimer = -10;                    \
    }                                    \
    b->pos[0] = 0x800;                   \
    b->pos[1] = 0x800;                   \
    b->spd[0] = 0x200;                   \
    b->spd[1] = 0x200;                   \
    b->cnt[0] = 1;                       \
    b->cnt[1] = 1;

void func_800ECAB0(GameObject *o)
{
    E_ECAB0 *e = (E_ECAB0 *)&o->unkB4;
    B_ECAB0 *b = (B_ECAB0 *)&o->unk48;
    s32 **pp;
    s32 *p;
    s16 i;
    s16 s;
    s32 a, lim;
    Fix16 pos[3];

    switch (o->step) {
    case 0:
        INIT(o, b);
        pp = D_80113FC0[o->unkC];
        p = *pp;
        e->n = *p++;
        for (i = 0; i < e->n; i++) {
            e->tab[i] = (s32)*pp + p[i];
        }
        e->b8 = D_800E3188 + o->unkC * 0x1600;
        *(char **)&o->unkA8 = e->b8;
        func_80028638(o->unkA0, e->b8);
        o->step = 1;
        if (o->unk68 == 2) o->unk98 = 1;
        o->unk68 = 0;
        o->unkA = 0x12;
        break;
    case 1:
        if (o->unk98 == 1) {
            s = 0x100;
            if (o->animFrame) s = -0x100;
            if (o->subtype == 8) s = s / 2;
            pos[0].p.whole = o->h->p.whole;
            pos[1].p.whole = o->y.p.whole - 0x50;
            pos[2].p.whole = o->d->p.whole;
            applyItemEffect(D_80113FCC + o->subtype * 6, pos, s, -0x200, 1);
            o->unk98 = 0;
        }
        if (o->visible == 0) goto set2;
        if (o->touchFlag) {
            o->step = 2;
        } else if (o->unk68) {
            o->unk68 = 0;
            INIT(o, b);
        }
        func_80028638(o->unkA0, e->b8);
        for (i = 0; i < e->n; i++) {
            if ((&o->timer)[i] >= 0) {
                if (b->cnt[i] < 4) {
                    e->val[i] = b->pos[i];
                    a = b->spd[i] / b->cnt[i];
                    b->pos[i] += a;
                    lim = 0x1000 / b->cnt[i];
                    if (lim < b->pos[i]) {
                        b->pos[i] = lim;
                        b->spd[i] *= -1;
                    } else if (b->pos[i] < 0) {
                        b->pos[i] = 0;
                        b->spd[i] *= -1;
                        b->cnt[i]++;
                    }
                }
            } else {
                e->val[i] = 0;
            }
            (&o->timer)[i]++;
            subtractScaledVertices(e->b8, e->tab[i], e->val[i]);
        }
        if (b->cnt[0] < 4) break;
        if (b->cnt[1] < 4) break;
    set2:
        o->step = 2;
        break;
    case 2:
        o->subState = 0;
        o->step = 0;
        o->unkA = o->unkA7;
        break;
    }
}
#undef INIT

void func_800ECF6C(void) {
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800ECF74);
extern u16 D_800A53C6_U16Arr[] asm("D_800A53C6");
extern u16 D_800A544E;
extern u8 D_800A5436[];

void func_800ECF74(GameObject *o)
{
    u32 ang;
    s16 v;

    switch (o->step) {
    case 0:
        o->velX = o->h->p.whole;
        o->velY = o->y.p.whole;
        o->velH = 1;
        o->unk74 = o->unk84;
        o->unk76 = o->unk88;
        o->unk84 = 0;
        o->unk88 = 0;
        if (D_800A53C6_U16Arr[0] & 1) o->step = 2;
        else o->step = 1;
        break;
    case 1:
        ang = D_800A544E;
        ang >>= 4;
        ang &= 0xff;
        o->unk84 = ((s16 (*)(s32, s32))fixedMulCos)(ang, o->velH) << 4;
        o->unk88 = ((s16 (*)(s32, s32))fixedMulSin)(ang, o->velH) << 4;
        if (D_800A5436[0] == 0) {
            o->active = 2;
            o->timer = 10;
            o->touchFlag = 0;
            o->step = 3;
            o->unk84 = o->unk74;
            o->unk88 = o->unk76;
        }
        break;
    case 2:
        ang = 0x100;
        ang -= (s16)D_800A544E >> 4;
        ang &= 0xff;
        o->unk84 = ((s16 (*)(s32, s32))fixedMulCos)(ang, o->velH) << 4;
        o->unk88 = ((s16 (*)(s32, s32))fixedMulSin)(ang, o->velH) << 4;
        if (D_800A5436[0] == 0) {
            o->active = 2;
            o->timer = 10;
            o->touchFlag = 0;
            o->step = 3;
            o->unk84 = o->unk74;
            o->unk88 = o->unk76;
        }
        break;
    case 3:
        if (--o->timer <= 0) {
            o->active = 1;
            o->timer = 0;
            o->touchFlag = 0;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
    switch ((*(s16 *)&D_800A544A)) {
    case 0: v = 1; break;
    case 1: v = 2; break;
    case 2: v = 3; break;
    default: v = 4; break;
    }
    o->velH = v;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine", func_800ED15C);
typedef struct O_ED15C {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    char p0[0x16 - 8]; u16 y;
    char p1[0x40 - 0x18]; u16 *h;
    char p2[0x69 - 0x44]; u8 b69;
    char p3[0x7a - 0x6a]; s16 s7a; u16 s7c; u16 s7e; s16 s80;
    char p4[0x84 - 0x82]; s32 d84; s32 d88; s32 d8c;
    char p5[0x94 - 0x90]; struct O_ED15C *p94;
} O_ED15C;
extern u8 D_800A5436[];

void func_800ED15C(O_ED15C *o)
{
    u16 v;
    s32 w;
    switch (o->b5) {
    case 0: {
        O_ED15C *p = o->p94;
        func_80022E44(p);
        o->b1 = p->b1;
        if (o->b6 == 0) o->b6++;
        if (o->b69 & 2) {
            p = o->p94;
            p->b5 = 1;
            p->b6 = 0;
            o->b5 = 1;
            o->b6 = 0;
        }
        break;
    }
    case 1: {
        O_ED15C *p = o->p94;
        func_80022E44(p);
        o->b1 = p->b1;
        switch (o->b6) {
        case 0:
            v = o->h[1];
            o->s80 = 0;
            w = o->y;
            o->s7e = w;
            o->d8c = 0x1000;
            o->b6++;
            o->s7c = v;
        case 1:
            if (D_800A53C6 & 1) o->s7a = 1;
            else o->s7a = -1;
            o->b6++;
        case 2:
            p = o->p94;
            o->d8c = ((p->d84 >> 3) + 0x1000) & 0xfff;
            if (D_800A5436[0] == 0) {
                o->d8c = 0;
                o->b69 = 0;
                o->b5 = 0;
                o->b6 = 0;
            }
            break;
        }
        break;
    }
    }
}
