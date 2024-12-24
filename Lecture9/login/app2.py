from flask import Flask, redirect, render_template, request, session

# Configure app
app = Flask(__name__)

# copy|paste to get sessions working in flask
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/login")
def login():
    return render_template("login.html")
