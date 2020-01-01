import matplotlib.pyplot as plt
import numpy as np

plt.figure(figsize = (4, 4))

x = np.linspace(0, 2 * np.pi)
plt.plot(x, np.sin(x))
plt.show()