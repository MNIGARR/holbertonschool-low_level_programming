#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_error_and_exit - prints error message to STDERR and exits
 * @code: exit status code
 * @msg: error prefix message
 * @name: file name or fd string to print
 */
static void print_error_and_exit(int code, const char *msg, const char *name)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, name);
	exit(code);
}

/**
 * close_fd - closes a file descriptor and exits on failure
 * @fd: file descriptor
 */
static void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, otherwise exits with required codes
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t rbytes;
	char buf[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file ", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error_and_exit(99, "Error: Can't write to ", av[2]);
	}

	while ((rbytes = read(fd_from, buf, 1024)) > 0)
	{
		ssize_t wbytes = 0, written;

		while (wbytes < rbytes)
		{
			written = write(fd_to, buf + wbytes, rbytes - wbytes);
			if (written == -1)
			{
				close_fd(fd_from);
				close_fd(fd_to);
				print_error_and_exit(99, "Error: Can't write to ", av[2]);
			}
			wbytes += written;
		}
	}

	if (rbytes == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error_and_exit(98, "Error: Can't read from file ", av[1]);
	}

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
