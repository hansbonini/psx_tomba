#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

/* ========================================================================
 * Psy-Q headers
 */

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

typedef struct fileLink {
    /* 0x0 */ CdlLOC loc;
    /* 0x4 */ int    size;
} fileLink;

/* ========================================================================
 * Macros
 */

/* Scratchpad fields reached from code that has no `scratchpad*` handy.
   Each expands to exactly the cast it replaced, so the generated code is
   unchanged; the names mirror the fields of `struct scratchpad`. */
#define NEXT_PRIM          (*(int*)0x1F800164)      /* 0x164 */
#define MOVIE_PLAY_STATE   (*(u8*)0x1F8001CC)       /* 0x1CC */
#define LOAD_COMPLETE      (*(u8*)0x1F8001CE)       /* 0x1CE */
#define MOVIE_ID           (*(u_char*)0x1F8001CD)      /* 0x1CD */
#define MOVIE_SKIP_REQUEST (*(u_char*)0x1F8001D3)      /* 0x1D3 */
#define CD_QUEUE_HEAD      (*(s32*)0x1F80029C)        /* 0x29C */
#define CD_QUEUE_TAIL      (*(s32*)0x1F8002A0)        /* 0x2A0 */
#define CURRENT_OT         (*(u_long*)0x1F8001E0)   /* 0x1E0 */
#define PAUSE_TOGGLE       (*(u16*)0x1F8001EE)      /* 0x1EE */
#define PAUSE_FLAGS        (*(u16*)0x1F8001F0)      /* 0x1F0 */
#define FRAME_BUFFER_INDEX (*(s16*)0x1F8001F4)      /* 0x1F4 */
#define JOYPAD_STATE       (*(u16*)0x1F8001FC)      /* 0x1FC */

#define CURRENT_TASK       (*(unkstruct_1F8001D4**)0x1F8001D4)
#define TASK_TABLE  0x801FD800
#define TIM_SCRATCH ((u_long*)0x801FBE00)

#define D_8009B01C ((u_long*)((byte*)&D_8009B010+0xC))
#define D_8009B034 ((DISPENV*)((byte*)&D_8009B010+0x24))
#define LZ_FILE_CTRL ((lz_t*)0x1F800070)
#define D_8009E3D4 ((void*)0x8009E3D4)

#define READ32(_dst, _src) { \
    _dst = (((u_char *)_src)[1] << 8) | (((u_char *)_src)[0] << 0) \
        | ((((u_char *)_src)[3] << 8) | (((u_char *)_src)[2] << 0) << 16);\
    _src = (char*)_src + 4; \
}
#define READ16(_dst, _src) { \
    _dst = (((u_char *)_src)[1] << 8) | ((u_char *)_src)[0]; \
    _src = (char*)_src + 2; \
}
/*
 * Set Primitive X/Y
 */
#define setXY(p, _x, _y) (p)->x = _x, (p)->y = _y

/* ========================================================================
 * Enums -- areas and sections
 */

typedef enum {
    /*0x00*/ AREA00_VILLAGEOFALLBEGINNINGS,
    /*0x01*/ AREA01_DWARFFOREST,
    /*0x02*/ AREA02_DWARFVILLAGE,
    /*0x03*/ AREA03_PHOENIXMOUNTAIN,
    /*0x04*/ AREA04_HAUNTEDMANSION,
    /*0x05*/ AREA05_BACCUSVILLAGE,
    /*0x06*/ AREA06_DIRTMOTOCROSS,
    /*0x07*/ AREA07_DWARFFORESTPURIFIED,
    /*0x08*/ AREA08_BACCUSLAKE,
    /*0x09*/ AREA09_MUSHROOMVILLAGE,
    /*0x0A*/ AREA10_DEEPJUNGLE,
    /*0x0B*/ AREA11_VILLAGEOFCIVILIZATION,
    /*0x0C*/ AREA12_HAUNTEDMANSIONPURIFIED,
    /*0x0D*/ AREA13_PIGISLAND,
    /*0x0E*/ AREA14_EVILPIGS,
    /*0x0F*/ AREA15_UNKNOWN,
    /*0x10*/ AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER,
    /*0x11*/ AREA17_VILLAGEOFCIVILIZATIONIRONTOWER,
    /*0x12*/ AREA18_VILLAGEOFCIVILIZATIONYCROSSING,
    /*0x13*/ AREA19_VILLAGEOFCIVILIZATIONPURIFIED,
} AREA;

typedef enum {
    /*0x00*/ AREA00_SECTION00_VILLAGEOFALLBEGINNINGS,
    /*0x01*/ AREA00_SECTION01_FORESTOFALLBEGINNINGS,
    /*0x02*/ AREA00_SECTION02_FORESTOFALLBEGINNINGSHUTENTRANCE,
    /*0x03*/ AREA00_SECTION03_100YEAROLDMANSHUT,
    /*0x04*/ AREA00_SECTION04_BEHINDTHEHUT,
    /*0x05*/ AREA00_SECTION05_OLPOND
} AREA00_SECTION;

typedef enum {
    /*0x00*/ AREA01_SECTION00_FORESTOF100FLOWERS,
    /*0x01*/ AREA01_SECTION01_FORESTOF100FLOWERSRIGHTENTRANCE,
    /*0x02*/ AREA01_SECTION02_WOBBLYWHARF,
    /*0x03*/ AREA01_SECTION03_WATCHTOWER,
    /*0x04*/ AREA01_SECTION04_CHARITYSQUARE
} AREA01_SECTION;

typedef enum {
    /*0x00*/ AREA02_SECTION00_DWARFVILLAGE,
    /*0x01*/ AREA02_SECTION01_DWARFELDERSHUT,
    /*0x02*/ AREA02_SECTION02_UNDERGROUNDPRISON,
    /*0x03*/ AREA02_SECTION03_UNDERGROUNDMAZE,
    /*0x04*/ AREA02_SECTION04_MILLIONYEAROLDMANSROOM,
    /*0x05*/ AREA02_SECTION05_THESMALLSTRANGEROOM
} AREA02_SECTION;

typedef enum {
    /*0x00*/ AREA03_SECTION00_STORMYMOUNTAIN,
    /*0x01*/ AREA03_SECTION01_STORMYMOUNTAINSECOND,
    /*0x02*/ AREA03_SECTION02_LAVACAVES,
    /*0x03*/ AREA03_SECTION03_PHOENIXNEST,
    /*0x04*/ AREA03_SECTION04_STORMYMOUNTAINPURIFIED,
    /*0x05*/ AREA03_SECTION05_STORMYMOUNTAINPURIFIEDSECOND
} AREA03_SECTION;

typedef enum {
    /*0x00*/ AREA04_SECTION00_NORTHSIDEOFMANSION,
    /*0x01*/ AREA04_SECTION01_WESTSIDEOFMANSION,
    /*0x02*/ AREA04_SECTION02_SOUTHSIDEOFMANSION,
    /*0x03*/ AREA04_SECTION03_EASTSIDEOFMANSION,
    /*0x04*/ AREA04_SECTION04_SUNNYROOM,
    /*0x05*/ AREA04_SECTION05_THIEFSROOMONE,
    /*0x06*/ AREA04_SECTION06_SWIMMINGROOM,
    /*0x07*/ AREA04_SECTION07_KEYHOLEROOM,
    /*0x08*/ AREA04_SECTION08_HIDINGROOM,
    /*0x09*/ AREA04_SECTION09_ROOMOFTRIBULATION,
    /*0x0A*/ AREA04_SECTION10_LAUGHINGROOM,
    /*0x0B*/ AREA04_SECTION11_CIVILIZATIONROOM,
    /*0x0C*/ AREA04_SECTION12_TRAPROOM,
    /*0x0D*/ AREA04_SECTION13_TRICKROOM,
    /*0x0E*/ AREA04_SECTION14_SUNTORCHSTAND,
    /*0x0F*/ AREA04_SECTION15_1000YEAROLDMANSROOM,
    /*0x10*/ AREA04_SECTION16_SHADOWROOM,
    /*0x11*/ AREA04_SECTION17_THIEFSROOMTWO,
    /*0x12*/ AREA04_SECTION18_THIEFSROOMTHREE,
    /*0x13*/ AREA04_SECTION19_CRYINGROOM,
} AREA04_SECTION;

typedef enum {
    /*0x00*/ AREA05_SECTION01_BACCUSVILLAGE,
    /*0x01*/ AREA05_SECTION02_CENTRALPARK,
    /*0x02*/ AREA05_SECTION03_BACCUSVILLAGE,
    /*0x03*/ AREA05_SECTION04_CENTRALPARK
} AREA05_SECTION;

typedef enum {
    /*0x00*/ AREA06_SECTION01_THEMERMAIDSINGINGROCKBEACH,
    /*0x01*/ AREA06_SECTION02_THEMERMAIDSINGINGROCKMERMAID
} AREA06_SECTION;

typedef enum {
    /*0x00*/ AREA07_SECTION00_FORESTOF100FLOWERS,
    /*0x01*/ AREA07_SECTION01_FORESTOF100FLOWERSRIGHTENTRANCE,
    /*0x02*/ AREA07_SECTION02_WOBBLYWHARF,
    /*0x03*/ AREA07_SECTION03_WATCHTOWER,
    /*0x04*/ AREA07_SECTION04_CHARITYSQUARE
} AREA07_SECTION;

typedef enum {
    /*0x00*/ AREA08_SECTION00_BACCUSLAKE,
    /*0x01*/ AREA08_SECTION01_BACCUSPIER,
    /*0x02*/ AREA08_SECTION02_BACCUSLAKE,
    /*0x03*/ AREA08_SECTION03_BACCUSPIER
} AREA08_SECTION;

typedef enum {
    /*0x00*/ AREA09_SECTION00_MUSHROOMFOREST,
    /*0x01*/ AREA09_SECTION01_LAKE,
    /*0x02*/ AREA09_SECTION02_MANSIONGRANDFATHERCLOCKROOM,
    /*0x03*/ AREA09_SECTION03_MANSIONCHANDELIERROOM,
    /*0x04*/ AREA09_SECTION04_MANSIONDESCENDINGSTAIRS,
    /*0x05*/ AREA09_SECTION05_MANSIONASCENDINGSTAIRS,
    /*0x06*/ AREA09_SECTION06_LEAFSLIDER
} AREA09_SECTION;

typedef enum {
    /*0x00*/ AREA10_SECTION00_MASAKARIJUNGLE,
    /*0x01*/ AREA10_SECTION01_MASAKARIRIVER,
    /*0x02*/ AREA10_SECTION02_OLDTREEHILL,
    /*0x03*/ AREA10_SECTION03_TRICKVILLAGE,
    /*0x04*/ AREA10_SECTION04_MASAKARIJUNGLEPURIFIED,
    /*0x05*/ AREA10_SECTION05_MASAKARIRIVERPURIFIED,
    /*0x06*/ AREA10_SECTION06_OLDTREEHILLPURIFIED,
    /*0x07*/ AREA10_SECTION07_TRICKVILLAGEPURIFIED,
    /*0x08*/ AREA10_SECTION08_10000YEAROLDMANSROOM
} AREA10_SECTION;

typedef enum {
    /*0x00*/ AREA11_SECTION00_LUMBERJACKTOWN,
    /*0x01*/ AREA11_SECTION01_LUMBERJACKFACTORY,
    /*0x02*/ AREA11_SECTION02_DRIEDWISHINGWELL
} AREA11_SECTION;

