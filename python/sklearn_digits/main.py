from sklearn import datasets

digits = datasets.load_digits()

# 学習データ
print(digits.data)
# 学習データの次元数
print(digits.data.ndim)
# 学習データの数 1797 x 64 ... つまり, 1794枚の画像データが8 x 8 = 64ピクセルのデータを持っている
print(digits.data.shape)
# 学習データのラベル
print(digits.target)
# 8 x 8の画像データ
print(digits.images[2])