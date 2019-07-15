int main () {
    typedef struct {
        // something ...
    } t_foo;

    typedef struct {
        int n;
        // フレキシブル配列メンバ
        // 可変長構造体を定義するためのテクニック
        // C99から正式に言語仕様として採用
        t_foo foo[];
    } t_bar;
}