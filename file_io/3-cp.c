#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

static void usage_exit(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

static void read_error_exit(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

static void write_error_exit(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

static void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

static int open_from(const char *file)
{
	int fd = open(file, O_RDONLY);

	if (fd == -1)
		read_error_exit(file);

	return (fd);
}

static int open_to(const char *file)
{
	int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
		write_error_exit(file);

	return (fd);
}

static void write_all(int fd, char *buf, ssize_t count, const char *to_name)
{
	ssize_t written = 0;
	ssize_t w;

	while (written < count)
	{
		w = write(fd, buf + written, count - written);
		if (w == -1)
			write_error_exit(to_name);
		written += w;
	}
}

static void copy_file(const char *from_name, const char *to_name)
{
	int fd_from, fd_to;
	ssize_t r;
	char buf[BUF_SIZE];

	fd_from = open_from(from_name);
	fd_to = open_to(to_name);

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
		write_all(fd_to, buf, r, to_name);

	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		read_error_exit(from_name);
	}

	close_fd(fd_from);
	close_fd(fd_to);
}

int main(int ac, char **av)
{
	if (ac != 3)
		usage_exit();

	copy_file(av[1], av[2]);
	return (0);
}
