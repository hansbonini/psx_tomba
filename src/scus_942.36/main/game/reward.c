#include "common.h"
#include "game.h"

u_char D_8007D6D0_data[0x10] asm("D_8007D6D0") = {
    7, 7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", updateItemPickupAnim);
void updateItemPickupAnim(unkstruct_800A6D50* arg0)
{
    int var_a1;
    int var_v0;
    u_short temp_a1;
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = arg0->unk6;
    switch (temp_v1) {                              // irregular
        case 0:
            playSFX(*(&D_8007D6D0 + arg0->item_id));
            func_800E92D4(0x1F4, arg0->unk12, arg0->unk16, arg0->unk1A);
            arg0->unkA5 = 0;
            if (arg0->item_id != ITEM_FLOWERTEARS) {
                arg0->unkB = 1;
                arg0->unkF = 4;
            }
            arg0->unk82 = -1024;
            *(int*)&arg0->unk28 = &D_8007722C;
            if (arg0->unk2E & 2) {
                *(int*)&arg0->unk28 = &D_800771FC;
            }
            arg0->unk6 = (u_char) (arg0->unk6 + 1);
            break;
        case 1:
            temp_a1 = arg0->unk2E;
            if (temp_a1 & 2) {
                applyAnimVelocityX(arg0, temp_a1 & 1);
            } else {
                applyAnimVelocityX(arg0, (temp_v1 - temp_a1) & 0xFFFF);
            }
            temp_v0 = arg0->unk82 + 64;
            arg0->unk82 = temp_v0;
            if ((short) temp_v0 >= 1025) {
                arg0->unk82 = 1024;
            }
            *(int*)&arg0->unk14 = (int) (*(int*)&arg0->unk14 + ((short) arg0->unk82 << 8));
            break;
    }
    if (arg0->unk2E & 1) {
        var_v0 = arg0->unk8C + 24;
    } else {
        var_v0 = arg0->unk8C - 24;
    }
    arg0->unk8C = (int) (var_v0 & 0xFF);
}

extern int D_80077274;
extern int D_8013A44C;
extern int D_80134018;
extern u8 D_8009C263;
extern u8 D_8009C616;
extern int D_80131D84[];
extern int D_8007728C;

typedef struct {
    int x;
    int y;
    int z;
} VEC3;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    s16 unk6;
    int* unk8;
} unk_8007D6E0;

extern unk_8007D6E0 D_8007D6E0[];

