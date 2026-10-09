#include "common.h"
#include "game.h"
#include "psyq/inline_c.h"


#define gte_rtps_real() __asm__ volatile("nop;" "nop;" ".word 0x4A180001")

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", projectActorPosition);
int projectActorPosition(u8* self, long* sxy, long* otz)
{
    *(s16*)0x1F800060 = *(u16*)(self + 0x12);
    *(s16*)0x1F800062 = *(u16*)(self + 0x16);
    if (*(u_long*)&GAME.selectedArea == 0x10005 && (u16)(CURRENT_TASK)->state2 != 3) {
        *(s16*)0x1F800064 = (s16)*(u16*)(self + 0x1A) >> 2;
    } else {
        *(s16*)0x1F800064 = *(u16*)(self + 0x1A);
    }
    SetRotMatrix(SCRATCH_VIEW_MATRIX);
    SetTransMatrix(SCRATCH_VIEW_MATRIX);
    gte_ldv0(&D_1F800060);
    gte_rtps_real();
    gte_stflg(&D_1F80008C);
    if (*(long*)0x1F80008C < 0) {
        return 1;
    }
    gte_stsxy(sxy);
    gte_stszotz(otz);
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", isPolyFT4OnScreen);
int isPolyFT4OnScreen(POLY_FT4* p)
{
    if ((u16)p->y0 >= 0xE0 && (u16)p->y1 >= 0xE0 && (u16)p->y2 >= 0xE0 && (u16)p->y3 >= 0xE0) {
        return 0;
    }
    if ((u16)p->x0 < 0x140 || (u16)p->x1 < 0x140 || (u16)p->x2 < 0x140 || (u16)p->x3 < 0x140) {
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", insertPrimWithBias);
s32 insertPrimWithBias(s32* arg0, u8* arg1, s32 arg2, s16 arg3, s32 arg4)
{
    s32 off = (arg2 << 2) + ((s32)arg3 * 4);
    s32  prev;

    if (off < 0) {
        off = 0;
    }
    off += (s32)arg1;
    if ((u32)(off - CURRENT_OT) >= 0xCA0) {
        return 1;
    }
    prev = *(s32*)off;
    *(s32*)off = (s32)arg0;
    *arg0 = prev | arg4;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", insertPrim);
s32 insertPrim(s32* arg0, u8* arg1, s32 arg2, s16 arg3, s32 arg4)
{
    s32 off = arg3 * 4;
    s32  prev;

    if (off < 0) {
        off = 0;
    }
    off += (s32)arg1;
    if ((u32)(off - CURRENT_OT) >= 0xCA0) {
        return 1;
    }
    prev = *(s32*)off;
    *(s32*)off = (s32)arg0;
    *arg0 = prev | arg4;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", setupActorPolyFT4);
void setupActorPolyFT4(u8* self, POLY_FT4* p, u_long* uv)
{
    setcode(p, 0x2D);
    SetSemiTrans(p, self[0xD] >> 7);
    *(u_long*)&p->u0 = uv[0];
    *(u_long*)&p->u1 = uv[1];
    *(u16*)&p->u2 = *(u16*)&uv[2];
    *(u16*)&p->u3 = *(u16*)&uv[3];
    p->tpage += *(u16*)(self + 0x1E);
    if (self[0xD] & 1) {
        p->clut = *(u16*)(self + 8);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_80045D0C);
int func_80045D0C(u8* self)
{
    s16 d;

    switch (GAME.selectedArea) {
    case 0:
        if (D_8009BCCA == 3) {
            return self[0xA];
        }
        break;
    case 2:
        if (D_8009BCCA == 0) {
            break;
        }
        if (D_8009BCCA == 3) {
            break;
        }
        return self[0xA];
    case 6:
        if ((u_int)(D_8009BCCA - 1) >= 2) {
            break;
        }
        return self[0xA];
    case 5:
    case 8:
        if (D_8009BCCA == 1 || D_8009BCCA == 3) {
            return self[0xA];
        }
        break;
    case 9:
        if (D_8009BCCA == 0) {
            break;
        }
        if (D_8009BCCA == 6) {
            break;
        }
        return self[0xA];
    case 10:
        if (D_8009BCCA == 8) {
            return self[0xA];
        }
        break;
    case 13:
    case 19:
        if (D_8009BCCA == 1) {
            return self[0xA];
        }
        break;
    case 18:
        if (D_8009BCCA == 2) {
            return self[0xA];
        }
        break;
    case 11:
    case 16:
    case 17:
        return self[0xA];
    }
    if (self[0xA] < 4) {
        switch (*(u16*)0x1F8001C8 & 1) {
        case 0:
            d = *(u16*)0x1F8000F6 - *(u16*)(self + 0x1A);
            break;
        case 1:
            d = *(u16*)(self + 0x12) - *(u16*)0x1F8000EE;
            break;
        }
        if (d != 0 && !(self[0xA] & 1)) {
            if (GAME.selectedArea == 4) {
                *(int*)0x1F8002B4 = d * 5 + 0x1000;
            } else {
                *(int*)0x1F8002B4 = d * 7 + 0x1000;
            }
            return self[0xA] | 1;
        }
    }
    return self[0xA];
}
