# Adapted from https://github.com/Vatuu/silent-hill-decomp/tree/master

# Configuration
BUILD_OVERLAYS ?= 1
NON_MATCHING   ?= 0
SKIP_ASM       ?= 0
VERSION 	   ?= us

# Names and Paths
ifeq ($(VERSION),us)
  GAME_NAME    := SCUS_942.36
  BASE_DIR     := scus_942.36
  ROM_DIR      := iso/${VERSION}
  CONFIG_DIR   := config/${BASE_DIR}
  LINKER_DIR   := linker/${BASE_DIR}
  BUILD_DIR    := build/
  OUT_DIR      := $(BUILD_DIR)/out
  TOOLS_DIR    := tools
  OBJDIFF_DIR  := $(TOOLS_DIR)/objdiff
  PERMUTER_DIR := permuter
  ASSETS_DIR   := assets/
  ASM_DIR      := asm/
  C_DIR        := src/
  EXPECTED_DIR := expected
else ifeq ($(VERSION),jp)
  GAME_NAME := SLPS_012.34
  BASE_DIR     := slps_012.34
  ROM_DIR      := iso/${VERSION}
  CONFIG_DIR   := config/${BASE_DIR}
  LINKER_DIR   := linker/${BASE_DIR}
  BUILD_DIR    := build/${BASE_DIR}
  OUT_DIR      := $(BUILD_DIR)/out
  TOOLS_DIR    := tools
  OBJDIFF_DIR  := $(TOOLS_DIR)/objdiff
  PERMUTER_DIR := permuter
  ASSETS_DIR   := assets/${BASE_DIR}
  ASM_DIR      := asm/${BASE_DIR}
  C_DIR        := src/${BASE_DIR}
  EXPECTED_DIR := expected
else ifeq ($(VERSION),eu)
  GAME_NAME := SLES_012.34
  BASE_DIR     := sles_012.34
  ROM_DIR      := iso/${VERSION}
  CONFIG_DIR   := config/${BASE_DIR}
  LINKER_DIR   := linker/${BASE_DIR}
  BUILD_DIR    := build/${BASE_DIR}
  OUT_DIR      := $(BUILD_DIR)/out
  TOOLS_DIR    := tools
  OBJDIFF_DIR  := $(TOOLS_DIR)/objdiff
  PERMUTER_DIR := permuter
  ASSETS_DIR   := assets/${BASE_DIR}
  ASM_DIR      := asm/${BASE_DIR}
  C_DIR        := src/${BASE_DIR}
  EXPECTED_DIR := expected
else
  $(error Invalid VERSION specified: $(VERSION))
endif

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
GET_YAML_TARGET := $(PYTHON) $(TOOLS_DIR)/get_yaml_target.py

# Flags
OPT_FLAGS           := -O2
ENDIAN              := -EL
INCLUDE_FLAGS       := -Iinclude -I $(BUILD_DIR)
DEFINE_FLAGS        := -D_LANGUAGE_C -DUSE_INCLUDE_ASM
CPP_FLAGS           := $(INCLUDE_FLAGS) $(DEFINE_FLAGS) -P -MP -undef -Wall -lang-c -nostdinc
LD_FLAGS            := $(ENDIAN) $(OPT_FLAGS) -nostdlib --no-check-sections
OBJCOPY_FLAGS       := -O binary
OBJDUMP_FLAGS       := --disassemble-all --reloc --disassemble-zeroes -Mreg-names=32
SPLAT_FLAGS         := --disassemble-all --make-full-disasm-for-code
DL_FLAGS := -G0
AS_FLAGS := $(ENDIAN) $(INCLUDE_FLAGS) $(OPT_FLAGS) $(DL_FLAGS) -march=r3000 -mtune=r3000 -no-pad-sections
CC_FLAGS := $(OPT_FLAGS) $(DL_FLAGS) -mips1 -mcpu=3000 -funsigned-char -gcoff -quiet

# PSY-Q libraries uses ASPSX 2.56 (PSQ 4.0)
# Archive library code uses GCC 2.6.0.
# Main-related and psyq code seem to use -G0 instead of -G8
define DL_FlagsSwitch
	$(if
		$(or 
			$(filter MAIN,$(patsubst build/src/$(BASE_DIR)/psyq/%,MAIN,$(1))), 
			$(filter MAIN,$(patsubst build/asm/${BASE_DIR}/psyq/%,MAIN,$(1)))
		),
		$(eval MASPSX_FLAGS = --aspsx-version=2.67 --macro-inc --expand-div --use-comm-section --run-assembler $(AS_FLAGS)),
		$(eval MASPSX_FLAGS = --aspsx-version=2.67 --expand-div --use-comm-section --run-assembler $(AS_FLAGS))
	)

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
find_s_files = $(shell find $(ASM_DIR)/$(strip $1) -type f -path "*.s" -not -path "asm/*matchings*" 2> /dev/null)

