#include "main.h"

int is_prime_helper(int n, int divisor);

/**
 * is_prime_number - returns 1 if n is a prime number, otherwise 0
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - helper function to check primality
 * @n: number
 * @divisor: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor)
{
	if (divisor * divisor > n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_prime_helper(n, divisor + 1));
}
