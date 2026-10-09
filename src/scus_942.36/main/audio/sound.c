#include "common.h"
#include "game.h"
#include "psyq/libspu.h"
#include "psyq/libsnd.h"

#define SOUND_QUEUE_SIZE 0x80
#define BGM_VOICE_MASK (SPU_00CH | SPU_01CH | SPU_02CH | SPU_03CH | SPU_04CH | SPU_05CH | SPU_06CH | SPU_07CH | SPU_08CH | SPU_09CH | SPU_10CH | SPU_11CH | SPU_12CH | SPU_13CH | SPU_14CH | SPU_15CH)
#define SFX_VOICE_MASK (SPU_16CH | SPU_17CH | SPU_18CH | SPU_19CH | SPU_20CH | SPU_21CH | SPU_22CH | SPU_23CH)

enum {
    SND_CMD_KEY_ON            = 0x0000,
    SND_CMD_KEY_OFF           = 0x1000,
    SND_CMD_OVERRIDE          = 0x8000,
    SND_CMD_BGM_FADE          = 0x9000,
    SND_CMD_PITCH_SLIDE       = 0xA000,
    SND_CMD_TYPE_MASK         = 0xF000,
    SND_CMD_PARAM_MASK        = 0x0F00,
    SND_CMD_VALUE_MASK        = 0x00FF,
    SND_SFX_ID_MASK           = 0x03FF,
    SND_KEYON_NOTE_OVERRIDE   = 0x0400,
    SND_KEYON_VOLUME_OVERRIDE = 0x0800,
    SND_OVERRIDE_NOTE         = 0x0000,
    SND_OVERRIDE_VOLUME       = 0x0100,
    SND_FADE_INTERVAL         = 0x0000,
    SND_FADE_STEP             = 0x0100,
    SND_FADE_TARGET           = 0x0200,
    SND_SLIDE_INTERVAL        = 0x0000,
    SND_SLIDE_STEP            = 0x0100,
    SND_SLIDE_DURATION        = 0x0200,
    SND_SLIDE_START           = 0x0300
};

typedef struct {
    u8 vab;
    u8 prog;
    u8 tone;
    u8 note;
    u8 volume;
    u8 priority;
    u8 pad[2];
} SfxDef;

SfxDef D_80077774[41] = {
    { 0, 2, 8, 40, 100, 0 },
    { 0, 0, 1, 1, 100, 0 },
    { 0, 0, 2, 2, 100, 0 },
    { 0, 0, 3, 3, 80, 0 },
    { 0, 0, 4, 4, 80, 0 },
    { 0, 0, 5, 5, 80, 0 },
    { 0, 0, 6, 6, 100, 0 },
    { 0, 0, 7, 7, 120, 0 },
    { 0, 0, 8, 8, 100, 0 },
    { 0, 0, 9, 9, 110, 0 },
    { 0, 0, 10, 10, 110, 0 },
    { 0, 0, 11, 11, 70, 0 },
    { 0, 0, 12, 12, 100, 0 },
    { 0, 0, 13, 13, 100, 0 },
    { 0, 0, 14, 14, 100, 0 },
    { 0, 0, 15, 15, 100, 0 },
    { 0, 1, 0, 16, 100, 0 },
    { 0, 1, 1, 17, 70, 0 },
    { 0, 1, 2, 18, 100, 0 },
    { 0, 1, 3, 19, 100, 0 },
    { 0, 1, 4, 20, 100, 0 },
    { 0, 1, 5, 21, 100, 0 },
    { 0, 1, 6, 22, 100, 0 },
    { 0, 1, 7, 23, 100, 0 },
    { 0, 1, 8, 24, 100, 0 },
    { 0, 1, 9, 25, 100, 0 },
    { 0, 1, 10, 26, 100, 0 },
    { 0, 1, 11, 27, 100, 0 },
    { 0, 1, 12, 28, 100, 0 },
    { 0, 1, 13, 29, 70, 0 },
    { 0, 1, 14, 30, 100, 0 },
    { 0, 1, 15, 31, 100, 0 },
    { 0, 2, 0, 32, 120, 0 },
    { 0, 2, 1, 33, 115, 0 },
    { 0, 2, 2, 34, 115, 0 },
    { 0, 2, 3, 35, 115, 0 },
    { 0, 2, 4, 36, 115, 0 },
    { 0, 2, 5, 37, 120, 0 },
    { 0, 2, 6, 38, 100, 0 },
    { 0, 1, 12, 27, 110, 0 },
    { 0, 2, 7, 39, 100, 0 }
};

