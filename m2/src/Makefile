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
CFLAGS = -Wall -Werror -g -O0 -std=c99 -MMD
CPPFLAGS = -DHOST $(INCLUDES)

else ifeq ($(PLATFORM), MSP432)
# Architectures Specific Flags
LINKER_FILE = -T ../msp432p401r.lds
CPU = -mcpu=cortex-m4
ARCH = -mthumb -march=armv7e-m
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
LDFLAGS = $(LINKER_FILE) $(SPECS) -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -MMD
CPPFLAGS = -DMSP432 $(INCLUDES)


endif

# Object Files
OBJS = $(SOURCES:.c=.o)

# Default build target
build: $(OBJS)
	$(LD) $(LDFLAGS) -o c1m2.out $(OBJS)

# special compile rule for interrupts
interrupts_msp432p401r_gcc.o: interrupts_msp432p401r_gcc.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -mgeneral-regs-only -c $< -o $@

# generate preprocessed code
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -E $< -o $@

# compile assembly from source
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@

# diassembly from final executable using objdump
c1m2.disasm: c1m2.out
	arm-none-eabi-objdump -d c1m2.out > c1m2.disasm

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# include .d files if they exist
-include *.d

# compile all
.PHONY: compile-all
compile-all: $(OBJS)

# Clean target to remove build artifacts
.PHONY: clean 
clean:
	rm -f *.o c1m2.out *.map *.i *.asm *.d

.PHONY: build

# for debugging
# $(info SOURCES = $(SOURCES))
	
