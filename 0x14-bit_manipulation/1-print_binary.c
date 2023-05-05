/**
* File: 0-binary_to_uint.c
* Auth: Eze Francis Ogonnaya
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void print_binary(unsigned long int n)
{
    if (n > 1)
    {
        print_binary(n >> 1);
    }
    _putchar((n & 1) ? '1' : '0');
}