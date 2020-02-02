# ビュー

from flask import request, redirect, render_template, url_for
from blog import app, db
from blog.models.entries import Entry

@app.route('/')
def entries():
    entries = Entry.query.order_by(Entry.id.desc()).all()
    return render_template('entries/index.html', entries = entries)

@app.route('/post', methods = ['POST'])
def post():
    entry = Entry(title = request.form['title'], text = request.form['text'])
    db.session.add(entry)
    db.session.commit()
    return redirect(url_for('entries'))