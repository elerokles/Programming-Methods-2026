/*
 * ch1 / 1.9 Character Arrays
 * Ex 1-20: detab - replace tabs in the input with the proper number of
 * blanks to space to the next tab stop (every TABSTOP columns).
 * Blanks are printed as '.' here so the result is visible on screen.
 */
#include <stdio.h>

#define TABSTOP 8
#define BLANK   '.'   /* change to ' ' for real blanks */

int main(void)
{
    int c, col = 0, n;   /* col: current output column */

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            n = TABSTOP - (col % TABSTOP);   /* blanks to next tab stop */
            while (n-- > 0) {
                putchar(BLANK);
                ++col;
            }
        } else {
            putchar(c);
            if (c == '\n')
                col = 0;
            else
                ++col;
        }
    }
    return 0;
}
