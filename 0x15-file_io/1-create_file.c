/**
* file: 1-create_file.c
* author: Eze Francis
*
*/
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
  * create_file - the function that creates a file.
  * @filename: A pointer to the name of the file to create.
  * @text_content: A pointer to a string to write to the file.
  * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int opn, wrn, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		{
			len++;
		}
	}
	opn = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wrn = write(opn, text_content, len);
	if (opn == -1 || wrn == -1)
	{
		return (-1);
	}
	close(opn);
	return (1);
}
