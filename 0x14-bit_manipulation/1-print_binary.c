/**
* File: 1-print_binary.c
* Auth: Eze Francis Ogonnaya
**/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
  * print_binary - prints the binary represenation of a number
  * @n: the number to be printed in binary
  * Return: void .
  */
void print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	putchar((n & 1) + '0');
}
