#include "common.h"
#include "game.h"

u_char D_8007D6D0_data[0x10] asm("D_8007D6D0") = {
    7, 7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

// INCLUDE_ASM("nonmatchings/main/game/reward", updateItemPickupAnim);
void updateItemPickupAnim(GameObject* obj)
{
    int var_v0;
    u_short temp_a1;
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = obj->step;
    switch (temp_v1) {
        case 0:
            playSFX(*(&D_8007D6D0 + obj->id));
            func_800E92D4(0x1F4, obj->x.p.whole, obj->y.p.whole, obj->z.p.whole);
            obj->unkA5 = 0;
            if (obj->id != ITEM_FLOWERTEARS) {
                obj->otMode = OT_MODE_FIXED;
                obj->priority = 4;
            }
            obj->velV = -1024;
            obj->movetab = &D_8007722C;
            if (obj->animFrame & 2) {
                obj->movetab = &D_800771FC;
            }
            obj->step = (u_char) (obj->step + 1);
            break;
        case 1:
            temp_a1 = obj->animFrame;
            if (temp_a1 & 2) {
                applyAnimVelocityX(obj, temp_a1 & 1);
            } else {
                applyAnimVelocityX(obj, (temp_v1 - temp_a1) & 0xFFFF);
            }
            temp_v0 = obj->velV + 64;
            obj->velV = temp_v0;
            if ((short) temp_v0 >= 1025) {
                obj->velV = 1024;
            }
            obj->y.raw = (int) (obj->y.raw + ((short) obj->velV << 8));
            break;
    }
    if (obj->animFrame & 1) {
        var_v0 = obj->rotZ + 24;
    } else {
        var_v0 = obj->rotZ - 24;
    }
    obj->rotZ = (int) (var_v0 & 0xFF);
}

extern int D_80077274;
extern int D_8007728C;


extern int D_8012D3F8;
extern int D_8012DDA4;
extern int D_80131694;
extern int D_801338C0;
extern int D_80137AAC;
extern int D_801388B4;
extern int D_80139A4C;
extern int D_8013A078;
extern int D_8013D954;
extern int D_8013E574;
extern int D_8013EFE8;

unk_8007D6E0 D_8007D6E0[14] = {
    { 0xA, 0x14, 0x10, 0x20, 1, 0, 2, &D_80014CCC },
    { 0x10, 0x20, 8, 0x18, 0x13, 0x24, 5, &D_8013A078 },
    { 0x10, 0x20, 0xA, 0x14, 8, 0, 3, &D_8013D954 },
    { 0x10, 0x20, 0x10, 0x20, 1, 0x11, 2, &D_8013EFE8 },
    { 0x10, 0x20, 0x10, 0x20, 2, 0xC, 8, &D_8012DDA4 },
    { 0x10, 0x20, 0x10, 0x20, 1, 0, 8, &D_8013E574 },
    { 8, 0x10, 8, 0x10, 9, 0, 3, &D_8012D3F8 },
    { 0x10, 0x20, 0xE, 0x1C, 0xB, 6, 5, &D_801388B4 },
    { 0xA, 0x14, 0x10, 0x20, 1, 0x1F, 2, &D_80137AAC },
    { 0x10, 0x20, 8, 0x10, 1, 4, 5, &D_801338C0 },
    { 8, 0x10, 8, 0x10, 1, 0x1E, 5, &D_80139A4C },
    { 0x10, 0x20, 0x10, 0x20, 1, 0xB, 5, &D_80139A4C },
    { 0x10, 0x20, 0x10, 0x20, 1, 4, 2, &D_80131694 },
    { 0xA, 0x14, 0xA, 0x14, 5, 0, 5, D_80131D84 }
};

s16 D_8007D788[0x100] = {
    0, -70, -140, -210, -281, -350, -420, -490, -559, -628, -696, -764, -832, -899, -965, -1031,
    -1097, -1161, -1225, -1289, -1351, -1413, -1474, -1533, -1592, -1650, -1707, -1763, -1818, -1872, -1925, -1977,
    -2027, -2076, -2124, -2171, -2216, -2260, -2302, -2344, -2383, -2422, -2459, -2494, -2528, -2561, -2591, -2621,
    -2648, -2675, -2699, -2722, -2743, -2763, -2781, -2797, -2812, -2824, -2836, -2845, -2853, -2859, -2863, -2866,
    -2867, -2866, -2863, -2859, -2853, -2845, -2836, -2824, -2812, -2797, -2781, -2763, -2743, -2722, -2699, -2675,
    -2648, -2621, -2591, -2561, -2528, -2494, -2459, -2422, -2383, -2344, -2302, -2260, -2216, -2171, -2124, -2076,
    -2027, -1977, -1925, -1872, -1818, -1763, -1707, -1650, -1592, -1533, -1474, -1413, -1351, -1289, -1225, -1161,
    -1097, -1031, -965, -899, -832, -764, -696, -628, -559, -490, -420, -350, -281, -210, -140, -70,
    0, 70, 140, 210, 281, 350, 420, 490, 559, 628, 696, 764, 832, 899, 965, 1031,
    1097, 1161, 1225, 1289, 1351, 1413, 1474, 1533, 1592, 1650, 1707, 1763, 1818, 1872, 1925, 1977,
    2027, 2076, 2124, 2171, 2216, 2260, 2302, 2344, 2383, 2422, 2459, 2494, 2528, 2561, 2591, 2621,
    2648, 2675, 2699, 2722, 2743, 2763, 2781, 2797, 2812, 2824, 2836, 2845, 2853, 2859, 2863, 2866,
    2867, 2866, 2863, 2859, 2853, 2845, 2836, 2824, 2812, 2797, 2781, 2763, 2743, 2722, 2699, 2675,
    2648, 2621, 2591, 2561, 2528, 2494, 2459, 2422, 2383, 2344, 2302, 2260, 2216, 2171, 2124, 2076,
    2027, 1977, 1925, 1872, 1818, 1763, 1707, 1650, 1592, 1533, 1474, 1413, 1351, 1289, 1225, 1161,
    1097, 1031, 965, 899, 832, 764, 696, 628, 559, 490, 420, 350, 281, 210, 140, 70
};

s16 NEG_SIN_TABLE[0x100] = {
    0, -100, -200, -301, -401, -501, -601, -700, -799, -897, -995, -1092, -1189, -1284, -1379, -1474,
    -1567, -1659, -1751, -1841, -1930, -2018, -2105, -2191, -2275, -2358, -2439, -2519, -2598, -2675, -2750, -2824,
    -2896, -2966, -3034, -3101, -3166, -3229, -3289, -3348, -3405, -3460, -3513, -3563, -3612, -3658, -3702, -3744,
    -3784, -3821, -3856, -3889, -3919, -3947, -3973, -3996, -4017, -4035, -4051, -4065, -4076, -4084, -4091, -4094,
    -4096, -4094, -4091, -4084, -4076, -4065, -4051, -4035, -4017, -3996, -3973, -3947, -3919, -3889, -3856, -3821,
    -3784, -3744, -3702, -3658, -3612, -3563, -3513, -3460, -3405, -3348, -3289, -3229, -3166, -3101, -3034, -2966,
    -2896, -2824, -2750, -2675, -2598, -2519, -2439, -2358, -2275, -2191, -2105, -2018, -1930, -1841, -1751, -1659,
    -1567, -1474, -1379, -1284, -1189, -1092, -995, -897, -799, -700, -601, -501, -401, -301, -200, -100,
    0, 100, 200, 301, 401, 501, 601, 700, 799, 897, 995, 1092, 1189, 1284, 1379, 1474,
    1567, 1659, 1751, 1841, 1930, 2018, 2105, 2191, 2275, 2358, 2439, 2519, 2598, 2675, 2750, 2824,
    2896, 2966, 3034, 3101, 3166, 3229, 3289, 3348, 3405, 3460, 3513, 3563, 3612, 3658, 3702, 3744,
    3784, 3821, 3856, 3889, 3919, 3947, 3973, 3996, 4017, 4035, 4051, 4065, 4076, 4084, 4091, 4094,
    4096, 4094, 4091, 4084, 4076, 4065, 4051, 4035, 4017, 3996, 3973, 3947, 3919, 3889, 3856, 3821,
    3784, 3744, 3702, 3658, 3612, 3563, 3513, 3460, 3405, 3348, 3289, 3229, 3166, 3101, 3034, 2966,
    2896, 2824, 2750, 2675, 2598, 2519, 2439, 2358, 2275, 2191, 2105, 2018, 1930, 1841, 1751, 1659,
    1567, 1474, 1379, 1284, 1189, 1092, 995, 897, 799, 700, 601, 501, 401, 301, 200, 100
};

s16 COS_TABLE[0x100] = {
    4096, 4094, 4091, 4084, 4076, 4065, 4051, 4035, 4017, 3996, 3973, 3947, 3919, 3889, 3856, 3821,
    3784, 3744, 3702, 3658, 3612, 3563, 3513, 3460, 3405, 3348, 3289, 3229, 3166, 3101, 3034, 2966,
    2896, 2824, 2750, 2675, 2598, 2519, 2439, 2358, 2275, 2191, 2105, 2018, 1930, 1841, 1751, 1659,
    1567, 1474, 1379, 1284, 1189, 1092, 995, 897, 799, 700, 601, 501, 401, 301, 200, 100,
    0, -100, -200, -301, -401, -501, -601, -700, -799, -897, -995, -1092, -1189, -1284, -1379, -1474,
    -1567, -1659, -1751, -1841, -1930, -2018, -2105, -2191, -2275, -2358, -2439, -2519, -2598, -2675, -2750, -2824,
    -2896, -2966, -3034, -3101, -3166, -3229, -3289, -3348, -3405, -3460, -3513, -3563, -3612, -3658, -3702, -3744,
    -3784, -3821, -3856, -3889, -3919, -3947, -3973, -3996, -4017, -4035, -4051, -4065, -4076, -4084, -4091, -4094,
    -4096, -4094, -4091, -4084, -4076, -4065, -4051, -4035, -4017, -3996, -3973, -3947, -3919, -3889, -3856, -3821,
    -3784, -3744, -3702, -3658, -3612, -3563, -3513, -3460, -3405, -3348, -3289, -3229, -3166, -3101, -3034, -2966,
    -2896, -2824, -2750, -2675, -2598, -2519, -2439, -2358, -2275, -2191, -2105, -2018, -1930, -1841, -1751, -1659,
    -1567, -1474, -1379, -1284, -1189, -1092, -995, -897, -799, -700, -601, -501, -401, -301, -200, -100,
    0, 100, 200, 301, 401, 501, 601, 700, 799, 897, 995, 1092, 1189, 1284, 1379, 1474,
    1567, 1659, 1751, 1841, 1930, 2018, 2105, 2191, 2275, 2358, 2439, 2519, 2598, 2675, 2750, 2824,
    2896, 2966, 3034, 3101, 3166, 3229, 3289, 3348, 3405, 3460, 3513, 3563, 3612, 3658, 3702, 3744,
    3784, 3821, 3856, 3889, 3919, 3947, 3973, 3996, 4017, 4035, 4051, 4065, 4076, 4084, 4091, 4094
};

u8 ITEM_REWARD_INDEX[0xA0] = {
    2, 2, 3, 0x13, 0, 1, 1, 1, 0xC, 1, 0, 0, 1, 1, 0xB, 4,
    0xA, 0, 0x16, 5, 1, 7, 8, 9, 0, 0, 0, 0, 1, 0x17, 1, 1,
    0, 0xD, 0, 0, 0, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0x11,
    1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0x14, 0x14, 0x14, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1,
    0, 0, 0x10, 0, 1, 0, 0, 0xB, 0, 1, 1, 0, 1, 0, 0xF, 1,
    1, 1, 0x15, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0
};


void (*ITEM_REWARD_TABLE[])(GameObject *) = {
    rewardNone,
    rewardItem,
    rewardHeart,
    rewardEffectOnly,
    rewardBakedYam,
    rewardDirtyMirror,
    rewardVitalityMaxUp,
    rewardWoodBoomerang,
    rewardStoneBoomerang,
    rewardIronBoomerang,
    rewardOneUp,
    rewardGoldenBowl,
    rewardBitingPlantFlower,
    rewardGrapple,
    rewardGrappleJack,
    rewardCrystalBalls,
    rewardMysteriousMushroom,
    rewardFlowerSeeds,
    rewardPigBag,
    rewardConditionalItem,
    rewardJewel,
    rewardSafeMushroom,
    rewardAnimalDash,
    rewardPants
};

extern int D_8011787C;
extern int D_80119484;
extern int D_80119C84;
extern int D_8011B60C;
extern int D_8011BE74;
extern int D_8011E4CC;
extern int D_8012CF4C;
extern int D_8012D3AC;
extern int D_8012D3B0;
extern int D_8012D3C0;
extern int D_8012D3C4;
extern int D_8012D3C8;
extern int D_8012D3D0;
extern int D_8012D3D4;
extern int D_8012D404;
extern int D_8012D408;
extern int D_8013105C;
extern int D_80131070;
extern int D_80131074;
extern int D_8013107C;
extern int D_80131080;
extern int D_80131088;
extern int D_80131094;
extern int D_80131098;
extern int D_8013109C;
extern int D_801310A0;
extern int D_801310A4;
extern int D_801310A8;
extern int D_801310AC;
extern int D_801310B0;
extern int D_801310B4;
extern int D_801310B8;
extern int D_801310C4;
extern int D_801310C8;
extern int D_801310CC;
extern int D_80134070;
extern int D_80134074;
extern int D_80134078;
extern int D_8013407C;
extern int D_80134080;
extern int D_80134084;
extern int D_80134088;
extern int D_80134098;
extern int D_801340A4;
extern int D_801340A8;
extern int D_801340AC;
extern int D_801340B8;
extern int D_801340BC;
extern int D_801340D0;
extern int D_80138288;
extern int D_801382A0;
extern int D_801382A4;
extern int D_801382A8;
extern int D_80138320;
extern int D_8013A428;
extern int D_8013A42C;
extern int D_8013A430;
extern int D_8013A580;
extern int D_8013D8BC;
extern int D_8013D950;
extern int D_8013D96C;
extern int D_8013DA58;
extern int D_8013DAB4;

ItemInit ITEM_INIT_DEFAULT = { 0, 2, 0x15, 0xFB, 4, 1, 1, 0, 0x160, 0x1F5, 7, 0x10, 7, 0x10, (int)&D_80012190 };

ItemInit ITEM_INIT_FROG = { 0, 2, 0x15, 0xFB, 4, 1, 1, 0, 0x160, 0x1F5, 7, 0x10, 7, 0x10, (int)&D_80012190 };

ItemInit ITEM_INIT_LOSTDWARF = { 1, 3, 0x14, 0xF6, 4, 1, 2, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_800122DC };

ItemInit ITEM_INIT_BANANAS = { 0, 0, 0x15, 0xF6, 4, 0, 0, 0, 0, 0, 7, 0x10, 7, 0x10, (int)&D_800122F8 };

ItemInit ITEM_INIT_FURIOUSTORNADO = { 0, 0, 0x14, 0xF6, 4, 1, 1, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, (int)&D_8001230C };

ItemInit ITEM_INIT_100YEAROLDBELL = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8013A42C };

