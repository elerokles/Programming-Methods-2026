/*
 * ch1 / 1.9 Character Arrays
 * Ex 1-17: print all input lines that are longer than 80 characters.
 */
#include <stdio.h>

#define MAXLINE 1000
#define LIMIT   80     /* print lines longer than this */

int mgetline(char line[], int maxline);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (line[len - 1] == '\n')   /* don't count the newline */
            --len;
        if (len > LIMIT)
            printf("%s", line);
    }
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
    line[i] = '\0';
    return i;
}
