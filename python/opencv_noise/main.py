import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg')
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

img_noise = cv2.fastNlMeansDenoisingColored(img_rgb)

plt.imshow(img_noise)
plt.show()
