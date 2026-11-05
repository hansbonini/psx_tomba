#include "common.h"
#include "psyq/libcd.h"

volatile s8* c005_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c005_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c005_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c005_cd_reg3 = (volatile s8*)0x1F801803;

extern int Stframe_no;
extern short Stsector_offset;
extern int StRgb24;
extern int StFunc1;
extern int StFunc2;
extern int StCHANNEL;
extern int CChannel;
extern int StEmu_Addr;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_005", StSetStream);
/**
 * @brief Set up CD-ROM streaming
 * 
 * Configures the frame range and the callbacks used during streaming
 * playback.
 * 
 * @param mode Bit 0: 1 = 24-bit color, 0 = 16-bit color
 * @param start_frame First frame number to read
 * @param end_frame Last frame number to read (0xFFFFFFFF = unlimited)
 * @param func1 Callback called whenever a frame has been completely read
 * @param func2 Callback called at the end of the stream (user data)
 */
void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)())
{
    StSetMask(1, start_frame, end_frame);
    StEmu_Addr = 0;
    StFunc1 = func1;
    StRgb24 = mode & 1;
    CChannel = 0;
    StCHANNEL = 0;
    Stsector_offset = 0;
    Stframe_no = 0;
    StFunc2 = func2;
}
