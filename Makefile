# Adapted from https://github.com/Vatuu/silent-hill-decomp/tree/master

# Configuration
BUILD_OVERLAYS ?= 1
NON_MATCHING   ?= 0
SKIP_ASM       ?= 0
# Executable serial: scus_942.36 (US), slps_011.44 (JP), sces_013.30 and
# sces_013.31 (EU). The disc of each one is extracted to iso/<serial>.
VERSION        ?= scus_942.36
VERSIONS       := scus_942.36 slps_011.44 sces_013.30 sces_013.31

# Names and Paths
ifeq ($(filter $(VERSION),$(VERSIONS)),)
  $(error Invalid VERSION specified: $(VERSION) (one of: $(VERSIONS)))
endif
GAME_NAME    := $(shell echo $(VERSION) | tr a-z A-Z)
BASE_DIR     := $(VERSION)
ROM_DIR      := iso/$(VERSION)
CONFIG_DIR   := config/$(BASE_DIR)
LINKER_DIR   := linker/$(BASE_DIR)
BUILD_DIR    := build/$(VERSION)
OUT_DIR      := build/out
TOOLS_DIR    := tools
OBJDIFF_DIR  := $(TOOLS_DIR)/objdiff
PERMUTER_DIR := permuter
ASSETS_DIR   := assets
ASM_DIR      := asm
C_DIR        := src
EXPECTED_DIR := expected

# Tools
CROSS   := mips-linux-gnu
AS      := $(CROSS)-as
LD      := $(CROSS)-ld
OBJCOPY := $(CROSS)-objcopy
OBJDUMP := $(CROSS)-objdump
CPP     := $(CROSS)-cpp
CC      := $(TOOLS_DIR)/gcc-2.7.2-psx/cc1
OBJDIFF := $(OBJDIFF_DIR)/objdiff

PYTHON          := python3
SPLAT           := splat split
MASPSX          := $(PYTHON) $(TOOLS_DIR)/maspsx/maspsx.py
ARMIPS          := $(TOOLS_DIR)/armips/armips
GET_YAML_TARGET := $(PYTHON) $(TOOLS_DIR)/get_yaml_target.py

# Flags
OPT_FLAGS           := -O2
ENDIAN              := -EL
INCLUDE_FLAGS       := -Iinclude -I $(BUILD_DIR)
DEFINE_FLAGS        := -D_LANGUAGE_C -DUSE_INCLUDE_ASM -DVERSION_$(subst .,,$(GAME_NAME))
CPP_FLAGS           := $(INCLUDE_FLAGS) $(DEFINE_FLAGS) -P -MP -undef -Wall -lang-c -nostdinc
LD_FLAGS            := $(ENDIAN) $(OPT_FLAGS) -nostdlib --no-check-sections
OBJCOPY_FLAGS       := -O binary
OBJDUMP_FLAGS       := --disassemble-all --reloc --disassemble-zeroes -Mreg-names=32
SPLAT_FLAGS         := --disassemble-all --make-full-disasm-for-code
DL_FLAGS := -G0
AS_FLAGS := $(ENDIAN) $(INCLUDE_FLAGS) $(OPT_FLAGS) $(DL_FLAGS) -march=r3000 -mtune=r3000 -no-pad-sections
CC_FLAGS := $(OPT_FLAGS) $(DL_FLAGS) -mips1 -mcpu=3000 -funsigned-char -gcoff -quiet

# Bios functions obj:number
BIOS_FUNCS := 	a07:B07 a08:B08 a09:B09 a10:B0A a11:B0B 	\
				a12:B0C a13:B0D a14:B0E a15:B0F a16:B10 	\
				a23:B17 a24:B18 a25:B19 a36:1 a37:2 		\
				a50:B32 a51:B33 a52:B34 a53:B35 a54:B36 	\
				a65:B41 a66:B42 a67:B43 a69:B45 a74:B4A 	\
				a75:B4B a76:B4C a78:B4E a80:B50 a91:B5B 	\
				a94:A94 c112:A70 c171:AAB c172:AAC c68:A44 	\
				c73:A49 l10:C0A

