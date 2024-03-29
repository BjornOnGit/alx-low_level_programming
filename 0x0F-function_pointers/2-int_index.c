#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - a function that searches for an integer.
 * @array: array as an argument.
 * @size: size of the array.
 * @cmp: function pointer
 * Return: 0 or -1.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
    int i;

    if (size <= 0 || array == NULL || cmp == NULL)
    {
        return (-1);
    }
    
    if (array != NULL && cmp != NULL)
    {
        for ( i = 0; i < size; i++)
        {
            if (cmp(array[i]))
                return (i);
        }
    }
    return (-1);
}