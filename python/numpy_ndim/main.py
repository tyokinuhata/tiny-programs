import numpy as np

l = np.empty((3, 3))
print(l)

# 次元数の取得
# 3 * 3の配列なので2が取得できる
print(l.ndim)
print(len(l.shape)) # 上と同意