from flask_script import Command
from hoge import db

class InitDB(Command):
    "Create database"

    def run(self):
        db.create_all()