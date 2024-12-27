import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # return apology("TODO")
    # User reached route via POST - lookup and purchase stock
    if request.method == "POST":
        # Ensure valid symbol and shares were submitted
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if not symbol:
            return apology("must provide symbol", 403)

        if not shares:
            return apology("must provide number of shares", 403)

        try:
            shares = int(shares)
        except ValueError:
            return apology("must provide number of shares", 403)
        if shares < 1:
            return apology("must provide positive amount of shares", 403)

        # look up valid stock symbol
        quote = lookup(symbol)
        if not quote:
            return apology("must provide valid symbol", 403)

        # Check database for user funds
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

        # Ensure funds are available
        moneyavailable = rows[0]['cash']
        price = quote['price']
        # calculate total stock price
        total_cost = price * shares
        # Execute trade if funds available
        if moneyavailable > total_cost:
            success = false
            try:
                # Start transaction ensure both update and insert operations execute or fail as 1
                db.execute("BEGIN TRANSACTION")
                transaction_type = "BUY"
                print(f"Avail $: {moneyavailable}")
                print(f"Stock $: {price}")
                print(f"Total Stock Cost $: {total_cost}")
                print(f"Available {moneyavailable - total_cost}")

                # subtract fund from user cash on successful purchase
                db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, session["user_id"])

                # BUY stock and insert transaction details to db (variables) and then (placeholders ?x2) and (arguments)
                db.execute("INSERT INTO transactions (symbol, shares, price, total_cost, transaction_type, user_id) VALUES(?, ?, ?, ?, ?, ?)"
                        , symbol, shares, price, total_cost, transaction_type, session["user_id"])
                # Commit transaction
                db.execute("COMMIT")
                success = true
            except:
                db.execute("ROLLBACK")
                return apology("Transaction failed.", 403)
        else:
            return apology("Add funds to your account.", 403)

        return render_template("index.html", success=success)
    # User reached route via GET - display stock quote form
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # return apology("TODO")
    # User reached route via POST - lookup stock symbol and result
    if request.method == "POST":
        # Ensure symbol was submitted
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 403)

        # look up valid stock symbol
        quote = lookup(symbol)
        if not quote:
            return apology("must provide valid symbol", 403)

        return render_template("quoted.html", quote=quote)
    # User reached route via GET - display stock quote form
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # return apology("TODO")
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username or not username.isalpha():
            return apology("must provide valid username", 403)

        # Ensure password was submitted
        elif not password:
            return apology("must provide valid password", 403)

        # Confirm password match
        elif password != confirmation:
            return apology("must provide matching passwords", 403)

        # Check database for username
        usercheck = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        # Ensure username exists
        if len(usercheck) != 0:
            return apology("username already exists", 403)

        # Generate hash for password
        hash = generate_password_hash(password)

        # Insert username and password to db (variables) and then (placeholders ?x2) and (arguments)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        # Go to login page
        return render_template("login.html")
    # User reached route via GET and needs to register for site
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
