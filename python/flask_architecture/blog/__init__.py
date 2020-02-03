# アプリケーション本体

from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config.from_object('blog.config')

db = SQLAlchemy(app)

from blog.views.entries import entry
from blog.views import views

app.register_blueprint(entry)