# Generate object paths
BIOS_OBJS := $(foreach f,$(BIOS_FUNCS), \
						 $(BUILD_DIR)/src/psyq/libapi/$(word 1,$(subst :, ,$f)).hasm.s.o)


# Map function obj to BIOS fn number
bios_num = $(word 2,$(subst :, ,$(filter $(notdir $1):%,$(BIOS_FUNCS))))

# PSY-Q libraries uses ASPSX 2.56 (PSQ 4.0)
# Archive library code uses GCC 2.6.0.
# Main-related and psyq code seem to use -G0 instead of -G8
define DL_FlagsSwitch
	$(eval MASPSX_FLAGS = --aspsx-version=2.56 --expand-div --use-comm-section --run-assembler $(AS_FLAGS))

	$(eval AS_FLAGS := $(ENDIAN) $(INCLUDE_FLAGS) $(OPT_FLAGS) $(DL_FLAGS) -march=r3000 -mtune=r3000 -no-pad-sections)
	$(eval CC_FLAGS := $(OPT_FLAGS) $(DL_FLAGS) -mips1 -mcpu=3000 -funsigned-char -gcoff -fverbose-asm -quiet)
endef

ifeq ($(NON_MATCHING),1)
	CPP_FLAGS := $(CPP_FLAGS) -DNON_MATCHING
endif

ifeq ($(SKIP_ASM),1)
	CPP_FLAGS := $(CPP_FLAGS) -DSKIP_ASM
endif

# Utils

# Function to find matching .s files for a target name.
find_s_files = $(shell find $(ASM_DIR)/$(strip $1) -type f -path "*.s" -not -path "asm/*matchings*" \
                     $(if $(findstring /,$1),,-not -path "*/overlays/*" -not -path "*/exe/*") 2> /dev/null)

# Function to find matching .c files for a target name.
find_c_files = $(shell find $(C_DIR)/$(strip $1) -type f -path "*.c" \
                     $(if $(findstring /,$1),,-not -path "*/overlays/*" -not -path "*/exe/*") 2> /dev/null)

# Function to list the objects of a target: the ones its linker script uses.
gen_o_files = $(shell grep -oE '$(BUILD_DIR)/[^ ()]*\.o' $(LINKER_DIR)/$(notdir $1).ld 2> /dev/null | sort -u)

# get_target_out = $(addprefix $(OUT_DIR)/,$1)

# Function to get path to .yaml file for given target.
get_yaml_path = $(addsuffix .yaml,$(addprefix $(CONFIG_DIR)/,$(notdir $1)))

# Function to get target output path for given target.
get_target_out = $(addprefix $(OUT_DIR)/,$(shell $(GET_YAML_TARGET) $(call get_yaml_path,$1)))

# Template definition for elf target.
# First parameter should be source target with folder (e.g. screens/credits).
# Second parameter should be end target (e.g. build/VIN/STF_ROLL.BIN).
# If we skip the ASM inclusion to determine progress, we will not be able to link. Skip linking, if so.

ifeq ($(SKIP_ASM),1)

define make_elf_target
$2: $2.elf
$2.elf: $(call gen_o_files, $1) \
		$(BIOS_OBJS)
endef

else

define make_elf_target
$2: $2.elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $$< $$@

$2.elf: $(call gen_o_files, $1)
	@mkdir -p $(dir $2)
	$(LD) $(LD_FLAGS) \
		-Map $2.map \
		-T $(LINKER_DIR)/$(notdir $1).ld \
		-T $(LINKER_DIR)/undefined_syms_auto.$(notdir $1).txt \
		-T $(LINKER_DIR)/undefined_funcs_auto.$(notdir $1).txt \
		$(if $(MANUAL_SYMS),-T $(MANUAL_SYMS)) \
		$(foreach f,$(wildcard $(SYMBOLS_DIR)/$(notdir $1)_undefined_syms.txt),-T $f) \
		-o $$@
endef

endif

# Targets
TARGET_MAIN := $(BASE_DIR)

