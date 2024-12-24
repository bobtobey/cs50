# Consolidating routes
from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", ["POST"])
def register():

    if not request.form.get("name"):
        return "failure"
