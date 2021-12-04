# contextlibはコンテキストマネージャーの抽象化レイヤを提供する
from contextlib import contextmanager

# ジェネレータベースのファクトリ関数
# contextlib.contextmanagerデコレータを使用するとwith文が自動でサポートされる
@contextmanager
def managed_file(name):
    try:
        f = open(name, "w")
        yield f
    finally:
        f.close()

with managed_file("hello.txt") as f:
    f.write("hello, world!")
