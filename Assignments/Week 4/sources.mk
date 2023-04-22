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

# Add your Source files to this variable
SRCS = Desktop/Course1/src/main.c                        \
	Desktop/Course1/src/memory.c                      \
	Desktop/Course1/src/interrupts_msp432p401r_gcc.c  \
	Desktop/Course1/src/startup_msp432p401r_gcc.c     \
	Desktop/Course1/src/system_msp432p401r.c          \
	Desktop/Course1/src/data.c \
	Desktop/Course1/src/course1.c \
	Desktop/Course1/src/stats.c



# Add your include paths to this variable
INCLUDES =  Desktop/Course1/include/msp432\
	    Desktop/Course1/include/common    \
	    Desktop/Course1/include/include/CMSIS



