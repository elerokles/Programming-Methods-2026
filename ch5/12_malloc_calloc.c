/*
 * ch5 / Dynamic memory allocation
 * malloc(size) and calloc(count, size) get memory from the heap at run
 * time; free(p) gives it back. calloc sets the memory to zero, malloc does not.
 * Here the user chooses the array size while the program runs.
 */
#define _CRT_SECURE_NO_WARNINGS     /* allow scanf in Visual Studio */
#include <stdio.h>
#include <stdlib.h>   /* malloc, calloc, free */
#include <string.h>

int main(void)
{
    int n, i;
    int *squares, *zeros;
    char *copy;
    const char *msg = "dynamic string";

    printf("how many numbers? ");
    if (scanf("%d", &n) != 1 || n <= 0)
        n = 5;

    squares = (int *)malloc(n * sizeof(int));   /* n ints, not initialized */
    zeros = (int *)calloc(n, sizeof(int));      /* n ints, all set to 0 */
    if (squares == NULL || zeros == NULL) {
        printf("error: out of memory\n");
        return 1;
    }
    for (i = 0; i < n; i++)
        squares[i] = i * i;
    for (i = 0; i < n; i++)
        printf("squares[%d]=%d zeros[%d]=%d\n", i, squares[i], i, zeros[i]);

    copy = (char *)malloc(strlen(msg) + 1);     /* +1 for the '\0' */
    if (copy != NULL) {
        strcpy(copy, msg);
        printf("copy = %s\n", copy);
    }

    free(squares);    /* always free what you allocate */
    free(zeros);
    free(copy);
    return 0;
}
