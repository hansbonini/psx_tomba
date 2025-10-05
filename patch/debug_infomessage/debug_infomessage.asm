.open "build/out/iso/us/SCUS_942.36",0x8000F800
.psx

.definelabel execDebug, 0x8001a954
.definelabel func_8001AC00, 0x8001AC00
.definelabel func_8001cf7c, 0x8001CF7C
.definelabel func_8001ce80, 0x8001CE80
.definelabel setEventComplete, 0x8001E31C
.definelabel fontdebugprintf, 0x80023AA4
.definelabel printInfoMessage, 0x80031124
.definelabel sprintf, 0x8005C38C
.definelabel d_8007b294, 0x8007B294
.definelabel d_8007b290, 0x8007B290
.definelabel d_8009b6a8, 0x8009B6A8
.definelabel d_8009eb4c, 0x8009EB4C
.definelabel game, 0x8009BCC8
.definelabel d_8009bcdc, 0x8009BCDC
.definelabel sprintf_buffer_msg, 0x800A1588

.org 0x8001ad58
.area 0x8001b2b0-.
  .importobj "build/patch/debug_infomessage/debug_infomessage.c.o"

  .notice "displayDebugScreen Empty space left: " + (0x8001b2b0-.) + " bytes"
  .fill 0x8001b2b0-.
.endarea

org 0x800462d8
  jal displayDebugScreen

.close
