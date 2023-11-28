#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for a buff
 * @file: file buffer
 *
 * Return: pointer to buffer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write stp %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - closes file descriptors
 * @fd: file descriptor
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int strt, stp, r, w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	strt = open(argv[1], O_RDONLY);
	r = read(strt, buff, 1024);
	stp = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (strt == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read strt file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(stp, buff, r);
		if (stp == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write stp %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(strt, buff, 1024);
		stp = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(strt);
	close_file(stp);

	return (0);
}