ItemInit ITEM_INIT_100YEAROLDKEY = { 0, 1, 0xB, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E7, 8, 0x10, 8, 0x10, (int)&D_8013A428 };

ItemInit ITEM_INIT_CHARITYWINGS = { 0, 1, 0x14, 0, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80012374 };

ItemInit ITEM_INIT_BITINGPLANTFLOWER = { 0, 0xC, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8013A580 };

ItemInit ITEM_INIT_HEALINGMUSHROOM = { 0, 1, 0xA, 0xEC, 3, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8012D3B0 };

ItemInit ITEM_INIT_BUCKET = { 0, 0, 0x14, 0xF6, 4, 1, 3, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, (int)&D_8001230C };

ItemInit ITEM_INIT_TEARJAR = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 0xA, 0x14, 8, 0x18, (int)&D_8012D3D0 };

ItemInit ITEM_INIT_FLOWERTEARS = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 0xA, 0x14, 8, 0x18, (int)&D_8012D3D4 };

ItemInit ITEM_INIT_BARON = { 0, 0xB, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80012320 };

ItemInit ITEM_INIT_BAKEDYAM = { 0, 4, 7, 0xEC, 3, 1, 0, 0, 0x100, 0x1E5, 8, 0x10, 8, 0x10, (int)&D_8013DAB4 };

ItemInit ITEM_INIT_LEAFBUTTERFLY = { 0, 0xA, 0x15, 0xF6, 4, 1, 0, 0, 0x160, 0x1F0, 8, 0x10, 8, 0x10, (int)&D_80012324 };

