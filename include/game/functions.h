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
void func_80126048(void);
void func_8011F6DC(void);
s32 playSFXWithNote(s32 arg0, s32 arg1);
void func_80034C14(u8* self);
void func_8005B1F8(u8* self);
void func_80036F98(u8* self);
void func_80122688(void);
void func_8011D498(void);
void func_8012298C(void);
void func_8011D79C(void);
int execCoreOpcode(u8 op);
int execGameOpcode(u8 op);
s16 func_80051284();
u16 nextRandom(void);
void func_800EBD5C(u8* arg0, s16 arg1, s16 arg2);
void func_8006A9EC(u8* a, u8* b);
s16 func_80036618(u8* self);
void func_80122F64(void);
void func_8011D844(void);
void func_8011CD70(void);
void func_8011602C(void);
int func_80022E44(u8* self);
s32 getCollisionPlaneAt(s16 a, s16 b);
s16 func_8004339C(u8* self, s16 a, s16 b);
s16 func_800443CC(u8* self, s16 a, s16 b);
void func_801248A0(void);
void func_8011E3E4(void);
void func_8011FC7C(void);
void func_80124B38(void);
void func_801233E0(void);
void func_8011EC1C(void);
void func_8011E254(void);
void func_80123D24(void);
void func_8011EF08(void);
void func_8011E170(void);
void func_8011F650(void);
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

#endif
