import flask

app = flask.Flask(__name__)

@app.route('/')
def index():
    return 'hello, world!'

# __name__ ... 特殊な変数. Pythonファイルのモジュール名が入っている
#              import hoge とした場合, __name__は "hoge" になる
#              python hoge.py とした場合, __name__は "__main__" になる
#              つまり, この判定を入れることで, モジュールとしてインポートした場合には実行されないようにしている
if __name__ == '__main__':
    app.run(debug = False, host = '0.0.0.0', port = 5000)