ItemInit ITEM_INIT_BUCKETOFWATER = { 0, 0, 0x15, 0xF6, 4, 1, 0, 0, 0x170, 0x1EF, 8, 0x10, 8, 0x10, (int)&D_80012328 };

ItemInit ITEM_INIT_DIRTYMIRROR = { 0, 5, 0xB, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 0x10, 0x20, (int)&D_8013D950 };

ItemInit ITEM_INIT_FUNKYPARASOL = { 0, 1, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80012308 };

ItemInit ITEM_INIT_WOODBOOMERANG = { 0, 7, 0x15, 0xF6, 4, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8001232C };

ItemInit ITEM_INIT_STONEBOOMERANG = { 0, 8, 0x15, 0xF6, 4, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80012330 };

ItemInit ITEM_INIT_IRONBOOMERANG = { 0, 9, 0x15, 0xF6, 4, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80012334 };

ItemInit ITEM_INIT_JUMPINGPANTS = { 0, 0, 0x14, 0xF6, 4, 1, 3, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, (int)&D_8001230C };

ItemInit ITEM_INIT_LUNCHBOX = { 0, 1, 0x14, 0xF6, 4, 1, 1, 0, 0x150, 0x1FC, 8, 0x10, 8, 0x10, (int)&D_80012304 };

ItemInit ITEM_INIT_LARGELUNCHBOX = { 0, 1, 0x14, 0xF6, 4, 1, 1, 0, 0x150, 0x1FD, 8, 0x10, 8, 0x10, (int)&D_80012304 };

ItemInit ITEM_INIT_GRAPPLE = { 0, 0xD, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80012310 };

ItemInit ITEM_INIT_1000YEAROLDKEY = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_801340D0 };

ItemInit ITEM_INIT_LARGEKEYPANEL_1 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80134070 };

ItemInit ITEM_INIT_LARGEKEYPANEL_2 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80134074 };

ItemInit ITEM_INIT_LARGEKEYPANEL_3 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80134078 };

ItemInit ITEM_INIT_LARGEKEYPANEL_4 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8013407C };

ItemInit ITEM_INIT_LARGEKEYPANEL_5 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80134080 };

ItemInit ITEM_INIT_RAINESSENCE = { 0, 1, 8, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80134088 };

ItemInit ITEM_INIT_CHEESE = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x150, 0x1F9, 8, 0x10, 8, 0x10, (int)&D_80012384 };

ItemInit ITEM_INIT_FLOWERSEEDS = { 0, 1, 8, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8013D96C };

ItemInit ITEM_INIT_SILVERPOWDER = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_801340A4 };

ItemInit ITEM_INIT_MOLASSES = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_801340A8 };

ItemInit ITEM_INIT_BLUEPOWDER = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8012D408 };

ItemInit ITEM_INIT_1000YEAROLDBELL = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8012D3AC };

ItemInit ITEM_INIT_MYSTERIOUSMUSHROOM = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8012D3C4 };

ItemInit ITEM_INIT_THREECRYSTALBALLS = { 0, 1, 8, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8013DA58 };

ItemInit ITEM_INIT_FORBIDDENMUSHROOM = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8012D3C0 };

ItemInit ITEM_INIT_ORDINARYMUSHROOM = { 0, 1, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8012D3C8 };

ItemInit ITEM_INIT_GREENPIGBAG = { 0, 1, 6, 0xF6, 0xC, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80138320 };

ItemInit ITEM_INIT_SMALLKEY = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_801340B8 };

ItemInit ITEM_INIT_BUNKFLOWER = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80138288 };

ItemInit ITEM_INIT_MATHBEADD1 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_80131094 };

ItemInit ITEM_INIT_MATHBEADD2 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_80131098 };

ItemInit ITEM_INIT_MATHBEADD3 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_8013109C };

ItemInit ITEM_INIT_MATHBEADD4 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310A0 };

ItemInit ITEM_INIT_MATHBEADD5 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310A4 };

ItemInit ITEM_INIT_MATHBEADD6 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310A8 };

ItemInit ITEM_INIT_MATHBEADD7 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310AC };

ItemInit ITEM_INIT_MATHBEADD8 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310B0 };

ItemInit ITEM_INIT_MATHBEADD9 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310B4 };

ItemInit ITEM_INIT_MATHBEADD10 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, (int)&D_801310B8 };

ItemInit ITEM_INIT_BOMB = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x120, 0x1F3, 0xC, 0xC, 0xC, 0xC, (int)&D_800122EC };

ItemInit ITEM_INIT_KOKKACLAW = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F1, 0xC, 0xC, 0xC, 0xC, (int)&D_800122E4 };

ItemInit ITEM_INIT_BUTAMUSHITHORN = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F0, 0xC, 0xC, 0xC, 0xC, (int)&D_800122E0 };

ItemInit ITEM_INIT_NEEDLEGATORTEETH = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F2, 0xC, 0xC, 0xC, 0xC, (int)&D_800122E8 };

ItemInit ITEM_INIT_GRANDPASBRACELET = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F5, 0xC, 0xC, 0xC, 0xC, (int)&D_800122F4 };

ItemInit ITEM_INIT_SMALLDRUM = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x120, 0x1F4, 0xC, 0xC, 0xC, 0xC, (int)&D_800122F0 };

ItemInit ITEM_INIT_REDCANDY = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E0, 0xC, 0xC, 0xC, 0xC, (int)&D_8011BE74 };

ItemInit ITEM_INIT_BLUECANDY = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E1, 0xC, 0xC, 0xC, 0xC, (int)&D_8011BE74 };

ItemInit ITEM_INIT_GREENCANDY = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E2, 0xC, 0xC, 0xC, 0xC, (int)&D_8011BE74 };

ItemInit ITEM_INIT_BLACKCANDY = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E3, 0xC, 0xC, 0xC, 0xC, (int)&D_8011BE74 };

ItemInit ITEM_INIT_SILVERCANDY = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E4, 0xC, 0xC, 0xC, 0xC, (int)&D_8011BE74 };

ItemInit ITEM_INIT_GOLDENCANDY = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E5, 0xC, 0xC, 0xC, 0xC, (int)&D_8011BE74 };

ItemInit ITEM_INIT_PINKPIGBAG = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_80134084 };

ItemInit ITEM_INIT_NAVYPIGBAG = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_80131070 };

ItemInit ITEM_INIT_YELLOWPIGBAG = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E2, 0xC, 0xC, 0xC, 0xC, (int)&D_80131088 };

ItemInit ITEM_INIT_KNOWLEDGEFRUIT = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_8013105C };

ItemInit ITEM_INIT_FUNGASAP = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_8013107C };

ItemInit ITEM_INIT_FUNGATREE = { 0, 1, 0xD, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_801310C8 };

ItemInit ITEM_INIT_CHIEFSPEAR = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_80131080 };

ItemInit ITEM_INIT_WOOD = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, (int)&D_80131074 };

ItemInit ITEM_INIT_JEWELOFWATER = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E3, 0xC, 0xC, 0xC, 0xC, (int)&D_801310C4 };

ItemInit ITEM_INIT_SEASHELLNECKLACE = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E6, 0xC, 0xC, 0xC, 0xC, (int)&D_801310CC };

ItemInit ITEM_INIT_ORANGEPIGBAG = { 0, 1, 0xF, 0xF6, 5, 1, 0, 0, 0x130, 0x1E6, 8, 0x10, 8, 0x10, (int)&D_80119484 };

ItemInit ITEM_INIT_HEALINGHERBS = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0xB0, 0x1E4, 8, 0x10, 8, 0x10, (int)&D_801382A0 };

ItemInit ITEM_INIT_SEAWEED = { 0, 1, 1, 0xF6, 3, 1, 0, 0, 0xC0, 0x1E3, 8, 0x10, 8, 0x10, (int)&D_8012CF4C };

ItemInit ITEM_INIT_PIPE = { 0, 1, 0xF, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8011787C };

ItemInit ITEM_INIT_WHATTHETHIEFLOST = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0x110, 0x1E2, 8, 0x10, 8, 0x10, (int)&D_801382A8 };

ItemInit ITEM_INIT_FLASHPANTS = { 0, 0, 0x14, 0xF6, 4, 1, 3, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, (int)&D_8001230C };

ItemInit ITEM_INIT_JEWELOFFIRE = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_801340AC };

