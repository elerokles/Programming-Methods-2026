/*
 * ch5 / 5.4 Character Pointers and Functions
 * amessage is an array (its characters can be changed); pmessage is a
 * pointer to a string constant. strcpy and strcmp written with pointers.
 * Named mystrcpy / mystrcmp so they don't clash with <string.h>.
 */
#include <stdio.h>

/* mystrcpy: copy t to s; pointer version */
void mystrcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')   /* copy, then advance both pointers */
        ;
}

/* mystrcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int mystrcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int main(void)
{
    char amessage[] = "now is the time";   /* an array */
    char *pmessage = "now is the time";    /* a pointer */
    char copy[50];

    amessage[0] = 'N';                     /* OK: array elements can change */
    printf("amessage = %s\npmessage = %s\n", amessage, pmessage);

    mystrcpy(copy, pmessage);
    printf("copy     = %s\n", copy);

    printf("mystrcmp(\"abc\", \"abd\") = %d\n", mystrcmp("abc", "abd"));   /* negative */
    printf("mystrcmp(\"abc\", \"abc\") = %d\n", mystrcmp("abc", "abc"));   /* 0 */
    printf("mystrcmp(\"b\", \"a\")     = %d\n", mystrcmp("b", "a"));       /* positive */
    return 0;
}
