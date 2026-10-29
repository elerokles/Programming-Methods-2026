/*
 * ch1 / 1.3 The for statement, 1.4 Symbolic Constants
 * Ex 1-5: print the temperature table in reverse order, from 300 degrees to 0.
 */
#include <stdio.h>

#define LOWER 0      /* lower limit of table */
#define UPPER 300    /* upper limit */
#define STEP  20     /* step size */

int main(void)
{
    int fahr;

    /* the for loop keeps initialization, test and step on one line */
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}
