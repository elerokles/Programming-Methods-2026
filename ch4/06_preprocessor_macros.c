/*
 * ch4 / 4.11 The C Preprocessor
 * - 4.11.2 macro substitution: forever, max(A, B)
 * - 4.11.3 conditional inclusion: #ifdef DEBUG, #if / #elif / #else, #undef
 * Comment out "#define DEBUG" to remove the debug output at compile time.
 */
#include <stdio.h>

#define DEBUG                                  /* turn debug printing on */
#define NATION 2                               /* 1 = Korean, 2 = English */
#define forever for (;;)                       /* infinite loop */
#define max(A, B) ((A) > (B) ? (A) : (B))      /* parentheses avoid precedence bugs */

int average(int x, int y)
{
#ifdef DEBUG
    printf("[debug] x=%d, y=%d\n", x, y);       /* only compiled if DEBUG is defined */
#endif
    return (x + y) / 2;
}

int main(void)
{
    int p = 1, q = 2, r = 3, s = 4;
    int n = 0;

    /* x = max(p+q, r+s) becomes ((p+q) > (r+s) ? (p+q) : (r+s)) */
    printf("max(p+q, r+s) = %d\n", max(p + q, r + s));
    printf("average(10, 20) = %d\n", average(10, 20));

#if NATION == 1
    printf("Annyeonghaseyo\n");
#elif NATION == 2
    printf("Hello world\n");
#else
    printf("other language\n");
#endif

    forever {                                  /* expands to for (;;) */
        if (++n == 3)
            break;
    }
    printf("forever loop stopped after %d steps\n", n);

#undef max                                     /* max is no longer a macro after this */
    return 0;
}
