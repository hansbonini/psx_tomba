#include "common.h"
#include "psyq/libstamp.h"
#include "padlocal.h"

#if REGION == REGION_EU && VERSION == 1 && LANGUAGE != LANGUAGE_NONE
PsyqStamp libpad_stamp = PSYQ_STAMP(PSYQ_LIB_PAD, 4, 3, 1, 40, 0, 49, 24);
#else
PsyqStamp libpad_stamp = PSYQ_STAMP(PSYQ_LIB_PAD, 4, 2, 1, 34, 19, 12, 22);
#endif
int (*_padFuncNextPort)(int) = 0;
void (*_padFuncClrInfo)(padPort*) = 0;
int (*_padFuncGetTxd)(padPort*, int) = 0;
void (*_padFuncCurrLimit)(padPort*) = 0;
int (*_padFuncPtr2Port)(padPort*) = 0;
padPort* (*_padFuncPort2Info)(int) = 0;
int (*_padFuncSendAuto)(padPort*) = 0;
int (*_padFuncChkEng)() = 0;
void (*_padFuncRecvAuto)(padPort*) = 0;
void (*_padFuncClrCmdNo)(padPort*) = 0;
int (*_padFuncIntGun)(void) = 0;
void (*_padFuncSetGunPort)(void) = 0;
void (*_padFuncGetGunPos)(void) = 0;
padPort* _padInfoDir = 0;
int _padIntExec = 0;
int _padGunExec = 0;
int _padSioChan = 0;
int _padSioState = 0;
int _padTotalCurr = 0;
int _padModeMtap = 0;
int _padChanStart = 0;
int _padChanStop = 1;
int _padFixResult[2] = {-1, -1};
padIntr* padmain_istat = (padIntr*)0x1F801070;
padSio* padmain_sio = (padSio*)0x1F801040;
int D_80097578 = 0;
int D_8009757C[3] = {0};

int PadEnableCom(int mask)
{
    int old;
    register int frames asm("$2");
    register int* p1 asm("$18");
    int* p2;

    old = (_padChanStop << 1) | (_padChanStart == 0);
    if (old != mask) {
        _padIntExec = 0;

        if (mask & 1) {
            p1 = &D_8009B2F0[0];
            frames = *p1;
            _padChanStart = 0;
            if (frames >= 150) {
                _padFuncClrInfo(_padInfoDir);
            }
            *p1 = 0;
        } else {
            _padChanStart = 1;
        }

        if (mask & 2) {
            p2 = &D_8009B2F0[1];
            frames = *p2;
            _padChanStop = 1;
            if (frames >= 150) {
                _padFuncClrInfo(_padInfoDir + 1);
            }
            *p2 = 0;
        } else {
            _padChanStop = 0;
        }

        _padIntExec = 1;
    }

    return old;
}

void _padSetVsyncParam(void)
{
    void** handlers;

    handlers = (void**)&D_8009B2E0[1];
    asm volatile("" : "=r"(handlers) : "0"(handlers));
    handlers[0] = func_80069058;
    handlers[1] = func_80068FF0;
    handlers[-1] = 0;
    handlers[2] = 0;
}

int func_80068FF0(void)
{
    if (!(padmain_istat->mask & 1) || !(padmain_istat->stat & 1)) {
        return 0;
    }

    if (_padFuncIntGun != NULL) {
        _padFuncIntGun();
    }

    return 1;
}

int func_80069058(void)
{
    int idx;
    int last;
    int* frames;
    padPort* port;
    int cur;
    int next;

    cur = _padChanStart;
    next = 1;
    D_80097578 = next;
    if (cur != 0) {
        frames = &D_8009B2F0[0];
        cur = *frames;
        if (cur < 150) {
            next = cur + 1;
            *frames = next;
        }
    }

    if (_padChanStop == 0) {
        frames = &D_8009B2F0[1];
        cur = *frames;
        if (cur < 150) {
            next = cur + 1;
            *frames = next;
        }
    }

    if (_padIntExec != 0) {
        idx = _padChanStart;
        last = _padChanStop;
        if (last >= idx) {
            port = (padPort*)((int)_padInfoDir + (((idx << 4) - idx) << 4));
            _padSioState = 0;
            _padSioChan = idx;
            if (_padInitSioMode(port) == 0) {
                _padFuncNextPort(0xFFFF);
            }

            _padTotalCurr = 0;
            while (_padChanStop >= _padSioChan) {
                idx = _padSioChan;
                port = (padPort*)((int)_padInfoDir + (((idx << 4) - idx) << 4));
                func_800694FC(port);
            }

            padmain_sio->baud = 0x88;
        }
    }

    return 0;
}

