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

void func_80033964(GameObject *obj)
{
    GameObject *box;
    s32 msg, tone;

    switch (obj->state) {
    case 0:
        switch (obj->id) {
        case 0x13:
            obj->model = 0;
            break;
        case 0x22:
            if (D_8009C114 != 0 || D_800A53AA_S16 < 0x280) {
                obj->state = 3;
                return;
            }
            break;
        case 0x12:
            obj->state = 3;
            return;
        case 0x63:
            obj->unkB4 = -0x10;
            obj->unkB6 = -0x18;
            obj->unkB8 = 0;
            obj->unkBC = 0x18;
            *(s16 *)&obj->unkBE = -0x18;
            *(s16 *)((u8 *)obj + 0xC0) = 0;
            *(s16 *)((u8 *)obj + 0xC4) = -0x10;
            *(s16 *)((u8 *)obj + 0xC6) = 0x18;
            *(s16 *)((u8 *)obj + 0xC8) = 0;
            *(s16 *)((u8 *)obj + 0xCC) = 0x18;
            *(s16 *)((u8 *)obj + 0xCE) = 0x18;
            *(s16 *)((u8 *)obj + 0xD0) = 0;
            if (GAME.selectedArea == 1 || GAME.selectedArea == 7) {
                obj->drawFlags = 1;
                obj->clut = GetClut(0xD0, 0x1E5);
                obj->tpage = 7;
                obj->anim = (void *)D_8013DAB0;
            } else {
                obj->drawFlags = 0;
                obj->tpage = 8;
                obj->anim = (void *)D_8013829C;
            }
            obj->spriteBank = SPR_DATA[3];
            obj->active = 2;
            obj->unkE = 0;
            break;
        }
        setHitbox(obj, 4, 0x28, 8, 0x28);
        obj->state++;
        obj->touchFlag = 0;
        obj->subState = 0;
        obj->rotX = 0;
        obj->rotY = 0;
        obj->rotZ = 0;
#if REGION == REGION_JP
        if (obj->animFrame == 1) {
            obj->rotY = -0x400;
        }
#else
        if (obj->animFrame == 1) {
            obj->rotY = -0x400;
        } else if (obj->animFrame == 2) {
            obj->rotY = 0x800;
            obj->active = 2;
        } else if (obj->animFrame == 3) {
            obj->rotY = 0x400;
            obj->active = 2;
        }
#endif
        break;
    case 1:
        cullAndQueueDraw((u8 *)obj);
        switch (obj->subState) {
        case 0:
            if (obj->touchFlag == 1) {
                if (D_800A5458 & 1) {
                    switch (obj->id) {
                    case 19:
                        if (D_8009C255 == 2) obj->id = 0x14;
                        break;
                    case 20:
                        if (D_8009C13E == 0xFF) obj->id = 0x23;
                        break;
                    }
#if REGION == REGION_JP
                    tone = D_8007D454[obj->id].tone;
                    msg = D_8007D454[obj->id].msg;
                    switch (obj->id) {
                    case 2:
                    case 3:
                    case 4:
                    case 6:
                        tone += (u16)BUTTON_CONFIG_INDEX;
                        break;
                    }
#else
                    msg = D_8007D454[obj->id].msg;
                    switch (obj->id) {
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
                        tone = D_8007D454[obj->id].tone;
                        break;
                    }
#endif
                    obj->parent = (s32)showMessageBox((s16)msg, (s16)tone, 0xA0, 0x8C);
                    obj->subState++;
                }
                obj->touchFlag = 0;
            }
            break;
        case 1:
            box = (GameObject *)obj->parent;
            if (box->state >= 2) {
                box->state++;
                D_8009BCAA = 0;
                D_8009BCA7 = 0;
                D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                SCRATCHPAD.drawFrozen = 0;
                D_800A5458 = 0;
                obj->subState = 0;
                if (obj->id == 0x11) {
                    setEventStarted(0x25, 0, 0);
                }
                if (obj->id == 0x13 && D_8009C13A == 0) {
                    setEventStarted(0x2E, 0, 0);
                    D_8009C255 = 1;
                }
                if (obj->id == 0x14 && D_8009C13D == 0) {
                    setEventStarted(0x31, 0, 0);
                }
            } else if (obj->id == 1 && (D_8009BCEC & 1) && D_8009BC98.unk00 == obj->id) {
                obj->subState++;
            }
            break;
        case 2:
            box = (GameObject *)obj->parent;
            if (*(u16 *)&box->state == 0x101) {
                box->subState = 0;
                obj->subState++;
            }
            break;
        case 3:
            box = (GameObject *)obj->parent;
            if (box->state >= 2) {
                box->state++;
                D_800A5458 = 0;
                obj->subState++;
            }
            break;
        case 4:
            if (D_8009BC98.unk00 >= 2) {
                obj->subState = 0;
            }
            break;
        }
        if (obj->id == 0x22 && D_800A53AA_S16Arr[0] < 0x3E8) {
            D_800A53AA_S16Arr[0] = 0x3E8;
        }
        break;
    case 2:
        break;
    case 3:
        freeAreaObject(obj);
        break;
    }
}
