import matplotlib.pyplot as plt
import numpy as np

x = np.random.rand(100)
y = np.random.rand(100)

plt.scatter(x, y)
plt.show()

plt.scatter(x, y, s = 600, c = "pink", alpha = 0.5, linewidths = "2", edgecolors = "red")
plt.show()

plt.scatter(x, y, s = 300, c = y, cmap = "Greens")
plt.show()