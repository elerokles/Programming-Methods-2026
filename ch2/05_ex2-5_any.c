/*
 * ch2 / 2.8
 * Ex 2-5: any(s1, s2) returns the first location in s1 where any character
 * from s2 occurs, or -1 if s1 contains no character from s2.
 * (The library function strpbrk does the same but returns a pointer.)
 */
#include <stdio.h>

int any(const char s1[], const char s2[])
{
    int i, k;

    for (i = 0; s1[i] != '\0'; i++)
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                return i;   /* first match */
    return -1;
}

int main(void)
{
    printf("any(\"hello, world\", \"wo\") = %d\n", any("hello, world", "wo"));   /* 4 */
    printf("any(\"hello, world\", \"xyz\") = %d\n", any("hello, world", "xyz")); /* -1 */
    return 0;
}
