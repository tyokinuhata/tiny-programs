import sklearn.datasets as datasets

from sklearn.svm import SVC

iris = datasets.load_iris()

model = SVC(C = 1.0, kernel = 'linear', decision_function_shape = 'ovr')
data = iris.data
labels = iris.target

model.fit(data, labels)

test_data = data[:1, :]
res = model.predict(test_data)
print(res)