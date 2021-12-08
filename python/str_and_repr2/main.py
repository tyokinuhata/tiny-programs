import datetime

today = datetime.date.today()

# 2021-12-08
# __str__の結果は読みやすいものが求められる
print(str(today))

# datetime.date(2021, 12, 8)
# __repr__の結果は一義的(誤解がない)であることが求められる
# 得られる文字列は開発者のデバッグ支援に利用できるよう意図されている
print(repr(today))
