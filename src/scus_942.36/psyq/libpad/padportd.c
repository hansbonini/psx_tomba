#include "common.h"
#include "padlocal.h"

/* PSY-Q LIBPAD PADPORTD: PadInitDirect, func_8006AB4C,
 * func_8006ABB4, func_8006ACA8, func_8006ACB8,
 * func_8006AD74, func_8006AFF0, func_8006B028. */

int PadInitDirect(u8 *output0, u8 *output1) {
    u8 *savedOutput0 = output0;
    u8 *savedOutput1 = output1;
    register padPort *obj asm("$16");
    u8 *table3c;
    u8 *table40;
    int i;
    int fill;
    register u8 **field40 asm("$4");
    u8 *cursor;
    void (*swapCommand)(padPort *);
    padPort *clearObj;
    int count;

    D_80097548 = 0;
    D_8009755C = 0;
    _padInitDirSeq();

    obj = &D_8009B3A0[0];
    D_80097510 = func_8006ABB4;
    D_80097514 = func_8006AB4C;
    D_80097518 = func_8006ACB8;
    D_8009751C = func_8006AD74;
    D_80097520 = func_8006AFF0;
    D_80097524 = func_8006B028;
    swapCommand = func_8006ACA8;
    asm volatile("" : "=r"(clearObj) : "0"(obj));
    D_80097544 = obj;
    D_80097534 = swapCommand;

    bzero(clearObj, sizeof(padPort) * 2);
    i = 0;
    fill = 0xFF;
    field40 = &obj->statusBuffer;
    table40 = D_8009B358;
    table3c = D_8009B310;
    cursor = (u8 *)&obj[0].output_30;
    *(u8 **)cursor = savedOutput0;
    cursor = (u8 *)&obj[1].output_30;
    *(u8 **)cursor = savedOutput1;
    do {
        PADPORT_FROM_STATUS_BUFFER(field40)->subPorts = 0;
        PADPORT_FROM_STATUS_BUFFER(field40)->ownerPort = obj;
        PADPORT_FROM_STATUS_BUFFER(field40)->output_30[0] = fill;
        PADPORT_FROM_STATUS_BUFFER(field40)->output_30[1] = 0;
        PADPORT_FROM_STATUS_BUFFER(field40)->response_3c = table3c;
        *field40 = table40;
        cursor = obj->actuatorMap;
        count = 5;
        do {
            *cursor = fill;
            count--;
            cursor++;
        } while (count >= 0);
        table40 += 0x23;
        table3c += 0x23;
        i++;
        field40 = &PADPORT_FROM_STATUS_BUFFER(field40)[1].statusBuffer;
        obj++;
    } while (i < 2);

    _padSetVsyncParam();
    D_80097548 = 1;
    return 1;
}

void func_8006AB4C(padPort *arg0) {
    int count;
    int value;
    char *ptr;

    if (arg0->communicationState != 0) {
        ptr = (char *)arg0->actuatorMap;
        value = 0xFF;
        count = 5;
        arg0->communicationState = 0;
        arg0->sequenceStep = 0;
        arg0->currentExtendedId = 0;
        arg0->fn_14 = 0;
        arg0->fn_18 = 0;
        arg0->modeCount = 0;
        arg0->currentModeIndex = 0;
        arg0->currentExtendedId = 0;
        arg0->actuatorCount = 0;
        arg0->combinationCount = 0;
        arg0->modeTable = 0;
        arg0->capabilities = 0;
        arg0->combinations = 0;

        do {
            *ptr = value;
            count -= 1;
            ptr += 1;
        } while (count >= 0);
    }
}

int func_8006ABB4(int result) {
    register int callbackResult asm("$5") = result;
    padPort *objects;
    int ignoredResult;
    int *channelResults;
    padPort *obj;
    int index;
    padSio *control;
    int limit;
    int offset;
    int nextResult;
    int cleared;

    objects = &D_8009B3A0[0];
    ignoredResult = -9;
    channelResults = &D_80097568[0];

    do {
        index = D_80097550;
        offset = index * sizeof(padPort);
        obj = (padPort *)(offset + (int)objects);

        if (callbackResult != ignoredResult) {
            cleared = callbackResult == 0;
            if (cleared) {
                channelResults[index] = 0;
            } else {
                _dirFailAuto(obj);
                func_8006ACA8(obj);
            }
        }

        asm("" : "=r"(control), "=r"(index) : "0"(D_800975A8), "1"(D_80097550));
        D_80097554 = 0;
        asm volatile("" : : : "memory");
        control->ctrl = 0;
        limit = D_80097564;
        index += 1;
        D_80097550 = index;
        asm volatile("" : : : "memory");
        if (limit >= index) {
            nextResult = _padInitSioMode(
                (padPort *)((((index << 4) - index) << 4) + (int)objects));
        } else {
            nextResult = 1;
        }
        callbackResult = 0xFFFF;
        asm("" : "=r"(callbackResult) : "0"(callbackResult));
    } while (nextResult == 0);

    return nextResult;
}

