#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

/* Functions of the engine every code overlay carries at 0x800E7388
   (src/overlays/x00/engine*.c).
   Part of game.h: include "game.h", not this file. */

void func_800E7DF8(void *, s32, s32);
void func_800E8758(void *, s32, s32);
void func_800E8A30(void *, s32, s32);
void func_800ED788(GameObject *);
void func_800EDD9C(GameObject*);
void func_800EE50C(GameObject*);
void func_800EE7F0(char*);
void func_8010E750(GameObject *);
void func_8011032C(u8*);
void func_8011068C(char*);
void func_8011070C(GameObject*);

void func_800ECF74(GameObject* o);
void func_800EDA30(char* o);
void func_800EDFA0(GameObject* o);
s16 func_800EE26C(void);
void func_800EF40C(GameObject* o);
void func_80110A64(GameObject* o);
void func_80113610(GameObject* o);

void func_800E9580(GameObject* o);
void func_800EB954(char* o, s32 a, s32 b, s32 c);
void func_800EBBAC(s32 type);
void func_800EE844(char* o);
void func_800FB38C(u8* o);
void func_800FB774(GameObject* o);
void func_80101D58(GameObject*);
void func_80103D54(GameObject* o);
void func_80104028(GameObject* o);
void func_80104118(GameObject* o);
void func_801041F0(GameObject* o);
void func_80105EA0(GameObject* o);
void func_80106100(GameObject* o);
void func_801062E8(GameObject*);
void func_8010633C(GameObject* o);
void func_80106928(GameObject* o);
void func_80106F50(GameObject* o);
void func_8010731C(GameObject* o);
void func_801074B8(GameObject* o);
void func_80107688(GameObject* o);
void func_80107A58(GameObject* o);
void func_80107E20(GameObject* o);
void func_8010810C(GameObject* o);
void func_801087E4(GameObject* o);
void func_80108B3C(GameObject* o);
void func_80108C70(GameObject* o);
void func_801091A0(GameObject* o);
void func_801094B8(GameObject* o);
void func_80109868(GameObject* o);
void func_80109D44(GameObject* o);
void func_80109FE0(GameObject* o);
void func_8010A1E4(GameObject* o);
void func_8010A3A0(GameObject* o);
void func_8010A794(GameObject* o);
void func_8010B384(GameObject* o);
void func_8010BD68(GameObject* o);
void func_8010C0F8(GameObject* o);
void func_8010C6E0(GameObject* o);
void func_8010CBD8(GameObject* o);
void func_8010CE5C(GameObject* o);
void func_8010D0DC(GameObject* o);
s32 func_8010D464(void);
void func_8010D9BC(GameObject* o);
void func_8010F604(u8* p);
void func_8011023C(GameObject* o);
void playerCling(GameObject* o);
void playerThrowEnemy(GameObject* o);

extern s8 D_80113DD0[];
extern s16 D_80113DE8[];
extern s16 D_80113DF8[];
extern u8 D_80113E08[];
extern u8 D_80113E10[];
extern void** D_80113E18[];
extern u16 D_80113F2C[];
extern s16 D_80113F58[];
extern char D_80113F70[];
extern char D_80113F74[];
extern s32* D_80113FB4[];
extern s32** D_80113FC0[];
extern char D_80113FCC[];
extern u8 D_80114570[][2];
extern s16 D_80114598[];
extern s16 D_801145B8[][2];
extern u8 D_80114638[];
extern u8 D_8011465C[];
extern u8 D_801146D8[];
extern s16 D_80114710[];
extern u16 D_801147B8[][10];
extern u8 D_80114D68[];
extern u8 D_80114DA4[];
extern u8 D_80114DA8[][6];
extern char D_80114E4A[];
extern char D_80115078[];
extern u8* D_8011508C[];
extern s32* D_80115140[][4];
void func_800EA86C(s16 a, s32 x, s32 y, s32 z);
void func_800EDCA8(s8* o, u8 p);
void func_800EE3BC(u32 a, s16 x, s16 y, s16 z);
void func_80113C20(s32 a, char b, s32 c, s32 d, s16 e);
void func_80113CB8(s32 unused, char sub, s32 x, s32 y, s32 z);

void func_800EEA38();
void func_800FDABC();
void func_800FDCEC();
void func_800FE970();
void func_8010DE48();
void func_8010E678();
void playerFallInWater();
void playerHurt();
void playerHurtBitten();

#endif
