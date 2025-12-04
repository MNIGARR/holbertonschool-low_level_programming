#include <stdio.h>

/* main - display alphabet except q and except 
return - seccess
*/

int main(void) 
{
    char c;

    for (c = 'a'; c <= 'z'; c++)
    {
        if(c != 'q' && c != 'e')
        {
            putchar(c);
        }
    }
    putchar('\n');

    return(0);
}