unk_8007D6E0 D_8007D6E0[14] = {
    { 0xA, 0x14, 0x10, 0x20, 1, 0, 2, (int*)0x80014CCC },
    { 0x10, 0x20, 8, 0x18, 0x13, 0x24, 5, (int*)0x8013A078 },
    { 0x10, 0x20, 0xA, 0x14, 8, 0, 3, (int*)0x8013D954 },
    { 0x10, 0x20, 0x10, 0x20, 1, 0x11, 2, (int*)0x8013EFE8 },
    { 0x10, 0x20, 0x10, 0x20, 2, 0xC, 8, (int*)0x8012DDA4 },
    { 0x10, 0x20, 0x10, 0x20, 1, 0, 8, (int*)0x8013E574 },
    { 8, 0x10, 8, 0x10, 9, 0, 3, (int*)0x8012D3F8 },
    { 0x10, 0x20, 0xE, 0x1C, 0xB, 6, 5, (int*)0x801388B4 },
    { 0xA, 0x14, 0x10, 0x20, 1, 0x1F, 2, (int*)0x80137AAC },
    { 0x10, 0x20, 8, 0x10, 1, 4, 5, (int*)0x801338C0 },
    { 8, 0x10, 8, 0x10, 1, 0x1E, 5, (int*)0x80139A4C },
    { 0x10, 0x20, 0x10, 0x20, 1, 0xB, 5, (int*)0x80139A4C },
    { 0x10, 0x20, 0x10, 0x20, 1, 4, 2, (int*)0x80131694 },
    { 0xA, 0x14, 0xA, 0x14, 5, 0, 5, (int*)0x80131D84 }
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

s16 D_8007D988[0x100] = {
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

s16 D_8007DB88[0x100] = {
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

u8 D_8007DD88[0xA0] = {
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

u8 D_8007DE28[0x60] = {
    0x8C, 0, 4, 0x80, 0xE0, 0, 4, 0x80, 0x68, 2, 4, 0x80, 0x5C, 3, 4, 0x80,
    0xE4, 3, 4, 0x80, 0x68, 4, 4, 0x80, 0xE8, 4, 4, 0x80, 0x64, 5, 4, 0x80,
    0xC8, 5, 4, 0x80, 0x2C, 6, 4, 0x80, 0x90, 6, 4, 0x80, 0x18, 7, 4, 0x80,
    0xC, 8, 4, 0x80, 0x5C, 9, 4, 0x80, 0xCC, 9, 4, 0x80, 0x30, 0xA, 4, 0x80,
    0x28, 0xB, 4, 0x80, 0x98, 0xB, 4, 0x80, 0xC, 0xC, 4, 0x80, 0xA0, 0xD, 4, 0x80,
    0x24, 0xE, 4, 0x80, 0xD8, 0xF, 4, 0x80, 0x48, 0x10, 4, 0x80, 0xD8, 0x10, 4, 0x80
};

itemDef D_8007DE88 = { 0, 2, 0x15, 0xFB, 4, 1, 1, 0, 0x160, 0x1F5, 7, 0x10, 7, 0x10, 0x80012190 };

itemDef D_8007DE9C = { 0, 2, 0x15, 0xFB, 4, 1, 1, 0, 0x160, 0x1F5, 7, 0x10, 7, 0x10, 0x80012190 };

itemDef D_8007DEB0 = { 1, 3, 0x14, 0xF6, 4, 1, 2, 0, 0, 0, 8, 0x10, 8, 0x10, 0x800122DC };

itemDef D_8007DEC4 = { 0, 0, 0x15, 0xF6, 4, 0, 0, 0, 0, 0, 7, 0x10, 7, 0x10, 0x800122F8 };

itemDef D_8007DED8 = { 0, 0, 0x14, 0xF6, 4, 1, 1, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, 0x8001230C };

itemDef D_8007DEEC = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8013A42C };

itemDef D_8007DF00 = { 0, 1, 0xB, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E7, 8, 0x10, 8, 0x10, 0x8013A428 };

itemDef D_8007DF14 = { 0, 1, 0x14, 0, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80012374 };

itemDef D_8007DF28 = { 0, 0xC, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8013A580 };

itemDef D_8007DF3C = { 0, 1, 0xA, 0xEC, 3, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, 0x8012D3B0 };

itemDef D_8007DF50 = { 0, 0, 0x14, 0xF6, 4, 1, 3, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, 0x8001230C };

itemDef D_8007DF64 = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 0xA, 0x14, 8, 0x18, 0x8012D3D0 };

itemDef D_8007DF78 = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 0xA, 0x14, 8, 0x18, 0x8012D3D4 };

itemDef D_8007DF8C = { 0, 0xB, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80012320 };

itemDef D_8007DFA0 = { 0, 4, 7, 0xEC, 3, 1, 0, 0, 0x100, 0x1E5, 8, 0x10, 8, 0x10, 0x8013DAB4 };

itemDef D_8007DFB4 = { 0, 0xA, 0x15, 0xF6, 4, 1, 0, 0, 0x160, 0x1F0, 8, 0x10, 8, 0x10, 0x80012324 };

itemDef D_8007DFC8 = { 0, 0, 0x15, 0xF6, 4, 1, 0, 0, 0x170, 0x1EF, 8, 0x10, 8, 0x10, 0x80012328 };

itemDef D_8007DFDC = { 0, 5, 0xB, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 0x10, 0x20, 0x8013D950 };

itemDef D_8007DFF0 = { 0, 1, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80012308 };

itemDef D_8007E004 = { 0, 7, 0x15, 0xF6, 4, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, 0x8001232C };

itemDef D_8007E018 = { 0, 8, 0x15, 0xF6, 4, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, 0x80012330 };

itemDef D_8007E02C = { 0, 9, 0x15, 0xF6, 4, 0, 0, 1, 0, 0, 8, 0x10, 8, 0x10, 0x80012334 };

itemDef D_8007E040 = { 0, 0, 0x14, 0xF6, 4, 1, 3, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, 0x8001230C };

itemDef D_8007E054 = { 0, 1, 0x14, 0xF6, 4, 1, 1, 0, 0x150, 0x1FC, 8, 0x10, 8, 0x10, 0x80012304 };

itemDef D_8007E068 = { 0, 1, 0x14, 0xF6, 4, 1, 1, 0, 0x150, 0x1FD, 8, 0x10, 8, 0x10, 0x80012304 };

itemDef D_8007E07C = { 0, 0xD, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80012310 };

itemDef D_8007E090 = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x801340D0 };

