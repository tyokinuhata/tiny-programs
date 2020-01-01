import matplotlib.pyplot as plt
import numpy as np

# plt.subplot(行・列・全体を通しての番号)
plt.subplot(211)
x = np.linspace(0, 10, 100)
plt.plot(x, np.sin(x))

plt.subplot(212)
x = np.linspace(0, 10, 100)
plt.plot(x, np.sin(x))

plt.show()