import matplotlib.pyplot as plt

from sklearn import datasets

digits = datasets.load_digits()

plt.imshow(digits.images[2], cmap = plt.cm.gray_r, interpolation = 'nearest')
plt.grid(True)
plt.show()

plt.imshow(digits.images[47], cmap = 'plasma', interpolation = 'bicubic')
plt.grid(True)
plt.show()