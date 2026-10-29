/*
 * ch5 / 5.7 Multi-dimensional Arrays
 * day_of_year(year, month, day) -> day of the year
 * month_day(year, yearday, &month, &day) -> month and day
 * daytab[2][13] holds the days per month for normal [0] and leap [1] years
 * (column 0 is unused so months are 1..12).
 * Ex 5-8: there was no error checking in day_of_year or month_day.
 * Now invalid input returns -1 (day_of_year) or sets month = day = -1
 * (month_day). Uses the test main() from the slides.
 */
#include <stdio.h>

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* is_leap: 1 if divisible by 4 and not by 100, or divisible by 400 */
int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/* day_of_year: set day of year from month & day; -1 on bad input */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 1 || month < 1 || month > 12)
        return -1;
    leap = is_leap(year);
    if (day < 1 || day > daytab[leap][month])
        return -1;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year; -1, -1 on bad input */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year < 1 || yearday < 1) {
        *pmonth = *pday = -1;
        return;
    }
    leap = is_leap(year);
    if (yearday > (leap ? 366 : 365)) {
        *pmonth = *pday = -1;
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(void)
{
    int yearday, month, day;

    yearday = day_of_year(1988, 2, 29);
    printf("%d\n", yearday);                            /* 60 */

    yearday = day_of_year(2020, 2, 31);
    printf("%d\n", yearday);                            /* -1: Feb 31 does not exist */

    month_day(1988, 60, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);         /* 2, 29 */

    month_day(1999, 366, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);         /* -1, -1: 1999 has 365 days */
    return 0;
}
