import numpy as np
import matplotlib.pyplot as plt
import torch
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