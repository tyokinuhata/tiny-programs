import cv2
import matplotlib.pyplot as plt

img_bgr = cv2.imread('sample.jpg')
img_gs = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2GRAY)
cv2.imwrite('sample2.jpg', img_gs)