#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", setSpawnAreaFlag);
void setSpawnAreaFlag(void)
{
    u8*  row = D_8007C110[GAME.selectedArea] + D_8009BCCA * 2;
    u16* dst = (u16*)((u8*)&GAME + 0x964 + row[0] * 2);

    *dst |= 1 << row[1];
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", loadSpawnPosition);
void loadSpawnPosition(u8* self)
{
    s16* row = (s16*)((u8*)D_8007BF78[GAME.selectedArea][GAME.selectedSection] + (u16)D_8009BCEA * 8);

    *(int*)(self + 0xEC) = *row++ << 16;
    *(int*)(self + 0xF0) = *row << 16;
    *(int*)(self + 0xF4) = row[1] << 16;
    switch (GAME.selectedArea) {
    case 0:
        if (D_8009C617 == 0 && GAME.selectedSection == 0) {
            *(s16*)(self + 0xEE) = 0x40;
        } else if (GAME.selectedSection == 3) {
            *(s16*)(self + 0xEE) = 0xD2;
        }
        break;
    case 2:
        if (GAME.selectedSection == 4) {
            *(s16*)(self + 0xEE) = 0x90;
        }
        break;
    case 4:
        if (GAME.selectedSection == 0xF) {
            *(s16*)(self + 0xEE) = 0x90;
        }
        break;
    case 10:
        if (GAME.selectedSection == 8) {
            *(s16*)(self + 0xEE) = 0x90;
        }
        break;
    }
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", initPlayerAtSpawn);
void initPlayerAtSpawn(void)
{
    u8* p = PLAYER;
    s16* row;
    u_int flags;
    u_int plane;

    p[0] = 3;
    if ((CURRENT_TASK)->loadGameSelected != 0) {
        D_8009C618 = 4;
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
    *(u16*)0x1F8001C8 = flags;
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
    if (D_8009C618 == 3 || D_8009C617 == 0) {
        loadSpawnPosition(p);
        *(s16*)(p + 0x12) = *(u16*)(p + 0xEE);
        *(s16*)(p + 0x16) -= 0x104;
    } else if ((CURRENT_TASK)->loadGameSelected != 0) {
        (CURRENT_TASK)->loadGameSelected = 0;
        *(VEC3*)&PLAYER[0x10] = D_8009C61C;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", loadSectionBounds);
void loadSectionBounds(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x2C) = *row++;
    *(u16*)(self + 0x2E) = *row++;
    *(u16*)(self + 0x30) = *row;
    *(u16*)(self + 0x32) = row[1];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", loadSectionHeight);
void loadSectionHeight(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x32) = row[3];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800246B0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", copyMatrix32);
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

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", getBaseMatrix);
void getBaseMatrix(MATRIX* dst)
{
    *dst=*(MATRIX*)(&D_1F8000F8);
    return;
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", initLighting);
void initLighting(u8* self)
{
    *(s16*)(self + 0x44) = 0x638;
    *(s16*)(self + 0x46) = 0x800;
    *(s16*)(self + 0x48) = 0;
    *(MATRIX*)(self + 0x20) = *(MATRIX*)(&D_1F8000F8);
    ((MATRIX*)(self + 0x20))->m[0][0] = 0xD00;
    ((MATRIX*)(self + 0x20))->m[1][0] = 0xD00;
    ((MATRIX*)(self + 0x20))->m[2][0] = 0xD00;
    self[0x40] = 0xC0;
    self[0x41] = 0xC0;
    self[0x42] = 0xC0;
    applyLighting(self);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", applyLighting);
void applyLighting(u8* self)
{
    SVECTOR v;
    VECTOR out;
    MATRIX* m = (MATRIX*)self;

    SetFarColor(255, 255, 255);
    SetBackColor(self[0x40], self[0x41], self[0x42]);
    SetColorMatrix((MATRIX*)(self + 0x20));
    *m = *(MATRIX*)(&D_1F8000F8);
    RotMatrixX(*(s16*)(self + 0x44), m);
    RotMatrixY(*(s16*)(self + 0x46), m);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", stubCamera1);
void stubCamera1(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", stubCamera2);
void stubCamera2(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", stubCamera3);
void stubCamera3(void) {
}
