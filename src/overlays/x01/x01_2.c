#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011EA14);


typedef struct { Fix16 a, y, b; } FV_1EA14;
extern void *D_8013DA7C[];
extern void *D_8013DA84;
extern char D_8013BA60[];
extern u8 D_8009C1BD[];
extern void readAnimFrameCount(GameObject *);
extern GameObject *allocObjectLayer2(void);
extern void applyItemEffect(char *, FV_1EA14 *, s32, s32, s32);
extern void printInfoMessage(s32, s32);
extern void removeItemFromInventory(s32, s32);
extern void addItemToInventory(s32, s32, s32);

static __inline__ s32 vdiv_1EA14(s32 a, s32 b)
{
    return a / b;
}

static __inline__ void start_1EA14(GameObject *o)
{
    s32 vy, vx;

    o->visible = (*(GameObject *)&PLAYER).visible;
    o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
    o->anim = D_8013DA7C[0];
    o->h->p.whole = (*(GameObject *)&PLAYER).h->p.whole;
    o->y.p.whole = (*(GameObject *)&PLAYER).y.p.whole;
    o->d->p.whole = (*(GameObject *)&PLAYER).d->p.whole;
    *(volatile s16 *)&o->timer = 20;
    vy = vdiv_1EA14(-0x6c00 - (o->y.p.whole << 8), o->timer);
    o->unk8C = 0;
    o->unk30 = 0x20;
    o->unk34 = -0x140;
    vx = vdiv_1EA14(0x79b00 - (o->h->p.whole << 8), 20);
    o->category |= 0x80;
    o->velY = vy;
    o->velX = vx;
    o->unkF = (*(GameObject *)&PLAYER).unkF - 1;
    o->step++;
}

