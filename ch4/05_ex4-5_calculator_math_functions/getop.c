/*
 * getop.c - reads the next token: a number, an operator, or a
 * lower-case function name (sin, cos, exp, pow).
 */
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator, numeric operand, or math function name */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c)) {             /* a function name like sin */
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return NAME;
    }
    if (!isdigit(c) && c != '.')
        return c;                 /* not a number */
    if (isdigit(c))               /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                 /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
