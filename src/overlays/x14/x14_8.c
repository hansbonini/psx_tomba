#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_8", func_8011F4A4);
typedef struct { s16 a, b, c, d; } E8_1F4A4;

extern s32 tickAnimation(GameObject *);
extern void func_8011CBD0(GameObject *, s32);
extern void func_8011EB94(void);
extern void func_8011EBCC(void);
extern void func_80123B8C(GameObject *, s32, u8);
extern void func_8011CC8C(GameObject *);
extern void func_80115FEC(GameObject *);

void func_8011F4A4(GameObject *o)
{
    u16 *q = (u16 *)&o->unkB4;

    switch (o->unk7) {
    case 0:
        q[4] = 1;
        q[5] = nextRandom() & 3;
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
            func_80123B8C(o, 1, q[5]);
            func_8011CC8C(o);
            func_80115FEC(o);
            o->unk7++;
            func_8011EBCC();
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            if (q[4] != 0) {
                q[4]--;
                q[5] = (q[5] + 1) & 3;
                o->unk7 = 2;
                func_8011CBD0(o, 0x15);
            } else {
                E8_1F4A4 *t = (E8_1F4A4 *)o->unk94;
                o->unk7++;
                t += o->unkAE;
                o->timer = t->c;
                func_8011CBD0(o, 0x12);
            }
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
