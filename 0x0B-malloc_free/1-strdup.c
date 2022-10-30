#include<stdio.h>
#include<stdlib.h>
#include "main.h"

/**
 * _strdup - return a pointer to a newly allocated space in
 * memory which contains a copy of the string given as a
 * parameter.
 * @str: string
 * Return: pointer or NULL
 */
char *_strdup(char *str)
{
    int i, size = 0;
    char *d;

    if (str == 0)
        return (NULL);

    while (str[size] != '\0')
        size++;

    d = malloc((sizeof(*str) * size) + 1);
     /* +1 is due to null byte or EOS character */

     if (d == 0)
        return (NULL);

    for (i = 0; i <= size; i++)
        d[i] = str[i];

    return (d);
}