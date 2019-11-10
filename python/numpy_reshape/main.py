import numpy as np

# np.array()で生成される配列 ... ndarray(N-dimensional array)と呼ばれるNumPy独自のデータ構造

# 1 * 9の行列
l = np.arange(9)
print(l)

# 3 * 3の配列に形状変換
l = l.reshape((3, 3))
print(l)