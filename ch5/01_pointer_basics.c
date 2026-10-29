/*
 * ch5 / 5.1 Pointers and Addresses
 * & gives the address of a variable, * (dereferencing) gives the value
 * stored at an address. Also traces the exercise fragment from the slides
 * (the slide has "np = &np", which should be "np = &n").
 */
#include <stdio.h>

int main(void)
{
    int x = 1, y = 2, z[10];
    int *ip;                 /* ip is a pointer to int */
    int m = 10, n = 5;
    int *mp, *np;

    ip = &x;                 /* ip now points to x */
    y = *ip;                 /* y is now 1 */
    *ip = 0;                 /* x is now 0 */
    printf("x=%d y=%d\n", x, y);

    ip = &z[0];              /* ip now points to z[0] */
    *ip = 5;
    *ip = *ip + 10;          /* z[0] = 15 */
    ++*ip;                   /* z[0] = 16 */
    (*ip)++;                 /* z[0] = 17; parentheses needed: *ip++ would move the pointer */
    printf("z[0]=%d\n", z[0]);

    /* exercise: trace the fragment */
    mp = &m;
    np = &n;
    *mp = *mp + *np;         /* m = 10 + 5 = 15 */
    *np = *mp - *np;         /* n = 15 - 5 = 10 */
    printf("%d %d\n%d %d\n", m, *mp, n, *np);   /* 15 15 / 10 10 */
    return 0;
}