typedef enum {
    /*0x00*/ AREA12_SECTION00_NORTHSIDEOFMANSION,
    /*0x01*/ AREA12_SECTION01_WESTSIDEOFMANSION,
    /*0x02*/ AREA12_SECTION02_SOUTHSIDEOFMANSION,
    /*0x03*/ AREA12_SECTION03_EASTSIDEOFMANSION,
    /*0x04*/ AREA12_SECTION04_SUNNYROOM,
    /*0x05*/ AREA12_SECTION05_THIEFSROOMONE,
    /*0x06*/ AREA12_SECTION06_SWIMMINGROOM,
    /*0x07*/ AREA12_SECTION07_KEYHOLEROOM,
    /*0x08*/ AREA12_SECTION08_HIDINGROOM,
    /*0x09*/ AREA12_SECTION09_ROOMOFTRIBULATION,
    /*0x0A*/ AREA12_SECTION10_LAUGHINGROOM,
    /*0x0B*/ AREA12_SECTION11_CIVILIZATIONROOM,
    /*0x0C*/ AREA12_SECTION12_TRAPROOM,
    /*0x0D*/ AREA12_SECTION13_TRICKROOM,
    /*0x0E*/ AREA12_SECTION14_SUNTORCHSTAND,
    /*0x0F*/ AREA12_SECTION15_1000YEAROLDMANSROOM,
    /*0x10*/ AREA12_SECTION16_SHADOWROOM,
    /*0x11*/ AREA12_SECTION17_THIEFSROOMTWO,
    /*0x12*/ AREA12_SECTION18_THIEFSROOMTHREE,
    /*0x13*/ AREA12_SECTION19_CRYINGROOM,
} AREA12_SECTION;

typedef enum {
    /*0x00*/ AREA13_SECTION00_PIGISLAND,
    /*0x01*/ AREA13_SECTION01_PIGISLANDCAVE,
    /*0x02*/ AREA13_SECTION02_PIGISLANDCAVEEND
} AREA13_SECTION;

typedef enum {
    /*0x00*/ AREA14_SECTION00_EVILPIGAREAONE,
    /*0x01*/ AREA14_SECTION01_EVILPIGAREATWO,
    /*0x02*/ AREA14_SECTION02_EVILPIGAREATHREE,
    /*0x03*/ AREA14_SECTION03_EVILPIGAREAFOUR,
    /*0x04*/ AREA14_SECTION04_EVILPIGAREAFIVE,
    /*0x05*/ AREA14_SECTION05_EVILPIGAREASIX,
    /*0x06*/ AREA14_SECTION06_EVILPIGAREASEVEN,
    /*0x07*/ AREA14_SECTION07_EVILPIGAREAEIGHT,
} AREA14_SECTION;

typedef enum {
    /*0x00*/ AREA15_SECTION00_SOFTLOCK1,
    /*0x01*/ AREA15_SECTION01_SOFTLOCK2,
    /*0x02*/ AREA15_SECTION02_BLACKSCREEN1,
    /*0x03*/ AREA15_SECTION03_BLACKSCREEN2
} AREA15_SECTION;

typedef enum {
    /*0x00*/ AREA16_SECTION00_STONESTOWN,
    /*0x01*/ AREA16_SECTION01_CLOCKTOWERSOFTLOCK,
    /*0x02*/ AREA16_SECTION02_CLOCKTOWERCRASH,
    /*0x03*/ AREA16_SECTION03_CLOCKTOWERENGINESROOM,
    /*0x04*/ AREA16_SECTION04_CLOCKTOWERENTRANCE,
    /*0x05*/ AREA16_SECTION05_CLOCKTOWERHALFWAYUP,
    /*0x06*/ AREA16_SECTION06_CLOCKTOWERENGINESROOMNOEXIT
} AREA16_SECTION;

typedef enum {
    /*0x00*/ AREA17_SECTION00_IRONTOWNCRASH,
    /*0x01*/ AREA17_SECTION01_IRONCASTLEENTRANCE,
    /*0x02*/ AREA17_SECTION02_IRONCASTLEMAINROOM,
    /*0x03*/ AREA17_SECTION03_IRONCASTLELEFTROOM,
    /*0x04*/ AREA17_SECTION04_IRONCASTLERIGHTROOM,
    /*0x05*/ AREA17_SECTION05_IRONCASTLEENGINEROOM,
    /*0x06*/ AREA17_SECTION06_IRONCASTLESOFTLOCK1,
    /*0x07*/ AREA17_SECTION07_IRONCASTLESOFTLOCK2,
    /*0x08*/ AREA17_SECTION08_IRONCASTLESOFTLOCK3,
    /*0x09*/ AREA17_SECTION09_IRONCASTLECRASH,
    /*0x0A*/ AREA17_SECTION10_IRONCASTLESOFTLOCK4,
    /*0x0B*/ AREA17_SECTION11_IRONCASTLESOFTLOCK5
} AREA17_SECTION;

typedef enum {
    /*0x00*/ AREA18_SECTION00_VILLAGEOFCIVILIZATION,
    /*0x01*/ AREA18_SECTION01_YCROSSING,
    /*0x02*/ AREA18_SECTION02_WITCHSHUT
} AREA18_SECTION;

typedef enum {
    /*0x00*/ AREA19_SECTION00_DWARFELDERSHUT,
    /*0x01*/ AREA19_SECTION01_DWARFELDERSHUT,
    /*0x02*/ AREA19_SECTION02_HIDDENVILLAGE
} AREA19_SECTION;

/* ========================================================================
 * Enums -- items, events, UI and input
 */

typedef enum {
    /* 0x00 */ ITEM_CHICK,
    /* 0x01 */ ITEM_FROG,
    /* 0x02 */ ITEM_LOSTDWARF,
    /* 0x03 */ ITEM_BANANAS,
    /* 0x04 */ ITEM_FURIOUSTORNADO,
    /* 0x05 */ ITEM_100YEAROLDBELL,
    /* 0x06 */ ITEM_100YEAROLDKEY,
    /* 0x07 */ ITEM_CHARITYWINGS,
    /* 0x08 */ ITEM_BITINGPLANTFLOWER,
    /* 0x09 */ ITEM_HEALINGMUSHROOM,
    /* 0x0A */ ITEM_BUCKET,
    /* 0x0B */ ITEM_TELESCOPE,
    /* 0x0C */ ITEM_TEARJAR,
    /* 0x0D */ ITEM_FLOWERTEARS,
    /* 0x0E */ ITEM_BARON,
    /* 0x0F */ ITEM_BAKEDYAM,
    /* 0x10 */ ITEM_LEAFBUTTERFLY,
    /* 0x11 */ ITEM_TORCH,
    /* 0x12 */ ITEM_BUCKETOFWATER,
    /* 0x13 */ ITEM_DIRTYMIRROR,
    /* 0x14 */ ITEM_FUNKYPARASOL,
    /* 0x15 */ ITEM_WOODBOOMERANG,
    /* 0x16 */ ITEM_STONEBOOMERANG,
    /* 0x17 */ ITEM_IRONBOOMERANG,
    /* 0x18 */ ITEM_DASHINGPANTS,
    /* 0x19 */ ITEM_MAP,
    /* 0x1A */ ITEM_BROKENVASE,
    /* 0x1B */ ITEM_BLACKJACK,
    /* 0x1C */ ITEM_FLASHPANTS,
    /* 0x1D */ ITEM_JUMPINGPANTS,
    /* 0x1E */ ITEM_LUNCHBOX,
    /* 0x1F */ ITEM_LARGELUNCHBOX,
    /* 0x20 */ ITEM_NORMALPANTS,
    /* 0x21 */ ITEM_GRAPPLE,
    /* 0x22 */ ITEM_GRAPPLEJACK,
    /* 0x23 */ ITEM_BABYPIG,
    /* 0x24 */ ITEM_1000YEAROLDKEY,
    /* 0x25 */ ITEM_REDPIGBAG,
    /* 0x26 */ ITEM_ORANGEPIGBAG,
    /* 0x27 */ ITEM_YELLOWPIGBAG,
    /* 0x28 */ ITEM_GREENPIGBAG,
    /* 0x29 */ ITEM_BLUEEVILPIGBAG,
    /* 0x2A */ ITEM_NAVYPIGBAG,
    /* 0x2B */ ITEM_PINKPIGBAG,
    /* 0x2C */ ITEM_10000YEAROLDKEY,
    /* 0x2D */ ITEM_1000000YEAROLDKEY,
    /* 0x2E */ ITEM_LARGEKEYPANEL_1,
    /* 0x2F */ ITEM_LARGEKEYPANEL_2,
    /* 0x30 */ ITEM_LARGEKEYPANEL_3,
    /* 0x31 */ ITEM_LARGEKEYPANEL_4,
    /* 0x32 */ ITEM_LARGEKEYPANEL_5,
    /* 0x33 */ ITEM_FUELBARREL,
    /* 0x34 */ ITEM_RAINESSENCE,
    /* 0x35 */ ITEM_BIGKEY,
    /* 0x36 */ ITEM_SMALLKEY,
    /* 0x37 */ ITEM_CHEESE,
    /* 0x38 */ ITEM_MAGICMIRROR,
    /* 0x39 */ ITEM_TORNMAP1,
    /* 0x3A */ ITEM_TORNMAP2,
    /* 0x3B */ ITEM_RUBBERGLOVES,
    /* 0x3C */ ITEM_BOMB,
    /* 0x3D */ ITEM_IRONHAMMER,
    /* 0x3E */ ITEM_IRONWHEEL,
    /* 0x3F */ ITEM_FLOWERSEEDS,
    /* 0x40 */ ITEM_PIPE,
    /* 0x41 */ ITEM_WINE,
    /* 0x42 */ ITEM_BUNKFLOWER,
    /* 0x43 */ ITEM_MATHBEADD1,
    /* 0x44 */ ITEM_MATHBEADD2,
    /* 0x45 */ ITEM_MATHBEADD3,
    /* 0x46 */ ITEM_MATHBEADD4,
    /* 0x47 */ ITEM_MATHBEADD5,
    /* 0x48 */ ITEM_MATHBEADD6,
    /* 0x49 */ ITEM_MATHBEADD7,
    /* 0x4A */ ITEM_MATHBEADD8,
    /* 0x4B */ ITEM_MATHBEADD9,
    /* 0x4C */ ITEM_MATHBEADD10,
    /* 0x4D */ ITEM_MATHBEADD11,
    /* 0x4E */ ITEM_MATHBEADD12,
    /* 0x4F */ ITEM_MATHBEADD13,
    /* 0x50 */ ITEM_MATHBEADD14,
    /* 0x51 */ ITEM_MATHBEADD15,
    /* 0x52 */ ITEM_CRYSTAL,
    /* 0x53 */ ITEM_BELL,
    /* 0x54 */ ITEM_CAKE,
    /* 0x55 */ ITEM_HAT,
    /* 0x56 */ ITEM_SHIPPARTS,
    /* 0x57 */ ITEM_BRONZEMEDAL,
    /* 0x58 */ ITEM_SILVERMEDAL,
    /* 0x59 */ ITEM_GOLDMEDAL,
    /* 0x5A */ ITEM_LETTER,
    /* 0x5B */ ITEM_WOOD,
    /* 0x5C */ ITEM_RAFT,
    /* 0x5D */ ITEM_GOLDENLEAFBUTTERFLY,
    /* 0x5E */ ITEM_GOLDENFRUIT,
    /* 0x5F */ ITEM_GOLDENFLOWER,
    /* 0x60 */ ITEM_PSYCHICFISH,
    /* 0x61 */ ITEM_SHOVEL,
    /* 0x62 */ ITEM_JEWELOFFIRE,
    /* 0x63 */ ITEM_JEWELOFWATER,
    /* 0x64 */ ITEM_JEWELOFWIND,
    /* 0x65 */ ITEM_MIGHTYFISH,
    /* 0x66 */ ITEM_SILVERPOWDER,
    /* 0x67 */ ITEM_MOLASSES,
    /* 0x68 */ ITEM_KOKKACLAW,
    /* 0x69 */ ITEM_BUTAMUSHITHORN,
    /* 0x6A */ ITEM_NEEDLEGATORTEETH,
    /* 0x6B */ ITEM_FLOWER,
    /* 0x6C */ ITEM_ELECTRIC_EEL,
    /* 0x6D */ ITEM_BLACKWATER,
    /* 0x6E */ ITEM_REDCANDY,
    /* 0x6F */ ITEM_BLUECANDY,
    /* 0x70 */ ITEM_GREENCANDY,
    /* 0x71 */ ITEM_BLACKCANDY,
    /* 0x72 */ ITEM_SILVERCANDY,
    /* 0x73 */ ITEM_GOLDENCANDY,
    /* 0x74 */ ITEM_FORBIDDENMUSHROOM,
    /* 0x75 */ ITEM_BLUEPOWDER,
    /* 0x76 */ ITEM_COCONUTS,
    /* 0x77 */ ITEM_FUNGALEATHER,
    /* 0x78 */ ITEM_GRANDPASBRACELET,
    /* 0x79 */ ITEM_WEEDKILLER,
    /* 0x7A */ ITEM_FUNGATREE,
    /* 0x7B */ ITEM_FUNGASAP,
    /* 0x7C */ ITEM_1000YEAROLDBELL,
    /* 0x7D */ ITEM_FUNGADRUM,
    /* 0x7E */ ITEM_MIGHTYFISHFOOD,
    /* 0x7F */ ITEM_UNUSUALKEY,
    /* 0x80 */ ITEM_CHUCKLINGMUSHROOM,
    /* 0x81 */ ITEM_WEEPINGMUSHROOM,
    /* 0x82 */ ITEM_MYSTERIOUSMUSHROOM,
    /* 0x83 */ ITEM_OVENBAKEDMUSHROOM,
    /* 0x84 */ ITEM_SACREDFISH,
    /* 0x85 */ ITEM_CHICK2,
    /* 0x86 */ ITEM_CHICK3,
    /* 0x87 */ ITEM_GOLDENBOWL,
    /* 0x88 */ ITEM_FLOWERTEARS2,
    /* 0x89 */ ITEM_SMALLDRUM,
    /* 0x8A */ ITEM_RISEANDSHINEPOWDER,
    /* 0x8B */ ITEM_BANANAJUICE,
    /* 0x8C */ ITEM_CHIEFSPEAR,
    /* 0x8D */ ITEM_CHARLESPANTS,
    /* 0x8E */ ITEM_THREECRYSTALBALLS,
    /* 0x8F */ ITEM_WHATTHETHIEFLOST,
    /* 0x90 */ ITEM_WHATTHETHIEFFORGOT,
    /* 0x91 */ ITEM_BOSSJEWEL,
    /* 0x92 */ ITEM_ORDINARYMUSHROOM,
    /* 0x93 */ ITEM_TRASHCAN,
    /* 0x94 */ ITEM_SEASHELLNECKLACE,
    /* 0x95 */ ITEM_THIEFSWIRE,
    /* 0x96 */ ITEM_STRONGWIRE,
    /* 0x97 */ ITEM_10000YEAROLDBELL,
    /* 0x98 */ ITEM_1000000YEAROLDBELL,
    /* 0x99 */ ITEM_COLDMEDICINE,
    /* 0x9A */ ITEM_YANSLUNCHBOX,
    /* 0x9B */ ITEM_KEYTOOLPOND,
    /* 0x9C */ ITEM_HEALINGHERBS,
    /* 0x9D */ ITEM_KNOWLEDGEFRUIT,
    /* 0x9E */ ITEM_SEAWEED,
    /* 0x9F */ ITEM_MINERSHAT,
} ITEM;

