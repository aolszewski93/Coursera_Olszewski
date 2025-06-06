/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 * @file     stats.h
 * @brief    Header file for statistics functions
 *
 * Author:   Albert Olszewski
 * Date:     2025-06-05
 *
 * Description:
 * This header file contains the declarations for a set of functions that perform
 * statistical analysis on an array of unsigned char data, such as calculating
 * the mean, median, minimum, and maximum values, as well as sorting and printing
 * the array and its statistics.
 ******************************************************************************/

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array (minimum, maximum, mean, median)
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 */
void print_statistics(unsigned char *data, unsigned int size);

/**
 * @brief Prints the elements of the array
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 */
void print_array(unsigned char *data, unsigned int size);

/**
 * @brief Calculates and returns the median value of the array
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 *
 * @return The median value of the array
 */
unsigned char find_median(unsigned char *data, unsigned int size);

/**
 * @brief Calculates and returns the mean value of the array
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 *
 * @return The mean value of the array
 */
unsigned char find_mean(unsigned char *data, unsigned int size);

/**
 * @brief Finds and returns the maximum value in the array
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 *
 * @return The maximum value in the array
 */
unsigned char find_maximum(unsigned char *data, unsigned int size);

/**
 * @brief Finds and returns the minimum value in the array
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 *
 * @return The minimum value in the array
 */
unsigned char find_minimum(unsigned char *data, unsigned int size);

/**
 * @brief Sorts the array from largest to smallest (in-place)
 *
 * @param data Pointer to the array of data
 * @param size The number of elements in the array
 */
void sort_array(unsigned char *data, unsigned int size);

#endif /* __STATS_H__ */