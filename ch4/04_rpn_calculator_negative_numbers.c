/*
 * ch4 / 4.3 External Variables
 * Reverse Polish calculator, version that also accepts negative numbers
 * (part of Ex 4-3). A '-' directly followed by a digit is the sign of a
 * number; a '-' on its own is the subtraction operator.
 * Example input:  10 -5 + 100 + 2 *   prints 210
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <string.h>   /* for strcmp() */

#define MAXOP   100   /* max size of operand or operator */
#define NUMBER  '0'   /* signal that a number was found */
#define BUFSIZE 100
#define MAXVAL  100   /* maximum depth of val stack */

int sp = 0;           /* stack pointer: defined outside of any function,   */
                      /* so main does not see the stack representation     */
int bufp = 0;         /* next free position in buf */

double val[MAXVAL];   /* value stack */
char buf[BUFSIZE];    /* buffer for ungetch */

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);

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

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand (numbers may start with '-') */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;                       /* not a number */
    i = 0;
    if (c == '-' || isdigit(c))         /* collect integer part along with '-' */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)            /* a lone '-' is the minus operator */
        return '-';
    return NUMBER;
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
