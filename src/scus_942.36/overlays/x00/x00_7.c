#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_80132598);
extern void *D_8013A4C4;
extern void *D_8013A4CC[];
extern void *D_8013A4D0[];
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);

void func_80132598(GameObject *o)
{
    s16 f;
    switch (o->step) {
    case 0:
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->active = 2;
        {
            s16 x = o->h->p.whole;
            o->velY = -0x400;
            o->velX = x;
        }
        o->anim = D_8013A4CC[0];
        readAnimFrameCount(o);
        {
            u16 c = D_8009BCCA;
            u8 s = o->step;
            o->unk78 = 1;
            o->unk68 = c;
            o->step = s + 1;
        }
    case 1:
        tickAnimation(o);
        f = ((u16 *)o->anim)[2];
        o->animFrame = f;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0)
            o->step = 2;
        break;
    case 2:
        tickAnimation(o);
        f = ((u16 *)o->anim)[2];
        o->animFrame = f;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x20))) {
            o->animFrame = D_800A53C6 ^ 1;
            o->anim = D_8013A4D0[0];
            readAnimFrameCount(o);
            o->step = 3;
        }
        break;
    case 3:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) {
            o->active = 1;
            o->step = 4;
        }
        break;
    case 4:
        if (tickAnimation(o)) {
            o->anim = D_8013A4C4;
            readAnimFrameCount(o);
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_801327B8);
typedef struct { s8 anim, z, ang, rad; } E4_327B8;
typedef struct { char c[12]; } V12_327B8;
extern GameObject PLAYER_GameObject asm("PLAYER");
extern u8 D_800A5399;
extern u8 D_800A53A7;
extern u8 D_800A543A;
extern u16 *D_800A53BC[];
extern Fix16 *D_800A53D8_Fix16Ptr asm("D_800A53D8");
extern s32 D_800A53FC;
extern Fix16 *D_800A53DC_Fix16PtrArr[] asm("D_800A53DC");
extern s32 D_800A5424[];
extern s32 D_8009BCEC[];
#define D_8009C984 D_8009BCEC[0]
extern s32 D_8009BCEC_S32 asm("D_8009BCEC");
extern u8 D_8009C10F[];
extern s32 D_1F8002D4[];
extern void *D_8013A4D4[];
extern char D_80077250[];
extern char D_8007725C[];
extern char D_80077238[];
extern void applyFrameVelocityX(GameObject *);
extern void pushDrawListMain(GameObject *);
extern void freeObjectLayer2(GameObject *);
extern void func_801322C4(GameObject *);
extern void func_800EDDDC(GameObject *, s32, s32);
extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);
extern void addItemToInventory(s32, s32, s32);
extern void removeItemFromInventory(s32, s32);
extern void showMessageBox(s32, s32, s32, s32);
extern s32 fixedMulCos(s16 a, s32 b);
extern s32 fixedMulSin(s16 a, s32 b);
extern void spawnItemFixed(s32, s32, void *);
extern void func_800EA86C(s32, s32, s32, s32);
extern void func_80023020(GameObject *);
extern void printInfoMessage(s32, s32);