SfxDef D_800778BC[1] = {
    { 4, 0, 0, 7, 120, 0 }
};

SfxDef D_800778C4[4] = {
    { 1, 0, 0, 0, 100, 0 },
    { 1, 0, 1, 1, 100, 0 },
    { 1, 0, 2, 2, 100, 0 },
    { 1, 0, 3, 3, 100, 0 }
};

extern s16 BGM_FADE_TIMER;
extern s16 BGM_FADE_INTERVAL;
extern s16 BGM_FADE_STEP;
extern s16 BGM_FADE_TARGET;
extern s16 PITCH_SLIDE_TIMER;
extern s16 PITCH_SLIDE_INTERVAL;
extern s16 PITCH_SLIDE_STEP;
extern s16 PITCH_SLIDE_DURATION;
extern s16 PITCH_SLIDE_VOICE;
extern int LAST_KEYON_VOICE;

typedef struct {
    u16 id;
    s16 arg;
} SfxQueueEntry;

typedef struct {
    u8 seq;
    u8 vab;
    u8 fadeIn;
    u8 unk3;
} BgmDef;

extern u16 AREA_BGM_VOLUME[];
extern s16 BGM_FADE_VOLUME;
extern SfxQueueEntry SOUND_QUEUE[];
extern BgmDef BGM_TRACK_DEFS[];
extern s16 BGM_VAB_ID;
extern u_long* SEQ_DATA[];
extern s16 BGM_TRACK_VOLUME[];
extern s16 JINGLE_VAB_ID;


