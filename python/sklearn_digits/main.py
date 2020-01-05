from sklearn import datasets
from sklearn import svm
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report

digits = datasets.load_digits()

# 学習データ
# print(digits.data)
# 学習データの次元数
# print(digits.data.ndim)
# 学習データの数 1797 x 64 ... つまり, 1794枚の画像データが8 x 8 = 64ピクセルのデータを持っている
# print(digits.data.shape)
# 学習データのラベル
# print(digits.target)
# 8 x 8の画像データ
# print(digits.images[2])

# zip ... ２つの配列から１つずつ要素を取り出してせっとにして１つの配列として返す
images_and_labels = list(zip(digits.images, digits.target))
# print(images_and_labels)

_len = len(digits.images)
# print(_len)
# print(digits.images.shape)
data = digits.images.reshape((_len, -1))
# print(data.shape)

# gamma ... １つの学習データがデータを分ける超平面に対して与える影響の範囲
#           gammaが小さいほど遠く, 大きいほど近くまで影響する
model = svm.SVC(gamma = 0.001)

# 学習データと検証用データに分ける
train_data = data[:_len // 2]
train_labels = digits.target[:_len // 2]
test_data = data[_len // 2:]
test_labels = digits.target[_len // 2:]

# 学習
model.fit(train_data, train_labels)

# 予測
predicted_data = model.predict(test_data)

# 分類結果

# preision(適合率) ... 正と予測したデータのうち, 実際に正であるものの割合
# recall(再現率) ... 実際に正であるもののうち, 正であると予測されたものの割合
# f1-score(F値) ... 再現率と適合率の調和平均
# support ... 個数

# accuracy ... 正答率
# macro avg ... マクロ平均
# weighted avg ... サンプル数で重み付けられた平均
print('%s\n%s\n' % (model, classification_report(test_labels, predicted_data)))
# コンフュージョンマトリックス(混同行列)
# ラベルと分類結果がどの程度離れているかのマトリックス
print('\n%s' % confusion_matrix(test_labels, predicted_data))