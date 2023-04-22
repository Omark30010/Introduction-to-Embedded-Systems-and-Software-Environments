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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Omar Khalid gohar
 * @date 23 4, 2023
 *
 */
#include <memory.h>

/***********************************************************
                Function Definitions
***********************************************************/

/*****************set_value()***********************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

/*****************clear_value()***********************/
void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

/*****************get_value()***********************/
char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

/*****************set_value()***********************/
void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

/*****************clear_all()***********************/
void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/*****************my_memmove()***********************/
uint8_t * my_memmove(uint8_t *src, uint8_t *dst, uint8_t length){
  int i ;
  uint8_t *temp_ptr;
  for( i = 0; i < length; i++)
  {
    temp_ptr[i] = src[i];
  }
  for( i = 0; i < length; i++)
  {
    dst[i] = temp_ptr[i];
  }

  return dst;
}

/*****************my_memcopy()***********************/
uint8_t * my_memcopy(uint8_t *src, uint8_t *dst, uint8_t length){
  int i ;
  for (i = 0; i < length; i++)
  {
    *( dst + i ) = *( src + i );
  }

  return dst;

}

/*****************my_memset()***********************/
uint8_t * my_memset(uint8_t *src, uint8_t length, uint8_t value){
  unsigned char i ;

  for ( i = 0; i < length; ++i)
  {
    *( src + i ) = value ;
  }

  return src ;

}

/*****************my_memzero()***********************/
uint8_t * my_memzero(uint8_t *src, size_t length){
	uint8_t i;

  for (i = 0; i < length; ++i)
  {
    *( src + i ) = '0' ;
  }

  return src;

}

/*****************my_reverse()***********************/
uint8_t * my_reverse(uit8_t *src, size_t length){
  int lo;
  int hi;

  for( lo = 0, hi = length - 1; hi > lo; lo++, hi--)
    {

      uint8_t *tmp = ( long int ) src[lo];
      src[lo] = src[hi];
      src[hi] = ( intptr_t ) tmp;

    }

    return src;


}

/*****************reserve_words()***********************/
uint32_t * reserve_words(size_t length){
  uint32_t *word_ptr;
  word_ptr = calloc( length, sizeof(uint32_t));
  if( word_ptr == NULL )
    return NULL;
  else
    return word_ptr;

}

/*****************free_words()***********************/
void free_words(uint32_t *src){
  if( src != NULL )
    free(src);

}

