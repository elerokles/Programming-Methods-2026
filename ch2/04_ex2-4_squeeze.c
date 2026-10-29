/*
 * ch2 / 2.8 Increment and Decrement Operators
 * squeeze(s, c) from the slides removes every occurrence of character c.
 * Ex 2-4: squeeze2(s1, s2) deletes each character in s1 that matches
 * ANY character in the string s2.
 */
#include <stdio.h>

/* squeeze: delete all c from s (version from the slides) */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];   /* j++: copy, then move to next free slot */
    s[j] = '\0';
}

/* squeeze2: delete from s1 every character that appears in s2 */
void squeeze2(char s1[], const char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
            ;
        if (s2[k] == '\0')   /* s1[i] not found in s2: keep it */
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main(void)
{
    char a[] = "hello, world";
    char b[] = "hello, world";

    squeeze(a, 'l');
    printf("squeeze(\"hello, world\", 'l')    = \"%s\"\n", a);
    squeeze2(b, "lo");
    printf("squeeze2(\"hello, world\", \"lo\") = \"%s\"\n", b);
    return 0;
}
