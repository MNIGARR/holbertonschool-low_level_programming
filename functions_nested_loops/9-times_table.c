#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
    int i, j, prod, tens, ones;

    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            prod = i * j;
            tens = prod / 10;
            ones = prod % 10;

            if (j == 0)
            {
                _putchar(ones + '0');
            }
            else
            {
                _putchar(',');
                _putchar(' ');

                if (prod < 10)
                    _putchar(' '); /* extra space for alignment */
                else
                    _putchar(tens + '0');

                _putchar(ones + '0');
            }
        }
        _putchar('\n');
    }
}
