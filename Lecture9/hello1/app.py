# Uses request.args.get
from flask import Flask, render_template
app = Flask(__name__)
@app.route("/")
def index():
    name = request.args.get("name")
    return render_template("index.html", placeholder=name)
