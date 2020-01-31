# アプリケーション本体

from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config.from_object('hoge.config')

db = SQLAlchemy(app)

import hoge.views
