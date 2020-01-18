# PIL ... Pillow. 現在開発が停止しているPIL(Python Image Library)からforkされた画像処理ライブラリ
#         OpenCVよりもできることの幅は狭いが, シンプルで使いやすい
from PIL import Image

img = Image.open('./sample.jpg')
img.show()