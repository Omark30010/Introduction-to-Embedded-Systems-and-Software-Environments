/**
 * @file: stats.h
 * @brief header file, contains declaration and documentation for the functions from stats.c file
 *
 *
 *
 * @author: Omar Gohar
 * @date: 23/04/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**  declaration of find_median() function
 * @brief calculates the median of array
 *
 * This function takes an array of data and array length as inputs. The function will
 * compute the median of input array and return the median as output.


 * @param myArray[] array of data
 * @param length    length of input array
 * @return the computed median of array
 *
 */

double find_median(unsigned char myArray[], int length);

/**  declaration of find_mean() function
 * @brief calculates the mean of array
 *
 * This function takes as input an array of data and array length as inputs. The function will
 * compute the mean of input array and return the mean as output.


 * @param myArray[] array of data
 * @param length    length of input array
 * @return the computed mean of array
 *
 */

double find_mean(unsigned char myArray[], int length);


/**    declaration of find_maximum() function
 *
 * @brief calculates the maximum of array
 *
 * This function takes as input an array of data and array length as inputs. The function will
 * find the maximum of input array and return the maximum as output float


 * @param myArray[] array of data
 * @param length    length of input array
 * @return the maximum element of array
 *
 */

unsigned char find_maximum(unsigned char myArray[], int length);


/**  declaration of find_minimum() function
 *
 * @brief finds the minimum element of array
 *
 * This function takes  an array of data and array length as inputs. The function will
 * find the minimum of input array and return the minimum output

 * @param myArray[] array of data
 * @param length    length of input array
 * @return the minimum element of array
 *
 */

unsigned char find_minimum(unsigned char myArray[], int length);


/**   declaration of sort_array() function
 *
 * @brief sorts the array from largest to smallest element.
 *
 * This function takes  an array of data and array length as inputs. The function will
 * sort the elements of array from largest to smallest, e.g the zeroth element should be
 * largest value and the last element should be the smallest value.

 * @param myArray[] array of data
 * @param length    length of input array
 * @return a pointer to array.
 *
 */

unsigned char *sort_array(unsigned char myArray[], int length);


/**   declaration of print_statistics() function
 *
 * @brief prints the statistics of array.
 *
 * This function takes  an array of data and array length as inputs. The function will
 * print the statistics of array including, median, mean, minimum and maximum.

 * @param myArray[] array of data
 * @param length    length of input array
 *
 *
 */

void print_statistics(unsigned char myArray[], int length);


/**   declaration of print_array() function
 *
 * @brief prints the contents of array.
 *
 * This function takes  an array of data and array length as inputs. The function will
 * print the contents of array.

 * @param myArray[] array of data
 * @param length    length of input array
 *
 */

void print_array(unsigned char myArray[], int length);

































#endif /* __STATS_H__ */
