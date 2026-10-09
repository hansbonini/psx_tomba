#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003C9D4);
typedef struct { char p0[0x84]; u8 *p84; u8 b88; char p89; u16 w8a; } S_3C9D4;

static __inline__ u8 run_3C9D4(void)
{
    S_3C9D4 *p;
    s32 r;
    u8 x;
    SCRIPT_CTX = &(*(S_3C9D4 *)&D_8009EBA8);
    p = SCRIPT_CTX;
    SCRIPT_CODE = (*(S_3C9D4 *)&D_8009EBA8).p84;
    if ((*(S_3C9D4 *)&D_8009EBA8).b88 == 2 && ++D_8009FD78 >= D_8009FD7C) {
        (*(S_3C9D4 *)&D_8009EBA8).b88 = 1;
    }
    x = p->b88;
    if (x != 1) return x;
    do {
        S_3C9D4 *q = SCRIPT_CTX;
        u8 *b = SCRIPT_CODE;
        u8 c = b[q->w8a];
        if (c < 0x80) {
            r = execCoreOpcode(c);
        } else {
            r = execGameOpcode(c);
        }
    } while (r != 0);
    return p->b88;
}

void func_8003C9D4(void)
{
    if (D_8009CA04 == 0) return;
    if ((*(u16 *)&PLAYER.obj.state) == 0x505) return;
    switch (GAME.selectedArea) {
    case 0:
        switch (D_8009BCCA) {
        case 0 ... 2:
            D_8009C858 = run_3C9D4();
        }
        break;
    case 1:
        switch (D_8009BCCA) {
        case 0 ... 4:
            D_8009C858 = run_3C9D4();
        }
        break;
    case 2:
        switch (D_8009BCCA) {
        case 0 ... 2:
            D_8009C858 = run_3C9D4();
        }
        break;
    case 0x13:
        switch (D_8009BCCA) {
        case 0 ... 1:
            D_8009C858 = run_3C9D4();
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003CE18);
typedef struct { char p0[0x8a]; u16 c; char p1[0x1190 - 0x8c]; s32 idx, k, sub, x, y, z; } G_3CE18;
extern GameObject *allocObjectLayer2(void);

void func_8003CE18(void)
{
    extern void func_800ED1D4(GameObject *o, s32 n);
    G_3CE18 *g = SCRIPT_CTX;
    s32 k = g->k;
    s32 idx = g->idx;
    s32 sub = g->sub;
    s32 x = g->x;
    s32 y = g->y;
    s32 z = g->z;
    switch (k) {
    case 2: case 9: case 10: {
        GameObject *o = allocObjectLayer2();
        if (o == 0) break;
        if (k == 9) o->active = 1; else o->active = 2;
        if (k == 9) o->type = 0x19; else o->type = 0x18;
        o->animFrame = 0;
        o->subtype = sub;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->objectIndex = 0x80;
        o->unkC = idx;
        o->unkD = 0;
        o->unk68 = 0;
        o->unk9C = 0;
        o->unkE = 0;
        o->unkF = 0;
        o->unk74 = 0;
        o->unk76 = 0;
        o->unk94 = 0;
        switch (k) {
        case 9:
            o->unkA = 13;
            func_800ED1D4(o, 1);
            break;
        case 10:
            o->unkA = 0x10;
            o->unkA0 = 0;
            break;
        case 2:
            o->unkA = 2;
            break;
        }
        o->state = 0;
        o->subState = 0;
        o->step = 0;
        SCRIPT_OBJECTS[idx] = o;
        break;
    }
    case 3: {
        GameObject *o = allocObjectLayer3();
        if (o == 0) break;
        o->active = 1;
        o->type = 0x2e;
        o->animFrame = 0;
        o->subtype = sub;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->objectIndex = 0x80;
        o->unkA = 0x10;
        o->unkC = idx;
        o->unkD = 0;
        o->unk68 = 0;
        o->unkF = 0;
        o->unkE = 0;
        o->unk74 = 0;
        o->unk76 = 0;
        o->unk94 = 0;
        o->state = 0;
        o->subState = 0;
        o->step = 0;
        SCRIPT_OBJECTS[idx] = o;
        break;
    }
    case 4: {
        GameObject *o = allocObjectLayer4();
        u8 c;
        if (o == 0) break;
        c = 1;
        o->active = c;
        o->type = 0x1e;
        o->animFrame = 0;
        o->subtype = sub;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->unkA = 2;
        o->unkC = idx;
        o->unkD = 0;
        o->unk68 = 0;
        o->objectIndex = c;
        o->unkF = 0;
        o->unk94 = 0;
        o->state = 0;
        o->subState = 0;
        o->step = 0;
        SCRIPT_OBJECTS[idx] = o;
        break;
    }
    case 5: case 6: case 7: case 8:
        break;
    }
    g->c++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003D0E4);
typedef struct { char pad[0x8a]; u16 w8a; char pad2[0x1190 - 0x8c]; s32 d1190; s32 d1194; s32 d1198; } G_3D0E4;

void func_8003D0E4(void)
{
    G_3D0E4 *g = SCRIPT_CTX;
    GameObject *o;
    s32 b, a;
    o = SCRIPT_OBJECTS[g->d1190];
    a = g->d1194;
    b = g->d1198;
    if (o != 0) {
        o->unk74 = a;
        o->unk76 = b;
        switch (o->type & 0x7f) {
        case 0x18:
            func_80112AA4(o);
            break;
        case 0x19:
            func_800EBDD8(o);
            break;
        case 0x2e:
            func_800E76A8(o);
            break;
        }
    }
    g->w8a++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpKillObject);
void scriptOpKillObject(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8** slot = SCRIPT_OBJECTS + *(s32*)((u8*)p + 0x1190);
    u8*  obj = *slot;
    u8*  other;

    if (obj != NULL) {
        other = *(u8**)(obj + 0x94);
        obj[4] = 3;
        if (other != NULL) {
            other[4] = 3;
        }
        *slot = NULL;
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerPosition);
void scriptOpSetPlayerPosition(void)
{
    PLAYER.obj.h->p.whole = *(s32*)((u8*)SCRIPT_CTX + 0x1190);
    PLAYER.obj.y.p.whole = *(s32*)((u8*)SCRIPT_CTX + 0x1194);
    PLAYER.obj.d->p.whole = *(s32*)((u8*)SCRIPT_CTX + 0x1198);
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerPosition);
void scriptOpGetPlayerPosition(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = PLAYER.obj.h->p.whole;
    *(s32*)((u8*)SCRIPT_CTX + 0x1194) = PLAYER.obj.y.p.whole;
    *(s32*)((u8*)SCRIPT_CTX + 0x1198) = PLAYER.obj.d->p.whole;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpShowMessageBox);
typedef struct {
    char pad0[0x8a];
    u16 w8a;
    char pad1[0x1190 - 0x8c];
    s32 idx;
    u32 cmd;
    s32 a[6];
} S_3D2A8;
typedef struct { s16 v[6]; } V6_3D2A8;
extern u8 D_800A5444[];
extern u8 D_8009BCA7_U8Arr[] asm("D_8009BCA7");
extern s32 showMessageBoxDirect(s32, s32, V6_3D2A8 *);

void scriptOpShowMessageBox(void)
{
    S_3D2A8 *s = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[s->idx];
    V6_3D2A8 tmp;
    u32 cmd = s->cmd;

    if (o != 0) {
        switch (cmd) {
        case 1:
            o->unk6A = 1;
            o->timer = s->a[0];
        case 0:
        case 9:
            o->unk6A = 0;
            o->subState = cmd;
            o->step = 0;
            break;
        case 2:
            o->timer = s->a[0];
            o->velX = s->a[1];
            o->unk6A = 1;
            o->subState = cmd;
            o->step = 0;
            break;
        case 3:
            o->timer = s->a[0];
            o->unk30 = s->a[1];
            o->unk34 = s->a[2];
            o->unk98 = s->a[3];
            o->unk9A = s->a[4];
            o->unk6A = 1;
            o->subState = cmd;
            o->step = 0;
            break;
        case 8:
            tmp.v[1] = s->a[3];
            tmp.v[3] = s->a[4];
            tmp.v[5] = s->a[5];
        case 4:
            if (cmd == 4) tmp = *(V6_3D2A8 *)&o->x;
            o->unk90 = showMessageBoxDirect(s->a[0], s->a[1], &tmp);
            switch (o->type & 0x7f) {
            case 0x18:
                o->unk74 = s->a[2];
                o->unk76 = 0;
                func_80112AA4(o);
                (*(u8 *)&D_8009C618) = 2;
                D_8009BCA7 = 1;
                D_800A539C = 5;
                D_800A539D = 0;
                D_800A539E = 0;
                break;
            case 0x19:
                o->unk68 = 2;
                D_800A5444[0] = 3;
                D_8009C618[0] = 2;
                D_8009BCA7_U8Arr[0] = 1;
                if (s->a[2] & 0x80) {
                    o->unk74 = o->animFrame + (s->a[2] & 0x7f);
                } else {
                    o->animFrame = o->touchFlag - 1;
                    o->unk74 = o->animFrame + s->a[2];
                }
                o->unk76 = 0;
                func_800EBDD8(o);
                {
                    u16 *k = &PLAYER.obj.animFrame;
                    D_800A539C = 1;
                    D_800A539D = 2;
                    D_800A539E = 0;
                    *k |= 8;
                }
                break;
            }
            D_8009BCAA = 1;
            o->unk6A = 1;
            o->subState = 4;
            o->step = 0;
            break;
        case 5:
            {
            s32 ty = o->type & 0x7f;
            if (ty == 0x18) goto L1;
            if (ty == 0x19) {
            L1:
                o->velX = s->a[0];
                o->velY = s->a[1];
            }
            }
            o->unk6A = 1;
            o->subState = cmd;
            o->step = 0;
            break;
        case 6:
            o->unk6A = 0;
            o->subState = cmd;
            o->step = 0;
            break;
        case 7:
            {
            s32 ty = o->type & 0x7f;
            if (ty == 0x18) goto L2;
            if (ty == 0x19) {
            L2:
                o->velX = s->a[0];
                o->velY = s->a[1];
                o->unk78 = s->a[2];
            }
            }
            o->unk6A = 1;
            o->subState = cmd;
            o->step = 0;
            break;
        }
    }
    s->w8a++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjField6A);
void scriptOpGetObjField6A(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x6A);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjPosition);
void scriptOpGetObjPosition(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(s16*)(*(u8**)(obj + 0x40) + 2);
        *(s32*)((u8*)p + 0x1194) = *(s16*)(obj + 0x16);
        *(s32*)((u8*)p + 0x1198) = *(s16*)(*(u8**)(obj + 0x44) + 2);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjectPosition);
void scriptOpSetObjectPosition(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s16*)(*(u8**)(obj + 0x40) + 2) = *(s32*)((u8*)p + 0x1194);
        *(s16*)(obj + 0x16) = *(s32*)((u8*)p + 0x1198);
        *(s16*)(*(u8**)(obj + 0x44) + 2) = *(s32*)((u8*)p + 0x119C);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjFrame);
void scriptOpSetObjFrame(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s16*)(obj + 0x2E) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjFrame);
void scriptOpGetObjFrame(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u16*)(obj + 0x2E);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpIsObjInState2);
void scriptOpIsObjInState2(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = ((obj[4] ^ 2) == 0);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjEnabled);
void scriptOpSetObjEnabled(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x0) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjVisible);
void scriptOpGetObjVisible(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        func_80022E44(obj);
        *(s32*)((u8*)p + 0x1190) = obj[1];
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpWriteFlag);
void scriptOpWriteFlag(void)
{
    ScriptContext* q = SCRIPT_CTX;

    SCRIPT_FLAGS[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpReadFlag);
void scriptOpReadFlag(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = SCRIPT_FLAGS[*(s32*)((u8*)SCRIPT_CTX + 0x1190)];
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjSubtype);
void scriptOpGetObjSubtype(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];
    u8  k;

    if (obj != NULL) {
        k = obj[2] & 0x7F;
        switch (k) {
        case 0x18:
            *(s32*)((u8*)p + 0x1190) = obj[0x68];
            break;
        case 0x19:
            *(s32*)((u8*)p + 0x1190) = obj[0x68];
            break;
        }
    } else {
        *(s32*)((u8*)p + 0x1190) = 0;
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpReadGlobal);
void scriptOpReadGlobal(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = SCRIPT_GLOBALS[*(s32*)((u8*)SCRIPT_CTX + 0x1190)];
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpWriteGlobal);
void scriptOpWriteGlobal(void)
{
    ScriptContext* q = SCRIPT_CTX;

    SCRIPT_GLOBALS[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpLoadBackground);
void scriptOpLoadBackground(void)
{
    ScriptContext* p = SCRIPT_CTX;

    if (D_8009C618[0] != 3) {
        func_800EBD5C(&PLAYER.obj, PLAYER.obj.h->p.whole, PLAYER.obj.y.p.whole);
    }
    *(s32*)((u8*)p + 0x1190) = PLAYER.obj.unk68;
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerField6B);
void scriptOpSetPlayerField6B(void)
{
    ScriptContext* p = SCRIPT_CTX;

    if (D_8009C618[0] != 3) {
        switch (*(s32*)((u8*)p + 0x1190)) {
        case 0:
            PLAYER.obj.objectIndex = 0;
            break;
        case 1:
            PLAYER.obj.objectIndex = 1;
            break;
        default:
            PLAYER.obj.objectIndex = 2;
            break;
        }
    }
    p->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003DB04);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjAnim);
void scriptOpSetObjAnim(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];
    u8  k;
    s32 v;

    if (obj != NULL) {
        k = obj[2] & 0x7F;
        switch (k) {
        case 0x18:
            obj[0xF] = *(s32*)((u8*)p + 0x1194);
            break;
        case 0x19:
        case 0x2E:
            v = *(s32*)((u8*)p + 0x1194);
            obj[0xE] = v;
            switch ((u8)v) {
            case 1:
                *(s8*)(obj + 0xF) = -0xB;
                break;
            case 2:
                *(s8*)(obj + 0xF) = 0x10;
                break;
            }
            break;
        }
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerState);
void scriptOpSetPlayerState(void)
{
    ScriptContext* p = SCRIPT_CTX;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b;

    PLAYER.obj.state = a;
    b = *(s32*)((u8*)p + 0x1194);
    PLAYER.obj.step = 0;
    PLAYER.obj.subState = b;
    switch ((u8)a) {
    case 1:
        D_8009BCA7 = 0;
        PLAYER.obj.active = 1;
        PLAYER.obj.unk9E = 0;
        break;
    case 4:
        switch ((u8)b) {
        case 2:
            D_800A544A = *(s32*)((u8*)p + 0x11A0);
        case 1:
            PLAYER.obj.animFrame = *(s32*)((u8*)p + 0x1198);
            D_800A53B8 = *(s32*)((u8*)p + 0x119C);
            break;
        }
        D_8009BCA7 = 1;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003DCF0);

void func_8003DCF0(void)
{
    u8 *o = SCRIPT_CTX;
    s32 a, b;
    if (D_8009BCA2 == 0)
        return;
    if (D_8009CA04 & 2) {
        PLAYER.obj.state = *(s32 *)(o + 0x1190);
        b = *(s32 *)(o + 0x1194);
        PLAYER.obj.step = 0;
        PLAYER.obj.subState = b;
        switch (PLAYER.obj.state) {
        case 1:
            D_8009BCA7 = 0;
            PLAYER.obj.active = 1;
            PLAYER.obj.unk9E = 0;
            break;
        case 4:
            switch (PLAYER.obj.subState) {
            case 2:
                D_800A544A = *(s32 *)(o + 0x11a0);
            case 1:
                PLAYER.obj.animFrame = *(s32 *)(o + 0x1198);
                D_800A53B8 = *(s32 *)(o + 0x119c);
            }
            D_8009BCA7 = 1;
            break;
        }
    } else {
        a = *(s32 *)(o + 0x1190);
        b = *(s32 *)(o + 0x1194);
        if (a == 9) {
            if (b == 8)
                D_8009BCA6 = 0;
            if (b == 9)
                D_8009BCA6 = 1;
        } else {
            PLAYER.obj.state = a;
            if (PLAYER.obj.state == 5)
                D_8009BCA7 = 1;
            if (PLAYER.obj.state == 1) {
                D_8009BCA7 = 0;
                if (GAME.selectedArea != 0 || D_800A5478 == 0)
                    PLAYER.obj.active = 1;
            }
            PLAYER.obj.subState = b;
            PLAYER.obj.step = 0;
        }
    }
    *(s16 *)(o + 0x8a) += 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerFacing);
void scriptOpSetPlayerFacing(void)
{
    ScriptContext* q = SCRIPT_CTX;

    PLAYER.obj.animFrame = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpAwardEvent);
void scriptOpAwardEvent(void)
{
    ScriptContext* p = SCRIPT_CTX;

    EVENT id = *(s32*)((u8*)p + 0x1190);

    if (*(s32*)((u8*)p + 0x1194) != 0) {
        awardEventProgress(id, 1, 0);
    } else {
        awardEventProgress(id, 0, 0);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetDialogId);
void scriptOpSetDialogId(void)
{
    ScriptContext* q = SCRIPT_CTX;

    D_8009BCAA = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpPlaySound);
void scriptOpPlaySound(void)
{
    ScriptContext* p = SCRIPT_CTX;

    playSFXWithNoteAndVolume(*(s32*)((u8*)p + 0x1190),
                  *(s32*)((u8*)p + 0x1194),
                  *(s32*)((u8*)p + 0x1198));
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpShowMessage);
void scriptOpShowMessage(void)
{
    ScriptContext* p = SCRIPT_CTX;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), MSG_TYPE_INFO);
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerTouchFlag);
void scriptOpGetPlayerTouchFlag(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = PLAYER.obj.touchFlag;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerHitFlag);
void scriptOpGetPlayerHitFlag(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = PLAYER.obj.unk9E;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003E014);
void func_800ED1D4(u8 *a, s32 b);
void func_8003E014(void)
{
    u8 *g = SCRIPT_CTX;
    u8 *p = SCRIPT_OBJECTS[*(s32 *)(g + 0x1190)];
    s32 f = *(s32 *)(g + 0x1194);
    if (p != 0 && p[2] == 0x19) {
        if (f == 0) {
            (*(u8 **)(p + 0x94))[4] = 3;
            *(s32 *)(p + 0x94) = 0;
        } else {
            func_800ED1D4(p, 1);
        }
    }
    (*(s16 *)(g + 0x8a))++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpShowMessage2);
void scriptOpShowMessage2(void)
{
    ScriptContext* p = SCRIPT_CTX;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), MSG_TYPE_INFO);
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetFadeEffect);
void scriptOpSetFadeEffect(void)
{
    ScriptContext* p = SCRIPT_CTX;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b = *(s32*)((u8*)p + 0x1194);

    D_8009BCDD = 0x10;
    D_8009BCA4 = a;
    D_8009BCDE = b;
    asm("");
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGiveItem);
void scriptOpGiveItem(void)
{
    ScriptContext* p = SCRIPT_CTX;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b = *(s32*)((u8*)p + 0x1194);
    s32 c = *(s32*)((u8*)p + 0x1198);

    if (a < 0) {
        if (c != 0) {
            printInfoMessage(0x15, 3);
            playSFX(10);
        }
        increaseMaxHealth();
    } else {
        addItemToInventory(a, b, c);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjTouchFlag);
void scriptOpGetObjTouchFlag(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x69);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjTouchFlag);
void scriptOpSetObjTouchFlag(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x69) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjParam);
void scriptOpSetObjParam(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x9C) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpMoveCamera);
void scriptOpMoveCamera(void)
{
    ScriptContext* temp_s0;

    temp_s0 = SCRIPT_CTX;
    func_800EDE44(&PLAYER.obj, *(s16*)&*(s32*)((u8*)temp_s0 + 0x1190), *(s16*)&*(s32*)((u8*)temp_s0 + 0x1194));
    temp_s0->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetAreaId);
