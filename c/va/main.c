#include <stdio.h>
// va_XXXXを使うために必要
#include <stdarg.h>
#include <assert.h>

// ... と書くと引数のチェックが抑止される
void tiny_printf(const char *, ...);

int main () {
    tiny_printf("sdd", "yaju", 114, 514);

    return 0;
}

void tiny_printf (const char *format, ...) {
    // variable argument listの略
    va_list ap;

    // ポインタapを引数formatの次の位置に向ける
    va_start(ap, format);

    for (int i = 0; format[i] != '\0'; i++) {
        switch (format[i]) {
            case 's':
                printf("%s", va_arg(ap, char *));
                break;
            case 'd':
                printf("%d", va_arg(ap, int));
                break;
            default:
                assert(0);
        }
    }

    va_end(ap);

    puts("");

    // なお, apの複製にはva_copyマクロを使用する(C99から追加)
}