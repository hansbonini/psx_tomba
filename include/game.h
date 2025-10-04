#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H

/* don't change these macros and structures which is refereced in kernel code */

#define DescMask 0xff000000
#define DescTH DescMask
#define DescHW 0xf0000000
#define DescEV 0xf1000000
#define DescRC 0xf2000000
#define DescUEV 0xf3000000 /* User event */
#define DescSW 0xf4000000  /* BIOS */

#define HwVBLANK (DescHW | 0x01) /* VBLANK */
#define HwGPU (DescHW | 0x02)    /* GPU */
#define HwCdRom (DescHW | 0x03)  /* CDROM Decorder */
#define HwDMAC (DescHW | 0x04)   /* DMA controller */
#define HwRTC0 (DescHW | 0x05)   /* RTC0 */
#define HwRTC1 (DescHW | 0x06)   /* RTC1 */
#define HwRTC2 (DescHW | 0x07)   /* RTC2 */
#define HwCNTL (DescHW | 0x08)   /* Controller */
#define HwSPU (DescHW | 0x09)    /* SPU */
#define HwPIO (DescHW | 0x0a)    /* PIO */
#define HwSIO (DescHW | 0x0b)    /* SIO */

#define HwCPU (DescHW | 0x10)    /* Exception */
#define HwCARD (DescHW | 0x11)   /* memory card */
#define HwCARD_0 (DescHW | 0x12) /* memory card */
#define HwCARD_1 (DescHW | 0x13) /* memory card */
#define SwCARD (DescSW | 0x01)   /* memory card */
#define SwMATH (DescSW | 0x02)   /* libmath */

#define RCntCNT0 (DescRC | 0x00) /* �\���s�N�Z�� */
#define RCntCNT1 (DescRC | 0x01) /* �������� */
#define RCntCNT2 (DescRC | 0x02) /* �V�X�e���N���b�N�W���� */
#define RCntCNT3 (DescRC | 0x03) /* �������� �^�[�Q�b�g�l�͂P�ɌŒ� */

#define RCntMdINTR 0x1000
#define RCntMdNOINTR 0x2000
#define RCntMdSC 0x0001
#define RCntMdSP 0x0000
#define RCntMdFR 0x0000
#define RCntMdGATE 0x0010

#define EvSpCZ 0x0001      /* counter becomes zero */
#define EvSpINT 0x0002     /* interrupted */
#define EvSpIOE 0x0004     /* end of i/o */
#define EvSpCLOSE 0x0008   /* file was closed */
#define EvSpACK 0x0010     /* command acknowledged */
#define EvSpCOMP 0x0020    /* command completed */
#define EvSpDR 0x0040      /* data ready */
#define EvSpDE 0x0080      /* data end */
#define EvSpTIMOUT 0x0100  /* time out */
#define EvSpUNKNOWN 0x0200 /* unknown command */
#define EvSpIOER 0x0400    /* end of read buffer */
#define EvSpIOEW 0x0800    /* end of write buffer */
#define EvSpTRAP 0x1000    /* general interrupt */
#define EvSpNEW 0x2000     /* new device */
#define EvSpSYSCALL 0x4000 /* system call instruction */
#define EvSpERROR 0x8000   /* error happned */
#define EvSpPERROR 0x8001  /* previous write error happned */
#define EvSpEDOM 0x0301    /* domain error in libmath */
#define EvSpERANGE 0x0302  /* range error in libmath */

#define EvMdINTR 0x1000
#define EvMdNOINTR 0x2000

#define EvStUNUSED 0x0000
#define EvStWAIT 0x1000
#define EvStACTIVE 0x2000
#define EvStALREADY 0x4000

#define TcbMdRT 0x1000  /* reserved by system */
#define TcbMdPRI 0x2000 /* reserved by system */

#define TcbStUNUSED 0x1000
#define TcbStACTIVE 0x4000

#include "psyq/libgpu.h"
#include "psyq/libgte.h"
#include "psyq/libspu.h"
#include "psyq/libsnd.h"

