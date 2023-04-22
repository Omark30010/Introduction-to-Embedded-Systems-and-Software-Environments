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
# A makefile that can compile multiple source files and support two platforms, HOST and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Builds <FILE>.i preprocessor file
#      <FILE>.asm - Builds <FILE>.asm assembly file
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      compile-all - Same as build
#      clean - removes all generated files
#
# Platform Overrides:
#      PLATFORM - Platform to be used (HOST, MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

ifeq ($(PLATFORM), MSP)
	CC=arm-none-eabi-gcc
	LD=arm-none-eabi-ld
	LDFLAGS=-Wl, -map $(TARGET).map -T $(LINKER_FILE)
	CFLAGS=-m$(CPU) -m$(ARCH) -m$(FLOAT-ABI) -m$(FPU) --$(SPECS) -Wall
	CPPFLAGS=-d 


LINKER_FILE=msp432p401r.lds
CPU=cortex-m4
SPECS=nosys.specs
ARCH=armv7e-m
TARGET=c1m2
FLOAT-ABI=hard
FPU=fpv4-sp-d16
TARGET=c1m2
CODE_SIZE=arm-none-eabi-size
	
OBJS = $(SRCS:.c=.o)	


else 
	CC=gcc
	LD=-ld
	LDFLAGS=-Wl, -map $(TARGET).map 
	CFLAGS= -Wall
	CPPFLAGS=-d 
	TARGET=c1m2
	CODE_SIZE=size


OBJS = $(SRCS: main.c=main.o memory.c=memory.o)

endif




%.i : %.c
	$(CC) $(CPPFLAGS) -E $< -o $@ 

%.asm : %.c
	$(CC) $(CPPFLAGS) -S $< $(CFLAGS) -o $@  

%.o : %.c
	$(CC) $(CPPFLAGS) -c $< $(CFLAGS) -o $@




.PHONY: build
build: compile-all

.PHONY: compile-all
compile-all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ 
	$(CODE_SIZE) -Bx $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(TARGET).asm $(TARGET).i




