#ifndef PADLOCAL_H
#define PADLOCAL_H

int _padStartCom(void);
extern int EnterCriticalSection(void);
extern void ExitCriticalSection(void);
int ChangeClearRCnt(int, int);
int SysDeqIntRP(int, void*);
extern int D_8009B2E0[];
int _padChkVsync(void);
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

#endif
