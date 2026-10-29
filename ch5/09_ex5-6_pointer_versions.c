/*
 * ch5 / 5.4 Character Pointers and Functions
 * Ex 5-6: earlier functions rewritten with pointers instead of array
 * indexing: getline (ch1/ch4), atoi (ch2), itoa and reverse (ch3),
 * strindex (ch4). The _ptr suffix avoids clashes with library names.
 */
#include <stdio.h>
#include <ctype.h>

/* getline_ptr: read a line into s, return length */
int getline_ptr(char *s, int lim)
{
    int c = 0;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return (int)(s - start);
}

/* atoi_ptr: convert s to integer (optional sign) */
int atoi_ptr(char *s)
{
    int n = 0, sign;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    while (isdigit(*s))
        n = 10 * n + (*s++ - '0');
    return sign * n;
}

/* reverse_ptr: reverse string s in place using two pointers */
void reverse_ptr(char *s)
{
    char *t = s, c;

    while (*t)                /* move t to the last character */
        t++;
    for (t--; s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* itoa_ptr: convert n to characters in s */
void itoa_ptr(int n, char *s)
{
    char *start = s;
    int sign = n;

    if (n < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse_ptr(start);
}

/* strindex_ptr: return index of t in s, -1 if none */
int strindex_ptr(char *s, char *t)
{
    char *b = s, *p, *r;

    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
            return (int)(s - b);
    }
    return -1;
}

int main(void)
{
    char line[100], num[20];
    int len;

    printf("atoi_ptr(\"  -1234\") = %d\n", atoi_ptr("  -1234"));
    itoa_ptr(-5678, num);
    printf("itoa_ptr(-5678)     = \"%s\"\n", num);
    printf("strindex_ptr(\"could would\", \"ould\") = %d\n", strindex_ptr("could would", "ould"));

    printf("type a line: ");
    len = getline_ptr(line, 100);
    printf("getline_ptr read %d characters: %s", len, line);
    return 0;
}
