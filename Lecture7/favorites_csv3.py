import csv

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
    # this iterates ober reader to create a dictionary
    for row in reader:
        # this now looks to the header of this column for what to print out
        # making this less fragile
        print(row["Email"])