void scriptOpGetAreaId(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_8009C619;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerFieldE2);
void scriptOpGetPlayerFieldE2(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_800A547A;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003E330);
typedef struct { char p0[0x8a]; u16 c; char p1[0x1190-0x8c]; s32 v; } G_3E330;
extern u8 D_8009BCD9;
extern u8 D_8009BCD8[];

void func_8003E330(void)
{
    G_3E330 *g = SCRIPT_CTX;
    u8 m = D_8009BCD9;
    s16 v = ((s16 *)&D_800A5430)[0];
    s32 a = g->v;
    if (v < m) {
        ((s16 *)&D_800A5430)[0] = v + a;
        if (((s16 *)&D_800A5430)[0] > m) ((s16 *)&D_800A5430)[0] = m;
        ((s16 *)&D_800A5432)[0] = ((s16 *)&D_800A5430)[0];
        D_8009BCD8[0] = ((s16 *)&D_800A5430)[0];
        g->v = 0;
    } else {
        g->v = 1;
    }
    g->c++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003E3C4);
void func_8003E3C4(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_8009BCD4;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", opNop);
void opNop(void)
{
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", execGameOpcode);
typedef struct { char pad[0x8a]; u16 w8a; char pad2[0x1190 - 0x8c]; s32 d1190; s32 d1194; s32 d1198; s32 d119c; } G_3E408;
extern s16 D_800A53AC[];

static __inline__ s32 op81_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o;
    s32 b, a;
    a = g->d1194;
    o = SCRIPT_OBJECTS[g->d1190];
    b = g->d1198;
    if (o != 0) {
        o->unk74 = a;
        o->unk76 = b;
        switch (o->type & 0x7f) {
        case 0x18:
            func_80112AA4(o);
            break;
        case 0x19:
            func_800EBDD8(o);
            break;
        case 0x2e:
            func_800E76A8(o);
            break;
        }
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op82_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject **p = &SCRIPT_OBJECTS[g->d1190];
    GameObject *o = *p;
    if (o != 0) {
        o->state = 3;
        if (o->unk94 != 0) ((GameObject *)o->unk94)->state = 3;
        *p = 0;
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op83_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    PLAYER.obj.h->p.whole = g->d1190;
    D_800A53AC[1] = g->d1194;
    PLAYER.obj.d->p.whole = g->d1198;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op84_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    s32 v;
    g->d1190 = PLAYER.obj.h->p.whole;
    g->d1194 = D_800A53AC[1];
    v = PLAYER.obj.d->p.whole;
    (*(s16 *)((char *)g + 0x8a))++;
    g->d1198 = v;
    return 1;
}

static __inline__ s32 op86_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) g->d1190 = o->unk6A;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op87_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) {
        o->h->p.whole = g->d1194;
        o->y.p.whole = g->d1198;
        o->d->p.whole = g->d119c;
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op88_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) {
        g->d1190 = o->h->p.whole;
        g->d1194 = o->y.p.whole;
        g->d1198 = o->d->p.whole;
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op89_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) o->animFrame = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op8a_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) g->d1190 = o->animFrame;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op8b_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) g->d1190 = o->state == 2;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op8c_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) o->active = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op8d_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) {
        func_80022E44(o);
        g->d1190 = o->visible;
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op8e_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    s32 v = SCRIPT_FLAGS[g->d1190];
    (*(s16 *)((char *)g + 0x8a))++;
    g->d1190 = v;
    return 1;
}