typedef enum {
    /* 0x00 */ EVENT_GRANDPASBRACELET,
    /* 0x01 */ EVENT_THE100YEAROLDWISEMAN,
    /* 0x02 */ EVENT_CLEARTHEFOG,
    /* 0x03 */ EVENT_TAKEMEHOME,
    /* 0x04 */ EVENT_MOTOCROSSCOURSE,
    /* 0x05 */ EVENT_WHOAREYOU,
    /* 0x06 */ EVENT_ALARGEPUDDLE,
    /* 0x07 */ EVENT_HIDEANDGOSEEK,
    /* 0x08 */ EVENT_ICANTSWIM,
    /* 0x09 */ EVENT_INSIDETHEKOKKAEGGS,
    /* 0x0A */ EVENT_TALEOFTHEEVILPIGS,
    /* 0x0B */ EVENT_THE1000YEAROLDMAN,
    /* 0x0C */ EVENT_DWARFELDER,
    /* 0x0D */ EVENT_BEGINNERSDWARFLANGUAGE,
    /* 0x0E */ EVENT_ALOSTCHILD,
    /* 0x0F */ EVENT_FLOWERSEEDS,
    /* 0x10 */ EVENT_THEAPBOX,
    /* 0x11 */ EVENT_SAVETHEDWARVES,
    /* 0x12 */ EVENT_TEACHINGOFTHEDWARVES,
    /* 0x13 */ EVENT_LOSTANDFOUND,
    /* 0x14 */ EVENT_STOPTHEFIGHT,
    /* 0x15 */ EVENT_THEGREATESCAPE,
    /* 0x16 */ EVENT_LOOKANDSEE,
    /* 0x17 */ EVENT_AMANSBESTFRIEND,
    /* 0x18 */ EVENT_WHATISTHIS,
    /* 0x19 */ EVENT_TREASURESFROMTHEMANSION,
    /* 0x1A */ EVENT_TOPHOENIXMOUNTAIN,
    /* 0x1B */ EVENT_THEBROKENFOUNTAIN,
    /* 0x1C */ EVENT_AFAMILIARLOOKINGMANSION,
    /* 0x1D */ EVENT_ASTORMYPIGBAG,
    /* 0x1E */ EVENT_PHOENIXMOUNTAIN,
    /* 0x1F */ EVENT_WHEREDIDICOMEFROM,
    /* 0x20 */ EVENT_MINIATUREMAKINGTRUMPETS,
    /* 0x21 */ EVENT_THEFAMOUSDIGGER,
    /* 0x22 */ EVENT_LAVACAVES,
    /* 0x23 */ EVENT_THEMASTEOFSKIES,
    /* 0x24 */ EVENT_WHATSAFUNGA,
    /* 0x25 */ EVENT_MONSTERHUNT,
    /* 0x26 */ EVENT_DEATHFRUITJUICE,
    /* 0x27 */ EVENT_PLANTAFLOWERGARDEN,
    /* 0x28 */ EVENT_TEARSFROMAFLOWER,
    /* 0x29 */ EVENT_SMILE,
    /* 0x2A */ EVENT_CRYBABY,
    /* 0x2B */ EVENT_CANTSTOPCRYING,
    /* 0x2C */ EVENT_THEREDFORTUNETELLER,
    /* 0x2D */ EVENT_APSLOTMACHINE,
    /* 0x2E */ EVENT_WHERESTHEBABYMOUSE,
    /* 0x2F */ EVENT_SOMECHEESEPLEASE,
    /* 0x30 */ EVENT_APOINTSHOW,
    /* 0x31 */ EVENT_ADRINKFORGOWNUPS,
    /* 0x32 */ EVENT_ROADTOBACCUSLAKE,
    /* 0x33 */ EVENT_ASMALLKEYHOLE,
    /* 0x34 */ EVENT_ABABYSBRIDGE,
    /* 0x35 */ EVENT_THEMOUSEPIGBAG,
    /* 0x36 */ EVENT_THEHAUNTEDMANSION,
    /* 0x37 */ EVENT_ALARGEKEYHOLE,
    /* 0x38 */ EVENT_PAINTINGOFABIGKEY,
    /* 0x39 */ EVENT_BREAKTHEMAGICEGG,
    /* 0x3A */ EVENT_REDHIDDENPOWERS,
    /* 0x3B */ EVENT_THEELDERREQUEST,
    /* 0x3C */ EVENT_LETSLEARNWORDS2,
    /* 0x3D */ EVENT_JUNGLEOFTHEMASAKARITRIBE,
    /* 0x3E */ EVENT_TREEOFKNOWLEDGEKNOWS,
    /* 0x3F */ EVENT_THEPUMPROCKS,
    /* 0x40 */ EVENT_AREFRESHINGDRINK,
    /* 0x41 */ EVENT_INEEDATEARBOTTLE,
    /* 0x42 */ EVENT_THESTOLENPICTUREBOOKOFTHEISLAND,
    /* 0x43 */ EVENT_DECIPHERSCRIBBLEINSLAND,
    /* 0x44 */ EVENT_SECRETOFTHEISLAND1,
    /* 0x45 */ EVENT_SECRETOFTHEISLAND2,
    /* 0x46 */ EVENT_SECRETOFTHEISLAND3,
    /* 0x47 */ EVENT_SECRETOFTHEISLAND4,
    /* 0x48 */ EVENT_SECRETOFTHEISLAND5,
    /* 0x49 */ EVENT_WENEEDPOWER,
    /* 0x4A */ EVENT_CATCHTHEELECTRICITY,
    /* 0x4B */ EVENT_ANINCIDENTFINDTHECULPRIT,
    /* 0x4C */ EVENT_WONDERSOFTHEBLACKWATER,
    /* 0x4D */ EVENT_THECIVILIZATIONMACHINE,
    /* 0x4E */ EVENT_FINDCHARLES,
    /* 0x4F */ EVENT_WHATSUNDERTHEFOREST,
    /* 0x50 */ EVENT_THE100FLOWERFOREST,
    /* 0x51 */ EVENT_THEBOSSTREASURE,
    /* 0x52 */ EVENT_IMSOHUNGRY,
    /* 0x53 */ EVENT_THERUSTYSTEELCAR,
    /* 0x54 */ EVENT_UNKNOWN21,
    /* 0x55 */ EVENT_THEDEEPJUNGLEPIG,
    /* 0x56 */ EVENT_HEALINGHERBSFORBARON,
    /* 0x57 */ EVENT_DELICIOUSKNOWLEDGEFRUIT,
    /* 0x58 */ EVENT_SEAWEEDFORYOURHEALTH,
    /* 0x59 */ EVENT_UNKNOWN22,
    /* 0x5A */ EVENT_BLUEHIDDENPOWERS,
    /* 0x5B */ EVENT_THEPIGSVILLAGE,
    /* 0x5C */ EVENT_THEHOUSEWITHWHITESMOKE,
    /* 0x5D */ EVENT_LETSLEARNWORDS3,
    /* 0x5E */ EVENT_LETSGETALONG,
    /* 0x5F */ EVENT_ABROKENBRIDGE,
    /* 0x60 */ EVENT_THEGREATBOULDERINTHEVILLAGEOFTHETREEPEOPLE,
    /* 0x61 */ EVENT_WHATTIMEISIT,
    /* 0x62 */ EVENT_UNKNOWN30,
    /* 0x63 */ EVENT_THEUNBREAKABLEGEAR,
    /* 0x64 */ EVENT_ABIGKEYHOLE,
    /* 0x65 */ EVENT_HOWAREWEGOINDTOKAEIT,
    /* 0x66 */ EVENT_BREAKTHERUSTYDOOR,
    /* 0x67 */ EVENT_THECUTEWITCH,
    /* 0x68 */ EVENT_FOODFORFUEL,
    /* 0x69 */ EVENT_INEEDABOMB,
    /* 0x6A */ EVENT_UNKNOWN34,
    /* 0x6B */ EVENT_UNKNOWN35,
    /* 0x6C */ EVENT_UNKNOWN36,
    /* 0x6D */ EVENT_THEPIGGLASSESINTHEPIGVILLAGE,
    /* 0x6E */ EVENT_UNKNOWN38,
    /* 0x6F */ EVENT_BACCUSVILLAGE,
    /* 0x70 */ EVENT_THEMERMAIDNECKLACE,
    /* 0x71 */ EVENT_BARONSSTRENGTH,
    /* 0x72 */ EVENT_WHATTHEWITCHLOST,
    /* 0x73 */ EVENT_ASAFEMUSHROOM,
    /* 0x74 */ EVENT_POWERUPFORTOOLS,
    /* 0x75 */ EVENT_UNKNOWN39,
    /* 0x76 */ EVENT_THE10000YEAROLDMAN,
    /* 0x77 */ EVENT_MIGHTYFISHFOOD,
    /* 0x78 */ EVENT_LETSMAKECANDY,
    /* 0x79 */ EVENT_THEMERMAIDSINGINGROCK,
    /* 0x7A */ EVENT_THEPIRATESTREASURE,
    /* 0x7B */ EVENT_THEUNDERWATERPIG,
    /* 0x7C */ EVENT_TRICKVILLAGE,
    /* 0x7D */ EVENT_THETHIEFSDOOR,
    /* 0x7E */ EVENT_THE10MATHBEADS,
    /* 0x7F */ EVENT_THE5GOLDENITEMS,
    /* 0x80 */ EVENT_UNBREAKABLEWIRE,
    /* 0x81 */ EVENT_GREENHIDDENPOWERS,
    /* 0x82 */ EVENT_UNKNOWN41,
    /* 0x83 */ EVENT_UNKNOWN42,
    /* 0x84 */ EVENT_TAKETWOOFTHESE,
    /* 0x85 */ EVENT_IWANTABRONZEMEDAL,
    /* 0x86 */ EVENT_IWANTASILVERMEDAL,
    /* 0x87 */ EVENT_IWANTAGOLDMEDAL,
    /* 0x88 */ EVENT_UNKNOWN43,
    /* 0x89 */ EVENT_UNKNOWN44,
    /* 0x8A */ EVENT_UNKNOWN45,
    /* 0x8B */ EVENT_UNKNOWN46,
    /* 0x8C */ EVENT_THETHREESISTERSOFKARAKURIFORT,
    /* 0x8D */ EVENT_LETTERSOFTHETHREESISTERS,
    /* 0x8E */ EVENT_UNKNOWN49,
    /* 0x8F */ EVENT_UNKNOWN50,
    /* 0x90 */ EVENT_MILLIONYEAROLDWISH,
    /* 0x91 */ EVENT_DIGLIKEAMOLE,
    /* 0x92 */ EVENT_THEBLUEFORTUNETELLER,
    /* 0x93 */ EVENT_UNKNOWN51,
    /* 0x94 */ EVENT_UNKNOWN52,
    /* 0x95 */ EVENT_UNKNOWN53,
    /* 0x96 */ EVENT_LETSRIDETHERAFT,
    /* 0x97 */ EVENT_TAKEOUT,
    /* 0x98 */ EVENT_UNKNOWN54,
    /* 0x99 */ EVENT_WHATSTHEUNDERWATER,
    /* 0x9A */ EVENT_UNKNOWN55,
    /* 0x9B */ EVENT_UNKNOWN56,
    /* 0x9C */ EVENT_SOURCEOFEVILMAGIC,
    /* 0x9D */ EVENT_SEVENFRIENDS,
    /* 0x9E */ EVENT_UNKNOWN57,
    /* 0x9F */ EVENT_THE8THEVILPIGBAG,
    /* 0xA0 */ EVENT_THEREALEVILPIG,
    /* 0xA1 */ EVENT_UNDERGROUNDTREASURE,
    /* 0xA2 */ EVENT_UNKNOWN58,
    /* 0xA3 */ EVENT_UNKNOWN59,
    /* 0xA4 */ EVENT_THEFLOWERTOWER,
    /* 0xA5 */ EVENT_UNKNOWN60,
    /* 0xA6 */ EVENT_AHUNGRYMONKEY,
    /* 0xA7 */ EVENT_PEACHFLOWERGAS,
    /* 0xA8 */ EVENT_THEEVILPIGBAG,
    /* 0xA9 */ EVENT_BITINGPLANTFLOWER,
    /* 0xAA */ EVENT_WHENTHEWINDDIESDOWN,
    /* 0xAB */ EVENT_THEPHOENIXFAVORITE,
    /* 0xAC */ EVENT_THEFIREPIGBAG,
    /* 0xAD */ EVENT_CHARLESPANTS,
    /* 0xAE */ EVENT_THEHAUNTEDPIGBAG,
    /* 0xAF */ EVENT_THEWORLDSGREATESTSMILE,
    /* 0xB0 */ EVENT_THEWORLDSGREATESTPOUT,
    /* 0xB1 */ EVENT_SOMETHINGCOOKIN,
    /* 0xB2 */ EVENT_LEAFBUTTERFLIES,
    /* 0xB3 */ EVENT_WHEREDTHELIGHTSGO,
    /* 0xB4 */ EVENT_WHERETHEBARRELSROLLS,
    /* 0xB5 */ EVENT_READYSETGO,
    /* 0xB6 */ EVENT_AMAGICMIRROR,
    /* 0xB7 */ EVENT_THEJUNGLEPIGBAG,
    /* 0xB8 */ EVENT_UNKNOWN61,
    /* 0xB9 */ EVENT_APRECIOUSTREASURECHEST,
    /* 0xBA */ EVENT_UNKNOWN62,
    /* 0xBB */ EVENT_THEMISTERIOUSMUSHROOM,
    /* 0xBC */ EVENT_LEAFSLIDER,
    /* 0xBD */ EVENT_REDBLUE,
    /* 0xBE */ EVENT_THETROUBLEDTHIEF,
    /* 0xBF */ EVENT_WHATTHETHIEFFORGOT,
    /* 0xC0 */ EVENT_UNKNOWN63,
    /* 0xC1 */ EVENT_UNKNOWN64,
    /* 0xC2 */ EVENT_UNKNOWN65,
    /* 0xC3 */ EVENT_UNKNOWN66,
    /* 0xC4 */ EVENT_UNKNOWN67,
    /* 0xC5 */ EVENT_UNKNOWN68,
    /* 0xC6 */ EVENT_UNKNOWN69,
    /* 0xC7 */ EVENT_UNKNOWN70,
    /* 0xC8 */ EVENT_UNKNOWN71,
    /* 0xC9 */ EVENT_UNKNOWN72,
    /* 0xCA */ EVENT_UNKNOWN73,
    /* 0xCB */ EVENT_UNKNOWN74,
    /* 0xCC */ EVENT_UNKNOWN76,
    /* 0xCD */ EVENT_UNKNOWN77,
    /* 0xCE */ EVENT_UNKNOWN78,
    /* 0xCF */ EVENT_UNKNOWN79,
    /* 0xD0 */ EVENT_UNKNOWN80,
    /* 0xD1 */ EVENT_UNKNOWN81,
    /* 0xD2 */ EVENT_UNKNOWN82,
    /* 0xD3 */ EVENT_UNKNOWN83,
    /* 0xD4 */ EVENT_UNKNOWN84,
    /* 0xD5 */ EVENT_UNKNOWN85,
    /* 0xD6 */ EVENT_UNKNOWN86,
    /* 0xD7 */ EVENT_UNKNOWN87,
    /* 0xD8 */ EVENT_UNKNOWN88,
    /* 0xD9 */ EVENT_UNKNOWN89,
    /* 0xDA */ EVENT_UNKNOWN90,
    /* 0xDB */ EVENT_UNKNOWN91,
    /* 0xDC */ EVENT_UNKNOWN92,
    /* 0xDD */ EVENT_UNKNOWN93,
    /* 0xDE */ EVENT_UNKNOWN94,
    /* 0xDF */ EVENT_UNKNOWN95,
    /* 0xE0 */ EVENT_UNKNOWN96,
    /* 0xE1 */ EVENT_UNKNOWN97,
    /* 0xE2 */ EVENT_UNKNOWN98,
    /* 0xE3 */ EVENT_UNKNOWN99,
    /* 0xE4 */ EVENT_UNKNOWN100,
    /* 0xE5 */ EVENT_UNKNOWN101,
    /* 0xE6 */ EVENT_UNKNOWN102,
    /* 0xE7 */ EVENT_UNKNOWN103,
    /* 0xE8 */ EVENT_UNKNOWN104,
    /* 0xE9 */ EVENT_UNKNOWN105,
    /* 0xEA */ EVENT_UNKNOWN106,
    /* 0xEB */ EVENT_UNKNOWN107,
    /* 0xEC */ EVENT_UNKNOWN108,
    /* 0xED */ EVENT_UNKNOWN109,
    /* 0xEE */ EVENT_UNKNOWN110,
    /* 0xEF */ EVENT_UNKNOWN111,
    /* 0xF0 */ EVENT_UNKNOWN112,
    /* 0xF1 */ EVENT_UNKNOWN113,
    /* 0xF2 */ EVENT_UNKNOWN114,
    /* 0xF3 */ EVENT_UNKNOWN115,
    /* 0xF4 */ EVENT_UNKNOWN116,
    /* 0xF5 */ EVENT_UNKNOWN117,
    /* 0xF6 */ EVENT_UNKNOWN118,
    /* 0xF7 */ EVENT_UNKNOWN119,
    /* 0xF8 */ EVENT_UNKNOWN120,
    /* 0xF9 */ EVENT_UNKNOWN121,
    /* 0xFA */ EVENT_UNKNOWN122,
    /* 0xFB */ EVENT_UNKNOWN123,
    /* 0xFC */ EVENT_UNKNOWN124,
    /* 0xFD */ EVENT_UNKNOWN125,
    /* 0xFE */ EVENT_UNKNOWN126,
    /* 0xFF */ EVENT_UNKNOWN127,
} EVENT;

