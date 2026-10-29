/*
 * ch5 / 5.4 Character Pointers and Functions
 * Ex 5-3: pointer version of strcat(s, t), which copies the string t to the
 * end of s. Uses the main routine from the slides: type s, then t.
 */
#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int lim);
void mystrcat(char *s, char *t);

int main(void)
{
    char s[MAXLINE * 2], t[MAXLINE];

    putchar('s'); putchar(':');
    mgetline(s, MAXLINE);
    putchar('t'); putchar(':');
    mgetline(t, MAXLINE);

    mystrcat(s, t);
    printf("%s\n", s);
    return 0;
}

/* mystrcat: concatenate t to end of s; s must be big enough */
void mystrcat(char *s, char *t)
{
    while (*s)                     /* find end of s */
        s++;
    while ((*s++ = *t++) != '\0')  /* copy t */
        ;
}

/* mgetline: read a line into s without the newline, return length */
int mgetline(char s[], int lim)
{
    int c = 0, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}
