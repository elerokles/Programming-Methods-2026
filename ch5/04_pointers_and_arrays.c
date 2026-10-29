/*
 * ch5 / 5.3 Pointers and Arrays
 * a[i] and *(pa + i) refer to the same element when pa = &a[0].
 * An array name passed to a function is the address of its first element,
 * so "char s[]" and "char *s" parameters mean the same thing.
 */
#include <stdio.h>

/* strlen_ptr: return length of string s, walking with a pointer */
int strlen_ptr(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return (int)(p - s);   /* pointer subtraction = number of elements */
}

int main(void)
{
    int a[5] = { 10, 20, 30, 40, 50 };
    int *pa;
    int i;

    pa = &a[0];            /* same as pa = a; */
    for (i = 0; i < 5; i++)
        printf("a[%d]=%d  *(pa+%d)=%d  *(a+%d)=%d\n", i, a[i], i, *(pa + i), i, *(a + i));

    pa++;                  /* legal: pa is a variable (a++ would be illegal) */
    printf("after pa++, *pa = %d\n", *pa);

    printf("strlen_ptr(\"hello, world\") = %d\n", strlen_ptr("hello, world"));
    printf("strlen_ptr(&\"hello\"[2])     = %d\n", strlen_ptr(&"hello"[2]));   /* part of an array */
    return 0;
}
