#include <stdio.h>

int main ()
{
    goto label_a;

    puts("This statement doesn't execute.\n");

label_a:
    puts("Reached label_a.");

label_b:
    // これは実行される
    puts("Reached label_b.");

    return 0;
}