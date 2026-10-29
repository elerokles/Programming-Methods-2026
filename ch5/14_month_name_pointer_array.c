/*
 * ch5 / 5.8-5.9 Initialization of Pointer Arrays, Pointers vs.
 * Multi-dimensional Arrays
 * month_name(n) returns a pointer to the name of the n-th month.
 * name[] is an array of pointers, each initialized to a string constant,
 * so the rows can have different lengths. A 2D char array would reserve
 * the same (longest) length for every row.
 */
#include <stdio.h>

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void)
{
    char *pname[] = { "Illegal month", "Jan", "Feb", "Mar" };   /* array of pointers */
    char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" }; /* 2D array: 15 chars per row */
    int i;

    for (i = 0; i <= 13; i++)
        printf("%2d: %s\n", i, month_name(i));

    printf("sizeof(pname) = %zu (4 pointers)\n", sizeof(pname));
    printf("sizeof(aname) = %zu (4 rows x 15 chars)\n", sizeof(aname));
    return 0;
}
