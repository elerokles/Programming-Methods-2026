/*
 * ch3 / 3.3 Else-If
 * binsearch(x, v, n): find x in the sorted array v[0] ... v[n-1] using a
 * three-way else-if decision. Returns the index of x, or -1 if not found.
 */
#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;      /* x is in the lower half */
        else if (x > v[mid])
            low = mid + 1;       /* x is in the upper half */
        else                     /* found match */
            return mid;
    }
    return -1;                   /* no match */
}

int main(void)
{
    int v[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int n = sizeof(v) / sizeof(v[0]);

    printf("binsearch(23) = %d\n", binsearch(23, v, n));   /* 5 */
    printf("binsearch(7)  = %d\n", binsearch(7, v, n));    /* -1 */
    return 0;
}
