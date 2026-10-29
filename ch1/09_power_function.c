/*
 * ch1 / 1.7 Functions, 1.8 Arguments - Call by Value
 * power(m, n) raises integer m to a positive integer power n.
 * n is a copy of the caller's value (call by value), so changing it
 * inside power() does not affect the caller.
 */
#include <stdio.h>

int power(int base, int n);   /* function prototype */

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %5d %7d\n", i, power(2, i), power(-3, i));
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)   /* n is used as a counter: call by value */
        p = p * base;
    return p;
}
