# 高階関数(higher-order function)
# 他の関数を引数として受け取ることができる関数
# 振る舞いを抜き出してプログラム内でやり取りできる

def greet(func):
    greeting = func("Hi, I am a Python program")
    print(greeting)

def yell(text):
    return text.upper() + "!"

def whisper(text):
    return text.lower() + "..."

bark = yell

greet(bark)
greet(whisper)

# 組み込み関数mapも高階関数
print(list(map(bark, ["hello", "hey", "hi"])))
