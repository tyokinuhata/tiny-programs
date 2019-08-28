// Linuxかどうかの判定

#include <stdio.h>

int main ()
{
// __linuxマクロが定義されていたらLinux
#ifdef __linux
    printf("This system is Linux.\n");
#else
    printf("This system is others.\n");
#endif
}
