# カスタム例外クラス
# 追加のデバッグ情報の提供によるカスタム関数、カスタムモジュール等のメンテナンス性の向上

def validate(name):
    if len(name) < 10:
        # ライブラリの一部として呼び出されたとき、スタックトレースを見てもバグの原因が分かりにくいため、関数の実装を調べる必要が出てくる
        raise ValueError

# validate("joe")


# 一般的に、カスタム例外はルートクラスExceptionか組み込み例外のValueError/TypeError等の派生クラスとして実装することが多い
class NameTooShortError(ValueError):
    pass

def validate(name):
    if len(name) < 10:
        # 例外の名前を見ただけでバグが推測できる
        # インスタンス化の際にname変数を渡している
        raise NameTooShortError(name)

validate("jane")

