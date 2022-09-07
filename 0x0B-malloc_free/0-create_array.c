#include <stdio.h>
#include <stdlib.h>
/**
 * create_array - creates an array of characters,
 * and initializes to a specific character
 * @size: size of the array
 * @a: char to be assigned to array
 * Return: pointer to the array initialized or NULL
 */

char *create_array(unsigned int size, char a)
{
    char *n = malloc(sizeof(a) * size);

    if (size == 0 || n == 0)
            return (NULL);

    while (size--)
            n[size] = a;

    return (n);
}

