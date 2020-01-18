import numpy as np
import matplotlib.pyplot as plt
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optimizer
import torchvision
import torchvision.transforms as transforms

# transforms.ToTensor() ... データをPyTorch用のTensor(PyTorch独自の多次元配列を取り扱うデータ構造)に変換する
# transforms.Normalize() ... データの正規化を行う. 変換前は0と1の間に分布するデータを, 変換後には-1と1に分布するデータに変換する
transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

# 学習データ
train_data_with_labels = torchvision.datasets.CIFAR10(root = './data', train = True, download = True, transform = transform)
train_data_loader = torch.utils.data.DataLoader(train_data_with_labels, batch_size = 4, shuffle = True, num_workers = 2)

# 検証データ
test_data_with_labels = torchvision.datasets.CIFAR10(root = './data', train = False, download = True, transform = transform)
test_data_loader = torch.utils.data.DataLoader(test_data_with_labels, batch_size = 4, shuffle = False, num_workers = 2)

class_names = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

def show_image(img):
    img = img / 2 + 0.5
    np_img = img.numpy()
    plt.imshow(np.transpose(np_img, (1, 2, 0)))
    plt.show()

train_data_iterator = iter(train_data_loader)
images, labels = train_data_iterator.next()
show_image(torchvision.utils.make_grid(images))
print(' '.join('%5s' % class_names[labels[j]] for j in range(4)))

# 畳み込みニューラルネットワーク
class CNN(nn.Module):
    def __init__(self):
        super(CNN, self).__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.pool = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.layer1 = nn.Linear(16 * 5 * 5, 120)
        self.layer2 = nn.Linear(120, 84)
        self.layer3 = nn.Linear(84, 10)

    def forward(self, input_data):
        input_data = self.pool(F.relu(self.conv1(input_data)))
        input_data = self.pool(F.relu(self.conv2(input_data)))
        input_data = input_data.view(-1, 16 * 5 * 5)
        input_data = F.relu(self.layer1(input_data))
        input_data = F.relu(self.layer2(input_data))
        input_data = F.relu(self.layer3(input_data))
        return input_data

model = CNN()

criterion = nn.CrossEntropyLoss()
optimizer = optimizer.SGD(model.parameters(), lr = 0.001, momentum = 0.9)

MAX_EPOCH = 3
for epoch in range(MAX_EPOCH):
    total_loss = 0.0
    for i, data in enumerate(train_data_loader, 0):
        train_data, train_labels = data
        optimizer.zero_grad()
        outputs = model(train_data)
        loss = criterion(outputs, train_labels)
        loss.backward()
        optimizer.step()
        total_loss += loss.item()
        if i % 2000 == 1999:
            print('学習進捗: [%d, %5d] loss: %.3f' % (epoch + 1, i + 1, total_loss / 2000))
            total_loss = 0.0
print('学習完了')