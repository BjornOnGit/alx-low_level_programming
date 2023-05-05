/**
* File: 4-clear_bit.c
* Auth: Eze Francis Ogonnaya
*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * clear_bit - sets the value of a bit at a given index to 0
  * @n: the value of the bit
  * @index: the given index
  * Return: -1 where there's an error
  * otherwise, the value is set to 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index < 0 || index >= sizeof(unsigned int) * 8)
	{
		return (-1);
	}
	*n &= ~(1 << index);
	return (1);
}
