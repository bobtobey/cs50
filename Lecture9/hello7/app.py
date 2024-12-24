# Consolidating routes
from flask import Flask, render_template, request

app = Flask(__name__)

# creating a second route
@app.route("/greet", methods=["GET", "POST"])
def index():
    if request.method == "post":
        
    return render_template("index.html")

