#include "common.h"
#include "psyq/libcd.h"

int D_80095F64[32] = {
    0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
};

extern CdlCB CD_cbsync;
extern s32 CD_debug;
extern CdlCB CD_cbready;
extern u8 CD_status;
extern CdlLOC CD_pos;
extern const char* CD_comstr[];
extern const char* CD_intstr[];
extern u8 CD_com;
extern u8 CD_mode;

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdStatus);
/**
 * @brief Get the last CD-ROM drive status
 * 
 * Returns the status byte received with the most recent command.
 * 
 * @return Drive status (CdlStatPlay, CdlStatShellOpen, ...)
 */
int CdStatus(void)
{
    return CD_status;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdMode);
/**
 * @brief Get the last CD-ROM mode set
 * 
 * Returns the mode byte sent with the most recent CdlSetmode.
 * 
 * @return Current CD-ROM mode
 */
int CdMode(void)
{
    return CD_mode;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdLastCom);
/**
 * @brief Get the last primitive command issued
 * 
 * Returns the code of the most recent command sent to the drive.
 * 
 * @return Command code
 */
int CdLastCom(void)
{
    return CD_com;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdLastPos);
/**
 * @brief Get the last position set with CdlSetloc
 * 
 * Returns a pointer to the internally stored target position.
 * 
 * @return Pointer to the last location
 */
CdlLOC* CdLastPos(void)
{
    return &CD_pos;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdReset);
/**
 * @brief Reset the CD-ROM subsystem
 * 
 * Mode 3 only reinstalls the interrupt handler. Otherwise the drive is
 * fully initialized and, in mode 1, the CD audio volume is also set.
 * 
 * @param mode 0 = reset, 1 = reset and initialize audio volume, 3 = reinstall interrupt handler only
 * @return 1 on success, 0 on failure
 */
int CdReset(int mode)
{
    if (mode == CdlModeAP) {
        CD_initintr();
        return 1;
    }
    if (CD_init()) {
        return 0;
    }
    if (mode == CdlModeDA && CD_initvol()) {
        return 0;
    }
    return 1;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdFlush);
/**
 * @brief Discard pending CD-ROM interrupts
 * 
 * Clears all pending CD-ROM interrupts and resets the command state.
 */
void CdFlush(void)
{
    CD_flush();
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdSetDebug);
/**
 * @brief Set the CD-ROM library debug level
 * 
 * Controls how much diagnostic text the library prints.
 * 
 * @param level 0 = none, 1 = errors, 2 = all commands
 * @return Previous debug level
 */
s32 CdSetDebug(s32 level) {
    s32 lastLevel;

    lastLevel = CD_debug;
    CD_debug = level;
    return lastLevel;
}


// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdComstr);
/**
 * @brief Get the name of a primitive command
 * 
 * Converts a command code to a printable string.
 * 
 * @param com Command code
 * @return Command name, or "none" if out of range
 */
char* CdComstr(u_char com)
{
    if (com >= 0x1c) {
        return "none";
    }
    return CD_comstr[com];
}


// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdIntstr);
/**
 * @brief Get the name of an interrupt type
 * 
 * Converts a CD-ROM interrupt type to a printable string.
 * 
 * @param intr Interrupt type
 * @return Interrupt name, or "none" if out of range
 */
char* CdIntstr(u_char intr) {
    if (intr >= 7) {
        return "none";
    }
    return CD_intstr[intr];
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdSync);
/**
 * @brief Wait for a primitive command to complete
 * 
 * Waits for (or checks) the completion of the last command issued with
 * CdControl().
 * 
 * @param mode 0 = wait for completion, 1 = return the current state immediately
 * @param result Buffer receiving the 8-byte result (may be NULL)
 * @return CdlComplete, CdlDiskError, CdlNoIntr (still running) or -1 on timeout
 */
int CdSync(int mode, u_char* result)
{
    return CD_sync(mode, result);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdReady);
/**
 * @brief Wait for CD-ROM data to become ready
 * 
 * Waits for (or checks) a DataReady/DataEnd event.
 * 
 * @param mode 0 = wait for the event, 1 = return the current state immediately
 * @param result Buffer receiving the 8-byte result (may be NULL)
 * @return CdlDataReady, CdlDataEnd, CdlDiskError, CdlNoIntr or -1 on timeout
 */
int CdReady(int mode, u_char* result) {
    return CD_ready(mode, result);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdSyncCallback);
/**
 * @brief Set the command completion callback
 * 
 * The callback is called from the interrupt handler when a primitive
 * command completes.
 * 
 * @param func New callback function (NULL to disable)
 * @return Previous callback function
 */
CdlCB CdSyncCallback(CdlCB func) {
    CdlCB old = CD_cbsync;
    CD_cbsync = func;
    return old;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdReadyCallback);
/**
 * @brief Set the data ready callback
 * 
 * The callback is called from the interrupt handler when sector data is
 * ready.
 * 
 * @param func New callback function (NULL to disable)
 * @return Previous callback function
 */
CdlCB CdReadyCallback(CdlCB func) {
    CdlCB old = CD_cbready;
    CD_cbready = func;
    return old;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdControl);
