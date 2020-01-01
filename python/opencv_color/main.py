import cv2
import matplotlib.pyplot as plt

# BGR(Blue, Green, Red)
img_bgr = cv2.imread('sample.jpg')
# print(img_bgr)
plt.imshow(img_bgr)
plt.show()

# RGB(Red, Green, Blue)
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)
plt.imshow(img_rgb)
plt.show()

# HSV(Hue(色相), Saturation(彩度), Value(明度))
img_hsv = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2HSV)
plt.imshow(img_hsv)
plt.show()

# グレースケール
img_gs = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY)
plt.imshow(img_gs)
plt.show()