ItemInit ITEM_INIT_JEWELOFWIND = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E4, 8, 0x10, 8, 0x10, (int)&D_801382A4 };

ItemInit ITEM_INIT_MIGHTYFISHFOOD = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80134098 };

ItemInit ITEM_INIT_RISEANDSHINEPOWDER = { 0, 1, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 0xA, 0x14, 8, 0x18, (int)&D_8012D404 };

ItemInit ITEM_INIT_GOLDENFLOWER = { 0, 1, 0xC, 0xF6, 0xB, 1, 0, 0, 0xA0, 0x1ED, 8, 0x10, 8, 0x10, (int)&D_8011E4CC };

ItemInit ITEM_INIT_MATHBEADD11 = { 0, 6, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_8001231C };

ItemInit ITEM_INIT_FUELBARREL = { 0, 1, 0xE, 0xF6, 0xB, 1, 0, 0, 0x130, 0x1ED, 8, 0x10, 8, 0x20, (int)&D_8011B60C };

ItemInit ITEM_INIT_10000YEAROLDBELL = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0x130, 0x1EA, 8, 0x10, 8, 0x20, (int)&D_8013A430 };

ItemInit ITEM_INIT_1000000YEAROLDBELL = { 0, 1, 0xB, 0xF6, 3, 0, 0, 0, 0xF0, 0x1E9, 8, 0x10, 8, 0x20, (int)&D_8013D8BC };

ItemInit ITEM_INIT_BOSSJEWEL = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_801340BC };

ItemInit ITEM_INIT_FUNGADRUM = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x120, 0x1F4, 8, 0x10, 8, 0x10, (int)&D_800122F0 };

ItemInit ITEM_INIT_WHATTHETHIEFFORGOT = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0x110, 0x1E2, 8, 0x10, 8, 0x10, (int)&D_801382A8 };

ItemInit ITEM_INIT_SACREDFISH = { 0, 1, 7, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, (int)&D_80119C84 };