void func_801327B8(GameObject *o)
{
    switch (o->state) {
    case 0:
        switch (o->subState) {
        case 0:
            if (D_8009C984 & 6) {
                o->state = 3;
                break;
            }
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0x18;
            o->hitHeight = 0x20;
            o->unk8C = 0;
            o->tpage = 0xb;
            o->unkD = 0;
            o->spriteBank = D_1F8002D4[0];
            o->anim = D_8013A4CC[0];
            o->unkA = 2;
            readAnimFrameCount(o);
            o->subState++;
            break;
        case 1:
            o->visible = 0;
            pushDrawListMain(o);
            break;
        }
        break;
    case 1:
        if (func_80022E44(o)) {
            switch (o->subState) {
            case 0:
                func_80132598(o);
                break;
            case 1:
                func_801322C4(o);
                break;
            }
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            switch (o->step) {
            case 0:
                PLAYER_GameObject.visible = 1;
                PLAYER_GameObject.unk8C = 0;
                D_8009C984 |= 2;
                func_800EDDDC(&PLAYER_GameObject, 0xd, 0);
                o->timer = 2;
                if (D_8009C10F[0] == 0) {
                    o->unk78 = 1;
                    o->h->p.whole = PLAYER_GameObject.h->p.whole;
                    PLAYER_GameObject.y.p.whole = o->y.p.whole - o->hitOffsetY;
                    setEventStarted(3, 0, 0);
                    o->timer = 300;
                    D_8009BCAA = 1;
                    D_8009BCA7 = 1;
                }
                addItemToInventory(1, 1, 1);
                o->step++;
            case 1:
                if (--o->timer <= 0) {
                    D_8009BCAA = 0;
                    D_8009BCA7 = 0;
                    o->subState = 1;
                }
                break;
            }
            break;
        case 1:
            tickAnimation(o);
            break;
        case 2:
            if (o->unk78 != 0) {
                D_8009BCAA = 0;
                D_8009BCA7 = 0;
            }
            D_8009C984 &= ~2;
            o->subState = 5;
            o->step = 0;
            break;
        case 3: {
            E4_327B8 *e;
            u32 t;
            u16 u;
            s32 ang;
            o->visible = D_800A5399;
            o->active = 2;
            o->animFrame = D_800A53C6 & 1;
            o->category |= 0x80;
            e = &((E4_327B8 *)&D_80011F0C)[((s8 *)&D_80012014)[*D_800A53BC[0]]];
            o->anim = ((void **)&D_8013A4C4)[e->anim];
            if (o->animFrame & 1) {
                u = D_800A5424[0] + 0x80 - e->ang;
                t = u; t &= 0xff;
            } else {
                u = e->ang + D_800A5424[0];
                t = u; t &= 0xff;
            }
            ang = (s16)t;
            o->h->p.whole = D_800A53D8_Fix16Ptr->p.whole + fixedMulCos(ang, e->rad);
            o->y.p.whole = PLAYER_GameObject.y.p.whole + fixedMulSin(ang, e->rad);
            o->d->p.whole = D_800A53DC_Fix16PtrArr[0]->p.whole;
            o->unk8C = D_800A5424[0];
            o->unkF = D_800A53A7 + (u8)e->z;
            if (D_800A539C == 2) {
                D_8009C984 &= ~2;
                o->state = 2;
                o->subState = 5;
                o->step = 0;
            }
            if ((*(u16 *)&GAME) != 0) break;
            if (D_8009BCCA == 0 && D_800A539D == 0x20 && D_800A53DC_Fix16PtrArr[0]->p.whole > 0 &&
                PLAYER_GameObject.y.p.whole >= -0x2f && (u16)(D_800A53D8_Fix16Ptr->p.whole - 0x400) < 0x18) {
                D_8009BCEC_S32 &= ~2;
                o->state = 2;
                o->subState = 5;
                o->step = 0;
            }
            if (D_8009C984 & 4) break;
            if (!(D_8009C984 & 2)) break;
            if (D_800A53FC != 0) {
                o->state = 2;
                o->subState = 5;
                o->step = 0;
                break;
            }
            switch (D_8009BCCA) {
            case 2:
                if (D_800A53D8_Fix16Ptr->p.whole >= 0xa61) o->subState = 6;
                break;
            case 5:
                if (D_800A53D8_Fix16Ptr->p.whole >= 0xbd && D_800A543A == 0) {
                    o->subState = 4;
                    D_8009BCAA = 1;
                    D_8009BCA7 = 1;
                }
                break;
            }
            break;
        }
        case 4:
            switch (o->step) {
            case 1:
                goto L3ffc;
            case 0:
                o->active = 2;
                o->animFrame = 0;
                o->unk8C = 0;
                removeItemFromInventory(1, 1);
                o->anim = D_8013A4D4[0];
                readAnimFrameCount(o);
                o->movetab = D_80077250;
                o->velY = -0x280;
                showMessageBox(5, 0, 0x100, 0x9c);
                PLAYER_GameObject.animFrame = 0;
                goto L4034;
            case 2: {
                V12_327B8 v;
                tickAnimation(o);
                applyFrameVelocityX(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (o->y.p.whole < -0xef) break;
                PLAYER_GameObject.visible = 1;
                v = *(V12_327B8 *)&o->x;
                spawnItemFixed(0x10, 0, &v);
                spawnItemFixed(0x10, 0, &v);
                setEventComplete(3, 0);
                func_800EA86C(1, o->x.p.whole, (s16)(o->y.p.whole - 0x20), o->z.p.whole);
                D_8009C984 = (D_8009C984 | 4) & ~2;
                o->timer = 300;
                o->step++;
                break;
            }
            case 3:
                if (--o->timer <= 0) {
                    D_8009BCAA = 0;
                    D_8009BCA7 = 0;
                    o->state = 3;
                }
                break;
            }
            break;
        case 5:
            if (o->visible == 0) o->state = 3;
            switch (o->step) {
            case 0:
                o->unk8C = 0;
                o->active = 2;
                o->anim = D_8013A4D4[0];
                readAnimFrameCount(o);
                removeItemFromInventory(1, 1);
                o->movetab = D_8007725C;
                o->animFrame = !(PLAYER_GameObject.h->p.whole < o->h->p.whole);
                o->velY = -0x400;
                D_8009C984 &= ~2;
                printInfoMessage(0x10, 2);
                o->step++;
            case 1:
                applyFrameVelocityX(o);
                tickAnimation(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (o->velY <= 0) break;
                o->step++;
                break;
            case 2:
                applyFrameVelocityX(o);
                tickAnimation(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 8) == 0) break;
                o->anim = (*(void **)&D_8013A4D0);
                readAnimFrameCount(o);
                goto L4034;
            case 3:
                applyFrameVelocityX(o);
                tickAnimation(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 8) == 0) break;
                goto L4034;
            case 4:
                if (tickAnimation(o) == 0) break;
                goto L4034;
            case 5:
                o->anim = ((void **)&D_8013A4C4)[0];
                readAnimFrameCount(o);
                o->movetab = D_8007725C;
                o->velY = -0x300;
                o->animFrame = !(PLAYER_GameObject.h->p.whole < o->h->p.whole);
                func_80023020(o);
                goto L4034;
            case 6:
                applyFrameVelocityX(o);
                tickAnimation(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (o->velY <= 0) break;
                o->step++;
                break;
            case 7:
                applyFrameVelocityX(o);
                tickAnimation(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 8) == 0) break;
                o->anim = ((void **)&D_8013A4C4)[0];
                readAnimFrameCount(o);
                o->step = 5;
                break;
            }
            break;
        case 6:
            switch (o->step) {
            case 1:
                goto L3ffc;
            case 0:
                o->active = 2;
                o->animFrame = 0;
                o->anim = D_8013A4D4[0];
                readAnimFrameCount(o);
                o->movetab = D_80077238;
                o->velY = -0x200;
                removeItemFromInventory(1, 1);
                D_8009C984 &= ~2;
                showMessageBox(5, 1, 0x100, 0x9c);
                goto L4034;
            L3ffc:
                tickAnimation(o);
                applyFrameVelocityX(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (o->velY <= 0) break;
            L4034:
                o->step++;
                break;
            case 2:
                tickAnimation(o);
                applyFrameVelocityX(o);
                o->y.raw += o->velY << 8;
                o->velY += 0x20;
                if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole) == 0) break;
                o->state = 3;
                break;
            }
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
#undef D_8009C984

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_80133408);
extern GameObject *allocObjectLayer2(void);
extern void readAnimFrameCount(GameObject *);
extern u16 D_800A53C6;
extern s32 D_1F8002D4[];
extern void *D_8013A4CC[];

void func_80133408(s32 x, s32 y, s32 z)
{
    GameObject *o = allocObjectLayer2();
    if (o) {
        u16 u;
        o->active = 1;
        o->type = 0x12;
        u = D_800A53C6;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->tpage = 0xb;
        o->unkD = 0;
        o->animFrame = u & 1;
        o->spriteBank = D_1F8002D4[0];
        o->anim = D_8013A4CC[0];
        o->unkA = 2;
        readAnimFrameCount(o);
        o->state = 2;
        o->subState = 3;
        o->step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_801334D4);
extern void *D_8013A5B8;
extern void *D_8013A5BC;

void func_801334D4(GameObject *o)
{
    switch (o->subState) {
    case 0:
        switch (o->step) {
        case 0:
            if (nextRandom() & 1) {
                o->anim = D_8013A5B8;
                readAnimFrameCount(o);
                o->timer = 0x40;
                o->step = 2;
                break;
            }
            o->anim = D_8013A5BC;
            readAnimFrameCount(o);
            o->timer = 0x20;
            o->step = 1;
            break;
        case 1:
            tickAnimation(o);
            if (--o->timer == 0)
                o->step = 0;
            break;
        case 2:
            tickAnimation(o);
            if (--o->timer == 0)
                o->step = 0;
            break;
        }
        break;
    case 1:
        switch (o->step) {
        case 0:
            switch (nextRandom() & 3) {
            case 0:
            case 1:
                o->anim = D_8013A5B8;
                readAnimFrameCount(o);
                o->timer = 0x40;
                o->step = 1;
                break;
            case 2:
                o->anim = D_8013A5BC;
                readAnimFrameCount(o);
                o->timer = 0x20;
                o->step = 1;
                break;
            case 3:
                o->anim = D_8013A5BC;
                readAnimFrameCount(o);
                o->timer = 0x20;
                o->step = 1;
                break;
            }
            break;
        case 1:
            tickAnimation(o);
            if (--o->timer == 0)
                o->step = 0;
            break;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_8013364C);
void func_8013364C(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->anim = D_8013A5B8;
        readAnimFrameCount(o);
        o->velX = 0x200;
        o->animFrame = 0;
        o->velY = -0x400;
        o->clut = GetClut(0x100, 0x1f0);
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        {
            s16 s = o->velY;
            s16 s2;
            o->y.raw += s << 8;
            s2 = o->velY + 0x40;
            o->velY = s2;
            if (s2 > 0x780)
                o->velY = 0x780;
        }
        if (o->visible == 0) {
            o->state = 3;
            o->subState = 0;
            o->step = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_80133748);
extern u8 D_8009C111;
void func_80133748(GameObject *o)
{
    s32 t;
    void *a;
    switch (o->state) {
    case 0:
        o->hitOffsetX = 10;
        o->hitWidth = 0x14;
        o->hitOffsetY = 0x10;
        o->hitHeight = 0x20;
        o->tpage = 8;
        o->animFrame = 1;
        t = D_1F8002D4[0];
        a = ((void **)&D_8013A5B8)[0];
        o->spriteBank = t;
        o->anim = a;
        readAnimFrameCount(o);
        o->unkD = 1;
        o->unkA = 0;
        o->clut = GetClut(0x100, 0x1f1 - o->subtype);
        readAnimFrameCount(o);
        o->unk8C = 0;
        o->category |= 0x80;
        o->state++;
        o->subState = o->subtype;
        if (D_8009C111 == 0xff) o->state = 3;
        break;
    case 1:
        func_80022E44(o);
        if (D_8009C111 == 0xff) {
            if (!o->visible) o->state = 3;
            func_801334D4(o);
        } else if (o->visible) {
            func_801334D4(o);
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            if (o->visible) o->subState = 1;
            break;
        case 1:
            break;
        case 2:
            switch (o->step) {
            case 0:
                o->anim = ((void **)&D_8013A5B8)[0];
                readAnimFrameCount(o);
                o->velX = 0x200;
                o->animFrame = 0;
                o->velY = -0x400;
                o->clut = GetClut(0x100, 0x1f0);
                o->step++;
            case 1:
                tickAnimation(o);
                o->h->raw += o->velX << 8;
                o->y.raw += o->velY << 8;
                o->velY += 0x40;
                if (o->velY > 0x780) o->velY = 0x780;
                if (!o->visible) {
                    o->state = 3;
                    o->subState = 0;
                    o->step = 0;
                }
                break;
            }
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_80133A04);
extern void *D_80139F74;
extern void *D_80139F78;

void func_80133A04(GameObject *o)
{
    s16 r;
    s16 v;

    switch (o->step) {
    case 0:
        o->anim = D_80139F74;
        readAnimFrameCount(o);
        o->animFrame = 1;
        o->velX = -0xc0;
        o->velY = -0x100;
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0)
            o->step++;
        break;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        r = ((s32 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + (o->hitHeight - o->hitOffsetY));
        if (o->touchFlag | r) {
            o->active = 4;
            o->anim = D_80139F78;
            readAnimFrameCount(o);
            o->step++;
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            o->anim = D_80139F74;
            readAnimFrameCount(o);
            v = 0x300;
            if (o->animFrame & 1)
                v = -0x300;
            o->velX = v;
            o->velY = -0x300;
            o->step++;
        }
        break;
    case 4:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0)
            o->step++;
        break;
    case 5:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        r = ((s32 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + (o->hitHeight - o->hitOffsetY));
        if (r)
            o->step = 3;
        break;
    }
    if (o->visible == 0) {
        o->state = 3;
        o->subState = 0;
        o->step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_80133CC4);
extern void *D_80139F5C;
extern void *D_80139F8C;
extern void *D_80139F74;
extern u8 D_8009BCA7_U8Arr[] asm("D_8009BCA7");
extern u8 D_8009BCAA_U8Arr[] asm("D_8009BCAA");
extern u8 D_8009BCA6_U8Arr[] asm("D_8009BCA6");
extern u8 D_8009C376[];
void func_80133CC4(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->anim = D_80139F5C;
        readAnimFrameCount(o);
        o->animFrame = 1;
        if (D_800A53DC_Fix16PtrArr[0]->p.whole != 0) break;
        if ((u16)((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole + 0x50) < 0xa0) {
            D_8009BCA7_U8Arr[0] = 1;
            D_8009BCAA_U8Arr[0] = 1;
            D_8009BCA6_U8Arr[0] = 1;
            o->step++;
        }
        break;
    case 1:
        o->anim = D_80139F8C;
        readAnimFrameCount(o);
        o->velX = 0xc0;
        o->animFrame = 0;
        o->velY = -0x480;
        o->step++;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0) {
            o->anim = D_80139F74;
            readAnimFrameCount(o);
            o->animFrame = o->h->p.whole >= 0x139;
            o->velH = (0x138 - o->h->p.whole) >> 6;
            o->velV = (-0x11c - o->y.p.whole) >> 6;
            o->velY = -0x200;
            o->timer = 0x40;
            o->step++;
        }
        break;
    case 3:
        tickAnimation(o);
        o->h->p.whole += o->velH;
        o->y.p.whole += o->velV;
        o->y.raw += o->velY << 8;
        o->velY += 0x10;
        if (--o->timer > 0) break;
        o->anim = D_80139F5C;
        readAnimFrameCount(o);
        o->animFrame = 0;
        o->subtype = 0;
        o->h->p.whole = 0x138;
        o->y.p.whole = -0x11c;
        D_8009C376[0] = 1;
        D_8009BCA7_U8Arr[0] = 0;
        D_8009BCAA_U8Arr[0] = 0;
        D_8009BCA6_U8Arr[0] = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_7", func_80133F64);
extern s32 D_1F8002D0[];
extern void *D_80139F60[];
extern void *D_80139F7C[];
extern void *D_80139F84[];
extern u8 D_8009C1B2;

void func_80133F64(GameObject *o)
{
    s32 st;
    void *an;

    switch (o->state) {
    case 0:
        o->hitOffsetX = 10;
        o->hitWidth = 0x14;
        o->hitOffsetY = 0x10;
        o->hitHeight = 0x20;
        o->tpage = 1;
        o->unkA = 2;
        *(s8 *)&o->unkF = -8;
        o->unkD = 0;
        o->spriteBank = D_1F8002D0[0];
        o->anim = D_80139F60[0];
        readAnimFrameCount(o);
        o->unk8C = 0;
        o->category |= 0x80;
        o->state++;
        if (D_8009C1B2 == 0xff)
            o->state = 3;
        break;
    case 1:
        if (o->subtype == 0x63) {
            func_80022E44(o);
            func_80133CC4(o);
            break;
        }
        if (D_8009C1B2 == 0xff) {
            o->active = 2;
            func_80022E44(o);
            if (o->visible == 0)
                o->state = 3;
        } else {
            func_80022E44(o);
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            st = o->step;
            if (st == 0) goto c0;
        chk:
            if (st == 1) goto fec;
            return;
        c0:
            an = D_80139F7C[0];
            goto set;
        case 1:
            st = o->step;
            if (st != 0) goto chk;
            an = D_80139F84[0];
        set:
            o->anim = an;
            readAnimFrameCount(o);
            o->step++;
            goto fec;
        case 2:
            o->state = 3;
            return;
        case 3:
            func_80133A04(o);
            return;
        case 4:
            break;
        default:
            return;
        }
    fec:
        tickAnimation(o);
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
