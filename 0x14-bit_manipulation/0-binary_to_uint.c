/**
* File: 0-binary_to_uint.c
* Auth: Eze Francis Ogonnaya
**/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 *
 * @b: A pointer to a string containing the binary number.
 *
 * Return: The unsigned integer converted from the binary number, or 0 if
 *         an error occurs.
 **/

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	unsigned int run = 1;
	int ass;

	if (!b)
	{
		return (0);
	}
	for (ass = 0; b[ass];)
	{
		ass++;
	}
	for (ass -= 1; ass >= 0; ass--)
	{
		if (b[ass] != '0' && b[ass] != '1')
		{
			return (0);
		}
		num += (b[ass] - '0') * run;
		run *= 2;
	}
	return (num);
}