ifeq ($(BUILD_OVERLAYS)$(VERSION), 1scus_942.36)
TARGET_OVERLAYS := scus_942.36/overlays/optsub00 scus_942.36/overlays/x00 \
                   $(foreach n,01 02 03 04 05 06 08 09 10 11 13 14 16 17 18,scus_942.36/overlays/x$(n))
endif

# The European discs boot a language menu (SCES_013.3x); the game itself is
# EXE/MAIN0.EXE .. MAIN8.EXE, one per language.
ifneq ($(filter sces_013.30 sces_013.31,$(VERSION)),)
TARGET_OVERLAYS += $(foreach n,0 1 2 3 4 5 6 7 8,$(BASE_DIR)/exe/main$(n))
endif

# Source Definitions
TARGET_IN  := $(TARGET_MAIN) $(TARGET_OVERLAYS)

# The sources in src/ are shared by every release; INCLUDE_ASM names a path
# under the asm folder of the executable, given to the assembler with -I.
# Each European MAINn.EXE has its own asm and build folders.
# build folder:asm folder
TARGET_BUILDS := $(BUILD_DIR):$(ASM_DIR)/$(BASE_DIR) \
                 $(foreach t,$(TARGET_OVERLAYS),$(if $(findstring /exe/,$t),$(BUILD_DIR)/exe/$(notdir $t):$(ASM_DIR)/$t))
