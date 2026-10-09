#include "common.h"

extern int D_80097504;
int StartPAD(void);
extern int EnterCriticalSection(void);
extern void ExitCriticalSection(void);
int ChangeClearRCnt(int, int);
int func_80069A9C(int, void*);
extern int D_8009B2E0[];
int func_800691C4(void);
typedef struct {
    u_char unk0[2];
    u_char unk2;
    u_char unk3;
    u_char unk4;
} padPort_act;
typedef struct padPort {
    int unk0;
    padPort_act* unk4;
    int unk8;
    struct padPort* unkC;
    struct padPort* unk10;
    int unk14;
    int unk18;
    char unk1C[0xC];
    u_char* unk28;
    u_char* unk2C;
    u_char* unk30;
    u_char unk34;
    u_char unk35;
    u_char unk36;
    u_char unk37;
    u_char unk38;
    u_char unk39;
    char unk3A[2];
    u_char* unk3C;
    u_char* unk40;
    char unk44;
    u_char unk45;
    u_char unk46;
    u_char unk47;
    u_char unk48;
    u_char unk49;
    char unk4A[7];
    u_char unk51[2];
    u_char unk53;
    char unk54[3];
    u_char unk57[6];
    u_char unk5D[6];
    char unk63[0x80];
    u_char unkE3;
    u_char unkE4;
    char unkE5;
    u_short unkE6;
    u_char unkE8;
    u_char unkE9;
    u_char unkEA;
    char unkEB[5];
} padPort;
extern padPort* D_80097544;
extern int D_8009755C;
typedef struct {
    u_long stat;
    u_long mask;
} padIntr;
extern void (*D_80097538)(void);
extern volatile padIntr* D_80097570;
typedef struct {
    u_long data;
    u_short stat;
    u_short unk6;
    u_short mode;
    u_short ctrl;
    u_short unkC;
    u_short baud;
} padSio;
int chkRC2wait(void);
extern volatile padSio* D_80097574;
void func_8006A378(padPort*);
void func_8006A38C(padPort*, int);
void func_8006A3CC(padPort*, int);
void func_8006A3AC(padPort*, int);
void func_8006A3EC(padPort*);
extern void (*D_80097514)(padPort*);
extern padPort D_8009B3A0[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", SetVideoMode);

long SetVideoMode(long mode) {
    long prev = D_80097504;
    D_80097504 = mode;
    return prev;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", GetVideoMode);

int GetVideoMode(void) { return D_80097504; }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_800689FC);

int func_800689FC(void) { return func_800691C4(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", PadInit);

int PadInit(void) { return StartPAD(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", PadStop);

void PadStop(void) { StopPAD(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", PadChkMtap);

int PadChkMtap(int port)
{
    int ret;

    if (D_8009755C == 0) {
        ret = 0;
    } else {
        ret = D_80097544[port >> 4].unkE8 == 8;
    }

    return ret;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068AA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068B68);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068C60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068D34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068E14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068E5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068EAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068FC4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80068FF0);

int func_80068FF0(void)
{
    if (!(D_80097570->mask & 1) || !(D_80097570->stat & 1)) {
        return 0;
    }

    if (D_80097538 != NULL) {
        D_80097538();
    }

    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069058);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_800691C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", StartPAD);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", StopPAD);

void StopPAD(void)
{
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    func_80069A9C(2, D_8009B2E0);
    ExitCriticalSection();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_800692E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_800694FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_800695C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006979C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", _padClrIntSio0);

int _padClrIntSio0(void)
{
    D_80097570->stat = ~0x80;

    while (D_80097574->stat & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }

    D_80097574->ctrl |= 0x10;
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069A60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069A8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069A9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069AAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069AB8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", _padSendAtLoadInfo);

void _padSendAtLoadInfo(padPort* port)
{
    switch (port->unk46) {
    case 2:
        func_8006A378(port);
        break;

    case 3:
        func_8006A38C(port, port->unkE4);
        break;

    case 4:
        func_8006A3CC(port, port->unk47);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069B4C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069C98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069CD0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069DA4);

void func_80069DA4(padPort* port)
{
    switch (port->unk46) {
    case 2:
        func_8006A38C(port, port->unk47);
        break;

    case 3:
        func_8006A3AC(port, port->unk47);
        break;

    case 4:
        if (port->unk48 == 0) {
            func_8006A3CC(port, port->unk47);
        } else {
            func_8006A3EC(port);
        }
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_80069E4C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A0C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A128);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A144);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A20C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A2A4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A2F8);

int func_8006A2F8(padPort* port)
{
    if (port->unk53) {
        if (port->unk46 == 2) {
            return 1;
        }

        port->unk46 = 0xFE;
    } else {
        D_80097514(port);
    }

    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A358);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A378);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A38C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A3AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A3CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A40C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A44C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A524);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A5E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A670);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006A9EC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006AB4C);

void func_8006AB4C(padPort* port)
{
    int i;
    u_char* slot;

    if (port->unk49) {
        slot = port->unk5D;
        port->unk49 = 0;
        port->unk46 = 0;
        port->unkE6 = 0;
        port->unk14 = 0;
        port->unk18 = 0;
        port->unkE3 = 0;
        port->unkE4 = 0;
        port->unkE6 = 0;
        port->unkE9 = 0;
        port->unkEA = 0;
        port->unk0 = 0;
        port->unk4 = NULL;
        port->unk8 = 0;

        for (i = 0; i < 6; ++i) {
            *slot++ = 0xFF;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006ABB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006ACA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006ACB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006AD74);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006AFF0);

int func_8006AFF0(padPort* port)
{
    int i;

    for (i = 0; i < 2; ++i) {
        if (port == &D_8009B3A0[i]) {
            return (i + 1) * 16;
        }
    }

    return 0xFF;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B028);

padPort* func_8006B028(int port) { return port & 0xF0 ? &D_8009B3A0[1] : D_8009B3A0; }

__asm__("nop");

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B04C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B080);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B154);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B3B8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B494);

int func_8006B494(padPort* port) {
    int ret;

    if ((port->unkE6 == 0) || (port->unk46 != 0xFF)) {
        ret = 1;
    } else {
        ret = 0;
    }

    return ret;
}

__asm__("nop");
__asm__("nop");
__asm__("nop");

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B4CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", chkRC2wait);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B58C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", __main);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B6A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", func_8006B70C);
