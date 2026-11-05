#include "common.h"
#include "padlocal.h"

/* Psy-Q LIBPAD PADCMD.OBJ: _padSetAct, _padSetCmd, _padSendAtLoadInfo, _padRecvAtLoadInfo, _padGetActSize, _padLoadActInfo, _padSetActAlign, _padSetMainMode, _padCmdParaMode and the command emitters. */

/**
 * @brief Internal: set the actuator (vibration) output data of a port
 * 
 * Stores the buffer whose bytes are sent to the actuators on every
 * communication.
 * 
 * @param arg0 Controller port state
 * @param arg1 Actuator data buffer
 * @param arg2 Size of the buffer in bytes
 */
void _padSetAct(padPort *arg0, u8 *arg1, int arg2)
{
    arg0->payload_28 = arg1;
    arg0->payload_28_len = arg2;
}

/**
 * @brief Internal: queue a configuration command for a port
 * 
 * Sets the command byte and its parameter buffer to be sent during the
 * next communication.
 * 
 * @param arg0 Controller port state
 * @param arg1 Controller command byte (0x43, 0x44, ...)
 * @param arg2 Parameter bytes
 * @param arg3 Number of parameter bytes
 */
void _padSetCmd(padPort *arg0, unsigned char arg1, u8 *arg2, unsigned char arg3)
{
    arg0->command = arg1;
    arg0->payload_2c = arg2;
    arg0->payload_2c_len = arg3;
}

/**
 * @brief Internal: select the next query command of the controller information sequence
 * 
 * Depending on the current step, requests the controller status (0x45),
 * the ID of a mode (0x4C) or a combination record (0x47).
 * 
 * @param arg0 Controller port state
 */
void _padSendAtLoadInfo(padPort *arg0)
{
    int state = arg0->sequenceStep;

    switch (state) {
    case 2:
        func_8006A378(arg0);
        break;
    case 3:
        func_8006A38C(arg0, arg0->currentModeIndex);
        break;
    case 4:
        func_8006A3CC(arg0, arg0->infoRecordIndex);
        break;
    }
}

#define CARD_RESPONSE(obj) \
    (*(unsigned char * volatile *)&(obj)->response_3c)

/**
 * @brief Internal: process a reply of the controller information sequence
 * 
 * Stores the mode/actuator/combination counts and the current mode, then
 * accumulates the size of the combination data. Once everything has been
 * counted it reserves the buffers with _padLoadActInfo() and starts
 * reading the tables.
 * 
 * @param obj Controller port state
 * @return 1 to advance to the next step, 0 to stay on the current step
 */
int _padRecvAtLoadInfo(padPort *obj) {
    unsigned int chunk;
    register unsigned int next asm("$2");
    unsigned int responseValue;
    switch (obj->sequenceStep) {
    case 2:
        obj->modeCount = CARD_RESPONSE(obj)[3];
        obj->currentModeIndex = CARD_RESPONSE(obj)[4];
        obj->currentExtendedId = 0;
        obj->actuatorCount = CARD_RESPONSE(obj)[5];
        obj->combinationCount = CARD_RESPONSE(obj)[6];
        obj->combinationStorageBytes = 0;
        break;

    case 3:
        responseValue = obj->response_3c[4];
        next = obj->response_3c[5];
        obj->infoRecordIndex = 0;
        obj->currentExtendedId = (responseValue << 8) + next;
        break;

    case 4:
        chunk = obj->combinationStorageBytes;
        next = obj->infoRecordIndex;
        responseValue = obj->response_3c[4];
        next++;
        obj->infoRecordIndex = next;
        chunk += 8;
        chunk += (responseValue + 3) & 0x1FC;
        obj->combinationStorageBytes = chunk;
        if ((next & 0xFF) < obj->combinationCount) {
return_zero:
            return 0;
        }

        if (_padGetActSize(obj) >= 0x81) {
            obj->sequenceStep = 0xFE;
            obj->communicationState = 2;
            goto return_zero;
        }

        obj->sequenceStep = 0xFF;
        _padLoadActInfo(obj, (unsigned char *)obj + 0x63);
        obj->sequenceStep = 2;
        goto return_zero;
    }

    return 1;
}

/**
 * @brief Internal: compute the buffer size needed for the controller tables
 * 
 * Adds up the space required by the mode ID table, the actuator records
 * and the combination records.
 * 
 * @param arg0 Controller port state
 * @return Size in bytes
 */
int _padGetActSize(padPort *arg0) {
    int first;
    int second;
    int responseBytes;
    int base;
    int raw_first;
    int raw_second;

    raw_first = arg0->modeCount;
    raw_second = arg0->actuatorCount;
    base = arg0->combinationStorageBytes;

    first = raw_first + 1;
    first >>= 1;
    first <<= 2;

    responseBytes = (raw_second << 2) + raw_second;
    second = (responseBytes + 3) & 0xFFC;
    second += 4;

    first += second;
    return first + base;
}

