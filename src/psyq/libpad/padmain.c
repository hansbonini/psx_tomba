#include "common.h"
#include "padlocal.h"

extern u8 func_8006A40C_x[] asm("func_8006A40C");
extern u8 func_8006A44C_x[] asm("func_8006A44C");
extern u8 func_8006A524_x[] asm("func_8006A524");
extern u8 func_8006A5E4_x[] asm("func_8006A5E4");
extern u8 func_8006A670_x[] asm("func_8006A670");

u32 D_80097518_d[1] asm("D_80097518") = {
    0x00000000,
};
u32 D_8009751C_d[1] asm("D_8009751C") = {
    0x00000000,
};
u32 D_80097520_d[1] asm("D_80097520") = {
    0x00000000,
};
u32 D_80097524_d[1] asm("D_80097524") = {
    0x00000000,
};
u32 D_80097528_d[1] asm("D_80097528") = {
    0x00000000,
};
u32 D_8009752C_d[1] asm("D_8009752C") = {
    0x00000000,
};
u32 D_80097530_d[1] asm("D_80097530") = {
    0x00000000,
};
u32 D_80097534_d[1] asm("D_80097534") = {
    0x00000000,
};
u32 D_80097538_d[1] asm("D_80097538") = {
    0x00000000,
};
u32 D_8009753C_d[1] asm("D_8009753C") = {
    0x00000000,
};
u32 D_80097540_d[1] asm("D_80097540") = {
    0x00000000,
};
u32 D_80097544_d[1] asm("D_80097544") = {
    0x00000000,
};
u32 D_80097548_d[1] asm("D_80097548") = {
    0x00000000,
};
u32 D_8009754C_d[1] asm("D_8009754C") = {
    0x00000000,
};
u32 D_80097550_d[1] asm("D_80097550") = {
    0x00000000,
};
u32 D_80097554_d[1] asm("D_80097554") = {
    0x00000000,
};
u32 D_80097558_d[1] asm("D_80097558") = {
    0x00000000,
};
u32 D_8009755C_d[1] asm("D_8009755C") = {
    0x00000000,
};
u32 D_80097560_d[1] asm("D_80097560") = {
    0x00000000,
};
u32 D_80097564_d[1] asm("D_80097564") = {
    0x00000001,
};
u32 D_80097568_d[2] asm("D_80097568") = {
    0xFFFFFFFF, 0xFFFFFFFF,
};
u32 D_80097570_d[1] asm("D_80097570") = {
    0x1F801070,
};
u32 D_80097574_d[1] asm("D_80097574") = {
    0x1F801040,
};
u32 D_80097578_d[4] asm("D_80097578") = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
u32 D_80097588_d[1] asm("D_80097588") = {
    0x00000000,
};
u32 D_8009758C_d[1] asm("D_8009758C") = {
    0x1F801040,
};
u32 D_80097590_d[1] asm("D_80097590") = {
    0x00000000,
};
u32 D_80097594_d[5] asm("D_80097594") = {
    (u32)func_8006A40C_x, (u32)func_8006A44C_x, (u32)func_8006A524_x, (u32)func_8006A5E4_x,
    (u32)func_8006A670_x,
};

