#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	char *sep;
	char *str;

	va_start(args, format);

	i = 0;
	sep = "";

	while (format && format[i])
	{
		if (format[i] == 'c')
			printf("%s%c", sep, va_arg(args, int)), sep = ", ";
		if (format[i] == 'i')
			printf("%s%d", sep, va_arg(args, int)), sep = ", ";
		if (format[i] == 'f')
			printf("%s%f", sep, va_arg(args, double)), sep = ", ";
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sep, str), sep = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
