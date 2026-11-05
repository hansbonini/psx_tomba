#include "common.h"
#include "padlocal.h"

/* CC1_FLAGS: -fno-cse-follow-jumps */
/* PSY-Q LIBPAD PADIF: func_8006A40C,
 * func_8006A44C, func_8006A524,
 * func_8006A5E4, func_8006A670. */

int func_8006A40C(padPort *port) {
    D_80097590 = _padFuncSendAuto(port);
    return _padSioRW(port, -2);
}

void func_8006A44C(padPort *obj) {
    if (_padSioChan == _padChanStart && _padGunExec != 0) {
        _padFuncGetGunPos();
        _padFuncSetGunPort();
    }

    if (D_80097590 != 0) {
        _padFuncSendAuto(obj->subPorts);
        _padFuncSendAuto(obj->subPorts + 1);
    }

    /* Read again for the argument: the original reloads the byte. */
    if (*(volatile u8*)&obj->command == 0) {
        func_8006979C(obj, 0x42);
    } else {
        func_8006979C(obj, obj->command);
    }
}

int func_8006A524(padPort *obj) {
    int result;
    int blockCount;
    int value;

    if (D_80097590 != 0) {
        _padFuncSendAuto(obj->subPorts + 2);
        _padFuncSendAuto(obj->subPorts + 3);
    }

    value = 0;
    if (obj->command == 0) {
        value = _padModeMtap;
    }

    result = func_8006979C(obj, value);
    if (result < 0) {
        return result;
    }
    if ((result & 0xF0) == 0) {
        return -9;
    }

    blockCount = (result & 0xF) << 1;
    D_80097588 = blockCount;
    if (blockCount == 0) {
        D_80097588 = 0x20;
    }
    return 0;
}

int func_8006A5E4(padPort *obj) {
    register padPort *card asm("$16");
    padPort *call_obj;
    int needs_ack;
    int value;
    register int result asm("$3");
    int ret;
    register u32 zero asm("$0");
    card = obj;
    needs_ack = 0;
    if ((card->response_3c[0] >> 4) == 8) {
        needs_ack = card->command < 1;
    }

    asm volatile("" : : : "$4");
    call_obj = card;
    value = _padFuncGetTxd(call_obj, needs_ack);
    call_obj = card;
    result = func_8006979C(call_obj, value & 0xFF);
    /* Match debt: architectural zero keeps the result copy in the first
     * branch delay slot; the barriers preserve the shared return path. */
        ret = 90;
    asm volatile("" : "=r"(ret) : "0"(ret));
    if (result == ret) {
        ret = result + zero;
        return ret;
    }
    ret = result + zero;
    asm volatile("" : "=r"(result), "=r"(ret) : "0"(result), "1"(ret));
    if (result != 0) {
    /* Retail returns -9 for positive values other than 90, and preserves
     * negative values. The BGEZ delay slot assigns -9 before branching. */
    ret = -9;
    if (result < 0) {
    ret = result;
    }
    }
done:
    return ret;
}

int func_8006A670(padPort *inPort) {
    register padPort *port = inPort;
    register int mode;
    register int index;
    register int offset;
    register padPort *other asm("$19");
    register int three;
    register int result;
    register padPort *arg;
    _padFuncCurrLimit(inPort);
    mode = 0;
    if (_padModeMtap) {
        register int id = port->response_3c[0];
        {
            register int eight = 8;
            if (id >> 4 == eight) {
                register int command = port->command;
                mode = command == 0;
            }
        }
    }
    if (mode) {
        index = -1;
        offset = -240;
        while (1) {
            if (--D_80097588 <= 0)
                break;
        /* Keep the incremented byte cursor: typed indexing changes scheduling. */
        if (index >= 0)
        {
            padAddr at;
            at.obj = port->subPorts;
            at.word += offset;
            _padFuncCurrLimit(at.obj);
        }
        result = func_8006979C(port, (u8)_padFuncGetTxd(port, 1));
        if (result < 0)
            return result;
        setRC2wait(60);
        if (!_padClrIntSio0())
            goto timeout;
        index++;
        offset += 240;
        if (index < 4)
                continue;
            break;
        }
    }
setup:
    {
        register int original = _padSioChan;
        register int opposite;
        opposite = !original;
        if (D_80097588 >= 2) {
            register int *count;
            register padAddr table;
            register int scaled;
            table.count = _padFixResult;
            scaled = opposite * 4;
            table.word = scaled + table.word;
            count = table.count;
            {
                register int product = opposite * 15;
                offset = product * 16;
            }
            three = 3;
            do {
                int remaining = *count;
                if (remaining < 0)
                    break;
                if (remaining > 0) {
                    /* Preserve the retail multiply and interior byte cursor. */
                    register int scaled;
                    register padAddr child asm("$3");
                    scaled = remaining * sizeof(padPort);
                    child.obj = _padInfoDir;
                    child.word = offset + child.word;
                    child.obj = child.obj->subPorts;
                    child.word += scaled;
                    other = child.obj - 1;
                    _padFuncRecvAuto(other);
                }
                {
                    register int value = *count;
                    if (value != three) {
                    if (value < 4) {
                        arg = port;
                        if (value >= 2)
                            goto call_transfer;
                        if (value < 0)
                            goto call_transfer;
                        goto primary;
                    }
                    arg = port;
                    if (value != 4)
                        goto call_transfer;
                    *count = three;
                    }
                    else
                    {
                paired:
                    do {
                    _padFuncRecvAuto(other - 1);
                    result = 1;
                    break;
                primary:
                    {
                        register padAddr base asm("$2");
                        base.obj = _padInfoDir;
                        other = (padPort *)(base.bytes + offset);
                    }
                    _padFuncRecvAuto(other);
                    _padFuncClrCmdNo(other);
                    result = -1;
                    } while (0);
                    *count = result;
                }
            transfer:
                arg = port;
                    }
            call_transfer:
                result = _padSioRW(port, (u8)_padFuncGetTxd(arg, mode));
                if (result < 0)
                    return result;
                setRC2wait(60);
                if (!_padClrIntSio0()) {
                timeout:
                    result = -3;
                    goto done;
                }
                --D_80097588;
            } while (D_80097588 >= 2);
        }
    }
    while (--D_80097588 > 0) {
        result = _padSioRW(port, (u8)_padFuncGetTxd(port, mode));
        if (result < 0)
            return result;
        setRC2wait(60);
        {
            int ready = _padClrIntSio0();
            if (!ready) {
                result = -3;
                return result;
            }
        }
    }
    func_80069A60();
    port->response_3c[port->response_index++] = *padif_sio;
    _padFuncNextPort(0);
    result = 0;
done:
    return result;
}

int D_80097588 = 0;
volatile u8* padif_sio = (volatile u8*)0x1F801040;
int D_80097590 = 0;
int (*padIntFunc[5])(void) = {
    (int (*)(void))func_8006A40C, (int (*)(void))func_8006A44C, (int (*)(void))func_8006A524,
    (int (*)(void))func_8006A5E4, (int (*)(void))func_8006A670,
};
