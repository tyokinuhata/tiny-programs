#include <stdio.h>

int main ()
{
#ifdef __linux
    printf("This system is Linux.\n");
#else
    printf("This system is others.\n");
#endif
}
