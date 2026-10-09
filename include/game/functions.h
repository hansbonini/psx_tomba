#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

/* Function prototypes.
   Part of game.h: include "game.h", not this file. */

void openTask(s32 arg0, long (*func)());
void fontDebugPrintf(short x, short y, short color, char* fmt);
void vblankHandler(void);
void bootSequenceTask(void);
void titleSequenceTask(void);
void gameTask(void);
void moviePlayerTask(void);
void mdecSliceCallback(void);
void lzDecompress(byte* src, byte* dest);
void loadTIM(u_long* address, short x, short y, short x2, short y2);
u_char awardEventProgress(EVENT event_id, int ap_table, int state);
void func_80125FE8(void);
void func_8011F67C(void);
extern void func_80126048();
extern void func_8011F6DC();
s32 playSFXWithNote(s32 arg0, s32 arg1);
void func_80034C14();
void func_8005B1F8(u8* self);
void func_80036F98();
void func_80122688(void);
void func_8011D498(void);
void func_8012298C(void);
void func_8011D79C(void);
int execCoreOpcode(u8 op);
int execGameOpcode(u8 op);
s16 func_80051284();
u16 nextRandom(void);
void func_800EBD5C(u8* arg0, s16 arg1, s16 arg2);
void PadInitDirect(u8* a, u8* b);
int PadStartCom(void);
s16 func_80036618(u8* self);
void func_80122F64(void);
void func_8011D844(void);
void func_8011CD70(void);
void func_8011602C(void);
int func_80022E44(u8* self);
char *getCollisionPlaneAt();
s16 func_8004339C(u8* self, s16 a, s16 b);
s32 func_800443CC();
extern void func_801248A0();
extern void func_8011E3E4();
extern void func_8011FC7C();
extern void func_80124B38();
extern void func_801233E0();
extern void func_8011EC1C();
extern void func_8011E254();
extern void func_80123D24();
extern void func_8011EF08();
extern void func_8011E170();
extern void func_8011F650();
void func_8012C03C(void);
void func_8012E2FC(void);
void func_80123EC8(void);
void func_80122A00(void);
s32 allocSfxVoice();
s32 queueSoundCommand();
void cdLoadTask(void);
// void applyAnimVelocityX(GameObject* arg0, u16 arg1);

/* Moved from the .c files */

/* main/audio/sound.c */
s32 getSfxVabOffset(u16 id);

/* main/game/effect.c */
void dispatchScreenEffect(u8* self);
void updateScrollAnchoredEffect(u8* self);

/* main/render/camera.c */
void applyLighting(u8* self);

/* main/render/drawutil.c */
void drawNowLoadingSprite(int x, int y, short sprt_id, short tpage, short arg4);
void drawUiSprite(short x, short y, short sprt_id);

/* main/system/cdfile.c */
s32 fixedMulCos2(s16 arg0, s16 arg1);

