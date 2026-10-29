/*
 * main.c - Ex 4-5: reverse Polish calculator with math library functions
 * (ch4 / 4.4 Scope Rules, 4.5 Header Files)
 * Adds access to sin, cos, exp and pow from <math.h>.
 * The program is split into main.c, stack.c, getop.c, getch.c + calc.h.
 * Examples:   2 3 pow      -> 8
 *             0 sin        -> 0
 *             1 exp        -> 2.7182818
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <string.h>   /* for strcmp() */
#include <math.h>     /* for sin, cos, exp, pow */
#include "calc.h"

#define MAXOP 100     /* max size of operand or operator */

void mathfnc(char[]);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:              /* a word like sin or pow */
            mathfnc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[])
{
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
}
