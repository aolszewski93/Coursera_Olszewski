/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from one memory location to another
 *
 * Given a pointer to a source and destination data set, this will move
 * a number of elements from the source to the destination. The length is
 * determined by the provided size parameter.
 *
 * @param src Pointer to source data array
 * @param dst Pointer to destination data array
 * @param size Number of elements to copy
 *
 * @return dst Pointer to the destination.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data from one memory location to another
 * 
 * Given a pointer to a source and destination data set, this will copy
 * a number of elements from the source to the destination. The length is
 * determined by the provided size parameter. This function does not
 * handle overlapping memory regions.
 * 
 * @param src Pointer to source data array
 * @param dst Pointer to destination data array
 * @param length Number of bytes to copy
 * 
 * @return dst Pointer to the destination.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets all locations in a memory region to a specific value
 * 
 * Given a pointer to a memory region, this function sets all bytes
 * in that region to a specific value. 
 * 
 * @param src Pointer to the memory region
 * @param length Number of bytes to set
 * @param value The value to set each byte to
 * 
 * @return src Pointer to the source memory region.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets all locations in a memory region to zero
 * 
 * Given a pointer to a memory region and length in bytes, 
 * this function sets all bytes in that region to zero.
 * 
 * @param src Pointer to the memory region
 * @param length Number of bytes to set to zero
 * 
 * @return src Pointer to the source memory region.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in a memory region
 * 
 * Given a pointer to a memory region and its length, this function
 * reverses the order of bytes in that region.
 * 
 * @param src Pointer to the memory region
 * @param length Number of bytes to reverse
 * 
 * @return src Pointer to the source memory region.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);


/**
 * @brief Reserves a block of dynamic memory for words
 * 
 * This function reserves a block of memory for a specified number of
 * 32-bit words. It allocates memory dynamically and returns a pointer to
 * memory if successful, or NULL if allocation fails.
 * 
 * @param length The number of 32-bit words to reserve
 * 
 * @return ptr A pointer to the reserved memory block, or NULL if allocation fails.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees a block of dynamically allocated memory
 * 
 * This function frees a block of memory that was previously reserved
 * using the reserve_words function. It takes a pointer to the memory
 * block to be freed.
 * 
 * @param src Pointer to the memory block to free
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
