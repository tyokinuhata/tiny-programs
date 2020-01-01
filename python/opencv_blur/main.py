import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg')
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

img_blur = cv2.GaussianBlur(img_rgb, (15, 15), 0)

plt.imshow(img_blur)
plt.show()