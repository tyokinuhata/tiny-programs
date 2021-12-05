# テンプレート文字列
# コア機能ではないため、標準ライブラリをインポートする必要がある
from string import Template

errno = 50159747054
name = "Bob"

t = Template("Hey, $name!")
print(t.substitute(name=name))

# テンプレート文字列ではフォーマット指定子を使用できない
t = Template("Hey $name, there is a $error error!")
print(t.substitute(name=name, error=hex(errno)))
