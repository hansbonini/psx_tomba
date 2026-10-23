#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/render/camera", setSpawnAreaFlag);
void setSpawnAreaFlag(void)
{
    u8*  row = D_8007C110[GAME.selectedArea] + D_8009BCCA * 2;
    u16* dst = (u16*)((u8*)&GAME + 0x964 + row[0] * 2);

    *dst |= 1 << row[1];
}


// INCLUDE_ASM("nonmatchings/main/render/camera", loadSpawnPosition);
void loadSpawnPosition(u8* self)
{
    s16* row = (s16*)((u8*)D_8007BF78[GAME.selectedArea][GAME.selectedSection] + (u16)D_8009BCEA * 8);

    *(int*)(self + NTSC_J(0xEC, 0xDC)) = *row++ << 16;
    *(int*)(self + NTSC_J(0xF0, 0xE0)) = *row << 16;
    *(int*)(self + NTSC_J(0xF4, 0xE4)) = row[1] << 16;
    switch (GAME.selectedArea) {
    case 0:
        if (D_8009C617 == 0 && GAME.selectedSection == 0) {
            *(s16*)(self + NTSC_J(0xEE, 0xDE)) = 0x40;
        } else if (GAME.selectedSection == 3) {
            *(s16*)(self + NTSC_J(0xEE, 0xDE)) = 0xD2;
        }
        break;
    case 2:
        if (GAME.selectedSection == 4) {
            *(s16*)(self + NTSC_J(0xEE, 0xDE)) = 0x90;
        }
        break;
    case 4:
        if (GAME.selectedSection == 0xF) {
            *(s16*)(self + NTSC_J(0xEE, 0xDE)) = 0x90;
        }
        break;
    case 10:
        if (GAME.selectedSection == 8) {
            *(s16*)(self + NTSC_J(0xEE, 0xDE)) = 0x90;
        }
        break;
    }
}


// INCLUDE_ASM("nonmatchings/main/render/camera", initPlayerAtSpawn);
void initPlayerAtSpawn(void)
{
    u8* p = &PLAYER.obj;
    s16* row;
    u_int flags;
    u_int plane;

    p[0] = 3;
    if ((CURRENT_TASK)->loadGameSelected != 0) {
        D_8009C618[0] = 4;
        if (*(u_long*)&GAME.selectedArea == 0x20000) {
            D_8009BCEA = 2;
        }
    }
    row = (s16*)((u8*)D_8007BF78[GAME.selectedArea][GAME.selectedSection] + (u16)D_8009BCEA * 8);
    *(int*)(p + 0x10) = *row++ << 16;
    *(int*)(p + 0x14) = *row++ << 16;
    *(int*)(p + 0x18) = *row << 16;
    flags = (u16)row[1];
    plane = flags >> 8;
    flags &= 1;
    SPAD->unk1C8 = flags;
    GAME.area00_fogControl = plane;
    if (flags == 0) {
        *(u8**)(p + 0x40) = p + 0x10;
        *(u8**)(p + 0x44) = p + 0x18;
    } else {
        *(u8**)(p + 0x44) = p + 0x10;
        *(u8**)(p + 0x40) = p + 0x18;
    }
    GAME.selectedPlane = (s16)(*(u16**)(p + 0x44))[1] / 90;
    {
        u8*  r = D_8007C110[GAME.selectedArea] + GAME.selectedSection * 2;
        u16* dst = (u16*)((u8*)&GAME + 0x964 + r[0] * 2);

        *dst |= 1 << r[1];
    }
    if (D_8009C618[0] == 3 || D_8009C617 == 0) {
        loadSpawnPosition(p);
        *(s16*)(p + 0x12) = *(u16*)(p + NTSC_J(0xEE, 0xDE));
        *(s16*)(p + 0x16) -= 0x104;
    } else if ((CURRENT_TASK)->loadGameSelected != 0) {
        (CURRENT_TASK)->loadGameSelected = 0;
        *(VEC3*)&PLAYER.obj.x = D_8009C61C;
    }
}

// INCLUDE_ASM("nonmatchings/main/render/camera", loadSectionBounds);
void loadSectionBounds(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x2C) = *row++;
    *(u16*)(self + 0x2E) = *row++;
    *(u16*)(self + 0x30) = *row;
    *(u16*)(self + 0x32) = row[1];
}

