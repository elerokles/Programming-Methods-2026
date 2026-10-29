/*
 * ch3 / 3.8 Goto and Labels
 * goto is used to leave two nested loops at once (break would only leave
 * the inner one): determine whether arrays a and b have an element in common.
 */
#include <stdio.h>

int main(void)
{
    int a[] = { 1, 3, 5, 7 };
    int b[] = { 2, 4, 5, 8 };
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i] == b[j])
                goto found;
    printf("no common element\n");
    return 0;

found:   /* a label: name followed by a colon */
    printf("common element: a[%d] = b[%d] = %d\n", i, j, a[i]);
    return 0;
}