TARGET_OUT := $(foreach target,$(TARGET_IN),$(call get_target_out,$(target)))
SYMBOLS_DIR  := symbols/$(BASE_DIR)
SYMBOL_FILES := $(wildcard $(SYMBOLS_DIR)/*.txt)
MANUAL_SYMS  := $(wildcard $(SYMBOLS_DIR)/undefined_syms.txt)
LD_FILES     := $(addsuffix .ld,$(addprefix $(LINKER_DIR)/,$(notdir $(TARGET_IN))))

# Rules
default: all

all: build

build: $(TARGET_OUT)

objdiff-config: regenerate
	@$(MAKE) NON_MATCHING=1 SKIP_ASM=1 expected
	@$(PYTHON) $(OBJDIFF_DIR)/objdiff_generate.py $(OBJDIFF_DIR)/config.yaml

report: objdiff-config
	@$(OBJDIFF) report generate > $(BUILD_DIR)/progress.json

check: build
	@sha256sum --ignore-missing --check $(CONFIG_DIR)/checksum.sha

expected: build
	mkdir -p $(EXPECTED_DIR)
	mv $(BUILD_DIR)/asm $(EXPECTED_DIR)
	mv $(EXPECTED_DIR)/asm/$(TARGET_MAIN)/psyq/libapi/c73.s.o $(EXPECTED_DIR)/asm/$(TARGET_MAIN)/psyq/libgpu/c73.s.o
	mv $(EXPECTED_DIR)/asm/$(TARGET_MAIN)/psyq/libapi/a07.s.o $(EXPECTED_DIR)/asm/$(TARGET_MAIN)/psyq/libcd/a07.s.o

generate: $(LD_FILES)

clean:
	rm -rf $(BUILD_DIR)

reset: clean
	rm -rf $(ASM_DIR)
	rm -rf $(LINKER_DIR)
	rm -rf $(EXPECTED_DIR)

setup: reset
	$(MAKE) generate

regenerate: reset
	$(MAKE) generate

clean-build: clean
	rm -rf $(LINKER_DIR)
	$(MAKE) generate
	$(MAKE) build

### decomp-permuter
# https://github.com/simonlindholm/decomp-permuter
#
#   make permuter-setup
#   make permuter-import FUNC=func_80016F5C SRC=src/scus_942.36/main/main.c
#   make permuter-run    FUNC=func_80016F5C
#
PERMUTER       := $(TOOLS_DIR)/decomp-permuter
PERMUTER_JOBS  ?= 4
permuter_asm    = $(shell find $(ASM_DIR)/$(BASE_DIR)/nonmatchings -name '$(1).s' -print -quit)

permuter-setup:
	@test -d $(PERMUTER) || git clone --depth 1 https://github.com/simonlindholm/decomp-permuter $(PERMUTER)
	@# distros PEP 668 (Ubuntu 24.04+) recusam o install global; cai para --user
	$(PYTHON) -m pip install --upgrade pynacl toml Levenshtein \
	  || $(PYTHON) -m pip install --upgrade --user pynacl toml Levenshtein \
	  || $(PYTHON) -m pip install --upgrade --user --break-system-packages pynacl toml Levenshtein

permuter-import:
	@test -n "$(FUNC)" || { echo 'usage: make permuter-import FUNC=<function> SRC=<file.c>'; exit 1; }
	@test -n "$(SRC)"  || { echo 'usage: make permuter-import FUNC=<function> SRC=<file.c>'; exit 1; }
	@test -d $(PERMUTER) || { echo 'missing $(PERMUTER); run: make permuter-setup'; exit 1; }
	@test -n "$(call permuter_asm,$(FUNC))" || { echo 'asm for $(FUNC) not found in $(ASM_DIR)/$(BASE_DIR)/nonmatchings'; exit 1; }
	@mkdir -p $(PERMUTER_DIR)/$(FUNC)
	$(MAKE) $(BUILD_DIR)/$(SRC:.c=.i)
	cp $(BUILD_DIR)/$(SRC:.c=.i) $(PERMUTER_DIR)/$(FUNC)/base.c
	$(PYTHON) $(PERMUTER)/strip_other_fns.py $(PERMUTER_DIR)/$(FUNC)/base.c $(FUNC)
	@printf '.include "include/macro.inc"\n.set noat\n.set noreorder\n' > $(PERMUTER_DIR)/$(FUNC)/target.s
	@cat $(call permuter_asm,$(FUNC)) >> $(PERMUTER_DIR)/$(FUNC)/target.s
	$(AS) $(AS_FLAGS) -o $(PERMUTER_DIR)/$(FUNC)/target.o $(PERMUTER_DIR)/$(FUNC)/target.s
	@install -m 755 $(TOOLS_DIR)/permuter_compile.sh $(PERMUTER_DIR)/$(FUNC)/compile.sh
	@{ \
	  echo 'func_name = "$(FUNC)"'; \
	  echo 'compiler_type = "gcc"'; \
	  echo ''; \
	  echo '[weight_overrides]'; \
	  echo 'perm_reorder_stmts = 0'; \
	  echo 'perm_duplicate_assignment = 0'; \
	  echo 'perm_ins_block = 0'; \
	  echo 'perm_var_cond_block = 0'; \
	  echo 'perm_remove_var = 0'; \
	  echo 'perm_remove_ast = 0'; \
	} > $(PERMUTER_DIR)/$(FUNC)/settings.toml
	@echo '==> $(PERMUTER_DIR)/$(FUNC) ready; run: make permuter-run FUNC=$(FUNC)'

permuter-run:
	@test -n "$(FUNC)" || { echo 'usage: make permuter-run FUNC=<function>'; exit 1; }
	@test -d $(PERMUTER_DIR)/$(FUNC) || { echo 'run first: make permuter-import FUNC=$(FUNC) SRC=<file.c>'; exit 1; }
	$(PYTHON) $(PERMUTER)/permuter.py -j $(PERMUTER_JOBS) $(PERMUTER_DIR)/$(FUNC)

# make permuter-reseed FUNC=func_80016F5C OUT=output-345-2
permuter-reseed:
	@test -n "$(FUNC)" || { echo 'usage: make permuter-reseed FUNC=<function> OUT=<output-dir>'; exit 1; }
	@test -n "$(OUT)"  || { echo 'usage: make permuter-reseed FUNC=<function> OUT=<output-dir>'; exit 1; }
	@test -f $(PERMUTER_DIR)/$(FUNC)/$(OUT)/source.c || { echo 'not found: $(PERMUTER_DIR)/$(FUNC)/$(OUT)/source.c'; exit 1; }
	cp $(PERMUTER_DIR)/$(FUNC)/base.c $(PERMUTER_DIR)/$(FUNC)/base.c.bak
	cp $(PERMUTER_DIR)/$(FUNC)/$(OUT)/source.c $(PERMUTER_DIR)/$(FUNC)/base.c
	rm -rf $(PERMUTER_DIR)/$(FUNC)/output-*
	@echo '==> base.c reseeded from $(OUT) (backup in base.c.bak)'
	@echo '==> run: make permuter-run FUNC=$(FUNC)'

permuter-clean:
	rm -rf $(PERMUTER_DIR)

patch_debug_sfx: build
	rm -rf $(BUILD_DIR)/patch/debug_sfx
	mkdir -p $(BUILD_DIR)/patch/debug_sfx
	$(CPP) -P -MMD -MP -MT patch/debug_sfx/debug_sfx/temp1.i -MF build/patch/debug_sfx/debug_sfx.i.d $(CPP_FLAGS) -o build/patch/debug_sfx/debug_sfx.i patch/debug_sfx/debug_sfx.c
	$(CC) $(CC_FLAGS) -o build/patch/debug_sfx/debug_sfx.c.s build/patch/debug_sfx/debug_sfx.i
	$(call DL_FlagsSwitch, build/patch/debug_sfx/debug_sfx.c.o)
	$(MASPSX) $(MASPSX_FLAGS) -o build/patch/debug_sfx/debug_sfx.c.o build/patch/debug_sfx/debug_sfx.c.s
	$(ARMIPS) patch/debug_sfx/debug_sfx.asm

patch_debug_event: build
	rm -rf $(BUILD_DIR)/patch/debug_event
	mkdir -p $(BUILD_DIR)/patch/debug_event
	$(CPP) -P -MMD -MP -MT patch/debug_event/debug_event/temp1.i -MF build/patch/debug_event/debug_event.i.d $(CPP_FLAGS) -o build/patch/debug_event/debug_event.i patch/debug_event/debug_event.c
	$(CC) $(CC_FLAGS) -o build/patch/debug_event/debug_event.c.s build/patch/debug_event/debug_event.i
	$(call DL_FlagsSwitch, build/patch/debug_event/debug_event.c.o)
	$(MASPSX) $(MASPSX_FLAGS) -o build/patch/debug_event/debug_event.c.o build/patch/debug_event/debug_event.c.s
	$(ARMIPS) patch/debug_event/debug_event.asm

patch_debug_infomessage: build
	rm -rf $(BUILD_DIR)/patch/debug_infomessage
	mkdir -p $(BUILD_DIR)/patch/debug_infomessage
	$(CPP) -P -MMD -MP -MT patch/debug_infomessage/debug_infomessage/temp1.i -MF build/patch/debug_infomessage/debug_infomessage.i.d $(CPP_FLAGS) -o build/patch/debug_infomessage/debug_infomessage.i patch/debug_infomessage/debug_infomessage.c
	$(CC) $(CC_FLAGS) -o build/patch/debug_infomessage/debug_infomessage.c.s build/patch/debug_infomessage/debug_infomessage.i
	$(call DL_FlagsSwitch, build/patch/debug_infomessage/debug_infomessage.c.o)
	$(MASPSX) $(MASPSX_FLAGS) -o build/patch/debug_infomessage/debug_infomessage.c.o build/patch/debug_infomessage/debug_infomessage.c.s
	$(ARMIPS) patch/debug_infomessage/debug_infomessage.asm

# Recipes

# .elf targets
# Generate .elf target for each target from TARGET_IN.
$(foreach target,$(TARGET_IN),$(eval $(call make_elf_target,$(target),$(call get_target_out,$(target)))))

# Generate objects.
# $1 build folder, $2 asm folder of INCLUDE_ASM.
define make_object_rules
$1/%.i: %.c
	@mkdir -p $$(dir $$@)
	$$(CPP) -P -MMD -MP -MT $$@ -MF $$@.d $$(CPP_FLAGS) -o $$@ $$<

$1/%.c.s: $1/%.i
	@mkdir -p $$(dir $$@)
	$$(call DL_FlagsSwitch, $$@)
	$$(CC) $$(CC_FLAGS) -o $$@ $$<

$1/%.c.o: $1/%.c.s
	@mkdir -p $$(dir $$@)
	$$(call DL_FlagsSwitch, $$@)
	-$$(MASPSX) $$(MASPSX_FLAGS) -I$2 -o $$@ $$<
	-$$(OBJDUMP) $$(OBJDUMP_FLAGS) $$@ > $$(@:.o=.dump.s)

$1/%.hasm.s.o: src/psyq/bios.s
	@mkdir -p $$(dir $$@)
	$$(CPP) -x assembler-with-cpp -P -MMD -MP -MT $$@ \
	-Iinclude -Ibuild -DFUNC_$$(call bios_num,$$(notdir $$*)) -o $$(@:.o=) $$<
	$$(AS) $$(AS_FLAGS) -o $$@ $$(@:.o=)

$1/%.s.o: %.s
	@mkdir -p $$(dir $$@)
	$$(AS) $$(AS_FLAGS) -I$2 -o $$@ $$<

$1/%.bin.o: %.bin
	@mkdir -p $$(dir $$@)
	$$(LD) -r -b binary -o $$@ $$<
endef

$(foreach b,$(TARGET_BUILDS),$(eval $(call make_object_rules,$(word 1,$(subst :, ,$b)),$(word 2,$(subst :, ,$b)))))

# LIBPAD 4.2 was built with a newer assembler than the rest of the executable:
# it fills branch delay slots itself (`jr ra` + `addiu sp`, `lui at` / `jal` /
# `sw %lo(at)`) and puts load-delay nops before loop labels. MASPSX 2.56 does
# neither, so these units go straight to GNU as in reorder mode. `-gcoff` is
# dropped because its line labels stop GNU as from swapping, and `move` is
# spelled as `addu` because newer binutils encode it as `or`. cc1 names the
# read-only section `.rdata`; it is renamed so the linker script picks it up.
# The original assembler padded each section to 16 bytes; `.balign 16` at the
# end of .text and .rodata does the same.
# Only units fully in C can be listed (INCLUDE_ASM depends on MASPSX).
GNU_AS_UNITS := psyq/libpad/padmain psyq/libpad/padcmd psyq/libpad/padentry \
                psyq/libpad/padif psyq/libpad/padportd psyq/libpad/padseqd \
                psyq/libpad/waitrc2
GNU_AS_OBJS  := $(foreach b,$(TARGET_BUILDS),$(foreach u,$(GNU_AS_UNITS),$(word 1,$(subst :, ,$b))/src/$(u).c.o))

$(GNU_AS_OBJS): %.c.o: %.i
	@mkdir -p $(dir $@)
	$(CC) $(OPT_FLAGS) -G0 -mips1 -mcpu=3000 -funsigned-char -quiet -o $(@:.o=.s) $<
	sed -i -E 's/^\tmove\t(\$$[0-9a-z]+),(\$$[0-9a-z]+)/\taddu\t\1,\2,$$0/; s/^\t\.rdata$$/\t.section .rodata/' $(@:.o=.s)
	grep -q '^[[:space:]]*\.section \.rodata' $(@:.o=.s) && printf '\t.section .rodata\n\t.balign 16\n' >> $(@:.o=.s) || true
	printf '\t.text\n\t.balign 16\n' >> $(@:.o=.s)
	$(AS) $(ENDIAN) $(INCLUDE_FLAGS) $(OPT_FLAGS) -G0 -march=r3000 -mtune=r3000 -o $@ $(@:.o=.s)
	-$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.dump.s)

# Split .yaml.
$(LINKER_DIR)/%.ld: $(CONFIG_DIR)/%.yaml $(SYMBOL_FILES)
	@mkdir -p $(dir $@)
	$(SPLAT) $(SPLAT_FLAGS) $<

### Settings
.SECONDARY:
.PHONY: all clean default permuter-setup permuter-import permuter-run permuter-reseed permuter-clean
SHELL = /bin/bash -e -o pipefail