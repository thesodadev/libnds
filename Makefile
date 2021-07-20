# Output file name
BIN_NAME = libnds.a

# Dirs with resources and source code
GFX_DIR = res/gfx
FONTS_DIR = res/fonts
COMMON_SRC_DIR = src
ARM9_SRC_DIR = src/arm9

# Find all .c and .s files
COMMON_SRC_FILES = $(wildcard $(COMMON_SRC_DIR)/*.c) $(wildcard $(COMMON_SRC_DIR)/*.s)

ARM9_SRC_FILES = $(wildcard $(ARM9_SRC_DIR)/*.c) $(wildcard $(ARM9_SRC_DIR)/*.s) \
				 $(wildcard $(ARM9_SRC_DIR)/system/*.c) $(wildcard $(ARM9_SRC_DIR)/system/*.s) \
				 $(wildcard $(ARM9_SRC_DIR)/dldi/*.c) $(wildcard $(ARM9_SRC_DIR)/dldi/*.s)

# And all resources
GFX_FILES = $(wildcard $(GFX_DIR)/*.grit)
FONT_FILES = $(wildcard $(FONTS_DIR)/*.bin)


# Toolchain
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
AS = arm-none-eabi-as
AR = arm-none-eabi-gcc-ar
BIN2S = bin2s
GRIT = grit


# Build config
INCLUDE_DIRS = 	-I$(GFX_DIR) \
				-I$(FONTS_DIR) \
				-I$(NEWLIB_DIR)/newlib/libc/include

ARCHFLAGS = -mthumb \
  			-mthumb-interwork \
			-march=armv5te \
			-mtune=arm946e-s

CFLAGS =	-Wall -O2 \
			-ffunction-sections \
			-fdata-sections \
			-fomit-frame-pointer \
			-DARM9 \
			-DNDEBUG \
			$(ARCHFLAGS) \
			$(INCLUDE_DIRS)

ASFLAGS =	-x assembler-with-cpp \
			-DARM9 \
			$(ARCHFLAGS) \
			-I$(COMMON_SRC_DIR)

ARFLAGS = -rcs
BIN2SFLAGS = -a 4
GRITFLAGS = -fts


# List all object files
OBJ_FILES =  $(GFX_FILES:.grit=.o) \
			 $(FONT_FILES:.bin=.o) \
			 $(patsubst %.s,%.o, $(patsubst %.c,%.o, $(COMMON_SRC_FILES) $(ARM9_SRC_FILES)))


# Build rules
$(BIN_NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.arm.o: %.arm.c
	$(CC) $(CFLAGS) -marm -c $< -o $@

%.o: %.s
	$(CC) $(ASFLAGS) -c $< -o $@

%.s %.h: %.png %.grit
	$(GRIT) $< $(GRITFLAGS) -o $*

%.o: %.bin
	$(BIN2S) $(BIN2SFLAGS) -H $(@:.o=.h) $< | \
	$(AS) -o $@


# General rules
.PHONY: all clean rebuild

all: $(BIN_NAME)

clean:
	rm -rf $(OBJ_FILES) $(BIN_NAME)

rebuild: clean all