u_char ITEM_INIT_INDEX[0xC8] = {
    [ITEM_CHICK]               = 0,
    [ITEM_FROG]                = 1,
    [ITEM_LOSTDWARF]           = 2,
    [ITEM_BANANAS]             = 3,
    [ITEM_FURIOUSTORNADO]      = 4,
    [ITEM_100YEAROLDBELL]      = 5,
    [ITEM_100YEAROLDKEY]       = 6,
    [ITEM_CHARITYWINGS]        = 7,
    [ITEM_BITINGPLANTFLOWER]   = 8,
    [ITEM_HEALINGMUSHROOM]     = 9,
    [ITEM_BUCKET]              = 0xA,
    [ITEM_TELESCOPE]           = 0,
    [ITEM_TEARJAR]             = 0xB,
    [ITEM_FLOWERTEARS]         = 0xC,
    [ITEM_BARON]               = 0xD,
    [ITEM_BAKEDYAM]            = 0xE,
    [ITEM_LEAFBUTTERFLY]       = 0xF,
    [ITEM_TORCH]               = 0,
    [ITEM_BUCKETOFWATER]       = 0x10,
    [ITEM_DIRTYMIRROR]         = 0x11,
    [ITEM_FUNKYPARASOL]        = 0x12,
    [ITEM_WOODBOOMERANG]       = 0x13,
    [ITEM_STONEBOOMERANG]      = 0x14,
    [ITEM_IRONBOOMERANG]       = 0x15,
    [ITEM_DASHINGPANTS]        = 0,
    [ITEM_MAP]                 = 0,
    [ITEM_BROKENVASE]          = 0,
    [ITEM_BLACKJACK]           = 0,
    [ITEM_FLASHPANTS]          = 0x53,
    [ITEM_JUMPINGPANTS]        = 0x16,
    [ITEM_LUNCHBOX]            = 0x17,
    [ITEM_LARGELUNCHBOX]       = 0x18,
    [ITEM_NORMALPANTS]         = 0,
    [ITEM_GRAPPLE]             = 0x19,
    [ITEM_GRAPPLEJACK]         = 0,
    [ITEM_BABYPIG]             = 0,
    [ITEM_1000YEAROLDKEY]      = 0x1A,
    [ITEM_REDPIGBAG]           = 0,
    [ITEM_ORANGEPIGBAG]        = 0x4E,
    [ITEM_YELLOWPIGBAG]        = 0x46,
    [ITEM_GREENPIGBAG]         = 0x2B,
    [ITEM_BLUEEVILPIGBAG]      = 0,
    [ITEM_NAVYPIGBAG]          = 0x45,
    [ITEM_PINKPIGBAG]          = 0x44,
    [ITEM_10000YEAROLDKEY]     = 0,
    [ITEM_1000000YEAROLDKEY]   = 0,
    [ITEM_LARGEKEYPANEL_1]     = 0x1B,
    [ITEM_LARGEKEYPANEL_2]     = 0x1C,
    [ITEM_LARGEKEYPANEL_3]     = 0x1D,
    [ITEM_LARGEKEYPANEL_4]     = 0x1E,
    [ITEM_LARGEKEYPANEL_5]     = 0x1F,
    [ITEM_FUELBARREL]          = 0x5A,
    [ITEM_RAINESSENCE]         = 0x20,
    [ITEM_BIGKEY]              = 0,
    [ITEM_SMALLKEY]            = 0x2C,
    [ITEM_CHEESE]              = 0x21,
    [ITEM_MAGICMIRROR]         = 0,
    [ITEM_TORNMAP1]            = 0,
    [ITEM_TORNMAP2]            = 0,
    [ITEM_RUBBERGLOVES]        = 0,
    [ITEM_BOMB]                = 0x38,
    [ITEM_IRONHAMMER]          = 0,
    [ITEM_IRONWHEEL]           = 0,
    [ITEM_FLOWERSEEDS]         = 0x22,
    [ITEM_PIPE]                = 0x51,
    [ITEM_WINE]                = 0,
    [ITEM_BUNKFLOWER]          = 0x2D,
    [ITEM_MATHBEADD1]          = 0x2E,
    [ITEM_MATHBEADD2]          = 0x2F,
    [ITEM_MATHBEADD3]          = 0x30,
    [ITEM_MATHBEADD4]          = 0x31,
    [ITEM_MATHBEADD5]          = 0x32,
    [ITEM_MATHBEADD6]          = 0x33,
    [ITEM_MATHBEADD7]          = 0x34,
    [ITEM_MATHBEADD8]          = 0x35,
    [ITEM_MATHBEADD9]          = 0x36,
    [ITEM_MATHBEADD10]         = 0x37,
    [ITEM_MATHBEADD11]         = 0x59,
    [ITEM_MATHBEADD12]         = 0,
    [ITEM_MATHBEADD13]         = 0,
    [ITEM_MATHBEADD14]         = 0,
    [ITEM_MATHBEADD15]         = 0,
    [ITEM_CRYSTAL]             = 0,
    [ITEM_BELL]                = 0,
    [ITEM_CAKE]                = 0,
    [ITEM_HAT]                 = 0,
    [ITEM_SHIPPARTS]           = 0,
    [ITEM_BRONZEMEDAL]         = 0,
    [ITEM_SILVERMEDAL]         = 0,
    [ITEM_GOLDMEDAL]           = 0,
    [ITEM_LETTER]              = 0,
    [ITEM_WOOD]                = 0x4B,
    [ITEM_RAFT]                = 0,
    [ITEM_GOLDENLEAFBUTTERFLY] = 0,
    [ITEM_GOLDENFRUIT]         = 0,
    [ITEM_GOLDENFLOWER]        = 0x58,
    [ITEM_PSYCHICFISH]         = 0,
    [ITEM_SHOVEL]              = 0,
    [ITEM_JEWELOFFIRE]         = 0x54,
    [ITEM_JEWELOFWATER]        = 0x4C,
    [ITEM_JEWELOFWIND]         = 0x55,
    [ITEM_MIGHTYFISH]          = 0,
    [ITEM_SILVERPOWDER]        = 0x23,
    [ITEM_MOLASSES]            = 0x24,
    [ITEM_KOKKACLAW]           = 0x39,
    [ITEM_BUTAMUSHITHORN]      = 0x3A,
    [ITEM_NEEDLEGATORTEETH]    = 0x3B,
    [ITEM_FLOWER]              = 0,
    [ITEM_ELECTRIC_EEL]        = 0,
    [ITEM_BLACKWATER]          = 0,
    [ITEM_REDCANDY]            = 0x3E,
    [ITEM_BLUECANDY]           = 0x3F,
    [ITEM_GREENCANDY]          = 0x40,
    [ITEM_BLACKCANDY]          = 0x41,
    [ITEM_SILVERCANDY]         = 0x42,
    [ITEM_GOLDENCANDY]         = 0x43,
    [ITEM_FORBIDDENMUSHROOM]   = 0x29,
    [ITEM_BLUEPOWDER]          = 0x25,
    [ITEM_COCONUTS]            = 0,
    [ITEM_FUNGALEATHER]        = 0,
    [ITEM_GRANDPASBRACELET]    = 0x3C,
    [ITEM_WEEDKILLER]          = 0,
    [ITEM_FUNGATREE]           = 0x49,
    [ITEM_FUNGASAP]            = 0x48,
    [ITEM_1000YEAROLDBELL]     = 0x26,
    [ITEM_FUNGADRUM]           = 0x5E,
    [ITEM_MIGHTYFISHFOOD]      = 0x56,
    [ITEM_UNUSUALKEY]          = 0x2C,
    [ITEM_CHUCKLINGMUSHROOM]   = 0,
    [ITEM_WEEPINGMUSHROOM]     = 0,
    [ITEM_MYSTERIOUSMUSHROOM]  = 0x27,
    [ITEM_OVENBAKEDMUSHROOM]   = 0,
    [ITEM_SACREDFISH]          = 0x60,
    [ITEM_CHICK2]              = 0,
    [ITEM_CHICK3]              = 0,
    [ITEM_GOLDENBOWL]          = 0,
    [ITEM_FLOWERTEARS2]        = 0,
    [ITEM_SMALLDRUM]           = 0x3D,
    [ITEM_RISEANDSHINEPOWDER]  = 0x57,
    [ITEM_BANANAJUICE]         = 0,
    [ITEM_CHIEFSPEAR]          = 0x4A,
    [ITEM_CHARLESPANTS]        = 0,
    [ITEM_THREECRYSTALBALLS]   = 0x28,
    [ITEM_WHATTHETHIEFLOST]    = 0x52,
    [ITEM_WHATTHETHIEFFORGOT]  = 0x5F,
    [ITEM_BOSSJEWEL]           = 0x5D,
    [ITEM_ORDINARYMUSHROOM]    = 0x2A,
    [ITEM_TRASHCAN]            = 0,
    [ITEM_SEASHELLNECKLACE]    = 0x4D,
    [ITEM_THIEFSWIRE]          = 0,
    [ITEM_STRONGWIRE]          = 0,
    [ITEM_10000YEAROLDBELL]    = 0x5B,
    [ITEM_1000000YEAROLDBELL]  = 0x5C,
    [ITEM_COLDMEDICINE]        = 0,
    [ITEM_YANSLUNCHBOX]        = 0,
    [ITEM_KEYTOOLPOND]         = 0,
    [ITEM_HEALINGHERBS]        = 0x4F,
    [ITEM_KNOWLEDGEFRUIT]      = 0x47,
    [ITEM_SEAWEED]             = 0x50,
    [ITEM_MINERSHAT]           = 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

ItemInit *ITEM_INIT_TABLE[97] = {
    &ITEM_INIT_DEFAULT, &ITEM_INIT_FROG, &ITEM_INIT_LOSTDWARF, &ITEM_INIT_BANANAS,
    &ITEM_INIT_FURIOUSTORNADO, &ITEM_INIT_100YEAROLDBELL, &ITEM_INIT_100YEAROLDKEY, &ITEM_INIT_CHARITYWINGS,
    &ITEM_INIT_BITINGPLANTFLOWER, &ITEM_INIT_HEALINGMUSHROOM, &ITEM_INIT_BUCKET, &ITEM_INIT_TEARJAR,
    &ITEM_INIT_FLOWERTEARS, &ITEM_INIT_BARON, &ITEM_INIT_BAKEDYAM, &ITEM_INIT_LEAFBUTTERFLY,
    &ITEM_INIT_BUCKETOFWATER, &ITEM_INIT_DIRTYMIRROR, &ITEM_INIT_FUNKYPARASOL, &ITEM_INIT_WOODBOOMERANG,
    &ITEM_INIT_STONEBOOMERANG, &ITEM_INIT_IRONBOOMERANG, &ITEM_INIT_JUMPINGPANTS, &ITEM_INIT_LUNCHBOX,
    &ITEM_INIT_LARGELUNCHBOX, &ITEM_INIT_GRAPPLE, &ITEM_INIT_1000YEAROLDKEY, &ITEM_INIT_LARGEKEYPANEL_1,
    &ITEM_INIT_LARGEKEYPANEL_2, &ITEM_INIT_LARGEKEYPANEL_3, &ITEM_INIT_LARGEKEYPANEL_4, &ITEM_INIT_LARGEKEYPANEL_5,
    &ITEM_INIT_RAINESSENCE, &ITEM_INIT_CHEESE, &ITEM_INIT_FLOWERSEEDS, &ITEM_INIT_SILVERPOWDER,
    &ITEM_INIT_MOLASSES, &ITEM_INIT_BLUEPOWDER, &ITEM_INIT_1000YEAROLDBELL, &ITEM_INIT_MYSTERIOUSMUSHROOM,
    &ITEM_INIT_THREECRYSTALBALLS, &ITEM_INIT_FORBIDDENMUSHROOM, &ITEM_INIT_ORDINARYMUSHROOM, &ITEM_INIT_GREENPIGBAG,
    &ITEM_INIT_SMALLKEY, &ITEM_INIT_BUNKFLOWER, &ITEM_INIT_MATHBEADD1, &ITEM_INIT_MATHBEADD2,
    &ITEM_INIT_MATHBEADD3, &ITEM_INIT_MATHBEADD4, &ITEM_INIT_MATHBEADD5, &ITEM_INIT_MATHBEADD6,
    &ITEM_INIT_MATHBEADD7, &ITEM_INIT_MATHBEADD8, &ITEM_INIT_MATHBEADD9, &ITEM_INIT_MATHBEADD10,
    &ITEM_INIT_BOMB, &ITEM_INIT_KOKKACLAW, &ITEM_INIT_BUTAMUSHITHORN, &ITEM_INIT_NEEDLEGATORTEETH,
    &ITEM_INIT_GRANDPASBRACELET, &ITEM_INIT_SMALLDRUM, &ITEM_INIT_REDCANDY, &ITEM_INIT_BLUECANDY,
    &ITEM_INIT_GREENCANDY, &ITEM_INIT_BLACKCANDY, &ITEM_INIT_SILVERCANDY, &ITEM_INIT_GOLDENCANDY,
    &ITEM_INIT_PINKPIGBAG, &ITEM_INIT_NAVYPIGBAG, &ITEM_INIT_YELLOWPIGBAG, &ITEM_INIT_KNOWLEDGEFRUIT,
    &ITEM_INIT_FUNGASAP, &ITEM_INIT_FUNGATREE, &ITEM_INIT_CHIEFSPEAR, &ITEM_INIT_WOOD,
    &ITEM_INIT_JEWELOFWATER, &ITEM_INIT_SEASHELLNECKLACE, &ITEM_INIT_ORANGEPIGBAG, &ITEM_INIT_HEALINGHERBS,
    &ITEM_INIT_SEAWEED, &ITEM_INIT_PIPE, &ITEM_INIT_WHATTHETHIEFLOST, &ITEM_INIT_FLASHPANTS,
    &ITEM_INIT_JEWELOFFIRE, &ITEM_INIT_JEWELOFWIND, &ITEM_INIT_MIGHTYFISHFOOD, &ITEM_INIT_RISEANDSHINEPOWDER,
    &ITEM_INIT_GOLDENFLOWER, &ITEM_INIT_MATHBEADD11, &ITEM_INIT_FUELBARREL, &ITEM_INIT_10000YEAROLDBELL,
    &ITEM_INIT_1000000YEAROLDBELL, &ITEM_INIT_BOSSJEWEL, &ITEM_INIT_FUNGADRUM, &ITEM_INIT_WHATTHETHIEFFORGOT,
    &ITEM_INIT_SACREDFISH
};


ApReward AP_REWARDS[8] = {
    { 500, 336, 483 },
    { 1000, 336, 480 },
    { 2000, 336, 481 },
    { 5000, 336, 482 },
    { 10000, 336, 483 },
    { 20000, 336, 480 },
    { 100000, 336, 481 },
    { 500000, 336, 482 }
};

// INCLUDE_ASM("nonmatchings/main/game/reward", func_8003F3D4);
void func_8003F3D4(u8* self)
{
    u8 state;

    state = self[4];
    switch (state) {
    case 0:
        self[4] = state + 1;
        *(s16*)(self + 0x6C) = D_8007D6E0[self[3]].unk0;
        *(s16*)(self + 0x6E) = D_8007D6E0[self[3]].unk1;
        *(s16*)(self + 0x70) = D_8007D6E0[self[3]].unk2;
        *(s16*)(self + 0x72) = D_8007D6E0[self[3]].unk3;
        *(s16*)(self + 0x1E) = D_8007D6E0[self[3]].unk4;
        *(int*)(self + 0x3C) = SPR_DATA[D_8007D6E0[self[3]].unk6];
        *(s16*)(self + 0xA6) = D_8007D6E0[self[3]].unk5;
        *(int*)(self + 0x24) = D_8007D6E0[self[3]].unk8[*(s16*)(self + 0xA6)];
        switch (self[3]) {
        case 1:
            func_8012FA34(0xE, 0);
            self[0xD] = 1;
            *(s16*)(self + 8) = GetClut(0xE0, 0x1F0);
            *(s16*)(self + 0x1E) = GetTPage(0, 0, 0x1C0, 0);
            break;
        case 4:
            if (self[0xD] != 0) {
                *(s16*)(self + 8) = GetClut(0x120, 0x1ED);
            }
            break;
        case 9:
            self[0xD] = 1;
            *(s16*)(self + 8) = GetClut(0xE0, 0x1F0);
            break;
        case 0xD:
            *(int*)(self + 0x24) = D_80131D84[self[0xC]];
            readAnimFrameCount(self);
            break;
        }
        *(s16*)(self + 0x98) = 3;
        *(int*)(self + 0x28) = (int)&D_8007728C;
        self[0xA5] = 1;
        self[0xA] = 2;
        *(int*)(self + 0x8C) = 0;
        readAnimFrameCount(self);
        break;
    case 1:
        if (self[3] == 3) {
            if (*(u16*)(self + 0x2E) & 1) {
                *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) - 0x20) & 0xFF;
            } else {
                *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) + 0x20) & 0xFF;
            }
        } else {
            if (*(u16*)(self + 0x2E) & 1) {
                *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) + 0x14) & 0xFF;
            } else {
                *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) - 0x14) & 0xFF;
            }
        }
        if (*(u16*)(self + 0x2E) & 2) {
            *(int*)(self + 0x14) += 0x50000;
        } else {
            applyFrameVelocityX(self);
        }
        if ((s16)probeCollisionAtDepthB(self, *(s16*)(*(int*)(self + 0x40) + 2), *(s16*)(self + 0x16)) != 0) {
            self[0] = 2;
            self[0xA5] = 0;
            *(int*)(self + 0x8C) = (-SPAD->hitSlope << 2) & 0xFF;
            self[4] = 2;
            self[5] = 0;
            self[6] = 0;
        }
        if (cullAndQueueDraw(self) == 0) {
            self[4] = 3;
        }
        break;
    case 2:
        updateItemPickupAnim((GameObject*)self);
        if (cullAndQueueDraw(self) == 0) {
            self[4] = 3;
        }
        break;
    case 3:
        freeWeaponObject(self);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", updateHopFall);
