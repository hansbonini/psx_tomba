#include "common.h"
#include "padlocal.h"

/* Psy-Q LIBPAD PADENTRY.OBJ: PadChkVsync, PadStartCom, PadStopCom, PadChkMtap, PadGetState, PadInfoMode, PadInfoAct, PadInfoComb, PadSetActAlign, PadSetMainMode, PadSetAct. */

/* The duplicated `return 1` bodies for cases 3 and 2 are load-bearing: a
 * shared case body makes GCC merge {2,3} into one range compare, while
 * retail's case tree tests ==3, <4, ==2, ==6 separately. */

void PadChkVsync(void) {
    _padChkVsync();
}

void PadStartCom(void) {
    _padStartCom();
}

void PadStopCom(void) {
    _padStopCom();
}

int PadChkMtap(int arg0)
{
  register int index;
  if (D_8009755C != 0)
  {
    index = arg0 >> 4;
    return D_80097544[index].currentId == 8;
  }
  return 0;
}

int PadGetState(int channel) {
    padPort *obj;

    obj = D_80097524(channel);
    if ((*(u32 *)&obj->payload_28_len & 0xFFFF0000) == 0
        && (obj == obj->ownerPort || obj->pad_38[0] == 0)
        && obj->output_30[0] == 0) {
        return obj->communicationState;
    }

    switch (obj->communicationState) {
    case 3:
        return 1;
    case 2:
        return 1;
    case 6:
        return 4;
    default:
        return obj->communicationState;
    }
}

int PadInfoMode(int channel, int mode, int index) {
    padPort *obj;

    obj = D_80097524(channel);
    switch (mode) {
    case 1:
        return obj->currentId;
    case 2:
        return obj->currentExtendedId;
    case 3:
        return obj->currentModeIndex;
    case 4:
        if (index < 0) {
            return obj->modeCount;
        }
        if (index < obj->modeCount) {
            return obj->modeTable[index];
        }
        break;
    case 100:
        return obj->frameCounter;
    default:
        return 0;
    }

late_fail:
    return 0;
}

int PadInfoAct(int channel, int index, int field) {
    padPort *obj;
    PadCapabilityRecord *entry;

    obj = D_80097524(channel);
    if (index < 0) {
        return obj->actuatorCount;
    }
    if (index >= obj->actuatorCount) {
        return 0;
    }

    entry = &obj->capabilities[index];
    switch (field) {
    case 1:
        return entry->protocol[0];
    case 2:
        return entry->protocol[1];
    case 3:
        return entry->payloadBytes;
    case 4:
        return entry->activationCost;
    case 5:
        return entry->high_bit;
    default:
        return 0;
    }
}

int PadInfoComb(int channel, int index0, int index1) {
    padPort *obj;
    PadCombinationRecord *entry;

    obj = D_80097524(channel);
    if (index0 < 0) {
        return obj->combinationCount;
    }
    if (index0 >= obj->combinationCount) {
        return 0;
    }
    entry = &obj->combinations[index0];
    if (index1 < 0) {
        return entry->length;
    }
    if (index1 >= entry->length) {
        return 0;
    }
    return entry->data[index1];
}

void PadSetActAlign(int channel, u8 *command) {
    _padSetActAlign(D_80097524(channel), command);
}

void PadSetMainMode(int channel, unsigned char byte1, unsigned char byte2) {
    _padSetMainMode(D_80097524(channel), byte1, byte2);
}

void PadSetAct(int channel, u8 *payload, int size) {
    _padSetAct(D_80097524(channel), payload, size);
}
