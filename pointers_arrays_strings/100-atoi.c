#include "main.h"

/**
 * _atoi - converts a string to an integer safely including INT_MIN
 * @s: pointer to the string
 *
 * Return: the integer value
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int result = 0;

	/* Skip non-digit characters and handle signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
			break;
		i++;
	}

	/* Convert digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	if (sign == -1)
		return (-((int)result));
	return ((int)result);
}
