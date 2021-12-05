# ラムダ関数
# 小さな単一式の無名関数
# 単一式関数(single expression function)とも呼ばれる

# 文やアノテーションは使用できない
# 暗黙のreturn文が常に存在する
add = lambda x, y: x + y
print(add(5, 3))


# 関数式(function expression)
# 関数をインラインで記述できる
print((lambda x, y: x + y)(5, 3))


# ラムダ関数の使い道
# イテラブルをキー以外の値でソートするためのコンパクトなキー関数として記述する
tuples = [(1, "a"), (2, "b"), (4, "a"), (3, "c")]
sorted(tuples, key=lambda x: x[1])


# ラムダはレキシカルクロージャとしても機能する
def make_adder(n):
    return lambda x: x + n

plus_3 = make_adder(3)
plus_5 = make_adder(5)

print(plus_3(4))
print(plus_5(4))

# ラムダ関数を使う際は、それが本当にクリーンでメンテナブルかどうかを考える
# 通常の関数やリスト内包の使用を検討する