# Function to find matching .c files for a target name.
find_c_files = $(shell find $(C_DIR)/$(strip $1) -type f -path "*.c" 2> /dev/null)

# Function to generate matching .o files for target name in build directory.
gen_o_files = $(addprefix $(BUILD_DIR)/, \
							$(patsubst %.s, %.s.o, $(call find_s_files, $1)) \
							$(patsubst %.c, %.c.o, $(call find_c_files, $1)))

# get_target_out = $(addprefix $(OUT_DIR)/,$1)

# Function to get path to .yaml file for given target.
get_yaml_path = $(addsuffix .yaml,$(addprefix $(CONFIG_DIR)/,$1))

# Function to get target output path for given target.
get_target_out = $(addprefix $(OUT_DIR)/,$(shell $(GET_YAML_TARGET) $(call get_yaml_path,$1)))

# Template definition for elf target.
# First parameter should be source target with folder (e.g. screens/credits).
# Second parameter should be end target (e.g. build/VIN/STF_ROLL.BIN).
# If we skip the ASM inclusion to determine progress, we will not be able to link. Skip linking, if so.

ifeq ($(SKIP_ASM),1)

define make_elf_target
$2: $2.elf
$2.elf: $(call gen_o_files, $1)
endef

else

define make_elf_target
$2: $2.elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $$< $$@

$2.elf: $(call gen_o_files, $1)
	@mkdir -p $(dir $2)
	$(LD) $(LD_FLAGS) \
		-Map $2.map \
		-T $(LINKER_DIR)/$1.ld \
		-T $(LINKER_DIR)/$(filter-out ./,$(dir $1))undefined_syms_auto.$(notdir $1).txt \
		-T $(LINKER_DIR)/$(filter-out ./,$(dir $1))undefined_funcs_auto.$(notdir $1).txt \
		-o $$@
endef

endif

# Targets
ifeq ($(VERSION),us)
TARGET_MAIN := scus_942.36
else ifeq ($(VERSION),jp)
TARGET_MAIN := slps_012.34
else ifeq ($(VERSION),eu)
TARGET_MAIN := sles_012.34
else
$(error Invalid VERSION specified: $(VERSION))
endif

ifeq ($(BUILD_OVERLAYS), 1)
#TARGET_OVERLAYS := field
endif

# Source Definitions
TARGET_IN  := $(TARGET_MAIN)
TARGET_OUT := $(foreach target,$(TARGET_IN),$(call get_target_out,$(target)))
LD_FILES     := $(addsuffix .ld,$(addprefix $(LINKER_DIR)/,$(TARGET_IN)))

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
	mv build/asm $(EXPECTED_DIR)/asm

generate: $(LD_FILES)

clean:
	rm -rf $(BUILD_DIR)

reset: clean
	rm -rf $(ASM_DIR)
	rm -rf $(LINKER_DIR)

setup: reset
	$(MAKE) generate

regenerate: reset
	$(MAKE) generate

clean-build: clean
	rm -rf $(LINKER_DIR)
	$(MAKE) generate
	$(MAKE) build

# Recipes

# .elf targets
# Generate .elf target for each target from TARGET_IN.
$(foreach target,$(TARGET_IN),$(eval $(call make_elf_target,$(target),$(call get_target_out,$(target)))))

# Generate objects.
$(BUILD_DIR)/%.i: %.c
	@mkdir -p $(dir $@)
	$(CPP) -P -MMD -MP -MT $@ -MF $@.d $(CPP_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.s: $(BUILD_DIR)/%.i
	@mkdir -p $(dir $@)
	$(call DL_FlagsSwitch, $@)
	$(CC) $(CC_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.s
	@mkdir -p $(dir $@)
	$(call DL_FlagsSwitch, $@)
	-$(MASPSX) $(MASPSX_FLAGS) -o $@ $<
	-$(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.dump.s)

$(BUILD_DIR)/%.s.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(AS_FLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	@mkdir -p $(dir $@)
	$(LD) -r -b binary -o $@ $<

# Split .yaml.
$(LINKER_DIR)/%.ld: $(CONFIG_DIR)/%.yaml
	@mkdir -p $(dir $@)
	$(SPLAT) $(SPLAT_FLAGS) $<

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail