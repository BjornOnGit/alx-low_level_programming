/**
* File: 100-get_endianness.c
* Auth: Eze Francis Ogonnaya
*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * get_endianness - checks the endianness
  * Return: 1 when it's a little endian
  *         0 when it's a big endian
 */
int get_endianness(void)
{
	int num = 1;
	char *end = (char *)&num;

	if (*end == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
