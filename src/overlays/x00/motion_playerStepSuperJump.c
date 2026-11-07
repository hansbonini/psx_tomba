#include "version.h"
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
typedef struct { char pad[0x14]; short driftH, driftY; } MotionDrift;
extern MotionDrift MOTION_DRIFT;
// FUNC 8010e66c 684 X000
// MATCHING 8010e66c 684
#define B(o, n) (((unsigned char *)(o))[n])
extern GameObject *PLAYER_EXT;
extern int MulCos(int a, int b);
extern void ObjSetAnimFromTable(GameObject *);
extern void AnimLoadDuration(GameObject *);
extern void SfxPlay2(int a, int b);
extern void spawnPlayerPowerEffect(int);
extern int AnimAdvance(GameObject *);
extern void playerUpdateSpeedFromPad(GameObject *);
extern void func_8010DE48(GameObject *);
extern void ObjMotionStep(GameObject *);
extern void ObjAddVelY7E(GameObject *);
extern void ObjTileCollide(GameObject *, int, int);
extern void playerAirSpinToFall(GameObject *);
extern int ObjCheckHeadCollision(GameObject *);

void playerStepSuperJump(GameObject *o)
{
    int v;
    switch (o->step) {
    case 0:
        o->timer = 0x31;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->touchFlag = 0;
        o->unk9E = 0;
        B(o, 0xc3) = 0;
        o->touchFlag = 0;
        o->unk9C = 1;
        o->unkB0 = 0;
        B(o, 0xa0) = 0;
        B(o, 0xa1) = 0;
        o->unkB6 = 0;
        o->velX = MulCos(0, o->unkB2);
        o->velY = -10;
        B(PLAYER_EXT, 8) = 0;
        PLAYER_EXT->animTimer = 4;
        PLAYER_EXT->timer = 0;
        PLAYER_EXT->subState = 0;
        PLAYER_EXT->unk1D = 0;
        B(o, 0xac) = 0;
        ObjSetAnimFromTable(o);
        AnimLoadDuration(o);
        PLAYER_EXT->animFrame = PLAYER_EXT->animTimer;
        SfxPlay2(2, 4);
        spawnPlayerPowerEffect(2);
        o->step = 1;
    case 1:
        o->h->raw += MOTION_DRIFT.driftH << 8;
        o->y.raw += ((short *)&MOTION_DRIFT.driftY)[0] << 8;
        AnimAdvance(o);
        playerUpdateSpeedFromPad(o);
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        o->velY -= 0x10;
        if (o->velY < -0x800)
            o->velY = -0x800;
        if (B(o, 0xcc) == 3)
            o->step = 2;
        ObjAddVelY7E(o);
        break;
    case 2:
        o->h->raw += MOTION_DRIFT.driftH << 8;
        o->y.raw += ((short *)&MOTION_DRIFT.driftY)[0] << 8;
        AnimAdvance(o);
        playerUpdateSpeedFromPad(o);
        ObjMotionStep(o);
        break;
    default:
        return;
    }
    ObjTileCollide(o, 0, 0);
    if (o->velY >= -0x383)
        playerAirSpinToFall(o);
    if (ObjCheckHeadCollision(o) || o->velY > 0) {
        o->unk84 = 0;
        v = 0x10;
        if (o->animFrame & 1)
            v = 0xf0;
        o->unk88 = v;
        B(o, 0xac) = 1;
        o->unk9C = 2;
        o->timer = 10;
        o->subState = 2;
        o->step = 3;
    }
    o->touchFlag = 0;
}

#endif
