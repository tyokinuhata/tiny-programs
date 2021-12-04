errno = 50159747054
name = "Bob"

# %演算子を用いたスタイル
# 古いスタイルの文字列フォーマット
# Cのprintfに近い
print("Hello, %s" % name)

# 16進数として表現することも可能
print("%x" % errno)

# １つの文字列で複数の置き換えを行いたい場合、タプルを渡す
print("Hey %s, there is a 0x%x error!" % (name, errno))

# ディクショナリを渡すことで名前による変数の置き換えも可能
print("Hey %(name)s, there is a 0x%(errno)x error!" % {
    "name": name,
    "errno": errno
})
