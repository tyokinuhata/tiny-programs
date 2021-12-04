# with文のコンテキストから抜けると自動でオープンファイルディスクリプタが閉じられる
# つまり、リソースの適切な確保と開放が簡単に、確実に行うことができる
with open("test.txt", "w") as  f:
    f.write("hello, world!")

# 上記は内部で以下のようなコードに変換される
# この場合、ファイルを開放する処理を書き忘れてリークする可能性がある
f = open("hello.txt", "w")
try:
    f.write("hello, world")
finally:
    f.close()
