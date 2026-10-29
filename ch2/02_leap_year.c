/*
 * ch2 / 2.5 Arithmetic Operators, 2.6 Relational and Logical Operators
 * A year is a leap year if it is divisible by 4 but not by 100,
 * except that years divisible by 400 ARE leap years.
 */
#include <stdio.h>

/* is_leap: return 1 if year is a leap year, 0 otherwise */
int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main(void)
{
    int years[] = { 1900, 2000, 2024, 2026 };
    int i;

    for (i = 0; i < 4; i++)
        printf("%d is %sa leap year\n", years[i], is_leap(years[i]) ? "" : "not ");
    return 0;
}
