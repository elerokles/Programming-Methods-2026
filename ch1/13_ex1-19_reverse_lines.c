/*
 * ch1 / 1.9 Character Arrays
 * Ex 1-19: write a function reverse(s) that reverses the string s,
 * and use it to reverse the input one line at a time.
 */
#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (line[len - 1] == '\n')   /* keep the newline out of the reversal */
            line[len - 1] = '\0';
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}

/* reverse: reverse string s in place by swapping from both ends */
void reverse(char s[])
{
    int i, j;
    char temp;

    for (j = 0; s[j] != '\0'; ++j)   /* find the end of the string */
        ;
    --j;                             /* index of last character */
    for (i = 0; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
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
