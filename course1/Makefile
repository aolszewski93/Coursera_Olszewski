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
# This Makefile provides a flexible build system for compiling a C-based embedded systems project for two platforms: the native HOST environment and the target MSP432 microcontroller.
#
# It supports:
#	•	Native compilation using gcc
#	•	Cross-compilation using arm-none-eabi-gcc for ARM Cortex-M4
#	•	Modular flags for platform-specific compilation and linking
#	•	Generation of build artifacts:
#	•	Preprocessed source files (*.i)
#	•	Assembly files (*.asm)
#	•	Object files (*.o)
#	•	Dependency files (*.d)
#	•	Linker map files (*.map)
#	•	Final executable (c1m2.out)
#	•	Disassembly from executable (c1m2.disasm)
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build         - Compile all source files and link into c1m2.out
#      compile-all   - Compile all source files to object files without linking
#      clean         - Remove all generated files (objects, output, map, etc.)
#      %.i           - Generate preprocessed output for a given C source file
#      %.asm         - Generate assembly output for a given C source file
#      c1m2.disasm   - Generate disassembled output from final executable
#
# Platform Overrides:
#      PLATFORM=HOST     - Compile using native GCC for testing on the host machine
#      PLATFORM=MSP432   - Cross-compile using arm-none-eabi-gcc for the MSP432 target
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
CPPFLAGS = -DHOST -DCOURSE1 -DVERBOSE $(INCLUDES)

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
	$(LD) $(LDFLAGS) -o main.out $(OBJS)

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
c1m2.disasm: main.out
	arm-none-eabi-objdump -d c1m2.out > c1m2.disasm

# Compile source files to object files
src/%.o: src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# include .d files if they exist
-include *.d

# compile all
.PHONY: compile-all
compile-all: $(OBJS)

# Clean target to remove build artifacts
.PHONY: clean 
clean:
	rm -f *.o main.out *.map *.i *.asm *.d

.PHONY: build

# for debugging
# $(info SOURCES = $(SOURCES))
	
