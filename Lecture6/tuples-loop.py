# Creates a list of tuples
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]
# Create a for loop
for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))
