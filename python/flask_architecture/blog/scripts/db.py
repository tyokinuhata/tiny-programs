from flask_script import Command
from entries import db

class InitDB(Command):
    "Create database"

    def run(self):
        db.create_all()