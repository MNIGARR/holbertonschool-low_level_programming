#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * err_exit - prints an error message to stderr and exits with a given code
 * @code: exit status code (97, 98, 99, 100)
 * @name: filename related to the error (used for 98 and 99), or NULL
 * @fd: file descriptor related to the error (used for 100)
 */
static void err_exit(int code, const char *name, int fd)
{
	if (code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	else if (code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name);
	else if (code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
	else if (code == 100)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(code);
}

/**
 * safe_close - closes a file descriptor or exits with code 100 on failure
 * @fd: file descriptor to close
 */
static void safe_close(int fd)
{
	if (close(fd) == -1)
		err_exit(100, NULL, fd);
}

/**
 * copy_file - copies content from one file descriptor to another
 * @fd_from: file descriptor to read from
 * @fd_to: file descriptor to write to
 * @from: source filename (for error messages)
 * @to: destination filename (for error messages)
 */
static void copy_file(int fd_from, int fd_to, char *from, char *to)
{
	ssize_t r, w;
	char buf[BUF_SIZE];

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			safe_close(fd_from);
			safe_close(fd_to);
			err_exit(99, to, 0);
		}
	}
	if (r == -1)
	{
		safe_close(fd_from);
		safe_close(fd_to);
		err_exit(98, from, 0);
	}
}

/**
 * main - entry point; copies the content of a file to another file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
		err_exit(97, NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		err_exit(98, av[1], 0);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		safe_close(fd_from);
		err_exit(99, av[2], 0);
	}

	copy_file(fd_from, fd_to, av[1], av[2]);

	safe_close(fd_from);
	safe_close(fd_to);

	return (0);
}
