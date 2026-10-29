/*
 * ch1 / 1.2 Variables and Arithmetic Expressions
 * Ex 1-3: print a Fahrenheit-Celsius table with a heading above it.
 * Uses C = (5/9)(F-32) with floating point so the result is not truncated.
 */
#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahr  Celsius\n");   /* heading (Ex 1-3) */
    printf("-------------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0f / 9.0f) * (fahr - 32.0f);
        printf("%4.0f %8.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