extern s16 PITCH_SLIDE_VAB;
extern s16 PITCH_SLIDE_PROG;
extern s16 PITCH_SLIDE_OLD_NOTE;
extern s16 PITCH_SLIDE_OLD_FINE;
extern s16 PITCH_SLIDE_NEW_NOTE;
extern s16 PITCH_SLIDE_NEW_FINE;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", updateSound);
void updateSound(void)
{
    int i;
    u16 cmd;

    SpuGetAllKeysStatus(VOICE_KEY_STATUS);
    for (i = 0; i < 24; i++) {
        if (VOICE_KEY_STATUS[i] == 0) {
            VOICE_PRIORITY[i] = 0xF;
        }
    }
    while (SOUND_QUEUE_COUNT != 0) {
        cmd = SOUND_QUEUE[SOUND_QUEUE_HEAD].id;
        switch (cmd & SND_CMD_TYPE_MASK) {
        case SND_CMD_KEY_ON:
            keyOnQueuedSfx(cmd);
            break;
        case SND_CMD_KEY_OFF:
            keyOffSfxVoice(cmd & SND_CMD_VALUE_MASK);
            break;
        case SND_CMD_OVERRIDE:
            setSfxOverride(cmd);
            break;
        case SND_CMD_BGM_FADE:
            setBgmFadeParam(cmd);
            break;
        case SND_CMD_PITCH_SLIDE:
            setPitchSlideParam(cmd);
            break;
        }
        SOUND_QUEUE_HEAD = (SOUND_QUEUE_HEAD + 1) & (SOUND_QUEUE_SIZE - 1);
        SOUND_QUEUE_COUNT--;
    }
    if (BGM_MUTED == 0 && BGM_FADE_ACTIVE != 0) {
        if (--BGM_FADE_TIMER == 0) {
            BGM_FADE_TIMER = BGM_FADE_INTERVAL;
            if (BGM_FADE_STEP < 0) {
                BGM_FADE_VOLUME += BGM_FADE_STEP;
                if (BGM_FADE_VOLUME <= 0) {
                    if (BGM_SEQ_ID != -1) {
                        SsSeqStop(BGM_SEQ_ID);
                        SsSeqClose(BGM_SEQ_ID);
                        BGM_SEQ_ID = -1;
                    }
                    BGM_FADE_ACTIVE = 0;
                }
            } else if (BGM_FADE_VOLUME >= BGM_FADE_TARGET) {
                BGM_FADE_ACTIVE = 0;
            }
            BGM_VOLUME = BGM_FADE_VOLUME;
        }
        SsSeqSetVol(BGM_SEQ_ID, BGM_FADE_VOLUME, BGM_FADE_VOLUME);
    }
    if (PITCH_SLIDE_ACTIVE != 0) {
        if (--PITCH_SLIDE_TIMER == 0) {
            PITCH_SLIDE_TIMER = PITCH_SLIDE_INTERVAL;
            PITCH_SLIDE_NEW_FINE += PITCH_SLIDE_STEP;
            if (PITCH_SLIDE_NEW_FINE < 0) {
                PITCH_SLIDE_NEW_FINE += 0x80;
                PITCH_SLIDE_NEW_NOTE--;
            } else if (PITCH_SLIDE_NEW_FINE >= 0x80) {
                PITCH_SLIDE_NEW_FINE -= 0x80;
                PITCH_SLIDE_NEW_NOTE++;
            }
            SsUtChangePitch(PITCH_SLIDE_VOICE, PITCH_SLIDE_VAB, PITCH_SLIDE_PROG, PITCH_SLIDE_OLD_NOTE, PITCH_SLIDE_OLD_FINE, PITCH_SLIDE_NEW_NOTE, PITCH_SLIDE_NEW_FINE);
        }
        if (--PITCH_SLIDE_DURATION == 0) {
            keyOffSfxVoice((u16)PITCH_SLIDE_VOICE);
            PITCH_SLIDE_ACTIVE = 0;
        }
    }
    if (BGM_MUTED != 0) {
        muteBgm();
        if (JINGLE_SEQ_ID != -1 && SsIsEos(JINGLE_SEQ_ID, 0) == 0) {
            unmuteBgm();
        }
    }
}

s32 getSfxVabOffset(u16 id);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOnQueuedSfx);
s32 keyOnQueuedSfx(s32 cmd)
{
    u8* e = (u8*)getSfxVabOffset(cmd & SND_SFX_ID_MASK);
    s16 voice = SOUND_QUEUE[SOUND_QUEUE_HEAD].arg;
    s16* prio;

    VOICE_KEY_STATUS[voice] = 1;
    VOICE_SFX_ID[voice] = -1;
    prio = &VOICE_PRIORITY[voice];
    if (*prio < e[5]) {
        return -1;
    }
    *prio = e[5];
    switch (cmd & (SND_KEYON_NOTE_OVERRIDE | SND_KEYON_VOLUME_OVERRIDE)) {
    case 0:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], e[3], 0, e[4], e[4]);
        break;
    case SND_KEYON_NOTE_OVERRIDE:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], SFX_NOTE_OVERRIDE, 0, e[4], e[4]);
        break;
    case SND_KEYON_VOLUME_OVERRIDE:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], e[3], 0, SFX_VOLUME_OVERRIDE, SFX_VOLUME_OVERRIDE);
        break;
    case SND_KEYON_NOTE_OVERRIDE | SND_KEYON_VOLUME_OVERRIDE:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], SFX_NOTE_OVERRIDE, 0, SFX_VOLUME_OVERRIDE, SFX_VOLUME_OVERRIDE);
        break;
    }
    return LAST_KEYON_VOICE;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", getSfxVabOffset);
