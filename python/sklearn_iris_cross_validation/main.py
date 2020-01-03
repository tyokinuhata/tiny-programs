import sklearn.datasets as datasets

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

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

# 学習済モデルに学習データを分類させる際の精度
predict_train = model.predict(train_data_std)
# 分類精度(正解率)の算出
accuracy_train = accuracy_score(train_labels, predict_train)
print('%.2f' % accuracy_train)

# 学習済みモデルに学習データを分類させる際の精度
predict_test = model.predict(test_data_std)
accuracy_test = accuracy_score(test_labels, predict_test)
print(accuracy_test)