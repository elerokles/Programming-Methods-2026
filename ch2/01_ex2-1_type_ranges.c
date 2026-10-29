/*
 * ch2 / 2.2 Data Types and Sizes
 * Ex 2-1: determine the ranges of char, short, int and long (signed and
 * unsigned) by printing values from the standard headers <limits.h> and
 * <float.h>, and by direct computation. Also computes the largest float
 * and double, and prints sizeof() for each type.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/* number of bits in type T, and its ranges computed from the bit count */
#define BITS(T)         (sizeof(T) * CHAR_BIT)
#define SIGNED_MAX(T)   ((long long)(((unsigned long long)1 << (BITS(T) - 1)) - 1))
#define SIGNED_MIN(T)   (-SIGNED_MAX(T) - 1)
#define UNSIGNED_MAX(T) (~(unsigned long long)0 >> (64 - BITS(T)))

/* float_max: largest finite float - biggest power of 2, then add smaller halves */
float float_max(void)
{
    float x = 1.0f, step;

    while (!isinf(x * 2))
        x *= 2;
    for (step = x / 2; step >= 1; step /= 2)
        if (!isinf(x + step))
            x += step;
    return x;
}

/* double_max: same method for double */
double double_max(void)
{
    double x = 1.0, step;

    while (!isinf(x * 2))
        x *= 2;
    for (step = x / 2; step >= 1; step /= 2)
        if (!isinf(x + step))
            x += step;
    return x;
}

int main(void)
{
    printf("--- From headers ---\n");
    printf("char           %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char    %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char  0 to %u\n", UCHAR_MAX);
    printf("short          %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short 0 to %u\n", USHRT_MAX);
    printf("int            %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int   0 to %u\n", UINT_MAX);
    printf("long           %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long  0 to %lu\n", ULONG_MAX);
    printf("long long      %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long 0 to %llu\n", ULLONG_MAX);
    printf("float          %e to %e\n", -FLT_MAX, FLT_MAX);
    printf("double         %e to %e\n", -DBL_MAX, DBL_MAX);

    printf("\n--- By computation ---\n");
    printf("signed char    %lld to %lld\n", SIGNED_MIN(signed char), SIGNED_MAX(signed char));
    printf("unsigned char  0 to %llu\n", UNSIGNED_MAX(unsigned char));
    printf("short          %lld to %lld\n", SIGNED_MIN(short), SIGNED_MAX(short));
    printf("unsigned short 0 to %llu\n", UNSIGNED_MAX(unsigned short));
    printf("int            %lld to %lld\n", SIGNED_MIN(int), SIGNED_MAX(int));
    printf("unsigned int   0 to %llu\n", UNSIGNED_MAX(unsigned int));
    printf("long           %lld to %lld\n", SIGNED_MIN(long), SIGNED_MAX(long));
    printf("unsigned long  0 to %llu\n", UNSIGNED_MAX(unsigned long));
    printf("long long      %lld to %lld\n", SIGNED_MIN(long long), SIGNED_MAX(long long));
    printf("unsigned long long 0 to %llu\n", UNSIGNED_MAX(unsigned long long));
    printf("float max      %e\n", float_max());
    printf("double max     %e\n", double_max());

    printf("\n--- sizeof (bytes) ---\n");
    printf("char        -> %zu\n", sizeof(char));
    printf("short       -> %zu\n", sizeof(short));
    printf("int         -> %zu\n", sizeof(int));
    printf("long        -> %zu\n", sizeof(long));
    printf("long long   -> %zu\n", sizeof(long long));
    printf("float       -> %zu\n", sizeof(float));
    printf("double      -> %zu\n", sizeof(double));
    printf("long double -> %zu\n", sizeof(long double));
    return 0;
}
