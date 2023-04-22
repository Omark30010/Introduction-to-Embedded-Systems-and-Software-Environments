/**
 * @file data.h
 * @brief basic data manipulation operations
 *
 * This header file provides an abstraction data manipulation
 * operations via function calls.
 *
 * @Author Omar Khalid Gohar
 * @dated  23 4 2023
 *
 **/

 #ifndef __DATA_H__
 #define __DATA_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "memory.h"
/********************************* my_itoa() *****************************/
/**
* @brief Convert integer-to-ASCII
*
* This function converts data from standard integer to ASCII string. Function takes
* three inputs data, ptr and base which specify the signed 32-bit integer data to be
* converted, unsigned 8-bit integer pointer and integer value spicifying the base
* from 2 to 16. 32-bit signed integer is converted into ASCII character string and
* string is copied into pointer ptr. function should return the length of converted
* ASCII string including null character. This function should handle signed data and
* may not use any string functions or libraries.
*
* @param data: signed 32-bit integer to be converted itno ASCII string
* @param ptr: unsigned 8-bit integer pointer pointed to ASCII char string
* @param base: integer value specifying the base from 2 to 10 to which you wish to convert
* @retun length of ASCII string
**/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/********************************** my_atoi() ************************/
/**
* @brief Converts ASCII-to-integer
*
* This function converts an ASCII character string into a 32-bit signed integer.
* function takes ptr, digits and bases as inputs and return a 32-bit signed integer.
* the character string to be converted is passed as a pointer(ptr). the number of
* characters in the string are passed as digits and base contains an integer value
* specifying base to which the string is converted to.
*
* @param ptr: unsigned 8-bit pointer to the character string to be converted
* @param digits: no of digits in character set
* @param base: integer value specifying base from 2 to 16
* @return the converted 32-bit signed integer
**/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

 #endif
