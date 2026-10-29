/*
 * ch1 / 1.9 Character Arrays
 * Read a set of text lines and print the longest.
 *   while (there's another line)
 *       if (it's longer than the previous longest)
 *           save it and its length
 *   print longest line
 * mgetline is used instead of getline to avoid a clash with the POSIX function.
 */
#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;                  /* current line length */
    int max;                  /* maximum length seen so far */
    char line[MAXLINE];       /* current input line */
    char longest[MAXLINE];    /* longest line saved here */

    max = 0;
    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)              /* there was a line */
        printf("%s", longest);
    return 0;
}

/* mgetline: read a line into line[], return its length */
int mgetline(char line[], int maxline)
{
    int c = 0, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';   /* mark the end of the string */
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
