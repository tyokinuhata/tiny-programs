def yell(text):
    return text.upper() + "!"

bark = yell

# 関数はデータ構造にも格納できる
funcs = [bark, str.lower, str.capitalize]
print(funcs)

for f in funcs:
    print(f, f("hey there"))

print(funcs[0]("heyho"))
