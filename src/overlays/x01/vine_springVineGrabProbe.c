#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 80126fe4 144 X001
// MATCHING 80126fe4 144
extern short probeGrabPointInBoxA(GameObject *, GameObject *);

void springVineGrabProbe(GameObject *o, GameObject *e)
{
    if (e->subtype == 0 && probeGrabPointInBoxA(o, e)) {
        o->unk9E = 4;
        o->unkBA = 0;
        o->velY = 0;
        SPAD->unk19E = 0;
        o->unkB8 = (*(unsigned short*)&SPAD->unk3BC);
        e->unk6A = 1;
        (*(GameObject **)&SPAD->unk3C0) = e;
        e->animFrame = (o->animFrame & 1) << 1;
    }
}

#endif