itemDef D_8007E0A4 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80134070 };

itemDef D_8007E0B8 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80134074 };

itemDef D_8007E0CC = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80134078 };

itemDef D_8007E0E0 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8013407C };

itemDef D_8007E0F4 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80134080 };

itemDef D_8007E108 = { 0, 1, 8, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80134088 };

itemDef D_8007E11C = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x150, 0x1F9, 8, 0x10, 8, 0x10, 0x80012384 };

itemDef D_8007E130 = { 0, 1, 8, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8013D96C };

itemDef D_8007E144 = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x801340A4 };

itemDef D_8007E158 = { 0, 1, 9, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x801340A8 };

itemDef D_8007E16C = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8012D408 };

itemDef D_8007E180 = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8012D3AC };

itemDef D_8007E194 = { 0, 0, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8012D3C4 };

itemDef D_8007E1A8 = { 0, 1, 8, 0, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8013DA58 };

itemDef D_8007E1BC = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8012D3C0 };

itemDef D_8007E1D0 = { 0, 1, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8012D3C8 };

itemDef D_8007E1E4 = { 0, 1, 6, 0xF6, 0xC, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80138320 };

itemDef D_8007E1F8 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x801340B8 };

itemDef D_8007E20C = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80138288 };

itemDef D_8007E220 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x80131094 };

itemDef D_8007E234 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x80131098 };

itemDef D_8007E248 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x8013109C };

itemDef D_8007E25C = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310A0 };

itemDef D_8007E270 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310A4 };

itemDef D_8007E284 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310A8 };

itemDef D_8007E298 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310AC };

itemDef D_8007E2AC = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310B0 };

itemDef D_8007E2C0 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310B4 };

itemDef D_8007E2D4 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E7, 0xC, 0xC, 0xC, 0xC, 0x801310B8 };

itemDef D_8007E2E8 = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x120, 0x1F3, 0xC, 0xC, 0xC, 0xC, 0x800122EC };

itemDef D_8007E2FC = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F1, 0xC, 0xC, 0xC, 0xC, 0x800122E4 };

itemDef D_8007E310 = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F0, 0xC, 0xC, 0xC, 0xC, 0x800122E0 };

itemDef D_8007E324 = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F2, 0xC, 0xC, 0xC, 0xC, 0x800122E8 };

itemDef D_8007E338 = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x130, 0x1F5, 0xC, 0xC, 0xC, 0xC, 0x800122F4 };

itemDef D_8007E34C = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x120, 0x1F4, 0xC, 0xC, 0xC, 0xC, 0x800122F0 };

itemDef D_8007E360 = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E0, 0xC, 0xC, 0xC, 0xC, 0x8011BE74 };

itemDef D_8007E374 = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E1, 0xC, 0xC, 0xC, 0xC, 0x8011BE74 };

itemDef D_8007E388 = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E2, 0xC, 0xC, 0xC, 0xC, 0x8011BE74 };

itemDef D_8007E39C = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E3, 0xC, 0xC, 0xC, 0xC, 0x8011BE74 };

itemDef D_8007E3B0 = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E4, 0xC, 0xC, 0xC, 0xC, 0x8011BE74 };

itemDef D_8007E3C4 = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0xF0, 0x1E5, 0xC, 0xC, 0xC, 0xC, 0x8011BE74 };

itemDef D_8007E3D8 = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x80134084 };

itemDef D_8007E3EC = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x80131070 };

itemDef D_8007E400 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E2, 0xC, 0xC, 0xC, 0xC, 0x80131088 };

itemDef D_8007E414 = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x8013105C };

itemDef D_8007E428 = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x8013107C };

itemDef D_8007E43C = { 0, 1, 0xD, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x801310C8 };

itemDef D_8007E450 = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x80131080 };

itemDef D_8007E464 = { 0, 1, 0xC, 0xF6, 3, 0, 0, 0, 0, 0, 0xC, 0xC, 0xC, 0xC, 0x80131074 };

itemDef D_8007E478 = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E3, 0xC, 0xC, 0xC, 0xC, 0x801310C4 };

itemDef D_8007E48C = { 0, 1, 0xD, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E6, 0xC, 0xC, 0xC, 0xC, 0x801310CC };

itemDef D_8007E4A0 = { 0, 1, 0xF, 0xF6, 5, 1, 0, 0, 0x130, 0x1E6, 8, 0x10, 8, 0x10, 0x80119484 };

