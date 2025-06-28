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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


/* placeholder for new functions */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  // move memory from src to dst by length of bytes specified by length variable
  if (src == dst || length == 0) {
    return dst; // No operation needed if src and dst are the same or length is zero
  }
  // Check for overlap
  if (src < dst && (src + length) > dst) {
    // Overlapping regions, copy backwards
    for (size_t i = length; i > 0; i--) {
      *(dst + i - 1) = *(src + i - 1);
    }
  } else {
    // Non-overlapping regions, copy forwards
    for (size_t i = 0; i < length; i++) {
      *(dst + i) = *(src + i);
    }
  }   
  
  //
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  // copy length of bytes from src to dst
  if (src == dst || length == 0) {
    return dst; // No operation needed if src and dst are the same or length is zero
  }
  // Non-overlapping regions, copy forwards
  for (size_t i = 0; i < length; i++) {
    *(dst + i) = *(src + i);
  }

  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  // set length of bytes in src to defined value
  for (size_t i = 0; i < length; i++) {
    *(src + i) = value;
  }
  //return pointer to src 
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  // set length of bytes in src to zero
  for (size_t i = 0; i < length; i++) {
    *(src + i) = 0;
  }
  //return src;
  return src;
}

void my_reverse(uint8_t * src, size_t length) {
  // reverse the order of bytes from src to end of length
  if (src == NULL || length == 0) {
    return; // No operation needed if src is NULL or length is zero
  }
  // Swap bytes in place
  // Using a temporary variable to swap elements
  uint8_t temp;

  for (size_t i = 0; i < length / 2; i++) {
    // store the temporary value
    temp = *(src + i);
    // grab the value from the end of the src and store it in the beginning
    *(src + i) = *(src + length - i - 1);
    // store the temporary value in the end of the src
    *(src + length - i - 1) = temp;
  }
  //return src;
  return src;
}

int32_t * reserve_words(size_t length) {
  // Allocate memory for an array of int32_t
  int32_t * ptr = (int32_t *)malloc(length * sizeof(int32_t));
  
  // check if memory allocation was successful
  if (ptr == NULL) {
    return NULL; // Memory allocation failed
  }  
  //return ptr if successful
  return ptr;
}

void free_words(int32_t * src) {
  // free up the memory allocated for the int32_t array
  if (src != NULL) {
    free(src);
  }
  // No return value needed, as the function is void
  return;
}
