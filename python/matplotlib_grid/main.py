import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 100)
plt.plot(x, np.arctan(x))
plt.grid(True) # デフォルトはFalse
plt.show()