#include<stdio.h>
#include<stdlib.h>
#include "main.h"

/**
 * _strlen - calculates number of char in a string
 * @s: string variable
 * Return: size of string
 */

int _strlen(char *s)
{
    int size = 0;

    while (s[size] != '\0')
        size++;

    return (size);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string variable
 * @s2: second string variable
 * Return: string pointer
 */

char *str_concat(char *s1, char *s2)
{
    int size1, size2, i;
    char *c;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";
    
    size1 = _strlen(s1);
    size2 = _strlen(s2);
    c = malloc(((size1 + size2) * sizeof(char)) + 1);
    if (c == 0)
        return (0);
    
    for (i = 0; i <= size1 + size2; i++)
    {
        if (i < size1)
            c[i] = s1[i];
        else
            c[i] = s2[i - size1];
    }

    c[i] = '\0';

    return (c);
}