/**
 * @brief Internal: start reading the mode, actuator and combination tables
 * 
 * Lays out the mode, actuator and combination tables inside the given
 * buffer and installs the send/receive handlers (func_80069DA4 /
 * func_80069E4C) that read them from the controller.
 * 
 * @param obj Controller port state
 * @param buffer Buffer receiving the tables
 * @return 1 if the sequence was started, 0 if the buffer is NULL, the tables are already loaded or the port is busy
 */
int _padLoadActInfo(padPort *obj, unsigned char *buffer) {
    int cursor;
    int result;
    int state;
    register int (*processFn)(padPort *);
    int rowCount;
    int columnCount;

    if (buffer == 0) {
        goto return_zero;
    }
    if (obj->capabilities != 0) {
        return 0;
    }
    if (_padFuncChkEng() != 0) {

return_zero:
    return 0;

    }
initialize:
    result = 1;
    asm volatile("" : "=r"(result) : "0"(result));
    state = 4;
    cursor = ((int)buffer + 3) >> 2;
    obj->communicationState = state;
    state = 1;
    obj->sequenceStep = state;
    obj->fn_14 = (void (*)(void *))func_80069DA4;
    asm volatile("" ::: "memory");
    rowCount = obj->modeCount;
        processFn = func_80069E4C;
    obj->fn_18 = processFn;
    asm volatile("" ::: "memory");
    columnCount = obj->actuatorCount;
    asm volatile("" : "=r"(rowCount), "=r"(columnCount), "=r"(result) : "0"(rowCount), "1"(columnCount), "2"(result));

    cursor <<= 2;
    obj->modeTable = (u16 *)cursor;
    obj->infoRecordIndex = 0;
    asm volatile("" ::: "memory");
    cursor += ((rowCount + 1) >> 1) * 4;
    obj->capabilities = (PadCapabilityRecord *)cursor;
    cursor += (columnCount * 5 + 3) & 0xFFC;
    obj->combinations = (PadCombinationRecord *)cursor;
    return result;
}

/**
 * @brief Internal: send handler for reading the controller tables
 * 
 * Requests the next mode ID (0x4C), actuator record (0x46) or combination
 * record (0x47, continued with 0x4B).
 * 
 * @param arg0 Controller port state
 */
void func_80069DA4(padPort *arg0) {
    int state = arg0->sequenceStep;

    switch (state) {
    case 2:
        func_8006A38C(arg0, arg0->infoRecordIndex);
        break;
    case 3:
        func_8006A3AC(arg0, arg0->infoRecordIndex);
        break;
    case 4:
        if (arg0->combinationBytesRemaining == 0) {
            func_8006A3CC(arg0, arg0->infoRecordIndex);
        } else {
            func_8006A3EC(arg0);
        }
        break;
    }
}

/**
 * @brief Internal: receive handler for reading the controller tables
 * 
 * Stores each reply in the mode, actuator or combination table and moves
 * to the next record or step.
 * 
 * @param inPort Controller port state
 * @return 1 to advance to the next step, 0 to stay on the current step
 */