typedef enum {
    /* 0x0 */ INVENTORY_SCREEN_ITEM,
    /* 0x1 */ INVENTORY_SCREEN_EVENT,
    /* 0x2 */ INVENTORY_SCREEN_STATUS,
    /* 0x3 */ INVENTORY_SCREEN_MAP,
    /* 0x4 */ INVENTORY_SCREEN_ITEM_ONLY,
} INVENTORY_SCREEN_ID;

typedef enum {
    SORT_MODE_1,
    SORT_MODE_2,
    SORT_MODE_3,
    SORT_MODE_4,
    SORT_MODE_DEFAULT = 0x8000,
} INVENTORY_SORT_MODE_ID;

typedef enum {
    TITLESCREEN_NEWGAME,
    TITLESCREEN_LOADGAME,
    TITLESCREEN_OPTIONS
} TITLESCREEN_OPTION_ID;

typedef enum {
    TITLESCREEN_MESSAGE_PRESSSTART,
    TITLESCREEN_MESSAGE_WHOOPCAMPCOPYRIGHT,
} TITLESCREEN_MESSAGE_ID;

typedef enum {
    JOY_SELECT   = 0x1,
    JOY_L3       = 0x2,
    JOY_R3       = 0x4,
    JOY_START    = 0x8,
    JOY_UP       = 0x10,
    JOY_RIGHT    = 0x20,
    JOY_DOWN     = 0x40,
    JOY_LEFT     = 0x80,
    JOY_L2       = 0x100,
    JOY_R2       = 0x200,
    JOY_L1       = 0x400,
    JOY_R1       = 0x800,
    JOY_TRIANGLE = 0x1000,
    JOY_CIRCLE   = 0x2000,
    JOY_CROSS    = 0x4000,
    JOY_SQUARE   = 0x8000,
} JOYPAD_BUTTONS;

/* ========================================================================
 * Structs
 */

typedef struct lz_t {
    int size;
    int offset;
} lz_t;

typedef struct unkstruct_01 {
    int unk0;
    int saved_reg_gp;
} unkstruct_01;

