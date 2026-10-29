/*
 * ch1 / 1.5.3 Line Counting
 * Ex 1-8: count blanks, tabs and newlines in the input.
 * Input ends with EOF (Ctrl+Z then Enter on Windows).
 */
#include <stdio.h>

int main(void)
{
    int c, nl, t, sp;

    nl = 0;   /* newlines */
    t = 0;    /* tabs */
    sp = 0;   /* blanks */

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++t;
        if (c == ' ')
            ++sp;
    }
    printf("newlines = %d\ntabs     = %d\nblanks   = %d\n", nl, t, sp);
    return 0;
}
