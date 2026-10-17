#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_80129EAC);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012A634);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T8012B2E4_2A634;

extern T8012B2E4_2A634 D_80135114[];
extern void advanceAnimFrame(GameObject *, s32);
extern void readAnimFrameCount(GameObject *);

void func_8012A634(GameObject *o)
{
    o->hitOffsetX = D_80135114[o->subtype].b0;
    o->hitWidth = D_80135114[o->subtype].b1;
    o->hitOffsetY = D_80135114[o->subtype].b2;
    o->hitHeight = D_80135114[o->subtype].b3;
    o->tpage = D_80135114[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80135114[o->subtype].w6];
    readAnimFrameCount(o);
    o->anim = D_80135114[o->subtype].anim[4];
    advanceAnimFrame(o, 0);
    o->unkA = 2;
    o->unk8C = 0;
    o->unkD = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->unkF = PLAYER.obj.unkF + 1;
    o->state++;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012A7A4);

extern u8 D_8009C36B;
extern s32 tickAnimation(GameObject *);

static __inline__ s32 check_2A7A4(void)
{
    return D_8009BC98.unk10 == 1 && D_8009BCA9 == 0x7d;
}

void func_8012A7A4(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8012A634(o);
        break;
    case 1:
        func_80022E44(o);
        if (o->unkC == 0x28) {
            switch (o->subState) {
            case 0:
                if (o->unk68) {
                    o->subState++;
                } else if (check_2A7A4()) {
                    D_8009BC98.unk10 = 0;
                    if (D_8009C36B == 0) D_8009C36B = 1;
                    o->subState++;
                }
                break;
            case 1:
                func_80129EAC(o);
                break;
            }
        }
        if (o->anim && o->active) tickAnimation(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012A92C);

void func_8012A92C(GameObject *o)
{
    if (o->unk68 != 0) o->subState++;
    if (D_8009C068.event_B9 == 0xff && o->subState == 0) {
        o->unk88 = 1;
        o->subState = 1;
        o->step = 0x46;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012A98C);
s32 func_8012A98C(void)
{
    if (D_8009C068.item_24 != 0 && D_8009C068.event_B9 != 0xff) return 1;
    return 0;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012A9BC);

typedef struct { s16 v[6]; } V6_2A9BC;
typedef struct { void **anims; s32 a; s32 b; } AT_2A9BC;
extern AT_2A9BC D_80135128[];
extern s32 tickAnimation(GameObject *);
extern s32 showMessageBoxDirect(s32, s32, V6_2A9BC *);
extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);
extern s16 func_80043AB0(GameObject *, s16, s16, s16);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

#define WC2(o) (*(u16 *)((char *)(o) + 0xc2))

static __inline__ void setanim_2A9BC(GameObject *o, s32 n)
{
    o->anim = D_80135128[o->subtype].anims[n];
    advanceAnimFrame(o, 0);
}

static __inline__ s32 chk_2A9BC(void)
{
    return D_8009C068.item_24 && ((u8 *)&D_8009C1C0)[5] != 0xff;
}

void func_8012A9BC(GameObject *o)
{
    V6_2A9BC v;
    GameObject *p;
    u8 k;

    tickAnimation(o);
    switch (o->step) {
    case 0:
        if (D_8009C068.event_B9 == 0xff) {
            o->unk68 = 0;
            goto reset;
        }
        PLAYER.obj.state = 5;
        PLAYER.obj.subState = 0;
        PLAYER.obj.step = 0;
        o->animFrame = o->unk68 & 1;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        o->step++;
        break;
    case 1:
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        o->step = 10;
        break;
    case 10:
        k = D_8009C068.event_B9;
        if (k == 0xff) {
            o->step = 0x5a;
            WC2(o) = 0x7a;
            break;
        }
        if (chk_2A9BC()) {
            v = *(V6_2A9BC *)&o->x;
            o->unk90 = showMessageBoxDirect(4, 1, &v);
            o->step = 0x5a;
            WC2(o) = 0x46;
        } else if (k == 0) {
            v = *(V6_2A9BC *)&o->x;
            o->unk90 = showMessageBoxDirect(4, 0, &v);
            o->step = 0x5a;
            WC2(o) = 0x32;
        } else {
            v = *(V6_2A9BC *)&o->x;
            o->unk90 = showMessageBoxDirect(4, 0, &v);
            o->step = 0x5a;
            WC2(o) = 0x7a;
        }
        break;
    case 0x33:
        break;
    case 0x32:
        setEventStarted(0xb9, 0, 0);
        o->step = 0x78;
        break;
    case 0x46:
        setanim_2A9BC(o, 2);
        o->velX = 0x100;
        o->velY = -0x400;
        o->animFrame = 0;
        o->touchFlag = 0;
        o->step = 0x47;
        break;
    case 0x47:
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        func_80043AB0(o, o->h->p.whole, o->y.p.whole, o->animFrame);
        if (o->velY > 0) o->step = 0x48;
        goto vis;
    case 0x48:
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        func_80043AB0(o, o->h->p.whole, o->y.p.whole, o->animFrame);
        if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole)) o->step = 0x46;
    vis:
        if (!o->visible) o->step = 0x49;
        break;
    case 0x49:
        setEventComplete(0xb9, 0);
        o->step = 0x78;
        WC2(o) = 0xfa;
        break;
    case 0x5a:
        setanim_2A9BC(o, 1);
        o->step = 0x5b;
        break;
    case 0x5b:
        p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        setanim_2A9BC(o, 0);
        o->step = WC2(o);
        break;
    case 0x6e:
        o->timer = 200;
        o->step = 0x6f;
        break;
    case 0x6f:
        if (--o->timer == 0) o->step = WC2(o);
        break;
    case 0x78:
        o->timer = 200;
        o->step = 0x79;
        break;
    case 0x7b:
        if (o->timer <= 0) o->timer = 4;
        o->step = 0x79;
        break;
    case 0x79:
        if (--o->timer == 0) o->step = 0x7a;
        break;
    case 0x7a:
        ((u8*)&D_8009BC98.unk0F)[0] = 0;
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        ((u8*)&D_8009BC98.unk0E)[0] = 0;
        if (o->unk88 == 0) {
            PLAYER.obj.unkB2 = 0;
            PLAYER.obj.state = 1;
            PLAYER.obj.subState = 0;
            PLAYER.obj.step = 0;
        }
        o->unk68 = 0;
        if (WC2(o) == 0xf0) {
            o->step = 0xf0;
        } else if (WC2(o) == 0xfa) {
            o->step = 0xfa;
        } else {
        reset:
            o->subState = 0;
            o->step = 0;
        }
        break;
    case 0xf0:
        o->anim = 0;
        break;
    case 0xfa:
        o->state = 2;
        break;
    }
}
#undef WC2

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012B008);
void func_8012B008(GameObject *o)
{
    if (o->unkC != 0x28) return;
    switch (o->subState) {
    case 0:
        if (o->unk68) o->subState++;
        if (D_8009C068.event_B9 != 0xff) break;
        if (o->subState != 0) break;
        o->unk88 = 1;
        o->subState = 1;
        o->step = 0x46;
        break;
    case 1:
        func_8012A9BC(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012B0AC);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T8012BD5C_2B0AC;

extern T8012BD5C_2B0AC D_80135120[];

void func_8012B0AC(GameObject *o)
{
    o->hitOffsetX = D_80135120[o->subtype].b0;
    o->hitWidth = D_80135120[o->subtype].b1;
    o->hitOffsetY = D_80135120[o->subtype].b2;
    o->hitHeight = D_80135120[o->subtype].b3;
    o->tpage = D_80135120[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80135120[o->subtype].w6];
    o->anim = D_80135120[o->subtype].anim[0];
    readAnimFrameCount(o);
    o->unkA = 2;
    o->unk8C = 0;
    o->unkD = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->unkF = PLAYER.obj.unkF + 1;
    o->state++;
    *(s32 *)((char *)o + 0x88) = 0;
    if (D_8009C068.event_B9 == 0xff) o->state = 3;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_7", func_8012B22C);
void func_8012B22C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8012B0AC(o);
        break;
    case 1:
        func_80022E44(o);
        if (o->unkC == 0x28) {
            switch (o->subState) {
            case 0:
                if (o->unk68 != 0) {
                    o->subState++;
                }
                if (D_8009C068.event_B9 == 0xff && o->subState == 0) {
                    o->subState = 1;
                    o->unk88 = 1;
                    o->step = 0x46;
                }
                break;
            case 1:
                func_8012A9BC(o);
                break;
            }
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
