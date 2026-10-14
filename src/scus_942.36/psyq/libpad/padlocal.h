#ifndef PADLOCAL_H
#define PADLOCAL_H

/*
 * LIBPAD 4.2 internal state. Field names and types follow
 * khasinski/parasite-eve-decomp (same PADMAIN/PADCMD/... objects).
 */

/* Actuator capability record (PadInfoAct). */
typedef struct {
    u8 protocol[2];
    u8 payloadBytes;
    u8 activationCost;
    u8 high_bit;
} PadCapabilityRecord;

/* Actuator combination record (PadInfoComb). */
typedef struct {
    u8 length;
    u8 reserved[3];
    u8* data;
} PadCombinationRecord;

/* Per-port command object. */
typedef struct padPort {
    u16* modeTable;                       /* 0x00 */
    PadCapabilityRecord* capabilities;    /* 0x04 */
    PadCombinationRecord* combinations;   /* 0x08 */
    struct padPort* subPorts;             /* 0x0C: multitap sub-ports */
    struct padPort* ownerPort;            /* 0x10 */
    void (*fn_14)(void*);                 /* 0x14 */
    int (*fn_18)(struct padPort*);        /* 0x18 */
    u8 pad_1C[0x04];
    u8* requestedActuatorMap;             /* 0x20 */
    u8 pad_24[0x04];
    u8* payload_28;                       /* 0x28 */
    u8* payload_2c;                       /* 0x2C */
    u8* output_30;                        /* 0x30 */
    u8 payload_28_len;                    /* 0x34 */
    u8 payload_2c_len;                    /* 0x35 */
    u8 command;                           /* 0x36 */
    u8 saved_command;                     /* 0x37 */
    u8 pad_38[0x04];
    u8* response_3c;                      /* 0x3C */
    u8* statusBuffer;                     /* 0x40 */
    u8 response_index;                    /* 0x44 */
    u8 payload_index;                     /* 0x45 */
    u8 sequenceStep;                      /* 0x46: 0xFE/0xFF terminal */
    u8 infoRecordIndex;                   /* 0x47 */
    u8 combinationBytesRemaining;         /* 0x48 */
    u8 communicationState;                /* 0x49: PadGetState */
    u8 retryCount;                        /* 0x4A */
    u8 pad_4B[0x01];
    int frameCounter;                     /* 0x4C */
    u8 pad_50[0x01];
    u8 requestedModeIndex;                /* 0x51 */
    u8 requestedModeLock;                 /* 0x52 */
    u8 modeAlreadySelected;               /* 0x53 */
    u8 pad_54[0x03];
    u8 actuatorEnabled[0x06];             /* 0x57 */
    u8 actuatorMap[0x06];                 /* 0x5D: 0xFF = unused */
    u8 pad_63[0x80];
    u8 modeCount;                         /* 0xE3 */
    u8 currentModeIndex;                  /* 0xE4 */
    u8 pad_e5[0x01];
    u16 currentExtendedId;                /* 0xE6 */
    u8 currentId;                         /* 0xE8: 8 = multitap */
    u8 actuatorCount;                     /* 0xE9 */
    u8 combinationCount;                  /* 0xEA */
    u8 pad_eb[0x01];
    int combinationStorageBytes;          /* 0xEC */
} padPort;

STATIC_ASSERT_SIZEOF(padPort, 0xF0);

#define OFFSETOF(type, member) ((u32) & (((type*)0)->member))

/* PadInitDirect walks the objects by their statusBuffer member. */
#define PADPORT_FROM_STATUS_BUFFER(p) \
    ((padPort*)((u8*)(p) - OFFSETOF(padPort, statusBuffer)))

/* Address arithmetic in the original's operand order. */
typedef union {
    padPort* obj;
    PadCapabilityRecord* capability;
    int* count;
    u8* bytes;
    u32 word;
} padAddr;

/* I_STAT / I_MASK at 0x1F801070. */
typedef struct {
    volatile u_long stat;
    volatile u_long mask;
} padIntr;

/* SIO0 at 0x1F801040. */
typedef struct {
    volatile u_char data;
    u_char unk1[3];
    volatile u_short stat;
    u_short unk6;
    volatile u_short mode;
    volatile u_short ctrl;
    u_short unkC;
    volatile u_short baud;
} padSio;