static __inline__ s32 op8f_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    SCRIPT_FLAGS[g->d1190] = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op90_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) {
        s32 t = o->type & 0x7f;
        if (t == 0x18) goto l;
        if (t == 0x19) {
        l:
            g->d1190 = o->unk68;
        }
    } else {
        g->d1190 = 0;
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op91_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    s32 v = SCRIPT_GLOBALS[g->d1190];
    (*(s16 *)((char *)g + 0x8a))++;
    g->d1190 = v;
    return 1;
}

static __inline__ s32 op92_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    SCRIPT_GLOBALS[g->d1190] = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op93_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    if (D_8009C618[0] != 3) func_800EBD5C(&PLAYER.obj, PLAYER.obj.h->p.whole, D_800A53AC[1]);
    g->d1190 = PLAYER.obj.unk68;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op94_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if ((D_8009C618[0] != 3 || PLAYER.obj.objectIndex == 1) && o != 0) o->objectIndex = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op95_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) {
        switch (o->type & 0x7f) {
        case 0x18:
            o->unkF = g->d1194;
            break;
        case 0x19:
        case 0x2e:
            {
                s32 c = g->d1194;
                ((u8 *)o)[0xe] = c;
                switch (c & 0xff) {
                case 1: *(s8 *)&o->unkF = -11; break;
                case 2: o->unkF = 0x10; break;
                }
            }
            break;
        }
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op96_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    if (D_8009C618[0] != 3) {
        switch (g->d1190) {
        case 0: PLAYER.obj.objectIndex = 0; break;
        case 1: PLAYER.obj.objectIndex = 1; break;
        default: PLAYER.obj.objectIndex = 2; break;
        }
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op98_3E408(void)
{
    char *p = (char *)SCRIPT_CTX;
    *(s32 *)(p + 0x1190) = PLAYER.obj.unk9E;
    *(s16 *)(p + 0x8a) += 1;
    return 1;
}

static __inline__ s32 op99_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    PLAYER.obj.animFrame = g->d1190;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op9a_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    {
        s32 a = g->d1190;
        if (g->d1194) awardEventProgress(a, 1, 0);
        else awardEventProgress(a, 0, 0);
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op9b_3E408(void)
{
    u8 *p = (u8 *)SCRIPT_CTX;
    *(s32 *)(p + 0x1190) = PLAYER.obj.touchFlag;
    (*(s16 *)(p + 0x8a))++;
    return 1;
}

static __inline__ s32 op9c_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    D_8009BCAA = g->d1190;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op9d_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    printInfoMessage(g->d1190, 2);
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op9e_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    playSFXWithNoteAndVolume(g->d1190, g->d1194, g->d1198);
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 op9f_3E408(void)
{
    u8 *g = (u8 *)SCRIPT_CTX;
    u8 *p = (u8 *)SCRIPT_OBJECTS[*(s32 *)(g + 0x1190)];
    s32 f = *(s32 *)(g + 0x1194);
    if (p != 0 && p[2] == 0x19) {
        if (f == 0) {
            (*(u8 **)(p + 0x94))[4] = 3;
            *(s32 *)(p + 0x94) = 0;
        } else {
            func_800ED1D4((GameObject *)p, 1);
        }
    }
    (*(s16 *)(g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa0_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    D_8009BCDD = 0x10;
    D_8009BCA4 = g->d1190;
    D_8009BCDE = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa2_3E408(void)
{
    char *p = (char *)SCRIPT_CTX;
    s32 a = *(s32 *)(p + 0x1190);
    s32 b = *(s32 *)(p + 0x1194);
    s32 c = *(s32 *)(p + 0x1198);
    if (a < 0) {
        if (c != 0) {
            printInfoMessage(0x15, 3);
            playSFX(10);
        }
        increaseMaxHealth();
    } else {
        addItemToInventory(a, b, c);
    }
    *(u16 *)(p + 0x8a) += 1;
    return 1;
}

static __inline__ s32 opa3_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) g->d1190 = o->touchFlag;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa4_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) o->touchFlag = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa5_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    GameObject *o = SCRIPT_OBJECTS[g->d1190];
    if (o != 0) o->unk9C = g->d1194;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa6_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    func_800EDE44(&PLAYER.obj, (s16)g->d1190, (s16)g->d1194);
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa7_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    g->d1190 = D_8009C619;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opa8_3E408(void)
{
    char *p = (char *)SCRIPT_CTX;
    *(s32 *)(p + 0x1190) = D_800A547A;
    *(u16 *)(p + 0x8a) += 1;
    return 1;
}

static __inline__ s32 opa9_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    u8 m = D_8009BCD9;
    s16 v = ((s16 *)&D_800A5430)[0];
    s32 a = g->d1190;
    if (v < m) {
        ((s16 *)&D_800A5430)[0] = v + a;
        if (((s16 *)&D_800A5430)[0] > m) ((s16 *)&D_800A5430)[0] = m;
        ((s16 *)&D_800A5432)[0] = ((s16 *)&D_800A5430)[0];
        D_8009BCD8[0] = ((s16 *)&D_800A5430)[0];
        g->d1190 = 0;
    } else {
        g->d1190 = 1;
    }
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opaa_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    g->d1190 = D_8009BCD4;
    (*(s16 *)((char *)g + 0x8a))++;
    return 1;
}

static __inline__ s32 opab_3E408(void)
{
    G_3E408 *g = SCRIPT_CTX;
    (*(s16 *)((char *)g + 0x8a))++;
    return 0;
}

static __inline__ s32 op97_3E408(void)
{
    if (D_8009BCA2 == 0) return 0;
    func_8003DCF0();
    return 1;
}

s32 execGameOpcode(u8 op)
{
    s32 r = 0;

    switch (op) {
    case 0xab:
        r = opab_3E408();
        break;
    case 0x80: func_8003CE18(); r = 1; break;
    case 0x81: r = op81_3E408(); break;
    case 0x82: r = op82_3E408(); break;
    case 0x83: r = op83_3E408(); break;
    case 0x84: r = op84_3E408(); break;
    case 0x85: scriptOpShowMessageBox(); r = 1; break;
    case 0x86: r = op86_3E408(); break;
    case 0x87: r = op87_3E408(); break;
    case 0x88: r = op88_3E408(); break;
    case 0x89: r = op89_3E408(); break;
    case 0x8a: r = op8a_3E408(); break;
    case 0x8b: r = op8b_3E408(); break;
    case 0x8c: r = op8c_3E408(); break;
    case 0x8d: r = op8d_3E408(); break;
    case 0x8f: r = op8f_3E408(); break;
    case 0x8e: r = op8e_3E408(); break;
    case 0x90: r = op90_3E408(); break;
    case 0x91: r = op91_3E408(); break;
    case 0x92: r = op92_3E408(); break;
    case 0x93: r = op93_3E408(); break;
    case 0x94: r = op94_3E408(); break;
    case 0x95: r = op95_3E408(); break;
    case 0x96: r = op96_3E408(); break;
    case 0x98: r = op98_3E408(); break;
    case 0x99: r = op99_3E408(); break;
    case 0x9a: r = op9a_3E408(); break;
    case 0x9b: r = op9b_3E408(); break;
    case 0x9c: r = op9c_3E408(); break;
    case 0x9d: r = op9d_3E408(); break;
    case 0x9e: r = op9e_3E408(); break;
    case 0x9f: r = op9f_3E408(); break;
    case 0xa0: r = opa0_3E408(); break;
    case 0xa1: r = op9d_3E408(); break;
    case 0xa2: r = opa2_3E408(); break;
    case 0xa3: r = opa3_3E408(); break;
    case 0xa4: r = opa4_3E408(); break;
    case 0xa5: r = opa5_3E408(); break;
    case 0xa6: r = opa6_3E408(); break;
    case 0xa7: r = opa7_3E408(); break;
    case 0xa8: r = opa8_3E408(); break;
    case 0xa9: r = opa9_3E408(); break;
    case 0xaa: r = opaa_3E408(); break;
    case 0x97:
        r = op97_3E408();
        break;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", lzDecompress);
void lzDecompress(byte *src, byte *dest)
{
    uint length;
    byte offset;
    int next_bitmask;
    src += 4;

    READ32(LZ_FILE_CTRL->size, src);
    READ16(LZ_BITMASK, src);
    LZ_CURRENT_BIT = 0;
    LZ_FILE_CTRL->offset = 0;
     
    do {
        if (((LZ_BITMASK >> LZ_CURRENT_BIT) & 1)) {
            u_char off, len;
            off = *src++;
            len = *src++;
            bcopy(dest - off, dest, len);
            dest += len;
            LZ_FILE_CTRL->offset += len;
        }
        else {
            *dest++ = *src++;
            LZ_FILE_CTRL->offset += 1;
        }
        LZ_CURRENT_BIT++;

        if ( LZ_CURRENT_BIT > 15) next_bitmask = 1;
        else if ( LZ_CURRENT_BIT > 15) next_bitmask = 1;
        else next_bitmask = 0;
        
        if (next_bitmask) {
            READ16(LZ_BITMASK, src);
            LZ_CURRENT_BIT = 0;
        }
    } while (LZ_FILE_CTRL->size > LZ_FILE_CTRL->offset);
    
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", lzDecompressToBuffer);
void lzDecompressToBuffer(char* src, char* dst, char* len)
{
    bzero(dst, len);
    lzDecompress(src, dst);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003F124);
void func_8003F124(void)
{
    switch (GAME.selectedArea) {
        case AREA05_BACCUSVILLAGE:
            func_800EF5B0();
            return;
        case AREA08_BACCUSLAKE:
            func_800F08C0();
            return;
        case AREA11_VILLAGEOFCIVILIZATION:
            func_800F1CA8();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_800F2D84();
            return;
        case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            func_800F428C();
            return;
        case AREA18_VILLAGEOFCIVILIZATIONYCROSSING:
            func_800F448C();
            return;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            func_800F5B4C();
        default:
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", updateObjectsLayer1);
void updateObjectsLayer1(void)
{
    u8* p = &D_800B07D8;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            D_8007D6A4[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0xEC;
    } while (D_1F800198 < 0x4);
}
