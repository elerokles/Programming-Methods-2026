/*
 * ch3 / 3.6 Loops - Do-While
 * itoa(n, s): convert integer n to characters in s (the inverse of atoi).
 * do-while is used because at least one digit must be stored, even if n is 0.
 * Digits come out in reverse order, so reverse(s) fixes the order at the end.
 */
#include <stdio.h>
#include <string.h>

void reverse(char s[]);

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)         /* record sign */
        n = -n;                 /* make n positive */
    i = 0;
    do {                        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = (int)strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(void)
{
    char s[20];
    int tests[] = { 0, 123, -456, 7 };
    int k;

    for (k = 0; k < 4; k++) {
        itoa(tests[k], s);
        printf("itoa(%d) = \"%s\"\n", tests[k], s);
    }
    return 0;
}
