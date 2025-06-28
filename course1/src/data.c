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


include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	// convert data from a standard integer to a ASCII string
	uint8_t *start = ptr;
	int is_negative = 0;
	// Handle zero case
	if (data == 0) {
		*ptr++ = '0';
		*ptr = '\0'; // Null-terminate the string
		return 2; // Return length of 2
	}

	// handle negative numbers for base 10
	if (data < 0 && base == BASE_10) {
		*ptr++ = '-';
		data = -data; // Make data positive for conversion
	}

	// convert integer to ASCII in reverse order
	while (data > 0) {
		int digit = data % base;
		if (digit < 10) {
			*ptr++ = '0' + digit; // Convert to ASCII character
		} else {
			*ptr++ = 'A' + (digit - 10); // Convert to ASCII character for hex
		}
		data /= base;
	}

	if (is_negative) {
		*ptr++ = '-'; // Add negative sign if needed
	}
	*ptr = '\0'; // Null-terminate the string

	// Reverse the string to get the correct order
	uint8_t *end = ptr - 1;
	while (start < end) {
		uint8_t temp = *start;
		*start = *end;
		*end = temp;
		start ++;
		end--;
	}

	return (uint8_t)(ptr - start + (start - (ptr -1)) + 1); // Return length of the string including null terminator
}

int32_t myatoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
	int32_t result = 0;
  int is_negative = 0;

  // Check for negative sign
  if (*ptr == '-') {
    is_negative = 1;
    ptr++;
    digits--;  // minus sign is not a digit
  }

  while (digits > 0) {
    int32_t value = 0;

    if (*ptr >= '0' && *ptr <= '9') {
      value = *ptr - '0';
    } else if (*ptr >= 'A' && *ptr <= 'F') {
      value = *ptr - 'A' + 10;
    }

    result = result * base + value;

    ptr++;
    digits--;
  }

  if (is_negative) {
    result = -result;
  }

  return result;
}

