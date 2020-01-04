import sklearn.datasets as datasets
import matplotlib.pyplot as plt
import numpy as np

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
from mlxtend.plotting import plot_decision_regions as pdr

iris = datasets.load_iris()

data = iris.data[:, [2, 3]]
labels = iris.target

# トレーニングデータ(学習データ)とテストデータに分ける
# トレーニングデータ80%, テストデータ20%
train_data, test_data, train_labels, test_labels = train_test_split(data, labels, test_size = 0.2, random_state = None)

# データの標準化処理
sc = StandardScaler()
sc.fit(train_data)
train_data_std = sc.transform(train_data)
test_data_std = sc.transform(test_data)

# 学習
model = SVC(kernel = 'linear', random_state = None)
model.fit(train_data_std, train_labels)

# vstack ... 配列を縦に連結
# hstack ... 配列を横に連結
combined_data_std = np.vstack((train_data_std, test_data_std))
combined_labels = np.hstack((train_labels, test_labels))

fig = plt.figure(figsize = (12, 8))

# 散布図の設定
scatter_kwargs = {'s': 300, 'edgecolor': 'white', 'alpha': 0.5}
contourf_kwargs = {'alpha': 0.2}
scatter_highlight_kwargs = {'s': 200, 'labels': 'Test', 'alpha': 0.7}

# mlxtend > plot_decision_regions ... 分類器の決定境界を描いてくれる
pdr(combined_data_std, combined_labels, clf = model, scatter_kwargs = scatter_kwargs, contourf_kwargs = contourf_kwargs, scatter_highlight_kwargs = scatter_highlight_kwargs)
plt.show()

# テスト
# test_data = np.array([[4.1, 5.2]])
# res = model.predict(test_data)
# print(res)