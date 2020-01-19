import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
import keras

from keras.models import Sequential
from keras.layers import Dense, Flatten
from keras.optimizers import Adam

fashion_mnist = keras.datasets.fashion_mnist
(train_data, train_labels), (test_data, test_labels) = fashion_mnist.load_data()

fashion_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat', 'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

# print(train_data.shape, len(train_labels))
# print(test_data.shape, len(test_labels))

# plt.figure(figsize = (12, 12))
# for i in range(16):
#     plt.subplot(4, 4, i + 1)
#     plt.xticks([])
#     plt.yticks([])
#     plt.grid(False)
#     plt.imshow(train_data[i], cmap = 'inferno')
#     plt.xlabel(fashion_names[train_labels[i]])
# plt.show()

BATCH_SIZE = 128
NUM_CLASSES = 10
EPOCHS = 20
IMG_ROWS, IMG_COLS = 28, 28

train_data = train_data.astype('float32')
test_data = test_data.astype('float32')

train_data /= 255
test_data /= 255

model = Sequential()

# 入力層
# 28 x 28の画像のため784
model.add(Flatten(input_shape = (IMG_ROWS, IMG_COLS)))
# 中間層
# ニューロン数は自由
model.add(Dense(128, activation = tf.nn.relu))
# 出力層
# 10種類のため10
model.add(Dense(10, activation = tf.nn.softmax))

# モデルの概要を表示
model.summary()

# モデルのコンパイル
model.compile(optimizer = Adam(), loss = 'sparse_categorical_crossentropy', metrics = ['accuracy'])

# 学習
fit_record = model.fit(train_data, train_labels, batch_size = BATCH_SIZE, epochs = EPOCHS, verbose = 1, validation_data = (test_data, test_labels))

# 検証
res_score = model.evaluate(test_data, test_labels)
# 検証誤差, 検証正解率
print(res_score[0], res_score[1])

location = 4
img = test_data[location]
print(img.shape)
img = (np.expand_dims(img, 0))
print(img.shape)

# 予測
predictions = model.predict(img)
print(predictions)
predictions_num = np.argmax(predictions[0])
print(fashion_names[predictions_num])

# 学習済みモデルの保存
model.save('tensorflow-keras-fashion-mnist-model.h5')