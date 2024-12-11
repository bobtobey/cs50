import csv

# 'with' keyword automatically closes the file outside the 'with' block
with open("people-100.csv", "r") as file:
    # reader library comes with Python
    reader = csv.reader(file)
    # next() allows us to skip the header row of a csv file
    next(reader)
    for row in reader:
        # this will print out the 2nd row
        print(row[1])
