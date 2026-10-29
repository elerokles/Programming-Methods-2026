/*
 * ch4 / 4.1 Basics of Functions
 * Ex 4-1: strrindex(s, t) returns the position of the RIGHTMOST occurrence
 * of t in s, or -1 if there is none.
 * Change from strindex: instead of returning at the first match, remember
 * the position and keep looking.
 * Example: s = "abcdedfabcde", t = "abc" -> 7
 */
#include <stdio.h>

int strrindex(char s[], char t[])
{
    int i, j, k;
    int pos = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;        /* remember it, keep looking */
    }
    return pos;
}

int main(void)
{
    char s[] = "abcdedfabcde";
    char t[] = "abc";

    printf("rightmost index = %d\n", strrindex(s, t));
    return 0;
}
