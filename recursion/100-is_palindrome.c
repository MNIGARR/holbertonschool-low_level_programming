#include "main.h"

int _strlen_rec(char *s);
int _palindrome_helper(char *s, int start, int end);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: pointer to the string
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);

	return (_palindrome_helper(s, 0, _strlen_rec(s) - 1));
}

/**
 * _strlen_rec - returns length of a string (recursive)
 * @s: string
 *
 * Return: length
 */
int _strlen_rec(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_rec(s + 1));
}

/**
 * _palindrome_helper - helper function to check palindrome
 * @s: string
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int _palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (_palindrome_helper(s, start + 1, end - 1));
}
