import numpy as np
import chainer

train_data, test_data = chainer.datasets.get_mnist(withlabel = True, ndim = 1)
print(train_data)
print(test_data)