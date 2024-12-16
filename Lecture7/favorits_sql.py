from cs50 import SQL

# Load database to a variable
db = SQL("sqlite:///favorites.db")

# Create a terminal input
favorite = input("Favorite: ")

# execute an SQL query that will create an 
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
row = rows[0]