void func_8006ACA8(padPort *obj) {
    u8 command;

    command = obj->command;
    obj->command = 0;
    obj->saved_command = command;
}

int func_8006ACB8(padPort *arg0, int needsAck) {
    int index;
    int mode;
    u8 *ptr;

    index = arg0->payload_index - 3;
    mode = arg0->command;
    if (mode != 0) {
        if (mode == 0x4D) {
            goto mode4D;
        }

    }
    else
    {
mode0:
    if (index < 6) {
        if (arg0->actuatorEnabled[index] == 0) {
            return 0;
        }
    }

    if (index >= arg0->payload_28_len) {
        return 0;
    }
    ptr = arg0->payload_28 + index;

load:
    asm volatile("" : "=r"(ptr) : "0"(ptr));
    return *ptr;

mode4D:
    if (index < arg0->payload_2c_len) {
        ptr = arg0->payload_2c + index;
        goto load;
    }
    return 0xFF;

    }
other:
    if (index >= arg0->payload_2c_len) {
        return 0;
    }
    return arg0->payload_2c[index];
}

void func_8006AD74(padPort *port) {
    register int limit, i, j, mask asm("$7"), active asm("$6");
    register int count;
    register int offset;
    register int one;
    register u8 *map, *data;
    bzero(port->actuatorEnabled, 6);
    if (port->currentExtendedId && port->payload_28) {
        limit = 6;
        if (port->payload_28_len < 7) {
            asm("" ::: "memory");
            limit = port->payload_28_len;
        }
        i = 0;
        if (port->actuatorCount) {
            one = 1;
            offset = 0;
            do {
                padAddr capability;
                active = 0;
                mask = 1;
                capability.capability = port->capabilities;
                capability.word = offset + capability.word;
                if (capability.capability->payloadBytes)
                    mask = 255;
                map = port->actuatorMap;
                data = port->payload_28;
                j = 0;
                if (limit) {
                    while (1) {
                        if (*map != i || !(*data & mask)) {
                            map++;
                            j++;
                            data++;
                            if (j < limit)
                                continue;
                        } else
                            goto selected;
                        break;
                    }
                }
            search_done:
                if (active) {
                    padAddr costRecord;
                    int total;
                    costRecord.capability = port->capabilities;
                    costRecord.word = offset + costRecord.word;
                    total = D_80097558 + costRecord.capability->activationCost;
                    if (total < 61)
                        D_80097558 = total;
                    else {
                        goto deny;
                    selected:
                        active = 1;
                        goto search_done;
                    deny:
                        active = 0;
                    }
                    if (active) {
                        map = port->actuatorMap;
                        data = port->actuatorEnabled;
                        j = 0;
                        if (limit)
                            do {
                                int same = *map == i;
                                map++;
                                if (same)
                                    *data = one;
                                j++;
                                data++;
                            } while (j < limit);
                    }
                }
                count = port->actuatorCount;
                asm("" : "=r"(i) : "0"(i), "r"(count));
                i++;
                offset += 5;
            } while (i < count);
        }
    } else {
        if (((unsigned)(port->currentId - 4) < 2 || port->currentId == 7) &&
            !port->currentExtendedId && port->payload_28_len >= 2) {
            if ((port->payload_28[0] & 192) == 64 && (port->payload_28[1] & 1) &&
                D_80097558 + 10 < 61) {
                port->actuatorEnabled[1] = 1;
                port->actuatorEnabled[0] = 1;
                D_80097558 += 10;
            }
        } else {
            asm("" ::: "memory");
            if (port->currentId == 3)
                port->actuatorEnabled[0] = 1;
            else if (!port->currentExtendedId) {
                register int value = 1;
                register int k asm("$3") = 5;
                /* Byte cursor over the object, offset by the flag index. */
                register padAddr cursor;
                cursor.obj = port;
                cursor.word += 5;
                do {
                    cursor.bytes[OFFSETOF(padPort, actuatorEnabled)] = value;
                    k--;
                    cursor.bytes--;
                } while (k >= 0);
            }
        }
    }
}

int func_8006AFF0(padPort *entry) {
    padPort *candidate;
    int index;
    int value;

    index = 0;
    value = 0x10;
    candidate = D_8009B3A0;
    for (; index < 2; index++) {
        if (entry == candidate) {
            return value;
        }
        value += 0x10;
        candidate += 1;
    }

    return 0xFF;
}

padPort *func_8006B028(int value) {
    padPort *entry = D_8009B3A0;

    if ((value & 0xF0) != 0) {
        entry += 1;
    }
    return entry;
}
