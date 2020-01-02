import numpy as np
import matplotlib.pyplot as plt
import sklearn.datasets as datasets

from sklearn.svm import SVC

iris = datasets.load_iris()
data = iris.data[:, [0, 1]]
labels = iris.target

data = data[labels != 2]
labels = labels[labels != 2]