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
 * @file main.c
 * @brief This file is to be used for the c1m3 assessment.
 *
 * This file provides various memory allocations. The learner will need
 * to analyze the code's memory footprint for this assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "misc.h"

static int g1;
const int g2 = 45;
char g3 = 12;
char g4 = 0;
extern char g5[N];

int main()
{
  register int l1;
  int * l2;
  printf("Address of pointer variable l2: %p\n", (void*)&l2);
  volatile int l3 = 12;
  
  l2 = (int *) malloc( N * g2 * sizeof(char) );

  printf("Address of malloc'd 12: %p\n", (void*)l2);
  if ( ! l2 )
  {
    return -1;
  }

  for( l1 = 0; l1 < g2; l3++)
  {
    g1 = func(l2);
  }

  return 0;
}

