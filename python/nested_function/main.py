# 入れ子の関数、ネストした関数、内側の関数

def speak(text):
    def murmur(t):
        return t.lower() + "..."
    return murmur(text)

print(speak("Hello, World"))

# speakの外にmurmurは存在しない
# murmur("Yo")
# speak.murmur

# 振る舞いを戻り値として返すこともできる
def get_speak_func(volume):

    def murmur(text):
        return text.lower() + "..."

    def yell(text):
        return text.upper() + "!"

    if volume > 0.5:
        return yell
    else:
        return murmur

print(get_speak_func(0.3))
print(get_speak_func(0.7))
