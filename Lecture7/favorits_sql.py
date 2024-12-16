from cs50 import SQL

# Load database to a variable
db = SQL("sqlite:///favorites.db")

# Create a terminal input
favorite = input("Favorite: ")

# execute an SQL query that will create a temporary table that we store in a variable
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
# Get the first row in our temp table
row = rows[0]

print(row["n"])
