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

    while (dest[i] != '\0')
        i++;
    
    while (str[j] != '\0')
    {
        dest[i] = str[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return (dest);
}