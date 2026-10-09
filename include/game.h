#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

/* psyq/kernel.h guards its structs on LANGUAGE_C, not _LANGUAGE_C */
#define LANGUAGE_C 1
#include "psyq/kernel.h"
#include "psyq/libetc.h"
#include "psyq/libcd.h"
#include "psyq/libpress.h"
#include "psyq/libgpu.h"
#include "psyq/libgte.h"
#include "psyq/libspu.h"
#include "psyq/libsnd.h"
#include "cdfiles.h"

/* The declarations of the game, by subject. The order matters: later files
   use the types of the earlier ones. */
#include "game/macros.h"
#include "game/areas.h"
#include "game/items.h"
#include "game/events.h"
#include "game/ui.h"
#include "game/vector.h"
#include "game/sound.h"
#include "game/movie.h"
#include "game/system.h"
#include "game/cdload.h"
#include "game/message.h"
#include "game/object.h"
#include "game/script.h"
#include "game/state.h"
#include "game/data.h"
#include "game/functions.h"

#endif // GAME_H
