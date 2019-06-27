#include <stdio.h>

int main (int argc, char *argv[]) {
    char s[16];

    fgets(s, 16, stdin);

    printf("%s", s);

    return 0;
}