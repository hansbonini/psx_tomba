/* Adapted from afsenovilla/Tombi-Decomp src/updatePlayer.c (MIT).
 * Copyright (c) 2026 afsenovilla and Tombi-Decomp contributors.
 * See LICENSES/Tombi-Decomp-MIT.txt. Regional behavior is checked against the original executable bytes.
 */
typedef struct { char savedPad[0x2c]; u16 w2c; } PlayerUpdateState;
#if REGION == REGION_JP
#define PLAYER_UPDATE_ANIM_COUNT 74
#define PLAYER_UPDATE_PAD D_8009C9D8_U16
#define PLAYER_UPDATE_INVULN_OFFSET 0xD0
#else
#define PLAYER_UPDATE_ANIM_COUNT 90
#define PLAYER_UPDATE_PAD PAD_PRESSED
#define PLAYER_UPDATE_INVULN_OFFSET 0xE0
#endif
typedef struct { void *p[PLAYER_UPDATE_ANIM_COUNT]; } PlayerUpdateAnimTable;
extern PlayerUpdateState *PLAYER_UPDATE_STATE asm("D_8009B698");
extern PlayerUpdateAnimTable PLAYER_UPDATE_ANIMS asm("D_800E7764");
extern u16 PLAYER_UPDATE_X asm("D_8007D5CC");
extern u16 PLAYER_UPDATE_Z asm("D_8007D5CE");
extern u8 PLAYER_UPDATE_MARKER asm("D_1F8001D2");
void initPlayer(GameObject *);
void updatePlayerActive(GameObject *, s32);
void func_801010D4(GameObject *);
void playerHurt(GameObject *);
void playerHurtBitten(GameObject *);
void playerFallInWater(GameObject *);
void func_800FDABC(GameObject *);
void func_800FDCEC(GameObject *);
void playerClimb(GameObject *);
void func_80108C70(GameObject *);
void func_8010A794(GameObject *);
void func_8010A3A0(GameObject *);
void func_800F7490(GameObject *);
void func_800288C4(void);
void func_80042C20(GameObject *);

#define PLAYER_UPDATE_U8(o, off) (*(u8 *)((char *)(o) + (off)))
#define PLAYER_UPDATE_S16(o, off) (*(s16 *)((char *)(o) + (off)))
#define PLAYER_UPDATE_RESET(o) \
    { \
        o->active = 3; \
        (*(unsigned char*)((char*)&o->unkA0 + 1)) = 0; \
        o->state = 2; \
        o->subState = 2; \
        o->step = 2; \
        o->unk7 = 0; \
        o->timer = 0x78; \
        PLAYER_UPDATE_STATE->w2c = 0x2f; \
        *(PlayerUpdateAnimTable *)tp = PLAYER_UPDATE_ANIMS; \
        o->anim = tp[PLAYER_UPDATE_STATE->w2c]; \
        advanceAnimFrame(o, 1); \
    }

void updatePlayer(GameObject *o)
{
    unsigned char savedPad[8];
    unsigned short b0, b1;
    short f;
    void *t[PLAYER_UPDATE_ANIM_COUNT];
    void **tp;

    memcpy(savedPad, &PLAYER_UPDATE_PAD, 8);
    b0 = D_1F8001FC;
    b1 = D_1F8001FE;
#if REGION == REGION_JP
    PLAYER_UPDATE_U8(o, 0xd2) = 0;
#else
    PLAYER_UPDATE_U8(o, 0xe2) = 0;
#endif
    if (D_8009BCA6) {
        o->visible = 1;
        return;
    }
#if REGION != REGION_JP
    if (D_8009EB58 == 0 && (*(u16 *)&D_8009C978) == 7) {
        unsigned char a, b, c;
        func_800288C4();
        a = PLAYER_UPDATE_U8(o, 0xd6);
        b = PLAYER_UPDATE_U8(o, 0xd5);
        c = o->unkBF;
        o->unkBF = 0;
        PLAYER_UPDATE_U8(o, 0xd7) = a;
        PLAYER_UPDATE_U8(o, 0xd6) = b;
        PLAYER_UPDATE_U8(o, 0xd5) = c;
    }
#endif
    if (D_8009BCA7) {
        *(volatile unsigned short *)&PAD_PRESSED = 0;
        D_1F8001FC = 0;
        D_8009C9DC = 0;
        D_1F8001FE = 0;
#if REGION != REGION_JP
        PLAYER_UPDATE_S16(o, 0xdc) = 0;
        PLAYER_UPDATE_S16(o, 0xde) = 0;
#endif
    }
    PLAYER_UPDATE_MARKER = 0;
    PLAYER_UPDATE_U8(o, 0xc7) = 0;
    switch (o->subtype) {
    case 0:
        if ((D_8009BCEC & 0x40) && (*(volatile unsigned short *)&PAD_PRESSED & (*(u16 *)&D_1F8003C4)) && o->subState == 1)
            PLAYER_UPDATE_U8(o, 0xc1) = 1;
        else
            PLAYER_UPDATE_U8(o, 0xc1) = o->unkA7;
        break;
    case 1:
        PLAYER_UPDATE_U8(o, 0xc1) = 1;
        o->unkA7 = 1;
        D_800A53A0[0] = PLAYER_UPDATE_X;
        D_800A545C[0] = PLAYER_UPDATE_Z;
        break;
    case 2:
        PLAYER_UPDATE_U8(o, 0xc1) = 1;
        o->unkA7 = 1;
        D_800A53A0[0] = PLAYER_UPDATE_X;
        D_800A545C[0] = PLAYER_UPDATE_Z;
        break;
    }
    {
        signed char *k = &D_8009C618[0];
        if (*k >= 5) goto z;
        if (*k < 3) {
        z:
            *k = 0;
        }
    }
    switch (o->state) {
    case 0:
        initPlayer(o);
        break;
    case 1:
        tp = t;
        if (D_8009BCA0) {
            PLAYER_UPDATE_RESET(o);
            break;
        }
        if (o->subState != 0x30 && PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) > 0) {
            if ((*(unsigned char*)((char*)&o->unkA0 + 3)) & 2) {
                o->visible ^= 1;
            } else if ((*(unsigned char*)((char*)&o->unkA0 + 2)) & 2) {
                o->visible ^= 1;
            } else {
                PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) = PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) - 1;
                o->visible = PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) & 1;
                if (PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) <= 0) {
#if REGION == REGION_EU
                    if (PLAYER_UPDATE_U8(o, 0xcc) != 2) o->active = 1;
#else
                    o->active = 1;
#endif
                    PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) = 0;
                    o->visible = 1;
                }
            }
        }
        if (o->cooldownTimer > 0 && --o->cooldownTimer <= 0) {
            o->active = 1;
            o->visible = 1;
        }
        ((void (*)(GameObject *))updatePlayerActive)(o);
        break;
    case 2:
        if (PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) > 0) {
            PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) = PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) - 1;
        #if REGION == REGION_JP
            o->visible = PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) & 1;
