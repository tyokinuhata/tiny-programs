import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg')
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

img_resize = cv2.resize(img_rgb, (img_rgb.shape[1] * 2, img_rgb.shape[0] * 2))
plt.imshow(img_resize)
plt.show()

img_resize = cv2.resize(img_rgb, (img_rgb.shape[1] // 8, img_rgb.shape[0] // 8))
plt.imshow(img_resize)
plt.show()