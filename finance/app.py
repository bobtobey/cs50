import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
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
    # Capture USER cash balance
    user_row = db.execute("SELECT cash, username FROM users WHERE id = ?", session["user_id"])
    cash = user_row[0]["cash"]
    name = user_row[0]["username"]

    # SQL select symbol, shares, current price, total value data from DB
    portfolio_rows = db.execute(
        "SELECT symbol, shares FROM portfolio WHERE user_id = ?", session["user_id"])

    # store current values by looping through db list
    stocks = []
    for portfolio_row in portfolio_rows:
        symbol = portfolio_row["symbol"]
        shares = portfolio_row["shares"]
        quote = lookup(symbol)
        current_price = quote['price']
        total_value = shares * current_price
        stocks.append({"symbol": symbol, "shares": shares,
                      "current_price": current_price, "total_value": total_value})

    # Get total acct value cash plus each total_value
    total_account_value = cash
    for stock in stocks:
        total_account_value += stock['total_value']

    # hide buy success message
    success = request.args.get("success", False)
    # get db column names from table
    headers = ["Symbol", "Shares", "Price", "Total"]
    # pass Stock info into the index.html
    return render_template("index.html", stocks=stocks, headers=headers, cash=cash, total_account_value=total_account_value, name=name, success=success)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # return apology("TODO")
    # User reached route via POST - lookup and purchase stock
    if request.method == "POST":
        # Ensure valid symbol and shares were submitted
        symbol = request.form.get("symbol")
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        if not symbol:
            return apology("must provide symbol", 400)

        if not shares:
            return apology("must provide number of shares", 400)

        try:
            shares = int(shares)
        except ValueError:
            return apology("must provide number of shares", 400)
        if shares < 1:
            return apology("must provide positive amount of shares", 400)

        # look up valid stock symbol
        quote = lookup(symbol)
        if not quote:
            return apology("must provide valid symbol", 400)

        # Check database for user funds
        rows = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

        # Ensure funds are available
        moneyavailable = rows[0]['cash']
        price = quote['price']
        # calculate total stock price
        total_cost = price * shares
        # Execute trade if funds available
        if moneyavailable > total_cost:
            try:
                # Start transaction ensure both update and insert operations execute or fail as 1
                db.execute("BEGIN TRANSACTION")
                transaction_type = "BUY"
                # subtract funds from user cash on successful purchase
                db.execute("UPDATE users SET cash = cash - ? WHERE id = ?",
                           total_cost, session["user_id"])

                # BUY stock and insert details into transactions db (variables) and then (placeholders ?x2) and (arguments)
                db.execute("INSERT INTO transactions (symbol, shares, price, total_cost, transaction_type, user_id) VALUES(?, ?, ?, ?, ?, ?)",
                           symbol, shares, price, total_cost, transaction_type, session["user_id"])

                # ADD stock and shares details into portfolio db (variables) and then (placeholders ?x2) and (arguments)
                portfolio_row = db.execute(
                    "SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)

                if len(portfolio_row) == 0:
                    # Stock not in portfolio insert in db
                    db.execute("INSERT INTO portfolio (symbol, shares, user_id) VALUES(?, ?, ?)",
                               symbol, shares, session["user_id"])
                else:
                    # Stock in portfolio update shares
                    current_shares = portfolio_row[0]["shares"]
                    new_shares = current_shares + shares
                    db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND symbol = ?",
                               new_shares, session["user_id"], symbol)

                # Commit transaction
                db.execute("COMMIT")
            except:
                db.execute("ROLLBACK")
                return apology("Transaction failed.", 400)
        else:
            return apology("Add funds to your account.", 400)

        # Redirect to homepage after successful buy
        return redirect(url_for("index", success="Your buy transaction was successful"))
    # User reached route via GET - display stock buy form
    else:
        success = request.args.get("success")
        return render_template("buy.html", success=success)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # return apology("TODO")
    # SQL select symbol/shares/buy or sell/price/time-date transaction details from DB
    transactions = db.execute(
        "SELECT symbol, shares, transaction_type, price, timestamp FROM transactions WHERE user_id = ?", session["user_id"])

    # get db column names from table
    headers = ["Symbol", "Shares", "Type", "Price", "Transacted"]
    # pass transactions into the index.html
    return render_template("history.html", transactions=transactions, headers=headers)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 400)

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
        symbol = request.form.get("symbol").upper()
        if not symbol:
            return apology("must provide symbol", 400)

        # look up valid stock symbol
        quote = lookup(symbol)
        if not quote:
            return apology("must provide valid symbol", 400)

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
        if not username:
            return apology("must provide valid username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide valid password", 400)

        # Confirm password match
        elif password != confirmation:
            return apology("must provide matching passwords", 400)

        # Check database for username
        usercheck = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        # Ensure username exists
        if len(usercheck) != 0:
            return apology("username already exists", 400)

        # Generate hash for password
        hash = generate_password_hash(password)

        # Insert username and password to db (variables) and then (placeholders ?x2) and (arguments)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        # Go to login page
        return redirect("/login")
    # User reached route via GET and needs to register for site
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # return apology("TODO")
    # Provide current portfolio stock symbols to sell form
    symbols = db.execute("SELECT symbol FROM portfolio")

    # User reached route via POST - sell stock
    if request.method == "POST":
        # Capture valid symbol and shares on submission
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide a symbol", 400)
        symbol = symbol.upper()
        shares = request.form.get("shares")
        if not shares:
            return apology("must provide number of shares", 400)
        try:
            shares = int(shares)
        except ValueError:
            return apology("must provide number of shares", 400)
        if shares < 1:
            return apology("must provide positive amount of shares", 400)

        # look up current stock info
        quote = lookup(symbol)

        # calculate total stock prices
        price = quote['price']
        total_cost = price * shares
        # Check database for current total shares of stock to sell
        portfolio_row = db.execute(
            "SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)
        total_shares_owned = portfolio_row[0]["shares"]

        # Execute
        if total_shares_owned >= shares:
            try:
                db.execute("BEGIN TRANSACTION")
                transaction_type = "SELL"

                # add funds to user cash on successful sell
                db.execute("UPDATE users SET cash = cash + ? WHERE id = ?",
                           total_cost, session["user_id"])

                # SELL stock and insert details into transactions db (variables) and then (placeholders ?x2) and (arguments)
                db.execute("INSERT INTO transactions (symbol, shares, price, total_cost, transaction_type, user_id) VALUES(?, ?, ?, ?, ?, ?)",
                           symbol, -shares, price, total_cost, transaction_type, session["user_id"])

                # SUBTRACT stock and shares details from portfolio db (variables) and then (placeholders ?x2) and (arguments)
                total_shares_remaining = total_shares_owned - shares
                if total_shares_remaining == 0:
                    # Action Sells all stock and delete from portfolio db
                    db.execute("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?",
                               session["user_id"], symbol)
                else:
                    # Stock in portfolio update shares
                    db.execute("UPDATE portfolio SET shares = ? WHERE user_id = ? AND symbol = ?",
                               total_shares_remaining, session["user_id"], symbol)

                # Commit Transaction
                db.execute("COMMIT")
            except Exception as e:
                print(f"Error: {e}")
                db.execute("ROLLBACK")
                return apology("Transaction failed.", 400)
        else:
            return apology("Not enough shares in your account.", 400)

        # Redirect to homepage after successful sell
        return redirect(url_for("index", success="Your sell transaction was successful"))
        # return render_template("sell.html", symbols=symbols)
    # User reached route via GET - display stock sell form
    else:
        return render_template("sell.html", symbols=symbols)


@app.route("/funds", methods=["GET", "POST"])
@login_required
def addfunds():
    """Add funds to cash account"""
    # return apology("TODO")
    # Capture and update USER cash balance
    user_row = db.execute("SELECT cash, username FROM users WHERE id = ?", session["user_id"])
    cash = user_row[0]["cash"]
    name = user_row[0]["username"]

    # User reached route via POST -
    if request.method == "POST":
        # Ensure valid cash amount submitted
        funds_to_add = request.form.get("funds")
        if not funds_to_add:
            return apology("must provide valid funds amount", 400)
        try:
            funds_to_add = int(funds_to_add)
        except ValueError:
            return apology("must provide amount of funds to be added", 400)
        if funds_to_add < 20 or funds_to_add > 500:
            return apology("must provide positive amount of funds to add", 400)

        # Calculate total amount of funds to add
        total_funds_amount = funds_to_add + cash

        print(f"Cash is: {cash} plus {total_funds_amount}")
        try:
            db.execute("BEGIN TRANSACTION")
            db.execute("UPDATE users SET cash = ? WHERE id = ?",
                       total_funds_amount, session["user_id"])
            # Commit transaction
            db.execute("COMMIT")
        except:
            db.execute("ROLLBACK")
            return apology("Transaction failed.", 400)

        return redirect(url_for("buy", success=f"You successfully added ${funds_to_add} to your account"))
    # User reached route via GET -
    else:
        return render_template("funds.html", cash=cash, name=name)
