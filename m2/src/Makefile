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

# Platform Overrides
PLATFORM = 

ifeq ($(PLATFORM), HOST)
# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = gcc
LD = gcc
LDFLAGS = -Wall -Werror -g -O0 -std=c99
CFLAGS = 
CPPFLAGs = -DHOST $(INCLUDES)

endif