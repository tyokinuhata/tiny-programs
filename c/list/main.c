#include <stdio.h>
#include <stdlib.h>

typedef struct tag_list {
    int key;
    char *value;
    struct tag_list *next; // 次のリストを示すポインタ
} t_list;

t_list *head = NULL;

// データ追加
void add(int, char *);
// データの検索
struct tag_list *find();
// データ削除
int delete(int);
// 全データ表示
void show(void);
// 全データ削除
int truncate(void);

int main(int argc, char *argv[]) {
    add(1, "foo");
    add(2, "bar");
    add(3, "baz");

    t_list *list = head;
    while (list != NULL) {
        printf("%d\n", list->key);
        printf("%s\n", list->value);
        list = list->next;
    }

    // printf("%s\n", head->value);

    return 0;
}

void add(int key, char *value) {
    // 先頭要素がNULLの場合
    if (head == NULL) {
        // ヘッドの作成
        head = malloc(sizeof(t_list));

        // データの挿入
        head->key = key;
        head->value = value;
        head->next = NULL;
    }
    else {
        // 古いヘッドを退避
        t_list *old_head = head;

        // 新しいヘッドの作成
        head = malloc(sizeof(t_list));

        // データ挿入
        head->key = key;
        head->value = value;
        head->next = old_head;
    }
}

// struct tag_list *find(int key) {

// }

// int delete(int key) {

// }

// int truncate(void) {

// }
