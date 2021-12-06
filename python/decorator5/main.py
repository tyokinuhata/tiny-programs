def uppercase(func):
    def wrapper():
        original_result = func()
        modified_result = original_result.upper()
        return modified_result
    return wrapper

def greet():
    """Return a friendly greeting."""
    return "Hello!"

decorated_greet = uppercase(greet)

# greet
print(greet.__name__)
# Return a friendly greeting.
print(greet.__doc__)

# wrapper
print(decorated_greet.__name__)
# None
print(decorated_greet.__doc__)

# デコレータを使用すると元の関数に関連付けられたメタデータの一部が覆い隠されてしまうという欠点がある
# e.g. 元の関数の名前、docstring、パラメータリスト


import functools

def uppercase(func):
    # functools.wrapsデコレータを使うと、元の関数のメタデータをクロージャにコピーすることができる
    @functools.wraps(func)
    def wrapper():
        original_result = func()
        modified_result = original_result.upper()
        return modified_result
    return wrapper

@uppercase
def greet():
    """Return a friendly greeting."""
    return "Hello!"

# greet
print(greet.__name__)
# Return a friendly greeting.
print(greet.__doc__)