int func_80069E4C(padPort *inPort) {
    register padPort *port = inPort;
    switch (port->sequenceStep) {
    case 2:
        port->modeTable[port->infoRecordIndex] =
            port->response_3c[5] + (port->response_3c[4] << 8);
        port->infoRecordIndex++;
        if (port->infoRecordIndex >= port->modeCount) {
            port->infoRecordIndex = 0;
            break;
        }
        return 0;
    case 3: {
        PadCapabilityRecord *record =
            port->capabilities + port->infoRecordIndex;
        record->protocol[0] = port->response_3c[4];
        record->protocol[1] = port->response_3c[5] & 127;
        record->payloadBytes = port->response_3c[6];
        record->activationCost = port->response_3c[7];
        {
            register int high = port->response_3c[5];
            record->high_bit = high >> 7;
        }
        port->infoRecordIndex++;
        if (port->infoRecordIndex >= port->actuatorCount) {
            port->infoRecordIndex = 0;
            port->combinationBytesRemaining = 0;
            break;
        }
        return 0;
    }
    case 4: {
        PadCombinationRecord *record = port->combinations + port->infoRecordIndex;
        register u8 *source, *base;
        register int bytes asm("$4");
        unsigned offset;
        if (port->combinationBytesRemaining == 0) {
            {
                register int length = port->response_3c[4];
                bytes = 3;
                port->combinationBytesRemaining = length;
            }
            record->length = port->combinationBytesRemaining;
            {
                register u8 *response = port->response_3c;
                register int index = port->infoRecordIndex;
                source = response + 5;
                if (index == 0) {
                    base = (u8 *)port->combinations;
                    offset = port->combinationCount * 8;
                } else {
                    base = record[-1].data;
                    offset = (record[-1].length + 3) & 0x1fc;
                }
            }
            base = base + offset;
            record->data = base;
            D_8009B300 = base;
        } else {
            register u8 *response = port->response_3c;
            bytes = 6;
            source = response + 2;
        }
        bytes--;
        if (bytes != -1) {
            register u8 **destination = &D_8009B300;
            do {
                register int remaining = port->combinationBytesRemaining;
                bytes--;
                if (!remaining)
                    goto exhausted;
                {
                    register u8 *dst = *destination;
                    register int value = *source++;
                    asm("" : "=r"(source) : "0"(source));
                    *dst = value;
                    *destination = dst + 1;
                }
                port->combinationBytesRemaining--;
            } while (bytes != -1);
        }

        if (port->combinationBytesRemaining != 0) {
    zero:
        return 0;
        }
    exhausted:
        {
            port->infoRecordIndex++;
            if (port->infoRecordIndex >= port->combinationCount) {
                port->communicationState = 6;
                port->sequenceStep = 254;
                return 0;
            }
            port->combinationBytesRemaining = 0;
        }
        goto zero;
    }
    default:
        return 1;
    }
complete:
    return 1;
}

/**
 * @brief Internal: start the actuator alignment sequence
 * 
 * Installs handlers that send the actuator map with command 0x4D and then
 * mark the actuators as assigned.
 * 
 * @param obj Controller port state
 * @param command 6-byte actuator map (actuator number for each output data byte, 0xFF = unused)
 * @return 1 if the request was accepted, 0 if the port is busy
 */
int _padSetActAlign(padPort *obj, u8 *command) {
    int result;
    int active;

    result = _padFuncChkEng(obj);
    if (result != 0) {
        return 0;
    } else {
        active = 1;
        obj->sequenceStep = active;
        obj->fn_14 = (void (*)(void *))func_8006A128;
        obj->requestedActuatorMap = command;
        obj->fn_18 = func_8006A144;
        result = 1;
    }
    return result;
}

/**
 * @brief Internal: send handler of the actuator alignment sequence
 * 
 * Queues command 0x4D with the requested 6-byte actuator map.
 * 
 * @param arg0 Controller port state
 */
void func_8006A128(padPort *arg0) {
    u8 *value = arg0->requestedActuatorMap;

    arg0->command = 0x4D;
    arg0->payload_2c_len = 6;
    arg0->payload_2c = value;
}
/**
 * @brief Internal: receive handler of the actuator alignment sequence
 * 
 * Builds the local actuator map from the requested one, keeping only as
 * many data bytes per actuator as it needs, and ends the sequence.
 * 
 * @param arg0 Controller port state
 * @return Always 0
 */
s32 func_8006A144(padPort *arg0) {
    s32 i;
    s32 ff;
    u8 *cursor;
    s32 matched;
    s32 remaining;
    s32 written;
    s32 needed;
    register u8 *out asm("$6");
    register s32 limit;

    i = 0;
    if (arg0->actuatorCount != 0) {
        ff = 0xFF;
        do {
            cursor = arg0->requestedActuatorMap;
            matched = 0;
            remaining = 5;
            do {
                if (*cursor++ == i) {
                    matched += 1;
                }
                remaining -= 1;
            } while (remaining >= 0);
            needed = arg0->capabilities[i].payloadBytes;
            cursor = arg0->requestedActuatorMap;
            written = 0;
            if (needed == 0) {
                needed = 1;
            }
            out = (u8 *)arg0;
            do {
                if (*cursor++ == i) {
                    if (matched < needed) {
                        out[OFFSETOF(padPort, actuatorMap)] = ff;
                        matched -= 1;
                    } else {
                        out[OFFSETOF(padPort, actuatorMap)] = i;
                    }
                }
                written += 1;
                out += 1;
            } while (written < 6);
            limit = arg0->actuatorCount;
            i += 1;
        } while (i < limit);
    }
    arg0->sequenceStep = 0xFE;
    return 0;
}

/**
 * @brief Internal: start the main mode change sequence
 * 
 * Installs handlers that send command 0x44 (set mode) and then reapply the
 * actuator map with 0x4D.
 * 
 * @param obj Controller port state
 * @param byte1 Mode index to select
 * @param byte2 Mode lock: 3 = lock the mode switch on the controller, otherwise unlocked
 * @return 1 if the request was accepted, 0 if the port is busy
 */
