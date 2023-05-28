/**
* file: 3-cp.c
* author: Eze Francis
*
*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Copies the contents of a file to another file.
 * @argc - The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char const *argv[])
{
	int fd_r, fd_w, x, m, n;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_r = open(argv[1], O_RDONLY);
	if (fd_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((x = read(fd_r, buf, BUFSIZ)) > 0)
	{
		if (fd_w < 0 || write(fd_w, buf, x) != x)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_r);
			exit(99);
		}
	}
	if (x < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	m = close(fd_r);
	n = close(fd_w);
	if (m < 0 || n < 0)
	{
		if (m < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_r);
		}
		if (n < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_w);
		}
		exit(100);
	}
	return (0);
}
