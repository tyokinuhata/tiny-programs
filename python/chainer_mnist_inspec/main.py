import matplotlib.pyplot as plt
import chainer
import chainer.links as L
import chainer.functions as F

from chainer import serializers

class MLP (chainer.Chain):
    def __init__ (self, number_hidden_units = 1000, number_out_units = 10):
        super(MLP, self).__init__()
        with self.init_scope():
            self.layer1 = L.Linear(None, number_hidden_units)
            self.layer2 = L.Linear(number_hidden_units, number_hidden_units)
            self.layer3 = L.Linear(number_hidden_units, number_out_units)

    def __call__ (self, input_data):
        res1 = F.relu(self.layer1(input_data))
        res2 = F.relu(self.layer2(res1))
        return self.layer3(res2)

model = MLP()
serializers.load_npz('chainer-mnist.model', model)
train_data, test_data = chainer.datasets.get_mnist(withlabel = True, ndim = 1)

data_location = 6423
predict_data, predict_label = test_data[data_location]

# plt.imshow(predict_data.reshape(28, 28), cmap = 'gray')
# plt.show()
# print(predict_label)

predict_data = predict_data[None, ...]
# 分類
predict = model(predict_data)
res = predict.array
probable_label = res.argmax(axis = 1)
print(res)
print(probable_label[0])