void updateHopFall(u8* self)
{
    switch (self[5]) {
    case 0:
        if (*(u16*)(self + 0x2E) & 2) {
            *(s16*)(self + 0x7E) = 0x200;
        } else {
            *(s16*)(self + 0x7E) = -0x200;
        }
        *(int*)(self + 0x28) = (int)&D_80077274;
        self[5]++;
        if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            *(int*)(self + 0x24) = D_8013A44C;
        } else {
            *(int*)(self + 0x24) = D_80134018;
        }
        readAnimFrameCount(self);
    case 1:
        if (*(u16*)(self + 0x2E) & 1) {
            *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) - 0x14) & 0xFF;
        } else {
            *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) + 0x14) & 0xFF;
        }
        if (!(*(u16*)(self + 0x2E) & 2)) {
            applyFrameVelocityX(self);
        }
        *(int*)(self + 0x14) += *(s16*)(self + 0x7E) << 8;
        if ((*(s16*)(self + 0x7E) += (*(u16*)(self + 0x2E) & 2) ? 0x50 : 0x20) > 0) {
            self[5]++;
        }
        break;
    case 2:
        if (*(u16*)(self + 0x2E) & 1) {
            *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) - 0x14) & 0xFF;
        } else {
            *(int*)(self + 0x8C) = (*(int*)(self + 0x8C) + 0x14) & 0xFF;
        }
        if (!(*(u16*)(self + 0x2E) & 2)) {
            applyFrameVelocityX(self);
        }
        *(int*)(self + 0x14) += *(s16*)(self + 0x7E) << 8;
        *(s16*)(self + 0x7E) += 0x20;
        if ((s16)probeCollisionAtDepthB(self, *(s16*)(*(int*)(self + 0x40) + 2), (s16)(*(u16*)(self + 0x16) + 0x14)) != 0) {
            self[4] = 2;
            self[5] = 0;
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", func_8003F9A4);
void func_8003F9A4(u8* self)
{
    u8* obj;
    int sfx;

    switch (self[4]) {
    case 0:
        self[0] = 2;
        self[0xA] = 2;
        self[0xA5] = 1;
        self[0xD] = 0;
        *(int*)(self + 0x8C) = 0;
        *(s16*)(self + 0x6C) = 10;
        *(s16*)(self + 0x6E) = 0x14;
        *(s16*)(self + 0x70) = 0x10;
        *(s16*)(self + 0x72) = 0x20;
        self[4]++;
        *(int*)(self + 0x3C) = SPAD->sprData[3];
        if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            *(s16*)(self + 0x1E) = 10;
            *(int*)(self + 0x24) = D_8013A44C;
        } else {
            *(s16*)(self + 0x1E) = 8;
            *(int*)(self + 0x24) = D_80134018;
        }
        readAnimFrameCount(self);
        cullAndQueueDraw(self);
        break;
    case 1:
        if (cullAndQueueDraw(self) != 0) {
            updateHopFall(self);
        }
        break;
    case 2:
        if (cullAndQueueDraw(self) != 0) {
            if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
                D_8009C263++;
                func_80126760(self[3]);
                if (D_8009BCCA < 4) {
                    sfx = 0xF7;
                } else {
                    sfx = 0xF9;
                }
            } else {
                sfx = 0x34;
            }
            playSFX(sfx);
            func_800E98A4(self, *(s16*)(self + 0x12), *(s16*)(self + 0x16), *(s16*)(self + 0x1A));
            if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
                D_8009C616 |= 1 << self[3];
                obj = allocActorObject();
                if (obj != NULL) {
                    obj[0] = 1;
                    obj[2] = 3;
                    obj[3] = self[3];
                    obj[0xC] = self[0xC];
                    *(VEC3*)(obj + 0x10) = *(VEC3*)(self + 0x10);
                    obj[0x6B] = self[0x6B];
                    obj[0x1D] = self[0x1D];
                    *(s16*)(obj + 0x7A) = 0;
                    obj[4] = 0;
                    obj[5] = 0;
                    obj[6] = 0;
                }
            }
            self[4] = 3;
        }
        break;
    case 3:
        freeWeaponObject(self);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", applyItemEffect);
void applyItemEffect(GameObject* obj, int arg1, short arg2, short arg3, int arg4)
{

    if (func_800236F4(obj->id) == ITEM_CHICK) {
        switch (obj->active) {
            case 0:
                spawnItem(obj->visible, obj->type, arg1);
                break;
            case 1:
                spawnItemDrop(obj->visible, obj->type, arg1);
                break;
            case 2:
                spawnItemAtPos(obj->visible, obj->type, arg1, arg2, (int) arg3);
                break;
            case 3:
                spawnItemDropAtPos(obj->visible, obj->type, arg1, arg2, (int) arg3);
                break;
            case 4:
                spawnItemBounce(obj->visible, obj->type, arg1, arg2, (int) arg3);
                break;
            case 5:
                spawnItemFixed(obj->visible, obj->type, arg1);
                break;
            case 6:
                func_80123188(arg1, obj->id, arg2, arg3);
                break;
            case 8:
                spawnItemChest(obj->visible, obj->type, arg1);
                break;
        }
        if (arg4 != 0) {
            func_80023794(obj->id);
        }
        if (obj->subState == 0) {
            playSFX(21);
        }
    }
}

