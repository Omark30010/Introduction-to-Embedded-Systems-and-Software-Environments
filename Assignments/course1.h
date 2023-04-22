/**
* @file course1.h
* @brief final assesment functions of course 1
*
* These functions will test and varify memory manipulation and data
* manipulation functions, that we have built in this assignment.
*
* @author Omar Khalid Gohar
* @dated 23 4 2023
*
**/
/**********************************************************************/
#ifndef __COURSE1_H__
#define __COURSE1_H__

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "memory.h"
#include "stats.h"
#include "platform.h"
#include "data.h"

#define BASE_16 (16)
#define BASE_10 (10)
#define TEST_DATA_1 (2345)
#define TEST_DATA_2 (-2345)

#define BYTES (8)

/**
* @brief call all other test functions
**/
int8_t course1();

/**
* @brief This function will test to atoi and itoa conversions
*
**/
int8_t test_data1();

/**
* @brief This function will test too atoi and itoa conversions
*
**/
int8_t test_data2();

/**
* @brief This function will test non-overlapped memmove.
*
**/
int8_t test_memmove1();

/**
* @brief This function will test overlapped memmove
*
* This function will test overlapped memmove where there is
* overlap of the end of destination and start of the source regions
**/
int8_t test_memmove2();

/**
* @brief This function will test overlapped memmove
*
* This function will test overlapped memmove where there is
* overlap of the start of destination and end of the source regions.
**/
int8_t test_memmove3();

/**
* @brief This function will test memcopy
*
**/
int8_t test_memcopy();

/**
* @brief This function will test memset and memzero.
*
**/
int8_t test_memset();

/**
* @brief This function will test reverse.
*
**/
iInt8_t test_reverse();

#endif
