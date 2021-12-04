# ワイルドカードインポート
# ワイルドカードインポートの場合、アンダースコアで始まる名前をインポートしない
# ただし、__all__でこの振る舞いを上書きできる模様
from module import *

# 以下のインポートではアンダースコアで始まる名前をインポートできる
# from module import external, _internal

# 以下のインポートもアンダースコアで始まる名前をインポートできる
import module

print(external())
# NameError: name '_internal' is not defined
print(_internal())

print(module.external())
print(module._internal())
