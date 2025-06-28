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
 * @file data.h
 * @brief Very basic data manipulation header file.
 *
 * This header file provides very basic data manipulation functions.
 *
 * @author Albert Olszewski
 * @date June 24, 2025
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_10 10
#define BASE_16 16

/**
 * @brief convert data from a standard integer to a ASCII string
 * 
 * This function calls the my_itoa function to convert a signed integer
 * to an ASCII string representation in the specified base.
 * 
 * @param data The signed integer to convert.
 * @param ptr Pointer to the buffer where the ASCII string will be stored.
 * @param base The base for conversion (e.g., BASE_10 for decimal, BASE_16 for hexadecimal).
 *
 * @return value The length of the resulting ASCII string.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief convert data from an ASCII string to a standard integer
 * 
 * This function calls the my_atoi function to convert an ASCII string
 * representation of a number back to a signed integer in the specified base.
 * 
 * @param ptr Pointer to the ASCII string to convert.
 * @param digits The number of digits in the ASCII string.
 * @param base The base for conversion (e.g., BASE_10 for decimal, BASE_16 for hexadecimal).
 *
 * @return value The resulting signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */ 
