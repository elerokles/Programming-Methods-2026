/*
 * ch3 / 3.4 Switch
 * Ex 3-2: escape(s, t) copies t to s, converting newline and tab into the
 * visible escape sequences \n and \t. unescape(s, t) does the reverse,
 * turning the two-character sequences \n and \t back into real characters.
 * Both use a switch.
 */
#include <stdio.h>

void escape(char s[], const char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], const char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[i + 1]) {
            case 'n':
                s[j++] = '\n';
                i++;            /* skip the 'n' too */
                break;
            case 't':
                s[j++] = '\t';
                i++;
                break;
            default:
                s[j++] = '\\';  /* not an escape we know: keep the backslash */
                break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char t[] = "Hello\tworld\nThis is a test.";
    char escaped[100];
    char unescaped[100];

    escape(escaped, t);
    printf("Escaped string: %s\n", escaped);

    unescape(unescaped, escaped);
    printf("Unescaped string: %s\n", unescaped);
    return 0;
}
