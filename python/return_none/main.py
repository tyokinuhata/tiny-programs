def foo1(value):
    if value:
        return value
    else:
        return None

def foo2(value):
    if value:
        return value
    else:
        # 単なるreturn文はreturn Noneと同じ意味になる
        return

def foo3(value):
    if value:
        return value
    # return文を省くとreturn Noneと同じ意味になる

print(type(foo1(0)))
print(type(foo2(0)))
print(type(foo3(0)))

# プロシージャ
# 戻り値のない関数
# 例えばprintはテキストの出力という副作用を目的として呼び出されるだけで、戻り値を受け取る目的では呼び出されない

# 暗黙のreturn None文は可読性を下げることもあるので、明示的に記述することも考える
