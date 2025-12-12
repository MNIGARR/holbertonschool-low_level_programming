#include <stdio.h>

/**
    * _strcat - concatenates two strings
    * @dest: destination string
    * @src: source string
    *
    * Return: pointer to dest
*/
char *_strcat(char *dest, char *str) {
    int i = 0;
    int j = 0;

    /* find the end of dest */
    while (dest[i] != '\0')
        i++;

    /* append src to dest */
    while (str[j] != '\0')
    {
        dest[i] = str[j];
        i++;
        j++;
    }

    /* add terminating null byte */
    dest[i] = '\0';

    return (dest);
}