typedef struct unkstruct_1F8001D4 {
    short unk0;
    short unk2;
    int task_id;
    int task_sp;
    int task_func;
    int task_gp;
    volatile u_short unk14;
    byte unk16;
    byte unk17;
    byte unk18;
    byte unk19;
    byte unk1a;
    byte unk1b;
    byte unk1c;
    byte unk1d;
    byte unk1e;
    byte unk1f;
    byte unk20;
    byte unk21;
    byte unk22;
    byte unk23;
    byte unk24;
    byte unk25;
    byte unk26;
    byte unk27;
    byte unk28;
    byte unk29;
    byte unk2a;
    byte unk2b;
    byte unk2c;
    byte unk2d;
    byte unk2e;
    byte unk2f;
    byte unk30;
    byte unk31;
    byte unk32;
    byte unk33;
    byte unk34;
    byte unk35;
    byte unk36;
    byte unk37;
    byte unk38;
    byte unk39;
    byte unk3a;
    byte unk3b;
    byte unk3c;
    byte unk3d;
    byte unk3e;
    byte unk3f;
    byte unk40;
    byte unk41;
    byte unk42;
    byte unk43;
    byte unk44;
    byte unk45;
    byte unk46;
    byte unk47;
    short state0;
    u_short state1;
    short state2;
    union {
        volatile u_short volatile_value;
        u_short value;
    } unk4E;
    byte unk50;
    byte unk51;
    byte unk52;
    byte unk53;
    byte unk54;
    byte unk55;
    byte unk56;
    byte unk57;
    u_short timer;
    u_short unk5A;
    byte unk5C;
    byte unk5D;
    u_short unk5E;
    short unk60;
    short unk62;
    u_short unk64;
    byte unk66;
    byte unk67;
    u_char loadGameSelected;
    u_char titleScreenSelectedOption;
    u_char unk6A;
    u_char unk6B;
    u_char unk6C;
    u_char unk6D;
    u_char unk6E;
    u_char unk6F;
} unkstruct_1F8001D4;

/* PSX scratchpad (data cache) at 0x1F800000, 1 KiB.
   Field offsets were verified against the 14 local definitions this replaces. */
typedef struct scratchpad {
    /* 0x000  Shared scratch area -- NOT a stable layout. These bytes are reused
       with a different shape by each user, so do not name fields in here:
         - func_8001964C / func_8004BDE4 / func_8004C258 assemble a SPRT at
           0x000-0x013 (code 0x003, rgb 0x004-0x006, xy 0x008/0x00A,
           uv 0x00C/0x00D, clut 0x00E, wh 0x010/0x012) writing it field by field
           and reading it back word-wise to copy into the OT;
         - 0x014 / 0x018 / 0x01C hold unrelated 4-byte values for ~10 other
           functions -- 0x018 in particular is one byte of the staged primitive
           in func_8004C258 and a word everywhere else.
       Two stable overlays live further up and are reached by explicit cast,
       never through this struct: a CAMERA at 0x0E2 and a MATRIX at 0x0F8. */
    /* 0x000 */ u_char  unk000[0x164];
    /* 0x164 */ int     nextprim;
    /* 0x168 */ u_char  unk168[0x4C];
    /* 0x1B4 */ u_char  debug_mode_enabled;
    /* 0x1B5 */ u_char  unk1B5[0xD];
    /* 0x1C2 */ u_char  unk1C2;
    /* 0x1C3 */ u_char  unk1C3;
    /* 0x1C4 */ u_char  unk1C4;
    /* 0x1C5 */ u_char  unk1C5;
    /* 0x1C6 */ short   unk1C6;
    /* 0x1C8 */ u_short unk1C8;
    /* 0x1CA */ u_char  unk1CA[2];
    /* 0x1CC */ u_char  moviePlayState;
    /* 0x1CD */ u_char  movieId;
    /* 0x1CE */ u_char  loadComplete;
    /* 0x1CF */ u_char  unk1CF;
    /* 0x1D0 */ u_char  unk1D0;
    /* 0x1D1 */ u_char  unk1D1;
    /* 0x1D2 */ u_char  unk1D2;
    /* 0x1D3 */ u_char  movieSkipRequest;
    /* 0x1D4 */ unkstruct_1F8001D4* currentTask;
    /* 0x1D8 */ u_char  unk1D8[4];
    /* 0x1DC */ short   unk1DC;
    /* 0x1DE */ short   unk1DE;
    /* 0x1E0 */ int     ot;
    /* 0x1E4 */ void*   prevOt;
    /* 0x1E8 */ volatile u_short vblankCount;
    /* 0x1EA */ short   unk1EA;
    /* 0x1EC */ short   useDrawSync;
    /* 0x1EE */ short   pauseToggle;
    /* 0x1F0 */ short   pauseFlags;
    /* 0x1F2 */ short   unk1F2;
    /* 0x1F4 */ short   frameBufferIndex;
    /* 0x1F6 */ u_short frameCount;
    /* 0x1F8 */ short   unk1F8;
    /* 0x1FA */ u_char  unk1FA[2];
    /* 0x1FC */ u_short joypad_state;
    /* 0x1FE */ u_char  unk1FE[0xA];
    /* 0x208 */ void**  freeObjects;
    /* 0x20C */ u_char  unk20C[0x2C];
    /* 0x238 */ short   freeObjectCount;
    /* 0x23A */ u_char  unk23A[0x192];
    /* 0x3CC */ u_char  unk3CC;
    /* 0x3CD */ u_char  unk3CD[5];
    /* 0x3D2 */ u_char  unk3D2;
    /* 0x3D3 */ u_char  unk3D3;
    /* 0x3D4 */ u_char  unk3D4[0x2C];
} scratchpad;

/* Item definition entry, reached through D_8007E6E4[D_8007E61C[item_id]].
   Holds the sprite/CLUT/animation description for one item. */
/* Cabecalho de arquivo do CD, apontado pela entrada da fila em D_8009E748.
   Derivado de func_80021340, a unica leitora da FileLinkArray (D_800791A0):
   a posicao de seek sai de &D_800791A0 + fileId * 8. */
typedef struct cdFileHeader {
    /* 0x00 */ s16 fileId;      /* indexa a FileLinkArray */
    /* 0x02 */ u8  unk2;
    /* 0x03 */ u8  subType;     /* nibble alto: 0x10 ou 0x90 */
    /* 0x04 */ u8  unk4[4];
    /* 0x08 */ s16 x;           /* destino em VRAM, quando o tipo e grafico */
    /* 0x0A */ s16 y;
    /* 0x0C */ s16 w;
    /* 0x0E */ s16 h;           /* tambem indexa D_80077D50 por h * 8 */
    /* 0x10 */ u32 flags;       /* nibble baixo = tipo; bit 0x10 = qual buffer */
} cdFileHeader;

typedef struct itemDef {
    /* 0x00 */ u_char unk0;
    /* 0x01 */ u_char unk1;
    /* 0x02 */ u_char unk2;
    /* 0x03 */ u_char unk3;
    /* 0x04 */ u_char unk4;
    /* 0x05 */ u_char unk5;
    /* 0x06 */ u_char unk6;
    /* 0x07 */ u_char unk7;
    /* 0x08 */ short  x;
    /* 0x0A */ short  y;
    /* 0x0C */ u_char unkC;
    /* 0x0D */ u_char unkD;
    /* 0x0E */ u_char unkE;
    /* 0x0F */ u_char unkF;
    /* 0x10 */ int    unk10;
} itemDef;

/* Views over the object returned by the allocator family
   (allocObjectLayer3 / func_80018474 / func_80018614). They describe the same
   block through different field subsets and cannot be merged into a single
   struct: offset 0x10 is u_char in unkstruct_1F800214 and int in
   unkstruct_80018474. */
typedef struct unkstruct_1F800214 {
    u_char  unk0;
    u_char  unk1;
    u_char  unk2;
    u_char  unk3;
    u_char  unk4;
    u_char  unk5;
    u_char  unk6;
    u_char  unk7;
    u_char  unk8;
    u_char  unk9;
    u_char  unkA;
    u_char  unkB;
    u_char  unkC;
    u_char  unkD;
    u_char  unkE;
    u_char  unkF;
    u_char  unk10;
    u_char  unk11;
    u_short unk12;
    u_short unk14;
    u_short unk16;
    u_short unk18;
    u_short unk1A;
} unkstruct_1F800214;

typedef struct unkstruct_800183E4 {
    byte  data[0x1C];
    byte  unk1C;
    byte  pad0[0x23];
    void* unk40;
    void* unk44;
} unkstruct_800183E4;

typedef struct unkstruct_80018474 {
    byte  unk0;
    byte  unk1;
    byte  unk2;
    byte  unk3;
    byte  unk4;
    byte  unk5;
    byte  unk6;
    byte  pad[0x6];
    byte  unkD;
    byte  unkE;
    byte  unkF;
    int   unk10;
    int   unk14;
    int   unk18;
    byte  pad2[0x11];
    short unk2E;
} unkstruct_80018474;

typedef struct unkstruct_80033FB0 {
    byte data[3];
    u_char unk3;
} unkstruct_80033FB0;

typedef struct unkstruct_8009E458 {
    /* 0x0000 */ byte    data[0x88];
    /* 0x0088 */ u_char  state;
    /* 0x0089 */ u_char  cmpFlag;
    /* 0x008A */ u_short pc;
    /* 0x008C */ u_short sp;
    /* 0x008E */ byte    unk8E[2];
    /* 0x0090 */ int     stack[0x400];
    /* 0x1090 */ int     vars[0x40];
    /* 0x1190 */ short   unk1190;
    /* 0x1192 */ short   unk1192;
    /* 0x1194 */ short   unk1194;
} unkstruct_8009E458;


typedef struct unkstruct_800A39B0 {
    short unk0;
    short unk2;
} unkstruct_800A39B0;


typedef struct {
    u_char unk0;
    u_char unk1;
    u_char unk2;
    u_char item_id;
    u_char unk4;
    u_char unk5;
    u_char unk6;
    u_char unk7;
    short clut;
    u_char unkA;
    u_char unkB;
    u_char unkC;
    u_char unkD;
    u_char unkE;
    signed char unkF;
    short unk10;
    short unk12;
    short unk14;
    short unk16;
    short unk18;
    short unk1A;
    u_char unk1C;
    u_char unk1D;
    short unk1E;
    short unk20;
    u_short unk22;
    int unk24;
    short unk28;
    short unk2A;
    short unk2C;
    short unk2E;
    u_char pad4[0xC];
    int unk3C;
    u_char pad5[0x24];
    int buffSize;
    u_char unk68;
    u_char unk69;
    u_char unk6A;
    u_char unk6B;
    short unk6C;
    short unk6E;
    short unk70;
    short unk72;
    u_char pad6[0x8];
    short unk7A;
    u_char pad7[0x3];
    short unk82;
    u_char pad8[0x8];
    int unk8C;
    u_char pad9[0x15];
    u_char unkA5;
} unkstruct_800A6D50;

typedef struct unkstruct_800AFF18 {
    short unk0;
    short unk2;
    char val[6];
} unkstruct_800AFF18;


struct inventory {
    u_char slots[256];
    u_short counter;
    u_short sortMode;
};

typedef struct equips {
    byte weapon;
    byte pants;
} equips;

