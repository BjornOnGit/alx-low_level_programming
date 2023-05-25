/**
* File: 3-set_bit.c
* Auth: Eze Francis Ogonnaya
**/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * set_bit - it sets the value of a bit at a given index to 1
  * @n: the value of the bit.
  * @index: the index of the bit
  * Return: -1 if there is an error, otherwise, bit is set to 1
  */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned int) * 8)
	{
		return (-1);
	}
	*n ^= (1 << index);
	return (1);
}
