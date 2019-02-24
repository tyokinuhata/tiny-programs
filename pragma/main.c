#include <stdio.h>

#define PRAGMA_STR(n) _Pragma(#n)
#define PRAGMA(n) PRAGMA_STR(pack(n))

int main(void) {
    PRAGMA(1);
    return 0;
}