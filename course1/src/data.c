/******************************************************************************
 * Copyright (C) 2025 by Albert Olszewski
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief This file provides very basic data manipulation functions.
 *
 * @author Albert Olszewski
 * @date June 24, 2025
 *
 */


#include "data.h"
#include <stdint.h>
#include <stdlib.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    uint8_t *start = ptr;        // Pointer to start of buffer
    uint8_t *head = ptr;         // Pointer used for reversal
    int is_negative = 0;
    uint32_t udata;

    // Handle zero explicitly
    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return 2;
    }

    // Handle negative numbers (only if base is 10)
    if (data < 0 && base == 10) {
        is_negative = 1;
        data = -data;
    }

    // Convert data to unsigned (for two's complement handling in non-decimal)
    udata = (base == 10) ? (uint32_t)data : *((uint32_t *)&data);

    // Convert to ASCII in reverse order
    while (udata > 0) {
        uint32_t digit = udata % base;
        *ptr++ = (digit < 10) ? ('0' + digit) : ('A' + (digit - 10));
        udata /= base;
    }

    // Add negative sign for base 10
    if (is_negative) {
        *ptr++ = '-';
    }

    *ptr = '\0';  // Null-terminate

    // Reverse the string (in-place using pointer arithmetic)
    uint8_t *end = ptr - 1;
    while (head < end) {
        uint8_t temp = *head;
        *head = *end;
        *end = temp;
        head++;
        end--;
    }

    return (uint8_t)(ptr - start + 1);  // Include null terminator in length
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int is_negative = 0;

    // Handle negative sign
    if (*ptr == '-') {
        is_negative = 1;
        ptr++;
        digits--;
    }

    while (digits > 0) {
        int32_t value = 0;

        if (*ptr >= '0' && *ptr <= '9') {
            value = *ptr - '0';
        } else if (*ptr >= 'A' && *ptr <= 'F') {
            value = *ptr - 'A' + 10;
        } else if (*ptr >= 'a' && *ptr <= 'f') {
            value = *ptr - 'a' + 10;
        } else {
            // Invalid character for base; treat as error or skip
            break;
        }

        result = result * base + value;
        ptr++;
        digits--;
    }

    if (is_negative) {
        result = -result;
    }

	if (base != 10 && (result & 0x80000000)) {
    	// Convert from unsigned to signed two's complement
    	result = (int32_t)result;
	}

    return result;
}

