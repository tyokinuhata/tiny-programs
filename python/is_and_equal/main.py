# ==演算子 ... 同等性。２つの変数が指しているオブジェクトが等しい(中身が同じである)かどうか
# is演算子 ... 同一性。２つの変数が指しているオブジェクトが同じかどうか

a = [1, 2, 3]
b = a

print(a, b)
# True
print(a == b)
# True
print(a is b)

c = list(a)
print(c)
# True
print(a == c)
# False
print(a is c)
