/**
* @file course1.c
*
* @brief implementation of test functions
*
* @author Omar Khalid Gohar
* @dated 23 4, 2018
**/
/*************************** test_data1() ********************************/
int8_t test_data1()
{
    uint8_t ptr[10] = {0};
    uint8_t length;
    uint32_t return_data;

    length = my_itoa( TEST_DATA_1, ptr, BASE_10 );
    return_data = my_atoi( ptr, length, BASE_10 );
    if( return_data == TEST_DATA_1 )
    {
        printf("itoa() and atoi() function pass test case1.\n");
    }
    else
    {
        printf("itoa() and atoi() functions fail test case2.\n");
    }

    return 0;
}

/******************************* test_data2() ******************************/

int8_t test_data2()
{
    uint8_t ptr[10] = {0};
    uint8_t length;
    uint32_t return_data;

    length = my_itoa( TEST_DATA_2, ptr, BASE_10 );
    return_data = my_atoi( ptr, length, BASE_10 );
    if( return_data == TEST_DATA_2 )
    {
        printf("itoa() and atoi() function pass test case2.\n");
    }
    else
    {
        printf("itoa() and atoi() functions fail test case2.\n");
    }

    return 0;
}

/******************************* test_memmove1() *******************************/
int8_t test_memmove1()
{
    uint8_t arr_src[] = "Hello Mars.";
    uint8_t arr_dst[12] = {0} ;
    uint8_t *arr_dst_ptr;
    arr_dst_ptr = my_memmove( arr_src, arr_dst, BYTES );
    if (strcmp(arr_dst_ptr, " Hello"))
    {
        printf("my_memmove() passes test case1.\n");
    }
    else
        printf("my_memmove() fails test case1.\n");



    return 0;
}

/***************************** test_memmove2() *********************************/
int8_t test_memmove2()
{
    uint8_t arr_src[100] = "Hello Martians.";
    uint8_t *arr_dst_ptr;

    // overlap of the end of destination and start of the source regions
    arr_dst_ptr = my_memmove( (arr_src + 3 ), arr_src, 7 );
    if (arr_dst_ptr != NULL)
    {
        printf("my_memmove() passes test case2.\n");
    }
    else
        printf("my_memmove() fails test case2.\n");

    return 0;
}

/***************************** test_memmove3() *********************************/
int8_t test_memmove3()
{
    uint8_t arr_src[100] = "Hello Martians.";
    uint8_t *arr_dst_ptr;

    // overlap of the start of destination and end of the source regions
    arr_dst_ptr = my_memmove( arr_src , (arr_src + 5), 7 );
    if (arr_dst_ptr != NULL)
    {
        printf("my_memmove() passes test case3.\n");
    }
    else
        printf("my_memmove() fails test case3.\n");

    return 0;
}

/****************************** test_memcopy() **********************************/
int8_t test_memcopy()
{
    uint8_t arr_src[] = "Hello Mars.";
    uint8_t arr_dst[12] = {0} ;
    uint8_t *arr_dst_ptr;
    arr_dst_ptr = my_memcopy( arr_src, arr_dst, BYTES );
    if ( strcmp(arr_dst_ptr, " Hello"))
    {
        printf("my_memcopy() passes test case1.\n");
    }
    else
        printf("my_memcopy() fails test case1.\n");


    return 0;
}

/********************************** test_memset() *******************************/
int8_t test_memset()
{
    uint8_t val = 'p';
    uint8_t csrc[] = "Hello";
    uint8_t *set_ptr ;
    uint8_t *zero_ptr;

    set_ptr = my_memset( csrc, BYTES, val );
    zero_ptr = my_memzero( csrc, BYTES );

    if (strcmp(zero_ptr, " 00000") && strcmp(set_ptr, "ppppp") )
    {
        printf("my_memset() and my_memzero() passes test case.\n");
    }
    else
        printf("my_memset() and my_memzero() fails test case.\n");


}
