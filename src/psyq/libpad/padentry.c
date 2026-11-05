#include "common.h"
#include "padlocal.h"

/* Psy-Q LIBPAD PADENTRY.OBJ: PadChkVsync, PadStartCom, PadStopCom, PadChkMtap, PadGetState, PadInfoMode, PadInfoAct, PadInfoComb, PadSetActAlign, PadSetMainMode, PadSetAct. */

/* The duplicated `return 1` bodies for cases 3 and 2 are load-bearing: a
 * shared case body makes GCC merge {2,3} into one range compare, while
 * retail's case tree tests ==3, <4, ==2, ==6 separately. */

/**
 * @brief Check whether pad communication ran since the last call
 * 
 * Wrapper around _padChkVsync(); the result is discarded.
 */
void PadChkVsync(void) {
    _padChkVsync();
}

/**
 * @brief Start controller communication
 * 
 * Hooks the pad handler into the VBlank interrupt and resets the port
 * states.
 */
void PadStartCom(void) {
    _padStartCom();
}

/**
 * @brief Stop controller communication
 * 
 * Unhooks the pad handler from the VBlank interrupt.
 */
void PadStopCom(void) {
    _padStopCom();
}

/**
 * @brief Check whether a multitap is connected to a port
 * 
 * Only reports a multitap when multitap mode is enabled.
 * 
 * @param arg0 Port number (0x00 or 0x10)
 * @return 1 if a multitap is connected, 0 otherwise
 */
int PadChkMtap(int arg0)
{
  register int index;
  if (_padModeMtap != 0)
  {
    index = arg0 >> 4;
    return _padInfoDir[index].currentId == 8;
  }
  return 0;
}

/**
 * @brief Get the connection state of a controller
 * 
 * Reports whether a controller is connected and how far the reading of its
 * extended information has progressed.
 * 
 * @param channel Port number (0x00 or 0x10)
 * @return PadStateDiscon (0), PadStateFindPad (1), PadStateFindCTP1 (2), PadStateReqInfo (4), PadStateExecCmd (5) or PadStateStable (6)
 */
int PadGetState(int channel) {
    padPort *obj;

    obj = _padFuncPort2Info(channel);
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

/**
 * @brief Get information about the controller modes
 * 
 * Returns the controller ID, the extended ID, the current mode index, the
 * number of modes or the ID of a given mode.
 * 
 * @param channel Port number (0x00 or 0x10)
 * @param mode InfoModeCurID (1), InfoModeCurExID (2), InfoModeCurExOffs (3), InfoModeIdTable (4) or 100 for the frame counter
 * @param index Mode table index for InfoModeIdTable (-1 = number of modes)
 * @return Requested value, or 0 if unavailable
 */
int PadInfoMode(int channel, int mode, int index) {
    padPort *obj;

    obj = _padFuncPort2Info(channel);
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

/**
 * @brief Get information about a controller actuator
 * 
 * Returns one field of an actuator record, or the number of actuators.
 * 
 * @param channel Port number (0x00 or 0x10)
 * @param index Actuator number (-1 = number of actuators)
 * @param field InfoActFunc (1), InfoActSub (2), InfoActSize (3), InfoActCurr (4) or InfoActSign (5)
 * @return Requested value, or 0 if unavailable
 */
int PadInfoAct(int channel, int index, int field) {
    padPort *obj;
    PadCapabilityRecord *entry;

    obj = _padFuncPort2Info(channel);
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

/**
 * @brief Get information about actuator combinations
 * 
 * Returns the number of combinations, the number of actuators in a
 * combination, or one actuator number of a combination.
 * 
 * @param channel Port number (0x00 or 0x10)
 * @param index0 Combination number (-1 = number of combinations)
 * @param index1 Index within the combination (-1 = number of actuators in it)
 * @return Requested value, or 0 if unavailable
 */
int PadInfoComb(int channel, int index0, int index1) {
    padPort *obj;
    PadCombinationRecord *entry;

    obj = _padFuncPort2Info(channel);
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

/**
 * @brief Assign actuators to the bytes of the actuator data
 * 
 * Requests the controller to map its actuators to the 6 bytes of transmit
 * data set with PadSetAct().
 * 
 * @param channel Port number (0x00 or 0x10)
 * @param command 6-byte actuator map (0xFF = unused byte)
 */
void PadSetActAlign(int channel, u8 *command) {
    _padSetActAlign(_padFuncPort2Info(channel), command);
}

/**
 * @brief Change the controller mode
 * 
 * Requests a switch to another mode (e.g. digital/analog) and optionally
 * locks the mode switch.
 * 
 * @param channel Port number (0x00 or 0x10)
 * @param byte1 Mode index
 * @param byte2 Lock flag: 3 = lock the mode switch, otherwise unlocked
 */
void PadSetMainMode(int channel, unsigned char byte1, unsigned char byte2) {
    _padSetMainMode(_padFuncPort2Info(channel), byte1, byte2);
}

/**
 * @brief Set the actuator transmit data buffer
 * 
 * Registers the buffer that is sent to the controller actuators on every
 * communication.
 * 
 * @param channel Port number (0x00 or 0x10)
 * @param payload Actuator data buffer
 * @param size Buffer size in bytes
 */
void PadSetAct(int channel, u8 *payload, int size) {
    _padSetAct(_padFuncPort2Info(channel), payload, size);
}
