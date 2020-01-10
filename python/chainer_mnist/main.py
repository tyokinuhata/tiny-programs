import numpy as np
import matplotlib.pyplot as plt
import chainer
import chainer.links as L
import chainer.functions as F

from chainer import iterators
from chainer import optimizers
from chainer.dataset import concat_examples

# class <クラス名> (<継承するクラス名>):
# MLP ... Multi-Layer Perceptron; 多層パーセプトロン
class MLP (chainer.Chain):

    # __init__はPythonの特殊関数
    # インスタンスの作成時に呼ばれる
    #
    # self ... インスタンス自身
    #
    # number_hidden_units ... 中間層(隠れ層)のユニット数
    # number_out_units ... 出力層のユニット数(0~9の数字の分類を出力するため10)
    def __init__ (self, number_hidden_units = 1000, number_out_units = 10):
        super(MLP, self).__init__()
        # with文 ... クローズが必要な処理を簡潔・安全に記述できる構文
        # 入力層・中間層(隠れ層)・出力層の定義
        with self.init_scope():
            # 全結合層の定義
            # 最初の第一引数がNoneになっているのはデータがその層に入力された
            self.layer1 = L.Linear(None, number_hidden_units)
            self.layer2 = L.Linear(number_hidden_units, number_hidden_units)
            self.layer3 = L.Linear(number_hidden_units, number_out_units)

    # __call__はPythonの特殊関数
    # インスタンスをメソッドっぽく書いたときに呼び出される
    # 例: model = MLP()
    #     model(input_data)
    #
    # relu ... ReLU関数
    def __call__ (self, input_data):
        res1 = F.relu(self.layer1(input_data))
        res2 = F.relu(self.layer2(res1))
        return self.layer3(res2)

model = MLP()
# 入力層のバイアスパラメータの配列の形
# print(model.layer1.b.shape)
# 1000ユニット(パーセプトロン)
# print(model.layer1.b.data)
# 学習前の重み配列(None)
# print(model.layer1.W.array)

# MNIST(Mixed National Institute of Standards and Technology database)
# 手書き数字のデータセットが70,000個ある
# 28 x 28 = 784次元のデータ
# scikit-learnの手書き数字は8 x 8のため, こちらの方がより特徴量が多くなっている
train_data, test_data = chainer.datasets.get_mnist(withlabel = True, ndim = 1)
# print(train_data)
# print(test_data)
# print(len(train_data))
# print(len(test_data))

# 学習用データと検証用データの反復子をデータセットを元に作成
# SerialIteratorはChainerで最もシンプルなイテレータ
BATCH_SIZE = 100
train_iterator = iterators.SerialIterator(train_data, BATCH_SIZE)
test_iterator = iterators.SerialIterator(test_data, BATCH_SIZE, repeat = False, shuffle = False)

# 最適化
# SGD(勾配降下法)
# lr ... learn rate(学習率)
optimizer = optimizers.SGD(lr = 0.01)
optimizer.setup(model)

# 検証処理
def testEpoch(train_iterator, train_loss):
    print('学習回数: {:02d} --> 学習誤差: {:.02f}' .format(train_iterator.epoch, float(train_loss.data)), end = '')

    test_losses = []
    test_accuracies = []

    while True:
        test_dataset = test_iterator.next()

        test_data, test_labels = concat_examples(test_dataset)

        test_predition = model(test_data)

        test_loss = F.softmax_cross_entropy(test_predition, test_labels)
        test_losses.append(test_loss.data)

        # 精度の計算
        accuracy = F.accuracy(test_predition, test_labels)

        test_accuracies.append(accuracy.data)

        if test_iterator.is_new_epoch:
            test_iterator.reset()
        # 書籍通りにやると落ちる(バージョンの問題？)
        # AttributeError: can't set attribute
        #     test_iterator.epoch = 0
        #     test_iterator.current_position = 0
        #     test_iterator.is_new_epoch = False
        #     test_iterator._pushed_position = None
            break

        print('検証誤差: {:.04f} 検証精度: {:.02f}' .format(np.mean(test_losses), np.mean(test_accuracies)))

# ミニバッチ ... 勾配降下法で損失関数の最小値を探索する場合, データ１つ１つを用いてパラメータを更新するのは効率が悪い.
#              そのため, データセットからランダムに取り出して複数個セットでまとめて入力する.
# エポック ... データセット中のデータを全て使い切るまでにかかる時間.
#             通常は複数のエポックを通して学習させる.
MAX_EPOCH = 20
while train_iterator.epoch < MAX_EPOCH:
    train_dataset = train_iterator.next()

    # タプルに変換
    train_data, train_labels = concat_examples(train_dataset)

    # 学習
    train_prediction = model(train_data)

    # ソフトマックス関数 ... 出力層で多用される関数.
    #                     特に多クラス分類において使用される.
    #                     0~1の実数値に変換して出力する.
    #
    # 交差エントロピー誤差 ... 損失関数の一種.
    #                       重みを自動で更新する.
    train_loss = F.softmax_cross_entropy(train_prediction, train_labels)

    # 勾配の計算
    # 損失関数をできるだけ小さくすることを実現するには毎回パラメータを調整する際に, 損失関数が小さくなっていく方向を知ることが重要
    model.cleargrads()
    # 誤差逆伝播
    # 学習結果とラベルの比較結果を前にフィードバックし, 各層の損失関数が調整する.
    train_loss.backward()
    # 最適化(誤差を反映してパラメータを更新)
    optimizer.update()

    if train_iterator.is_new_epoch:
        testEpoch(train_iterator, train_loss)