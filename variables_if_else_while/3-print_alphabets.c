#include <stdlio.h>

int main(void) {

    char c; 

    // print lowercase
    for(c = 'a': c <= 'z'; c++)
        putchar(c);

    // print uppercase
    for(c = 'A'; c <= 'Z'; c++)
        putchar(c);

    putchar('\n');
    return(0);
}
