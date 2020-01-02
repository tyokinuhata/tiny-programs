import matplotlib.pyplot as plt

from sklearn import datasets
from mpl_toolkits.mplot3d import Axes3D
# PCA(Principal Component Analysis; 主成分分析)
# 教師なしの機械学習で多次元の特徴量の特徴を失わない前提でデータの特徴量を圧縮する
from sklearn.decomposition import PCA

iris = datasets.load_iris()

data = iris.data
labels = iris.target

x_min, x_max = data[:, 0].min(), data[:, 0].max()
y_min, y_max = data[:, 1].min(), data[:, 1].max()

fig = plt.figure(2, figsize = (12, 9))
ax = Axes3D(fig, elev = -140, azim = 100)

reduced_data = PCA(n_components = 3).fit_transform(data)

ax.scatter(reduced_data[:, 0], reduced_data[:, 1], reduced_data[:, 2], s = 200, c = labels, cmap = plt.cm.Set2, edgecolor='darkgray')
plt.grid(True)
plt.show()