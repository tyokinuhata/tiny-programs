class MangledMethod:
    def __method(self):
        return 42

    def call_it(self):
        return self.__method()

# AttributeError: 'MangledMethod' object has no attribute '__method'
# ネームマングリングはメソッドにも適用される
# print(MangledMethod().__method())
print(MangledMethod().call_it())
