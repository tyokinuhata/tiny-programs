# グローバル変数
_MangledGlobal__mangled = 23

class MangledGlobal:
    def test(self):
        return __mangled

# 23
# ネームマングリングにより、このようなことが起きる
print(MangledGlobal().test())