// INCLUDE_ASM("nonmatchings/main/render/camera", loadSectionHeight);
void loadSectionHeight(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x32) = row[3];
}

// INCLUDE_ASM("nonmatchings/main/render/camera", func_800246B0);


typedef struct { s16 a, b, c, d; } S4_246B0;
typedef struct {
    u8 b0; char p1[7]; Vec3L pos; char p14[0x20 - 0x14]; s32 d20; s32 d24;
    char p28[0x2c - 0x28]; s16 w2c, w2e, w30, w32; s32 *p34; char p38[0x78 - 0x38]; s32 d78; s32 d7c;
} C_246B0;
typedef struct { char p[0x4c]; u16 w4c; } O_246B0;
extern void func_8002A0A0(C_246B0 *);
#define FLAG (SPAD->unk1C8)
#define SFLAG ((*(s16 *)&SPAD->unk1C8))

static __inline__ s32 smax_246B0(s32 a, s16 b) { s16 r = a; asm("" : "=r"(r) : "0"(r)); if (a < b) r = b; return r; }
static __inline__ s32 smin_246B0(s32 a, s16 b) { register s16 r asm("$4") = a; if ((s16)a > b) r = b; return r; }

void func_800246B0(void)
{
    C_246B0 *c;
    s16 *p, *q;
    s32 off, x, v;
    u16 w;
    char pad[0x10];
    c = &CAMERA_SCROLL;
    c->b0 = 1;
    p = (s16 *)&((S4_246B0 **)&D_8007B680)[((u16 *)&GAME)[0]][D_8009BCCA];
    D_800A38E4 = *p++;
    D_800A38E6 = *p++;
    D_800A38E8 = *p++;
    D_800A38EA = *p;
    if (!(FLAG & 1)) {
        D_800A38EC = &((s32*)&SCRATCHPAD.vrx.raw)[3];
        D_800A38F0 = &((s32*)&SCRATCHPAD.vrx.raw)[5];
    } else {
        D_800A38F0 = &((s32*)&SCRATCHPAD.vrx.raw)[3];
        D_800A38EC = &((s32*)&SCRATCHPAD.vrx.raw)[5];
    }
    ((s32*)&SCRATCHPAD.vrx.raw)[0] = 0;
    ((s32*)&SCRATCHPAD.vrx.raw)[1] = 0;
#if REGION == REGION_JP
    ((s32*)&SCRATCHPAD.vrx.raw)[2] = 0xFDE00000;
#else
    if ((((u16 *)&GAME)[0] == 4 && D_8009BCCA < 4) || *(s32 *)((u16 *)&GAME) == 0x50000)
        ((s32*)&SCRATCHPAD.vrx.raw)[2] = 0xFDC00000;
    else
        ((s32*)&SCRATCHPAD.vrx.raw)[2] = 0xFDE00000;
#endif
    q = D_8007BF78[((u16 *)&GAME)[0]][D_8009BCCA];
    w = (*(O_246B0 **)&D_1F8001D4)->w4c;
    q += (*(u16 *)&D_8009BCEA) * 4;
    switch (w) {
    case 1: case 2:
        off = -0x38;
        break;
    case 4: case 5: case 6:
        off = 0;
        break;
    }
    if (!(FLAG & 1)) {
        ((s32*)&SCRATCHPAD.vrx.raw)[3] = smax_246B0(*q++, c->w2c) << 16;
        { register s32 t asm("$2"); t = smin_246B0((u16)*q++ + off, c->w32) << 16; ((s32*)&SCRATCHPAD.vrx.raw)[4] = t; }
        ((s32*)&SCRATCHPAD.vrx.raw)[5] = *q << 16;
    } else {
        ((s32*)&SCRATCHPAD.vrx.raw)[3] = *q++ << 16;
        { register s32 t asm("$2"); t = smin_246B0((u16)*q++ + off, c->w32) << 16; ((s32*)&SCRATCHPAD.vrx.raw)[4] = t; }
        ((s32*)&SCRATCHPAD.vrx.raw)[5] = smax_246B0(*q, c->w2c) << 16;
    }
    x = SPAD->vpy.p.whole;
    asm("");
    v = c->w30;
    if (x < v || (v = c->w32, v < x))
        ((s32*)&SCRATCHPAD.vrx.raw)[4] = v << 16;
    { register s32 *pp asm("$4") = c->p34;
    v = c->w2e;
    if (v < ((Vec2s *)pp)->y || (v = c->w2c, ((Vec2s *)pp)->y < v))
        *pp = v << 16; }
    if (D_8009C068.disableSelectMenu) {
        c->d20 = 0x1000;
        if (FLAG & 1) c->d24 = -0x1000;
        else c->d24 = 0x1000;
        c->d78 = 0;
        c->d7c = SFLAG * 0x5A00;
    } else {
        c->d20 = 0;
        c->d24 = 0;
        c->d78 = 0;
        c->d7c = SFLAG * 0x5A00;
    }
    func_8002A0A0(c);
    ((s32*)&SCRATCHPAD.unk168[3].raw)[0] = c->pos.x;
    ((s32*)&SCRATCHPAD.unk168[3].raw)[1] = c->pos.y;
    ((s32*)&SCRATCHPAD.unk168[3].raw)[2] = c->pos.z;
    ((s32*)&SCRATCHPAD.unk168[3].raw)[3] = c->pos.x;
    ((s32*)&SCRATCHPAD.unk168[3].raw)[4] = c->pos.y + ((s32*)&SCRATCHPAD.vrx.raw)[1];
    ((s32*)&SCRATCHPAD.unk168[3].raw)[5] = c->pos.z;
}
#undef FLAG
#undef SFLAG

