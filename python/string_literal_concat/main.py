items = [
    "foo",
    "bar"   # コンマが無い
    "baz"
]

# ['foo', 'barbaz'] と出力される
# これは文字列リテラルの連結による挙動
# 長い文章の改行に便利
print(items)

# このように常に行末にカンマを配置することでgit diffの見栄えやバグを避けることができる
items = [
    "foo",
    "bar",
    "baz",
]

print(items)
