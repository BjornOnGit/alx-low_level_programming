/**
* file: 0-read_textfile.c
* author: Eze Francis
*
*/
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
* read_textfile - Reads a text file and prints it to POSIX stdout.
* @filename: A pointer to the name of the file.
* @letters: The number of letters the
*           function should read and print.
*
* Return: If the function fails or filename is NULL - 0.
*         O/w - the actual number of bytes the function can read and print.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t opn, rdd, wrn;
char *buffer;
if (filename == NULL)
{
return (0);
}
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
return (0);
}
opn = open(filename, O_RDONLY);
rdd = read(opn, buffer, letters);
wrn = write(STDOUT_FILENO, buffer, rdd);
if (opn == -1 || rdd == -1 || wrn == -1 || wrn != rdd)
{
free(buffer);
return (0);
}
free(buffer);
close(opn);
return (wrn);
}