int _padSetMainMode(padPort *obj, int byte1, int byte2) {
    register int compareByte asm("$19");
    register int flag asm("$3");
    register int result;

    compareByte = byte1;
    result = _padFuncChkEng(obj);
    if (result != 0) {
        return 0;
    }

    result = 1;
    asm("" : "=r"(result) : "0"(result));
    flag = 1;
    obj->sequenceStep = flag;
    obj->fn_14 = (void (*)(void *))func_8006A2A4;
    obj->fn_18 = func_8006A2F8;
    obj->requestedModeIndex = byte1;
    obj->requestedModeLock = byte2;
    flag = (compareByte & 0xFF) ^ obj->currentModeIndex;
    flag = (unsigned int)flag < 1;
    obj->modeAlreadySelected = flag;
    return result;
}

/**
 * @brief Internal: send handler of the main mode change sequence
 * 
 * Queues command 0x44 with the mode and lock bytes, then command 0x4D with
 * the actuator map.
 * 
 * @param arg0 Controller port state
 */
void func_8006A2A4(padPort *arg0) {
    int state = arg0->sequenceStep;

    switch (state) {
    case 2:
        arg0->command = 0x44;
        arg0->payload_2c = (unsigned char *)arg0 + 0x51;
        arg0->payload_2c_len = state;
        break;
    case 3:
        arg0->command = 0x4D;
        arg0->payload_2c = arg0->actuatorMap;
        arg0->payload_2c_len = 6;
        break;
    }
}

/**
 * @brief Internal: receive handler of the main mode change sequence
 * 
 * If the requested mode was already active the sequence just continues;
 * otherwise the port information is cleared so it is read again.
 * 
 * @param arg0 Controller port state
 * @return 1 to advance to the next step, 0 otherwise
 */
int func_8006A2F8(padPort *arg0) {
    if (arg0->modeAlreadySelected != 0) {
        if (arg0->sequenceStep == 2) {
            return 1;
        }

        arg0->sequenceStep = 0xFE;
        return 0;
    }

    _padFuncClrInfo(arg0);
    return 0;
}
/**
 * @brief Internal: queue command 0x43 (enter/exit configuration mode)
 * 
 * Sets the command byte to 0x43 with a single parameter byte.
 * 
 * @param obj Controller port state
 * @param value 1 = enter configuration mode, 0 = exit
 */
void _padCmdParaMode(padPort *obj, unsigned char value) {
    obj->command = 0x43;
    obj->payload_2c = (unsigned char *)obj + 0x24;
    obj->pad_24[0] = value;
    obj->payload_2c_len = 1;
}
/**
 * @brief Internal: queue command 0x45 (query controller status)
 * 
 * Sets the command byte to 0x45 without parameters.
 * 
 * @param obj Controller port state
 */
void func_8006A378(padPort *obj) {
    obj->command = 0x45;
    obj->payload_2c = 0;
    obj->payload_2c_len = 0;
}
/**
 * @brief Internal: queue command 0x4C (query mode ID)
 * 
 * Sets the command byte to 0x4C with a mode index parameter.
 * 
 * @param obj Controller port state
 * @param value Mode index
 */
void func_8006A38C(padPort *obj, unsigned char value) {
    obj->command = 0x4C;
    obj->payload_2c = (unsigned char *)obj + 0x24;
    obj->pad_24[0] = value;
    obj->payload_2c_len = 1;
}
/**
 * @brief Internal: queue command 0x46 (query actuator information)
 * 
 * Sets the command byte to 0x46 with an actuator index parameter.
 * 
 * @param obj Controller port state
 * @param value Actuator index
 */
void func_8006A3AC(padPort *obj, unsigned char value) {
    obj->command = 0x46;
    obj->payload_2c = (unsigned char *)obj + 0x24;
    obj->pad_24[0] = value;
    obj->payload_2c_len = 1;
}
/**
 * @brief Internal: queue command 0x47 (query actuator combination)
 * 
 * Sets the command byte to 0x47 with a combination index parameter.
 * 
 * @param obj Controller port state
 * @param value Combination index
 */
void func_8006A3CC(padPort *obj, unsigned char value) {
    obj->command = 0x47;
    obj->payload_2c = (unsigned char *)obj + 0x24;
    obj->pad_24[0] = value;
    obj->payload_2c_len = 1;
}
/**
 * @brief Internal: queue command 0x4B (continue reading combination data)
 * 
 * Sets the command byte to 0x4B without parameters. The exact meaning of
 * this controller command is uncertain.
 * 
 * @param obj Controller port state
 */
void func_8006A3EC(padPort *obj) {
    obj->command = 0x4B;
    obj->payload_2c = 0;
    obj->payload_2c_len = 0;
}
