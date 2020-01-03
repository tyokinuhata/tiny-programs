import sklearn.datasets as datasets

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC

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
model.fit(train_data, train_labels)