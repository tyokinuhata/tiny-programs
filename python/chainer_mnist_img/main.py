import numpy as np
import matplotlib.pyplot as plt
import chainer

train_data, test_data = chainer.datasets.get_mnist(withlabel = True, ndim = 1)

data_location = 60
data, label = train_data[60]
plt.imshow(data.reshape(28, 28), cmap = 'inferno', interpolation = 'bicubic')
plt.show()