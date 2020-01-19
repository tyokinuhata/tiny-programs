import numpy as np
import matplotlib.pyplot as plt
import keras

from keras.datasets import mnist
from keras import backend as Keras
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D

BATCH_SIZE = 128
NUM_CLASSES = 10
EPOCHS = 1
IMG_ROWS, IMG_COLS = 28, 28

hand_written_number_names = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

(train_data, train_labels), (test_data, test_labels) = mnist.load_data()
# print(train_data.shape, test_data.shape)

# 学習モデルに合わせてデータ配列の形状を変換
# Conv2Dクラス(TensorFlowの２次元畳み込み層のクラス)に渡す引数にデータの形状(input_shape)を渡す必要がある
#
# image_data_format() ... Keras内部に設定されている画像におけるデフォルトのフォーマット規則(channels_first/channels_last)を取得する
if Keras.image_data_format() == 'channels_first':
    train_data = train_data.reshape(train_data.shape[0], 1, IMG_ROWS, IMG_COLS)
    test_data = test_data.reshape(test_data.shape[0], 1, IMG_ROWS, IMG_COLS)
    input_shape = (1, IMG_ROWS, IMG_COLS)
else:
    train_data = train_data.reshape(train_data.shape[0], IMG_ROWS, IMG_COLS, 1)
    test_data = test_data.reshape(test_data.shape[0], IMG_ROWS, IMG_COLS, 1)
    input_shape = (IMG_ROWS, IMG_COLS, 1)
# print(train_data.shape, test_data.shape)

# 学習モデルに合わせてデータ調整
# 学習用のモデルに渡すにはuint8(8ビット符号付整数) -> float32(32ビット浮動小数点数)に変換する必要がある
train_data = train_data.astype('float32')
test_data = test_data.astype('float32')
# print(test_data)

# 正規化処理
# データセットのデータが0~255の間に分布している値のため, 255で割ることによって0.0~1.0の間に分布するようになる
train_data /= 255
test_data /= 255

# ラベルデータの変換
# One-hotベクトル変換
# 3 -> [0, 0, 0, 1, 0, 0, 0, 0, 0, 0]
# print(train_labels, test_labels)
train_labels = keras.utils.to_categorical(train_labels, NUM_CLASSES)
test_labels = keras.utils.to_categorical(test_labels, NUM_CLASSES)
# print(train_labels, test_labels)

# モデルの構築
# Kerasにおけるニューラルネットワークの構築方法 ... Sequential Model, Functional API, Modelクラス
#                                            Sequential Modelを使う方法が一番直感的
model = Sequential()

# Conv2D ... 2次元の畳み込み層. 入力層. Conv1Dというものもある.
#            Conv2D(ユニット数, 2次元の畳み込みエリアの幅と高さ, 活性化関数の種類, 入力データの形状)
model.add(Conv2D(32, kernel_size = (3, 3), activation = 'relu', input_shape = input_shape))
model.add(Conv2D(64, (3, 3), activation = 'relu'))
# MaxPooling2D ... プーリング層
model.add(MaxPooling2D(pool_size = (2, 2)))
# Dropout ... ドロップアウト層. 過学習を防ぐ
model.add(Dropout(0.25))
# Flatten ... 入力の平滑化
model.add(Flatten())
# Dense ... 全結合層
model.add(Dense(128, activation = 'relu'))
model.add(Dropout(0.5))
# ソフトマックス. 出力を確率の形に変換する
model.add(Dense(NUM_CLASSES, activation = 'softmax'))

model.summary()

# モデルのコンパイル
model.compile(optimizer = keras.optimizers.Adadelta(), loss = keras.losses.categorical_crossentropy, metrics = ['accuracy'])

# グラフの描画
def plot_loss_accuracy_graph(fit_record):
    # 誤差の履歴をプロット
    plt.plot(fit_record.history['loss'], '-D', color = 'blue', label = 'train_loss', linewidth = 2)
    plt.plot(fit_record.history['val_loss'], '-D', color = 'blue', label = 'train_loss', linewidth = 2)
    plt.title('LOSS')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend(loc = 'upper right')
    plt.show()
    # 精度の履歴をプロット
    plt.plot(fit_record.history['acc'], '-o', color = 'green', label = 'train_accuracy', linewidth = 2)
    plt.plot(fit_record.history['val_acc'], '-o', color = 'black', label = 'val_accuracy', linewidth = 2)
    plt.title('ACCURACY')
    plt.xlabel('Epochs')
    plt.ylabel('Accuracy')
    plt.legend(loc = 'lower right')
    plt.show()

# 学習
fit_record = model.fit(train_data, train_labels, batch_size = BATCH_SIZE, epochs = EPOCHS, verbose = 1, validation_data = (test_data, test_labels))
plot_loss_accuracy_graph(fit_record)

# 検証
res_score = model.evaluate(test_data, test_labels, verbose = 0)
# 検証誤差, 検証正解率
print(res_score[0], res_score[1])

# 予測
predictions = model.predict(test_data)

# 画像の描画
def plot_image(location, predictions, labels, dataset):
    predictions, labels, img = predictions[location], labels[location], dataset[location]

    plt.grid(False)
    plt.xticks([])
    plt.yticks([])
    plt.imshow(img)

    # argmax ... 配列で一番大きい要素のインデックスを返す
    predicted_label = np.argmax(predictions)
    if predicted_label == labels:
        color = 'green'
    else:
        color = 'red'
    # max ... 配列から最大値を取り出す
    plt.xlabel('{} {:2.0f}% ({})'.format(hand_written_number_names[predicted_label], 100 * np.max(predictions), hand_written_number_names[labels]), color = color)

# ヒストグラムの描画
def plot_labels_graph(location, predictions, labels):
    predictions, labels = predictions[location], labels[location]

    plt.grid(False)
    plt.xticks([])
    plt.yticks([])

    this_plot = plt.bar(range(10), predictions, color = '#666666')
    plt.ylim([0, 1])
    predicted_label = np.argmax(predictions)
    this_plot[predicted_label].set_color('red')
    this_plot[labels].set_color('green')

# One-hotベクトルのラベルを整数に変換する
def convert_one_hot_vector_2_integers(one_hot_vector):
    return [np.where(r == 1)[0][0] for r in one_hot_vector]

test_data = test_data.reshape(test_data.shape[0], IMG_ROWS, IMG_COLS)
location = 77
plt.figure(figsize = (6, 3))

plt.subplot(1, 2, 1)
plot_image(location, predictions, convert_one_hot_vector_2_integers(test_labels), test_data)

plt.subplot(1, 2, 2)
plot_labels_graph(location, predictions, convert_one_hot_vector_2_integers(test_labels))
_ = plt.xticks(range(10), hand_written_number_names, rotation = 45)