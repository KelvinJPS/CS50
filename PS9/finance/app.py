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
    user_stocks = db.execute("SELECT stock, shares FROM portfolio WHERE user_id = ? ", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    grand_total = cash
      #Get current price and total 
    for user_stock in user_stocks:
        user_stock["price"] = lookup(user_stock["symbol"])["price"]
        user_stock["total"] = user_stock["price"] * user_stock["shares"]
        user_stock["name"] = lookup(user_stock["symbol"])["name"]
        grand_total += user_stock["total"]
    return render_template("index.html",user_stocks=user_stocks,cash=cash,grand_total=grand_total) 

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
    symbol_portfolio = db.execute("SELECT symbol FROM portfolio WHERE userid = ?",session["user_id"])
    # Make new record 
    if not symbol_portfolio:
        db.execute("INSERT INTO portfolio (userid,symbol,shares)",session["user_id"], symbol, shares )
    # Update
    db.execute(purchase_query,session["user_id"],symbol,shares,stock_price,datetime.utcnow())
    db.execute("UPDATE users SET cash = ? ", user["cash"] - (stock_price  * shares) )
    db.execute("UPDATE portfolio SET shares += ?",shares )
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

    if not request.form.get("symbol"):
        return apology("missing symbol")

    stock = request.form.get("symbol")
    quote = lookup(stock)
    if not lookup(stock):
        return apology("invalid symbol")


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

    if request.method == "GET":
        user_stocks = db.execute("SELECT symbol FROM purchases WHERE userid = ?", session["user_id"])
        return render_template("sell.html")
    #Input validation
    if not request.form.get("symbol"):
        apology("symbol required")

    if not request.form.get("shares"):
        apology("number of shares required")

    # assign variables
    shares = 0
    symbol = request.form.get("symbol")
    price = lookup(symbol)["price"]
    date = datetime.utcnow()
    try:
        shares = int(request.form.get("shares"))
    except ValueError:
        return apology("shares is not a number")
    # Validate sell
    rows = db.execute("SELECT symbol FROM purchases WHERE userid = ? AND shares !=0  GROUP BY symbol", session["user_id"], symbol)
    if not rows:
        return apology("user does not posses shares for that symbol")
    sell_query = """INSERT INTO sells (userid, symbol, shares, price, date) 
    VALUES (?,?,?,?,?)"""
    db.execute(sell_query,session["user_id"],symbol,shares,price,date)
    return apology("TODO")