void func_8011EA14(GameObject *o)
{
    GameObject *n;
    FV_1EA14 v;
    s32 t;

    switch (o->step) {
    case 0:
        start_1EA14(o);
        break;
    case 1:
        if (--o->timer > 0)
            break;
        o->timer = 0xf;
        o->step++;
        break;
    case 2:
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->y.raw += o->unk34 << 8;
        o->unk34 += o->unk30;
        if (--o->timer > 0)
            break;
        o->h->p.whole = 0x79b;
        o->y.p.whole = -0x6c;
        o->timer = 20;
        o->step++;
        break;
    case 3:
        if (--o->timer > 0)
            break;
        o->unk8C = 0x100;
        o->timer = 0x40;
        o->step++;
        break;
    case 4:
        t = o->unk8C;
        if (o->animFrame & 1)
            t += 2;
        else
            t -= 2;
        o->unk8C = t & 0xff;
        if (--o->timer > 0)
            break;
        o->anim = D_8013DA84;
        readAnimFrameCount(o);
        o->timer = 0x50;
        n = allocObjectLayer2();
        if (n != 0) {
            n->active = 1;
            n->subtype = 1;
            n->type = 0x22;
            n->x.p.whole = o->x.p.whole;
            n->y.p.whole = o->y.p.whole + 0x20;
            n->z.p.whole = o->z.p.whole;
            D_8009C1BD[0] = 2;
        }
        o->step++;
        break;
    case 5:
        if (--o->timer > 0)
            break;
        v.a.p.whole = o->x.p.whole;
        v.y.p.whole = o->y.p.whole + 0x30;
        v.b.p.whole = o->z.p.whole;
        applyItemEffect(D_8013BA60, &v, 0, 0, 1);
        printInfoMessage(0xf, 2);
        removeItemFromInventory(0x12, 1);
        addItemToInventory(0xa, 1, 0);
        D_8009C068.unk54d = 1;
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        D_8009BC98.unk0E = 0;
        o->state = 3;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011EDF8);
extern void func_8011E600(GameObject *);
extern void func_8011EA14(GameObject *);

void func_8011EDF8(GameObject *o)
{
    if (o->visible == 0) return;
    switch (o->subState) {
    case 0:
        break;
    case 1:
        func_8011E600(o);
        break;
    case 2:
        func_8011EA14(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011EE60);
typedef struct {
    u16 b0, b1, b2, b3, w1e;
    s16 idx;
    void **tab;
} Ent_1EE60;
extern Ent_1EE60 D_8013BA68[];
extern s32 tickAnimation(GameObject *);
extern void freeObjectLayer4(GameObject *);

void func_8011EE60(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->hitOffsetX = D_8013BA68[o->subtype].b0;
        o->hitWidth = D_8013BA68[o->subtype].b1;
        o->hitOffsetY = D_8013BA68[o->subtype].b2;
        o->hitHeight = D_8013BA68[o->subtype].b3;
        o->tpage = D_8013BA68[o->subtype].w1e;
        o->spriteBank = SPR_DATA[D_8013BA68[o->subtype].idx];
        o->anim = *D_8013BA68[o->subtype].tab;
        o->unk8C = 0;
        o->unkD = 0;
        o->category |= 0x80;
        o->unkA = 2;
        readAnimFrameCount(o);
        o->state = 1;
        break;
    case 1:
        func_80022E44(o);
        if (o->visible) {
            switch (o->subState) {
            case 0:
                break;
            case 1:
                func_8011E600(o);
                break;
            case 2:
                func_8011EA14(o);
                break;
            }
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            o->subState = 1;
            break;
        case 1:
            tickAnimation(o);
            break;
        case 2:
            o->subState = 5;
            o->step = 0;
            break;
        case 3:
            o->state = 3;
            break;
        }
        break;
    case 3:
        D_8009C068.unk597 = 0;
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F0CC);

typedef struct { Fix16 x, y, z; } V3_1F0CC;
extern void *D_8013D944[];
extern char D_8013BA98[];
void func_80117CE8(s16 x, s16 y, s16 z);
void func_800322A4(s32 a, s32 x, s32 y, s32 z);
void func_8002367C(s32 a);

void func_8011F0CC(GameObject *o)
{
    V3_1F0CC v;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0xb;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013D944[o->subtype];
        o->hitOffsetX = 0x10;
        o->hitWidth = 0x1c;
        o->hitOffsetY = 0xe;
        o->hitHeight = 0x1c;
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        switch (o->subState) {
        case 0:
            o->subState++;
            func_80022E44(o);
            func_80117CE8(o->h->p.whole, o->y.p.whole, o->d->p.whole);
            func_800322A4(2, o->h->p.whole, o->y.p.whole, o->d->p.whole);
            v.x.p.whole = o->h->p.whole;
            v.y.p.whole = o->y.p.whole;
            v.z.p.whole = o->d->p.whole;
            applyItemEffect(D_8013BA98, &v, 0, 0, 0);
            o->timer = 0x20;
            D_8009C068.unk54e = 4;
            break;
        case 1:
            if (--o->timer == -1) {
                o->subState++;
            } else if ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1) {
                func_80022E44(o);
            }
            break;
        case 2:
            o->state = 3;
            ((GameObject *)o->unk94)->state = 3;
            func_8002367C(o->objectIndex);
            func_8002367C(((GameObject *)o->unk94)->objectIndex);
            break;
        }
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F30C);

extern void func_80022D3C(GameObject *, s32);

void func_8011F30C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (!(D_8009C608.purifiedAreas & 1)) {
            o->state = 3;
            break;
        }
        o->state++;
        o->active = 2;
        if (D_8009C068.event_A4) {
            o->subState = 1;
        } else {
            o->subState = 0;
        }
        break;
    case 1:
        switch (o->subState) {
        case 0:
            switch (o->step) {
            case 0: {
                u8 *c = &D_8009C068.unk721;
                if (*c >= 4) {
                    *c = 5;
                    o->step++;
                }
                break;
            }
            case 1:
                func_80022D3C(o, 0x90);
                break;
            }
            break;
        case 1:
            func_80022D3C(o, 0x90);
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F43C);

extern u8 D_8009C3EC_U8 asm("D_8009C3EC");
extern u8 D_800A38BD[];
extern u8 D_8009C3EC[];
extern void setEventStarted(s32, s32, s32);

void func_8011F43C(GameObject *o)
{
    u8 s;
    GameObject *e;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            o->state++;
            o->hitOffsetX = 0x24;
            o->hitWidth = 0x48;
            o->hitOffsetY = 0x2b;
            o->hitHeight = 0x57;
            o->active = 1;
            o->unk68 = 0;
            if (D_8009C3EC[0] || D_8009C068.event_4D == 0xff) {
                o->unkA0 = (s32)((char **)&D_1F800334)[0] + *(s32 *)((*(char **)&SCRATCHPAD.wmdData[1]) + 0x34);
            }
            break;
        case 1:
        case 2:
            o->state++;
            o->active = 2;
            o->unkF = 8;
            if (D_8009C068.event_4D == 0xff) o->y.p.whole += 0x10;
            else o->y.p.whole += 0x76;
            break;
        case 3:
            o->state++;
            o->unkA = 0x11;
            o->unk88 = 0x40;
            o->active = 2;
            o->unkF = 8;
            o->y.p.whole += 0x10;
            break;
        }
        break;
    case 1:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
            s = o->subState;
            if (s != 0) break;
            if (D_8009C3EC_U8 || D_8009C068.event_4D == 0xff) {
                o->subState = s + 1;
                break;
            }
            if (o->unk68 == 0) break;
            setEventStarted(0x18, 0, 1);
            D_8009C3EC_U8 = 1;
            o->unkA0 = (s32)((char **)&D_1F800334)[0] + *(s32 *)((*(char **)&SCRATCHPAD.wmdData[1]) + 0x34);
            e = allocObjectLayer3();
            if (e != 0) {
                e->type = 0x3d;
                e->active = 1;
                e->subtype = 0;
                e->timer = 0x18;
                e->h->raw = o->h->raw;
                e->y.raw = o->y.raw;
                e->d->raw = o->d->raw;
            }
            o->unk68 = 0;
            o->subState++;
            break;
        case 1:
        case 2:
            s = o->subState;
            switch (s) {
            case 0:
                if (D_800A38BD[0] == 4) {
                    o->unkF = 0;
                    o->subState++;
                }
                break;
            case 1:
                if (D_800A38BD[0] == 7) o->subState = s + 1;
                break;
            case 2:
                o->y.raw += 0x18000;
                break;
            }
            break;
        case 3:
            s = o->subState;
            switch (s) {
            case 0:
                if (D_800A38BD[0] == 4) o->subState = s + 1;
                break;
            case 1:
                o->d->p.whole -= 2;
                if (o->d->p.whole < 0x1037) o->subState++;
                break;
            case 2:
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F82C);

s32 func_8011F82C(GameObject *o)
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F940);



void func_8011F940(GameObject *o)
{
    switch (o->step) {
    case 0:
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        SCRATCHPAD.unk18C = o->h->raw;
        o->timer = 60;
        o->step++;
        break;
    case 1:
        if (--o->timer == -1) {
            o->step++;
        }
        break;
    case 2:
        o->unk74 += 0x80;
        if (o->unk74 > 0x1000) {
            GameObject *p = (GameObject *)o->unk94;
            o->unk74 = 0x1000;
            o->timer = 30;
            o->active = 1;
            o->step++;
            p->unk6A = 1;
            p = (GameObject *)p->unk94;
            p->unk6A = 1;
        }
        o->unk76 = o->unk74;
        o->unk78 = o->unk74;
        break;
    case 3:
        if (--o->timer == -1) {
            o->step = 0;
            o->subState++;
            D_800A38BB[0] = 6;
            D_8009C068.unk5ab = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011FAD0);


struct GSInventory_1FAD0 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1FAD0 { u8 weapon; u8 pants; };

typedef struct GameTask_1FAD0 {
    s16 status;
    s16 sleepTimer;
    s32 task_id;
    s32 task_sp;
    s32 task_func;
    s32 task_gp;
    volatile u16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    u8 unk2f;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
    u8 unk3a;
    u8 unk3b;
    u8 unk3c;
    u8 unk3d;
    u8 unk3e;
    u8 unk3f;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    s16 state0;
    s16 state1;
    s16 mode;
    s16 step;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u16 timer;
    u16 unk5A;
    u16 countdown;
    u16 unk5E;
    s16 unk60;
    s16 unk62;
    u16 unk64;
    u8 unk66;
    u8 unk67;
    u8 loadGameSelected;
    u8 titleScreenSelectedOption;
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
} GameTask_1FAD0;

extern u8 D_8009D6DD_U8Arr[] asm("D_8009D6DD");
extern u8 D_8009D6DE_U8Arr[] asm("D_8009D6DE");
extern u8 D_8009D6DF_U8Arr[] asm("D_8009D6DF");
extern u8 D_8009E3ED_U8Arr[] asm("D_8009E3ED");
extern u8 D_8009E3EE_U8Arr[] asm("D_8009E3EE");
extern u8 D_8009E3EF_U8Arr[] asm("D_8009E3EF");

void func_8011FAD0(GameObject *o)
{
    s16 t;

    switch (o->step) {
    case 0:
        if (o->visible == 0) break;
        if (func_8011F82C(o) == 0) break;
        o->step++;
        (*(GameObject *)&PLAYER).active = 2;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        D_1F80018C = o->h->raw;
        o->timer = 10;
        break;
    case 1:
        if (--o->timer == -1) {
            (*(GameObject *)&PLAYER).active = 5;
            ((u8 *)&D_800A539C)[0] = 5;
            ((u8*)&D_8009BC98.unk0E)[0] = 0;
            (*(GameObject *)&PLAYER).visible = 0;
            ((u8 *)&D_800A539D)[0] = 0x40;
            o->timer = 0x14;
            o->step++;
            ((s16 *)&GAME.nextArea)[0] = 0xe;
            ((s16 *)&GAME.nextSection)[0] = 0;
            ((s16 *)&GAME.nextSpawnPoint)[0] = 0;
        }
        break;
    case 2:
        t = o->timer;
        if (t == 0) {
            GAME.fadeScreenControl = 3;
            ((u8*)&D_8009BC98.unk0C)[0] = 1;
            ((u8*)&SCRATCHPAD.unk3D1)[0] = 1;
            o->step++;
        } else {
            o->timer = t - 1;
        }
        o->unk74 += 0x80;
        if (o->unk74 > 0x4000) {
            o->unk74 = 0x4000;
            o->step++;
        }
        o->unk76 = o->unk74;
        o->unk78 = o->unk74;
        break;
    case 3:
        o->unk74 += 0x80;
        if (o->unk74 > 0x4000) {
            o->unk74 = 0x4000;
        }
        o->unk76 = o->unk74;
        o->unk78 = o->unk74;
        if (GAME.fadeScreenControl == 1) {
            (*(GameTask_1FAD0 **)&D_1F8001D4)->mode = 7;
            (*(GameTask_1FAD0 **)&D_1F8001D4)->step = 0;
            D_8009D6DD_U8Arr[0] = 0xff;
            D_8009D6DE_U8Arr[0] = 0xff;
            D_8009D6DF_U8Arr[0] = 0xff;
            D_8009E3ED_U8Arr[0] = 0xff;
            D_8009E3EE_U8Arr[0] = 0xff;
            D_8009E3EF_U8Arr[0] = 0xff;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011FD7C);


extern char D_8013BAA0[];
extern s16 D_8013BAE0[];
extern void pushDrawListLayer4(GameObject *);

static __inline__ s32 onscreen_1FD7C(GameObject *o)
{
    if (D_8009BC98.unk0A == 0) return 0;
    if ((u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))) >= 0x12d) return 0;
    return (u16)((*(u16 *)&SCRATCHPAD.unk168[7].p.whole) - (o->y.p.whole + 0x10)) < 0xc9;
}

void func_8011FD7C(GameObject *o)
{
    s16 buf[4];
    GameObject *p;
    s32 dx, dy;

    switch (o->state) {
    case 0:
        if (D_8009C068.item_25 == 0 || (D_8009C608.purifiedAreas & 2)) {
            o->state = 3;
            break;
        }
        o->state++;
        o->unkA = 0x13;
        o->unk6A = 0;
        o->active = 2;
        if (o->unkC == 0) {
            buf[0] = 0x80;
            buf[1] = 0x1fe;
            buf[2] = 0x10;
            buf[3] = 2;
            LoadImage(buf, D_8013BAA0);
            o->hitOffsetX = 0x18;
            o->hitWidth = 0x30;
            o->hitOffsetY = 0x18;
            o->hitHeight = 0x32;
        } else {
            o->hitOffsetX = 0xa;
            o->hitWidth = 0x14;
            o->hitOffsetY = 0xe;
            o->hitHeight = 0x36;
        }
        o->unk84 = 0;
        o->unk88 = D_8013BAE0[o->unkC];
        o->unk8C = 0;
        if (D_8009C068.unk5ab == 0) {
            o->subState = 0;
            o->unk74 = 0x800;
            o->unk76 = 0x800;
            o->unk78 = 0x800;
        } else {
            if (o->unkC == 0) {
                o->subState = 2;
                o->active = 1;
            } else {
                o->subState = 1;
                o->active = 2;
            }
            o->unk74 = 0x1000;
            o->unk76 = 0x1000;
            o->unk78 = 0x1000;
        }
        break;
    case 1:
        if (o->unkC != 0) {
            p = (GameObject *)o->unk90;
            if (p->visible == 0) break;
            o->unk74 = p->unk74;
            o->unk76 = p->unk76;
            o->unk78 = p->unk78;
            dx = (s16)(o->unk30 >> 16) * o->unk74;
            dy = (s16)(o->unk34 >> 16) * o->unk74;
            o->h->raw = p->h->raw + (dx << 4);
            o->y.raw = p->y.raw + (dy << 4);
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
                if (onscreen_1FD7C(o)) o->subState++;
                break;
            case 1:
                func_8011F940(o);
                break;
            case 2:
                func_8011FAD0(o);
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_80120174);

extern void pushDrawListLayer7(GameObject *);

void func_80120174(GameObject *o)
{
    switch (o->unkC) {
    case 0:
        o->unkD = 0x80;
        if (o->unk30 < -0x3c0000) o->unk30 = 0x17c0000;
        o->unk30 -= o->animFrame << 4;
        o->x.raw = o->unk30;
        break;
    case 1:
        if (o->unk30 < -0x280000) o->unk30 = 0x1680000;
        o->unk30 -= o->animFrame << 4;
        o->x.raw = o->unk30;
        break;
    case 2:
        o->x.p.whole = (u32)o->unk30 >> 4;
        break;
    case 3:
        o->x.p.whole = (u32)o->unk30 >> 3;
        break;
    case 4:
        o->unkD = 0x80;
        *(s8 *)&o->unkF = -1;
        if (o->unk30 < -0x3c0000) {
            o->unk30 = 0x17c0000;
        } else if (o->unk30 < 0xa0) {
            o->animFrame = 0x800;
        }
        o->unk30 -= o->animFrame << 4;
        o->x.raw = o->unk30;
        break;
    }
    {
        s32 y = o->unk34;
        o->y.p.whole = ((u32)(y - (*(u16 *)&SCRATCHPAD.unk168[7].p.whole)) & 0xfff) >> 4;
    }
    o->visible = 1;
    pushDrawListLayer7(o);
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8012029C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8012042C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_801205D8);
struct GSInventory_205D8 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_205D8 { u8 weapon; u8 pants; };
extern void func_801367F8(s32, s32, s32, s32);
extern void func_80135C0C(s32, s32, s32);

void func_801205D8(GameObject *o)
{
    D_8009E454 = 0;
    if (GAME.baronState == 3)
        func_801367F8(0, o->x.p.whole, o->y.p.whole, o->z.p.whole);
    if (D_8009C068.event_0E != 0xff) {
        if (!(GAME.area00_eventControl & 0x100))
            goto clr;
        if (GAME.selectedSection == 3 || GAME.selectedSection == 1)
            func_80135C0C(o->x.p.whole, o->y.p.whole, o->z.p.whole);
    } else {
        if (!(GAME.area00_eventControl & 0x100))
            goto clr;
        GAME.area00_eventControl &= ~0x100;
    }
    if (!(GAME.area00_eventControl & 0x100)) {
    clr:
        D_8009C068.unk597 = 0;
    }
    if (D_8009C068.event_14 == 0xff && D_8009C068.item_1A != 0)
        removeItemFromInventory(0x1a, 1);
}
