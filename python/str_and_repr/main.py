class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage

car = Car("red", 37281)
# <__main__.Car object at 0x10c0b0f40>
# デフォルトの文字列変換が行われ、オブジェクトインスタンスのクラス名とid(CPythonの場合はオブジェクトのメモリアドレス)が返される
# しかし大抵の場合、あまり役立つ情報ではない
print(car)


class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage

    def __str__(self):
        return f"a {self.color} car"

car = Car("red", 37281)
# a red car
# __str__マジックメソッド(ダンダーメソッド)を正しく実装すれば、いちいちオブジェクトの属性を個別で出力したり、to_stringメソッドを実装したりする必要がなくなる
print(car)


class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage

    def __repr__(self):
        return "__repr__ for Car"

    def __str__(self):
        return "__str__ for Car"

car = Car("red", 37281)
# __str__ for Car
print(car)
# __str__ for Car
print("{}".format(car))
# [__repr__ for Car]
# リストやディクショナリといったコンテナはそれらに含まれているオブジェクトを表現するために__repr__を使用する
print([car])
# __str__ for Car
# 明示的に__str__を呼び出す
print(str(car))
# __repr__ for Car
# 明示的に__repr__を呼び出す
print(repr(car))
# __repr__ for Car
# PythonのREPLを使用してcarを直接見た場合、__repr__が呼び出される
# >>> car

# ちなみにreprはrepresentationの略でレパー等と読むそう
