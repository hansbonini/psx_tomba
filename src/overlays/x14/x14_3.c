#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_3", func_8011EC04);
typedef struct GVars_1EC04 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_1EC04;

typedef struct { s16 a, b, c, d; } E8_1EC04;

extern s32 tickAnimation(GameObject *);
extern void func_8011CBD0(GameObject *, s32);
extern void func_8011EB94(void);
extern void func_8011EBCC(void);
extern s32 func_8012225C(GameObject *);
extern void func_8011CC8C(GameObject *);
extern void func_80115FEC(GameObject *);

void func_8011EC04(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        func_8011CBD0(o, 0x14);
        o->unk7++;
        func_8011EB94();
        break;
    case 1:
        if (tickAnimation(o)) {
            func_8011CBD0(o, 0x15);
            o->unk7++;
        }
        break;
    case 2:
        if (tickAnimation(o)) {
            func_8012225C(o);
            (*(GVars_1EC04 *)&D_8009BC98).b58 = 0;
            func_8011CC8C(o);
            func_80115FEC(o);
            o->timer = 0x14;
            o->unk7++;
            func_8011EBCC();
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            E8_1EC04 *t = (E8_1EC04 *)o->unk94;
            o->unk7++;
            t += o->unkAE;
            o->timer = t->c;
            func_8011CBD0(o, 0x12);
        }
        break;
    case 4:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->step = 0;
            o->unk7 = 0;
            o->subState++;
        }
        break;
    }
}
