class PrefixPostfixTest:
    def __init__(self):
        self.__bam__ = 42

# これはネームマングリングが行われない
print(PrefixPostfixTest().__bam__)

# 先頭と末尾にダンダーが付いている名前はPythonにおいて特別な用途の予約語として扱われるケースが多い
# これらはマジックメソッドと呼ばれる