int _padChkVsync(void)
{
    int old = D_80097578;

    D_80097578 = 0;
    return old;
}

void _padStartCom(void)
{
    _padIntExec = 0;
    EnterCriticalSection();
    SysDeqIntRP(2, D_8009B2E0);
    SysEnqIntRP(2, D_8009B2E0);
    padmain_istat->stat = ~1;
    padmain_istat->mask |= 1;
    ChangeClearRCnt(3, 0);
    ExitCriticalSection();
    _padFuncClrInfo(_padInfoDir);
    _padFuncClrInfo(_padInfoDir + 1);
    {
        register int* frames = D_8009B2F0;

        asm("" : "=r"(frames) : "0"(frames));
        frames[1] = 0;
        frames[0] = 0;
    }
    _padIntExec = 1;
}

void _padStopCom(void)
{
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, D_8009B2E0);
    ExitCriticalSection();
}

int _padInitSioMode(padPort* port)
{
    register padSio* sio = padmain_sio;
    sio->ctrl = 0x40;
    sio->ctrl = 0;
    sio->mode = 0xD;
    sio->baud = 0x88;
    setRC2wait(port->currentId == 8 ? 80 : 145);
    {
        int index = _padSioChan;
        {
            register padSio* regs = padmain_sio;
            register int control = 0x1003;
            if (index) {
                control = 0x3003;
            }
            regs->ctrl = control;
        }
        {
            register int* address asm("$1") = _padFixResult + index;
            register int remaining asm("$2") = *address;
            if (remaining >= 0) {
                if (remaining > 0) {
                    register int* counts = _padFixResult;
                    do {
                        padAddr count;
                        count.count = counts;
                        count.word = (_padSioChan * 4) + count.word;
                        (*count.count)--;
                        _padFuncRecvAuto(port->subPorts + *count.count);
                    } while (counts[_padSioChan] > 0);
                }
                {
                    register int index = _padSioChan;
                    register int* table asm("$3");
                    register int* count;
                    table = _padFixResult;
                    count = &table[index];
                    if (*count == 0) {
                        register int value asm("$3") = -1;
                        register padPort* arg asm("$4") = port;
                        void (*callback)(padPort*);
                        asm("" : : "r"(arg));
                        callback = _padFuncRecvAuto;
                        *count = value;
                        callback(arg);
                        _padFuncClrCmdNo(port);
                    }
                }
            }
        }
    }
    sio = padmain_sio;
    if (sio->stat & 0x200) {
        {
            register int control = sio->ctrl;
            sio->ctrl = control | 0x10;
        }
        if (sio->stat & 0x200) {
            sio->data = 1;
            func_80069A60();
            (void)padmain_sio->data;
            return 0;
        }
        padmain_istat->stat = ~0x80;
    }
    if (port->pad_50[0] && port->command) {
        return 0;
    }

    *port->response_3c = 0;
    return 1;
}

void func_800694FC(padPort* port)
{
    register int* index asm("$5") = &_padSioState;
    register int count;
    register int result;
    register int (*next)(void) asm("$2");
    count = *index;
    next = padIntFunc[count];
    *index = count + 1;
    result = next();
    if (result >= 0) {
        if (_padSioState) {
            setRC2wait(60);
            if (!_padClrIntSio0()) {
                _padFuncNextPort(-3);
            }
        }
        if (_padSioState >= 5) {
            _padSioState--;
        }
    } else {
        _padFuncNextPort(result);
    }
}

