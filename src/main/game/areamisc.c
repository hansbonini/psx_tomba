#include "common.h"
#include "game.h"

#if REGION != REGION_JP
u32 D_8007D424_d[3] asm("D_8007D424") = {
    0x00070006, 0x00090006, 0x000B0007,
};
u32 D_8007D430_d[3] asm("D_8007D430") = {
    0x000D000C, 0x000C000D, 0x00100010,
};
u32 D_8007D43C_d[3] asm("D_8007D43C") = {
    0x00010000, 0x00030000, 0x00050001,
};
u32 D_8007D448_d[3] asm("D_8007D448") = {
    0x00130012, 0x00130014, 0x00170014,
};
#endif

u32 D_8007D454_d[74] asm("D_8007D454") = {
    0x00000002, 0x00000000, 0x001E0001, 0x00000000,
    0x00060001, 0x00000000, 0x000C0001, 0x00000000,
    0x00000001, 0x00000000, 0x00010002, 0x00000000,
    0x00120001, 0x00000000, 0x00020002, 0x00000000,
    0x00030002, 0x00000000, 0x00000001, 0x00000000,
    0x00010001, 0x00000000, 0x00020001, 0x00000000,
    0x00030001, 0x00000000, 0x00000001, 0x00000000,
    0x00050001, 0x00000000, 0x00010001, 0x00000000,
    0x00020001, 0x00000000, 0x00050002, 0x00000000,
    0x00490002, 0x00000000, 0x00050001, 0x00000000,
    0x00070001, 0x00000000, 0x00000001, 0x00000000,
    0x00010001, 0x00000000, 0x00020001, 0x00000000,
    0x00030001, 0x00000000, 0x00000001, 0x00000000,
    0x00000001, 0x00000000, 0x00010001, 0x00000000,
    0x00020001, 0x00000000, 0x00030001, 0x00000000,
    0x00000001, 0x00000000, 0x00010001, 0x00000000,
    0x00020001, 0x00000000, 0x00030001, 0x00000000,
    0x00000003, 0x00000000, 0x00640002, 0x00000000,
    0x000A0002, 0x00000000,
};

asm(
    ".globl D_8007D456\nD_8007D456 = D_8007D454 + 2\n"
);

// INCLUDE_ASM("nonmatchings/main/game/areamisc", func_80033964);
typedef struct { u16 msg; u16 tone; u8 pad[4]; } SignText;
extern u16 D_8007D424[];
extern u16 D_8007D430[];
extern u16 D_8007D43C[];
extern u16 D_8007D448[];
extern SignText D_8007D454[];
extern u8 D_8009C13A, D_8009C13D, D_8009C13E, D_8009C255;
extern u8 D_800A5458;
extern s32 D_8013829C, D_8013DAB0;
extern GameObject *showMessageBox();
extern s16 D_800A53AA_S16 asm("D_800A53AA");
extern s16 D_800A53AA_S16Arr[] asm("D_800A53AA");

