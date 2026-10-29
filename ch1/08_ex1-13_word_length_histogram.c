/*
 * ch1 / 1.6 Arrays
 * Ex 1-13: print a histogram of the lengths of words in the input,
 * first with horizontal bars, then with vertical bars.
 */
#include <stdio.h>

#define MAXWORDS 100   /* maximum number of words remembered */

int main(void)
{
    int c, i, row;
    int len = 0, nwords = 0, max = 0;
    int wl[MAXWORDS];   /* word lengths */

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (len > 0 && nwords < MAXWORDS) {   /* a word just ended */
                wl[nwords++] = len;
                if (len > max)
                    max = len;
            }
            len = 0;
        } else {
            ++len;
        }
    }
    if (len > 0 && nwords < MAXWORDS) {   /* last word without trailing space */
        wl[nwords++] = len;
        if (len > max)
            max = len;
    }

    /* horizontal: one row of '*' per word */
    printf("\nHorizontal:\n");
    for (i = 0; i < nwords; ++i) {
        for (c = 0; c < wl[i]; ++c)
            putchar('*');
        putchar('\n');
    }

    /* vertical: print rows from the tallest bar down */
    printf("\nVertical:\n");
    for (row = max; row >= 1; --row) {
        for (i = 0; i < nwords; ++i)
            printf("%c ", wl[i] >= row ? '*' : ' ');
        putchar('\n');
    }
    return 0;
}
