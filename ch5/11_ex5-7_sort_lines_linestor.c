/*
 * ch5 / 5.6 Pointer Arrays
 * Ex 5-7: rewrite readlines to store lines in an array supplied by main
 * (linestor[]) instead of calling alloc to maintain storage.
 * The position of the next free character is kept in a char pointer
 * (p), which plays the role that allocp had in alloc.
 * Faster because there is no function call per line, and only one
 * bounds check against the end of linestor.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
#define MAXLEN   1000       /* max length of any input line */
#define MAXSTOR  10000      /* size of the line storage */

char *lineptr[MAXLINES];
char linestor[MAXSTOR];     /* storage supplied by main's file instead of allocbuf */

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *v[], int left, int right);
int mgetline(char *s, int lim);

/* sort input lines */
int main(void)
{
    int nlines;

    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        myqsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines into linestor, return number of lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;                     /* next free position */
    char *linestop = linestor + MAXSTOR;    /* end of the storage */

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';           /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;                       /* move past this line and its '\0' */
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* myqsort: sort v[left]...v[right] into increasing order */
void myqsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}

/* mgetline: read a line into s (newline is always kept), return length */
int mgetline(char *s, int lim)
{
    int c = 0, i;

    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n' || (c == EOF && i > 0))
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}
