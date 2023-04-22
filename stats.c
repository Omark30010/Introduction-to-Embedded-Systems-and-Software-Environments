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
 * @file Introduction to Embedded Systems and Software Environments Assignments
 * @brief Introduction to Embedded Systems and Software Environments Peer-graded Assignments: Week 1
 *
 * couple of functions that can analyze an array of unsigned char
 * data items and report analytics on the maximum, minimum, mean, and median of the data set
 *
 * @author  Omar Khalid
 * @date 14 / 4 / 2023
 *
 */
#include <stdio.h>
#include "stats.h"
#include <math.h>

/* Size of the Data Set */
#define SIZE (40)

int print_array(unsigned char A[],int length){
  #ifdef VERBOSE
  printf("\nArray : \n");
  for (int i = 0; i < length; i++){
    printf("%d,",A[i]);
  }
  return 0;
  #endif
}
int find_minimum(unsigned char A[],int length){
  int v = 0;
  int minimum = A[0];
  for (int j = 1; j < length; j++){
    if (A [j] < minimum)
    minimum = A[j];
  }
  return minimum;
}
int find_maximum(unsigned char A[],int length){
  int b = 0;
  int maximum = A[0];
  for (int g = 1; g < length; g++){
    if (A[g] > maximum)
    maximum = A[g];
  }
  return maximum;
}
int find_median(unsigned char A[],int length){
  for (int s = 0; s < length - 1; s++){
    for (int d = 0; d < length - s - 1; d++){
      if (A[d] > A[d+1]){
        int temp = A[d];
        A[d] = A[d+1];
        A[d+1] = temp;
        }
    }
  }

  int median = (A[(length/2)-1]+A[length/2])/2;
  return median;
}
int find_mean(unsigned char A[],int length){
  double sum = 0 ;
  for (int n = 0; n < length; n++){
     sum = sum + A[n];
  }
  int mean = sum / length;
  return mean;
}
int sort_array(unsigned char A[],int length){
  for (int k = 0; k < length - 1; k++){
    for (int l = 0; l < length - k - 1; l++){
      if (A[l] < A[l+1]){
        int temp = A[l];
        A[l] = A[l+1];
        A[l+1] = temp;
        }
    }
  }
  printf("\nSorted Array : \n");
  for (int k = 0; k < length; k++){
    printf("%d,",A[k]);
  }
  return 0;
}
int print_statistics(unsigned char A[],int length){
  printf("                                                    ");
  printf("\nminimum = %d \n",find_minimum(A,length));
  printf("maximum = %d \n",find_maximum(A,length));
  printf("mean = %d \n",find_mean(A,length));
  printf("median = %d \n",find_median(A,length));
  return 0;
}
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_array(test,SIZE);
  print_statistics(test,SIZE);
  sort_array(test,SIZE);
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */
