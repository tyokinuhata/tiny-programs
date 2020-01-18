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

MAX_EPOCH = 4
for epoch in range(MAX_EPOCH):
    total_loss = 0.0
    for i, data in enumerate(train_data_loader):
        train_data, train_labels = data
        # 入力をtorch.autograd.Variableに変換
        train_data, train_labels = Variable(train_data), Variable(train_labels)
        # 計算された勾配情報の削除
        optimizer.zero_grad()
        # モデルに学習データを与えて予測を計算
        outputs = model(train_data)
        # lossとwによる微分を計算
        loss = loss_res(outputs, train_labels)
        loss.backward()
        # 勾配を更新
        optimizer.step()
        # 誤差を累計
        total_loss += loss.data[0]
        # 2000ミニバッチずつ進捗を表示
        if i % 2000 = 1999:
            print('学習進捗: [%d, %d] 学習誤差(loss): %.3f' % (epoch + 1, i + 1, total_loss / 2000))
            total_loss = 0.0
print('学習終了')