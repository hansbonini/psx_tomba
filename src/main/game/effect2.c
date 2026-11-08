#include "common.h"
#include "game.h"
#include "game/gte.h"


// INCLUDE_ASM("nonmatchings/main/game/effect2", updateImpactEffect);

void updateImpactEffect(GameObject *obj)
{
    u8 s = obj->state;
    s32 d;
    switch (s) {
    case 0:
        obj->tpage = 0x15;
        if (obj->id == 0 || obj->id == 3) {
            obj->tpage = 0x14;
        }
        obj->drawFlags = 0;
        *(s8 *)&obj->priority = -30;
        obj->drawType = DRAW_SPRITE;
        obj->animFrame = 0;
        obj->anim = ((void **)&D_80012194)[obj->id];
        obj->spriteBank = D_1F8002D8[0];
        obj->state++;
        readAnimFrameCount(obj);
        if (obj->id == 2) {
#if REGION != REGION_JP
            obj->drawFlags = 0x80;
            obj->tpage = 0x13;
            obj->anim = (*(void **)&D_800123C8);
#endif
            playSFX(D_8007C840[obj->id]);
        }
        break;
    case 1:
        if (obj->id == 2) {
            obj->visible = 1;
            pushEffectDrawList(obj);
            if (PLAYER.obj.animFrame & 1) d = -14; else d = 14;
            obj->h->p.whole = PLAYER.obj.h->p.whole + d;
#if REGION == REGION_JP
            obj->y.p.whole = PLAYER.obj.y.p.whole;
#else
            obj->y.p.whole = (u16)PLAYER.obj.y.p.whole - 14;
#endif
            if (tickAnimation(obj)) {
                obj->state++;
            }
        } else if (cullAndQueueDraw(obj)) {
            if (tickAnimation(obj)) {
                obj->state++;
            }
        }
        break;
    case 2:
        obj->state = s + 1;
        break;
    case 3:
        freeEffectObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", initMsgBoxA);
void initMsgBoxA(u8* self)
{
    *(void**)(self + 0x24) = &D_80014C94;
    readAnimFrameCount(self);
    self[4] = 1;
    self[5] = 0;
    self[6] = 0;
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", initMsgBoxB);
void initMsgBoxB(u8* self)
{
    *(void**)(self + 0x24) = &D_80014C8C;
    readAnimFrameCount(self);
    self[4] = 1;
    self[5] = 1;
    self[6] = 0;
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002EBC4);
extern void func_80023020(GameObject *);
extern s16 fixedMulCos(s32, s32);
extern s16 fixedMulSin(s32, s32);

void func_8002EBC4(GameObject *obj)
{
    u8 *p;
    s32 f;
    u16 u;
    s32 v;
    u8 st;
    if (obj->visible == 0)
        func_80023020(obj);
    st = obj->subState;
    if (st != 0) {
        if (st != 1)
            return;
    } else
        obj->subState = st + 1;
    p = (u8 *)obj->parent;
    switch ((s16)(obj->animFrame = *(u16 *)(p + 0x2e) & 7)) {
    case 0: case 2:
        obj->rotY = 0x40;
        obj->rotZ = 0xe0;
        break;
    case 1: case 3:
        obj->rotY = 0x40;
        obj->rotZ = 0x20;
        break;
    case 4:
        obj->rotY = 0x60;
        obj->rotZ = 0;
        break;
    case 5:
        obj->rotY = 0x20;
        obj->rotZ = 0;
        break;
    case 6:
        obj->rotY = 0x80;
        obj->rotZ = 0x20;
        break;
    case 7:
        obj->rotY = 0;
        obj->rotZ = 0xe0;
        break;
    }
    obj->x.p.whole = *(s16 *)(p + 0x12) + fixedMulCos((s16)obj->rotY, 8);
    v = obj->rotY;
    obj->y.p.whole = *(s16 *)(p + 0x16) + fixedMulSin((s16)v, 8);
    obj->z.p.whole = *(s16 *)(p + 0x1a);
    if (tickAnimation(obj)) {
        obj->state = 2;
        obj->subState = 0;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002ED1C);

void func_8002ED1C(GameObject *obj)
{
    s32 d;
    obj->rotZ = 0;
    obj->visible = D_800A5399;
    if (D_800A539D == 2 && D_800A5416 >= -0xc7 && D_800A5434 != 0) {
        obj->anim = (*(void **)&D_80014C8C);
        readAnimFrameCount(obj);
#if REGION == REGION_JP
        if (D_800A5416 > 0 && *D_800A53BC[0] == 0x55)
#else
        if (D_800A5416 > 0 && *D_800A53BC[0] == 0x47)
#endif
            obj->rotZ = D_800A5424_S32;
    } else if (D_800A539D == 4 && D_800A5416 >= -0xc7) {
        obj->anim = (*(void **)&D_80014C8C);
        readAnimFrameCount(obj);
        if (D_800A5416 > 0)
            obj->rotZ = D_800A5424_S32;
    } else {
        obj->anim = D_80014C90;
        readAnimFrameCount(obj);
        d = D_800A5424_S32;
        obj->rotZ = (u8)((PLAYER.obj.animFrame & 1) ? d - 0x20 : d + 0x20);
    }
    obj->h->p.whole = ((Fix16 **)&D_800A53D8)[0]->p.whole;
    obj->y.p.whole = D_800A53AE[0] + 4;
    obj->d->p.whole = ((Fix16 **)&D_800A53DC)[0]->p.whole;
    obj->priority = D_800A53A7[0] + 1;
    obj->priority = PLAYER.obj.priority + D_80011F0D[((s8 *)&D_80012014)[*D_800A53BC[0]] * 4];
    if (D_800A5461[0] == 0)
        obj->state = 3;
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", updateStrikeBurst);

void updateStrikeBurst(GameObject *obj)
{
    switch (obj->state) {
    case 0:
        switch (obj->id) {
        case 0:
            obj->anim = ((char *)&D_80014C94);
            readAnimFrameCount(obj);
            setObjState(obj, 1, 0, 0);
            break;
        case 1:
            obj->anim = ((char *)&D_80014C8C);
            readAnimFrameCount(obj);
            setObjState(obj, 1, 1, 0);
            break;
        }
        break;
    case 1:
        cullAndQueueDraw(obj);
        switch (obj->id) {
        case 0:
            func_8002EBC4(obj);
            break;
        case 1:
            func_8002ED1C(obj);
            break;
        }
        break;
    case 2:
        obj->state++;
        break;
    case 3:
        freeEffectObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002F05C);
void func_8002F05C(GameObject *parent, s32 x, s32 y, s32 z)
{
    GameObject *obj = allocEffectObject();
    s32 v;
    if (obj != 0) {
        obj->active = 1;
        obj->type = 0x12;
        obj->animFrame = parent->animFrame;
        obj->x.raw = x << 16;
        obj->y.raw = y << 16;
        obj->z.raw = z << 16;
        obj->tpage = D_8009B6A0->tpage2;
        obj->clut = D_8009B6A0->clut2;
        obj->drawType = DRAW_OVERLAY_8;
        *(s8 *)&obj->priority = -0x1C;
        obj->drawFlags = 1;
        obj->id = 0;
        v = SPAD->sprData[1];
        obj->category |= 0x80;
        obj->unk1D = 0x4d;
        *(GameObject **)&obj->parent = parent;
        obj->spriteBank = v;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002F138);

void func_8002F138(void)
{
    GameObject *obj;
    s32 v;

    if (D_8009C260 != 0 && (obj = allocEffectObject()) != 0) {
        obj->active = 1;
        obj->type = 0x12;
        obj->animFrame = ((u16 *)&PLAYER.obj.animFrame)[0] & 1;
        obj->x.raw = D_800A53A8[0];
        obj->y.raw = D_800A53A8[1];
        obj->z.raw = D_800A53A8[2];
        obj->tpage = 0;
        obj->clut = GetClut(0x80, 499);
        obj->drawFlags = 1;
        obj->drawType = DRAW_OVERLAY_8;
        obj->id = 1;
        obj->priority = D_800A53A7[0] + 1;
        v = D_1F8002CC;
        obj->category |= 0x80;
        obj->unk1D = 0x4d;
        obj->spriteBank = v;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002F220);
void func_8002F220(GameObject *obj)
{
    u8 s = obj->state;
    s16 t;
    switch (s) {
    case 0:
        if (obj->subState != 0) break;
        obj->anim = D_80014CB4;
        readAnimFrameCount(obj);
        obj->x.p.whole = D_800A53AA;
        if (((u16 *)&PLAYER)[2] == 0x405) {
            obj->y.p.whole = -0x24;
        } else if (PLAYER.obj.y.p.whole < -0xf1 && PLAYER.obj.h->p.whole >= 0xf3) {
            obj->y.p.whole = -0xf0;
        } else {
#if REGION == REGION_JP
            obj->y.p.whole = -0x24;
#else
            obj->y.p.whole = -0x28;
#endif
        }
        t = D_800A53B2_U16;
        obj->state = 1;
        obj->subState = 0;
        obj->z.p.whole = t;
        break;
    case 1:
        cullAndQueueDraw(obj);
        switch (obj->subState) {
        case 0:
            obj->subState++;
        case 1:
            obj->h->p.whole = PLAYER.obj.h->p.whole;
            if (PLAYER.obj.y.p.whole < -0xf1 && PLAYER.obj.h->p.whole >= 0xf3) {
                obj->y.p.whole = -0xf0;
            } else {
#if REGION == REGION_JP
                obj->y.p.whole = -0x24;
#else
                obj->y.p.whole = -0x28;
#endif
            }
            obj->d->p.whole = PLAYER.obj.d->p.whole;
            obj->animFrame = PLAYER.obj.animFrame & 1;
            break;
        }
        break;
    case 2:
        obj->state = s + 1;
        break;
    case 3:
        freeEffectObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002F404);

void func_8002F404(GameObject *obj)
{
    u8 t = obj->state;
    s32 x;

    switch (t) {
    case 0:
        if (obj->subState == 0) {
            obj->anim = D_80012354[obj->id];
            readAnimFrameCount(obj);
            x = (*(s16 *)&D_800A53AA);
            if (PLAYER.obj.animFrame & 1) {
                obj->x.p.whole = x + 8;
            } else {
                obj->x.p.whole = x - 8;
            }
            obj->y.p.whole = PLAYER.obj.y.p.whole + 0x10;
            obj->z.p.whole = D_800A53B2[0];
            obj->state = 1;
            obj->subState = 0;
        }
        break;
    case 1:
        cullAndQueueDraw(obj);
        if (obj->visible != 0) {
            switch (obj->subState) {
            case 0:
                obj->subState++;
            case 1:
                if (tickAnimation(obj)) {
                    obj->state = 2;
                }
                break;
            }
        }
        break;
    case 2:
        obj->state = t + 1;
        break;
    case 3:
        freeEffectObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002F56C);
void func_8002F56C(GameObject *obj)
{
    switch (obj->state) {
    case 0:
        if (obj->subState == 0) {
            obj->anim = (D_80012354 + obj->id)[obj->param];
            readAnimFrameCount(obj);
            obj->x.p.whole = ((u16 *)&D_800A53AA)[0];
            obj->y.p.whole = (u16)PLAYER.obj.y.p.whole - 8;
            *(s16 *)((char *)obj + 0x1a) = D_800A53B2[0];
            { u8 t = (*(u8 *)&D_800A53A7);
            obj->state = 1;
            obj->subState = 0;
            obj->priority = t - 1; }
        }
        break;
    case 1:
        cullAndQueueDraw(obj);
        if (obj->visible == 0)
            break;
        switch (obj->subState) {
        case 0:
            obj->timer = 200;
            obj->rotX = 0;
            switch (obj->param) {
            case 0: obj->velX = 0x10; obj->velY = -0x100; obj->rotY = 1; break;
            case 1: obj->velX = 0xe; obj->velY = -0x140; obj->rotY = 2; break;
            case 2: obj->velX = 0x12; obj->velY = -0x180; obj->rotY = 1; break;
            case 3: obj->velX = 0x11; obj->velY = -0x200; obj->rotY = 1; break;
            case 4: obj->velX = 0xf; obj->velY = -0x220; obj->rotY = 2; break;
            case 5: obj->velX = 0x10; obj->velY = -0x240; obj->rotY = 1; break;
            }
            obj->subState++;
        case 1:
            obj->rotX = (obj->rotX + obj->rotY) & 0xff;
            obj->h->p.whole = fixedMulCos(obj->rotX, obj->velX);
            obj->y.raw -= 0x10000;
            if (--obj->timer == 0)
                obj->state = 2;
            break;
        }
        break;
    case 2:
        obj->state++;
        break;
    case 3:
        freeEffectObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", dispatchMsgBoxHandler);
void dispatchMsgBoxHandler(u8* self)
{
    D_8007C848[self[3]]();
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", func_8002F804);
void func_8002F804(GameObject *parent, s16 b, char c)
{
    GameObject *obj = allocEffectObject();
    if (obj != 0) {
        obj->active = 1;
        obj->type = 0x13;
        obj->animFrame = parent->animFrame;
        *(Vec3L *)&obj->x = *(Vec3L *)&parent->x;
        if (b == 0) {
            obj->tpage = 0;
            obj->clut = GetClut(0x80, 0x1f0);
            obj->drawFlags = 0x81;
            obj->spriteBank = D_1F8002CC;
            obj->drawType = DRAW_OVERLAY_8;
            *(s8 *)&obj->priority = -7;
            obj->id = b;
            obj->param = c;
            obj->unk1D = 0x4d;
            *(GameObject **)&obj->parent = parent;
            obj->category |= 0x80;
        } else {
            obj->tpage = 0x14;
            obj->drawFlags = 0;
            obj->spriteBank = D_1F8002D8[0];
            obj->drawType = DRAW_SPRITE_ROTATED;
            obj->id = b;
            obj->param = c;
            obj->priority = D_800A53A7[0] - 1;
            obj->category |= 0x80;
            obj->unk1D = 0x4d;
            *(GameObject **)&obj->parent = parent;
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", clearTalkPose);
extern u8 TALK_POSE;
void func_800EDDDC(u8 *p, s32 a, s32 b);
#if REGION != REGION_JP
void clearTalkPose(void)
{
    u8 *p = &D_800A539A;
    TALK_POSE = 0;
    switch (*p) {
    case 0:
        if (GAME.selectedArea == AREA09_MUSHROOMVILLAGE) func_800EDDDC(p - 2, 0, 0);
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
#endif

// INCLUDE_ASM("nonmatchings/main/game/effect2", updateMessageBox);
typedef struct MessageBox {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 visible;
    /* 0x02 */ u8 type;
    /* 0x03 */ u8 subtype;
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 subState;
    /* 0x06 */ u8 pad6[4];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 padB[4];
    /* 0x0F */ u8 unkF;
    /* 0x10 */ Fix16 x;
    /* 0x14 */ Fix16 y;
    /* 0x18 */ Fix16 z;
    /* 0x1C */ u8 pad1C[2];
    /* 0x1E */ s16 tpage;
    /* 0x20 */ s16 timer;
    /* 0x22 */ s16 blink;
    /* 0x24 */ u8 pad24[8];
    /* 0x2C */ u16 animTimer;
    /* 0x2E */ u16 anchored;
    /* 0x30 */ s32 worldX;
    /* 0x34 */ s32 worldY;
    /* 0x38 */ s32 worldZ;
    /* 0x3C */ u8 pad3C[0x58];
    /* 0x94 */ u16 *script;
    /* 0x98 */ u8 pad98[0x1C];
    /* 0xB4 */ u16 mode;
    /* 0xB6 */ u16 voiceTone;
    /* 0xB8 */ u16 choice;
    /* 0xBA */ s16 lineX;
    /* 0xBC */ s16 lineY;
    /* 0xBE */ s16 left;
    /* 0xC0 */ s16 top;
    /* 0xC2 */ u16 width;
    /* 0xC4 */ u16 height;
    /* 0xC6 */ s16 voice;
    /* 0xC8 */ u16 color;
    /* 0xCA */ u16 slot;
    /* 0xCC */ u16 voiceTimer;
    /* 0xCE */ u16 cursorX;
    /* 0xD0 */ u16 cursorY;
    /* 0xD2 */ s16 closeTimer;
} MessageBox;

static inline void restoreTalkPose(void)
{
#if REGION != REGION_JP
    TALK_POSE = 0;
    switch (PLAYER.obj.type) {
    case 0:
        if (GAME.selectedArea == AREA09_MUSHROOMVILLAGE) {
            func_800EDDDC((u8 *)&PLAYER, 0, 0);
        }
        break;
    case 1:
        func_800E7DF8(&PLAYER, 0, (*(s16 *)&PLAYER.obj.animFrame));
        break;
    case 2:
        func_800E8A30(&PLAYER, 0, (*(s16 *)&PLAYER.obj.animFrame));
        break;
    case 3:
        func_800E8758(&PLAYER, 0, (*(s16 *)&PLAYER.obj.animFrame));
        break;
    }
#endif
}

void updateMessageBox(MessageBox *o)
{
    MATRIX *m = &SPAD->objectMatrix;
    SVECTOR *pos = (SVECTOR *)0x1F800040;
    SVECTOR *zero = (SVECTOR *)0x1F800048;
    DVECTOR *sxy = &SPAD->screenXY;
    MATRIX *w = &SPAD->workMatrix;
    s16 n;
    s32 r;
    s32 xy;
    s32 vy;
    s16 yy;
    s16 d;
    u16 half;
    u16 height;

    switch (o->state) {
    case 0:
        o->color = 0;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        if (++o->blink >= 0x3C) {
            o->blink = 0;
        }
        if (o->voice != -1) {
            if (GAME.selectedArea == 6) {
                D_800B0778 = 4;
            } else {
                D_800B0778 = 0x78;
            }
        }
        switch (o->subState) {
        case 0:
#if REGION == REGION_JP
            if (PAD_PRESSED[0] & SPAD->buttonAttack) {
#else
            if (SPAD->joypad_state & SPAD->buttonJump) {
#endif
                o->timer = 1;
            }
            for (;;) {
                u16 code;

                if (--o->timer != 0) {
                    break;
                }
                o->timer = o->mode;
                code = *o->script++;
                switch ((s16)code) {
                case (s16)MSG_END:
                    o->mode = 0;
                    o->timer = 2;
                    freeMessageGlyphs(o->slot);
                    restoreTalkPose();
                    o->state = 2;
                    break;
                case (s16)MSG_CLOSE:
                    o->mode = 1;
                    o->timer = 2;
                    freeMessageGlyphs(o->slot);
                    restoreTalkPose();
                    o->state = 3;
                    break;
                case (s16)MSG_HALT:
                    o->script--;
                    restoreTalkPose();
                    o->timer = 2;
                    break;
#if REGION != REGION_JP
                case (s16)MSG_POSE:
                    TALK_POSE = *o->script++;
                    S16(o, 0x20) = 1;
                    break;
#endif
                case (s16)MSG_NEWLINE:
                    o->cursorX = 8;
                    o->timer = 1;
                    o->cursorY += 0xD;
                    break;
                case (s16)MSG_CHOICE:
                    o->choice = 1;
                    o->timer = 1;
                    break;
                case (s16)MSG_WAIT:
#if REGION == REGION_JP
                    if (o->mode == 1) {
#else
                    if (o->mode == 2) {
#endif
                        o->timer = 0xB4;
                    }
                    o->subState = 1;
                    break;
                case (s16)MSG_CLEAR:
                    freeMessageGlyphs(o->slot);
                    MESSAGE_SLOTS[o->slot].count = 0;
                    o->cursorX = 8;
#if REGION == REGION_JP
                    o->cursorY = 8;
#else
                    o->cursorY = 6;
#endif
                    o->timer = 1;
                    break;
                case (s16)MSG_BOX:
                    half = o->width >> 1;
                    height = o->height;
                    o->width = *o->script++;
                    o->height = *o->script++;
                    o->cursorX = 8;
#if REGION == REGION_JP
                    o->cursorY = 8;
#else
                    o->cursorY = 6;
#endif
                    o->timer = 1;
                    o->lineX = -(o->width >> 1);
                    o->lineY = -o->height - 0x30;
                    {
                        s16 t = o->left + half;
                        o->left = t + o->lineX;
                    }
                    {
                        s16 t = o->top + height + 0x30;
                        o->top = t + o->lineY;
                    }
                    break;
                case (s16)MSG_MOVE:
                    {
                        s32 dx = *(s16 *)o->script++;
                        s32 dy = *(s16 *)o->script++;
                        o->timer = 1;
                        o->left += dx;
                        o->top += dy;
                    }
                    break;
                case (s16)MSG_DELAY:
                    o->timer = *o->script++;
                    break;
                case (s16)MSG_VOICE:
                    o->voice = *o->script++;
                    o->voiceTone = *o->script++;
#if REGION != REGION_JP
                    if (o->voiceTone == 8) {
                        o->voiceTone = 0xFFFF;
                    }
                    TALK_POSE = 1;
#endif
                    o->timer = 1;
                    break;
                case (s16)MSG_COLOR:
                    o->color = *o->script++;
                    o->timer = 1;
                    break;
                default:
                    n = MESSAGE_SLOTS[o->slot].count++;
                    r = loadMessageGlyph(o->slot, code & 0xFFF, 0);
                    if ((code & 0x7000) == 0x4000) {
                        MESSAGE_GLYPHS[o->slot][n].id = r | 0xC000;
                        MESSAGE_GLYPHS[o->slot][n].x = o->width - 0x10;
                        MESSAGE_GLYPHS[o->slot][n].y = o->height - 0x10;
                        MESSAGE_GLYPHS[o->slot][n].clut = GetClut(0x150, o->color + 0x1F0);
                    } else {
                        MESSAGE_GLYPHS[o->slot][n].id = r | 0x8000;
                        MESSAGE_GLYPHS[o->slot][n].x = o->cursorX;
                        MESSAGE_GLYPHS[o->slot][n].y = o->cursorY;
                        MESSAGE_GLYPHS[o->slot][n].clut = GetClut(0x150, o->color + 0x1F0);
                    }
                    if ((code & 0x7000) == 0x5000) {
                        o->cursorX += GLYPH_CACHE[(s16)r].w;
                        o->timer = 1;
                    } else if ((code & 0x7000) != 0x6000) {
                        o->cursorX += GLYPH_CACHE[(s16)r].w;
                    }
#if REGION != REGION_JP
                    if (SPAD->joypad_state & SPAD->buttonJump) {
                        o->timer = 1;
                    }
#endif
                    if (o->voice != -1) {
                        if (--o->voiceTimer == 0) {
#if REGION == REGION_JP
                            playSFX(D_80075ACC_slps01144[(u16)o->voice]);
#else
                            playSFXWithNote(0xB, (u16)o->voice);
#endif
                            o->voiceTimer = 3;
                        }
                    }
                    break;
                }
            }
            break;
        case 1:
            if (o->choice == 0) {
                switch (o->mode) {
#if REGION == REGION_JP
                case 6:
                case 12:
                    if (SPAD->joypad_state & SPAD->buttonAttack) {
                        o->subState = 0;
                    }
                    break;
                case 1:
                    if (--o->timer == 0 || (SPAD->joypad_state & SPAD->buttonAttack)) {
#else
                case 3:
                case 6:
                    if (SPAD->joypad_state & SPAD->buttonJump) {
                        o->subState = 0;
                    }
                    break;
                case 2:
                    if (--o->timer == 0 || (SPAD->joypad_state & SPAD->buttonJump)) {
#endif
                        o->timer = 1;
                        o->subState = 0;
                    }
                    break;
                }
            } else {
#if REGION == REGION_JP
                if (SPAD->debugNoSaveScreen == 0 && (SPAD->joypad_state & 0x10)) {
#else
                if (SPAD->debugNoSaveScreen == 0 && (SPAD->joypad_state & 0x4000)) {
#endif
                    playSFXWithNote(0xA, 0xA);
                    openMenuScreen(MENU_SCREEN_SAVE);
                    o->mode = 0;
                    o->timer = 2;
                    freeMessageGlyphs(o->slot);
                    o->state = 2;
                    o->subState = 0;
                }
#if REGION == REGION_JP
                if (SPAD->joypad_state & 0x40) {
                    playSFXWithNote(0x1B, 0x1C);
#else
                if (SPAD->joypad_state & 0x2000) {
                    playSFXWithNote(0x1B, 0x1C);
                    o->timer = 1;
#endif
                    o->subState = 0;
                }
            }
            break;
        }
        if (o->anchored != 0) {
            getBaseMatrix(m);
            pos->vx = o->worldX;
            pos->vy = o->worldY;
            pos->vz = o->worldZ;
            MulMatrix0((MATRIX *)D_1F8000C0, m, w);
            ApplyRotMatrix(pos, w->t);
            w->t[0] += SPAD->viewMatrix.t[0];
            w->t[1] += SPAD->viewMatrix.t[1];
            w->t[2] += SPAD->viewMatrix.t[2];
            SetRotMatrix(w);
            SetTransMatrix(w);
            zero->vx = 0;
            zero->vy = 0;
            zero->vz = 0;
            gte_ldv0(zero);
            gte_rtps();
            gte_stsxy(sxy);
            xy = *(s32 *)sxy;
            o->x.p.whole = xy;
            vy = *(s32 *)sxy >> 16;
            o->left = o->x.p.whole + o->lineX;
            o->z.p.whole = 0;
            yy = xy >> 16;
            o->top = yy + o->lineY;
            o->y.p.whole = vy;
        }
#if REGION == REGION_JP
        if (o->left < 0) {
            o->left = 0;
        }
        if (o->top < 0) {
            o->top = 0;
        }
        d = 0x140 - (o->left + o->width);
        if (d < 0) {
            o->left += d;
        }
        d = 0xE0 - (o->top + o->height);
#else
        if (o->left < 8) {
            o->left = 8;
        }
        if (o->top < 8) {
            o->top = 8;
        }
        d = 0x138 - (o->left + o->width);
        if (d < 0) {
            o->left += d;
        }
        d = 0xD8 - (o->top + o->height);
#endif
        if (d < 0) {
            o->top += d;
        }
        MESSAGE_SLOTS[o->slot].x = o->left;
        MESSAGE_SLOTS[o->slot].y = o->top;
        if (MESSAGE_SLOTS[o->slot].count != -1) {
            o->visible = 1;
            pushEffectDrawList(o);
        }
        if (o->closeTimer != -1 && !(--o->closeTimer & 0xFFFF)) {
            freeMessageGlyphs(o->slot);
            restoreTalkPose();
            o->state = 3;
        }
        break;
    case 2:
        break;
    case 3:
        freeEffectObject(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", showMessageBox);
void showMessageBox(s32 arg0, s32 arg1, s16 arg2, s16 arg3)
{
    msgBox box;

    box.unk2 = arg2;
    box.unk6 = arg3;
    box.unkA = 0;
    openMessageBox(arg0, arg1, &box, 0, -1);
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", showMessageBoxTimed);
void showMessageBoxTimed(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4)
{
    msgBox box;

    box.unk2 = arg2;
    box.unk6 = arg3;
    box.unkA = 0;
    openMessageBox(arg0, arg1, &box, 0, arg4);
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", showMessageBoxDirect);
void showMessageBoxDirect(s32 arg0, s32 arg1, s32 arg2)
{
    openMessageBox(arg0, arg1, arg2, 1, -1);
    return;
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", showMessageBoxDirectTimed);
void showMessageBoxDirectTimed(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    openMessageBox(arg0, arg1, arg2, 1, arg3);
    return;
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", openMessageBox);
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
        if (MESSAGE_SLOTS[i].count == -1 && (o = allocEffectObject()) != 0) {
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
#if REGION == REGION_JP
            case 0:
                o->b4 = 12;
                break;
            case 1:
                o->b4 = 6;
                break;
            case 2:
                o->b4 = 1;
                break;
#else
            case 0:
                o->b4 = 6;
                break;
            case 1:
                o->b4 = 3;
                break;
            case 2:
                o->b4 = 2;
                break;
#endif
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
#if REGION == REGION_JP
            o->d0 = 8;
#else
            o->d0 = 6;
#endif
            o->c6 = 0xffff;
            o->ca = i;
            o->cc = 1;
            o->d2 = w;
            o->w20 = 1;
            o->w22 = 0;
            MESSAGE_SLOTS[i].count = 0;
            b = SP398;
#if REGION == REGION_JP
            i = dx;
            v = *(s16 *)(b + k * 2 + 0x10) + i;
#else
            v = *(s16 *)(b + k * 2 + 0x10) + dx;
#endif
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

// INCLUDE_ASM("nonmatchings/main/game/effect2", loadMessageGlyph);


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
        addPrim((*(u_long *)&SCRATCHPAD.ot) + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
    } else {
        load = (DR_LOAD *)D_1F800164;
        setRECT(&rect, GLYPH_CACHE[(s16)freeSlot].u, GLYPH_CACHE[(s16)freeSlot].v, w, h >> 1);
        SetDrawLoad(load, &rect);
        dst = (u16 *)load->p;
        for (j = 0; j < w * (u16)(h >> 1); j++) {
            *dst++ = *src++;
        }
        addPrim((*(u_long *)&SCRATCHPAD.ot) + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
        load = (DR_LOAD *)D_1F800164;
        setRECT(&rect, GLYPH_CACHE[(s16)freeSlot].u, GLYPH_CACHE[(s16)freeSlot].v + (h >> 1), w, h >> 1);
        SetDrawLoad(load, &rect);
        dst = (u16 *)load->p;
        for (j = 0; j < w * (u16)(h >> 1); j++) {
            *dst++ = *src++;
        }
        addPrim((*(u_long *)&SCRATCHPAD.ot) + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
    }
    return freeSlot;
}

// INCLUDE_ASM("nonmatchings/main/game/effect2", freeMessageGlyphs);
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
