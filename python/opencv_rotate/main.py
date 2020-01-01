import cv2
import matplotlib.pyplot as plt
import numpy as np

img_bgr = cv2.imread('sample.jpg')
img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

# cv2.getRotationMatrix2D(回転の中心, 回転角度, 倍率)
mat = cv2.getRotationMatrix2D(tuple(np.array(img_rgb.shape[:2]) / 2), 45, 1.0)
# cv2.warpAffine(画像, 変換行列, 画像サイズ)
img_rotate = cv2.warpAffine(img_rgb, mat, img_rgb.shape[:2])

plt.imshow(img_rotate)
plt.show()