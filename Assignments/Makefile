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
# This makefile builds the C1M2 project for both the native build machine
# and for the msp432 development board.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build        Compile all source files and link.
#      clean        Remove all generated files.
#      compile-all  Compile all object files, but DO NOT link.
#
#      <file>.asm   Generate assembly output of c-program implementation files and the
#                   final output executable (Use the –S flag and the objdump utility).
#
#      <file>.i     Generate the preprocessed output of all c-program implementation
#                   files (use the –E flag).
#
#      <file>.o     Generate the object file for all c-source files (but do not link)
#                   by specifying the object file you want to compile.
#
# Platform Overrides:
#      HOST    Build for the native build machine architecture
#      MSP432  Build for the msp432 development board (armv7e-m)
#      Builds for PLATFORM=HOST if PLATFORM is not defined.
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM =
# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
ifeq ($(PLATFORM),HOST)
# Compiler Flags and Defines
CPU = x86_64
CC = gcc
LD = ld
LDFLAGS = -wl,-Map=c1m2.map -T msp432p401r.lds 
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGs = -M -MF
DEFINEFLAG = -DHOST
else #PLATFORM == MSP432
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -wl,-Map=c1m2.map -T msp432p401r.lds 
CFLAGS =-mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) -Wall
CPPFLAGs = -M -MF
DEFINEFLAG = -DMSP432
endif
OBJS = $(SOURCES:.c=.o)
OUTS = $(SOURCES:.c=.out)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(CPPFLAGs) $(DEFINEFLAG) $< $(CC) $(DEFINEFLAG) -E -o $@

%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -S $< objdump $(OBJS) -D

.PHONY: compile-all
compile-all: $(OBJS)
$(OBJS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $(SOURCES)

.PHONY: build
build: $(OUTS)
$(OUTS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(LDFLAGS) -o c1m2.out $^ size c1m2.out

.PHONY: clean
clean:
	rm -f *.i *.d *.map *.s *.out *.o

