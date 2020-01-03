import numpy as np
import matplotlib.pyplot as plt
import sklearn.datasets as datasets

from sklearn.svm import SVC

iris = datasets.load_iris()
data = iris.data[:, [0, 1]]
labels = iris.target

data = data[labels != 2]
labels = labels[labels != 2]

# SVC(サポートベクタマシン)の準備
model = SVC(C = 1.0, kernel = 'linear')
# 学習
model.fit(data, labels)

# 回帰係数
# print(model.coef_)
# 切片(誤差)
# print(model.intercept_)

fig, ax = plt.subplots(figsize = (12, 9))

setoa = data[labels == 0]
versicolor = data[labels == 1]

plt.scatter(setoa[:, 0], setoa[:, 1], s = 300, c = 'white', linewidths = 2, edgecolor = 'lightgray')
plt.scatter(versicolor[:, 0], versicolor[:, 1], s = 300, c = 'firebrick', linewidths = 2, edgecolor = 'lightgray')

Xi = np.linspace(4, 7.25)
Y = -model.coef_[0][0] / model.coef_[0][1] * Xi - model.intercept_ / model.coef_[0][1]

ax.plot(Xi, Y, linestyle = 'dashed', linewidth = 3)

plt.grid(True)
plt.show()