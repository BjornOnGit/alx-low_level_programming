#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - function that prints a name.
 * @name: string variable
 * @f: function pointer
 */

void print_name(char *name, void (*f)(char *))
{
    if (f != NULL)
    {
        f(name);
    } 
}