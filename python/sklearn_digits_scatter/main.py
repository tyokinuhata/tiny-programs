import matplotlib.pyplot as plt

from sklearn import datasets
from sklearn import decomposition
from mpl_toolkits.mplot3d import Axes3D

def get_color (color):
    if color == 0:
        return 'red'
    elif color == 1:
        return 'orange'
    elif color == 2:
        return 'yellow'
    elif color == 3:
        return 'greenyellow'
    elif color == 4:
        return 'green'
    elif color == 5:
        return 'cyan'
    elif color == 6:
        return 'blue'
    elif color == 7:
        return 'navy'
    elif color == 8:
        return 'purple'
    else:
        return 'black'

digits = datasets.load_digits()

data = digits.data
labels = digits.target

# PCA(主成分分析)による次元削減
pca = decomposition.PCA(n_components = 3)
reduced_data = pca.fit_transform(data)

fig = plt.figure(figsize = (12, 9))
subfig = fig.add_subplot(111, projection = '3d')
colors = list(map(get_color, labels))

subfig.scatter(reduced_data[:, 0], reduced_data[:, 1], reduced_data[:, 2], s = 50, c = colors, alpha = 0.3)
plt.show()