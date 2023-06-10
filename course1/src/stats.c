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
 * @brief Implementation file for my C-programming code
 *
 * A simple programming that prints statistics of a dataset.
 *
 * @author Ashar Mohiuddin
 * @date March 2023
 *
 */

#include "stats.h"
#include <stdio.h>

/* Size of the Data Set */
#define SIZE (40)


void main() {

  unsigned char test[SIZE] = {34, 201, 190, 154, 8,   194, 2,   6,   114, 88,
                              45, 76,  123, 87,  25,  23,  200, 122, 150, 90,
                              92, 87,  177, 244, 201, 6,   12,  60,  8,   2,
                              5,  67,  7,   87,  250, 230, 99,  3,   100, 90};

  /* Other Variable Declarations Go Here */


  /* Statistics and Printing Functions Go Here */

  // average = find_mean(&test, SIZE);
  
  print_array(&test, SIZE);
  
  print_statistics(&test, SIZE);
  
  print_array(&test, SIZE);
  
}

/* Add other Implementation File Code Here */

float find_mean(unsigned char *list, int size) {
  float count = 0;
  float result;
  for (int i = 0; i < size; i++) {
    count = count + list[i];
  }
  result = count / size;

  return result;
}

float find_median(unsigned char *list, int size) {
  float median;

  sort_array(list, size);

  if ((size % 2) == 0) {
    median = (list[(size / 2) - 1] + list[((size / 2) + 1) - 1]) / 2.;
  } else if ((size % 2) == 1) {
    median = list[((size + 1) / 2) - 1];
  }
  return median;
}

void sort_array(unsigned char *list, int size) {
  int i, j, temp;
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      if (list[i] < list[j]) {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
}

int find_maximum(unsigned char *list, int size) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (max < list[i]) {
      max = list[i];
    } else {
      continue;
    }
    return max;
  }
}

int find_minimum(unsigned char *list, int size) {
  int min = list[0];
  for (int i = 1; i < size; i++) {
    if (min > list[i]) {
      min = list[i];
    } else {
      continue;
    }
  }
  return min;
}

void print_statistics(unsigned char *list, int size) {
  float median,mean;
  int max,min;
  median = find_median(list, size);
  mean = find_mean(list, size);
  max = find_maximum(list, size);
  min = find_minimum(list, size);
  printf("Median: %f\n",median);
  printf("Mean: %f\n",mean);
  printf("Maximum: %d\n",max);
  printf("Minimum: %d\n",min);
}

void print_array(unsigned char *list, int size) {
  for (int i=0;i<size;i++) {
    printf("%d|",list[i]);
  }
  printf("\n");
}