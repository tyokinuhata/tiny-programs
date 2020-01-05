import numpy as np
import chainer

# MNIST(Mixed National Institute of Standards and Technology database)
# 手書き数字のデータセットが70,000個ある
# 28 x 28 = 784次元のデータ
# scikit-learnの手書き数字は8 x 8のため, こちらの方がより特徴量が多くなっている
train_data, test_data = chainer.datasets.get_mnist(withlabel = True, ndim = 1)
print(train_data)
print(test_data)
print(len(train_data))
print(len(test_data))