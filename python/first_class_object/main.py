# Pythonの関数はファーストクラスオブジェクト(第一級オブジェクト)
# つまり、変数に代入したり、データ構造に格納したり、引数として他の関数に渡したり、他の関数から値として返すこともできる
# ちなみにPythonにおけるオブジェクトとは、Pythonで書いたプログラムが操作したり、処理したりする対象のこと

def yell(text):
    return text.upper() + "!"

# 変数に代入できる
# yell関数を呼び出すのではなく、yellが参照している関数オブジェクトを受け取り、その関数オブジェクトを指すbarkという２つ目の名前を作成している
bark = yell
print(bark("woof"))

del yell
# NameError: name 'yell' is not defined
# print(yell("hello?"))
# 関数オブジェクトとその名前は別物
# そのため、yellを削除してもbarkは依然として呼び出せる
print(bark("hey"))

# Pythonは関数作成時にデバック目的としてその関数に文字列の識別子を割り当てる
# この内部識別子の値は依然としてyellということに注意する
print(bark.__name__)
print(bark.__qualname__)
