#include "main.h"

/**
 * wildcmp - compares two strings considering wildcard '*'
 * @s1: first string
 * @s2: second string (may contain '*')
 *
 * Return: 1 if strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings end, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If s2 has '*', it can match empty or any sequence */
	if (*s2 == '*')
	{
		/* Skip multiple '*' characters */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* '*' matches empty OR consumes one char from s1 */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);

		return (wildcmp(s1, s2 + 1));
	}

	/* If characters match, move forward */
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
