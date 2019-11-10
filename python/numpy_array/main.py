import numpy as np

l = np.array([1, 2, 3])
print(l)

print(l * 3) # [3 6 9]
print(l + 2) # [3 4 5]

l2 = np.array([1, 1, 4])
print(l + l2) # [2 3 7]
print(l - l2) # [0 1 -1]
print(l / l2) # [1. 2. 0.75]
print(l * l2) # [1 2 12]