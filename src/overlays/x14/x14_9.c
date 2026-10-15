#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_9", func_8011F674);
typedef struct { s32 a; s16 t; s16 b; } E8_1F674;

extern s32 tickAnimation(GameObject *o);
extern void func_8011CBD0(GameObject *o, s32 n);
extern void func_8011CC8C(GameObject *o);
extern void func_80115FEC(GameObject *o);
extern void func_8011EB94(void);
extern void func_8011EBCC(void);
extern void func_80121B04(GameObject *o);

void func_8011F674(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        func_8011CBD0(o, 0x14);
        o->unk7++;
        func_8011EB94();
        func_80121B04(o);
        break;
    case 1:
        if (tickAnimation(o)) {
            func_8011CBD0(o, 0x15);
            o->unk7++;
        }
        break;
    case 2:
        if (tickAnimation(o)) {
            func_8011CC8C(o);
            func_80115FEC(o);
            o->timer = 0x14;
            o->unk7++;
            func_8011EBCC();
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            E8_1F674 *e = (E8_1F674 *)o->unk94;
            o->unk7++;
            e += o->unkAE;
            o->timer = e->t;
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
