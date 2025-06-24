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
 * @file stats.c
 * @brief Implementation of basic statistical functions for an array
 *
 * This program provides functions to analyze an array of unsigned char values,
 * including finding the mean, median, minimum, and maximum, sorting the array,
 * and printing the results.
 *
 * @author Albert Olszewski
 * @date 2025-06-06
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Function implementations */

void print_statistics(unsigned char *data, unsigned int size) {
  // Print min, max, mean, and median
  printf("Minimum: %d\n", find_minimum(data, size));
  printf("Maximum: %d\n", find_maximum(data, size));
  printf("Mean: %d\n", find_mean(data, size));
  printf("Median: %d\n", find_median(data, size));
}

void print_array(unsigned char *data, unsigned int size) {
  // print all elements of the array
  for (unsigned int i = 0; i < size; i++) {
    printf("%d ", data[i]);
    if ((i+1) % 10 == 0) {
      printf("\n");
    }
  }
}

unsigned char find_median(unsigned char *data, unsigned int size) {
  // Calculate the median value of the array.
  // First, sort the array
  sort_array(data, size);
  if (size % 2 == 0) {
    return (data[size / 2 - 1] + data[size / 2]) / 2;
  }
  else {
    return data[size / 2];
  }
}

unsigned char find_mean(unsigned char *data, unsigned int size) {
  // Calculate the mean value of the array
  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += data[i];
  }
  return (unsigned char)(sum / size);
}

unsigned char find_maximum(unsigned char *data, unsigned int size) {
  // Find the maximum value in the array.
  unsigned char max = data[0];
  for (unsigned int i = 1; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  // Return the maximum value found
  return max;
}

unsigned char find_minimum(unsigned char *data, unsigned int size) {
  // Find the minimum value in the array.
  unsigned char min = data[0];
  for (unsigned int i = 1; i < size; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}

void sort_array(unsigned char *data, unsigned int size) {
  // return sorted array from largest to smallest
  for (unsigned int i = 0; i < size - 1; i++) {
    for (unsigned int j = 0; j < size - i - 1; j++) {
      if (data[j] < data[j + 1]) {
        // Swap data[j] and data[j + 1]
        unsigned char temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
  
}


void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Other Variable Declarations Go Here */
  unsigned char mean, median, max, min;

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  print_statistics(test, SIZE);
  sort_array(test, SIZE);
  printf("\nSorted Array:\n");
  print_array(test, SIZE);


};



