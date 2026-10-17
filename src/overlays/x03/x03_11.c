#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012EFFC);


extern void *D_8013837C[];
extern void *D_8013838C[];
extern s32 showMessageBoxDirect(s32, s32, void *);
extern void readAnimFrameCount(GameObject *);
extern void tickAnimation(GameObject *);
extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);
extern void removeItemFromInventory(s32, s32);

static __inline__ void setAnim_2EFFC(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_8012EFFC(GameObject *o)
{
    s32 m, n;
    Fix16 *q;

    switch (o->step) {
    case 0:
        o->unk68 = 0;
        if (D_8009C068.unk727 == 0) o->step = 1;
        else if (D_8009C068.unk727 == 1) o->step = 8;
        else if (D_8009C068.unk727 == 2) o->step = 0x10;
        else if (D_8009C068.unk727 == 4) o->state = 3;
        break;
    case 1:
        if (o->unk68 == 0) break;
        m = 8;
        n = 0;
        q = &o->x;
        o->step++;
        D_8009C068.unk727 = 1;
        goto talk;
    case 2:
        tickAnimation(o);
        { GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        }
        o->step++;
        break;
    case 3:
        tickAnimation(o);
        o->unk90 = showMessageBoxDirect(8, 1, &o->x);
        o->step++;
        break;
    case 4:
        tickAnimation(o);
        { GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        }
        o->step++;
        setEventStarted(EVENT_THETROUBLEDTHIEF, 0, 0);
        o->timer = 300;
        break;
    case 6:
        tickAnimation(o);
        o->unk90 = showMessageBoxDirect(8, 2, &o->x);
        o->step++;
        break;
    case 8:
        if (D_8009BC98.unk10 && D_8009BC98.unk11 == 0x8f) {
            o->step = 10;
            break;
        }
        if (o->unk68 == 0) break;
        m = 8;
        n = 2;
        q = &o->x;
        o->step++;
        goto talk;
    case 10:
        o->step++;
        D_8009C068.unk727 = 2;
        D_8009BC98.unk10 = 0;
        removeItemFromInventory(ITEM_WHATTHETHIEFLOST, 1);
        m = 8;
        n = 3;
        q = &o->x;
        goto talk;
    case 11:
        tickAnimation(o);
        { GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        }
        o->step++;
        break;
    case 12:
        o->step++;
        o->unk90 = showMessageBoxDirect(8, 4, &o->x);
        break;
    case 13:
        tickAnimation(o);
        { GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        }
        o->step++;
        setEventComplete(0xbe, 0);
        o->timer = 300;
        break;
    case 5:
    case 14:
        if (--o->timer == -1) o->step++;
        break;
    case 16:
        if (o->visible == 0) {
            D_8009C068.unk727 = 4;
            o->state = 3;
            break;
        }
        if (o->unk68 == 0) break;
        m = 8;
        n = 4;
        q = &o->x;
        o->step++;
    talk:
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        PLAYER.obj.state = PLAYER_ENTER;
        PLAYER.obj.subState = PLAYER_IDLE;
        PLAYER.obj.step = 0;
        o->unk90 = showMessageBoxDirect(m, n, q);
        o->unkAC = 2;
        o->animFrame = o->unk68 & 1;
        setAnim_2EFFC(o, D_8013837C[0]);
        break;
    case 7:
    case 9:
    case 17:
        tickAnimation(o);
        { GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        }
    case 15:
        PLAYER.obj.state = PLAYER_ACTIVE;
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        PLAYER.obj.subState = PLAYER_IDLE;
        PLAYER.obj.step = 0;
        o->step = 0;
        o->unkAC = 6;
        o->anim = D_8013838C[0];
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012F400);
extern u16 GetClut(s32, s32);

void func_8012F400(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->active = 3;
        o->hitOffsetX = 6;
        o->hitWidth = 0xc;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->tpage = 4;
        o->unkD = 1;
        o->clut = GetClut(0xa0, 0x1e1);
        o->unkAC = 6;
        o->anim = D_8013838C[0];
        o->spriteBank = SCRATCHPAD.sprData[14];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        func_8012EFFC(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012F510);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012F69C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012F808);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012F994);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012FB00);


extern void *D_8013971C[];
extern void *D_8013975C[];

