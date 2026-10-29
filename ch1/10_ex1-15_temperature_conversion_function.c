/*
 * ch1 / 1.7 Functions
 * Ex 1-15: rewrite the temperature conversion program of section 1.2
 * to use a function for the conversion.
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float fahr_to_celsius(float fahr);

int main(void)
{
    float fahr;

    printf("Fahr  Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%4.0f %8.1f\n", fahr, fahr_to_celsius(fahr));
    return 0;
}

/* fahr_to_celsius: convert a Fahrenheit temperature to Celsius */
float fahr_to_celsius(float fahr)
{
    return (5.0f / 9.0f) * (fahr - 32.0f);
}