// INCLUDE_ASM("nonmatchings/main/render/camera", copyMatrix32);
void copyMatrix32(s32* src, s32* dst)
{
    s32 a, b, c, d;

    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    a = src[4];
    b = src[5];
    c = src[6];
    d = src[7];
    dst[4] = a;
    dst[5] = b;
    dst[6] = c;
    dst[7] = d;
}

void getBaseMatrix(MATRIX* dst)
{
    *dst=*SCRATCH_BASE_MATRIX;
    return;
}


// INCLUDE_ASM("nonmatchings/main/render/camera", initLighting);
void initLighting(u8* self)
{
    ((LightEnv*)self)->rotX = 0x638;
    ((LightEnv*)self)->rotY = 0x800;
    ((LightEnv*)self)->rotZ = 0;
    ((LightEnv*)self)->color = *SCRATCH_BASE_MATRIX;
    ((LightEnv*)self)->color.m[0][0] = 0xD00;
    ((LightEnv*)self)->color.m[1][0] = 0xD00;
    ((LightEnv*)self)->color.m[2][0] = 0xD00;
    ((LightEnv*)self)->backR = 0xC0;
    ((LightEnv*)self)->backG = 0xC0;
    ((LightEnv*)self)->backB = 0xC0;
    applyLighting(self);
}

// INCLUDE_ASM("nonmatchings/main/render/camera", applyLighting);
void applyLighting(u8* self)
{
    SVECTOR v;
    VECTOR out;
    MATRIX* m = &((LightEnv*)self)->light;

    SetFarColor(255, 255, 255);
    SetBackColor(((LightEnv*)self)->backR, ((LightEnv*)self)->backG, ((LightEnv*)self)->backB);
    SetColorMatrix(&((LightEnv*)self)->color);
    *m = *SCRATCH_BASE_MATRIX;
    RotMatrixX(((LightEnv*)self)->rotX, m);
    RotMatrixY(((LightEnv*)self)->rotY, m);
    v.vx = 0;
    v.vy = 0x1000;
    v.vz = 0;
    ApplyMatrix(m, &v, &out);
    m->m[0][0] = out.vx;
    m->m[0][1] = out.vy;
    m->m[0][2] = out.vz;
    m->m[1][0] = 0;
    m->m[1][1] = 0;
    m->m[1][2] = 0;
    m->m[2][0] = 0;
    m->m[2][1] = 0;
    m->m[2][2] = 0;
    SetFogNear(0x118, 0x220);
}

// INCLUDE_ASM("nonmatchings/main/render/camera", stubCamera1);
void stubCamera1(void) {
}

// INCLUDE_ASM("nonmatchings/main/render/camera", stubCamera2);
void stubCamera2(void) {
}

// INCLUDE_ASM("nonmatchings/main/render/camera", stubCamera3);
void stubCamera3(void) {
}
