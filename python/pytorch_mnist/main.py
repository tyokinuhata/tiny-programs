import matplotlib.pyplot as plt
import torchvision.transforms as transforms

from torch.utils.data import DataLoader
from torchvision.datasets import MNIST

data_directory = './data'
BATCH_SIZE = 8

mnist_data = MNIST(data_directory, train = True, download = True, transform = transforms.ToTensor())

data_loader = DataLoader(mnist_data, batch_size = BATCH_SIZE, shuffle = False)

data_iterator = iter(data_loader)
images, labels = data_iterator.next()
# print(len(images))
# print(len(labels))

location = 4
image = images[location].numpy()
print(image.shape)
reshaped_image = image.reshape(28, 28)
plt.imshow(reshaped_image, cmap = 'inferno', interpolation = 'bicubic')
plt.show()
print(labels[location])