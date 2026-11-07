#include "common.h"
#include "game.h"

/* This object replaces only the verified PAL dispatcher slice. The shared
 * implementation can also serve the separately proposed US dispatcher.
 */
#if REGION == REGION_EU && (VERSION == 0 || VERSION == 1)
#include "player_update.inc"
#endif
