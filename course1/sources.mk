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

ifeq ($(PLATFORM), HOST)
# Add your Source files to this variable
SOURCES = \
  src/main.c \
  src/memory.c \
  src/course1.c \
  src/data.c \
  src/stats.c

# Add your include paths to this variable
INCLUDES = \
  -Iinclude/common

else ifeq ($(PLATFORM), MSP432)
# Add your Source files to this variable
SOURCES = \
  src/main.c \
  src/memory.c \
  src/interrupts_msp432p401r_gcc.c \
  src/startup_msp432p401r_gcc.c \
  src/system_msp432p401r.c \
  src/course1.c \
  src/data.c \
  src/stats.c

INCLUDES = \
  -Iinclude/common \
  -Iinclude/msp432 \
  -Iinclude/CMSIS

endif


