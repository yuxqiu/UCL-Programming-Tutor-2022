# Copy from flask official website
from flask import Flask, render_template

app = Flask(__name__, template_folder='.')


@app.route("/hello")
def hello():
    return "Hello, World!"


@app.route("/")
def index():
    return render_template('index.html', feeling="happy")
