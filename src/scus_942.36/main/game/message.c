#include "common.h"
#include "game.h"


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002E964);
extern void readAnimFrameCount(GameObject *);
extern void playSFX(s32);
extern void pushDrawListCapped(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void freeObjectLayer3(GameObject *);

void func_8002E964(GameObject *o)
{
    u8 s = o->state;
    s32 d;
    switch (s) {
    case 0:
        o->tpage = 0x15;
        if (o->subtype == 0 || o->subtype == 3) {
            o->tpage = 0x14;
        }
        o->unkD = 0;
        *(s8 *)&o->unkF = -30;
        o->unkA = 0;
        o->animFrame = 0;
        o->anim = ((void **)&D_80012194)[o->subtype];
        o->spriteBank = D_1F8002D8[0];
        o->state++;
        readAnimFrameCount(o);
        if (o->subtype == 2) {
            o->unkD = 0x80;
            o->tpage = 0x13;
            o->anim = (*(void **)&D_800123C8);
            playSFX(D_8007C840[o->subtype]);
        }
        break;
    case 1:
        if (o->subtype == 2) {
            o->visible = 1;
            pushDrawListCapped(o);
            if (PLAYER.obj.animFrame & 1) d = -14; else d = 14;
            o->h->p.whole = PLAYER.obj.h->p.whole + d;
            o->y.p.whole = (u16)PLAYER.obj.y.p.whole - 14;
            if (tickAnimation(o)) {
                o->state++;
            }
        } else if (func_80022E44(o)) {
            if (tickAnimation(o)) {
                o->state++;
            }
        }
        break;
    case 2:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", initMsgBoxA);
void initMsgBoxA(u8* self)
{
    *(void**)(self + 0x24) = &D_80014C94;
    readAnimFrameCount(self);
    self[4] = 1;
    self[5] = 0;
    self[6] = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", initMsgBoxB);
void initMsgBoxB(u8* self)
{
    *(void**)(self + 0x24) = &D_80014C8C;
    readAnimFrameCount(self);
    self[4] = 1;
    self[5] = 1;
    self[6] = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002EBC4);
extern void func_80023020(GameObject *);
extern s16 fixedMulCos(s32, s32);
extern s16 fixedMulSin(s32, s32);
extern s32 tickAnimation(GameObject *);

void func_8002EBC4(GameObject *o)
{
    u8 *p;
    s32 f;
    u16 u;
    s32 v;
    u8 st;
    if (o->visible == 0)
        func_80023020(o);
    st = o->subState;
    if (st != 0) {
        if (st != 1)
            return;
    } else
        o->subState = st + 1;
    p = (u8 *)o->unk90;
    switch ((s16)(o->animFrame = *(u16 *)(p + 0x2e) & 7)) {
    case 0: case 2:
        o->unk88 = 0x40;
        o->unk8C = 0xe0;
        break;
    case 1: case 3:
        o->unk88 = 0x40;
        o->unk8C = 0x20;
        break;
    case 4:
        o->unk88 = 0x60;
        o->unk8C = 0;
        break;
    case 5:
        o->unk88 = 0x20;
        o->unk8C = 0;
        break;
    case 6:
        o->unk88 = 0x80;
        o->unk8C = 0x20;
        break;
    case 7:
        o->unk88 = 0;
        o->unk8C = 0xe0;
        break;
    }
    o->x.p.whole = *(s16 *)(p + 0x12) + fixedMulCos((s16)o->unk88, 8);
    v = o->unk88;
    o->y.p.whole = *(s16 *)(p + 0x16) + fixedMulSin((s16)v, 8);
    o->z.p.whole = *(s16 *)(p + 0x1a);
    if (tickAnimation(o)) {
        o->state = 2;
        o->subState = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002ED1C);
extern u8 D_800A5399;
extern u16 *D_800A53BC[];
extern s32 D_800A5424;
extern u8 D_800A53A7[];

void func_8002ED1C(GameObject *o)
{
    s32 d;
    o->unk8C = 0;
    o->visible = D_800A5399;
    if (D_800A539D == 2 && D_800A5416 >= -0xc7 && D_800A5434 != 0) {
        o->anim = (*(void **)&D_80014C8C);
        readAnimFrameCount(o);
        if (D_800A5416 > 0 && *D_800A53BC[0] == 0x47)
            o->unk8C = D_800A5424;
    } else if (D_800A539D == 4 && D_800A5416 >= -0xc7) {
        o->anim = (*(void **)&D_80014C8C);
        readAnimFrameCount(o);
        if (D_800A5416 > 0)
            o->unk8C = D_800A5424;
    } else {
        o->anim = D_80014C90;
        readAnimFrameCount(o);
        d = D_800A5424;
        o->unk8C = (u8)((PLAYER.obj.animFrame & 1) ? d - 0x20 : d + 0x20);
    }
    o->h->p.whole = ((Fix16 **)&D_800A53D8)[0]->p.whole;
    o->y.p.whole = D_800A53AE[0] + 4;
    o->d->p.whole = ((Fix16 **)&D_800A53DC)[0]->p.whole;
    o->unkF = D_800A53A7[0] + 1;
    o->unkF = PLAYER.obj.unkF + D_80011F0D[((s8 *)&D_80012014)[*D_800A53BC[0]] * 4];
    if (D_800A5461[0] == 0)
        o->state = 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002EF20);
extern void freeObjectLayer3(GameObject *);

void func_8002EF20(GameObject *o)
{
    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            o->anim = ((char *)&D_80014C94);
            readAnimFrameCount(o);
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            break;
        case 1:
            o->anim = ((char *)&D_80014C8C);
            readAnimFrameCount(o);
            o->state = 1;
            o->subState = 1;
            o->step = 0;
            break;
        }
        break;
    case 1:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
            func_8002EBC4(o);
            break;
        case 1:
            func_8002ED1C(o);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F05C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F138);
extern s32 D_800A53A8[];
extern u8 D_800A53A7[];

void func_8002F138(void)
{
    GameObject *o;
    s32 v;

    if (D_8009C260 != 0 && (o = allocObjectLayer3()) != 0) {
        o->active = 1;
        o->type = 0x12;
        o->animFrame = ((u16 *)&PLAYER.obj.animFrame)[0] & 1;
        o->x.raw = D_800A53A8[0];
        o->y.raw = D_800A53A8[1];
        o->z.raw = D_800A53A8[2];
        o->tpage = 0;
        o->clut = GetClut(0x80, 499);
        o->unkD = 1;
        o->unkA = 8;
        o->subtype = 1;
        o->unkF = D_800A53A7[0] + 1;
        v = D_1F8002CC;
        o->category |= 0x80;
        o->unk1D = 0x4d;
        o->spriteBank = v;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F220);
void func_8002F220(GameObject *o)
{
    extern u16 D_800A53B2;
    u8 s = o->state;
    s16 t;
    switch (s) {
    case 0:
        if (o->subState != 0) break;
        o->anim = D_80014CB4;
        readAnimFrameCount(o);
        o->x.p.whole = D_800A53AA;
        if (((u16 *)&PLAYER)[2] == 0x405) {
            o->y.p.whole = -0x24;
        } else if (PLAYER.obj.y.p.whole < -0xf1 && PLAYER.obj.h->p.whole >= 0xf3) {
            o->y.p.whole = -0xf0;
        } else {
            o->y.p.whole = -0x28;
        }
        t = D_800A53B2;
        o->state = 1;
        o->subState = 0;
        o->z.p.whole = t;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            o->subState++;
        case 1:
            o->h->p.whole = PLAYER.obj.h->p.whole;
            if (PLAYER.obj.y.p.whole < -0xf1 && PLAYER.obj.h->p.whole >= 0xf3) {
                o->y.p.whole = -0xf0;
            } else {
                o->y.p.whole = -0x28;
            }
            o->d->p.whole = PLAYER.obj.d->p.whole;
            o->animFrame = PLAYER.obj.animFrame & 1;
            break;
        }
        break;
    case 2:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F404);
extern u16 D_800A53B2[];
extern void readAnimFrameCount(GameObject *);

void func_8002F404(GameObject *o)
{
    u8 t = o->state;
    s32 x;

    switch (t) {
    case 0:
        if (o->subState == 0) {
            o->anim = D_80012354[o->subtype];
            readAnimFrameCount(o);
            x = (*(s16 *)&D_800A53AA);
            if (PLAYER.obj.animFrame & 1) {
                o->x.p.whole = x + 8;
            } else {
                o->x.p.whole = x - 8;
            }
            o->y.p.whole = PLAYER.obj.y.p.whole + 0x10;
            o->z.p.whole = D_800A53B2[0];
            o->state = 1;
            o->subState = 0;
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->visible != 0) {
            switch (o->subState) {
            case 0:
                o->subState++;
            case 1:
                if (tickAnimation(o)) {
                    o->state = 2;
                }
                break;
            }
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F56C);
void func_8002F56C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (o->subState == 0) {
            o->anim = (D_80012354 + o->subtype)[o->unkC];
            readAnimFrameCount(o);
            o->x.p.whole = ((u16 *)&D_800A53AA)[0];
            o->y.p.whole = (u16)PLAYER.obj.y.p.whole - 8;
            *(s16 *)((char *)o + 0x1a) = D_800A53B2[0];
            { u8 t = (*(u8 *)&D_800A53A7);
            o->state = 1;
            o->subState = 0;
            o->unkF = t - 1; }
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->visible == 0)
            break;
        switch (o->subState) {
        case 0:
            o->timer = 200;
            o->unk84 = 0;
            switch (o->unkC) {
            case 0: o->velX = 0x10; o->velY = -0x100; o->unk88 = 1; break;
            case 1: o->velX = 0xe; o->velY = -0x140; o->unk88 = 2; break;
            case 2: o->velX = 0x12; o->velY = -0x180; o->unk88 = 1; break;
            case 3: o->velX = 0x11; o->velY = -0x200; o->unk88 = 1; break;
            case 4: o->velX = 0xf; o->velY = -0x220; o->unk88 = 2; break;
            case 5: o->velX = 0x10; o->velY = -0x240; o->unk88 = 1; break;
            }
            o->subState++;
        case 1:
            o->unk84 = (o->unk84 + o->unk88) & 0xff;
            o->h->p.whole = fixedMulCos(o->unk84, o->velX);
            o->y.raw -= 0x10000;
            if (--o->timer == 0)
                o->state = 2;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", dispatchMsgBoxHandler);
void dispatchMsgBoxHandler(u8* self)
{
    D_8007C848[self[3]]();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F804);
typedef struct { s32 x, y, z; } V3_2F804;
void func_8002F804(GameObject *a, s16 b, char c)
{
    GameObject *o = allocObjectLayer3();
    if (o != 0) {
        o->active = 1;
        o->type = 0x13;
        o->animFrame = a->animFrame;
        *(V3_2F804 *)&o->x = *(V3_2F804 *)&a->x;
        if (b == 0) {
            o->tpage = 0;
            o->clut = GetClut(0x80, 0x1f0);
            o->unkD = 0x81;
            o->spriteBank = D_1F8002CC;
            o->unkA = 8;
            *(s8 *)&o->unkF = -7;
            o->subtype = b;
            o->unkC = c;
            o->unk1D = 0x4d;
            *(GameObject **)&o->unk90 = a;
            o->category |= 0x80;
        } else {
            o->tpage = 0x14;
            o->unkD = 0;
            o->spriteBank = D_1F8002D8[0];
            o->unkA = 2;
            o->subtype = b;
            o->unkC = c;
            o->unkF = D_800A53A7[0] - 1;
            o->category |= 0x80;
            o->unk1D = 0x4d;
            *(GameObject **)&o->unk90 = a;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", clearTalkPose);
extern u8 D_800A539A;
extern u8 TALK_POSE;
void func_800EDDDC(u8 *p, s32 a, s32 b);
void func_800E7DF8(u8 *p, s32 a, s32 b);
void func_800E8A30(u8 *p, s32 a, s32 b);
void func_800E8758(u8 *p, s32 a, s32 b);
void clearTalkPose(void)
{
    u8 *p = &D_800A539A;
    TALK_POSE = 0;
    switch (*p) {
    case 0:
        if (GAME.selectedArea == 9) func_800EDDDC(p - 2, 0, 0);
        break;
    case 1:
        func_800E7DF8(p - 2, 0, (*(s16 *)&PLAYER.obj.animFrame));
        break;
    case 2:
        func_800E8A30(p - 2, 0, (*(s16 *)&PLAYER.obj.animFrame));
        break;
    case 3:
        func_800E8758(p - 2, 0, (*(s16 *)&PLAYER.obj.animFrame));
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", updateMessageBox);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBox);
void showMessageBox(s32 arg0, s32 arg1, s16 arg2, s16 arg3)
{
    msgBox box;

    box.unk2 = arg2;
    box.unk6 = arg3;
    box.unkA = 0;
    openMessageBox(arg0, arg1, &box, 0, -1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBoxTimed);
void showMessageBoxTimed(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4)
{
    msgBox box;

    box.unk2 = arg2;
    box.unk6 = arg3;
    box.unkA = 0;
    openMessageBox(arg0, arg1, &box, 0, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBoxDirect);
void showMessageBoxDirect(s32 arg0, s32 arg1, s32 arg2)
{
    openMessageBox(arg0, arg1, arg2, 1, -1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBoxDirectTimed);
void showMessageBoxDirectTimed(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    openMessageBox(arg0, arg1, arg2, 1, arg3);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", openMessageBox);
typedef struct {
    u8 active, b01, type, b03;
    char p04[6];
    u8 b0a, b0b, b0c, b0d, b0e, b0f;
    s32 x, y, z;
    char p1c[2];
    s16 w1e, w20, w22;
    char p24[8];
    u16 w2c, w2e;
    s32 d30, d34, d38;
    char p3c[0x58];
    s32 d94;
    char p98[0x1c];
    s16 b4;
    u16 b6;
    s16 b8;
    u16 ba;
    s16 bc, be, c0;
    u16 c2;
    u16 c4;
    u16 c6;
    s16 c8, ca, cc, ce, d0, d2;
} E2d_30800;
extern char *WFM3_DATA;
#define SP398 (*(char * volatile *)&WFM3_DATA)

E2d_30800 *openMessageBox(s32 k, s32 dx, s16 *pos, s16 anim, u16 w)
{
    s32 i;
    E2d_30800 *o;
    u16 v;
    char *b;
    for (i = 0; i < 4; i++) {
        if (MESSAGE_SLOTS[i].count == -1 && (o = allocObjectLayer3()) != 0) {
            o->type = 0x1a;
            o->b0a = 10;
            o->w1e = 0x14;
            o->b0f = 0x32;
            o->active = 1;
            o->b0c = k;
            o->w2c = 0;
            o->w2e = anim;
            if (anim != 0) {
                o->d30 = pos[1];
                o->d34 = pos[3];
                o->d38 = pos[5];
            } else {
                o->x = pos[1] << 16;
                o->y = pos[3] << 16;
                o->z = 0;
            }
            switch (D_8009C9E4) {
            case 0:
                o->b4 = 6;
                break;
            case 1:
                o->b4 = 3;
                break;
            case 2:
                o->b4 = 2;
                break;
            }
            o->c2 = 0x100;
            o->c4 = 0x30;
            o->b6 = 0xffff;
            o->b8 = 0;
            o->ba = -(o->c2 >> 1);
            o->bc = -o->c4 - 0x30;
            o->be = pos[1] + o->ba;
            o->c0 = pos[3] + o->bc;
            o->ce = 8;
            o->d0 = 6;
            o->c6 = 0xffff;
            o->ca = i;
            o->cc = 1;
            o->d2 = w;
            o->w20 = 1;
            o->w22 = 0;
            MESSAGE_SLOTS[i].count = 0;
            b = SP398;
            v = *(s16 *)(b + k * 2 + 0x10) + dx;
            o->c8 = v;
            b = SP398;
            b += *(u16 *)(b + 8);
            b += *(u16 *)(b + (v << 1));
            o->d94 = (s32)b;
            return o;
        }
    }
}
#undef SP398

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", loadMessageGlyph);
#define setaddr(p, _addr) (((P_TAG *)(p))->addr = (u_long)(_addr))
#define getaddr(p) (u_long)(((P_TAG *)(p))->addr)
#define addPrim(ot, p) setaddr(p, getaddr(ot)), setaddr(ot, p)
#define setRECT(r, _x, _y, _w, _h) (r)->x = (_x), (r)->y = (_y), (r)->w = (_w), (r)->h = (_h)


s16 loadMessageGlyph(s32 p, s32 id, s32 bank)
{
    RECT rect;
    s32 i;
    s32 freeSlot;
    s32 j;
    s16 key;
    s32 n;
    u16 *src;
    u16 *dst;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    DR_LOAD *load;

    freeSlot = -1;
    key = (bank << 12) | (id & 0xfff);
    for (i = 0; i < 0x3c; i++) {
        if (GLYPH_CACHE[i].id == key) {
            GLYPH_CACHE[i].mask |= 1 << p;
            return i;
        }
        if (GLYPH_CACHE[i].id == -1) {
            freeSlot = i;
        }
    }
    if ((s16)freeSlot == -1) {
        return -1;
    }
    GLYPH_CACHE[(s16)freeSlot].mask |= 1 << p;
    src = ((u16 **)&WFM3_DATA)[bank];
    dst = (u16 *)(id * 2 + (s32)src);
    src = (u16 *)((u8 *)src + dst[0x48]);
    w = *src++;
    h = *src++;
    n = w * h;
    a = *src++;
    b = *src++;
    GLYPH_CACHE[(s16)freeSlot].id = key;
    GLYPH_CACHE[(s16)freeSlot].unk8 = 0;
    GLYPH_CACHE[(s16)freeSlot].w = a;
    GLYPH_CACHE[(s16)freeSlot].h = h;
    GLYPH_CACHE[(s16)freeSlot].flag = b;
    if (n < 0x1b) {
        load = (DR_LOAD *)D_1F800164;
        setRECT(&rect, GLYPH_CACHE[(s16)freeSlot].u, GLYPH_CACHE[(s16)freeSlot].v, w, h);
        SetDrawLoad(load, &rect);
        dst = (u16 *)load->p;
        for (j = 0; j < w * h; j++) {
            *dst++ = *src++;
        }
        addPrim(D_1F8001E0 + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
    } else {
        load = (DR_LOAD *)D_1F800164;
        setRECT(&rect, GLYPH_CACHE[(s16)freeSlot].u, GLYPH_CACHE[(s16)freeSlot].v, w, h >> 1);
        SetDrawLoad(load, &rect);
        dst = (u16 *)load->p;
        for (j = 0; j < w * (u16)(h >> 1); j++) {
            *dst++ = *src++;
        }
        addPrim(D_1F8001E0 + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
        load = (DR_LOAD *)D_1F800164;
        setRECT(&rect, GLYPH_CACHE[(s16)freeSlot].u, GLYPH_CACHE[(s16)freeSlot].v + (h >> 1), w, h >> 1);
        SetDrawLoad(load, &rect);
        dst = (u16 *)load->p;
        for (j = 0; j < w * (u16)(h >> 1); j++) {
            *dst++ = *src++;
        }
        addPrim(D_1F8001E0 + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
    }
    return freeSlot;
}
#undef setaddr
#undef getaddr
#undef addPrim
#undef setRECT

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", freeMessageGlyphs);
void freeMessageGlyphs(u32 p)
{
    char pad[4];
    s32 i;
    s32 k;
    u32 u;
    if (MESSAGE_SLOTS[p].count != -1) {
        for (i = 0; i < MESSAGE_SLOTS[p].count; i++) {
            k = (s16)MESSAGE_GLYPHS[p][i].id;
            u = GLYPH_CACHE[k].mask & ~(1 << p);
            GLYPH_CACHE[k].mask = u;
            if (u == 0) GLYPH_CACHE[k].id = -1;
        }
        MESSAGE_SLOTS[p].count = -1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", updateInfoMessage);
typedef struct S_30EF8 {
    char p0; u8 b01; char p1[2]; u8 b04; char p2[0x20 - 5];
    s16 timer; char p3[0xb4 - 0x22];
    u16 wb4, wb6; char p4[0xbe - 0xb8];
    u16 wbe, wc0; char p5[0xca - 0xc2];
    u16 wca;
} S_30EF8;
typedef struct M2_30EF8 { u16 mask; s16 pad[4]; } M2_30EF8;
extern M2_30EF8 D_800A5142[];
void updateInfoMessage(S_30EF8 *o)
{
    s32 i;
    switch (o->b04) {
    case 0:
        o->b04++;
        if (o->wb6 == 2 && o->wb4 == 0)
            o->timer = 0x28;
        else
            o->timer = 0x78;
        break;
    case 1:
        MESSAGE_SLOTS[o->wca].x = o->wbe;
        MESSAGE_SLOTS[o->wca].y = o->wc0;
        o->b01 = 1;
        pushDrawListCapped(o);
        if (--o->timer == 0 || MESSAGE_SLOTS[o->wca].unk2 == -1) {
            MESSAGE_SLOTS[o->wca].unk2 = -1;
            o->b04++;
        }
        break;
    case 2:
        for (i = 0; i < MESSAGE_SLOTS[o->wca].count; i++) {
            s32 v = (s16)MESSAGE_GLYPHS[o->wca][i].id * 10;
            if ((*(u16 *)((char *)D_800A5142 + v) &= ~(1 << o->wca)) == 0)
                *(s16 *)((char *)GLYPH_CACHE + v) = -1;
        }
        MESSAGE_SLOTS[o->wca].count = -1;
        o->b04++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", printInfoMessage);

void drawInfoMessageText(void* obj, s32 stringIndex)
{
    u8*      base;
    s16*     tbl;
    s16*     ent;
    u_short* str;
    s32      token;

    base = *(u8**)(PSX_SCRATCH + 0x398);
    tbl  = (s16*)(base + *(s16*)(base + 8));
    ent  = tbl + stringIndex;
    str  = (u_short*)((u8*)tbl + *ent);

    for (;;) {
        token = *str++;

        if ((u_short)(token + 2) < 2) {
            return;
        }
        if ((s16)token == -3) continue;
        if ((s16)token == -7) continue;
        if ((s16)token == -6) {
            str += 2;
            continue;
        }
        drawMessageGlyph(obj, (s16)token);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", drawMessageGlyph);
typedef struct { char p[0xc2]; u16 w2, w4; char q[4]; u16 idx; char r[2]; u16 wce, wd0; } O_316EC;

void drawMessageGlyph(O_316EC *o, u16 k)
{
    s32 n;
    s32 r;
    n = MESSAGE_SLOTS[o->idx].count++;
    r = ((s32 (*)(s32, s32, s32))loadMessageGlyph)(o->idx, k & 0xfff, 0);
    if ((k & 0x7000) == 0x4000) {
        MESSAGE_GLYPHS[o->idx][n].id = r | 0x4000;
        MESSAGE_GLYPHS[o->idx][n].x = o->w2 - 0x10;
        MESSAGE_GLYPHS[o->idx][n].y = o->w4 - 0x10;
    } else {
        MESSAGE_GLYPHS[o->idx][n].id = r;
        MESSAGE_GLYPHS[o->idx][n].x = o->wce;
        MESSAGE_GLYPHS[o->idx][n].y = o->wd0;
    }
    if ((k & 0x7000) == 0x5000 || (k & 0x7000) != 0x6000)
        o->wce += GLYPH_CACHE[r].w;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", dispatchAreaDialogInit);
void dispatchAreaDialogInit(void)
{
    switch (GAME.selectedArea) {
        case AREA05_BACCUSVILLAGE:
            func_800EF7C0();
            return;
        case AREA11_VILLAGEOFCIVILIZATION:
            func_800F5D5C();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_800EFC0C();
            return;
        case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            func_800F026C();
            return;
        case AREA08_BACCUSLAKE:
            func_800F0A60();
            return;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            func_800F0590();
        default:
            return;
    }
}
