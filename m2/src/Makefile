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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk


ifeq ($(PLATFORM), HOST)
# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = gcc
LD = gcc
LDFLAGS = 
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -DHOST $(INCLUDES)

else ifeq ($(PLATFORM), MSP432)
# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
CPU = mcpu=cortex-m4
ARCH = -mthumb -march=armv7e-m
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
LDFLAGS = $(LINKER_FILE) $(SPECS)
CFLAGS = -Wall -Werror -g -O0 -std=c99 $(CPU) $(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16
CPPFLAGS = -DMSP432 $(INCLUDES)


endif

# Object Files
OBJS = $(SOURCES:.c=.o)

# Default build target
build: $(OBJS)
	$(LD) $(LDFLAGS) -o c1m2.out $(OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Clean target to remove build artifacts
.PHONY: clean 
clean:
	rm -f src/*.o c1m2.out *.map *.i *.asm *.d

	