/**
 * _memset - fills the first n bytes of memory pointed to by s with byte b
 * @s: pointer to the memory area
 * @b: byte value to fill
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
