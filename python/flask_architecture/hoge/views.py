# ビュー

from hoge import app

@app.route('/')
def index():
    return 'hello, world!'