import numpy as np
import chainer
import chainer.links as L
import chainer.functions as F

from chainer import iterators

# class <クラス名> (<継承するクラス名>):
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