class BaseValidationError(ValueError):
    pass

class NameTooShortError(BaseValidationError):
    pass

class NameTooLongError(BaseValidationError):
    pass

class NameTooCuteError(BaseValidationError):
    pass

def validate(name):
    if len(name) < 10:
        raise NameTooShortError(name)

name = "jane"
try:
    validate(name)
# このパッケージのエラーを全て処理できるようなtry ... except文を記述できる
# 逆に、より具体的な例外をキャッチすることもできる
except BaseValidationError as err:
    handle_validation_error(err)

# カスタム例外クラスを定義すると、EAFP(Easier to Ask for Forgiveness than Permission)コーディングスタイルを導入しやすくなる
# 「許可を得るよりも許しを請う方が容易」というマーフィーの法則に基づいている
# この場合は、仮定が偽と評価された場合に例外がキャッチされることを前提とするコーディングスタイルを指している
