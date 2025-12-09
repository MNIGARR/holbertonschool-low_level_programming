#include "main.h"

/**
 * print_triangle - prints a triangle using '#'
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int row, col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		/* print spaces first */
		for (col = 1; col <= size - row; col++)
			_putchar(' ');

		/* then print #'s */
		for (col = 1; col <= row; col++)
			_putchar('#');

		_putchar('\n');
	}
}
