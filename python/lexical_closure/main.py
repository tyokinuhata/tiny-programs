# レキシカルクロージャ(あるいは単にクロージャ)
# プログラムのフローがその外側のレキシカルスコープから離れても、そのスコープの値を覚えている

# murmurとyellは外側にあるtextパラメータにアクセスできている
# さらに、このパラメータを記憶しているように見える
# つまり、振る舞いを事前に設定できるということ
def get_speak_func(text, volume):

    def murmur():
        return text.lower() + "..."

    def yell():
        return text.upper() + "!"

    if volume > 0.5:
        return yell
    else:
        return murmur

print(get_speak_func("Hello, World", 0.7))
print(get_speak_func("Hello, World", 0.7)())


def make_adder(n):
    def add(x):
        return x + n
    return add

plus_3 = make_adder(3)
plus_5 = make_adder(5)

print(plus_3(4))
print(plus_5(4))