typedef struct gameConfig {
    u_short selectedArea;
    u_short selectedSection;
    byte selectedPlane;
    byte area00_fogControl;
    byte unk6;
    u_char unk7;
    int totalTimePlayed;
    u_long playerAP;
    u_char playerHealth;
    u_char playerHealthDisplayed;
    char unk12;
    char unk13;
    u_char unk14;
    u_char fadeScreenControl;
    byte fadeScreenAmount;
    u_char saveSlot;
    byte unk18;
    byte unk19;
    byte unk1a;
    byte unk1b;
    byte unk1c;
    byte unk1d;
    byte unk1e;
    byte unk1f;
    u_char playerLives;
    byte unk21;
    u_short selectedSpawnPoint;
    int area00_eventControl;
    byte unk28;
    byte unk29;
    byte unk2a;
    byte unk2b;
    byte unk2c;
    byte unk2d;
    byte unk2e;
    byte unk2f;
    byte displayExpBar;
    byte unk31;
    byte unk32;
    byte unk33;
    byte area00_pickedItems[32];
    byte area01_pickedItems[32];
    byte area02_pickedItems[32];
    byte area03_pickedItems[32];
    byte area04_pickedItems[32];
    byte area05_pickedItems[32];
    byte area06_pickedItems[32];
    byte area07_pickedItems[32];
    byte area08_pickedItems[32];
    byte area09_pickedItems[32];
    byte area10_pickedItems[32];
    byte area11_pickedItems[32];
    byte area12_pickedItems[32];
    byte area13_pickedItems[32];
    byte area14_pickedItems[32];
    byte area15_pickedItems[32];
    byte area16_pickedItems[32];
    byte area17_pickedItems[32];
    byte area18_pickedItems[32];
    byte area19_pickedItems[32];
    byte unk2b4;
    byte unk2b5;
    byte unk2b6;
    byte unk2b7;
    byte unk2b8;
    byte unk2b9;
    byte unk2ba;
    byte unk2bb;
    byte unk2bc;
    byte unk2bd;
    byte unk2be;
    byte unk2bf;
    byte unk2c0;
    byte unk2c1;
    byte unk2c2;
    byte unk2c3;
    byte unk2c4;
    byte unk2c5;
    byte unk2c6;
    byte unk2c7;
    byte unk2c8;
    byte unk2c9;
    byte unk2ca;
    byte unk2cb;
    byte unk2cc;
    byte unk2cd;
    byte unk2ce;
    byte unk2cf;
    byte unk2d0;
    byte unk2d1;
    byte unk2d2;
    byte unk2d3;
    byte unk2d4;
    byte unk2d5;
    byte unk2d6;
    byte unk2d7;
    byte unk2d8;
    byte unk2d9;
    byte unk2da;
    byte unk2db;
    byte unk2dc;
    byte unk2dd;
    byte unk2de;
    byte unk2df;
    byte unk2e0;
    byte unk2e1;
    byte unk2e2;
    byte unk2e3;
    byte unk2e4;
    byte unk2e5;
    byte unk2e6;
    byte unk2e7;
    byte unk2e8;
    byte unk2e9;
    byte unk2ea;
    byte unk2eb;
    byte unk2ec;
    byte unk2ed;
    byte unk2ee;
    byte unk2ef;
    byte unk2f0;
    byte unk2f1;
    byte unk2f2;
    byte unk2f3;
    byte unk2f4;
    byte unk2f5;
    byte unk2f6;
    byte unk2f7;
    byte unk2f8;
    byte unk2f9;
    byte unk2fa;
    byte unk2fb;
    byte unk2fc;
    byte unk2fd;
    byte unk2fe;
    byte unk2ff;
    byte unk300;
    byte unk301;
    byte unk302;
    byte unk303;
    byte unk304;
    byte unk305;
    byte unk306;
    byte unk307;
    byte unk308;
    byte unk309;
    byte unk30a;
    byte unk30b;
    byte unk30c;
    byte unk30d;
    byte unk30e;
    byte unk30f;
    byte unk310;
    byte unk311;
    byte unk312;
    byte unk313;
    byte unk314;
    byte unk315;
    byte unk316;
    byte unk317;
    byte unk318;
    byte unk319;
    byte unk31a;
    byte unk31b;
    byte unk31c;
    byte unk31d;
    byte unk31e;
    byte unk31f;
    byte unk320;
    byte unk321;
    byte unk322;
    byte unk323;
    byte unk324;
    byte unk325;
    byte unk326;
    byte unk327;
    byte unk328;
    byte unk329;
    byte unk32a;
    byte unk32b;
    byte unk32c;
    byte unk32d;
    byte unk32e;
    byte unk32f;
    byte unk330;
    byte unk331;
    byte unk332;
    byte unk333;
    byte unk334;
    byte unk335;
    byte unk336;
    byte unk337;
    byte unk338;
    byte unk339;
    byte unk33a;
    byte unk33b;
    byte unk33c;
    byte unk33d;
    byte unk33e;
    byte unk33f;
    byte unk340;
    byte unk341;
    byte unk342;
    byte unk343;
    byte unk344;
    byte unk345;
    byte unk346;
    byte unk347;
    byte unk348;
    byte unk349;
    byte unk34a;
    byte unk34b;
    byte unk34c;
    byte unk34d;
    byte unk34e;
    byte unk34f;
    byte unk350;
    byte unk351;
    byte unk352;
    byte unk353;
    byte unk354;
    byte unk355;
    byte unk356;
    byte unk357;
    byte unk358;
    byte unk359;
    byte unk35a;
    byte unk35b;
    byte unk35c;
    byte unk35d;
    byte unk35e;
    byte unk35f;
    byte unk360;
    byte unk361;
    byte unk362;
    byte unk363;
    byte unk364;
    byte unk365;
    byte unk366;
    byte unk367;
    byte unk368;
    byte unk369;
    byte unk36a;
    byte unk36b;
    byte unk36c;
    byte unk36d;
    byte unk36e;
    byte unk36f;
    byte unk370;
    byte unk371;
    byte unk372;
    byte unk373;
    byte unk374;
    byte unk375;
    byte unk376;
    byte unk377;
    byte unk378;
    byte unk379;
    byte unk37a;
    byte unk37b;
    byte unk37c;
    byte unk37d;
    byte unk37e;
    byte unk37f;
    byte unk380;
    byte unk381;
    byte unk382;
    byte unk383;
    byte unk384;
    byte unk385;
    byte unk386;
    byte unk387;
    byte unk388;
    byte unk389;
    byte unk38a;
    byte unk38b;
    byte unk38c;
    byte unk38d;
    byte unk38e;
    byte unk38f;
    byte unk390;
    byte unk391;
    byte unk392;
    byte unk393;
    byte unk394;
    byte unk395;
    byte unk396;
    byte unk397;
    byte unk398;
    byte unk399;
    byte unk39a;
    byte unk39b;
    byte unk39c;
    byte unk39d;
    byte unk39e;
    byte unk39f;
    byte unk3a0;
    byte unk3a1;
    byte unk3a2;
    byte unk3a3;
    byte unk3a4;
    byte unk3a5;
    byte unk3a6;
    byte unk3a7;
    byte unk3a8;
    byte unk3a9;
    byte unk3aa;
    byte unk3ab;
    byte unk3ac;
    byte unk3ad;
    byte unk3ae;
    byte unk3af;
    byte unk3b0;
    byte unk3b1;
    byte unk3b2;
    byte unk3b3;
    byte unk3b4;
    byte unk3b5;
    byte unk3b6;
    byte unk3b7;
    byte unk3b8;
    byte unk3b9;
    byte unk3ba;
    byte unk3bb;
    byte unk3bc;
    byte unk3bd;
    byte unk3be;
    byte unk3bf;
    byte unk3c0;
    byte unk3c1;
    byte unk3c2;
    byte unk3c3;
    byte unk3c4;
    byte unk3c5;
    byte unk3c6;
    byte unk3c7;
    byte unk3c8;
    byte unk3c9;
    byte unk3ca;
    byte unk3cb;
    byte unk3cc;
    byte unk3cd;
    byte unk3ce;
    byte unk3cf;
    byte unk3d0;
    byte unk3d1;
    byte unk3d2;
    byte unk3d3;
    byte unk3d4;
    byte unk3d5;
    byte unk3d6;
    byte unk3d7;
    byte unk3d8;
    byte unk3d9;
    byte unk3da;
    byte unk3db;
    byte unk3dc;
    byte unk3dd;
    byte unk3de;
    byte unk3df;
    byte unk3e0;
    byte unk3e1;
    byte unk3e2;
    byte unk3e3;
    byte unk3e4;
    byte unk3e5;
    byte unk3e6;
    byte unk3e7;
    byte unk3e8;
    byte unk3e9;
    byte unk3ea;
    byte unk3eb;
    byte unk3ec;
    byte unk3ed;
    byte unk3ee;
    byte unk3ef;
    byte unk3f0;
    byte unk3f1;
    byte unk3f2;
    byte unk3f3;
    byte unk3f4;
    byte unk3f5;
    byte unk3f6;
    byte unk3f7;
    byte unk3f8;
    byte unk3f9;
    byte unk3fa;
    byte unk3fb;
    byte unk3fc;
    byte unk3fd;
    byte unk3fe;
    byte unk3ff;
    byte unk400;
    byte unk401;
    byte unk402;
    byte unk403;
    byte unk404;
    byte unk405;
    byte unk406;
    byte unk407;
    byte unk408;
    byte unk409;
    byte unk40a;
    byte unk40b;
    byte unk40c;
    byte unk40d;
    byte unk40e;
    byte unk40f;
    byte unk410;
    byte unk411;
    byte unk412;
    byte unk413;
    byte unk414;
    byte unk415;
    byte unk416;
    byte unk417;
    byte unk418;
    byte unk419;
    byte unk41a;
    byte unk41b;
    byte unk41c;
    byte unk41d;
    byte unk41e;
    byte unk41f;
    byte unk420;
    byte unk421;
    byte unk422;
    byte unk423;
    byte unk424;
    byte unk425;
    byte unk426;
    byte unk427;
    byte unk428;
    byte unk429;
    byte unk42a;
    byte unk42b;
    byte unk42c;
    byte unk42d;
    byte unk42e;
    byte unk42f;
    byte unk430;
    byte unk431;
    byte unk432;
    byte unk433;
    u_short nextArea;
    u_short nextSection;
    u_char redExpLevel;
    u_char greenExpLevel;
    u_char blueExpLevel;
    u_char redExpBar;
    u_char greenExpBar;
    u_char blueExpBar;
    byte unk43e;
    byte unk43f;
    u_short nextSpawnPoint;
    u_char disableSelectMenu;
    u_char inventoryScreen;
    u_char event[256];
    byte unk544;
    byte unk545;
    byte unk546;
    byte unk547;
    byte unk548;
    byte unk549;
    byte unk54a;
    byte baronState;
    byte unk54c;
    byte unk54d;
    byte unk54e;
    char unk54f;
    byte unk550;
    byte unk551;
    byte unk552;
    byte unk553;
    byte unk554;
    byte unk555;
    byte unk556;
    byte unk557;
    byte unk558;
    byte unk559;
    byte unk55a;
    byte unk55b;
    byte unk55c;
    byte unk55d;
    byte unk55e;
    byte unk55f;
    byte unk560;
    byte unk561;
    byte unk562;
    byte unk563;
    byte unk564;
    byte unk565;
    byte unk566;
    byte unk567;
    byte unk568;
    byte unk569;
    byte unk56a;
    byte unk56b;
    byte unk56c;
    byte unk56d;
    byte unk56e;
    byte unk56f;
    byte unk570;
    byte unk571;
    byte unk572;
    byte unk573;
    byte unk574;
    byte unk575;
    byte unk576;
    byte unk577;
    byte unk578;
    byte unk579;
    byte unk57a;
    byte unk57b;
    byte unk57c;
    byte unk57d;
    byte unk57e;
    byte unk57f;
    byte unk580;
    byte unk581;
    byte unk582;
    byte unk583;
    byte unk584;
    byte unk585;
    byte unk586;
    byte unk587;
    byte unk588;
    byte unk589;
    byte unk58a;
    byte unk58b;
    byte unk58c;
    byte unk58d;
    byte unk58e;
    byte unk58f;
    byte unk590;
    byte unk591;
    byte unk592;
    byte unk593;
    byte unk594;
    byte unk595;
    byte unk596;
    byte unk597;
    byte unk598;
    byte unk599;
    byte unk59a;
    byte unk59b;
    byte unk59c;
    byte unk59d;
    byte unk59e;
    byte unk59f;
    byte unk5a0;
    byte pipeState;
    byte unk5a2;
    byte unk5a3;
    byte unk5a4;
    byte unk5a5;
    byte unk5a6;
    byte unk5a7;
    byte unk5a8;
    byte unk5a9;
    byte unk5aa;
    byte unk5ab;
    byte unk5ac;
    byte unk5ad;
    byte unk5ae;
    byte unk5af;
    byte unk5b0;
    byte unk5b1;
    byte unk5b2;
    byte unk5b3;
    byte unk5b4;
    byte unk5b5;
    byte unk5b6;
    byte unk5b7;
    byte unk5b8;
    byte unk5b9;
    byte unk5ba;
    byte unk5bb;
    byte unk5bc;
    byte unk5bd;
    byte unk5be;
    byte unk5bf;
    byte unk5c0;
    byte unk5c1;
    byte unk5c2;
    byte unk5c3;
    byte unk5c4;
    byte unk5c5;
    byte unk5c6;
    byte unk5c7;
    byte unk5c8;
    byte unk5c9;
    byte unk5ca;
    byte unk5cb;
    byte unk5cc;
    byte unk5cd;
    byte unk5ce;
    byte unk5cf;
    byte unk5d0;
    byte unk5d1;
    byte unk5d2;
    byte unk5d3;
    byte unk5d4;
    byte unk5d5;
    byte unk5d6;
    byte unk5d7;
    byte unk5d8;
    byte unk5d9;
    byte unk5da;
    byte unk5db;
    byte unk5dc;
    byte unk5dd;
    byte unk5de;
    byte unk5df;
    byte unk5e0;
    byte unk5e1;
    byte unk5e2;
    byte unk5e3;
    byte unk5e4;
    byte unk5e5;
    byte unk5e6;
    byte unk5e7;
    byte unk5e8;
    byte unk5e9;
    byte unk5ea;
    byte unk5eb;
    byte unk5ec;
    byte unk5ed;
    byte unk5ee;
    byte unk5ef;
    byte unk5f0;
    byte unk5f1;
    byte unk5f2;
    byte unk5f3;
    byte unk5f4;
    byte unk5f5;
    byte unk5f6;
    byte unk5f7;
    byte unk5f8;
    byte unk5f9;
    byte unk5fa;
    byte unk5fb;
    byte unk5fc;
    byte unk5fd;
    byte unk5fe;
    byte unk5ff;
    byte unk600;
    byte unk601;
    byte unk602;
    byte unk603;
    byte unk604;
    byte unk605;
    byte unk606;
    byte unk607;
    byte unk608;
    byte unk609;
    byte unk60a;
    byte unk60b;
    byte unk60c;
    byte unk60d;
    byte unk60e;
    byte unk60f;
    byte unk610;
    byte unk611;
    byte unk612;
    byte unk613;
    byte unk614;
    byte unk615;
    byte unk616;
    byte unk617;
    byte unk618;
    byte unk619;
    byte unk61a;
    byte unk61b;
    byte unk61c;
    byte unk61d;
    byte unk61e;
    byte unk61f;
    byte unk620;
    byte unk621;
    byte unk622;
    byte unk623;
    byte unk624;
    byte unk625;
    byte unk626;
    byte unk627;
    byte unk628;
    byte unk629;
    byte unk62a;
    byte unk62b;
    byte unk62c;
    byte unk62d;
    byte unk62e;
    byte unk62f;
    byte unk630;
    byte unk631;
    byte unk632;
    byte unk633;
    byte unk634;
    byte unk635;
    byte unk636;
    byte unk637;
    byte unk638;
    byte unk639;
    byte unk63a;
    byte unk63b;
    byte unk63c;
    byte unk63d;
    byte unk63e;
    byte unk63f;
    byte unk640;
    byte unk641;
    byte unk642;
    byte unk643;
    byte unk644;
    byte unk645;
    byte unk646;
    byte unk647;
    byte unk648;
    byte unk649;
    byte unk64a;
    byte unk64b;
    byte unk64c;
    byte unk64d;
    byte unk64e;
    byte unk64f;
    byte unk650;
    byte unk651;
    byte unk652;
    byte unk653;
    byte unk654;
    byte unk655;
    byte unk656;
    byte unk657;
    byte unk658;
    byte unk659;
    byte unk65a;
    byte unk65b;
    byte unk65c;
    byte unk65d;
    byte unk65e;
    byte unk65f;
    byte unk660;
    byte unk661;
    byte unk662;
    byte unk663;
    byte unk664;
    byte unk665;
    byte unk666;
    byte unk667;
    byte unk668;
    byte unk669;
    byte unk66a;
    byte unk66b;
    byte unk66c;
    byte unk66d;
    byte unk66e;
    byte unk66f;
    short unk670;
    short unk672;
    short unk674;
    byte unk676;
    byte unk677;
    byte unk678;
    byte unk679;
    byte unk67a;
    byte unk67b;
    byte unk67c;
    byte unk67d;
    byte unk67e;
    byte unk67f;
    byte unk680;
    byte unk681;
    byte unk682;
    byte unk683;
    byte goldenFlowerState;
    byte unk685;
    byte unk686;
    byte unk687;
    byte unk688;
    byte unk689;
    byte unk68a;
    byte unk68b;
    byte unk68c;
    byte unk68d;
    byte unk68e;
    byte unk68f;
    byte unk690;
    byte unk691;
    byte unk692;
    byte unk693;
    byte unk694;
    byte unk695;
    byte unk696;
    byte unk697;
    byte unk698;
    byte unk699;
    byte unk69a;
    byte unk69b;
    byte unk69c;
    byte unk69d;
    byte unk69e;
    byte unk69f;
    byte unk6a0;
    byte unk6a1;
    byte unk6a2;
    byte unk6a3;
    byte unk6a4;
    byte unk6a5;
    byte unk6a6;
    byte unk6a7;
    byte unk6a8;
    byte unk6a9;
    byte unk6aa;
    byte unk6ab;
    byte unk6ac;
    byte unk6ad;
    byte unk6ae;
    byte playerIdleState;
    byte unk6b0;
    byte unk6b1;
    byte unk6b2;
    byte unk6b3;
    byte unk6b4;
    byte unk6b5;
    byte unk6b6;
    byte unk6b7;
    byte unk6b8;
    byte unk6b9;
    byte unk6ba;
    byte unk6bb;
    byte unk6bc;
    byte unk6bd;
    byte unk6be;
    byte unk6bf;
    byte unk6c0;
    byte unk6c1;
    byte unk6c2;
    byte unk6c3;
    byte unk6c4;
    byte unk6c5;
    byte unk6c6;
    byte unk6c7;
    byte unk6c8;
    byte unk6c9;
    byte unk6ca;
    byte unk6cb;
    byte unk6cc;
    byte unk6cd;
    byte unk6ce;
    byte unk6cf;
    byte unk6d0;
    byte unk6d1;
    byte unk6d2;
    byte unk6d3;
    byte unk6d4;
    byte unk6d5;
    byte unk6d6;
    byte unk6d7;
    byte unk6d8;
    byte unk6d9;
    byte unk6da;
    byte unk6db;
    byte unk6dc;
    byte unk6dd;
    byte unk6de;
    byte unk6df;
    byte unk6e0;
    byte unk6e1;
    byte unk6e2;
    byte unk6e3;
    byte unk6e4;
    byte unk6e5;
    byte unk6e6;
    byte unk6e7;
    byte unk6e8;
    byte unk6e9;
    byte unk6ea;
    byte unk6eb;
    byte unk6ec;
    byte unk6ed;
    byte unk6ee;
    byte unk6ef;
    byte unk6f0;
    byte unk6f1;
    byte unk6f2;
    byte unk6f3;
    byte unk6f4;
    byte unk6f5;
    byte unk6f6;
    byte unk6f7;
    byte unk6f8;
    byte unk6f9;
    byte unk6fa;
    byte unk6fb;
    byte unk6fc;
    byte unk6fd;
    byte unk6fe;
    byte unk6ff;
    byte unk700;
    byte unk701;
    byte unk702;
    byte unk703;
    byte unk704;
    byte unk705;
    byte unk706;
    byte unk707;
    byte unk708;
    byte unk709;
    byte unk70a;
    byte unk70b;
    byte unk70c;
    byte unk70d;
    byte unk70e;
    byte unk70f;
    byte unk710;
    byte unk711;
    byte unk712;
    byte unk713;
    byte unk714;
    byte unk715;
    byte unk716;
    byte unk717;
    byte unk718;
    byte unk719;
    byte unk71a;
    byte bittingPlantFlowerState;
    byte unk71c;
    byte unk71d;
    byte unk71e;
    u_char goldenBowlState;
    u_char unk720;
    byte unk721;
    byte unk722;
    byte unk723;
    byte unk724;
    byte unk725;
    byte unk726;
    byte unk727;
    byte unk728;
    byte unk729;
    byte unk72a;
    byte unk72b;
    byte unk72c;
    byte unk72d;
    byte unk72e;
    u_char unk72f;
    u_char unk730;
    u_char unk731;
    byte unk732;
    byte unk733;
    byte unk734;
    byte unk735;
    char unk736;
    byte unk737;
    byte unk738;
    byte unk739;
    byte unk73a;
    byte unk73b;
    byte unk73c;
    byte unk73d;
    byte unk73e;
    byte unk73f;
    byte unk740;
    byte unk741;
    byte unk742;
    byte unk743;
    u_char item[256];
    struct inventory inventory;
    u_short currentArea;
    u_short currentSection;
    u_short currentSpawnPoint;
    u_char inventoryButton;
    u_char playerState;
    struct equips playerEquips;
    byte unk952;
    byte unk953;
    byte unk954;
    byte unk955;
    byte unk956;
    byte unk957;
    byte unk958;
    byte unk959;
    byte unk95a;
    byte unk95b;
    byte unk95c;
    byte unk95d;
    byte unk95e;
    byte unk95f;
    byte unk960;
    byte unk961;
    byte unk962;
    u_char purifiedAreas;
    byte unk964;
    byte unk965;
    byte unk966;
    byte unk967;
    byte unk968;
    byte unk969;
    byte unk96a;
    byte unk96b;
    byte unk96c;
    byte unk96d;
    byte unk96e;
    byte unk96f;
    byte unk970;
    byte unk971;
    byte unk972;
    byte unk973;
    byte unk974;
    byte unk975;
    byte unk976;
    byte unk977;
    byte unk978;
    byte unk979;
    byte unk97a;
    byte unk97b;
    byte unk97c;
    byte unk97d;
    byte unk97e;
    byte unk97f;
    byte unk980;
    byte unk981;
    byte unk982;
    byte unk983;
    byte unk984;
} gameConfig;

