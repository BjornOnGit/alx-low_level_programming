/**
* File: 5-flip_bits.c
* Auth: Eze Francis Ogonnaya
**/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * flip_bits - counts the number of bits needed
  * to flip from one number to another.
  * @n: the number
  * @m: the number to flip into
  * Return: count - the number of bits required
  * for the flip
  */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int var = n ^ m, count = 0;

	while (var > 0)
	{
		count += (var & 1);
		var >>= 1;
	}
	return (count);
}