/* BIOS / LIBAPI. */
int EnterCriticalSection(void);
void ExitCriticalSection(void);
int ChangeClearRCnt(int, int);
int SysDeqIntRP(int, void*);
int SysEnqIntRP(int, void*);
void bzero(void*, int);

/* PADMAIN. */
void _padSetVsyncParam(void);
int func_80068FF0(void);
int func_80069058(void);
int _padChkVsync(void);
void _padStartCom(void);
void _padStopCom(void);
int _padInitSioMode(padPort*);
void func_800694FC(padPort*);
int _padSioRW(padPort*, int);
int func_8006979C(padPort*, int);
int _padClrIntSio0(void);
void func_80069A60(void);

/* PADCMD. */
void _padSetAct(padPort*, u8*, int);
void _padSendAtLoadInfo(padPort*);
int _padRecvAtLoadInfo(padPort*);
int _padGetActSize(padPort*);
int _padLoadActInfo(padPort*, u8*);
void func_80069DA4(padPort*);
int func_80069E4C(padPort*);
int _padSetActAlign(padPort*, u8*);
void func_8006A128(padPort*);
int func_8006A144(padPort*);
int _padSetMainMode(padPort*, int, int);
void func_8006A2A4(padPort*);
int func_8006A2F8(padPort*);
void _padCmdParaMode(padPort*, u8);
void func_8006A378(padPort*);
void func_8006A38C(padPort*, u8);
void func_8006A3AC(padPort*, u8);
void func_8006A3CC(padPort*, u8);
void func_8006A3EC(padPort*);

/* PADPORTD. */
void func_8006AB4C(padPort*);
int func_8006ABB4(int);
void func_8006ACA8(padPort*);
int func_8006ACB8(padPort*, int);
void func_8006AD74(padPort*);
int func_8006AFF0(padPort*);
padPort* func_8006B028(int);

/* PADSEQD. */
void _padInitDirSeq(void);
int func_8006B080(padPort*);
void func_8006B154(padPort*);
void _dirFailAuto(padPort*);
int func_8006B494(padPort*);

/* WAITRC2. */
void setRC2wait(int);
int chkRC2wait(void);

/* State. */
extern int (*D_80097510)(int);                  /* DMA/transfer completion */
extern void (*D_80097514)(padPort*);            /* reset object */
extern int (*D_80097518)(padPort*, int);        /* read payload byte */
extern void (*D_8009751C)(padPort*);            /* actuator map */
extern int (*D_80097520)(padPort*);             /* channel id of object */
extern padPort* (*D_80097524)(int);             /* object of channel */
extern int (*D_80097528)(padPort*);             /* state dispatch */
extern int (*D_8009752C)();                     /* transfer busy */
extern void (*D_80097530)(padPort*);            /* response handler */
extern void (*D_80097534)(padPort*);            /* swap byte field */
extern int (*D_80097538)(void);
extern void (*D_8009753C)(void);
extern void (*D_80097540)(void);
extern padPort* D_80097544;                     /* port objects */
extern int D_80097548;                          /* service ready */
extern int D_8009754C;
extern int D_80097550;                          /* active port index */
extern int D_80097554;                          /* command step */
extern int D_80097558;                          /* actuator cost total */
extern int D_8009755C;                          /* multitap command byte */
extern int D_80097560;                          /* port 1 absent */
extern int D_80097564;                          /* last port index */
extern int D_80097568[];                        /* channel counts */
extern padIntr* D_80097570;
extern padSio* D_80097574;
extern int D_80097578;                          /* vsync callback pending */
extern int D_80097588;
extern volatile u8* D_8009758C;
extern int D_80097590;
extern int (*D_80097594[])(void);               /* command step handlers */
extern padSio* D_800975A8;
extern int D_8009B2E0[];                        /* VSync interrupt queue node */
extern int D_8009B2F0[2];                       /* idle frames per port */
extern u8* D_8009B300;
extern u8 D_8009B310[];
extern u8 D_8009B358[];
extern padPort D_8009B3A0[];
extern u32 D_8009B6A4;                          /* timeout start */
extern u32 D_8009FD80;                          /* timeout limit */

#endif