typedef struct CAMERA {
    short vrx, pad1, vry, pad2, vrz, pad3;
    short vpx, pad4, vpy, pad5, vpz;
    MATRIX matrix;
} CAMERA;

typedef struct
{
    u8 first, second;
} U8Pair;

/* ========================================================================
 * Extern data -- sorted by address
 */

/* --- PSX scratchpad (0x1F800000) -- see `struct scratchpad` --- */
extern u_char SCRATCHPAD;
extern u_char D_1F8000C0[];
extern u_char D_1F8000F8[];
extern u_char D_1F800118[];
extern u_char D_1F8001A0[0x24];
extern int D_1F8002C8[];
extern u16  D_1F8001C8;
extern s32* D_1F800204;
extern u16  D_1F800236;
extern s32* D_1F800208;
extern u16  D_1F800238;
extern s32* D_1F80020C;
extern u16  D_1F80023A;
extern s32* D_1F800210;
extern u16  D_1F80023E;
extern s32* D_1F800214;
extern u16  D_1F80023C;
extern s16  D_1F80016A;
extern s32  D_1F80029C;
extern s32  D_1F800200;
extern s32  D_1F800298;
extern s32  D_1F8002AC;
extern u16  D_1F800176;
extern u16  D_1F800186;
extern s32* D_1F800220;
extern s16  D_1F80024A;
extern u8*  D_1F800354;
extern s32* D_1F800218;
extern s32* D_1F80021C;
extern s32* D_1F800224;
extern s32* D_1F800228;
extern s32* D_1F80022C;
extern s32* D_1F800230;
extern u16  D_1F800240;
extern u16  D_1F800242;
extern u16  D_1F800244;
extern u16  D_1F800246;
extern u16  D_1F800248;
extern u16  D_1F80024C;
extern s16  D_1F8003A8[];
extern short D_1F8003B6;

