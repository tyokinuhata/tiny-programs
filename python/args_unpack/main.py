def print_vector(x, y, z):
    print(f"<{x}, {y}, {z}>")

print_vector(0, 1, 0)

tuple_vec = (0, 1, 0)
list_vec = [0, 1, 0]

# インデックスをいちいち明示するのは面倒
print_vector(tuple_vec[0], tuple_vec[1], tuple_vec[2])
print_vector(list_vec[0], list_vec[1], list_vec[2])

# アンパック(*演算子)により、展開できる
print_vector(*tuple_vec)
print_vector(*list_vec)

# ジェネレータでも使用可
genexpr = (x * x for x in range(3))
print_vector(*genexpr)

# ディクショナリも**演算子でアンパックできる
dic_vec = {"y": 0, "z": 1, "x": 1}
print_vector(**dic_vec)
# *演算子を使うとキーがランダムな順序で渡されるため注意
print_vector(*dic_vec)