int _padSioRW(padPort* inObj, int inByte)
{
    register padPort* port = inObj;
    register int outgoing = inByte;
    u_char received;
    register int deviceId;
    register u_long baud;
    int replyByte;
    register int result asm("$2");

    if (outgoing < 0) {
        received = padmain_sio->data;
        port->response_index = 0xFF;
        port->payload_index = 1;
        *port->statusBuffer = ~outgoing;
        replyByte = received;
        if (!(padmain_sio->stat & 1)) {
            do {
            } while (!(padmain_sio->stat & 1));
        }
        do {
        } while (chkRC2wait() == 0);
        result = ~outgoing;
        padmain_sio->data = result;
        result = replyByte;
        return result;
    }
    {
        register int expected;
        {
            register u_char* response = port->response_3c;
            deviceId = *response;
        }
        expected = 8;
        baud = 0x88;
        if ((deviceId >> 4) == expected) {
            if ((u_char)port->response_index >= 9U) {
                baud = 0x22;
            }
        }
    }
    {
        register padSio* registers = padmain_sio;
        register u_long timer = *(volatile u_short*)0x1F801120;
        register u_long ready = registers->stat;
        register padSio* cursor;
        D_8009FD80 = 0x1AE;
        D_8009B6A4 = timer;
        if (!(ready & 2)) {
            cursor = registers;
            do {
            } while (!(cursor->stat & 2));
        } else {
            cursor = registers;
        }
    }
    {
        register padSio* sio = padmain_sio;
        register padIntr* irq = padmain_istat;
        received = sio->data;
        replyByte = received;
        sio->baud = baud;
        if (!(irq->stat & 0x80)) {
            do {
                if (chkRC2wait() != 0) {
                    result = -20;
                    return result;
                }
            } while ((padmain_istat->stat & 0x80) == 0);
        }
        padmain_sio->data = (u_char)outgoing;
        port->payload_index += 1;
        port->response_3c[port->response_index] = replyByte;
        result = port->response_index;
        result++;
        port->response_index = result;
        result = replyByte;
    }
    return result;
}

int func_8006979C(padPort* obj, int value)
{
    padSio* sio;
    padIntr* irq;
    volatile u_short* counter;
    volatile u_short* target;
    volatile u_short* mode;
    u_long start;
    u_long limit;
    u_long ticks;
    u_long wrap;
    int baud;
    int received;
    int first_byte;
    u_short poll_status;

    first_byte = obj->response_3c[0];
    baud = 0x88;
    if ((first_byte >> 4) == 8 && obj->response_index >= 9) {
        baud = 0x22;
    }

    {
        padSio* ready_sio = padmain_sio;
        do {
            poll_status = ready_sio->stat;
        } while ((poll_status & 2) == 0);
    }
    setRC2wait(400);

    sio = padmain_sio;
    received = sio->data;
    if (obj->response_index != 0 || (received >> 4) != 8) {
        sio->baud = baud;
    } else {
        sio->baud = 0x22;
    }

    irq = padmain_istat;
    if (!(irq->stat & 0x80)) {
        register padIntr* poll_irq;
        counter = (volatile u_short*)0x1F801120;
        target = (volatile u_short*)0x1F801128;
        wrap = 0x10000;
        mode = (volatile u_short*)0x1F801124;
        poll_irq = irq;
        start = D_8009B6A4;
        limit = D_8009FD80;
        do {
            ticks = *counter;
            if (ticks < start) {
                if (*target != 0) {
                    ticks += *target;
                } else {
                    ticks += wrap;
                }
            }
            if (*mode & 0x200) {
                if (ticks - start >= limit) {
                    return -2;
                }
            }
            if (((ticks - start) >> 3) >= limit) {
                return -2;
            }
        } while (!(poll_irq->stat & 0x80));
    }

    if (obj->currentId != 8 && _padSioState == 2) {
        setRC2wait(60);
        while (!chkRC2wait()) {
        }
    }

    padmain_sio->data = value;
    obj->payload_index++;
    if (obj->response_index != 0xFF) {
        /* The response cursor is read again after the payload update. */
        asm volatile("" ::: "memory");
        obj->response_3c[obj->response_index] = received;
    }
    obj->response_index++;
    return received;
}

int _padClrIntSio0(void)
{
    padmain_istat->stat = ~0x80;

    while (padmain_sio->stat & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }

    padmain_sio->ctrl |= 0x10;
    return 1;
}

void func_80069A60(void)
{
    while (!(padmain_sio->stat & 2)) {
    }
}

__asm__("nop");
