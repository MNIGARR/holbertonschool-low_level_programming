#include <stdlio.h>

// main - Prints alphabet in lowecase and uppercase

// return : always(0)

int main(void) {

    char c; 

    for(c = 'a': c <= 'z'; c++)
        putchar(c);

    for(c = 'A'; c <= 'Z'; c++)
        putchar(c);

    putchar('\n');

    return(0);
}
