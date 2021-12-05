# 関数のように振る舞うオブジェクト
# 全ての関数はオブジェクトだが、全てのオブジェクトは関数ではない
# ただし、オブジェクトを呼び出し可能(callable)にすると、多くの場合は関数のように扱える

class Adder:
    def __init__(self, n):
        self.n = n

    def __call__(self, x):
        return self.n + x

plus_3 = Adder(3)
print(plus_3(4))    # オブジェクトのインスタンスを関数として呼び出すと、__call__メソッドが実行される

# オブジェクトが呼び出し可能かどうかチェックする組み込み関数callable
# True
print(callable(plus_3))
# False
print(callable("hoge"))
