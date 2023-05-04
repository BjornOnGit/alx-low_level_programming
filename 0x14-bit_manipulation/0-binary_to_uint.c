/*
 * File: 0-binary_to_uint.c
 * Auth: Eze Francis Ogonnaya
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

unsigned int binary_to_uint(const char *b){
    /* Check for invalid input by iterating with a for loop and then an if condition*/

    for ( int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] != '0' && b[i] != '1')
        {
            printf("That input is invalid: %s\n", b);
            return 0;
        }
        
    }

    /* assign and initialize a value of zero to the unsigned integer*/
    unsigned int num = 0;

    /*iterate through the binary number and calculate the value of the unsigned integer*/
    for ( int i = 0; b[i] != '\0'; i++)
    {
        num = (num << 1) | (b[i] - '0');
    }

    return num;
}

unsigned int binary_to_uint(const char *b);

int main(int argc, char const *argv[])
{
    const char *b = "1010";
    unsigned int num = binary_to_uint(b);
    printf("The unsigned integer value of %s is %u\n", b, num);
    return 0;
}