itemDef D_8007E4B4 = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0xB0, 0x1E4, 8, 0x10, 8, 0x10, 0x801382A0 };

itemDef D_8007E4C8 = { 0, 1, 1, 0xF6, 3, 1, 0, 0, 0xC0, 0x1E3, 8, 0x10, 8, 0x10, 0x8012CF4C };

itemDef D_8007E4DC = { 0, 1, 0xF, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8011787C };

itemDef D_8007E4F0 = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0x110, 0x1E2, 8, 0x10, 8, 0x10, 0x801382A8 };

itemDef D_8007E504 = { 0, 0, 0x14, 0xF6, 4, 1, 3, 0, 0x160, 0x1FA, 8, 0x10, 8, 0x10, 0x8001230C };

itemDef D_8007E518 = { 0, 1, 9, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x801340AC };

itemDef D_8007E52C = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0xE0, 0x1E4, 8, 0x10, 8, 0x10, 0x801382A4 };

itemDef D_8007E540 = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80134098 };

itemDef D_8007E554 = { 0, 1, 0xB, 0xF6, 3, 0, 0, 0, 0, 0, 0xA, 0x14, 8, 0x18, 0x8012D404 };

itemDef D_8007E568 = { 0, 1, 0xC, 0xF6, 0xB, 1, 0, 0, 0xA0, 0x1ED, 8, 0x10, 8, 0x10, 0x8011E4CC };

itemDef D_8007E57C = { 0, 6, 0x14, 0xF6, 4, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x8001231C };

itemDef D_8007E590 = { 0, 1, 0xE, 0xF6, 0xB, 1, 0, 0, 0x130, 0x1ED, 8, 0x10, 8, 0x20, 0x8011B60C };

itemDef D_8007E5A4 = { 0, 1, 8, 0xF6, 3, 1, 0, 0, 0x130, 0x1EA, 8, 0x10, 8, 0x20, 0x8013A430 };

itemDef D_8007E5B8 = { 0, 1, 0xB, 0xF6, 3, 0, 0, 0, 0xF0, 0x1E9, 8, 0x10, 8, 0x20, 0x8013D8BC };

itemDef D_8007E5CC = { 0, 1, 8, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x801340BC };

itemDef D_8007E5E0 = { 0, 1, 0x14, 0xF6, 4, 1, 0, 0, 0x120, 0x1F4, 8, 0x10, 8, 0x10, 0x800122F0 };

itemDef D_8007E5F4 = { 0, 1, 9, 0xF6, 3, 1, 0, 0, 0x110, 0x1E2, 8, 0x10, 8, 0x10, 0x801382A8 };

itemDef D_8007E608 = { 0, 1, 7, 0xF6, 3, 0, 0, 0, 0, 0, 8, 0x10, 8, 0x10, 0x80119C84 };

u_char D_8007E61C[0xC8] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0, 0xB, 0xC, 0xD, 0xE,
    0xF, 0, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0, 0, 0, 0, 0x53, 0x16, 0x17, 0x18,
    0, 0x19, 0, 0, 0x1A, 0, 0x4E, 0x46, 0x2B, 0, 0x45, 0x44, 0, 0, 0x1B, 0x1C,
    0x1D, 0x1E, 0x1F, 0x5A, 0x20, 0, 0x2C, 0x21, 0, 0, 0, 0, 0x38, 0, 0, 0x22,
    0x51, 0, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x59, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x4B, 0, 0, 0, 0x58,
    0, 0, 0x54, 0x4C, 0x55, 0, 0x23, 0x24, 0x39, 0x3A, 0x3B, 0, 0, 0, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x29, 0x25, 0, 0, 0x3C, 0, 0x49, 0x48, 0x26, 0x5E, 0x56, 0x2C,
    0, 0, 0x27, 0, 0x60, 0, 0, 0, 0, 0x3D, 0x57, 0, 0x4A, 0, 0x28, 0x52,
    0x5F, 0x5D, 0x2A, 0, 0x4D, 0, 0, 0x5B, 0x5C, 0, 0, 0, 0x4F, 0x47, 0x50, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

