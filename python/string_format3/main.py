errno = 50159747054
name = "Bob"

# フォーマット済み文字列リテラル
# ES2015のテンプレートリテラルに近い
# 内部的には+演算子による文字列連結に変換される
print(f"Hello, {name}")

# インラインで演算を行うことも可能
a = 5
b = 10
print(f"Five plus ten is {a + b} and not {2 * (a + b)}")

print(f"Hey, {name}, there is a {errno:#x} error!")
