/**
* File: 2-get_bit.c
* Auth: Eze Francis Ogonnaya
**/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * get_bit - gets the value of a bit at a given index
  * @n: the bit
  * @index: The point at which the value is gotten - they start from 0
  * Return: -1 where there is an error otherwise, the bit is at index
  */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned int) * 8)
	{
		return (-1);
	}
	if ((n & (1 << index)) == 0)
	{
		return (0);
	}
	return (1);
}