static __inline__ void setAnim_2FB00(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_8012FB00(GameObject *o)
{
    u8 t = o->state;
    switch (t) {
    case 0:
        o->state = t + 1;
        o->active = 3;
        *(s8 *)&o->unkF = -4;
        if (!(D_8009C608.purifiedAreas & 0x10)) {
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0xc;
            o->hitHeight = 0x1c;
            o->tpage = 1;
            o->unkD = 0;
            o->spriteBank = SCRATCHPAD.sprData[2];
            o->unkAC = 0;
            setAnim_2FB00(o, D_8013971C[0]);
        } else {
            o->hitOffsetX = 10;
            o->hitWidth = 0x14;
            o->hitOffsetY = 0x18;
            o->hitHeight = 0x2e;
            o->tpage = 10;
            o->unkD = 1;
            o->clut = GetClut(0xd0, 0x1e2);
            o->spriteBank = SCRATCHPAD.sprData[12];
            o->unkAC = 0;
            setAnim_2FB00(o, D_8013975C[0]);
        }
        break;
    case 1:
        tickAnimation(o);
        func_80022E44(o);
        if (!(D_8009C608.purifiedAreas & 0x10)) {
            if (D_8009C068.event_35 == 0) func_8012F510(o);
            else func_8012F69C(o);
        } else {
            if (D_8009C068.event_35 == 0) func_8012F808(o);
            else func_8012F994(o);
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8012FCE0);


extern u16 D_80135210[];
extern u16 D_80135218[];
extern void freeObjectUnlayered(GameObject *);

#define W1C(o) (*(s16 *)((char *)(o) + 0x1c))

void func_8012FCE0(GameObject *o)
{
    GameObject *pl = &(*(GameObject *)&PLAYER);
    s16 v;

    switch (o->state) {
    case 0:
        if (GAME.purifiedAreas & 2)
            o->state = 2;
        else if (GAME.selectedSection < 2)
            o->state++;
        else
            o->state = 3;
    clr:
        D_8009BC98.unk14 = 0;
        break;
    case 1:
        if (SCRATCHPAD.unk1A4) goto clr;
        switch (o->subState) {
        case 0:
            if (D_8009BC98.unk0A) {
                o->subState++;
                D_8009BC98.unk14 = 0x100;
            }
            break;
        case 1:
            if ((*(GameObject *)&PLAYER).y.p.whole >= -0x153) goto clr;
            if (U8(&(*(GameObject *)&PLAYER), 0xa2) | U8(&(*(GameObject *)&PLAYER), 0xa3)) goto clr;
            if (D_8009BC98.unk0F) goto clr;
            if ((*(GameObject *)&PLAYER).subState == 0x34) goto clr;
            switch ((*(GameObject *)&PLAYER).unk9C) {
            case 0:
                D_8009BC98.unk14 = 0x100;
                break;
            case 1:
                D_8009BC98.unk14 += 8;
                if (D_8009BC98.unk14 > 0x200) D_8009BC98.unk14 = 0x200;
                break;
            case 2:
                D_8009BC98.unk14 += 0x10;
                if (D_8009BC98.unk14 > 0x300) D_8009BC98.unk14 = 0x300;
                break;
            }
            break;
        }
        break;
    case 2:
        switch (o->subState) {
        case 0:
            if (GAME.selectedSection < 4) {
                o->state = 3;
            } else {
                o->clut = 0;
                o->subState++;
            }
            break;
        case 1:
            o->clut = 0;
            W1C(o) = D_80135210[nextRandom() & 3];
            o->tpage = D_80135218[nextRandom() & 3];
            o->subState++;
            break;
        case 2:
            o->clut += W1C(o);
            if (o->clut < -0x300) o->clut = -0x300;
            if ((u16)--o->tpage == 0xffff) {
                o->tpage = 0x32;
                o->clut = 0;
                o->subState++;
            }
            break;
        case 3:
            if ((u16)--o->tpage == 0xffff) o->subState = 1;
            break;
        }
        D_8009BC98.unk16 = 0;
        if (pl->touchFlag == 1) break;
        if (U8(pl, 0xc9))
            v = o->clut >> 1;
        else
            v = o->clut;
        if ((u16)(pl->x.p.whole - 0x514) < 0xb4) {
            if (pl->unk9C && pl->velY > 0x200) pl->velY = 0x200;
            D_8009BC98.unk16 = v;
        }
        if ((u16)(pl->x.p.whole - 0x1012) < 0x226) {
            if (pl->unk9C && pl->velY > 0x200) pl->velY = 0x200;
            D_8009BC98.unk16 = v;
        }
        if ((u16)(pl->x.p.whole - 0x13a3) < 0x85) {
            if (pl->unk9C && pl->velY > 0x200) pl->velY = 0x200;
            D_8009BC98.unk16 = v;
        }
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}
#undef W1C

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8013018C);
typedef struct { s16 x, y, z; u8 st, c; } R_3018C;
extern R_3018C D_80135250[];
extern R_3018C D_80135220[];

static __inline__ GameObject *spawn_3018C(R_3018C *r, GameObject *link)
{
    GameObject *e = allocObjectLayer4();

    if (e) {
        e->active = 1;
        e->type = 0x2e;
        e->unkA = 7;
        e->x.p.whole = r->x;
        e->y.p.whole = r->y;
        e->z.p.whole = r->z;
        e->subtype = r->st;
        e->unkC = r->c;
        e->unk90 = (s32)link;
        return e;
    }
    return 0;
}

void func_8013018C(GameObject *o)
{
    GameObject *p;
    R_3018C *r;

    switch (GAME.selectedSection) {
    case 0:
    case 4:
        r = D_80135250;
        spawn_3018C(r, 0);
        spawn_3018C(r + 1, 0);
        break;
    case 1:
    case 5:
        r = D_80135220;
        p = spawn_3018C(r, 0);
        spawn_3018C(r + 1, p);
        p = spawn_3018C(r + 2, 0);
        spawn_3018C(r + 3, p);
        spawn_3018C(r + 4, p);
        spawn_3018C(r + 5, 0);
        break;
    }
    freeObjectUnlayered(o);
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8013058C);

#define W1C(o) (*(u16 *)&(o)->category)
#define W1E(o) (*(u16 *)&(o)->tpage)
extern GameObject PLAYER__3058C;
GameObject *allocObjectLayer2(void);

static __inline__ void spawn_3058C(GameObject *o, s16 x, s16 y)
{
    GameObject *e = allocObjectLayer2();

    if (e) {
        e->active = 1;
        e->type = 0x28;
        e->unkA = 2;
        e->subtype = o->subtype;
        e->x.p.whole = x;
        e->y.p.whole = y;
        e->z.p.whole = 0;
        e->unk90 = (s32)&W1C(o);
        W1C(o)++;
    }
}

static __inline__ void spawn2_3058C(GameObject *o, u16 *q)
{
    GameObject *e;

    e = allocObjectLayer2();
    if (e == 0)
        return;
    e->active = 1;
    e->type = 0x28;
    e->unkA = 2;
    e->subtype = 2;
    e->animFrame = o->timer;
    o->timer = (o->timer + 1) & 1;
    if (e->animFrame == 0) {
        u16 t = *q;
        e->y.p.whole = -0x7ee;
        e->x.p.whole = t - 0x40;
    } else {
        u16 t = *q;
        e->y.p.whole = -0x85f;
        e->x.p.whole = t + 0x180;
    }
    e->z.p.whole = 0x5a;
    e->unk90 = (s32)&o->tpage;
    o->clut = 0xf0;
    o->tpage++;
    o->subState++;
}

void func_8013058C(GameObject *o)
{
    GameObject *p = &PLAYER__3058C;
    switch (o->state) {
    case 0:
        o->state++;
        W1C(o) = 0;
        o->tpage = 0;
        o->timer = nextRandom() & 1;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if (p->z.p.whole == 0) {
                o->subtype = 3;
                o->subState++;
            } else {
                o->subtype = 2;
                o->subState = 3;
            }
            break;
        case 1:
            if (W1C(o) != 0)
                break;
            if (p->z.p.whole != 0) {
                o->subState = 0;
                break;
            }
            if ((u16)(p->x.p.whole - 0x1086) < 0xbe) {
                if (SCRATCHPAD.unk1F8 & 0xf)
                    break;
                if (!(nextRandom() & 1))
                    break;
                spawn_3058C(o, (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) - 0x40, -0x6cc);
            } else {
                if ((u16)(p->x.p.whole - 0x1144) >= 0xaf)
                    break;
                if (SCRATCHPAD.unk1F8 & 0xf)
                    break;
                if (!(nextRandom() & 1))
                    break;
                spawn_3058C(o, (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) - 0x40, -0x720);
            }
            o->clut = 0xf0;
            o->subState++;
            break;
        case 2:
        case 4:
            if (--o->clut == -1) {
                o->subState = 0;
            }
            break;
        case 3: {
            u16 *q;

            if (W1E(o) >= 2)
                break;
            if (p->z.p.whole != 0x5a) {
                o->subState = 0;
                break;
            }
            q = &(*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2));
            if ((u16)(*q - 0x10a9) >= 0x73)
                break;
            if (SCRATCHPAD.unk1F8 & 0xf)
                break;
            if (!(nextRandom() & 1))
                break;
            spawn2_3058C(o, q);
            break;
        }
        }
        break;
    case 2:
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}
#undef W1C
#undef W1E

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80130900);
typedef struct { u16 x, y; } XY_30900;
extern XY_30900 D_80135260;
extern XY_30900 D_80135264[];
extern XY_30900 D_80135274[];
extern u16 D_80135284[];

#define W1C(o) (*(u16 *)((char *)(o) + 0x1c))

void func_80130900(GameObject *o)
{
    GameObject *pl = &PLAYER;
    GameObject *e;
    u16 x, y;

    switch (o->state) {
    case 0:
        W1C(o) = 0;
        o->state++;
        o->tpage = 0;
        o->timer = 0;
        o->subState = o->subtype * 2;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            o->clut = (nextRandom() & 7) * 8 + 0x14;
            o->subState++;
            break;
        case 1:
            if (W1C(o) >= 2) break;
            if (pl->z.p.whole != 0) break;
            if ((u16)(pl->x.p.whole - 0x3e5) >= 0x98) break;
            if (--o->clut != -1) break;
            x = D_80135260.x;
            y = D_80135260.y;
            goto spawn;
        case 2:
            o->clut = (nextRandom() & 7) * 8 + 1;
            o->subState++;
            break;
        case 3:
            if (W1C(o) >= 2) break;
            if (pl->z.p.whole != 0) break;
            if ((u16)(pl->x.p.whole - 0x834) >= 0x119) break;
            if (--o->clut != -1) break;
            {
                XY_30900 *t;
                x = nextRandom() & 3;
                t = &D_80135264[x];
                x = t->x;
                y = t->y;
            }
            goto spawn;
        case 4:
            o->clut = (nextRandom() & 7) * 8 + 10;
            o->subState++;
            break;
        case 5:
            if (W1C(o) >= 2) break;
            if (pl->z.p.whole != 0) break;
            if ((u16)(pl->x.p.whole - 0x921) >= 0xbd) break;
            if (--o->clut != -1) break;
            {
                XY_30900 *t;
                x = nextRandom() & 3;
                t = &D_80135274[x];
                x = t->x;
                y = t->y;
            }
        spawn:
            e = allocObjectLayer2();
            if (e) {
                e->active = 2;
                e->type = 2;
                e->unkA = 2;
                e->subtype = 2;
                e->unkC = 4;
                e->z.p.whole = 0x3c;
                e->animFrame = 0;
                e->x.p.whole = x;
                e->y.p.whole = y;
                e->unk90 = (s32)&W1C(o);
                W1C(o)++;
            }
            o->timer = (o->timer + 8) & 8;
            o->clut = D_80135284[(nextRandom() & 7) + (o->timer & 0xffff)];
            break;
        }
        break;
    case 2:
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}
#undef W1C

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80130C34);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_30C34;
extern E28_30C34 D_8013534C[];
extern E28_30C34 D_801352A4[];
extern E28_30C34 D_80135314[];
extern GameObject *D_8009E73C[];

