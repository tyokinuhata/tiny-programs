# ビュー

from flask import render_template
from hoge import app

@app.route('/')
def root():
    return render_template('root/index.html')