# コンテキストマネージャー
# with文をサポートするためのプロトコル(インタフェース)
# __enter__と__exit__を追加する必要がある

class ManagedFile:
    def __init__(self, name):
        self.name = name

    def __enter__(self):
        self.file = open(self.name, "w")
        return self.file

    def __exit__(self, exc_type, exc_val, exc_tb):
        if self.file:
            self.file.close()

with ManagedFile("hello.txt") as f: # ここで__enter__が呼ばれる
    f.write("hello, world!")
# ここで__exit__が呼ばれる
