import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg')
img_gs = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY)
retval, img_bin = cv2.threshold(img_gs, 100, 255, 0)

# OpenCV4では動作せず
img, contours, hierarchy = cv2.findContours(img_bin, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
img_contour = cv2.drawContours(img, contours, -1, (0, 0, 255), 3)

plt.imshow(img_contour)
plt.show()
