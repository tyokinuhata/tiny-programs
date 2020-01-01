import cv2
import matplotlib.pyplot as plt
import numpy as np

img_bgr = cv2.imread('sample.jpg')
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

filter = np.array([[0, 1, 0], [1, 0, 1], [0, 1, 0]], np.uint8)

img_dilate = cv2.dilate(img_rgb, filter)
plt.imshow(img_dilate)
plt.show()

img_erode = cv2.erode(img_rgb, filter)
plt.imshow(img_erode)
plt.show()
