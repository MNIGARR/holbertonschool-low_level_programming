#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * print_usage_and_exit - prints usage error and exits with 97
 */
static void print_usage_and_exit(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * exit_read_error - prints read error and exits with 98
 * @file: file name
 */
static void exit_read_error(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * exit_write_error - prints write error and exits with 99
 * @file: file name
 */
static void exit_write_error(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * close_fd - closes a fd, exits with 100 on failure
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
 * open_from - opens source file for reading
 * @file: file name
 *
 * Return: fd
 */
static int open_from(const char *file)
{
	int fd = open(file, O_RDONLY);

	if (fd == -1)
		exit_read_error(file);

	return (fd);
}

/**
 * open_to - opens/creates destination file
 * @file: file name
 *
 * Return: fd
 */
static int open_to(const char *file)
{
	int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
		exit_write_error(file);

	return (fd);
}

/**
 * write_all - writes exactly count bytes
 * @fd: destination fd
 * @buf: buffer
 * @count: bytes to write
 * @to_name: destination file name for error message
 */
static void write_all(int fd, char *buf, ssize_t count, const char *to_name)
{
	ssize_t written = 0;
	ssize_t w;

	while (written < count)
	{
		w = write(fd, buf + written, count - written);
		if (w == -1)
			exit_write_error(to_name);
		written += w;
	}
}

/**
 * copy_file - copies from one file to another using 1024-byte buffer
 * @from_name: source filename
 * @to_name: destination filename
 */
static void copy_file(const char *from_name, const char *to_name)
{
	int fd_from, fd_to;
	ssize_t r;
	char buf[BUF_SIZE];

	fd_from = open_from(from_name);
	fd_to = open_to(to_name);

	r = read(fd_from, buf, BUF_SIZE);
	while (r > 0)
	{
		write_all(fd_to, buf, r, to_name);
		r = read(fd_from, buf, BUF_SIZE);
	}

	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		exit_read_error(from_name);
	}

	close_fd(fd_from);
	close_fd(fd_to);
}

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	if (ac != 3)
		print_usage_and_exit();

	copy_file(av[1], av[2]);

	return (0);
}
