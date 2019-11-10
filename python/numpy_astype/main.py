import numpy as np

l1 = np.arange(10)
print(l1)
print(l1.dtype.name)

# int64からfloat32に変換
l2 = l1.astype('float32')
print(l2)
print(l2.dtype.name)