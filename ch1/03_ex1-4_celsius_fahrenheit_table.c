/*
 * ch1 / 1.2 Variables and Arithmetic Expressions
 * Ex 1-4: print the corresponding Celsius to Fahrenheit table.
 * F = 9C/5 + 32 (integer arithmetic, like the first version in the slides)
 */
#include <stdio.h>

int main(void)
{
    int fahr, celsius;
    int lower, upper, step;

    lower = -20;    /* lower limit of temperature table */
    upper = 150;    /* upper limit */
    step = 10;      /* step size */

    printf("Celsius to Fahrenheit conversion table:\n\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = 9 * celsius / 5 + 32;
        printf("%3d %6d\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