void func_80130C34(GameObject *o)
{
    E28_30C34 *p;
    s16 i;
    GameObject *n;
    u16 v = GAME.selectedSection;

    if (v == 2) {
        if (GAME.purifiedAreas & 4) {
            o->state = 3;
            return;
        }
        i = 0;
        p = D_8013534C;
        for (; p->f0 != 0xff; p = &D_8013534C[++i]) {
            n = allocObjectLayer2();
            if (n == 0) continue;
            {
                n->active = 3;
                n->type = 0x32;
                n->unkA = 0;
                n->animFrame = p->f2;
                n->subtype = p->f18;
                n->unkC = p->f1a;
                n->x.p.whole = p->f12;
                n->y.p.whole = p->f14;
                n->z.p.whole = p->f16;
                n->unkB4 = p->f4;
                n->unkB8 = p->f10;
                n->unkBA = p->fe;
                n->unk74 = p->f6;
                n->unk76 = p->f8;
                n->unk78 = p->fa;
                n->unk7A = p->fc;
                n->unk90 = (s32)o;
                SCRIPT_OBJECTS[i] = n;
                n->unk68 = 0;
            }
        }
        return;
    }
    switch (D_8009C068.event_23) {
    case 0:
        if (v) break;
        i = 0;
        p = D_801352A4;
        for (; p->f0 != 0xff; p = &D_801352A4[++i]) {
            if (*(volatile u16 *)&p->f0 & 0x80) {
                n = allocObjectLayer4();
                if (n == 0) continue;
                {
                    n->active = 1;
                    n->type = 0x1a;
                    n->unkA = 0x10;
                    n->animFrame = p->f2;
                    n->subtype = p->f18;
                    n->unkC = p->f1a;
                    n->x.p.whole = p->f12;
                    n->y.p.whole = p->f14;
                    n->z.p.whole = p->f16;
                }
            } else {
                n = allocObjectLayer2();
                if (n) {
                    n->active = 3;
                    n->type = 0x32;
                    n->unkA = 0;
                    n->animFrame = p->f2;
                    n->subtype = p->f18;
                    n->unkC = p->f1a;
                    n->x.p.whole = p->f12;
                    n->y.p.whole = p->f14;
                    n->z.p.whole = p->f16;
                    n->unkB4 = p->f4;
                    n->unkB8 = p->f10;
                    n->unkBA = p->fe;
                    n->unk74 = p->f6;
                    n->unk76 = p->f8;
                    n->unk78 = p->fa;
                    n->unk7A = p->fc;
                    n->unk90 = (s32)o;
                    SCRIPT_OBJECTS[i] = n;
                }
                if (p->fe == 3 && D_8009C068.event_1D) n->state = 3;
            }
        }
        return;
    case 1:
        if (v != 1) break;
        i = 0;
        p = D_80135314;
        for (; p->f0 != 0xff; p = &D_80135314[++i]) {
            if (*(volatile u16 *)&p->f0 & 0x80) {
                n = allocObjectLayer4();
                if (n == 0) continue;
                {
                    n->active = 1;
                    n->type = 0x1a;
                    n->unkA = 0x10;
                    n->animFrame = p->f2;
                    n->subtype = p->f18;
                    n->unkC = p->f1a;
                    n->x.p.whole = p->f12;
                    n->y.p.whole = p->f14;
                    n->z.p.whole = p->f16;
                }
            } else {
                n = allocObjectLayer2();
                if (n == 0) continue;
                {
                    n->active = 2;
                    n->type = 0x32;
                    n->unkA = 0;
                    n->animFrame = p->f2;
                    n->subtype = p->f18;
                    n->unkC = p->f1a;
                    n->x.p.whole = p->f12;
                    n->y.p.whole = p->f14;
                    n->z.p.whole = p->f16;
                    n->unkB4 = p->f4;
                    n->unkB8 = p->f10;
                    n->unkBA = p->fe;
                    n->unk74 = p->f6;
                    n->unk76 = p->f8;
                    n->unk78 = p->fa;
                    n->unk7A = p->fc;
                    n->unk90 = (s32)o;
                    D_8009E73C[0] = n;
                }
            }
        }
        return;
    }
    o->state = 3;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80131194);
