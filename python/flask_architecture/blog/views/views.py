from flask import redirect, url_for
from blog import app

@app.errorhandler(404)
def not_found(error):
    return redirect(url_for('entry.entries'))