extern s32 GetGraphType(void);
extern s32 func_80023608(s32);
extern s32 PadGetState(s32);
extern u16 func_80028D70(s32);
extern u8 *allocObjectUnlayered(void);
extern void func_80023794(s32);
extern void func_80028A74(s32, s32, s32, s32);
extern void func_80028B34(void);
extern void func_8002F05C(GameObject *, s32, s32, s32);
extern void func_8003481C(GameObject *);
extern void func_800348FC(GameObject *);
extern void func_800349DC(s16 *, s32, s16 *, s16 *);
extern void func_80038AC0(GameObject *);
extern void func_8003A10C(GameObject *);
extern void func_8004637C(void);
extern void func_80046428(void *);
extern void func_80046CDC(void);
extern void func_8004A300(GameObject *);
extern void func_8004AD8C(void);
extern void func_8004AFAC(void);
extern void func_8004CFE0(void);
extern void func_8004D0C0(void);
extern void func_8004DB3C(void);
extern void func_8004DC34(void);
extern void func_8004DD14(void);
extern void func_8004DFA0(GameObject *);
extern void func_8004E244(GameObject *);
extern void func_8004E3EC(void);
extern void func_8004E714(char *, s32, s32);
extern void func_8004F5A4(void);
extern void func_800E76A8(o);
extern void func_800E92D4(s32, s32, s32, s32);
extern void func_800E9484(void *);
extern void func_800E9EB8(GameObject *);
extern void func_800EA094(void *);
extern void func_800EA3A4(GameObject *);
extern void func_800EAA5C(void *);
extern void func_800EAAC8(GameObject *);
extern void func_800EB490(GameObject *);
extern void func_800EBA58(GameObject *);
extern void func_800EBA70(s32, GameObject *);
extern void func_800EBDD8(o);
extern void func_800EEDE0(GameObject *);
extern void func_800EEF64(GameObject *);
extern void func_80110DA0(s32 a, s32 b, s32 c);
extern void func_80112AA4(o);
extern void func_80116308(GameObject *);
extern void func_8011AF78(void);
extern void func_8011BB50(GameObject *, u8 *);
extern void func_8011BC04(GameObject *, u8 *);
extern void func_8011BDA4(GameObject *, u8 *);
extern void func_8011BEE4(GameObject *, GameObject *);
extern void func_8011BF60(GameObject *, u8 *);
extern void func_8011C0B0(GameObject *, u8 *);
extern void func_8011C1A8(GameObject *, u8 *);
extern void func_8011C270(GameObject *, u8 *);
extern void func_8011C334(GameObject *, GameObject *);
extern void func_8011C384(GameObject *, u8 *);
extern void func_8011C47C(GameObject *, u8 *);
extern void func_8011C620(GameObject *, GameObject *);
extern void func_8011CF54(GameObject *, u8 *);
extern void func_8011D0E0(GameObject *, GameObject *);
extern void func_8011D25C(GameObject *, GameObject *);
extern void func_8011D6F8(GameObject *, u8 *);
extern void func_8011DA28(GameObject *);
extern void func_8011E680(GameObject *, GameObject *);
extern void func_8011E6CC(GameObject *, GameObject *);
extern void func_8011E768(GameObject *, GameObject *);
extern void func_8011E818(GameObject *, GameObject *);
extern void func_8011E838(GameObject *, GameObject *);
extern void func_8011E858(GameObject *, u8 *);
extern void func_8011E8D4(GameObject *, GameObject *);
extern void func_8011E978(GameObject *, u8 *);
extern void func_8011E984(GameObject *, u8 *);
extern void func_8011EAF4(GameObject *, GameObject *);
extern void func_8011EB3C(GameObject *, GameObject *);
extern void func_8011EC28(GameObject *, GameObject *);
extern void func_8011EC90(GameObject *, u8 *);
extern void func_8011EDBC(void);
extern void func_8011EE24(GameObject *, u8 *);
extern void func_8011EFD4(GameObject *, u8 *);
extern void func_8011F070(GameObject *, u8 *);
extern void func_8011F2B4(GameObject *, GameObject *);
extern void func_8011F490(GameObject *, u8 *);
extern void func_8011F5C4(s32, s32);
extern void func_8011F634(GameObject *, GameObject *);
extern void func_8011F710(GameObject *, u8 *);
extern void func_8011F884(GameObject *, GameObject *);
extern void func_8011FA14(GameObject *, u8 *);
extern void func_8011FC08(GameObject *, GameObject *);
extern void func_8011FD70(GameObject *, GameObject *);
extern void func_8011FEE4(GameObject *, GameObject *);
extern void func_8011FFAC(GameObject *, u8 *);
extern void func_80120278(GameObject *, u8 *);
extern void func_801202E0(GameObject *, GameObject *);
extern void func_801204C4(GameObject *, u8 *);
extern void func_80120710(GameObject *, GameObject *);
extern void func_80120B3C(void *);
extern void func_80120C78(void *);
extern void func_801235F8(GameObject *, u8 *);
extern void func_80123680(GameObject *, u8 *);
extern void func_8012370C(GameObject *, u8 *);
extern void func_80124BA0(GameObject *, GameObject *);
extern void func_80124C1C(GameObject *, GameObject *);
extern void func_80124C74(GameObject *, GameObject *);
extern void func_80124CCC(GameObject *, GameObject *);
extern void func_80124D6C(GameObject *, GameObject *);
extern void func_80124DF0(GameObject *, GameObject *);
extern void func_80124E1C(GameObject *, GameObject *);
extern void func_80124EC0(GameObject *, GameObject *);
extern void func_80124F60(GameObject *, GameObject *);
extern void func_80124FC8(GameObject *, GameObject *);
extern void func_801250E8(GameObject *, GameObject *);
extern void func_8012523C(GameObject *, GameObject *);
extern void func_80125274(GameObject *, u8 *);
extern void func_801252F4(GameObject *, GameObject *);
extern void func_8012533C(GameObject *, GameObject *);
extern void func_80125354(GameObject *, u8 *);
extern void func_8012543C(GameObject *, u8 *);
extern void func_801254DC(GameObject *, u8 *);
extern void func_80125584(GameObject *, u8 *);
extern void func_80125630(GameObject *, u8 *);
extern void func_801257A8(GameObject *, u8 *);
extern void func_8012589C(GameObject *, u8 *);
extern void func_801259DC(GameObject *, u8 *);
extern void func_80125BB4(GameObject *, u8 *);
extern void func_80125EF4(GameObject *, u8 *);
extern void func_801262AC(u8 *a, u8 *b);
extern void initItemObject(GameObject *);

#endif