extern s32 D_8009E644;
void func_80127D18(s32 a, s32 b, s32 c);

void func_80131194(GameObject *o)
{
    s32 a = (*(s32 *)&SCRIPT_OBJECTS);
    s32 b = D_8009E644;

    switch (o->step) {
    case 0:
        if (D_8009BC98.unk0A != 0 && D_800A53D8[1] >= 0x1b9) {
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk12 = 1;
            (*(GameObject *)&PLAYER).active = 1;
            D_8009C608.playerEquips = 0;
            D_800A53D8[1] = 0x1b8;
            (*(GameObject *)&PLAYER).animFrame = 0;
            (*(GameObject *)&PLAYER).state = 5;
            (*(GameObject *)&PLAYER).subState = 0;
            (*(GameObject *)&PLAYER).step = 0;
            o->step++;
        }
        break;
    case 1:
        if ((*(GameObject *)&PLAYER).touchFlag) {
            D_8009C068.unk58f = 1;
            func_80127D18(a, 0, 0);
            func_80127D18(b, 0, 0);
            o->step++;
        }
        break;
    case 2:
        if (D_8009C068.unk58f == 3) {
            o->clut = 0x3c;
            o->step++;
        }
        break;
    case 3:
        if (--o->clut <= 0) {
            D_8009C068.unk58f = 4;
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8013133C);

typedef struct { s16 v[6]; } V6_3133C;

extern GameObject *D_8009E648;

void func_8013133C(GameObject *o)
{
    GameObject *p = D_8009E648;
    GameObject *q;
    V6_3133C v;

    switch (o->step) {
    case 0:
        if (D_8009C068.event_1D) {
            o->subState = 2;
            o->step = 0;
            break;
        }
        o->step++;
        break;
    case 1:
        if (D_8009BC98.unk0A == 0) break;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        (*(u8 *)&PLAYER) = 1;
        D_800A53C6 = 0;
        D_800A539C = 5;
        D_800A539D = 0;
        D_800A539E = 0;
        setEventStarted(EVENT_ASTORMYPIGBAG, 0, 0);
        o->clut = 200;
        o->step++;
        break;
    case 2:
        if (--o->clut > 0) break;
        v = *(V6_3133C *)&p->x;
        p->unk90 = showMessageBoxDirect(2, 0xf, &v);
        func_80127D18(p, 9, 0);
        o->step++;
        break;
    case 3:
        tickAnimation(p);
        q = (GameObject *)p->unk90;
        if (q->state != 2) break;
        q->state = 3;
        func_80127D18(p, 0, 0);
        setEventComplete(0x1a, 0);
        o->clut = 200;
        o->step = 15;
        break;
    case 15:
        if (--o->clut > 0) break;
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        D_8009BC98.unk0E = 0;
        D_800A544A = 0;
        D_800A539C = 1;
        D_800A539D = 0;
        D_800A539E = 0;
        p->unk68 = 0;
        p->subState = 1;
        p->step = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80131564);

typedef struct { char c[12]; } B12_31564;

#define SPAWN(q, k) { v = *(B12_31564 *)&(q)->x; (q)->unk90 = (s32)showMessageBoxDirect(2, k, &v); }
#define DONE(x) (((GameObject *)(x)->unk90)->state == 2)
#define KILL(x) ((GameObject *)(x)->unk90)->state = 3

void func_80131564(GameObject *o)
{
    GameObject *a = (*(GameObject **)&SCRIPT_OBJECTS);
    GameObject *b = D_8009E644;
    B12_31564 v;

    switch (o->step) {
    case 0:
        SPAWN(b, 4);
        func_80127D18(a, 0, 0);
        o->step++;
        break;
    case 1:
        if (DONE(b)) {
            KILL(b);
            o->clut = 4;
            o->step++;
        }
        break;
    case 2:
        if (--o->clut <= 0) {
            SPAWN(a, 5);
            func_80127D18(a, 3, 0);
            func_80127D18(b, 0, 0);
            o->step++;
        }
        break;
    case 3:
        if (DONE(a)) {
            KILL(a);
            SPAWN(b, 6);
            func_80127D18(a, 0, 0);
            func_80127D18(b, 3, 0);
            o->step++;
        }
        break;
    case 4:
        if (DONE(b)) {
            KILL(b);
            SPAWN(a, 7);
            func_80127D18(a, 3, 0);
            func_80127D18(b, 0, 0);
            o->step++;
        }
        break;
    case 5:
        if (DONE(a)) {
            KILL(a);
            SPAWN(b, 8);
            func_80127D18(a, 0, 0);
            func_80127D18(b, 3, 0);
            o->step++;
        }
        break;
    case 6:
        if (DONE(b)) {
            KILL(b);
            SPAWN(a, 9);
            func_80127D18(a, 3, 0);
            func_80127D18(b, 0, 0);
            o->step++;
        }
        break;
    case 7:
        if (DONE(a)) {
            KILL(a);
            o->clut = 200;
            setEventStarted(EVENT_THEMASTEOFSKIES, 0, 0);
            o->step = 0x10;
        }
        break;
    case 8:
        a->h->p.whole = a->unk30 + (o->clut & 1);
        a->y.p.whole = a->unk34 + (nextRandom() & 1);
        if (--o->clut <= 0) {
            SPAWN(a, 0xa);
            func_80127D18(a, 3, 0);
            func_80127D18(b, 0, 0);
            o->step++;
        }
        break;
    case 9:
        if (DONE(a)) {
            KILL(a);
            a->animFrame = 1;
            a->subState = 2;
            a->step = 0;
            o->step++;
        }
        break;
    case 10:
        if (!a->visible) {
            SPAWN(b, 0xb);
            func_80127D18(b, 3, 0);
            a->state = 3;
            o->step++;
        }
        break;
    case 11:
        if (DONE(b)) {
            KILL(b);
            b->subState = 2;
            b->step = 0;
            o->step++;
        }
        break;
    case 12:
        if (b->h->p.whole < 0x1d0) {
            b->h->p.whole = 0x1d0;
            b->subState = 1;
            b->step = 0;
            o->clut = 0x3c;
            o->step++;
        }
        break;
    case 13:
        if (--o->clut <= 0) {
            SPAWN(b, 0xc);
            func_80127D18(b, 3, 0);
            o->step++;
        }
        break;
    case 14:
        if (DONE(b)) {
            KILL(b);
            b->subState = 2;
            b->step = 0;
            o->step++;
        }
        break;
    case 15:
        PLAYER.obj.animFrame = b->h->p.whole < (*(Fix16 **)&PLAYER.obj.h)->p.whole;
        if (!b->visible) {
            PLAYER.obj.state = PLAYER_ACTIVE;
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            PLAYER.obj.unkB2 = 0;
            PLAYER.obj.subState = PLAYER_IDLE;
            PLAYER.obj.step = 0;
            b->state = 3;
            o->state = 3;
        }
        break;
    case 16:
        if (--o->clut <= 0) {
            o->clut = 0x3c;
            func_80127D18(a, 0, 0);
            a->unk30 = a->h->p.whole;
            a->unk34 = a->y.p.whole;
            o->step = 8;
        }
        break;
    }
}
#undef SPAWN
#undef DONE
#undef KILL

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80131CB0);
extern GameObject PLAYER_GameObject asm("PLAYER");
#define P PLAYER_GameObject
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A539D_U8Arr[] asm("D_800A539D");
extern u8 D_800A539E_U8Arr[] asm("D_800A539E");
extern void func_800EDE44(GameObject *, s32, s32);

void func_80131CB0(GameObject *o)
{
    GameObject *e = (*(GameObject **)&D_8009E73C);

    switch (o->step) {
    case 0: {
        u8 *f = &D_8009C068.unk6aa;
        s16 r;
        if (*f == 1) {
            ((u8*)&D_8009BC98.unk0F)[0] = 1;
            ((u8*)&D_8009BC98.unk12)[0] = 1;
            P.animFrame = 0;
            r = e->h->p.whole < P.h->p.whole;
            D_800A539C_U8Arr[0] = 5;
            D_800A539D_U8Arr[0] = 0x64;
            D_800A539E_U8Arr[0] = 0;
            *f = 2;
            P.animFrame = r;
            o->step++;
            e->subState = 1;
            e->step = 0;
        }
        break;
    }
    case 1:
        o->step++;
    case 2:
        if (D_8009C068.unk590 == 1) {
            func_800EDE44(&P, 0x14, 0);
            o->clut = 0x14;
            o->step++;
        }
        break;
    case 3:
        if (--o->clut <= 0) {
            func_800EDE44(&P, 0x15, 0);
            if (e->h->p.whole < P.h->p.whole) P.velX = -0x200;
            else P.velX = 0x200;
            P.velY = -0x200;
            P.unk9C = 1;
            o->clut = 0x10;
            o->step++;
        }
        break;
    case 4:
        P.d->p.whole += 5;
        P.y.raw += P.velY << 8;
        P.velY += 0x10;
        P.h->raw += P.velX << 8;
        if (P.velX < 0) {
            if (P.h->p.whole < e->h->p.whole) P.h->p.whole = e->h->p.whole;
        } else {
            if (e->h->p.whole < P.h->p.whole) P.h->p.whole = e->h->p.whole;
        }
        if (P.velY > 0) {
            P.unk9C = 2;
            o->step++;
        }
        if (P.d->p.whole >= 0x88) P.d->p.whole = 0x87;
        break;
    case 5:
        P.d->p.whole += 5;
        P.y.raw += P.velY << 8;
        P.velY += 0x10;
        if (P.d->p.whole >= 0x88) P.d->p.whole = 0x87;
        P.h->raw += P.velX << 8;
        if (P.velX < 0) {
            if (P.h->p.whole < e->h->p.whole) P.h->p.whole = e->h->p.whole;
        } else {
            if (e->h->p.whole < P.h->p.whole) P.h->p.whole = e->h->p.whole;
        }
        if (e->y.p.whole - 0x10 < P.y.p.whole) {
            func_800EDE44(&P, 0xd, 0);
            P.animFrame = 0;
            P.h->p.whole = e->h->p.whole;
            P.y.p.whole = e->y.p.whole;
            e->subState = 2;
            e->step = 0;
            o->step++;
        }
        break;
    case 6:
        break;
    }
}
#undef P

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801320D0);

typedef struct { s16 v[6]; } V6_320D0;
extern void addItemToInventory(s32, s32, s32);

void func_801320D0(GameObject *o)
{
    GameObject *p = (*(GameObject **)&SCRIPT_OBJECTS);
    GameObject *q;
    V6_320D0 v;

    switch (o->step) {
    case 0:
        if (D_8009BC98.unk0A == 0) break;
        o->step = 10;
        if (D_8009C068.event_AC) break;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A53C6 = 0;
        D_800A539C = 5;
        D_800A539D = 0;
        D_800A539E = 0;
        setEventStarted(EVENT_THEFIREPIGBAG, 0, 0);
        o->clut = 300;
        o->step = 1;
        break;
    case 1:
        if (--o->clut > 0) break;
        o->step = 11;
        break;
    case 10:
        if (p->unk68 == 0) break;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        (*(u8 *)&PLAYER) = 1;
        D_800A53C6 = 0;
        D_800A539C = 5;
        D_800A539D = 0;
        D_800A539E = 0;
        o->step++;
        if (D_8009C068.unk69c == 0) break;
        v = *(V6_320D0 *)&p->x;
        p->unk90 = showMessageBoxDirect(7, 2, &v);
        func_80127D18(p, 3, 0);
        o->step = 17;
        break;
    case 11:
        p->animFrame = 1;
        v = *(V6_320D0 *)&p->x;
        p->unk90 = showMessageBoxDirect(7, 0, &v);
        func_80127D18(p, 3, 0);
        o->step++;
        break;
    case 12:
        q = (GameObject *)p->unk90;
        if (q->state != 2) break;
        q->state = 3;
        v = *(V6_320D0 *)&p->x;
        p->unk90 = showMessageBoxDirect(7, 1, &v);
        func_80127D18(p, 3, 0);
        o->step++;
        break;
    case 13:
        q = (GameObject *)p->unk90;
        if (q->state != 2) break;
        q->state = 3;
        p->animFrame = 0;
        v = *(V6_320D0 *)&p->x;
        p->unk90 = showMessageBoxDirect(7, 2, &v);
        func_80127D18(p, 3, 0);
        o->step++;
        break;
    case 14:
        {
        GameObject *q = (GameObject *)p->unk90;
        if (q->state != 2) break;
        q->state = 3;
        func_80127D18(p, 0, 0);
        o->clut = 8;
        o->step++;
        }
        break;
    case 15:
        if (--o->clut > 0) break;
        p->animFrame = 1;
        v = *(V6_320D0 *)&p->x;
        p->unk90 = showMessageBoxDirect(7, 3, &v);
        func_80127D18(p, 3, 0);
        o->step++;
        break;
    case 16:
        {
        GameObject *q = (GameObject *)p->unk90;
        if (q->state != 2) break;
        q->state = 3;
        p->animFrame = 0;
        addItemToInventory(ITEM_CHARLESPANTS, 1, 1);
        D_8009C068.unk69c = 1;
        o->clut = 0x3c;
        o->step = 25;
        }
        break;
    case 17:
        q = (GameObject *)p->unk90;
        if (q->state != 2) break;
        q->state = 3;
        o->clut = 2;
        o->step = 25;
        break;
    case 25:
        if (--o->clut > 0) break;
        ((u8*)&D_8009BC98.unk0F)[0] = 0;
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        ((u8*)&D_8009BC98.unk0E)[0] = 0;
        p->animFrame = 1;
        p->unk68 = 0;
        (*(u8 *)&PLAYER) = 1;
        D_800A544A = 0;
        D_800A539C = 1;
        D_800A539D = 0;
        D_800A539E = 0;
        func_80127D18(p, 0, 0);
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8013254C);
void func_8013254C(GameObject *o)
{
    if (GAME.selectedSection == 0) {
        switch (o->subState) {
        case 0:
            func_80131194(o);
            break;
        case 1:
            func_80131564(o);
            break;
        case 2:
            func_8013133C(o);
            break;
        }
    } else if (GAME.selectedSection == 1) {
        if (o->subState == 0) func_80131CB0(o);
    } else {
        func_801320D0(o);
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132610);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8013261C);
void func_8013261C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80130C34(o);
        o->state++;
        if (GAME.selectedSection == 0 && D_8009C068.event_1D == 0) o->subState = 2;
        break;
    case 1:
        if (GAME.selectedSection == 0) {
            switch (o->subState) {
            case 0:
                func_80131194(o);
                break;
            case 1:
                func_80131564(o);
                break;
            case 2:
                func_8013133C(o);
                break;
            }
        } else if (GAME.selectedSection == 1) {
            if (o->subState == 0) func_80131CB0(o);
        } else {
            func_801320D0(o);
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

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132798);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} SP_32798;

extern SP_32798 *D_801353BC;

void func_80132798(GameObject *o)
{
    SP_32798 *p, *list;
    GameObject *e;
    s16 i;

    if (!D_8009C068.event_07 || D_8009C068.unk66d) {
        o->state = 3;
        return;
    }
    list = D_801353BC;
    i = -1;
    while ((p = &list[++i])->f0 != 0xff) {
            if (*(volatile s16 *)&p->f0 & 0x80) {
                e = allocObjectLayer4();
                if (e) {
                    e->type = 0x1a;
                    e->active = 1;
                    e->unkA = 0x10;
                    e->animFrame = p->f2;
                    e->subtype = p->f18;
                    e->unkC = p->f1a;
                    e->x.p.whole = p->f12;
                    e->y.p.whole = p->f14;
                    e->z.p.whole = p->f16;
                }
            } else {
                e = allocObjectLayer2();
                if (e) {
                    do {
                    e->active = 1;
                    e->type = 0x32;
                    e->unkA = 0;
                    e->animFrame = p->f2;
                    e->subtype = p->f18;
                    e->unkC = p->f1a;
                    e->x.p.whole = p->f12;
                    e->y.p.whole = p->f14;
                    e->z.p.whole = p->f16;
                    e->unkB4 = p->f4;
                    e->unkB8 = p->f10;
                    e->unkBA = p->fe;
                    e->unk74 = p->f6;
                    e->unk76 = p->f8;
                    e->unk78 = p->fa;
                    e->unk7A = p->fc;
                    e->unk68 = 0;
                    e->unk90 = (s32)o;
                    } while (0);
                }
            }
    }
}

void func_801329A4(void) {
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801329AC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801329B8);

void func_80132A50(void) {
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132A58);
typedef struct { s16 s0, s2; } S2_32A58;

void func_80132A58(GameObject *o)
{
    if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) != 1) return;
    if ((u16)((*(S2_32A58 **)&PLAYER.obj.h)->s2 - 0xc8e) >= 0x28) return;
    if (PLAYER.obj.y.p.whole != -0x7bb) return;
    switch (D_8009C068.event_AA) {
    case 0:
        o->subState = 1;
        o->step = 0;
        break;
    case 1:
        if (D_8009C608.purifiedAreas & 2) {
            o->subState = 1;
            o->step = 2;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132B04);

void func_80132B04(GameObject *o)
{
    switch (o->step) {
    case 0:
        PLAYER.obj.state = PLAYER_ENTER;
        PLAYER.obj.subState = 100;
        PLAYER.obj.step = 0;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        D_8009BC98.unk0E = 1;
        setEventStarted(EVENT_WHENTHEWINDDIESDOWN, 0, 0);
        o->clut = 200;
        o->step++;
        break;
    case 1:
        if (--o->clut <= 0) o->step = 0xf;
        break;
    case 2:
        PLAYER.obj.state = PLAYER_ENTER;
        PLAYER.obj.subState = 100;
        PLAYER.obj.step = 0;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        D_8009BC98.unk0E = 1;
        setEventComplete(0xaa, 0);
        o->clut = 200;
        o->step = 1;
        break;
    case 0xf:
        PLAYER.obj.state = PLAYER_ACTIVE;
        PLAYER.obj.subState = PLAYER_IDLE;
        PLAYER.obj.step = 0;
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        D_8009BC98.unk0E = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132C88);
void func_80132C88(GameObject *o)
{
    u8 c;

    switch (o->subState) {
    case 0:
        c = (*(u8*)((char*)&PLAYER.obj.unkA0 + 2));
        if (c == 1 && (u16)((*(Fix16 **)&PLAYER.obj.h)->p.whole - 0xc8e) < 0x28 && PLAYER.obj.y.p.whole == -0x7bb) {
            switch (D_8009C068.event_AA) {
            case 0:
                o->subState = 1;
                o->step = 0;
                break;
            case 1:
                if (D_8009C608.purifiedAreas & 2) {
                    o->subState = 1;
                    o->step = 2;
                }
                break;
            }
        }
        break;
    case 1:
        func_80132B04(o);
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132D70);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132D7C);


void func_80132D7C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        break;
    case 1:
        if (D_8009BC98.unk0A == 0) break;
        switch (o->subState) {
        case 0:
            if (U8(&(*(GameObject *)&PLAYER), 0xa2) != 1) break;
            if ((u16)((*(GameObject *)&PLAYER).h->p.whole - 0xc8e) >= 0x28) break;
            if ((*(GameObject *)&PLAYER).y.p.whole != -0x7bb) break;
            switch (D_8009C068.event_AA) {
            case 0:
                o->subState = 1;
                o->step = 0;
                break;
            case 1:
                if (D_8009C608.purifiedAreas & 2) {
                    o->subState = 1;
                    o->step = 2;
                }
                break;
            }
            break;
        case 1:
            func_80132B04(o);
            break;
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

void func_80132EE4(void) {
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132EEC);
void func_80132EEC(GameObject *o)
{
    if (D_8009C068.event_AB != 0xff && D_8009C068.item_42 >= 5) {
        o->subState = 1;
        o->step = 2;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80132F2C);

void func_80132F2C(GameObject *o)
{
    switch (o->step) {
    case 0:
        break;
    case 1:
        if (--o->clut <= 0) o->step = 0xf;
        break;
    case 2:
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        D_8009BC98.unk0E = 1;
        o->clut = 300;
        setEventComplete(0xab, 0);
        o->step = 1;
        break;
    case 0xf:
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        D_8009BC98.unk0E = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133004);

void func_80133004(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (D_8009C068.event_AB == 0xff) break;
        if (D_8009C068.item_42 < 5) break;
        o->subState = 1;
        o->step = 2;
        break;
    case 1:
        switch (o->step) {
        case 1:
            if (--o->clut <= 0) {
                o->step = 0xf;
            }
            break;
        case 2:
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0E = 1;
            o->clut = 300;
            setEventComplete(0xab, 0);
            o->step = 1;
            break;
        case 0:
            break;
        case 0xf:
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            o->subState = 0;
            o->step = 0;
            break;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133138);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133144);

void func_80133144(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        break;
    case 1:
        if (D_8009BC98.unk0A) func_80133004(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801331E4);
typedef struct {
    s16 flags;
    s16 frame;
    s16 wb4;
    s16 w74, w76, w78, w7a;
    s16 wba, wb8;
    s16 x, y, z;
    s16 subtype;
    s16 b0c;
} E_331E4;
extern E_331E4 *D_801353F8;
extern GameObject *allocObjectLayer4(void);
extern GameObject *allocObjectLayer2(void);

void func_801331E4(GameObject *o)
{
    E_331E4 *tbl = D_801353F8;
    E_331E4 *e;
    s16 i;
    GameObject *p;

    for (i = 0, e = tbl; e->flags != 0xff; e = &tbl[++i]) {
        if (*(volatile u16 *)&e->flags & 0x80) {
            p = allocObjectLayer4();
            if (p) {
                p->active = 1;
                p->type = 0x32;
                p->unkA = 0x10;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
            }
        } else {
            p = allocObjectLayer2();
            if (p) {
                p->active = 3;
                p->type = 0x32;
                p->unkA = 0;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
                p->unkB4 = e->wb4;
                p->unkB8 = e->wb8;
                p->unkBA = e->wba;
                p->unk74 = e->w74;
                p->unk76 = e->w76;
                p->unk78 = e->w78;
                p->unk7A = e->w7a;
                p->unk90 = (s32)o;
            }
        }
    }
}

void func_801333BC(void) {
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801333C4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801333D0);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133468);
typedef struct {
    s16 flags;
    s16 frame;
    s16 wb4;
    s16 w74, w76, w78, w7a;
    s16 wba, wb8;
    s16 x, y, z;
    s16 subtype;
    s16 b0c;
} E_33468;
extern E_33468 *D_80135434;

void func_80133468(GameObject *o)
{
    E_33468 *tbl = D_80135434;
    E_33468 *e;
    s16 i;
    GameObject *p;
    s32 k;

    if (D_8009C068.event_24 == 0xff) {
        o->state = 3;
        return;
    }
    for (i = 0, e = tbl; e->flags != 0xff; e = &tbl[++i]) {
        k = e->b0c == 0x28;
        if (k == 0x28 && D_8009C068.event_24 == 0xff) continue;
        if (*(volatile u16 *)&e->flags & 0x80) {
            p = allocObjectLayer4();
            if (p) {
                p->active = 1;
                p->type = 0x32;
                p->unkA = 0x10;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
            }
        } else {
            p = allocObjectLayer2();
            if (p) {
                p->active = 3;
                p->type = 0x32;
                p->unkA = 0;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
                p->unkB4 = e->wb4;
                p->unkB8 = e->wb8;
                p->unkBA = e->wba;
                p->unk74 = e->w74;
                p->unk76 = e->w76;
                p->unk78 = e->w78;
                p->unk7A = e->w7a;
                p->unk90 = (s32)o;
            }
        }
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_8013368C);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133724);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_33724;
extern E28_33724 *D_8013548C;

void func_80133724(GameObject *o)
{
    E28_33724 *base;
    E28_33724 *p;
    s16 i;
    GameObject *n;
    s16 k;

    base = D_8013548C;
    i = 0;
    p = base;

    for (; p->f0 != 0xff; p = &base[++i]) {
        k = p->f1a == 0x28;
        switch (k) {
        case 0x28:
            if (D_8009C068.event_B9 == 0xff) continue;
            break;
        case 0x29:
            if (D_8009C068.event_21 == 0xff) continue;
            break;
        }
        if (*(volatile u16 *)&p->f0 & 0x80) {
            GameObject *m;
            m = allocObjectLayer4();
            if (m == 0) continue;
            m->active = 1;
            m->type = 0x32;
            m->unkA = 0x10;
            m->animFrame = p->f2;
            m->subtype = p->f18;
            m->unkC = p->f1a;
            m->x.p.whole = p->f12;
            m->y.p.whole = p->f14;
            m->z.p.whole = p->f16;
        } else {
            n = allocObjectLayer2();
            if (n == 0) continue;
            n->active = 3;
            n->type = 0x32;
            n->unkA = 0;
            n->animFrame = p->f2;
            if (GAME.selectedSection == 1)
                n->subtype = p->f18 + 1;
            else
                n->subtype = p->f18;
            n->unkC = p->f1a;
            n->x.p.whole = p->f12;
            n->y.p.whole = p->f14;
            n->z.p.whole = p->f16;
            n->unkB4 = p->f4;
            n->unkB8 = p->f10;
            n->unkBA = p->fe;
            n->unk74 = p->f6;
            n->unk76 = p->f8;
            n->unk78 = p->fa;
            n->unk7A = p->fc;
            n->unk90 = (s32)o;
        }
    }
}

void func_8013396C(void) {
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133974);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133980);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133A18);

typedef struct { s16 v[6]; } V6_33A18;
typedef struct { void **p; s32 a, b; } T12_33A18;
extern T12_33A18 D_80135498[];
#define P (*(GameObject *)&PLAYER)
extern u8 D_8009C4A6;
extern s16 D_800A544A_S16Arr[] asm("D_800A544A");
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);

void func_80133A18(GameObject *o)
{
    V6_33A18 v;
    u8 s;

    switch (o->step) {
    case 0:
        s = D_8009C068.event_07;
        if (s != 1) break;
        if (P.d->p.whole != 0x5a) break;
        if ((u16)(P.h->p.whole - 0xc58) >= 0x14) break;
        if ((u16)(P.y.p.whole + 0x6f4) >= 0xa) break;
        if (D_800A539C != 5) break;
        if (D_800A539D != 0xb) break;
        v = *(V6_33A18 *)&o->x;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        D_8009C618[0] = 2;
        D_8009C068.unk66d = 1;
        o->unkBC = o->animFrame;
        o->animFrame = 1;
        o->anim = D_80135498[o->subtype].p[1];
        readAnimFrameCount(o);
        if (D_8009C068.event_97 == s) {
            o->unk90 = showMessageBoxDirect(5, 0, &v);
            o->step = 10;
        } else {
            o->unk90 = showMessageBoxDirect(5, 0, &v);
            o->step = 1;
        }
        break;
    case 1:
        tickAnimation(o);
        {
        GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        o->anim = D_80135498[o->subtype].p[0];
        readAnimFrameCount(o);
        o->velX = -0x180;
        o->velY = -0x400;
        o->step++;
        break;
        }
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (o->velY > 0) o->step++;
        if (!o->visible) o->step = 9;
        break;
    case 3:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole)) {
            o->anim = D_80135498[o->subtype].p[0];
            readAnimFrameCount(o);
            o->velX = -0x180;
            o->velY = -0x400;
            o->step = 2;
        }
        if (!o->visible) o->step = 9;
        break;
    case 9:
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        ((u8*)&D_8009BC98.unk0E)[0] = 0;
        D_800A544A_S16Arr[0] = 0;
        o->animFrame = o->unkBC;
        { u8 *c = &D_8009C068.unk66a; *c = *c + 1; }
        D_1F8001C6 = 0;
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        break;
    case 10:
        tickAnimation(o);
        {
        GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        if (D_8009C4A6 == 0) {
            o->anim = D_80135498[o->subtype].p[0];
            readAnimFrameCount(o);
            v = *(V6_33A18 *)&o->x;
            o->unk90 = showMessageBoxDirect(5, 2, &v);
            o->step = 11;
        } else {
            o->anim = D_80135498[o->subtype].p[0];
            readAnimFrameCount(o);
            v = *(V6_33A18 *)&o->x;
            o->unk90 = showMessageBoxDirect(5, 1, &v);
            o->step = 12;
        }
        break;
        }
    case 11:
        tickAnimation(o);
        {
        GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        o->step = 14;
        break;
        }
    case 12:
        tickAnimation(o);
        {
        GameObject *p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        addItemToInventory(ITEM_CHEESE, 1, 1);
        addItemToInventory(ITEM_CHEESE, 1, 1);
        o->step = 14;
        break;
        }
    case 14:
        o->timer = 200;
        setEventComplete(0x97, 0);
        o->step++;
        break;
    case 15:
        if (--o->timer <= 0) o->step = 1;
        break;
    }
}
#undef P

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80133FD4);
void func_80133FD4(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (D_8009C068.event_07 == 1 && D_8009C068.unk66d == 0) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    case 1:
        func_80133A18(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_80134048);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80134CF8_34048;

extern T80134CF8_34048 D_80135490[];
extern s32 SPR_DATA[];

extern void readAnimFrameCount(GameObject *);

void func_80134048(GameObject *o)
{
    o->hitOffsetX = D_80135490[o->subtype].b0;
    o->hitWidth = D_80135490[o->subtype].b1;
    o->hitOffsetY = D_80135490[o->subtype].b2;
    o->hitHeight = D_80135490[o->subtype].b3;
    o->tpage = D_80135490[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80135490[o->subtype].w6];
    o->anim = D_80135490[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unkD = 1;
    o->clut = 0x780a;
    o->unk8C = 0;
    o->unkF = 0;
    o->unkA = 0;
    o->subState = 0;
    o->category |= 0x80;
    o->state++;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_11", func_801341B0);
void func_801341B0(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80134048(o);
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            if (D_8009C068.event_07 == 1 && D_8009C068.unk66d == 0) {
                o->subState = 1;
                o->step = 0;
            }
            break;
        case 1:
            func_80133A18(o);
            break;
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
