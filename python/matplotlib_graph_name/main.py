import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 100)
plt.plot(x, np.arctan(x))
plt.title('Title for the Graph')
plt.xlabel('Label for X-axis')
plt.ylabel('Label for Y-axis')
plt.show()