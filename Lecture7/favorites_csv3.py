import csv

with open("people-100.csv", "r") as file:
    # DictReader library comes with Python
    reader = csv.DictReader(file)
    for row in reader:
        # this will print out the 2nd row
        print(row["Email"])