void initItemObject(GameObject* obj)
{
    short x;
    short y;
    int color;
    int* anim;
    ItemInit* init;

    if ((obj->id == ITEM_JEWELOFWIND) && (GAME.event[EVENT_THEJUNGLEPIGBAG] == 0)) {
        obj->state = 2;
        return;
    }
    obj->unk68 = 0;
    obj->touchFlag = 0;
    init = ITEM_INIT_TABLE[ITEM_INIT_INDEX[obj->id]];
    obj->drawType = init->drawType;
    obj->tpage = (short)init->tpage;
    (*(s8 *)&obj->priority) = -9;
    obj->drawFlags = (u_char)init->drawFlags;
    setHitbox(obj, (short)init->hitboxX, (short)init->hitboxY, (short)init->hitboxW, (short)init->hitboxH);

    obj->spriteBank = *(&SPR_DATA[init->spriteBank]);
    obj->animFrame = 1;
    if (obj->id == ITEM_LOSTDWARF) {
        if ((u_long) (obj->param & 0x7F) >= 4U) {
            obj->scale = 0x2000;
            setHitbox(obj, (short) (init->hitboxX * 2), (short) (init->hitboxY * 2), (short) (init->hitboxW * 2), (short) (init->hitboxH * 2));
        } else {
            obj->scale = 0x1000;
        }
    }

    switch (init->clutMode) {
        case 0:
            x = init->clutX;
            y = init->clutY;
            obj->clut = GetClut((int) x, (int) y);
            break;
        case 1:
            x = init->clutX;
            y = init->clutY;
            obj->clut = GetClut((int) x, (int) y + (obj->param & 0x7F));
            break;
        case 2:
            x = AP_REWARDS[obj->param & 0x7F].clutX;
            y = AP_REWARDS[obj->param & 0x7F].clutY;
            obj->clut = GetClut((int) x, (int) y);
            break;
        case 3:
            if (GAME.item[ITEM_JUMPINGPANTS] == 0) {
                color = 0;
            } else {
                color = 2;
                if (GAME.item[ITEM_DASHINGPANTS] == 0) {
                    color = 1;
                }
            }
            x = init->clutX;
            y = init->clutY;
            obj->clut = GetClut(x, y + color);
            break;
    }

    switch (init->animMode) {
        case 0:
            anim = init->anim;
            obj->anim = (int) *anim;
            break;
        case 1:
            anim = (int) ((obj->param & 0x7F) * 4) + *(int*)&init->anim;
            obj->anim = (int) *anim;
            break;
    }
    readAnimFrameCount(obj);
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardNone);
void rewardNone(GameObject* obj)
{
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardItem);
void rewardItem(GameObject* obj)
{
    u_char current_item;

    addItemToInventory(obj->id, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    current_item = obj->id;
    switch (current_item) {
        case ITEM_BOMB:
            setEventComplete(EVENT_INEEDABOMB, 4);
            break;
        case ITEM_PIPE:
            GAME.pipeState = 1;
            break;
        case ITEM_GOLDENFLOWER:
            GAME.goldenFlowerState = 1;
            break;
        case ITEM_TEARJAR:
            setEventComplete(EVENT_INEEDATEARBOTTLE, 1);
            break;
        case ITEM_MIGHTYFISHFOOD:
            setEventComplete(EVENT_WHATSTHEUNDERWATER, 0);
            break;
        case ITEM_WHATTHETHIEFFORGOT:
            setEventStarted(EVENT_WHATTHETHIEFFORGOT, 1, 1);
            break;
        case ITEM_BOSSJEWEL:
            setEventComplete(EVENT_THEBOSSTREASURE, 1);
            addPlayerAP(100000);
            break;
        case ITEM_SEASHELLNECKLACE:
            setEventStarted(EVENT_THEMERMAIDNECKLACE, 0, 0);
            break;
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardHeart);
void rewardHeart(GameObject* obj)
{
    if (D_8009BCA0 == 0) {
        func_800E92D4(0x64, obj->x.p.whole, obj->y.p.whole, obj->z.p.whole);
        playSFX(9);
        if (!(obj->param & 0x80)) {
            func_8002367C(obj->objectIndex);
        }
        if (!(obj->param & 0x7F)) {
            *(short*)&D_800A5430+=1;
            if ((short)GAME.playerHealthDisplayed < *(short*)&D_800A5430 ) {
                *(short*)&D_800A5430 = GAME.playerHealthDisplayed;
            }
        } else {
            *(short*)&D_800A5430+=2;
            if ((short)GAME.playerHealthDisplayed < *(short*)&D_800A5430 ) {
                *(short*)&D_800A5430 = GAME.playerHealthDisplayed;
            }
        }
        D_800A5432 = D_800A5430;
        GAME.playerHealth = (u_char) D_800A5430;
        obj->state++;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardEffectOnly);
void rewardEffectOnly(GameObject* obj)
{
    func_800E92D4(AP_REWARDS[obj->param & 0x7F].ap, obj->x.p.whole, obj->y.p.whole, obj->z.p.whole);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    playSFX(9);
    obj->state+=1;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardBakedYam);
void rewardBakedYam(GameObject* obj)
{
    addItemToInventory(ITEM_BAKEDYAM, 1, true);
    if ((GAME.event[EVENT_SOMETHINGCOOKIN] & 0xFF) == 3) {
        GAME.event[EVENT_SOMETHINGCOOKIN] += 1;
    }
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex, &GAME.event[EVENT_SOMETHINGCOOKIN]);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardDirtyMirror);
void rewardDirtyMirror(GameObject* obj)
{
    GAME.unk54e = 5;
    addItemToInventory(ITEM_DIRTYMIRROR, 1, true);
    setEventStarted(EVENT_AMAGICMIRROR, 0, 0);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardVitalityMaxUp);
void rewardVitalityMaxUp(GameObject* obj)
{
    if (D_8009BCA0 == 0) {
        increaseMaxHealth();
        printInfoMessage(MSG_VITALITYMAXUP_ACQUIRED, MSG_TYPE_REWARD);
        playSFX(10);
        if (!(obj->param & 0x80)) {
            func_8002367C(obj->objectIndex);
        }
        obj->state++;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardWoodBoomerang);
void rewardWoodBoomerang(GameObject* obj)
{
    addItemToInventory(ITEM_WOODBOOMERANG, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardStoneBoomerang);
void rewardStoneBoomerang(GameObject* obj)
{
    addItemToInventory(ITEM_STONEBOOMERANG, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardIronBoomerang);
void rewardIronBoomerang(GameObject* obj)
{
    addItemToInventory(ITEM_IRONBOOMERANG, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardOneUp);
void rewardOneUp(GameObject* obj)
{
    u_char lives = GAME.playerLives;
    if (lives < 99) {
        GAME.playerLives = (u_char)(lives+1);
        printInfoMessage(MSG_ONEUP_ACQUIRED, MSG_TYPE_REWARD);
        playSFX(10);
    }
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardGoldenBowl);
void rewardGoldenBowl(GameObject* obj)
{
    u_char health;

    if (D_8009BCA0 == 0) {
        health = GAME.playerHealthDisplayed;
        if (health < 16) {
            health += GAME.bonusHealth;
            GAME.playerHealthDisplayed = health;
            if ((u_long) ((byte)health & 0xFF) >= 17) {
                GAME.playerHealthDisplayed = 16;
            }
            playSFX(10);
            D_800A5430 = (u_short*)(*(char*)&GAME.playerHealthDisplayed);
            D_800A5432 = *(char*)&GAME.playerHealthDisplayed;
            *(char*)&GAME.playerHealth = *(char*)&GAME.playerHealthDisplayed;
        }
        GAME.goldenBowlState = 1;
        D_800B078C = &D_800121C8;
        playSFX(10);
        if (!(obj->param & 0x80)) {
            func_8002367C(obj->objectIndex);
        }
        obj->state++;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardBitingPlantFlower);
void rewardBitingPlantFlower(GameObject* obj)
{
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = obj->subState;
    switch (temp_v1) {
        case 0:
            addItemToInventory(ITEM_BITINGPLANTFLOWER, 1, true);
            setEventStarted(EVENT_BITINGPLANTFLOWER, 0, 0);
            if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
                GAME.bittingPlantFlowerState = 2;
            }
            if (!(obj->param & 0x80)) {
                func_8002367C(obj->objectIndex);
            }
            obj->cooldownTimer = 0x12CU;
            asm("");
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            PLAYER.obj.state = PLAYER_SCRIPTED;
            PLAYER.obj.subState = PLAYER_IDLE;
            PLAYER.obj.step = 0;
            PLAYER.obj.unk7 = 0;
            obj->subState++;
            return;
        case 1:
            temp_v0 = obj->cooldownTimer - 1;
            obj->cooldownTimer = temp_v0;
            if ((temp_v0 << 0x10) == 0) {
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                PLAYER.obj.state = PLAYER_ACTIVE;
                PLAYER.obj.subState = PLAYER_IDLE;
                PLAYER.obj.step = 0;
                PLAYER.obj.unk7 = 0;
                obj->state++;
            }
            return;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardGrapple);
void rewardGrapple(GameObject* obj)
{
    addItemToInventory(ITEM_GRAPPLE, 1, true);
    setEventComplete(EVENT_APRECIOUSTREASURECHEST, 0);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardGrappleJack);
void rewardGrappleJack(GameObject* obj)
{
    addItemToInventory(ITEM_GRAPPLEJACK, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardCrystalBalls);
void rewardCrystalBalls(GameObject* obj)
{
    switch (GAME.event[EVENT_LOSTANDFOUND]) {
        case 0:
            setEventStarted(EVENT_LOSTANDFOUND, 0, 0);
            printInfoMessage(MSG_LOSTANDFOUND_STARTED, MSG_TYPE_REWARD);
            break;
        case 1:
            printInfoMessage(MSG_LOSTANDFOUND_PROGRESS, MSG_TYPE_REWARD);
            GAME.event[EVENT_LOSTANDFOUND]+= 1;
            break;
        case 2:
            addItemToInventory(ITEM_THREECRYSTALBALLS, 1, true);
            setEventComplete(EVENT_LOSTANDFOUND, 0);
            break;
    }
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardMysteriousMushroom);
void rewardMysteriousMushroom(GameObject* obj)
{
    setEventComplete(EVENT_THEMISTERIOUSMUSHROOM, 0);
    addItemToInventory(obj->id, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardFlowerSeeds);
void rewardFlowerSeeds(GameObject* obj)
{
    setEventStarted(EVENT_FLOWERSEEDS, 0, 0);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    addItemToInventory(obj->id, 1, true);
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardPigBag);
void rewardPigBag(GameObject* obj)
{
    int temp;

    switch (obj->subState) {
        case 0:
            addItemToInventory(obj->id, 1, true);
            if (!(obj->param & 0x80)) {
                func_8002367C(obj->objectIndex);
            }
            switch (obj->id) {
                case ITEM_REDPIGBAG:
                    setEventComplete(EVENT_ASTORMYPIGBAG, 2);
                    break;
                case ITEM_ORANGEPIGBAG:
                    setEventComplete(EVENT_THEMOUSEPIGBAG, 2);
                    break;
                case ITEM_YELLOWPIGBAG:
                    setEventComplete(EVENT_THEUNDERWATERPIG, 2);
                    break;
                case ITEM_GREENPIGBAG:
                    setEventComplete(EVENT_THEFIREPIGBAG, 2);
                    break;
                case ITEM_BLUEEVILPIGBAG:
                    setEventComplete(EVENT_THEEVILPIGBAG, 2);
                    break;
                case ITEM_NAVYPIGBAG:
                    setEventComplete(EVENT_THEJUNGLEPIGBAG, 2);
                    break;
                case ITEM_PINKPIGBAG:
                    setEventComplete(EVENT_THEHAUNTEDPIGBAG, 2);
                    break;
            }
            obj->cooldownTimer = 0x168U;
            obj->subState++;
            return;
        case 1:
            temp = (*(u16 *)&obj->cooldownTimer) - 1;
            obj->cooldownTimer = temp;
            if ((temp << 0x10) == 0) {
                switch (obj->id) {
                    case ITEM_REDPIGBAG:        
                        setEventStarted(EVENT_PHOENIXMOUNTAIN, 0, 3);
                        break;
                    case ITEM_ORANGEPIGBAG:
                        setEventStarted(EVENT_BACCUSVILLAGE, 0, 3);
                        break;
                    case ITEM_YELLOWPIGBAG:
                        setEventStarted(EVENT_TRICKVILLAGE, 0, 3);
                        break;
                    case ITEM_GREENPIGBAG:
                        setEventStarted(EVENT_LAVACAVES, 0, 3);
                        break;
                    case ITEM_BLUEEVILPIGBAG:
                        setEventStarted(EVENT_THE100FLOWERFOREST, 0, 3);
                        break;
                    case ITEM_NAVYPIGBAG:
                        setEventStarted(EVENT_THEDEEPJUNGLEPIG, 0, 3);
                        break;
                    case ITEM_PINKPIGBAG:
                        setEventStarted(EVENT_THEHAUNTEDMANSION, 0, 3);
                        break;
                }
                obj->state++;
            }
            return;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardConditionalItem);
void rewardConditionalItem(GameObject* obj)
{
    if ((GAME.selectedArea == AREA10_DEEPJUNGLE) || (obj->param == 1)) {
        addItemToInventory(obj->id, 1, true);
    }
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardJewel);
void rewardJewel(GameObject* obj)
{
    u_char current_item;
    
    current_item = obj->id;
    switch (current_item) {
        case ITEM_JEWELOFFIRE: 
            if (GAME.expLevel[0] == 9) {
                setEventComplete(EVENT_REDHIDDENPOWERS, 1);
                addItemToInventory(obj->id, 1, true);
                asm("");
                if (!(obj->param & 0x80)) {
                    func_8002367C(obj->objectIndex);
                    asm("");
                }
                obj->state++;
            } else {
                if (obj->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    obj->cooldownTimer = 0x78;
                } 
                obj->state--;
            }
            break;
        case ITEM_JEWELOFWATER: 
            if (GAME.expLevel[2] == 9) {
                setEventComplete(EVENT_BLUEHIDDENPOWERS, 0);
                addItemToInventory(obj->id, 1, true);
                asm("");
                if (!(obj->param & 0x80)) {
                    func_8002367C(obj->objectIndex);
                    asm("");
                }
                obj->state++;
            } else {
                setEventStarted(EVENT_BLUEHIDDENPOWERS, 0, 0);
                if (obj->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    obj->cooldownTimer = 0x78;
                } 
                obj->state--;
            }
            break;
        case ITEM_JEWELOFWIND:
            if (GAME.expLevel[1] == 9) {
                setEventComplete(EVENT_GREENHIDDENPOWERS, 1);
                addItemToInventory(obj->id, 1, true);
                if (!(obj->param & 0x80)) {
                    func_8002367C(obj->objectIndex);
                }
                obj->state++;
            } else {
                setEventStarted(EVENT_GREENHIDDENPOWERS, 0, 1);
                if (obj->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    obj->cooldownTimer = 0x78;
                } 
                obj->state--;
            }
            break;
    }
    return;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardSafeMushroom);
void rewardSafeMushroom(GameObject* obj)
{
    setEventComplete(EVENT_ASAFEMUSHROOM, 0);
    addItemToInventory(obj->id, 1, true);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardAnimalDash);
void rewardAnimalDash(GameObject* obj)
{
    printInfoMessage(MSG_ANIMALDASH_ACQUIRED, MSG_TYPE_REWARD);
    GAME.area00_eventControl |= 0x40;
    playSFX(10);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    GAME.unk6ad = 1;
    GAME.unk736 = 1;
    obj->state++;
}

// INCLUDE_ASM("nonmatchings/main/game/reward", rewardPants);
void rewardPants(GameObject* obj)
{   
    if (GAME.item[ITEM_JUMPINGPANTS] == 0) {
        addItemToInventory(ITEM_JUMPINGPANTS, 1, true);
    } else if ((GAME.item[ITEM_DASHINGPANTS] == 0)) {
        addItemToInventory(ITEM_DASHINGPANTS, 1, true);
    } else if (GAME.item[ITEM_FLASHPANTS] == 0) {
        addItemToInventory(ITEM_FLASHPANTS, 1, true);
    }
    playSFX(10);
    if (!(obj->param & 0x80)) {
        func_8002367C(obj->objectIndex);
    }
    obj->state++;
}