/* --- RAM / ROM data 0x8001____ --- */
extern char D_80010000;
extern char D_80010008;
extern int D_800121C8;

/* --- RAM / ROM data 0x8007____ --- */
extern u_short D_80076E80[];
extern int D_80076FAC[];
extern int D_800771FC;
extern int D_8007722C;
extern int AP_TABLE[];
extern u_char EVENT_STARTED_AP_TABLE[];
extern u_char EVENT_COMPLETE_AP_TABLE[];
extern int D_80077754;
extern int D_80077758;
extern u_char D_8007775C[];
extern int  D_80077D50[];
extern u_char D_80077FA8;
extern short D_80078F80[];
extern int D_8007912C[];
extern s16  D_8007D788[];
extern s16  D_8007D988[];
extern s16  D_8007DB88[];
extern fileLink D_800791A0[]; // FileLinkArray
extern int  D_800791A4[];
extern u_short D_8007B290;
extern int D_8007B294;
extern int D_8007B2F4[];
extern int D_8007B2F6[];
extern int D_8007B2F8[];
extern int D_8007B2FA[];
extern int D_8007B2FC[];
extern int D_8007B2FE[];
extern u_long D_8007C290[];
extern U8Pair D_8007C2B8[];
extern int D_8007D6A0;
extern u_char D_8007D6D0;
extern u_char D_8007E61C[];
extern int D_8007E6E4[];
extern int D_8007E868;
extern int D_8007E86C;
extern int D_8007E86E;

/* --- RAM / ROM data 0x8009____ --- */
extern DISPENV D_8009AFE8;
extern u_char D_8009B000;
extern u_char D_8009B004;
extern u_char D_8009B008;
extern int D_8009B010;
extern int D_8009B018;
extern int D_8009B024;
extern int D_8009B028;
extern int D_8009B02A;
extern int D_8009B02C;
extern int D_8009B03C;
extern SpuCommonAttr D_8009B048; // SPU_ATTR
extern short D_8009B078;
extern short D_8009B07C;
extern short D_8009B094;
extern u_char LZ_CURRENT_BIT;
extern u_short LZ_BITMASK;
extern byte D_8009B6A8; // SELECTED ROW
extern short D_8009BC28[];
extern u_char D_8009BC98[0x2C];
extern u_char D_8009BCA0;
extern char D_8009BCA7;
extern char D_8009BCAA;
extern gameConfig GAME;
extern char D_8009BCDA;
extern char D_8009BCDB;
extern u_char D_8009BCDF;
extern short D_8009BCEA;
extern u_char D_8009C3F8;
extern int  D_8009C658[];
extern int  D_8009C65C[];
extern int  D_8009C758[];
extern u_short D_8009C864;
extern u_short D_8009C866;
extern void* D_8009C8A8;
extern int  D_8009C8B0;
extern short D_8009C940;
extern volatile u_short D_8009C9D8;
extern short D_8009C9DA;
extern volatile u_short D_8009C9DC;
extern short D_8009C9DE;
extern char D_8009C9E4;
extern short D_8009C9F0;
extern int D_8009CA04;
extern u_long OT_FRAMEBUFFER;
extern DRAWENV* D_8009D6C4;
extern char D_8009D6DD;
extern char D_8009D6DE;
extern char D_8009D6DF;
extern char D_8009E3ED;
extern char D_8009E3EE;
extern char D_8009E3EF;
extern short D_8009E430;
extern char D_8009E450;
extern void (*D_8007C68C[])(u8* self);
extern void (*D_8007D6A4[])(u8* self);
extern void (*D_8007F6F4[])(u8* self);
extern void (*D_8007D57C[])(u8* self);
extern void (*D_8007F988[])(void);
extern void (*D_8007C848[])(void);
extern u8*  D_8007B680[];
extern u16  D_8009BCCA;
extern s16  D_8009B074;
extern u8   D_80014C94;
extern u8   D_80014C8C;
extern u8*  D_8009C974;
extern int  D_8009E74C[];
extern u8   D_800778E4[];
extern u8   D_800778E5[];
extern s32  D_80077AEC[];
extern s32  D_80078EB0[];
extern u8   D_8009C61A;
extern u8*  D_8007EB44;
extern u8   D_8009BCDD;
extern u8   D_8009BCA4;
extern u8   D_8009BCDE;
extern s16  D_800A2818;
extern s16  D_8009C9F8;
extern u8*  D_8007C110[];
extern u8*  D_80077084[];
extern u8   D_800B07CC[];
extern s32  D_800A38DC;
extern unkstruct_8009E458* D_8009E458;
extern u8*  D_8009E640[];
extern s16* D_800A53D8;
extern s16* D_800A53DC;
extern s16  D_800A53AE;
extern u8   D_8009C10C[];
extern u8   D_8009C20C[];
extern u8   D_800A5401;
extern u8   D_800A5436;
extern u8   D_8009C619;
extern u8   D_800A547A;
extern s32  D_8009BCD4;
extern long MEMCARD_HW_END_IO;
extern long MEMCARD_HW_END_ERROR;
extern long MEMCARD_HW_TIMEOUT;
extern long MEMCARD_HW_NEW_DEVICE;
extern long MEMCARD_SW_END_IO;
extern long MEMCARD_SW_END_ERROR;
extern long MEMCARD_SW_TIMEOUT;
extern long MEMCARD_SW_NEW_DEVICE;
extern short D_8009E638;
extern u_short D_8009E744;
extern int  D_8009E748[];
extern int D_8009EB4C;
extern short D_8009EB52;
extern u_short D_8009EB5A;
extern u_short D_8009EB7C;
extern short D_8009EBA0;
extern int D_8009EBA8;

/* --- RAM / ROM data 0x800A____ --- */
extern char* SPRINTF_BUFFER_MSG[];
extern char D_800A15D8; // SPU_SEQ_TABLE
extern char D_800A1890;
extern short D_800A2790;
extern short D_800A3030[];
extern short D_800A32F8;
extern byte D_800A3348[0x3D4];
extern u_char D_800A38B8[];
extern u_char D_800A3940[0x70];
extern u_char D_800A3941;
extern u8*  D_1F8001D4;
extern s16  D_1F8003B8;
extern s16  D_1F8003BA;
extern s32  D_8009BCBC;
extern u8   D_8009E438[];
extern s8   D_8009C618;
extern u8   D_800A5403;
extern s16  D_1F8000E6;
extern s16  D_1F8003C4;
extern s16  D_1F8003C6;
extern s16  D_1F8003C8;
extern s16  D_1F8003CA;
extern u16  D_8007B2C4[];
extern u16  D_8007B2C6[];
extern u16  D_8007B2C8[];
extern u16  D_8007B2CA[];
extern char D_800C3188;
extern char D_800D3188;
extern char D_800D5188;
extern u8   D_800A5400;
extern s16  D_8009C97A;
extern u8   D_8009C97C;
extern u8   D_8009C97D;
extern u8   D_8009C97E;
extern u8   D_8009C97F;
extern u8   D_8009C982;
extern u8   D_8009C983;
extern u8   D_8009EB58;
extern s16  D_1F8000F2;
extern s32  D_80012368[];
extern void* D_1F8002D8;
extern s32  D_1F800278;
extern u16  D_800A544A;
extern u16  D_800A53B8;
extern s32  D_8009BCFC;
extern s32  D_1F800198;
extern u8   D_800B0B88;
extern u8   D_800A5438;
extern u8   D_800A55C8;
extern u8   D_800B0518;
extern u8   D_800A3D08;
extern u8   D_800B07D8;
extern s32* D_1F80025C;
extern u16  D_1F80024E;
extern u8   D_800A55C4;
extern u8   D_800A37D0;
extern s32* D_1F800274;
extern u16  D_1F800258;
extern s32* D_1F800270;
extern u16  D_1F80025A;
extern short D_800A3952;
extern short D_800A3954;
extern short D_800A3956;
extern unkstruct_800A39B0 D_800A39B0[];
extern unkstruct_800AFF18 D_800A5140[];
extern u_char D_800A5398[0x178];
extern char D_800A539C;
extern char D_800A539D;
extern char D_800A539E;
extern char D_800A539F;
extern u_short D_800A53C6;
extern u_short D_800A5430;
extern u_short D_800A5432;
extern int D_800A5858;
extern int D_800A5970;
extern unkstruct_800AFF18 D_800AFF18[];

/* --- RAM / ROM data 0x800B____ --- */
extern u_char D_800B00F8[0x16C];
extern int D_800B0470;
extern int D_800B04F0;
extern int D_800B0528;
extern int D_800B0680;
extern u_char D_800B0770[0x68];
extern u_char* D_800B078C;
extern char D_800B07AC[8];
extern char D_800B07CD;
extern int D_800B3184;
extern char D_800B3188;

/* --- RAM / ROM data 0x800D____ --- */
extern int D_800D7188;

/* --- Task table (0x801FD800) --- */
extern unkstruct_1F8001D4* D_801FD800;
extern int D_801FD804;
extern int D_801FD808;
extern int D_801FD80C;
extern int D_801FD810;

/* ========================================================================
 * Declarations kept for reference (not in use)
 */

// extern char* D_80010120[];
// extern char* D_80010134[];
// extern char* D_8001014C[];

/* ========================================================================
 * Function prototypes
 */

void openTask(s32 arg0, long (*func)());
void fontDebugPrintf(short x, short y, short color, char* fmt);
void vblankHandler(void);
void bootSequenceTask(void);
void titleSequenceTask(void);
void func_8001A51C(void);
void moviePlayerTask(void);
void mdecSliceCallback(void);
void lzDecompress(byte* src, byte* dest);
void loadTIM(u_long* address, short x, short y, short x2, short y2);
u_char awardEventProgress(EVENT event_id, int ap_table, int state);
void func_80125FE8(void);
void func_8011F67C(void);
void func_80126048(void);
void func_8011F6DC(void);
s32 func_80020058(s32 arg0, s32 arg1);
void func_80034C14(u8* self);
void func_8005B1F8(u8* self);
void func_80036F98(u8* self);
void func_80122688(void);
void func_8011D498(void);
void func_8012298C(void);
void func_8011D79C(void);
void func_8003C124(u8 op);
void func_8003E408(u8 op);
s16 func_80051284();
void func_80076364(SpuReverbAttr* attr);
u16 func_80022570(void);
void func_800EBD5C(u8* arg0, s16 arg1, s16 arg2);
void func_8006A9EC(u8* a, u8* b);
s16 func_80036618(u8* self);
void func_80122F64(void);
void func_8011D844(void);
void func_8011CD70(void);
void func_8011602C(void);
void func_80022E44(u8* self);
s32 func_80042654(s16 a, s16 b);
s16 func_8004339C(u8* self, s16 a, s16 b);
s16 func_800443CC(u8* self, s16 a, s16 b);
void func_801248A0(void);
void func_8011E3E4(void);
void func_8011FC7C(void);
void func_80124B38(void);
void func_801233E0(void);
void func_8011EC1C(void);
void func_8011E254(void);
void func_80123D24(void);
void func_8011EF08(void);
void func_8011E170(void);
void func_8011F650(void);
void func_8012C03C(void);
void func_8012E2FC(void);
void func_80123EC8(void);
void func_80122A00(void);
s32 func_8001FF28(void);
s32 func_80020EEC(s32 a, s32 b);
void func_80021340(void);
// void func_80022618(unkstruct_800A6D50* arg0, u16 arg1);

#endif // GAME_H
