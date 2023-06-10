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
 * @file stat.h
 * @brief Header file for stat.c file.
 *
 * This file contains the declaration and commentation of function defined and used in stat.c file.
 *
 * @author Ashar Mohiuddin
 * @date March 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function to find the mean of the given array.
 * 
 * <Add Extended Description Here> This function asks users for a unsigned char pointer that points to a pointer and an integer 
   containing total no. of array elements and then uses a for-loop and basic arthmetics to find the mean of the array. 
 * 
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array  
 *
 * @return Mean of the given array.
 */
float find_mean(unsigned char *, int);


/**
 * @brief A function to find the median of the given array.
 * 
 * <Add Extended Description Here> This function first uses the sort_array() function to sort the array in a descending order and 
   then it returns the center value of the array if number of elements in the array are odd or find mean of (n/2) and ((n/2)+1) 
   if number of elements in the given array are even.
 *  
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array 
 *
 * @return Returns the median of the given array.
 */
float find_median(unsigned char *, int); 


/**
 * @brief A function to find the maximum number in the given array.
 *
 * <Add Extended Description Here> This functon uses a for-loop and conditional statements to find the maximum of the given array.
 *
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array 
 *
 * @return Returns the maximum number in the given array.
 */
int find_maximum(unsigned char *, int);


/**
 * @brief A function to find the minimum number in the given array.
 *
 * <Add Extended Description Here> This functon uses a for-loop and conditional statements to find the minimum of the given array.
 *
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array
 *
 * @return Returns the minimum number in the given array.
 */
int find_minimum(unsigned char *, int);


/**
 * @brief A function to sort the elements in the given array in descending order.
 *
 * <Add Extended Description Here> This function uses a for-loop and conditional statement to sort the elements in the given array 
   in descending order.
 *
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array
 *
 * @return This function does not return any value.
 */
void sort_array(unsigned char *, int);


/**
 * @brief A function to print the elements of an array.
 *
 * <Add Extended Description Here> This function uses for-loop, conditional statements and printf() function to print the elements 
   of an array.
 *
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array
 *
 * @return This function does not return any value.
 */
void print_array(unsigned char *, int);

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * <Add Extended Description Here> this function uses find_median(), find_mean(), find_maximum() and find_minimum() function to 
   print the median, mean, maximum and minimum number of the given array.
 *
 * @param unsigned char * : A pointer pointing to an unsigned char array 
          int : An integer containing the number of elements the given array
 *
 * @return This function does not return any value.
 */
void print_statistics(unsigned char *, int);


#endif /* __STATS_H__ */