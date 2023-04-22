/**
* @brief  implementation of my_itoa() and my_atoi() function.
*
**/

#include "data.h"

/********************** my_itoa() *********************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t buffer[11];
    uint8_t *buffer_ptr;
    buffer_ptr = buffer;
    int i;
    unsigned v;

    int sign = (base == 10 && data < 0);    
    if (sign)
        v = -data;
    else
        v = (unsigned)data;

    while (v || buffer_ptr == buffer)
    {
        i = v % base;
        v /= base; 
        if (i < 10)
          *buffer_ptr++ = i + '0';
        else
          *buffer_ptr++ = i + 'a' - 10;
    }

    uint8_t len = buffer_ptr - buffer;

    if (sign) 
    {
        *ptr++ = '-';
        len++;
    }

    while (buffer_ptr > buffer)
        *ptr++ = *--buffer_ptr;

    return len;
}

/************************* my_atoi() **********************************/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t deci = 0;
    int32_t mul;
    int32_t character;
    bool neg_no = 0;

    if (*ptr == '-'){
        ptr++;
        digits -= 1;
        neg_no = 1;
    }
    while ( (character = *ptr++) != 0 ){
        if (character > '9'){  
            character -= '7'; 
        } else {
            character -= '0';  
        }
        mul = 1;
        for (uint8_t i = digits - 1; i > 0; i--){
            mul *= base;
        }
        character *= mul;
        deci += character;
        digits -= 1;
    }
    
    if (neg_no){
        deci = 0 - deci;
    }
    
    return deci;

}