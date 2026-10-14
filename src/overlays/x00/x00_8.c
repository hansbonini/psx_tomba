#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_8", func_801341A0);
typedef struct { char pad[0x4c]; s16 w4c; s16 w4e; } C4C_341A0;
typedef struct { s16 p0, x, p4, y, p8, z; } Pos_341A0;
extern u8 D_8009C10D;
extern u8 D_8009C115;
extern u8 D_8009BCD9;
extern u8 D_8009BCD8[];
#define D_8009C970 D_8009BCD8[0]
extern u8 D_8009BCA7_U8Arr[] asm("D_8009BCA7");
#define D_8009C93F D_8009BCA7_U8Arr[0]
extern u8 D_8009BCA3[];
#define D_8009C93B D_8009BCA3[0]
extern u8 D_8009BCA2_U8Arr[] asm("D_8009BCA2");
#define D_8009C93A D_8009BCA2_U8Arr[0]
extern u8 D_8009BCDD_U8Arr[] asm("D_8009BCDD");
#define D_8009C975 D_8009BCDD_U8Arr[0]
#define D_8009D2B0 D_8009C618[0]
extern void *D_8013A614[];
extern void *D_8013A618[];
extern void *D_8013A61C[];
extern void *D_8013A620[];
extern void *D_8013A624[];
extern void *D_8013A628[];
extern void *D_8013A634[];
extern void *D_1F8002D4;
extern s16 *D_801389E4[];
extern u8 D_800A5401;
extern u8 D_800A539E_U8Arr[] asm("D_800A539E");
#define D_800A603E D_800A539E_U8Arr[0]
extern u8 D_800A539D_U8Arr[] asm("D_800A539D");
#define D_800A603D D_800A539D_U8Arr[0]
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
#define D_800A603C D_800A539C_U8Arr[0]
extern s32 D_8009BCEC[];
#define D_8009C984 D_8009BCEC[0]
extern u8 D_1F8001CD[];
#define D_1F8001CD D_1F8001CD[0]
extern u8 D_1F8001CC[];
#define D_1F8001CC D_1F8001CC[0]
#define D_1F8001C6 ((s16 *)&D_1F8001C6)[0]
extern s16 D_800A544A_S16Arr[] asm("D_800A544A");
#define D_800A60EA D_800A544A_S16Arr[0]
extern s16 D_800A53C6_S16Arr[] asm("D_800A53C6");
#define D_800A6066 D_800A53C6_S16Arr[0]
extern s16 D_8009C0FC_S16Arr[] asm("D_8009C0FC");
#define D_8009CD94 D_8009C0FC_S16Arr[0]
extern s16 D_8009C108[];
#define D_8009CDA0 D_8009C108[0]
extern s16 D_8009C0FE_S16Arr[] asm("D_8009C0FE");
#define D_8009CD96 D_8009C0FE_S16Arr[0]
#define D_800A60D2 ((s16 *)&D_800A5432)[0]
#define D_800A60D0 ((s16 *)&D_800A5430)[0]
extern void readAnimFrameCount(GameObject *);
extern void applyAnimVelocityY(GameObject *, s32);
extern s32 showMessageBox(s32, s32, s32, s32);
extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);
extern void stopBgm(s32);
extern void startAreaBgm(void);
extern void dispatchAreaItemUpdate(GameObject *, Pos_341A0 *, s32);
extern void addItemToInventory(s32, s32, s32);
extern void playSFX(s32);
extern void tickAnimation(GameObject *);
extern void freeObjectLayer2(GameObject *);

