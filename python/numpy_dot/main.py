import numpy as np

l1 = [1, 2, 3]
l2 = [1, 1, 4]

# ベクトルの内積
# l1[0] * l2[0] + l1[1] * l2[1] + l1[2] * l2[2]
# 1 + 2 + 12 = 15
print(np.dot(l1, l2))

# 二次元ベクトルの内積
l3 = np.array([[1, 2], [3, 4]])
l4 = np.array([[3, 4], [1, 2]])
print(np.dot(l3, l4))