void func_80033964(GameObject *o)
{
    GameObject *box;
    s32 msg, tone;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0x13:
            o->unkA0 = 0;
            break;
        case 0x22:
            if (D_8009C114 != 0 || D_800A53AA_S16 < 0x280) {
                o->state = 3;
                return;
            }
            break;
        case 0x12:
            o->state = 3;
            return;
        case 0x63:
            o->unkB4 = -0x10;
            o->unkB6 = -0x18;
            o->unkB8 = 0;
            o->unkBC = 0x18;
            *(s16 *)&o->unkBE = -0x18;
            *(s16 *)((u8 *)o + 0xC0) = 0;
            *(s16 *)((u8 *)o + 0xC4) = -0x10;
            *(s16 *)((u8 *)o + 0xC6) = 0x18;
            *(s16 *)((u8 *)o + 0xC8) = 0;
            *(s16 *)((u8 *)o + 0xCC) = 0x18;
            *(s16 *)((u8 *)o + 0xCE) = 0x18;
            *(s16 *)((u8 *)o + 0xD0) = 0;
            if (GAME.selectedArea == 1 || GAME.selectedArea == 7) {
                o->unkD = 1;
                o->clut = GetClut(0xD0, 0x1E5);
                o->tpage = 7;
                o->anim = (void *)D_8013DAB0;
            } else {
                o->unkD = 0;
                o->tpage = 8;
                o->anim = (void *)D_8013829C;
            }
            o->spriteBank = SPR_DATA[3];
            o->active = 2;
            o->unkE = 0;
            break;
        }
        o->hitOffsetX = 4;
        o->hitWidth = 8;
        o->hitOffsetY = 0x28;
        o->hitHeight = 0x28;
        o->state++;
        o->touchFlag = 0;
        o->subState = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (o->animFrame == 1) {
            o->unk88 = -0x400;
        } else if (o->animFrame == 2) {
            o->unk88 = 0x800;
            o->active = 2;
        } else if (o->animFrame == 3) {
            o->unk88 = 0x400;
            o->active = 2;
        }
        break;
    case 1:
        func_80022E44((u8 *)o);
        switch (o->subState) {
        case 0:
            if (o->touchFlag == 1) {
                if (D_800A5458 & 1) {
                    switch (o->subtype) {
                    case 19:
                        if (D_8009C255 == 2) o->subtype = 0x14;
                        break;
                    case 20:
                        if (D_8009C13E == 0xFF) o->subtype = 0x23;
                        break;
                    }
                    msg = D_8007D454[o->subtype].msg;
                    switch (o->subtype) {
                    case 2:
                        tone = D_8007D424[(s16)BUTTON_CONFIG_INDEX];
                        break;
                    case 3:
                        tone = D_8007D430[(s16)BUTTON_CONFIG_INDEX];
                        break;
                    case 4:
                        tone = D_8007D43C[(s16)BUTTON_CONFIG_INDEX];
                        break;
                    case 6:
                        tone = D_8007D448[(s16)BUTTON_CONFIG_INDEX];
                        break;
                    default:
                        tone = D_8007D454[o->subtype].tone;
                        break;
                    }
                    o->unk90 = (s32)showMessageBox((s16)msg, (s16)tone, 0xA0, 0x8C);
                    o->subState++;
                }
                o->touchFlag = 0;
            }
            break;
        case 1:
            box = (GameObject *)o->unk90;
            if (box->state >= 2) {
                box->state++;
                D_8009BCAA = 0;
                D_8009BCA7 = 0;
                D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                D_1F8001C6 = 0;
                D_800A5458 = 0;
                o->subState = 0;
                if (o->subtype == 0x11) {
                    setEventStarted(0x25, 0, 0);
                }
                if (o->subtype == 0x13 && D_8009C13A == 0) {
                    setEventStarted(0x2E, 0, 0);
                    D_8009C255 = 1;
                }
                if (o->subtype == 0x14 && D_8009C13D == 0) {
                    setEventStarted(0x31, 0, 0);
                }
            } else if (o->subtype == 1 && (D_8009BCEC & 1) && D_8009BC98.unk00 == o->subtype) {
                o->subState++;
            }
            break;
        case 2:
            box = (GameObject *)o->unk90;
            if (*(u16 *)&box->state == 0x101) {
                box->subState = 0;
                o->subState++;
            }
            break;
        case 3:
            box = (GameObject *)o->unk90;
            if (box->state >= 2) {
                box->state++;
                D_800A5458 = 0;
                o->subState++;
            }
            break;
        case 4:
            if (D_8009BC98.unk00 >= 2) {
                o->subState = 0;
            }
            break;
        }
        if (o->subtype == 0x22 && D_800A53AA_S16Arr[0] < 0x3E8) {
            D_800A53AA_S16Arr[0] = 0x3E8;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
