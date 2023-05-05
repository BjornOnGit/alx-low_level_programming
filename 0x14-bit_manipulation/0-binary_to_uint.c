/*
* File: 0-binary_to_uint.c
* Auth: Eze Francis Ogonnaya
*/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* binary_to_uint - the function name
* @b: parameter of type const char *.
* Return: unsigned int .
*/
unsigned int binary_to_uint(const char *b)
{
/** assign and initialize
*  a value of zero
* to the unsigned integer
*/
	unsigned int num = 0, run = 1;
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
