#include <stdio.h>

int main (int argc, char *argv[]) {
    goto label;

    printf("This statement doesn't execute.\n");

label:

    return 0;
}