int PadEnableCom(int mask)
{
    int old;
    register int frames asm("$2");
    register int* p1 asm("$18");
    int* p2;

    old = (D_80097564 << 1) | (D_80097560 == 0);
    if (old != mask) {
        D_80097548 = 0;

        if (mask & 1) {
            p1 = &D_8009B2F0[0];
            frames = *p1;
            D_80097560 = 0;
            if (frames >= 150) {
                D_80097514(D_80097544);
            }
            *p1 = 0;
        } else {
            D_80097560 = 1;
        }

        if (mask & 2) {
            p2 = &D_8009B2F0[1];
            frames = *p2;
            D_80097564 = 1;
            if (frames >= 150) {
                D_80097514(D_80097544 + 1);
            }
            *p2 = 0;
        } else {
            D_80097564 = 0;
        }

        D_80097548 = 1;
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
    if (!(D_80097570->mask & 1) || !(D_80097570->stat & 1)) {
        return 0;
    }

    if (D_80097538 != NULL) {
        D_80097538();
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

    cur = D_80097560;
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

    if (D_80097564 == 0) {
        frames = &D_8009B2F0[1];
        cur = *frames;
        if (cur < 150) {
            next = cur + 1;
            *frames = next;
        }
    }

    if (D_80097548 != 0) {
        idx = D_80097560;
        last = D_80097564;
        if (last >= idx) {
            port = (padPort*)((int)D_80097544 + (((idx << 4) - idx) << 4));
            D_80097554 = 0;
            D_80097550 = idx;
            if (_padInitSioMode(port) == 0) {
                D_80097510(0xFFFF);
            }

            D_80097558 = 0;
            while (D_80097564 >= D_80097550) {
                idx = D_80097550;
                port = (padPort*)((int)D_80097544 + (((idx << 4) - idx) << 4));
                func_800694FC(port);
            }

            D_80097574->baud = 0x88;
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
    D_80097548 = 0;
    EnterCriticalSection();
    SysDeqIntRP(2, D_8009B2E0);
    SysEnqIntRP(2, D_8009B2E0);
    D_80097570->stat = ~1;
    D_80097570->mask |= 1;
    ChangeClearRCnt(3, 0);
    ExitCriticalSection();
    D_80097514(D_80097544);
    D_80097514(D_80097544 + 1);
    {
        register int* frames = D_8009B2F0;

        asm("" : "=r"(frames) : "0"(frames));
        frames[1] = 0;
        frames[0] = 0;
    }
    D_80097548 = 1;
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
    register padSio* sio = D_80097574;
    sio->ctrl = 0x40;
    sio->ctrl = 0;
    sio->mode = 0xD;
    sio->baud = 0x88;
    setRC2wait(port->currentId == 8 ? 80 : 145);
    {
        int index = D_80097550;
        {
            register padSio* regs = D_80097574;
            register int control = 0x1003;
            if (index) {
                control = 0x3003;
            }
            regs->ctrl = control;
        }
        {
            register int* address asm("$1") = D_80097568 + index;
            register int remaining asm("$2") = *address;
            if (remaining >= 0) {
                if (remaining > 0) {
                    register int* counts = D_80097568;
                    do {
                        padAddr count;
                        count.count = counts;
                        count.word = (D_80097550 * 4) + count.word;
                        (*count.count)--;
                        D_80097530(port->subPorts + *count.count);
                    } while (counts[D_80097550] > 0);
                }
                {
                    register int index = D_80097550;
                    register int* table asm("$3");
                    register int* count;
                    table = D_80097568;
                    count = &table[index];
                    if (*count == 0) {
                        register int value asm("$3") = -1;
                        register padPort* arg asm("$4") = port;
                        void (*callback)(padPort*);
                        asm("" : : "r"(arg));
                        callback = D_80097530;
                        *count = value;
                        callback(arg);
                        D_80097534(port);
                    }
                }
            }
        }
    }
    sio = D_80097574;
    if (sio->stat & 0x200) {
        {
            register int control = sio->ctrl;
            sio->ctrl = control | 0x10;
        }
        if (sio->stat & 0x200) {
            sio->data = 1;
            func_80069A60();
            (void)D_80097574->data;
            return 0;
        }
        D_80097570->stat = ~0x80;
    }
    if (port->pad_50[0] && port->command) {
        return 0;
    }

    *port->response_3c = 0;
    return 1;
}

void func_800694FC(padPort* port)
{
    register int* index asm("$5") = &D_80097554;
    register int count;
    register int result;
    register int (*next)(void) asm("$2");
    count = *index;
    next = D_80097594[count];
    *index = count + 1;
    result = next();
    if (result >= 0) {
        if (D_80097554) {
            setRC2wait(60);
            if (!_padClrIntSio0()) {
                D_80097510(-3);
            }
        }
        if (D_80097554 >= 5) {
            D_80097554--;
        }
    } else {
        D_80097510(result);
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
        received = D_80097574->data;
        port->response_index = 0xFF;
        port->payload_index = 1;
        *port->statusBuffer = ~outgoing;
        replyByte = received;
        if (!(D_80097574->stat & 1)) {
            do {
            } while (!(D_80097574->stat & 1));
        }
        do {
        } while (chkRC2wait() == 0);
        result = ~outgoing;
        D_80097574->data = result;
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
        register padSio* registers = D_80097574;
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
        register padSio* sio = D_80097574;
        register padIntr* irq = D_80097570;
        received = sio->data;
        replyByte = received;
        sio->baud = baud;
        if (!(irq->stat & 0x80)) {
            do {
                if (chkRC2wait() != 0) {
                    result = -20;
                    return result;
                }
            } while ((D_80097570->stat & 0x80) == 0);
        }
        D_80097574->data = (u_char)outgoing;
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
        padSio* ready_sio = D_80097574;
        do {
            poll_status = ready_sio->stat;
        } while ((poll_status & 2) == 0);
    }
    setRC2wait(400);

    sio = D_80097574;
    received = sio->data;
    if (obj->response_index != 0 || (received >> 4) != 8) {
        sio->baud = baud;
    } else {
        sio->baud = 0x22;
    }

    irq = D_80097570;
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

    if (obj->currentId != 8 && D_80097554 == 2) {
        setRC2wait(60);
        while (!chkRC2wait()) {
        }
    }

    D_80097574->data = value;
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
    D_80097570->stat = ~0x80;

    while (D_80097574->stat & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }

    D_80097574->ctrl |= 0x10;
    return 1;
}

void func_80069A60(void)
{
    while (!(D_80097574->stat & 2)) {
    }
}

__asm__("nop");