int D_8007E6E4[97] = {
    (int)&D_8007DE88, (int)&D_8007DE9C, (int)&D_8007DEB0, (int)&D_8007DEC4,
    (int)&D_8007DED8, (int)&D_8007DEEC, (int)&D_8007DF00, (int)&D_8007DF14,
    (int)&D_8007DF28, (int)&D_8007DF3C, (int)&D_8007DF50, (int)&D_8007DF64,
    (int)&D_8007DF78, (int)&D_8007DF8C, (int)&D_8007DFA0, (int)&D_8007DFB4,
    (int)&D_8007DFC8, (int)&D_8007DFDC, (int)&D_8007DFF0, (int)&D_8007E004,
    (int)&D_8007E018, (int)&D_8007E02C, (int)&D_8007E040, (int)&D_8007E054,
    (int)&D_8007E068, (int)&D_8007E07C, (int)&D_8007E090, (int)&D_8007E0A4,
    (int)&D_8007E0B8, (int)&D_8007E0CC, (int)&D_8007E0E0, (int)&D_8007E0F4,
    (int)&D_8007E108, (int)&D_8007E11C, (int)&D_8007E130, (int)&D_8007E144,
    (int)&D_8007E158, (int)&D_8007E16C, (int)&D_8007E180, (int)&D_8007E194,
    (int)&D_8007E1A8, (int)&D_8007E1BC, (int)&D_8007E1D0, (int)&D_8007E1E4,
    (int)&D_8007E1F8, (int)&D_8007E20C, (int)&D_8007E220, (int)&D_8007E234,
    (int)&D_8007E248, (int)&D_8007E25C, (int)&D_8007E270, (int)&D_8007E284,
    (int)&D_8007E298, (int)&D_8007E2AC, (int)&D_8007E2C0, (int)&D_8007E2D4,
    (int)&D_8007E2E8, (int)&D_8007E2FC, (int)&D_8007E310, (int)&D_8007E324,
    (int)&D_8007E338, (int)&D_8007E34C, (int)&D_8007E360, (int)&D_8007E374,
    (int)&D_8007E388, (int)&D_8007E39C, (int)&D_8007E3B0, (int)&D_8007E3C4,
    (int)&D_8007E3D8, (int)&D_8007E3EC, (int)&D_8007E400, (int)&D_8007E414,
    (int)&D_8007E428, (int)&D_8007E43C, (int)&D_8007E450, (int)&D_8007E464,
    (int)&D_8007E478, (int)&D_8007E48C, (int)&D_8007E4A0, (int)&D_8007E4B4,
    (int)&D_8007E4C8, (int)&D_8007E4DC, (int)&D_8007E4F0, (int)&D_8007E504,
    (int)&D_8007E518, (int)&D_8007E52C, (int)&D_8007E540, (int)&D_8007E554,
    (int)&D_8007E568, (int)&D_8007E57C, (int)&D_8007E590, (int)&D_8007E5A4,
    (int)&D_8007E5B8, (int)&D_8007E5CC, (int)&D_8007E5E0, (int)&D_8007E5F4,
    (int)&D_8007E608
};

typedef struct {
    int unk0;
    s16 unk4;
    s16 unk6;
} unk_8007E868;

unk_8007E868 D_8007E868_data[8] asm("D_8007E868") = {
    { 500, 0x150, 0x1E3 },
    { 1000, 0x150, 0x1E0 },
    { 2000, 0x150, 0x1E1 },
    { 5000, 0x150, 0x1E2 },
    { 10000, 0x150, 0x1E3 },
    { 20000, 0x150, 0x1E0 },
    { 100000, 0x150, 0x1E1 },
    { 500000, 0x150, 0x1E2 }
};

asm(".globl D_8007E86C\nD_8007E86C = D_8007E868 + 4");
asm(".globl D_8007E86E\nD_8007E86E = D_8007E868 + 6");

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", func_8003F3D4);
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
        *(int*)(self + 0x3C) = D_1F8002C8[D_8007D6E0[self[3]].unk6];
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
        if ((s16)func_80044620(self, *(s16*)(*(int*)(self + 0x40) + 2), *(s16*)(self + 0x16)) != 0) {
            self[0] = 2;
            self[0xA5] = 0;
            *(int*)(self + 0x8C) = (-*(s16*)0x1F80027E << 2) & 0xFF;
            self[4] = 2;
            self[5] = 0;
            self[6] = 0;
        }
        if (func_80022E44(self) == 0) {
            self[4] = 3;
        }
        break;
    case 2:
        updateItemPickupAnim((unkstruct_800A6D50*)self);
        if (func_80022E44(self) == 0) {
            self[4] = 3;
        }
        break;
    case 3:
        freeObjectLayer1(self);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", func_8003F78C);
