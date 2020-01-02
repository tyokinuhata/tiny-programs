import matplotlib.pyplot as plt

from sklearn import datasets

iris = datasets.load_iris()

data = iris.data
labels = iris.target

x_min, x_max = data[:, 0].min(), data[:, 0].max()
y_min, y_max = data[:, 1].min(), data[:, 1].max()

plt.figure(2, figsize = (12, 9))
plt.scatter(data[:, 0], data[:, 1], s = 300, c = labels, cmap = plt.cm.Set2, edgecolor='darkgray')
plt.xlabel('Sepal length')
plt.ylabel('Sepal width')
plt.grid(True)
plt.show()

plt.figure(2, figsize = (12, 9))
plt.scatter(data[:, 2], data[:, 3], s = 300, c = labels, cmap = plt.cm.Set2, edgecolor='darkgray')
plt.xlabel('Petal length')
plt.ylabel('Petal width')
plt.grid(True)
plt.show()