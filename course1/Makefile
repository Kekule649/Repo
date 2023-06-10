#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile that support two platforms; the host environment and the target embedded system MSP432 and can 
# natively and cross compile an application
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      bulid - Builds and links all source files
#      all - same as build
#      compile_all - compile all files but does not link
#      clean - removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#      ARCH - ARM Architecture (thumb)
#      SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = size
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -Wall -Werror -g -std=c99 $(INCLUDES) 
	TARGET = c1m2

	SRCS = main.c memory.c

else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-size
	LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE)
	CFLAGS = -Wall -Werror -g -std=c99 $(INCLUDES) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) \
	-mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	TARGET = c1m2


endif

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
PREP = $(SRCS:.c=.i)
ASMS = $(SRCS:.c=.asm)

%.o	:	%.c
	$(CC) $(CFLAGS) -MMD -MP -MF $(@:.o=.d) -c $< -o $@ -D$(PLATFORM)

%.i	:	%.c
	$(CC) $(CFLAGS) -E $< -o $@ -D$(PLATFORM)

%.asm	:	%.c
	$(CC) $(CFLAGS) -S $< -o $@ -D$(PLATFORM)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY:	compile-all
compile-all: $(OBJS)

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ -D$(PLATFORM)
	$(LD) -Atd $(TARGET).out 


.PHONY: clean
clean:
	rm -f $(OBJS) $(PREP) $(ASMS) $(DEPS) $(TARGET).out $(TARGET).map

-include $(DEPS)