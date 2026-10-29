/*
 * calc.h - shared definitions for the multi-file calculator (ch4 / 4.5)
 * Every .c file includes this header with "calc.h" so they all agree on
 * the constants and function prototypes. The #ifndef guard prevents the
 * header from being included twice (4.11.3).
 */
#ifndef CALC_H
#define CALC_H

#define NUMBER '0'   /* signal that a number was found */
#define NAME   'n'   /* signal that a name (sin, exp, pow) was found */

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

#endif /* CALC_H */
