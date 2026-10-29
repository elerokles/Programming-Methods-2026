/*
 * ch1 / 1.10 External Variables and Scope
 * Longest-line program, specialized version: line, longest and max are
 * external (global) variables shared by all functions instead of arguments.
 */
#include <stdio.h>

#define MAXLINE 1000   /* maximum input line size */

int max;               /* maximum length seen so far */
char line[MAXLINE];    /* current input line */
char longest[MAXLINE]; /* longest line saved here */

int mgetline(void);
void copy(void);

/* print longest input line: specialized version */
int main(void)
{
    int len;
    extern int max;          /* extern declarations are optional here, */
    extern char longest[];   /* because the definitions are above in this file */

    max = 0;
    while ((len = mgetline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)  /* there was a line */
        printf("%s", longest);
    return 0;
}

/* mgetline: specialized version, reads into the external line[] */
int mgetline(void)
{
    int c = 0, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version, copies line[] into longest[] */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
