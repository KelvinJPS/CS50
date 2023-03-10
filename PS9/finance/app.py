import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

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

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


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
    purchases = db.execute("SELECT * FROM purchases WHERE userid = ?", session["user_id"])
    user_stocks = {}
    # Populate user_stocks
    for purchase in purchases:
        symbol = purchase["symbol"]
        shares = purchase["shares"]
        if symbol in user_stocks: 
            user_stocks[symbol] += shares 
        else:
            user_stocks[symbol] = shares

    # cash = db.execute("SELECT cash FROM  users WHERE id = ?", session["user_id"])
    print(user_stocks)

    return apology("TODO")



@app.route("/buy", methods=["POST","GET"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        return render_template("buy.html")

    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    #Input validation
    if not symbol:
        return apology("stock's symbol required")

    if not lookup(symbol):
        return apology("stock doesn't exists")

    try :
        if int(shares) < 0:
            return apology("shares is not a positive number")
    except ValueError:
        return apology("shares is not a number")

    # validate purchase
    stock_price = lookup(symbol)["price"]
    user = db.execute("SELECT * FROM users WHERE id = ?",session["user_id"])[0]
    if stock_price > user["cash"]:
        return apology("insufficient funds")

    #purchase     
    shares = int(shares)
    purchase_query = """INSERT INTO purchases (userid, symbol, shares, price, date) 
    VALUES (?,?,?,?,?)"""
    db.execute(purchase_query,session["user_id"],symbol,shares,stock_price,datetime.utcnow())
    db.execute("UPDATE users SET cash = ? ", user["cash"] - (stock_price  * shares) )
    return redirect("/")

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
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
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
    #Get user input 
    if request.method == "GET":
        return render_template("quote.html")


    stock = request.form.get("symbol")
    quote = lookup(stock)
    return render_template("quoted.html",quote=quote)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "GET":
        return render_template("register.html")

    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")
    user_found = db.execute("SELECT username FROM users WHERE username = ? ", username )
    
    if not username:
        return apology("username required")

    if user_found:
        return apology("username already exists")

    if not password:
            return apology("password required")

    if confirmation != password:
        return apology("passwords don't match")

    password_hash = generate_password_hash(password)
    db.execute("INSERT INTO users (username, hash) VALUES (?,?)", 
              username, password_hash) 
    return redirect("/")

     



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
