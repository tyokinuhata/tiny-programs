import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 2 * np.pi)
plt.plot(x, np.sin(x))
positions = [0, np.pi / 2, np.pi, np.pi * 3 / 2, np.pi * 2]
labels = ['0', '90', '180', '270', '360']
plt.xticks(positions, labels)
plt.show()