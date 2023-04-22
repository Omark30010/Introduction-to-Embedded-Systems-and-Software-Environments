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
 * @brief implementation of functions.
 *
 * functions:
 * @main()
 * @find_median()
 * @find_mean()
 * @find_maximum()
 * @find_minimum()
 * @sort_aray()
 * @print_array()
 * @print_statistics()
 *
 * @author Omar Khalid Gohar
 * @date 23/04/2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main(int argc, char *argv[]) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  double mean;
  double median;
  unsigned char max_element;
  unsigned char min_element;
  unsigned char *sorted_array;


  mean = find_mean(test, SIZE);
  median = find_median(test, SIZE);
  max_element = find_maximum(test, SIZE);
  min_element = find_minimum(test, SIZE);
  sorted_array = sort_array(test, SIZE);

  print_array(test, SIZE);
  PRINTF("\nsorted array is:\n");
  int i;
  for(i = 0; i < SIZE; i++){

    PRINTF("%d\t", sorted_array[i]);

  }
  PRINTF("median of array is: %.2f \n\n", median);
  PRINTF("maximum element of array is: %d \n\n", max_element);
  PRINTF("minimum element of array is: %d \n\n", min_element);
  print_statistics(test, SIZE);


  return 0;
}

/** functiion definitioins**/

/* definition of print_statistics() function*/

void print_statistics(unsigned char myArray[], int length){

     double mean;
     double median;
     unsigned char max_element;
     unsigned char min_element;
     unsigned char *sorted_array;

     sorted_array = sort_array(myArray, length);
     mean = find_mean(myArray, length);
     median = find_median(myArray, length);
     max_element = sorted_array[0];
     min_element = sorted_array[length - 1];


     PRINTF("statistics of array are:\n");
     PRINTF("mean: %.2f  median: %.2f  maximum: %d  minimum: %d \n", mean, median, max_element, min_element);


}

/* definition of find_median() function*/

double find_median(unsigned char myArray[], int length){

     int mid_index1;
     int mid_index2;
     unsigned char *sorted_array;
     unsigned char mid_element1;
     unsigned char mid_element2;
     double median;

     mid_index1 = SIZE / 2;
     mid_index2 = mid_index1 + 1;
     sorted_array = sort_array(myArray, length);
     mid_element1 = sorted_array[mid_index1];
     mid_element2 = sorted_array[mid_index2];

     median = (mid_element1 + mid_element2) / 2;

     return median;

}

/* definition of find_mean() function*/

double find_mean(unsigned char myArray[], int length){
     int i;
     double mean;
     double sum;
     sum = 0;
     for(i = 0; i < SIZE; i++){
     sum += myArray[i];

     }

     mean = sum / SIZE;
     return mean;

}

/* definition of find_maximum() function*/

unsigned char find_maximum(unsigned char myArray[], int length){
       unsigned char *sorted_array;
       unsigned char max_element;
       /* sort the array in decending order*/
       sorted_array = sort_array(myArray, SIZE);
       max_element = sorted_array[0];

       return max_element;
}

/* definition of find_minimum() function*/

unsigned char find_minimum(unsigned char myArray[], int length){
       unsigned char *sorted_array;
       unsigned char min_element;
       /* sort the array in decending order*/
       sorted_array = sort_array(myArray, SIZE);
       min_element = sorted_array[SIZE - 1];

       return min_element;

}

/* definition of sort_array() function*/

unsigned char *sort_array(unsigned char myArray[], int length){
      int i;
      int j;
      int temp;
      for(i = 0; i < length; i++){

         for(j = i+1; j < length; j++){

            if(myArray[i] < myArray[j]){

            temp = myArray[i];
            myArray[i] = myArray[j];
            myArray[j] = temp;
            }
         }
      }

      return myArray;
}

/* definition of print_array() function*/

void print_array(unsigned char myArray[], int length)
{
    #ifdef VERBOSE

    int i;
    PRINTF("The contents of array are:\n");
    for(i = 0; i < SIZE; i++)
    {
      PRINTF("%d\t", myArray[i]);

    }

    #endif

}














