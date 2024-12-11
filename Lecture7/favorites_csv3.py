import csv

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    # and this now creates a dictionary 
    reader = csv.DictReader(file)
    for row in reader:
        # this will print out the 2nd row
        print(row["Email"])
