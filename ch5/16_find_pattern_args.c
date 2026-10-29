/*
 * ch5 / 5.10 Command-line Arguments
 * find: print lines that match the pattern given as the first argument.
 * Improves the pattern program from 4.1: the pattern comes from argv
 * instead of a fixed "ould", and strstr() from <string.h> replaces strindex.
 * Optional arguments:
 *   -x  print all lines EXCEPT those that match
 *   -n  precede each printed line by its line number
 *   example:  find -x -n ould    or    find -nx ould
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int mgetline(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    /* each argument starting with '-' is a list of option letters */
    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]) != '\0')
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (mgetline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}

/* mgetline: read a line into s, return length */
int mgetline(char *s, int lim)
{
    int c = 0, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
