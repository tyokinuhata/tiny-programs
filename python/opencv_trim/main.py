import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg')
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

size = img_rgb.shape
# print(size)

img_trim = img_rgb[:size[0] // 2, :size[1] // 2]
plt.imshow(img_trim)
plt.show()