inline s32 getSfxVabOffset(u16 arg0)
{
    u8 a = D_800778E4[arg0 * 2];
    u8 b = D_800778E5[arg0 * 2];

    return SFX_BANKS[a] + b * sizeof(SfxDef);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOffSfxVoice);
inline s16 keyOffSfxVoice(s16 voice)
{
    u16 i = voice;

    if (VOICE_KEY_STATUS[i] != 0) {
        VOICE_PRIORITY[i] = 0xF;
        return SsUtKeyOffV(voice);
    }
    return -1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", setSfxOverride);
s32 setSfxOverride(s32 cmd)
{
    switch (cmd & SND_CMD_PARAM_MASK) {
    case SND_OVERRIDE_NOTE:
        SFX_NOTE_OVERRIDE = cmd & SND_CMD_VALUE_MASK;
        break;
    case SND_OVERRIDE_VOLUME:
        SFX_VOLUME_OVERRIDE = cmd & SND_CMD_VALUE_MASK;
        break;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", setBgmFadeParam);
s32 setBgmFadeParam(s32 cmd)
{
    switch (cmd & SND_CMD_PARAM_MASK) {
    case SND_FADE_INTERVAL:
        BGM_FADE_INTERVAL = cmd & SND_CMD_VALUE_MASK;
        BGM_FADE_TIMER = 1;
        break;
    case SND_FADE_STEP:
        BGM_FADE_STEP = cmd & SND_CMD_VALUE_MASK;
        if ((cmd & SND_CMD_VALUE_MASK) >= 0x80) {
            BGM_FADE_STEP = (cmd & SND_CMD_VALUE_MASK) | 0xFF00;
        }
        break;
    case SND_FADE_TARGET:
        BGM_FADE_TARGET = cmd & SND_CMD_VALUE_MASK;
        break;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", setPitchSlideParam);
s32 setPitchSlideParam(s32 cmd)
{
    switch (cmd & SND_CMD_PARAM_MASK) {
    case SND_SLIDE_INTERVAL:
        PITCH_SLIDE_INTERVAL = cmd & SND_CMD_VALUE_MASK;
        PITCH_SLIDE_TIMER = 1;
        break;
    case SND_SLIDE_STEP:
        PITCH_SLIDE_STEP = cmd & SND_CMD_VALUE_MASK;
        if ((cmd & SND_CMD_VALUE_MASK) >= 0x80) {
            PITCH_SLIDE_STEP = (cmd & SND_CMD_VALUE_MASK) | 0xFF00;
        }
        break;
    case SND_SLIDE_DURATION:
        PITCH_SLIDE_DURATION = cmd & SND_CMD_VALUE_MASK;
        break;
    case SND_SLIDE_START:
        PITCH_SLIDE_ACTIVE = 1;
        PITCH_SLIDE_VOICE = LAST_KEYON_VOICE;
        break;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", allocSfxVoice);
s32 allocSfxVoice(id)
    u16 id;
{
    s32 i;
    u8 a;
    u8 b;
    u8 prio;

    for (i = 0x17; i >= 0x10; i--) {
        if (VOICE_KEY_STATUS[i] == 0 && VOICE_SFX_ID[i] == -1) {
            return i;
        }
    }
    {
        u8* e = (u8*)SFX_BANKS[D_800778E4[id * 2]] + D_800778E5[id * 2] * sizeof(SfxDef);
        prio = e[5];
    }
    for (i = 0x17; i >= 0x10; i--) {
        if (VOICE_PRIORITY[i] >= prio) {
            return i;
        }
    }
    return -1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFX);
s32 playSFX(s32 arg)
{
    register s32 id asm("$16") = arg;
    s32 slot = allocSfxVoice(id);

    if (slot == -1) {
        return -1;
    }
    if (queueSoundCommand(id & SND_SFX_ID_MASK, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFXWithNote);
s32 playSFXWithNote(s32 id, s32 note)
{
    s32 slot = allocSfxVoice(id);

    if (slot == -1 || queueSoundCommand((note & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_NOTE), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand((id & SND_SFX_ID_MASK) | SND_KEYON_NOTE_OVERRIDE, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFXWithVolume);
s32 playSFXWithVolume(s32 id, s32 volume)
{
    s32 slot = allocSfxVoice(id);

    if (slot == -1 || queueSoundCommand((volume & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_VOLUME), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand((id & SND_SFX_ID_MASK) | SND_KEYON_VOLUME_OVERRIDE, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFXWithNoteAndVolume);
s32 playSFXWithNoteAndVolume(s32 id, s32 note, s32 volume)
{
    s32 slot;

    if ((GAME.selectedArea == 2 || GAME.selectedArea == 0x13) && id == 0x32) {
        id = 0x61;
    }
    slot = allocSfxVoice(id);
    if (slot == -1 || queueSoundCommand((note & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_NOTE), slot) == -1 || queueSoundCommand((volume & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_VOLUME), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand((id & SND_SFX_ID_MASK) | (SND_KEYON_NOTE_OVERRIDE | SND_KEYON_VOLUME_OVERRIDE), slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFXWithPitchSlide);
s32 playSFXWithPitchSlide(s32 id, s32 interval, s32 step, s32 duration)
{
    u8* e;
    s32 slot;
    s32 note;

    if (PITCH_SLIDE_ACTIVE != 0) {
        keyOffSfxVoice(PITCH_SLIDE_VOICE);
        PITCH_SLIDE_ACTIVE = 0;
    }
    e = (u8*)getSfxVabOffset(id);
    PITCH_SLIDE_VAB = VAB_IDS[e[0]];
    PITCH_SLIDE_PROG = e[1];
    note = e[3];
    PITCH_SLIDE_NEW_FINE = 0;
    PITCH_SLIDE_OLD_FINE = 0;
    PITCH_SLIDE_NEW_NOTE = note;
    PITCH_SLIDE_OLD_NOTE = note;
    slot = allocSfxVoice(id);
    if (slot == -1 || queueSoundCommand(id & SND_SFX_ID_MASK, slot) == -1 || queueSoundCommand((interval & SND_CMD_VALUE_MASK) | (SND_CMD_PITCH_SLIDE | SND_SLIDE_INTERVAL), slot) == -1 || queueSoundCommand((step & SND_CMD_VALUE_MASK) | (SND_CMD_PITCH_SLIDE | SND_SLIDE_STEP), slot) == -1 || queueSoundCommand((duration & SND_CMD_VALUE_MASK) | (SND_CMD_PITCH_SLIDE | SND_SLIDE_DURATION), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand(SND_CMD_PITCH_SLIDE | SND_SLIDE_START, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOnSFX);
s16 keyOnSFX(s32 id)
{
    s32 voice = allocSfxVoice(id);
    u8* e = (u8*)(SFX_BANKS[D_800778E4[(id & SND_SFX_ID_MASK) * 2]] + D_800778E5[(id & SND_SFX_ID_MASK) * 2] * sizeof(SfxDef));

    return SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], e[3], 0, e[4], e[4]);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFXAndSetNote);
s16 playSFXAndSetNote(s32 id, s16 note)
{
    s32 voice = allocSfxVoice(id);
    u8* e = (u8*)(SFX_BANKS[D_800778E4[(id & SND_SFX_ID_MASK) * 2]] + D_800778E5[(id & SND_SFX_ID_MASK) * 2] * sizeof(SfxDef));

    return SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], note, 0, e[4], e[4]);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", queueSfxKeyOff);
void queueSfxKeyOff(s32 voice)
{
    queueSoundCommand((voice & SND_CMD_VALUE_MASK) | SND_CMD_KEY_OFF, voice);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOffActiveSfxVoices);
void keyOffActiveSfxVoices(void)
{
    s32 i;

    for (i = 0x10; i < 0x18; i++) {
        if (VOICE_KEY_STATUS[i] != 0) {
            VOICE_PRIORITY[i] = 0xF;
            VOICE_SFX_ID[i] = -1;
            SsUtKeyOffV(i);
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", startAreaBgm);
void startAreaBgm(void)
{
    openAreaBgm(-1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", startAreaBgmWithReverb);
void startAreaBgmWithReverb(s16 reverbDepth)
{
    openAreaBgm(reverbDepth);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", adjustAreaBgmVolume);
inline s32 adjustAreaBgmVolume(s32 id)
{
    switch (GAME.selectedArea) {
    case 0:
    case 2:
        id += 5;
        break;
    case 6:
        switch (D_8009BCCA) {
        case 0:
            id -= 5;
            break;
        case 1:
            id += 0xC;
            break;
        case 2:
            id += 0xC;
            break;
        }
        break;
    case 9:
        switch (D_8009BCCA) {
        case 0:
            id -= 0xB;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            id += 0xA;
            break;
        }
        break;
    }
    return id;
}

extern BgmDef AREA_BGM_DEFS[];
extern u8* AREA_REVERB_DEPTH[];
extern s32 AREA_REVERB_MODE[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", openAreaBgm);
s32 openAreaBgm(s32 reverbDepth)
{
    u16 vab;
    int t;
    int area;
    s32 depth;
    s32 mode;

    if (BGM_SEQ_ID != -1) {
        SsSeqStop(BGM_SEQ_ID);
        SsSeqClose(BGM_SEQ_ID);
        BGM_SEQ_ID = -1;
    }
    BGM_MUTED = 0;
    vab = VAB_IDS[AREA_BGM_DEFS[0].vab];
    BGM_VAB_ID = vab;
    BGM_SEQ_ID = SsSeqOpen(SEQ_DATA[AREA_BGM_DEFS[0].seq], vab);
    SsSetMVol(100, 100);
    do {
        t = (int)&GAME;
    } while (0);
    area = *(u16*)t;
    if (AREA_BGM_DEFS[area].fadeIn != 0) {
        SsSeqSetVol(BGM_SEQ_ID, 0, 0);
        area = (s16)AREA_BGM_VOLUME[*(u16*)t];
        BGM_FADE_VOLUME = 0;
        switch (GAME_A) {
        case 0:
        case 2:
            area += 5;
            break;
        case 6:
            switch (D_8009BCCA) {
            case 0:
                area -= 5;
                break;
            case 1:
                area += 0xC;
                break;
            case 2:
                area += 0xC;
                break;
            }
            break;
        case 9:
            switch (D_8009BCCA) {
            case 0:
                area -= 0xB;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                area += 0xA;
                break;
            }
            break;
        }
        BGM_FADE_TARGET = area;
        BGM_FADE_ACTIVE = 1;
    } else {
        t = adjustAreaBgmVolume((s16)AREA_BGM_VOLUME[area]);
        SsSeqSetVol(BGM_SEQ_ID, t, t);
        BGM_VOLUME = t;
        BGM_FADE_ACTIVE = 0;
    }
    depth = (s16)reverbDepth;
    mode = 1;
    if (depth < 0) {
        mode = GAME.selectedArea;
        depth = AREA_REVERB_DEPTH[mode][D_8009BCCA];
        mode = AREA_REVERB_MODE[mode];
        depth <<= 24;
        depth >>= 16;
    }
    setReverbMode(mode, depth);
    SsSeqPlay(BGM_SEQ_ID, SSPLAY_PLAY, 1);
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", startBgmTrack);
s32 startBgmTrack(s32 id)
{
    s16* vol;
    u16 vab;

    if (BGM_SEQ_ID != -1) {
        SsSeqStop(BGM_SEQ_ID);
        SsSeqClose(BGM_SEQ_ID);
        BGM_SEQ_ID = -1;
    }
    vab = VAB_IDS[BGM_TRACK_DEFS[id].vab];
    BGM_VAB_ID = vab;
    BGM_SEQ_ID = SsSeqOpen(SEQ_DATA[BGM_TRACK_DEFS[id].seq], vab);
    SsSetMVol(100, 100);
    SsSeqSetVol(BGM_SEQ_ID, BGM_TRACK_VOLUME[id], BGM_TRACK_VOLUME[id]);
    BGM_FADE_ACTIVE = 0;
    BGM_VOLUME = BGM_TRACK_VOLUME[id];
    SsSeqPlay(BGM_SEQ_ID, SSPLAY_PLAY, 1);
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", stopBgm);
void stopBgm(s32 fadeOut)
{
    if (fadeOut != 0) {
        BGM_FADE_VOLUME = AREA_BGM_VOLUME[GAME.selectedArea] - 1;
        BGM_FADE_INTERVAL = 1;
        BGM_FADE_TIMER = 1;
        BGM_FADE_STEP = -1;
        BGM_FADE_ACTIVE = 1;
    } else {
        if (BGM_SEQ_ID != -1) {
            SsSeqStop(BGM_SEQ_ID);
            SsSeqClose(BGM_SEQ_ID);
            BGM_SEQ_ID = -1;
        }
        BGM_FADE_ACTIVE = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", restoreAreaBgmVolume);
void restoreAreaBgmVolume(void)
{
    s16 vol;

    if (BGM_SEQ_ID != -1) {
        vol = adjustAreaBgmVolume((s16)AREA_BGM_VOLUME[GAME.selectedArea]);
        SsSeqSetVol(BGM_SEQ_ID, vol, vol);
        BGM_MUTED = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playJingle);
s32 playJingle(s32 seqIndex)
{
    u16 vab;

    if (JINGLE_SEQ_ID != -1) {
        SsSeqStop(JINGLE_SEQ_ID);
        SsSeqClose(JINGLE_SEQ_ID);
        JINGLE_SEQ_ID = -1;
    }
    if (seqIndex == 1) {
        if (BGM_SEQ_ID != -1) {
            SsSeqStop(BGM_SEQ_ID);
            SsSeqClose(BGM_SEQ_ID);
            BGM_SEQ_ID = -1;
        }
    }
    vab = *(u16*)0x1F8003AC;
    JINGLE_VAB_ID = vab;
    JINGLE_SEQ_ID = SsSeqOpen(SEQ_DATA[seqIndex], vab);
    SsSetMVol(100, 100);
    SsSeqSetVol(JINGLE_SEQ_ID, 0x50, 0x50);
    SsSeqPlay(JINGLE_SEQ_ID, SSPLAY_PLAY, 1);
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", queueSoundCommand);
s32 queueSoundCommand(cmd, param)
    u16 cmd;
    s32 param;
{
    s32 i;
    u16 idx = SOUND_QUEUE_HEAD;

    for (i = 0; i < SOUND_QUEUE_COUNT; i++) {
        if (SOUND_QUEUE[(s16)idx].id == cmd) {
            return -1;
        }
        idx = (idx + 1) & (SOUND_QUEUE_SIZE - 1);
    }
    SOUND_QUEUE[SOUND_QUEUE_TAIL].id = cmd;
    SOUND_QUEUE[SOUND_QUEUE_TAIL].arg = param;
    SOUND_QUEUE_TAIL = (SOUND_QUEUE_TAIL + 1) & (SOUND_QUEUE_SIZE - 1);
    SOUND_QUEUE_COUNT++;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", stopAllSound);
void stopAllSound(void)
{
    s32 i;

    if (BGM_SEQ_ID != -1) {
        SsSeqStop(BGM_SEQ_ID);
        SsSeqClose(BGM_SEQ_ID);
        BGM_SEQ_ID = -1;
    }
    if (JINGLE_SEQ_ID != -1) {
        SsSeqStop(JINGLE_SEQ_ID);
        SsSeqClose(JINGLE_SEQ_ID);
        JINGLE_SEQ_ID = -1;
    }
    BGM_FADE_ACTIVE = 0;
    PITCH_SLIDE_ACTIVE = 0;
    for (i = 0; i < 0x18; i++) {
        VOICE_PRIORITY[i] = 0xF;
        VOICE_SFX_ID[i] = -1;
    }
    SOUND_QUEUE_TAIL = 0;
    SOUND_QUEUE_HEAD = 0;
    SOUND_QUEUE_COUNT = 0;
    SpuSetKey(SPU_OFF, SPU_ALLCH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", setReverbMode);
void setReverbMode(s32 reverbMode, s16 reverbDepth)
{
    SpuReverbAttr attr;

    attr.mask = SPU_REV_MODE | SPU_REV_DEPTHL | SPU_REV_DEPTHR;
    attr.mode = reverbMode | SPU_REV_MODE_CLEAR_WA;
    attr.depth.left = reverbDepth;
    attr.depth.right = reverbDepth;
    SpuReserveReverbWorkArea(SPU_ON);
    SpuSetReverbModeParam(&attr);
    SpuSetReverb(SPU_ON);
    SpuSetReverbDepth(&attr);
    SpuSetReverbVoice(SPU_ON, BGM_VOICE_MASK);
    SpuSetReverbVoice(SPU_OFF, SFX_VOICE_MASK);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", muteBgm);
void muteBgm(void)
{
    BGM_MUTED = 1;
    SsSeqSetVol(BGM_SEQ_ID, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", unmuteBgm);
void unmuteBgm(void)
{
    BGM_MUTED = 0;
    SsSeqSetVol(BGM_SEQ_ID, BGM_VOLUME, BGM_VOLUME);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOffSfxAll);
void keyOffSfxAll(void)
{
    SpuSetKey(SPU_OFF, SFX_VOICE_MASK);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", shutdownSound);
void shutdownSound(void)
{
    s32 i;

    if (SOUND_INITIALIZED != 0) {
        sndQuit();
    }
    SsInitHot();
    SsSetTableSize(&D_800A15D8, 4, 1);
    SsSetTickMode(SS_TICK60);
    SsSetAutoKeyOffMode(0);
    SpuSetKey(SPU_OFF, SPU_ALLCH);
    SsSetReservedVoice(0x10);
    D_8009B048.mask = (
        SPU_COMMON_CDMIX |
        SPU_COMMON_CDVOLR | 
        SPU_COMMON_CDVOLL | 
        SPU_COMMON_MVOLR | 
        SPU_COMMON_MVOLL
    );
    D_8009B048.mvol.left = 0x3FFF;
    D_8009B048.mvol.right = 0x3FFF;
    D_8009B048.cd.volume.left = 0x7FFF;
    D_8009B048.cd.volume.right = 0x7FFF;
    D_8009B048.cd.mix = SPU_ON;
    SpuSetCommonAttr(&D_8009B048);
    SsStart();
    
    SOUND_QUEUE_TAIL = 0;
    SOUND_QUEUE_HEAD = 0;
    SOUND_QUEUE_COUNT = 0;
    BGM_VOLUME = 0;
    BGM_FADE_ACTIVE = 0;
    PITCH_SLIDE_ACTIVE = 0;
    for (i = 0; i < 0x18; ++i) {
        VOICE_PRIORITY[i] = 0xF;
        VOICE_SFX_ID[i] = -1;
    }
    for (i = 0; i < 0x8; ++i) {
        (&D_1F8003B6-7)[i] = -1;
    }
    BGM_SEQ_ID = -1;
    JINGLE_SEQ_ID = -1;
    SOUND_INITIALIZED = 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", sndQuit);
void sndQuit(void)
{
    SOUND_INITIALIZED = 0;
    SsEnd();
    SsQuit();
}
