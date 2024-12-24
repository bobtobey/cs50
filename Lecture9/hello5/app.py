# Says hello to request.args["name"]
from flask import Flask, render_template, request

app = Flask(__name__)

#  this route just serves index.html
@app.route("/")
def index():
    return render_template("index.html")

# creating a second route
@app.route("/greet")
def greet():
    name = request.form.get("name", "world")
    return render_template("greet.html", name=name)