void func_8003F78C(u8* self)
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
        if (GAME.selectedArea == 0) {
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
        if ((s16)func_80044620(self, *(s16*)(*(int*)(self + 0x40) + 2), (s16)(*(u16*)(self + 0x16) + 0x14)) != 0) {
            self[4] = 2;
            self[5] = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", func_8003F9A4);
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
        *(int*)(self + 0x3C) = *(int*)0x1F8002D4;
        if (GAME.selectedArea == 0) {
            *(s16*)(self + 0x1E) = 10;
            *(int*)(self + 0x24) = D_8013A44C;
        } else {
            *(s16*)(self + 0x1E) = 8;
            *(int*)(self + 0x24) = D_80134018;
        }
        readAnimFrameCount(self);
        func_80022E44(self);
        break;
    case 1:
        if (func_80022E44(self) != 0) {
            func_8003F78C(self);
        }
        break;
    case 2:
        if (func_80022E44(self) != 0) {
            if (GAME.selectedArea == 4) {
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
            if (GAME.selectedArea == 0) {
                D_8009C616 |= 1 << self[3];
                obj = allocObjectLayer2();
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
        freeObjectLayer1(self);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", applyItemEffect);
void applyItemEffect(unkstruct_800A6D50* arg0, int arg1, short arg2, short arg3, int arg4)
{

    if (func_800236F4(arg0->item_id) == ITEM_CHICK) {
        switch (arg0->spawnMode) {
            case 0:
                spawnItem(arg0->unk1, arg0->unk2, arg1);
                break;
            case 1:
                spawnItemDrop(arg0->unk1, arg0->unk2, arg1);
                break;
            case 2:
                spawnItemAtPos(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 3:
                spawnItemDropAtPos(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 4:
                spawnItemBounce(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 5:
                spawnItemFixed(arg0->unk1, arg0->unk2, arg1);
                break;
            case 6:
                func_80123188(arg1, arg0->item_id, arg2, arg3);
                break;
            case 8:
                spawnItemChest(arg0->unk1, arg0->unk2, arg1);
                break;
        }
        if (arg4 != 0) {
            func_80023794(arg0->item_id);
        }
        if (arg0->subState == 0) {
            playSFX(21);
        }
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", initItemObject);
void initItemObject(unkstruct_800A6D50* arg0)
{

    
    short x;
    short y;
    int temp_v0;
    int color;
    int* var_v0;
    u_char temp_v1;
    u_char temp_v1_2;
    itemDef* temp_s1;

    if ((arg0->item_id == ITEM_JEWELOFWIND) && (GAME.event[EVENT_THEJUNGLEPIGBAG] == 0)) {
        arg0->state = 2;
        return;
    }
    arg0->unk68 = 0;
    arg0->unk69 = 0;
    temp_s1 = D_8007E6E4[D_8007E61C[arg0->item_id]];
    arg0->unkA = temp_s1->unk0;
    arg0->unk1E = (short)temp_s1->unk2;
    arg0->unkF = -9;
    arg0->unkD = (u_char)temp_s1->unk5;
    arg0->unk6C = (short)temp_s1->unkC;
    arg0->unk6E = (short)temp_s1->unkD;
    arg0->unk70 = (short)temp_s1->unkE;
    arg0->unk72 = (short)temp_s1->unkF;

    arg0->unk3C = *(&D_1F8002C8[temp_s1->unk4]);
    arg0->unk2E = 1;
    if (arg0->item_id == 2) {
        if ((u_long) (arg0->unkC & 0x7F) >= 4U) {
            arg0->buffSize = 0x2000;
            arg0->unk6C = (short) (temp_s1->unkC * 2);
            arg0->unk6E = (short) (temp_s1->unkD * 2);
            arg0->unk70 = (short) (temp_s1->unkE * 2);
            arg0->unk72 = (short) (temp_s1->unkF * 2);
        } else {
            arg0->buffSize = 0x1000;
        }
    }

    switch (temp_s1->unk6) {                              // irregular
        case 0:
            x = temp_s1->x;
            y = temp_s1->y;
            arg0->clut = GetClut((int) x, (int) y);
            break;
        case 1:
            x = temp_s1->x;
            y = temp_s1->y;
            arg0->clut = GetClut((int) x, (int) y + (arg0->unkC & 0x7F));
            break;
        case 2:
            temp_v0 = (arg0->unkC & 0x7F) * 2;
            x = *(u_short*)(&D_8007E86C + temp_v0);
            y = *(u_short*)(&D_8007E86E + temp_v0);
            arg0->clut = GetClut((int) x, (int) y);
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
            x = temp_s1->x;
            y = temp_s1->y;
            arg0->clut = GetClut(x, y + color);
            break;
    }

    switch (temp_s1->unk7) {
        case 0:
            var_v0 = temp_s1->unk10;
            arg0->unk24 = (int) *var_v0;
            break;
        case 1:
            var_v0 = (int) ((arg0->unkC & 0x7F) * 4) + *(int*)&temp_s1->unk10;
            arg0->unk24 = (int) *var_v0;
            break;
    }
    readAnimFrameCount(arg0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardNone);
void rewardNone(unkstruct_800A6D50* arg0)
{
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardItem);
void rewardItem(unkstruct_800A6D50* arg0)
{
    int var_a0;
    int var_a1;
    int var_a2;
    u_char current_item;

    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    current_item = arg0->item_id;
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
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardHeart);
void rewardHeart(unkstruct_800A6D50* arg0)
{
    if (D_8009BCA0 == 0) {
        func_800E92D4(0x64, arg0->unk12, arg0->unk16, arg0->unk1A);
        playSFX(9);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->objectIndex);
        }
        if (!(arg0->unkC & 0x7F)) {
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
        arg0->state++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardEffectOnly);
void rewardEffectOnly(unkstruct_800A6D50* arg0)
{
    func_800E92D4(*(&D_8007E868 + ((arg0->unkC & 0x7F) * 2)), arg0->unk12, arg0->unk16, arg0->unk1A);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    playSFX(9);
    arg0->state+=1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardBakedYam);
void rewardBakedYam(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_BAKEDYAM, 1, true);
    if ((GAME.event[EVENT_SOMETHINGCOOKIN] & 0xFF) == 3) {
        GAME.event[EVENT_SOMETHINGCOOKIN] += 1;
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex, &GAME.event[EVENT_SOMETHINGCOOKIN]);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardDirtyMirror);
void rewardDirtyMirror(unkstruct_800A6D50* arg0)
{
    GAME.unk54e = 5;
    addItemToInventory(ITEM_DIRTYMIRROR, 1, true);
    setEventStarted(EVENT_AMAGICMIRROR, 0, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardVitalityMaxUp);
void rewardVitalityMaxUp(unkstruct_800A6D50* arg0)
{
    if (D_8009BCA0 == 0) {
        increaseMaxHealth();
        printInfoMessage(MSG_VITALITYMAXUP_ACQUIRED, MSG_TYPE_REWARD);
        playSFX(10);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->objectIndex);
        }
        arg0->state++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardWoodBoomerang);
void rewardWoodBoomerang(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_WOODBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardStoneBoomerang);
void rewardStoneBoomerang(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_STONEBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardIronBoomerang);
void rewardIronBoomerang(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_IRONBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardOneUp);
void rewardOneUp(unkstruct_800A6D50* arg0)
{
    u_char lives = GAME.playerLives;
    if (lives < 99) {
        GAME.playerLives = (u_char)(lives+1);
        printInfoMessage(MSG_ONEUP_ACQUIRED, MSG_TYPE_REWARD);
        playSFX(10);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardGoldenBowl);
void rewardGoldenBowl(unkstruct_800A6D50* arg0)
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
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->objectIndex);
        }
        arg0->state++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardBitingPlantFlower);
void rewardBitingPlantFlower(unkstruct_800A6D50* arg0)
{
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = arg0->subState;
    switch (temp_v1) {
        case 0:
            addItemToInventory(ITEM_BITINGPLANTFLOWER, 1, true);
            setEventStarted(EVENT_BITINGPLANTFLOWER, 0, 0);
            if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
                GAME.bittingPlantFlowerState = 2;
            }
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->objectIndex);
            }
            arg0->cooldownTimer = 0x12CU;
            asm("");
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_800A539C = 5;
            D_800A539D = 0;
            D_800A539E = 0;
            D_800A539F = 0;
            arg0->subState++;
            return;
        case 1:
            temp_v0 = arg0->cooldownTimer - 1;
            arg0->cooldownTimer = temp_v0;
            if ((temp_v0 << 0x10) == 0) {
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                D_800A539F = 0;
                arg0->state++;
            }
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardGrapple);
void rewardGrapple(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_GRAPPLE, 1, true);
    setEventComplete(EVENT_APRECIOUSTREASURECHEST, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardGrappleJack);
void rewardGrappleJack(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_GRAPPLEJACK, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardCrystalBalls);
void rewardCrystalBalls(unkstruct_800A6D50* arg0)
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
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardMysteriousMushroom);
void rewardMysteriousMushroom(unkstruct_800A6D50* arg0)
{
    setEventComplete(EVENT_THEMISTERIOUSMUSHROOM, 0);
    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardFlowerSeeds);
void rewardFlowerSeeds(unkstruct_800A6D50* arg0)
{
    setEventStarted(EVENT_FLOWERSEEDS, 0, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    addItemToInventory(arg0->item_id, 1, true);
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardPigBag);
void rewardPigBag(unkstruct_800A6D50* arg0)
{
    int temp;

    switch (arg0->subState) {                              // switch 3; irregular
        case 0:                                     // switch 3
            addItemToInventory(arg0->item_id, 1, true);
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->objectIndex);
            }
            switch (arg0->item_id) {
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
            arg0->cooldownTimer = 0x168U;
            arg0->subState++;
            return;
        case 1:
            temp = arg0->cooldownTimer - 1;
            arg0->cooldownTimer = temp;
            if ((temp << 0x10) == 0) {
                switch (arg0->item_id) {
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
                arg0->state++;
            }
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardConditionalItem);
void rewardConditionalItem(unkstruct_800A6D50* arg0)
{
    if ((GAME.selectedArea == AREA10_DEEPJUNGLE) || (arg0->unkC == 1)) {
        addItemToInventory(arg0->item_id, 1, true);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardJewel);
void rewardJewel(unkstruct_800A6D50* arg0)
{
    int var_a0;
    int var_a2;
    u_char current_item;
    u_char var_v0;
    
    current_item = arg0->item_id;
    switch (current_item) {
        case ITEM_JEWELOFFIRE: 
            if (GAME.redExpLevel == 9) {
                setEventComplete(EVENT_REDHIDDENPOWERS, 1);
                addItemToInventory(arg0->item_id, 1, true);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->objectIndex);
                    asm("");
                }
                arg0->state++;
            } else {
                if ((short)arg0->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    arg0->cooldownTimer = 0x78;
                } 
                arg0->state--;
            }
            break;
        case ITEM_JEWELOFWATER: 
            if (GAME.blueExpLevel == 9) {
                setEventComplete(EVENT_BLUEHIDDENPOWERS, 0);
                addItemToInventory(arg0->item_id, 1, true);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->objectIndex);
                    asm("");
                }
                arg0->state++;
            } else {
                setEventStarted(EVENT_BLUEHIDDENPOWERS, 0, 0);
                if ((short)arg0->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    arg0->cooldownTimer = 0x78;
                } 
                arg0->state--;
            }
            break;
        case ITEM_JEWELOFWIND:
            if (GAME.greenExpLevel == 9) {
                setEventComplete(EVENT_GREENHIDDENPOWERS, 1);
                addItemToInventory(arg0->item_id, 1, true);
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->objectIndex);
                }
                arg0->state++;
            } else {
                setEventStarted(EVENT_GREENHIDDENPOWERS, 0, 1);
                if ((short)arg0->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    arg0->cooldownTimer = 0x78;
                } 
                arg0->state--;
            }
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardSafeMushroom);
void rewardSafeMushroom(unkstruct_800A6D50* arg0)
{
    setEventComplete(EVENT_ASAFEMUSHROOM, 0);
    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardAnimalDash);
void rewardAnimalDash(unkstruct_800A6D50* arg0)
{
    printInfoMessage(MSG_ANIMALDASH_ACQUIRED, MSG_TYPE_REWARD);
    GAME.area00_eventControl |= 0x40;
    playSFX(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    GAME.unk6ad = 1;
    GAME.unk736 = 1;
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardPants);
void rewardPants(unkstruct_800A6D50* arg0)
{   
    if (GAME.item[ITEM_JUMPINGPANTS] == 0) {
        addItemToInventory(ITEM_JUMPINGPANTS, 1, true);
    } else if ((GAME.item[ITEM_DASHINGPANTS] == 0)) {
        addItemToInventory(ITEM_DASHINGPANTS, 1, true);
    } else if (GAME.item[ITEM_FLASHPANTS] == 0) {
        addItemToInventory(ITEM_FLASHPANTS, 1, true);
    }
    playSFX(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}
