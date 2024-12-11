import csv

with open("people-100.csv", "r") as file:
    # reader library comes with Python
    reader = DictReader(file)
    for row in reader:
        # this will print out the 2nd row
        print(row[2])
