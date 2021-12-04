# ネームマングリング
# クラスが後から拡張(サブクラス)されても名前の衝突が起きにくくするために、Pythonインタープリタが属性の名前を上書きする仕組み

class Test:
    def __init__(self):
        self.foo = 11
        self._bar = 23
        # 先頭を二重のアンダースコアで始めることでネームマングリングが行われる
        self.__baz = 42

class ExtendedTest(Test):
    def __init__(self):
        super().__init__()
        self.foo = "overriden"
        self._bar = "overriden"
        self.__baz = "overriden"

t = Test()

# ['_Test__baz', '__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_bar', 'foo']
# bazが_Test__bazに変更されていることが分かる
print(dir(t))

t2 = ExtendedTest()
print(t2.foo)
print(t2._bar)
# AttributeError: 'ExtendedTest' object has no attribute '__baz'
# print(t2.__baz)
# ['_ExtendedTest__baz', '_Test__baz', '__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_bar', 'foo']
print(dir(t2))
print(t2._ExtendedTest__baz)
print(t2._Test__baz)
