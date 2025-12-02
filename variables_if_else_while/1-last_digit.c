#include <stdio.h>
#include <stlib.h>
#include <time.h>

// main - Prints the last digit of a random number and checks its value

// Return: Always 0 (Sucess)

int main (void) {

    int n;
    int last_digit;

    srand(time(o));
    n = rand() -RAND_MAX / 2;
    last_digit= n % 10;

    prinf("Last digit of %d is %d", n, last_digit)

    if(last_digit > 5)
        prinf("and is greater than 5\n");
    else if(last_digit == 0)
        prinf("and is 0\n");
    else if(last_digit < 6)
        prinf("and is less than 6 and not 0\n")

    return 0;
}
