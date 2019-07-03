#include <stdio.h>
#include <stdlib.h>

// 構造体の宣言(struct)と型の作成(type_def)を同時に行っている
typedef struct tag_list {
    int key;
    char *value;
    struct tag_list *next; // 次の要素を示すポインタ
} t_list;

t_list *current = NULL;
void *start = NULL;

// 要素追加
void add(int, char *);
// 要素の検索
struct tag_list *find();
// 要素削除
int delete(int);
// 全要素表示
void show(void);
// 全要素削除
int truncate(void);

int main(int argc, char *argv[]) {
    // 要素の追加
    add(1, "foo");
    add(2, "bar");
    add(3, "baz");

    // 要素の検索
    t_list *foo = find(1);
    printf("%d: %s\n", foo->key, foo->value);

    return 0;
}

// 要素の追加
void add(int key, char *value) {
    // 先頭要素がNULLの場合
    if (current == NULL) {
        // メモリ確保
        current = malloc(sizeof(t_list));

        // データの挿入
        current->key = key;
        current->value = value;
        current->next = NULL;

        // 先頭要素のアドレスを保存
        start = current;
    }
    else {
        // 現在の位置を移動
        t_list *old = current;

        // 現在位置にデータを挿入
        current = malloc(sizeof(t_list));
        current->key = key;
        current->value = value;
        current->next = NULL;

        // 一つ前の要素のnextに現在の要素のアドレスを挿入
        old->next = current;
    }
}

// 要素の検索
t_list *find(int key) {
    t_list *list = start;
    while (list != NULL) {
        if (list->key == key) return list;
        list = list->next;
    }
    return NULL;
}

// int delete(int key) {

// }

// int truncate(void) {

// }
