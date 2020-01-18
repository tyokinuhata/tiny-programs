import matplotlib.pyplot as plt
import torchvision.transforms as transforms
import torch.nn as nn
import torch.optim as optimizer

from torch.utils.data import DataLoader
from torchvision.datasets import MNIST
from torch.autograd import Variable

data_directory = './data'
BATCH_SIZE = 8

# mnist_data = MNIST(data_directory, train = True, download = True, transform = transforms.ToTensor())
# data_loader = DataLoader(mnist_data, batch_size = BATCH_SIZE, shuffle = False)

# data_iterator = iter(data_loader)
# images, labels = data_iterator.next()
# print(len(images))
# print(len(labels))

# location = 4
# image = images[location].numpy()
# print(image.shape)
# reshaped_image = image.reshape(28, 28)
# plt.imshow(reshaped_image, cmap = 'inferno', interpolation = 'bicubic')
# plt.show()
# print(labels[location])

class MLP(nn.Module):
    def __init__(self):
        super().__init__()
        # 入力層
        self.layer1 = nn.Linear(28 * 28, 100)
        # 中間層(隠れ層)
        self.layer2 = nn.Linear(100, 50)
        # 出力層
        self.layer3 = nn.Linear(50, 10)

    def forward(self, input_data):
        input_data = input_data.view(-1, 28 * 28)
        input_data = self.layer1(input_data)
        input_data = self.layer2(input_data)
        input_data = self.layer3(input_data)
        return input_data

# 学習データ
train_data_with_labels = MNIST(data_directory, train = True, download = True, transform = transforms.ToTensor())
train_data_loader = DataLoader(train_data_with_labels, batch_size = BATCH_SIZE, shuffle = True)

# 検証データ
test_data_with_labels = MNIST(data_directory, train = False, download = True, transform = transforms.ToTensor())
test_data_loader = DataLoader(test_data_with_labels, batch_size = BATCH_SIZE, shuffle = True)

model = MLP()
# コスト関数(ソフトマックス)
# クロスエントロピー
loss_res = nn.CrossEntropyLoss()
# 最適化手法
# SGD ... Stochastic Gradient Descent. 確率勾配降下法というコスト関数の最小値を見つける手法
optimizer = optimizer.SGD(model.parameters(), lr = 0.01)