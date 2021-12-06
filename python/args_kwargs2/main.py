def foo(x, *args, **kwargs):
    # *argsと**kwargsは書き換えることができる
    kwargs["name"] = "Alice"
    new_args = args + ("extra",)
    # 引数アンパック演算子(*, **)を用いることでさらに別の関数に渡すこともできる
    bar(x, *new_args, **kwargs)

def bar(x, *args, **kwargs):
    pass


class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage

class AlwaysBlueCar(Car):
    # 全ての引数をスーパークラスに渡す
    # スーパークラスのコンストラクタが変化したとしても、サブクラスは変更なしで正常に動作する
    # ただし可読性は低下するため、自分の手出しできない外部クラスの振る舞いを変更・上書きするために用いる
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.color = "blue"

# blue
print(AlwaysBlueCar("green", 48392).color)


import functools

def trace(f):
    @functools.wraps(f)
    def decorated_function(*args, **kwargs):
        print(f, args, kwargs)
        result = f(*args, **kwargs)
        print(result)
    return decorated_function

@trace
def greet(greeting, name):
    return f"{greeting}, {name}!"

greet("Hello", "Bob")
