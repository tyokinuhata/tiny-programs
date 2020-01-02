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
print(model.coef_)
# 切片(誤差)
print(model.intercept_)