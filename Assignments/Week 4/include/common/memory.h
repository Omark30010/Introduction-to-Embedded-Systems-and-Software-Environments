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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Omar Khalid Gohar
 * @date 23 4, 2023
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Sets a value of a data array
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @breif Move data from one memory location to another.
 *
 * This function takes two byte pointers (one source and one destination) and
 * a length of bytes to move from the source location to the destination. All
 * opertions should be performed using pointer arthematics.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to distination memory location
 * @param length number of bytes to copy
 *
 * @return a pointer to distination(dst)
**/
uint8_t * my_memmove(uint8_t *src, uint8_t *dst, uint8_t length);

/**
 * @breif Copy data from one memory location to another.
 *
 * This function takes two byte pointers (one source and one destination) and
 * a length of bytes to copy from the source location to the destination. All
 * opertions should be performed using pointer arthematics.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to distination memory location
 * @param length number of bytes to copy
 *
 * @return a pointer to distination(dst)
**/
uint8_t * my_memcopy(uint8_t *src, uint8_t *dst, uint8_t length);

/**
 * @breif Set location of memory to a given value.
 *
 * This should take a pointer to a memory location, a length in bytes
 * and set all locations of that memory to a given value. All operations
 * should be performed using pointer arthematics. You should NOT use set_all() function.
 *
 * @param src Pointer to memory location
 * @param length numberof bytes
 * @param value value to set memory
 *
 * @return a pointer to source(src)
**/
uint8_t * my_memset(uint8_t *src, uint8_t length, uint8_t value);

/**
 * @breif Zero out memory.
 *
 * This should take a pointer to a memory location, a length in bytes
 * and zero out all of the memory. All operations should be performed using
 * pointer arthematics. You should not use clear_all() function.
 *
 * @param src Pointer to memory location
 * @param length numberof bytes
 *
 * @return a pointer to source(src)
**/
uint8_t * my_memzero(uint8_t *src, size_t length);

/**
 * @breif Reserve a number of bytes in memory.
 *
 * This should take a pointer to a memory location, a length in bytes
 * and reserve all of the bytes. All operations should be performed using
 * pointer arthematics
 *
 * @param src Pointer to memory location
 * @param length numberof bytes
 *
 * @return a pointer to src
**/
uint8_t * my_reverse(uit8_t *src, size_t length);

/**
 * @brief Alocate dynamic memory.
 *
 * This function takes number of words to allocate in dynamic memory.
 *
 * @param length number of words
 *
 * @return Should return a pointer to memory if successful, or a Null Pointer if not successful
**/
uint32_t * reserve_words(size_t length);

/**
 * @brie Free a dynamic memory allocation.
 *
 * This function takes a pointer src and free the dynamic memory allocation.
 * All operations should be performed using pointer arthimatic.
 *
 * @param src Pointer to the memory that should be free
 *
 * @return void
**/
void free_words(uint32_t *src);
#endif /* __MEMORY_H__ */