#else
            if (PLAYER_UPDATE_U8(o, 0xd1) == 0) o->visible = PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) & 1;
#endif
            if (PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) <= 0) {
                o->active = 1;
                PLAYER_UPDATE_S16(o, PLAYER_UPDATE_INVULN_OFFSET) = 0;
                o->visible = 1;
            }
        }
        switch (o->subState) {
        case 0: playerHurt(o); break;
        case 1: playerHurtBitten(o); break;
        case 2: playerFallInWater(o); break;
        case 3: func_800FDABC(o); break;
        case 4: func_800FDCEC(o); break;
        }
        (*(unsigned char*)&o->unkA8) = 0;
        o->unkA6 = 0;
        f = 0;
        if (o->unk9E == 0 && o->state == 5) {
            f = o->subState == 0x40;
            if (o->subState == 0x65) f++;
        }
        if (f == 0) func_80042C20(o);
        break;
    case 3:
        o->state = 1;
        break;
    case 5:
        tp = t;
        if (D_8009BCA0) {
            PLAYER_UPDATE_RESET(o);
            break;
        }
        if (o->cooldownTimer > 0 && --o->cooldownTimer <= 0) {
            o->active = 1;
            o->cooldownTimer = 0;
            o->visible = 1;
        }
        func_801010D4(o);
        break;
    case 6:
        tp = t;
        if (D_8009BCA0) {
            PLAYER_UPDATE_RESET(o);
            break;
        }
        if (o->cooldownTimer > 0 && --o->cooldownTimer <= 0) {
            o->active = 1;
            o->cooldownTimer = 0;
            o->visible = 1;
        }
        switch (o->subState) {
        case 0:
            playerClimb(o);
            break;
        case 3:
            o->animFrame &= 1;
            func_80108C70(o);
            break;
        case 4:
            o->animFrame &= 1;
            func_8010A794(o);
            break;
        case 5:
            o->animFrame &= 1;
            func_8010A3A0(o);
            o->unk8C = 0;
            break;
        case 6:
            func_800F7490(o);
            break;
        case 7:
            o->unk8C = 0;
            func_8010A3A0(o);
            if (o->touchFlag) {
                o->state = 1;
                o->subState = 0;
                o->step = 0;
            }
            break;
        }
        (*(unsigned char*)&o->unkA8) = 0;
        o->unkA6 = 0;
        if (o->unk9E == 0) func_80042C20(o);
        break;
    }
    D_1F80016A[0] = o->h->p.whole;
    D_1F80016E_S16Arr[0] = o->y.p.whole;
    D_1F800172[0] = o->d->p.whole;
    GAME.selectedPlane = o->d->p.whole / 90;
    memcpy(&PLAYER_UPDATE_PAD, savedPad, 8);
    D_1F8001FC = b0;
    D_1F8001FE = b1;
}

#undef PLAYER_UPDATE_RESET
#undef PLAYER_UPDATE_U8
#undef PLAYER_UPDATE_S16

#undef PLAYER_UPDATE_ANIM_COUNT
#undef PLAYER_UPDATE_INVULN_OFFSET

#undef PLAYER_UPDATE_PAD
