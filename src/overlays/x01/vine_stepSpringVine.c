#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011a528 180 X001
// MATCHING 8011a528 180

extern void (*D_8013C44C[])(GameObject *);
extern void springVineIdle();
extern void springVineRopeStep1();
extern void springVineRopeStep2();
extern void springVineRopeStep3();
extern void springVineRopeStep4();
static void (*D_8013C460[5])(GameObject *) = {
    springVineIdle, springVineRopeStep1, springVineRopeStep2, springVineRopeStep3,
    springVineRopeStep4,
};
extern void ObjListPush_1F800224(GameObject *o);

void stepSpringVine(GameObject *o)
{
    GameObject *p;

    if (o->subtype != 0) return;
    D_8013C44C[o->subState](o);
    D_8013C460[o->subState]((GameObject *)o->unk94);
    ((GameObject *)o->unk94)->step = o->step;
    p = (GameObject *)o->unk94;
    if (p->visible == 0) {
        p->visible = 1;
        ObjListPush_1F800224((GameObject *)o->unk94);
    }
}

#endif
