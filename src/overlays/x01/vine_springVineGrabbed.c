#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011a85c 1696 X001
// MATCHING 8011a85c 1696

extern short COS_TABLE[];
extern char D_8013C474[];
extern int springVineSwayStep(GameObject *o);
extern void spawnSpringVineLeafBurst(int x, int y, int z);
extern GameObject *spawnForestDwarfAt(short k, short d, short n, short x, short y, short z);
extern GameObject *spawnLayer2ObjectUnlessFlagged(void *);

#define BURST() \
    spawnSpringVineLeafBurst(o->h->p.whole, o->y.p.whole, o->d->p.whole); \
    o->objectIndex = 1; \
    if (GAME_U16Arr[1] == 0) playSFX(0x44); else playSFX(0x49);

void springVineGrabbed(GameObject *o)
{

    switch (o->step) {
    case 0:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->unk74 = 0;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->velV = 0x340;
        if (*(short *)((char *)o + 0x74) == 0) {
            o->unk84 = 0;
            o->y.raw = o->unk34;
            if (PLAYER_GameObject.velX == 0) {
                o->animFrame = 4;
            } else {
                if ((o->animFrame >> 1) & 1) {
                    o->unk74 = 0x200;
                    o->velH = 0x200;
                    o->velX = -0x10;
                } else {
                    o->unk74 = -0x200;
                    o->velH = -0x200;
                    o->velX = 0x10;
                }
                o->unkA6 = 0x20;
                o->timer = 2;
            }
        }
        o->step++;
        o->objectIndex = 0;
        if (GAME_U16Arr[1] == 0) playSFX(0x42);
        else playSFX(0x47);
        break;
    case 1:
        if (!o->unk6A) goto next;
        if ((o->animFrame >> 1) != 2 && springVineSwayStep(o)) o->animFrame = 4;
        {
            unsigned char v = ((unsigned char *)&o->unk88)[1];
            if (v > 0x80) o->y.raw += (COS_TABLE[v] * (o->velV - 0x100)) >> 4;
            else o->y.raw += (COS_TABLE[v] * o->velV) >> 4;
            o->unk88 += 0x280;
            v = (unsigned)o->unk88 >> 8;
            if (v == 0) {
                o->y.raw = o->unk34;
                if (GAME_U16Arr[1] == 0) playSFX(0x43);
                else playSFX(0x48);
            }
        }
        break;
    case 2:
        {GameObject *e = (GameObject *)o->unk94;
        o->unk88 = 0;
        o->velV = ((o->unk34 - e->y.raw) / 15) >> 8;
        o->velX = ((o->unk30 - o->h->raw) >> 8) / 64;
        o->unk74 = 0;
        o->active = 2;
        o->step++;
        break;}
    case 3:
        o->y.raw -= (COS_TABLE[((unsigned char *)&o->unk88)[1]] * o->velV) >> 4;
        if (o->unk6A) o->y.raw -= (COS_TABLE[((unsigned char *)&o->unk88)[1]] * o->velV) >> 4;
        o->h->raw += o->velX << 8;
        o->unk88 += 0x200;
        if (o->unk76 < ((o->unk88 >> 8) & 0xff)) {
            switch (o->unkC) {
            case 0:
                break;
            case 1:
                if (o->unk98 == 0) {
                    GameObject *e = spawnLayer2ObjectUnlessFlagged(D_8013C474);
                    if (!e) {
                        o->unk98 = 1;
                        break;
                    }
                    e->active = 5;
                    e->unkF = 3;
                    e->animFrame = 0;
                    e->h->raw = o->h->raw;
                    e->y.raw = o->y.raw;
                    e->d->raw = o->d->raw;
                    o->unk98 = 1;
                    BURST();
                }
                break;
            case 3:
            case 4:
                if (o->unk98 == 0) {
                    o->unk90 = (int)spawnForestDwarfAt(0, 0, o->unkC, o->x.p.whole, o->y.p.whole, o->z.p.whole);
                    o->unk98 = 1;
                    if (o->unk90) {
                        BURST();
                    }
                }
                break;
            }
        }
        if ((short)((unsigned char *)&o->unk88)[1] >= 0x41) {
            if (!o->objectIndex) {
                BURST();
            }
            o->active = 1;
            o->velH = 0;
            o->velX = 0;
            o->unk74 = 0;
            o->unk84 = 0;
            o->h->raw = o->unk30;
            if (o->y.raw >= o->unk34) {
                o->step++;
                o->y.raw = o->unk34;
                o->h->raw = o->unk30;
                o->velH = 0;
                o->velV = 0;
                o->velX = 0;
                o->velY = 0;
                o->unk84 = 0;
                o->unk88 = 0;
                o->unk74 = 0;
                o->velV = 0x200;
            }
        }
        break;
    case 4:
        o->unk88 += 0x400;
        {
            int v = o->unk88 >> 8;
            if (v & 0x80) {
            next:
                o->step++;
                break;
            }
            o->y.raw -= (COS_TABLE[v & 0xff] * o->velV) >> 4;
        }
        if (o->touchFlag) o->touchFlag = 0;
        if (o->unk6A) o->step = 0;
        break;
    case 5:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->subState = 0;
        o->step = 0;
        o->unk68 = 0;
        break;
    }
}

#endif
