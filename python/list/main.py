# 一次元配列
l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(l)

# 二次元配列
l2 = [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
print(l2)

# 三次元配列
l3 = [[[1, 2], [1, 2]], [[1, 2], [1, 2]]]
print(l3)

# 文字列配列
sl = ['a', 'b', 'c', 'd', 'e']
print(sl)

# 要素の取り出し
print(l[0])

# 要素のスライス
print(l[0:6])
print(l[0:-6])
print(l[:3])
print(l[8:])
print(l[0:100])

# 要素の更新
l[0] = 999
print(l)

# 要素の追加
l + [11]
print(l)

l += [12]
print(l)

l.append(13)
print(l)

# 要素の削除
del l[0]
print(l)

# リストの代入
nl = l
cl = l[:]
del l[0]
print(nl)   # nlはlの影響を受ける(0番目の要素が消えている)
print(cl)   # clはlの影響を受けない