import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import axes3d, Axes3D

np.random.seed(0)
random_x = np.random.randn(100)
random_y = np.random.randn(100)
random_z = np.random.randn(100)

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1, projection = "3d")

x = np.ravel(random_x)
y = np.ravel(random_y)
z = np.ravel(random_z)

c = 'r'
m = '^'
s = 300
ax.scatter3D(x, y, z, s = s, c = c, marker = m)
plt.show()