#define LZ_FILE_CTRL ((lz_t*)0x1F800070)
#define IS_DEBUG_MODE_ENABLED ((u_char)(0x1F80001B4))
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
    /* 0x06 */ EVENT_UNKOWN,
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
    /* 0x12 */ EVENT_UNKNOWN2,
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
    /* 0x20 */ EVENT_UNKNOWN3,
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
    /* 0x2D */ EVENT_UNKNOWN4,
    /* 0x2E */ EVENT_WHERESTHEBABYMOUSE,
    /* 0x2F */ EVENT_SOMECHEESEPLEASE,
    /* 0x30 */ EVENT_UNKNOWN5,
    /* 0x31 */ EVENT_ADRINKFORGOWNUPS,
    /* 0x32 */ EVENT_ROADTOBACCUSLAKE,
    /* 0x33 */ EVENT_ASMALLKEYHOLE,
    /* 0x34 */ EVENT_UNKNOWN6,
    /* 0x35 */ EVENT_THEMOUSEPIGBAG,
    /* 0x36 */ EVENT_THEHAUNTEDMANSION,
    /* 0x37 */ EVENT_ALARGEKEYHOLE,
    /* 0x38 */ EVENT_PAINTINGOFABIGKEY,
    /* 0x39 */ EVENT_BREAKTHEMAGICEGG,
    /* 0x3A */ EVENT_REDHIDDENPOWERS,
    /* 0x3B */ EVENT_UNKNOWN7,
    /* 0x3C */ EVENT_UNKNOWN8,
    /* 0x3D */ EVENT_UNKNOWN9,
    /* 0x3E */ EVENT_TREEOFKNOWLEDGEKNOWS,
    /* 0x3F */ EVENT_THEPUMPROCKS,
    /* 0x40 */ EVENT_AREFRESHINGDRINK,
    /* 0x41 */ EVENT_INEEDATEARBOTTLE,
    /* 0x42 */ EVENT_UNKNOWN10,
    /* 0x43 */ EVENT_UNKNOWN11,
    /* 0x44 */ EVENT_UNKNOWN12,
    /* 0x45 */ EVENT_UNKNOWN13,
    /* 0x46 */ EVENT_UNKNOWN14,
    /* 0x47 */ EVENT_UNKNOWN15,
    /* 0x48 */ EVENT_UNKNOWN16,
    /* 0x49 */ EVENT_WENEEDPOWER,
    /* 0x4A */ EVENT_UNKNOWN17,
    /* 0x4B */ EVENT_UNKNOWN18,
    /* 0x4C */ EVENT_UNKNOWN19,
    /* 0x4D */ EVENT_THECIVILIZATIONMACHINE,
    /* 0x4E */ EVENT_FINDCHARLES,
    /* 0x4F */ EVENT_WHATSUNDERTHEFOREST,
    /* 0x50 */ EVENT_THE100FLOWERFOREST,
    /* 0x51 */ EVENT_THEBOSSTREASURE,
    /* 0x52 */ EVENT_IMSOHUNGRY,
    /* 0x53 */ EVENT_UNKNOWN20,
    /* 0x54 */ EVENT_UNKNOWN21,
    /* 0x55 */ EVENT_THEDEEPJUNGLEPIG,
    /* 0x56 */ EVENT_HEALINGHERBSFORBARON,
    /* 0x57 */ EVENT_DELICIOUSKNOWLEDGEFRUIT,
    /* 0x58 */ EVENT_SEAWEEDFORYOURHEALTH,
    /* 0x59 */ EVENT_UNKNOWN22,
    /* 0x5A */ EVENT_BLUEHIDDENPOWERS,
    /* 0x5B */ EVENT_UNKNOWN23,
    /* 0x5C */ EVENT_UNKNOWN24,
    /* 0x5D */ EVENT_UNKNOWN25,
    /* 0x5E */ EVENT_UNKNOWN26,
    /* 0x5F */ EVENT_UNKNOWN27,
    /* 0x60 */ EVENT_UNKNOWN28,
    /* 0x61 */ EVENT_UNKNOWN29,
    /* 0x62 */ EVENT_UNKNOWN30,
    /* 0x63 */ EVENT_UNKNOWN31,
    /* 0x64 */ EVENT_UNKNOWN32,
    /* 0x65 */ EVENT_UNKNOWN33,
    /* 0x66 */ EVENT_BREAKTHERUSTYDOOR,
    /* 0x67 */ EVENT_THECUTEWITCH,
    /* 0x68 */ EVENT_FOODFORFUEL,
    /* 0x69 */ EVENT_INEEDABOMB,
    /* 0x6A */ EVENT_UNKNOWN34,
    /* 0x6B */ EVENT_UNKNOWN35,
    /* 0x6C */ EVENT_UNKNOWN36,
    /* 0x6D */ EVENT_UNKNOWN37,
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
    /* 0x7A */ EVENT_UNKNOWN40,
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
    /* 0x8C */ EVENT_UNKNOWN47,
    /* 0x8D */ EVENT_UNKNOWN48,
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
    /* 0xA0 */ EVENT_AREALEVILPIGBAG,
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
    byte unk4;
    byte unk5;
    byte unk6;
    byte unk7;
    byte unk8;
    byte unk9;
    byte unka;
    byte unkb;
    byte unkc;
    byte unkd;
    byte unke;
    byte unkf;
    byte unk10;
    byte unk11;
    byte unk12;
    byte unk13;
    byte unk14;
    byte unk15;
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
    short action;
    u_short unk4A;
    short unk4C;
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
    u_short unk58;
    u_short unk5A;
    byte unk5C;
    byte unk5D;
    u_short unk5E;
    byte unk60;
    byte unk61;
    byte unk62;
    byte unk63;
    u_short unk64;
    byte unk66;
    byte unk67;
    u_char start_or_load;
    byte unk69;
    byte unk6A;
    byte unk6B;
} unkstruct_1F8001D4;


