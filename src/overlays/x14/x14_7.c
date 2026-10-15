#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_7", func_8011F2C4);
typedef struct { s32 a; s16 t; s16 b; } E8_1F2C4;
typedef struct { s16 x0, x2, x4, x6; u16 n; s16 k; } Q_1F2C4;

extern u8 D_80125624[];
extern s32 tickAnimation(GameObject *o);
extern void updateObjectSideFlag(GameObject *o);
extern void func_8011CBD0(GameObject *o, s32 n);
extern void func_8011CC8C(GameObject *o);
extern void func_80115FEC(GameObject *o);
extern void func_8011EB94(void);
extern void func_8011EBCC(void);
extern void func_80120AB0(GameObject *o, u8 k);

void func_8011F2C4(GameObject *o)
{
    Q_1F2C4 *q = (Q_1F2C4 *)&o->unkB4;

    switch (o->unk7) {
    case 0:
        q->n = D_80125624[nextRandom() & 0xf];
        q->k = 0;
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
            updateObjectSideFlag(o);
            func_80120AB0(o, q->k);
            func_8011CC8C(o);
            func_80115FEC(o);
            o->unk7++;
            func_8011EBCC();
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            if (q->n) {
                q->n--;
                q->k++;
                o->unk7 = 2;
                func_8011CBD0(o, 0x15);
            } else {
                E8_1F2C4 *e = (E8_1F2C4 *)o->unk94;
                o->unk7++;
                e += o->unkAE;
                o->timer = e->t;
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
