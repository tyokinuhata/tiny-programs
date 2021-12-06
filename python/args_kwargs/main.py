# オプションパラメータ
# *args ... 位置パラメータ。*プレフィックスが付いている
# **kwargs ... キーワードパラメータ。**プレフィックスが付いている

def foo(required, *args, **kwargs):
    print(required)
    if args:
        print(args)
    if kwargs:
        print(kwargs)

# TypeError: foo() missing 1 required positional argument: 'required'
# foo()

# hello
foo("hello")

# hello
# (1, 2, 3)
# *argsはタプルにまとめられる
foo("hello", 1, 2, 3)

# hello
# (1, 2, 3)
# {'key1': 'value', 'key2': 999}
# **kwargsはディクショナリにまとめられる
foo("hello", 1, 2, 3, key1="value", key2=999)
