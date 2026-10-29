/*
 * ch3 / 3.7 Break and Continue
 * trim(s): remove trailing blanks, tabs and newlines; break leaves the loop
 * as soon as the rightmost non-blank character is found.
 * sum_positive(): continue skips negative elements and goes to the next one.
 */
#include <stdio.h>
#include <string.h>

/* trim: remove trailing blanks, tabs, newlines; return new length */
int trim(char s[])
{
    int n;

    for (n = (int)strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return n + 1;
}

/* sum_positive: add only the non-negative elements of a[] */
int sum_positive(int a[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        if (a[i] < 0)   /* skip negative elements */
            continue;
        sum += a[i];
    }
    return sum;
}

int main(void)
{
    char s[] = "hello world  \t\n";
    int a[] = { 3, -1, 4, -1, 5 };

    printf("trimmed length = %d, string = \"%s\"\n", trim(s), s);
    printf("sum of positive elements = %d\n", sum_positive(a, 5));   /* 12 */
    return 0;
}
