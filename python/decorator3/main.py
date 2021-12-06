def strong(func):
    def wrapper():
        return f"<strong>{func()}</strong>"
    return wrapper

def emphasis(func):
    def wrapper():
        return f"<em>{func()}</em>"
    return wrapper

@strong
@emphasis
def greet():
    return "Hello!"

# <strong><em>Hello!</em></strong>
# デコレータは下から順に適用される
# つまり strong(emphasis(greet)) と同じ
print(greet())
