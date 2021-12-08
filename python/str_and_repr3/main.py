class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage

    def __repr__(self):
        # 変換フラグ!rを使用することで、出力文字列にstrではなくreprが使用されるようにしている
        return f"{self.__class__.__name__}({self.color!r}, {self.mileage!r})"

car = Car("red", 37281)
# __str__が無い場合は__repr__が呼び出される
# Car('red', 37281)
print(str(car))
