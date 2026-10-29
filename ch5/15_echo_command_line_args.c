/*
 * ch5 / 5.10 Command-line Arguments
 * echo: print the command-line arguments on one line.
 * argc = number of arguments (including the program name),
 * argv = array of pointers to the argument strings.
 *   echo hello, world   ->  argc = 3, argv = { "echo", "hello,", "world" }
 * In Visual Studio: Project > Properties > Debugging > Command Arguments.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    printf("\n");
    return 0;
}
