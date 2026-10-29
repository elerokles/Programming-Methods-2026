/*
 * ch2 / 2.7 Type Conversions
 * Ex 2-3: htoi(s) converts a string of hexadecimal digits (with an optional
 * 0x or 0X prefix) into its equivalent integer value.
 * Allowed digits: 0-9, a-f, A-F.
 */
#include <stdio.h>

int htoi(const char s[])
{
    int i, n, d;

    i = 0;
    /* skip optional 0x or 0X */
    if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
        i += 2;

    n = 0;
    for (; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            d = s[i] - '0';          /* character -> digit value */
        else if (s[i] >= 'a' && s[i] <= 'f')
            d = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            d = s[i] - 'A' + 10;
        else
            break;                   /* invalid character, stop */
        n = 16 * n + d;
    }
    return n;
}

int main(void)
{
    printf("htoi(\"84ada\") = %d\n", htoi("84ada"));
    printf("htoi(\"f\")     = %d\n", htoi("f"));
    printf("htoi(\"F0\")    = %d\n", htoi("F0"));
    printf("htoi(\"12fab\") = %d\n", htoi("12fab"));
    printf("htoi(\"0x1F\")  = %d\n", htoi("0x1F"));
    return 0;
}