void func_801341A0(GameObject *o)
{
    s16 *e;
    Pos_341A0 s;

    switch (o->state) {
    case 0:
        if (D_8009C10D != 0xff) {
            D_8009C93F = 1;
            switch ((*(u8 *)&D_8009C40C)) {
            case 0:
                o->unkB4 = 0;
                break;
            case 1 ... 3:
                o->unkB4 = 1;
                break;
            case 4:
                o->unkB4 = 2;
                break;
            }
        } else if (D_8009C115 != 0xff) {
            D_8009C93F = 1;
            switch ((*(u8 *)&D_8009C40C)) {
            case 0:
                o->unkB4 = 3;
                break;
            case 1 ... 3:
                o->unkB4 = 4;
                break;
            case 4:
                o->unkB4 = 5;
                break;
            }
        } else if (D_8009C970 < D_8009BCD9) {
            o->unkB4 = 7;
        } else {
            o->unkB4 = 6;
        }
        o->active = 2;
        o->tpage = 1;
        o->unkB6 = 0;
        o->unkD = 1;
        o->clut = GetClut(0xc0, 0x1e0);
        {
            s32 d = (s32)D_1F8002D4;
            void *a = D_8013A614[0];
            o->spriteBank = d;
            o->anim = a;
        }
        readAnimFrameCount(o);
        o->unkA = 0;
        o->unkF = 0;
        o->animFrame = 0;
        o->movetab = ((char *)&D_800771FC);
        o->timer = 0;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        e = D_801389E4[(u16)o->unkB4];
        e += (u16)o->unkB6 * 2;
        switch (e[0]) {
        case 0:
            break;
        case 1:
            if (o->timer == 0) {
                o->timer = e[1];
            } else if (--o->timer == 0) {
                o->unkB6++;
            }
            break;
        case 2:
            switch (o->subState) {
            case 0:
                o->anim = D_8013A624[0];
                readAnimFrameCount(o);
                o->h->raw = 0x880000;
                o->y.raw = -0x3c0000;
                o->subState++;
                break;
            case 1:
                if (D_8009D2B0 == 3) break;
                if ((u16)((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole + 32) >= 64) break;
                if (!(D_1F8001FC & (*(u16 *)&D_1F8003C4))) break;
                if (D_800A5401 == 0) break;
                if (D_800A603C != 1) break;
                if ((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole > 0) o->animFrame = 0;
                else o->animFrame = 1;
                D_800A603C = 5;
                D_800A603D = 0;
                D_800A603E = 0;
                D_8009D2B0 = 0;
                D_8009C93F = 1;
                o->anim = D_8013A628[0];
                readAnimFrameCount(o);
                o->cooldownTimer = 60;
                o->subState++;
                break;
            case 2:
                if (--o->cooldownTimer == 0) o->unkB6++;
                break;
            }
            break;
        case 3:
            if (D_8009D2B0 == 3) break;
            if ((u16)((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole + 32) >= 64) break;
            if (!(D_1F8001FC & (*(u16 *)&D_1F8003C4))) break;
            if (D_800A5401 == 0) break;
            if (D_800A603C != 1) break;
            if ((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole > 0) o->animFrame = 0;
            else o->animFrame = 1;
            D_800A603C = 5;
            D_800A603D = 0;
            D_800A603E = 0;
            D_8009D2B0 = 0;
            D_8009C93F = 1;
            o->unkB6++;
            break;
        case 4:
            switch (o->subState) {
            case 0:
                o->anim = D_8013A618[0];
                readAnimFrameCount(o);
                o->subState++;
            case 1:
                if (o->h->p.whole < 40) o->animFrame = 0;
                if (o->h->p.whole >= 161) o->animFrame = 1;
                applyAnimVelocityX(o, o->animFrame);
                {
                    Fix16 *p = (*(Fix16 **)&D_800A53D8);
                    if (p->p.whole >= 180 && D_800A603C != 1) break;
                    p->p.whole = 180;
                }
                D_800A603C = 5;
                D_800A603D = 0;
                D_800A603E = 0;
                D_8009C93A = 1;
                D_8009C984 |= 0x10;
                o->subState = 0;
                o->unkB6++;
                break;
            }
            break;
        case 5:
            switch (o->subState) {
            case 0:
                if (o->animFrame == 0) {
                    o->subState = 2;
                    break;
                }
                o->anim = D_8013A634[0];
                readAnimFrameCount(o);
                o->cooldownTimer = 21;
                o->subState++;
                break;
            case 1:
                if (--o->cooldownTimer == 0) {
                    o->animFrame = 0;
                    o->subState++;
                }
                break;
            case 2:
                applyAnimVelocityX(o, o->animFrame);
                if (o->h->p.whole >= 121) {
                    o->subState = 0;
                    o->unkB6++;
                }
                break;
            }
            break;
        case 6:
            o->anim = D_8013A61C[0];
            readAnimFrameCount(o);
        case 7:
            o->unk90 = showMessageBox(1, e[1], 120, 156);
            o->unkB6++;
            break;
        case 8:
            if (((u8 *)o->unk90)[4] < 2) break;
            o->anim = D_8013A614[0];
            readAnimFrameCount(o);
            ((u8 *)o->unk90)[4]++;
            o->unkB6++;
            break;
        case 9:
            setEventStarted(e[1], 0, 0);
            o->unkB6++;
            break;
        case 10:
            setEventComplete(e[1], 0);
            o->unkB6++;
            break;
        case 11:
            D_8009C975 = 3;
            o->unkB6++;
            break;
        case 12:
            if (D_8009C975 == 1) o->unkB6++;
            break;
        case 13:
            D_8009C975 = 4;
            o->unkB6++;
            break;
        case 14:
            if (D_8009C975 == 0) o->unkB6++;
            break;
        case 15:
            D_1F8001CC = 1;
            D_1F8001CD = 3;
            D_1F8001C6 = 2;
            stopBgm(0);
            openTask(1, moviePlayerTask);
            o->unkB6++;
            break;
        case 16:
            startAreaBgm();
            o->unkB6++;
            break;
        case 17:
            D_800A603C = 5;
            D_800A603D = 0;
            D_800A603E = 0;
            {
                s16 t = (*(Fix16 **)&D_800A53D8)->p.whole > o->h->p.whole;
                D_8009C93F = 1;
                D_800A6066 = t;
            }
            o->unkB6++;
            break;
        case 18:
            D_800A60EA = 0;
            D_800A603C = 1;
            D_800A603D = 0;
            D_800A603E = 0;
            D_8009C93F = 0;
            o->unkB6++;
            break;
        case 19:
            D_800A603C = 5;
            D_800A603D = 3;
            D_800A603E = 0;
            o->unkB6++;
            break;
        case 20:
            {
                C4C_341A0 *c = D_1F8001D4;
                D_8009CD96 = 2;
                D_8009CDA0 = 1;
                D_8009CD94 = 0;
                c->w4c = 7;
                c->w4e = 0;
            }
            o->unkB6++;
            break;
        case 21:
            {
                u8 *q = (u8 *)o->unk94;
                q[5] = 1;
                q[6] = 0;
            }
            o->unkB6++;
            break;
        case 22:
            {
                u8 *q = (u8 *)o->unk94;
                q[5] = 6;
                q[6] = 0;
            }
            o->unkB6++;
            break;
        case 23:
            switch (o->subState) {
            case 0:
                o->animFrame = 1;
                o->anim = D_8013A618[0];
                readAnimFrameCount(o);
                o->movetab = ((char *)&D_800771FC);
                o->subState++;
            case 1:
                applyAnimVelocityY(o, 0);
                if (o->y.p.whole < -51) break;
                o->subState++;
                break;
            case 2:
                applyAnimVelocityX(o, o->animFrame);
                if (o->h->p.whole < 110) {
                    o->anim = D_8013A620[0];
                    readAnimFrameCount(o);
                    D_8009C93B = 1;
                    o->cooldownTimer = 60;
                    o->subState++;
                }
                break;
            case 3:
                if (--o->cooldownTimer == 0) {
                    o->subState = 0;
                    o->unkB6++;
                }
                break;
            }
            break;
        case 24:
            switch (o->subState) {
            case 0:
                o->animFrame = 1;
                o->anim = D_8013A620[0];
                readAnimFrameCount(o);
                o->cooldownTimer = 60;
                o->subState++;
                break;
            case 1:
                if (--o->cooldownTimer == 0) {
                    s.x = o->h->p.whole;
                    s.y = o->y.p.whole;
                    s.z = o->d->p.whole;
                    dispatchAreaItemUpdate(o, &s, 0);
                    o->animFrame = 1;
                    o->subState++;
                }
                break;
            case 2:
                applyAnimVelocityX(o, 0);
                if ((u16)(D_800A53AA - o->h->p.whole) < 32) o->subState++;
                break;
            case 3:
                if (--o->y.p.whole < -56) {
                    o->subState = 0;
                    o->animFrame = 0;
                    o->unkB6++;
                }
                break;
            }
            break;
        case 25:
            addItemToInventory(6, 1, 1);
            o->unkB6++;
            break;
        case 26:
            {
                s32 v = D_8009BCD9;
                D_800A60D0 = v;
                D_800A60D2 = v;
                D_8009C970 = v;
            }
            playSFX(10);
            o->unkB6++;
            break;
        case 27:
            o->unkB6++;
            o->unkB8 = o->unkB6;
            break;
        case 28:
            o->unkB6 = o->unkB8;
            break;
        }
        if (func_80022E44(o)) tickAnimation(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
#undef D_8009C970
#undef D_8009C93F
#undef D_8009C93B
#undef D_8009C93A
#undef D_8009C975
#undef D_8009D2B0
#undef D_800A603E
#undef D_800A603D
#undef D_800A603C
#undef D_8009C984
#undef D_1F8001CD
#undef D_1F8001CC
#undef D_1F8001C6
#undef D_800A60EA
#undef D_800A6066
#undef D_8009CD94
#undef D_8009CDA0
#undef D_8009CD96
#undef D_800A60D2
#undef D_800A60D0

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_8", func_80134E50);
typedef struct { s16 x, y; } P_34E50;
extern s32 angleBetweenPoints(P_34E50 a, P_34E50 b);
extern u16 D_1F80016E;

void func_80134E50(GameObject *o)
{
    P_34E50 a, b;
    u32 d;
    switch (o->subState) {
    case 0:
        o->unk84 = 0x80;
        o->unkA = 2;
        o->velH = 0x80;
        o->unk88 = 0;
        o->unk8C = 0;
        o->animFrame = 1;
        o->subState++;
        break;
    case 1:
        a.x = o->h->p.whole;
        a.y = o->y.p.whole;
        b.x = (*(u16 *)&D_1F80016A);
        b.y = D_1F80016E;
        o->unk88 = angleBetweenPoints(a, b);
        o->timer = 0x78;
        o->subState++;
        break;
    case 2:
        d = (o->unk84 - o->unk88) & 0xff;
        if (d != 0) {
            if (d < 0x80) o->unk84 = (o->unk84 - 1) & 0xff;
            else o->unk84 = (o->unk84 + 1) & 0xff;
        }
        if ((u32)((o->unk84 - 0x40) & 0xff) < 0x80) {
            o->animFrame = 0;
            o->unk8C = (o->unk84 + 0x80) & 0xff;
        } else {
            o->animFrame = 1;
            o->unk8C = o->unk84;
        }
        o->h->raw += (D_8007DB88[(u8)o->unk84] * o->velH) >> 4;
        o->y.raw += (D_8007D988[(u8)o->unk84] * o->velH) >> 4;
        if (--o->timer == -1) o->subState = 1;
        if ((u32)((u16)o->h->p.whole - 0x14d) >= 0x10c) o->subState++;
        else if ((u16)(o->y.p.whole + 0xc8) >= 0x74) o->subState++;
        break;
    case 3:
        a.x = o->h->p.whole;
        a.y = o->y.p.whole;
        b.x = 0x1ec;
        b.y = -0x87;
        o->unk88 = angleBetweenPoints(a, b);
        o->timer = 0x78;
        o->subState--;
        break;
    }
}