/**
 * @brief Internal: issue a primitive command with retries
 * 
 * Sends the command (preceded by CdlSetloc for commands that take a
 * position parameter), retrying up to four times and issuing a CdlNop
 * first if the shell was opened.
 * 
 * @param com Command code
 * @param param Parameter bytes (may be NULL)
 * @param result Result buffer (may be NULL)
 * @param arg3 Non-zero to not wait for the acknowledge
 * @return 0 on success, -1 on failure
 */
static inline int loop(u_char com, u_char* param, u_char* result, int arg3) {
    int i;
    CdlCB cbprev = CD_cbsync;
    for (i = 3; i != -1; --i) {
        CD_cbsync = 0;

        if (com != 1 && (CD_status & CdlStatShellOpen) != 0) {
            CD_cw(CdlNop, 0, 0, 0);
        }

        if (param == 0 || D_80095F64[com] == 0 ||
            CD_cw(CdlSetloc, param, result, 0) == 0) {
            CD_cbsync = cbprev;
            if (CD_cw(com, param, result, arg3) == 0) {
                return 0;
            }
        }
    }

    CD_cbsync = cbprev;
    return -1;
}

/**
 * @brief Issue a primitive command to the CD-ROM drive
 * 
 * Sends the command and waits for the acknowledge, but not for command
 * completion.
 * 
 * @param com Command code
 * @param param Parameter bytes (may be NULL)
 * @param result Buffer receiving the result (may be NULL)
 * @return 1 on success, 0 on failure
 */
int CdControl(u_char com, u_char* param, u_char* result) {
    return loop(com, param, result, 0) == 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdControlF);
/**
 * @brief Issue a primitive command without waiting for the acknowledge
 * 
 * Fast variant of CdControl() that returns as soon as the command is sent.
 * 
 * @param com Command code
 * @param param Parameter bytes (may be NULL)
 * @return 1 on success, 0 on failure
 */
int CdControlF(u_char com, u_char* param)
{

    return loop(com, param, NULL, 1) == 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdControlB);
/**
 * @brief Issue a primitive command and wait for completion
 * 
 * Blocking variant of CdControl() that also waits until the command
 * completes.
 * 
 * @param com Command code
 * @param param Parameter bytes (may be NULL)
 * @param result Buffer receiving the result (may be NULL)
 * @return 1 if the command completed successfully, 0 otherwise
 */
int CdControlB(u_char com, u_char* param, u_char* result)
{
    if (loop(com, param, result, 0) != 0) {
        return 0;
    }
    return CD_sync(0, result) == 2;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdMix);
/**
 * @brief Set the CD audio mixing volume
 * 
 * Sets the attenuation used to mix CD audio into the SPU.
 * 
 * @param vol Attenuation values
 * @return Always 1
 */
int CdMix(CdlATV* vol) {
    CD_vol(vol);
    return 1;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdGetSector);
/**
 * @brief Transfer data from the CD-ROM sector buffer
 * 
 * Copies data of the current sector into memory. Normally called from a
 * data ready callback.
 * 
 * @param madr Destination address
 * @param size Transfer size in 32-bit words
 * @return 1 on success
 */
int CdGetSector(void* madr, int size)
{
    return CD_getsector(madr, size) == 0;

}
// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdDataCallback);
/**
 * @brief Set the CD-ROM DMA completion callback
 * 
 * Registers a callback for DMA channel 3 (CD-ROM).
 * 
 * @param func New callback function (NULL to disable)
 * @return Previous callback function
 */
void(*CdDataCallback(void (*func)()))
{
    return DMACallback(3, func); 
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdDataSync);
/**
 * @brief Wait for the CD-ROM DMA transfer to finish
 * 
 * Waits for (or checks) the DMA transfer started by CdGetSector().
 * 
 * @param mode 0 = wait for completion, 1 = return immediately
 * @return Undefined (the result of the internal wait is not returned)
 */
int CdDataSync(int mode) {
    CD_datasync(mode);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdIntToPos);
/**
 * @brief Convert an absolute sector number to a CD-ROM position
 * 
 * Adds the 2-second lead-in and converts the sector number to BCD
 * minute/second/sector.
 * 
 * @param i Absolute sector number
 * @param p Receives the position
 * @return p
 */
CdlLOC* CdIntToPos(int i, CdlLOC* p) {
    inline int ENCODE_BCD(n) { return (((n / 10) << 4) + (n % 10)); };

    i += 150;
    p->sector = ENCODE_BCD(i % 75);
    p->second = ENCODE_BCD(i / 75 % 60);
    p->minute = ENCODE_BCD(i / 75 / 60);
    return p;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/sys", CdPosToInt);
/**
 * @brief Convert a CD-ROM position to an absolute sector number
 * 
 * Decodes the BCD minute/second/sector fields and subtracts the 2-second
 * lead-in.
 * 
 * @param p Position to convert
 * @return Absolute sector number
 */
int CdPosToInt(CdlLOC* p) {
    #define DECODE_BCD(x) (((x) >> 4) * 10 + ((x) & 0xF))

    u8 sector = p->sector;
    u8 second = p->second;
    u8 minute = p->minute;

    return (DECODE_BCD(minute) * 60 + DECODE_BCD(second)) * 75 +
           DECODE_BCD(sector) - 150;
}
