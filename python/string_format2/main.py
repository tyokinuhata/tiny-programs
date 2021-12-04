errno = 50159747054
name = "Bob"

# format関数による文字列フォーマット
print("Hello, {}".format(name))

# :x のようにフォーマット仕様を指定できる
print("Hey {name}, there is a 0x{errno:x} error!".format(name=name, errno=errno))
