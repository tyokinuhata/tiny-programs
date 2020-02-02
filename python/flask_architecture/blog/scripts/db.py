from flask_script import Command
from blog import db

class InitDB(Command):
    "Create database"

    def run(self):
        db.create_all()