typedef struct unkstruct_8009E458 {
    byte data[0x8A];
    u_short unk8A;
    byte pad[0x1104];
    short unk1190;
    short unk1192;
    short unk1194;
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
} inventory;

typedef struct equips {
    ITEM weapon;
    ITEM pants;
} equips;

typedef struct gameConfig {
    u_short selectedArea;
    u_short selectedSection;
    byte selectedPlane;
    byte area00_fogControl;
    byte unk6;
    u_char totalTimePlayed;
    int unk8;
    int playerAP;
    u_char playerHealth;
    u_char playerHealthDisplayed;
    char unk12;
    char unk13;
    u_char unk14;
    byte unk15;
    byte unk16;
    u_char unk17;
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
    byte unk30;
    byte unk31;
    byte unk32;
    byte unk33;
    byte area00_pickedItems;
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
    byte unk48;
    byte unk49;
    byte unk4a;
    byte unk4b;
    byte unk4c;
    byte unk4d;
    byte unk4e;
    byte unk4f;
    byte unk50;
    byte unk51;
    byte unk52;
    byte unk53;
    byte unk54;
    byte unk55;
    byte unk56;
    byte unk57;
    byte unk58;
    byte unk59;
    byte unk5a;
    byte unk5b;
    byte unk5c;
    byte unk5d;
    byte unk5e;
    byte unk5f;
    byte unk60;
    byte unk61;
    byte unk62;
    byte unk63;
    byte unk64;
    byte unk65;
    byte unk66;
    byte unk67;
    byte unk68;
    byte unk69;
    byte unk6a;
    byte unk6b;
    byte unk6c;
    byte unk6d;
    byte unk6e;
    byte unk6f;
    byte unk70;
    byte unk71;
    byte unk72;
    byte unk73;
    byte unk74;
    byte unk75;
    byte unk76;
    byte unk77;
    byte unk78;
    byte unk79;
    byte unk7a;
    byte unk7b;
    byte unk7c;
    byte unk7d;
    byte unk7e;
    byte unk7f;
    byte unk80;
    byte unk81;
    byte unk82;
    byte unk83;
    byte unk84;
    byte unk85;
    byte unk86;
    byte unk87;
    byte unk88;
    byte unk89;
    byte unk8a;
    byte unk8b;
    byte unk8c;
    byte unk8d;
    byte unk8e;
    byte unk8f;
    byte unk90;
    byte unk91;
    byte unk92;
    byte unk93;
    byte unk94;
    byte unk95;
    byte unk96;
    byte unk97;
    byte unk98;
    byte unk99;
    byte unk9a;
    byte unk9b;
    byte unk9c;
    byte unk9d;
    byte unk9e;
    byte unk9f;
    byte unka0;
    byte unka1;
    byte unka2;
    byte unka3;
    byte unka4;
    byte unka5;
    byte unka6;
    byte unka7;
    byte unka8;
    byte unka9;
    byte unkaa;
    byte unkab;
    byte unkac;
    byte unkad;
    byte unkae;
    byte unkaf;
    byte unkb0;
    byte unkb1;
    byte unkb2;
    byte unkb3;
    byte unkb4;
    byte unkb5;
    byte unkb6;
    byte unkb7;
    byte unkb8;
    byte unkb9;
    byte unkba;
    byte unkbb;
    byte unkbc;
    byte unkbd;
    byte unkbe;
    byte unkbf;
    byte unkc0;
    byte unkc1;
    byte unkc2;
    byte unkc3;
    byte unkc4;
    byte unkc5;
    byte unkc6;
    byte unkc7;
    byte unkc8;
    byte unkc9;
    byte unkca;
    byte unkcb;
    byte unkcc;
    byte unkcd;
    byte unkce;
    byte unkcf;
    byte unkd0;
    byte unkd1;
    byte unkd2;
    byte unkd3;
    byte unkd4;
    byte unkd5;
    byte unkd6;
    byte unkd7;
    byte unkd8;
    byte unkd9;
    byte unkda;
    byte unkdb;
    byte unkdc;
    byte unkdd;
    byte unkde;
    byte unkdf;
    byte unke0;
    byte unke1;
    byte unke2;
    byte unke3;
    byte unke4;
    byte unke5;
    byte unke6;
    byte unke7;
    byte unke8;
    byte unke9;
    byte unkea;
    byte unkeb;
    byte unkec;
    byte unked;
    byte unkee;
    byte unkef;
    byte unkf0;
    byte unkf1;
    byte unkf2;
    byte unkf3;
    byte unkf4;
    byte unkf5;
    byte unkf6;
    byte unkf7;
    byte unkf8;
    byte unkf9;
    byte unkfa;
    byte unkfb;
    byte unkfc;
    byte unkfd;
    byte unkfe;
    byte unkff;
    byte unk100;
    byte unk101;
    byte unk102;
    byte unk103;
    byte unk104;
    byte unk105;
    byte unk106;
    byte unk107;
    byte unk108;
    byte unk109;
    byte unk10a;
    byte unk10b;
    byte unk10c;
    byte unk10d;
    byte unk10e;
    byte unk10f;
    byte unk110;
    byte unk111;
    byte unk112;
    byte unk113;
    byte unk114;
    byte unk115;
    byte unk116;
    byte unk117;
    byte unk118;
    byte unk119;
    byte unk11a;
    byte unk11b;
    byte unk11c;
    byte unk11d;
    byte unk11e;
    byte unk11f;
    byte unk120;
    byte unk121;
    byte unk122;
    byte unk123;
    byte unk124;
    byte unk125;
    byte unk126;
    byte unk127;
    byte unk128;
    byte unk129;
    byte unk12a;
    byte unk12b;
    byte unk12c;
    byte unk12d;
    byte unk12e;
    byte unk12f;
    byte unk130;
    byte unk131;
    byte unk132;
    byte unk133;
    byte unk134;
    byte unk135;
    byte unk136;
    byte unk137;
    byte unk138;
    byte unk139;
    byte unk13a;
    byte unk13b;
    byte unk13c;
    byte unk13d;
    byte unk13e;
    byte unk13f;
    byte unk140;
    byte unk141;
    byte unk142;
    byte unk143;
    byte unk144;
    byte unk145;
    byte unk146;
    byte unk147;
    byte unk148;
    byte unk149;
    byte unk14a;
    byte unk14b;
    byte unk14c;
    byte unk14d;
    byte unk14e;
    byte unk14f;
    byte unk150;
    byte unk151;
    byte unk152;
    byte unk153;
    byte unk154;
    byte unk155;
    byte unk156;
    byte unk157;
    byte unk158;
    byte unk159;
    byte unk15a;
    byte unk15b;
    byte unk15c;
    byte unk15d;
    byte unk15e;
    byte unk15f;
    byte unk160;
    byte unk161;
    byte unk162;
    byte unk163;
    byte unk164;
    byte unk165;
    byte unk166;
    byte unk167;
    byte unk168;
    byte unk169;
    byte unk16a;
    byte unk16b;
    byte unk16c;
    byte unk16d;
    byte unk16e;
    byte unk16f;
    byte unk170;
    byte unk171;
    byte unk172;
    byte unk173;
    byte unk174;
    byte unk175;
    byte unk176;
    byte unk177;
    byte unk178;
    byte unk179;
    byte unk17a;
    byte unk17b;
    byte unk17c;
    byte unk17d;
    byte unk17e;
    byte unk17f;
    byte unk180;
    byte unk181;
    byte unk182;
    byte unk183;
    byte unk184;
    byte unk185;
    byte unk186;
    byte unk187;
    byte unk188;
    byte unk189;
    byte unk18a;
    byte unk18b;
    byte unk18c;
    byte unk18d;
    byte unk18e;
    byte unk18f;
    byte unk190;
    byte unk191;
    byte unk192;
    byte unk193;
    byte unk194;
    byte unk195;
    byte unk196;
    byte unk197;
    byte unk198;
    byte unk199;
    byte unk19a;
    byte unk19b;
    byte unk19c;
    byte unk19d;
    byte unk19e;
    byte unk19f;
    byte unk1a0;
    byte unk1a1;
    byte unk1a2;
    byte unk1a3;
    byte unk1a4;
    byte unk1a5;
    byte unk1a6;
    byte unk1a7;
    byte unk1a8;
    byte unk1a9;
    byte unk1aa;
    byte unk1ab;
    byte unk1ac;
    byte unk1ad;
    byte unk1ae;
    byte unk1af;
    byte unk1b0;
    byte unk1b1;
    byte unk1b2;
    byte unk1b3;
    byte unk1b4;
    byte unk1b5;
    byte unk1b6;
    byte unk1b7;
    byte unk1b8;
    byte unk1b9;
    byte unk1ba;
    byte unk1bb;
    byte unk1bc;
    byte unk1bd;
    byte unk1be;
    byte unk1bf;
    byte unk1c0;
    byte unk1c1;
    byte unk1c2;
    byte unk1c3;
    byte unk1c4;
    byte unk1c5;
    byte unk1c6;
    byte unk1c7;
    byte unk1c8;
    byte unk1c9;
    byte unk1ca;
    byte unk1cb;
    byte unk1cc;
    byte unk1cd;
    byte unk1ce;
    byte unk1cf;
    byte unk1d0;
    byte unk1d1;
    byte unk1d2;
    byte unk1d3;
    byte unk1d4;
    byte unk1d5;
    byte unk1d6;
    byte unk1d7;
    byte unk1d8;
    byte unk1d9;
    byte unk1da;
    byte unk1db;
    byte unk1dc;
    byte unk1dd;
    byte unk1de;
    byte unk1df;
    byte unk1e0;
    byte unk1e1;
    byte unk1e2;
    byte unk1e3;
    byte unk1e4;
    byte unk1e5;
    byte unk1e6;
    byte unk1e7;
    byte unk1e8;
    byte unk1e9;
    byte unk1ea;
    byte unk1eb;
    byte unk1ec;
    byte unk1ed;
    byte unk1ee;
    byte unk1ef;
    byte unk1f0;
    byte unk1f1;
    byte unk1f2;
    byte unk1f3;
    byte unk1f4;
    byte unk1f5;
    byte unk1f6;
    byte unk1f7;
    byte unk1f8;
    byte unk1f9;
    byte unk1fa;
    byte unk1fb;
    byte unk1fc;
    byte unk1fd;
    byte unk1fe;
    byte unk1ff;
    byte unk200;
    byte unk201;
    byte unk202;
    byte unk203;
    byte unk204;
    byte unk205;
    byte unk206;
    byte unk207;
    byte unk208;
    byte unk209;
    byte unk20a;
    byte unk20b;
    byte unk20c;
    byte unk20d;
    byte unk20e;
    byte unk20f;
    byte unk210;
    byte unk211;
    byte unk212;
    byte unk213;
    byte unk214;
    byte unk215;
    byte unk216;
    byte unk217;
    byte unk218;
    byte unk219;
    byte unk21a;
    byte unk21b;
    byte unk21c;
    byte unk21d;
    byte unk21e;
    byte unk21f;
    byte unk220;
    byte unk221;
    byte unk222;
    byte unk223;
    byte unk224;
    byte unk225;
    byte unk226;
    byte unk227;
    byte unk228;
    byte unk229;
    byte unk22a;
    byte unk22b;
    byte unk22c;
    byte unk22d;
    byte unk22e;
    byte unk22f;
    byte itemFuriousTornadoCollected;
    byte unk231;
    byte unk232;
    byte unk233;
    byte area00_redApplesOnPumpRocks;
    byte unk235;
    byte unk236;
    byte unk237;
    byte unk238;
    byte unk239;
    byte unk23a;
    byte unk23b;
    byte unk23c;
    byte unk23d;
    byte unk23e;
    byte unk23f;
    byte unk240;
    byte unk241;
    byte unk242;
    byte unk243;
    byte unk244;
    byte unk245;
    byte unk246;
    byte unk247;
    byte unk248;
    byte unk249;
    byte unk24a;
    byte unk24b;
    byte unk24c;
    byte unk24d;
    byte unk24e;
    byte unk24f;
    byte unk250;
    byte unk251;
    byte unk252;
    byte unk253;
    byte unk254;
    byte unk255;
    byte unk256;
    byte unk257;
    byte unk258;
    byte unk259;
    byte unk25a;
    byte unk25b;
    byte unk25c;
    byte unk25d;
    byte unk25e;
    byte unk25f;
    byte unk260;
    byte unk261;
    byte unk262;
    byte unk263;
    byte unk264;
    byte unk265;
    byte unk266;
    byte unk267;
    byte unk268;
    byte unk269;
    byte unk26a;
    byte unk26b;
    byte unk26c;
    byte unk26d;
    byte unk26e;
    byte unk26f;
    byte unk270;
    byte unk271;
    byte unk272;
    byte unk273;
    byte unk274;
    byte unk275;
    byte unk276;
    byte unk277;
    byte unk278;
    byte unk279;
    byte unk27a;
    byte unk27b;
    byte unk27c;
    byte unk27d;
    byte unk27e;
    byte unk27f;
    byte unk280;
    byte unk281;
    byte unk282;
    byte unk283;
    byte unk284;
    byte unk285;
    byte unk286;
    byte unk287;
    byte unk288;
    byte unk289;
    byte unk28a;
    byte unk28b;
    byte unk28c;
    byte unk28d;
    byte unk28e;
    byte unk28f;
    byte unk290;
    byte unk291;
    byte unk292;
    byte unk293;
    byte unk294;
    byte unk295;
    byte unk296;
    byte unk297;
    byte unk298;
    byte unk299;
    byte unk29a;
    byte unk29b;
    byte unk29c;
    byte unk29d;
    byte unk29e;
    byte unk29f;
    byte unk2a0;
    byte unk2a1;
    byte unk2a2;
    byte unk2a3;
    byte unk2a4;
    byte unk2a5;
    byte unk2a6;
    byte unk2a7;
    byte unk2a8;
    byte unk2a9;
    byte unk2aa;
    byte unk2ab;
    byte unk2ac;
    byte unk2ad;
    byte unk2ae;
    byte unk2af;
    byte unk2b0;
    byte unk2b1;
    byte unk2b2;
    byte unk2b3;
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
    byte unk6af;
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
    byte unk963;
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


extern u_char SCRATCHPAD;
extern u_char D_1F8000C0[];
extern u_char D_1F8000F8[];
extern u_char D_1F800118[];
// extern char* D_80010120[];
// extern char* D_80010134[];
// extern char* D_8001014C[];
// extern u_char D_1F8001B4;
// extern u_long D_1F8001D4;
// extern u_short D_1F8001F6; // ASTERISK CURSOR COLOR
// extern u_short D_1F8001FC;
extern int D_1F8002C8[];
extern short D_1F8003B6;


extern u_short D_8007B290;
extern int D_8007B294;
extern U8Pair D_8007C2B8[];
extern int AP_TABLE;
extern u_char EVENT_AP_TABLE;
extern u_char EVENT_AP_TABLE2;
extern u_char D_8007775C[];
extern int D_800771FC;
extern int D_8007722C;
extern u_char D_80077FA8;
extern short D_80078F80;
extern int D_800791A0; // FileLinkArray
extern int D_8007B2F4[];
extern int D_8007B2F6[];
extern int D_8007B2F8[];
extern int D_8007B2FA[];
extern int D_8007B2FC[];
extern int D_8007B2FE[];
extern int D_8007D6A0;
extern u_char D_8007D6D0;
extern u_char D_8007E61C[];
extern int D_8007E6E4[];
extern int D_8007E868;
extern int D_8007E86C;
extern int D_8007E86E;

extern SpuCommonAttr D_8009B048; // SPU_ATTR
extern short D_8009B078;
extern short D_8009B07C;
extern short D_8009B094;
extern u_char LZ_CURRENT_BIT;
extern u_short LZ_BITMASK;
extern short D_8009BC28;
extern int D_8009BC98;
extern u_char D_8009BCA0;
extern char D_8009BCAA;
extern char D_8009BCA7;
extern char D_8009BCDA;
extern char D_8009BCDB;
extern u_char D_8009BCDF;
extern byte D_8009B6A8; // SELECTED ROW
extern gameConfig GAME;
extern int SELECTED_SECTION;
extern int PLAYER_AP;
extern u_char PLAYER_HEALTH;
extern u_char PLAYER_HEALTH_DISPLAYED;
extern u_char D_8009BCDC;
extern u_char PLAYER_LIVES;
extern char AREA00_EVENT_CONTROL;
extern u_short NEXT_AREA;
extern u_short NEXT_SECTION;
extern u_char BLUE_EXP_LEVEL;
extern u_char GREEN_EXP_LEVEL;
extern u_char RED_EXP_LEVEL;
extern char INVENTORY_SCREEN;
extern u_char EVENT_LIST[256];
extern u_char ITEM_LIST[256];
extern u_char INVENTORY_SLOT[256];
extern u_short INVENTORY_SLOT_COUNTER[2];
extern u_short INVENTORY_SORT_MODE;
extern u_short CURRENT_AREA;
extern u_short CURRENT_SECTION;
extern u_short D_8009C864;
extern u_short D_8009C866;
extern void* D_8009C8A8;
extern short D_8009C940;
extern volatile u_short D_8009C9D8;
extern short D_8009C9DA;
extern volatile u_short D_8009C9DC;
extern short D_8009C9DE;
extern short D_8009C9F0;
extern int D_8009CA04;
extern u_char D_8009C3F8;
extern short D_8009E430;
extern unkstruct_8009E458* D_8009E458;
extern short D_8009E638;
extern u_short D_8009E744;
extern u_long OT_FRAMEBUFFER;
extern DRAWENV* D_8009D6C4;
extern char D_8009D6DD;
extern char D_8009D6DE;
extern char D_8009D6DF;
extern char D_8009E3ED;
extern char D_8009E3EE;
extern char D_8009E3EF;
extern long MEMCARD_HW_END_IO;
extern long MEMCARD_HW_END_ERROR;
extern long MEMCARD_HW_TIMEOUT;
extern long MEMCARD_HW_NEW_DEVICE;
extern long MEMCARD_SW_END_IO;
extern long MEMCARD_SW_END_ERROR;
extern long MEMCARD_SW_TIMEOUT;
extern long MEMCARD_SW_NEW_DEVICE;
extern int D_8009EBA8;
extern int D_8009EB4C;
extern short D_8009EBA0;
extern short D_8009EB52;
extern u_short D_8009EB5A;
extern u_short D_8009EB7C;
extern char* SPRINTF_BUFFER_MSG[];
extern char D_800A15D8; // SPU_SEQ_TABLE
extern short D_800A2790;
extern short D_800A3030;
extern short D_800A32F8;
extern u_char D_800A3940;
extern short D_800A3952;
extern u_char D_800A5398;
extern unkstruct_800A39B0 D_800A39B0[];
extern u_char D_800A38B8[];
extern unkstruct_800AFF18 D_800A5140[];
extern char D_800A539C;
extern char D_800A539D;
extern char D_800A539E;
extern char D_800A539F;
extern u_short D_800A5430;
extern u_short D_800A5432;
extern int D_800A5858;
extern int D_800A5970;
extern unkstruct_800AFF18 D_800AFF18[];
extern u_char D_800B00F8;
extern int D_800B0470;
extern int D_800B04F0;
extern int D_800B0528;
extern int D_800B0680;
extern u_char D_800B0770;
extern u_char* D_800B078C;
extern char D_800B07CD;
extern int D_800B3184;
extern char D_800B3188;
extern void func_80019844(void);
extern int D_800121C8;

void FontDebugPrintf(short x, short y, short color, char* fmt);
void func_8001F1C0(void);

// void func_80022618(unkstruct_800A6D50* arg0, u16 arg1);

#endif _INCLUDE_GAME_H
