import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg', 0)
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

retval, img_bin = cv2.threshold(img_rgb, 100, 255, cv2.THRESH_TOZERO)

plt.imshow(img_bin)
plt.show()