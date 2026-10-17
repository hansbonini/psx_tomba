#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_5", func_8011EEE4);
struct GSInventory_1EEE4 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1EEE4 { u8 weapon; u8 pants; };
typedef struct { s16 a, b, c, d; } E8_1EEE4;

extern s32 tickAnimation(GameObject *);
extern u8 D_80125454[];
extern void func_8011CBD0(GameObject *, s32);
extern void func_8011EB94(void);
extern void func_8011EBCC(void);
extern void func_80123760(GameObject *, u8);
extern void func_8011F97C(GameObject *);
extern void func_8011CC8C(GameObject *);
extern void func_80115FEC(GameObject *);

void func_8011EEE4(GameObject *o)
{
    u16 *q = (u16 *)&o->unkB4;

    switch (o->unk7) {
    case 0:
        if (o->unk38 < 0x80 && GAME.selectedSection != 7) {
            q[5] = D_80125454[nextRandom() & 0xf];
            if (q[5] == 0)
                q[4] = 2;
            else
                q[4] = 0;
        } else {
            q[5] = 0;
            q[4] = 2;
        }
        q[3] = (u8)o->unk38;
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
            if (q[5] == 0)
                func_80123760(o, q[3]);
            else
                func_8011F97C(o);
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
                if (q[4] == 1)
                    q[3] = (o->unk38 + 0x10) & 0xff;
                else
                    q[3] = (o->unk38 - 0x10) & 0xff;
                o->unk7 = 2;
                func_8011CBD0(o, 0x15);
            } else {
                E8_1EEE4 *t = (E8_1EEE4 *)o->unk94;
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
