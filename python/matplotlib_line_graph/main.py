import matplotlib.pyplot as plt
import numpy as np

plt.plot([1, 2, 3, 4])
plt.show()

plt.plot([4, 3, 2, 1])
plt.show()

x = np.array([1, 2, 3, 4, 5])
y = np.array([100, 200, 300, 400, 500])
plt.plot(x, y)
plt.show()

x = np.arange(5)
y = np.arange(start = 100, stop = 600, step = 100)
plt.plot(x, y)
plt.show()

vol = 30
x = np.arange(vol)
y = [x_i + np.random.randn(1) for x_i in x]
a, b = np.polyfit(x, y, 1)
plt.plot(x, y, 'o', np.arange(vol), a * np.arange(vol) + b, '-')
plt.show()