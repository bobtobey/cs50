import csv

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
    # Initialize counter variables
    # scratch = 0
    # c = 0
    # python = 0
    # Cleaner way to initialize multiple variables
    scratch, c, python = 0, 0, 0

    for row in reader:
        favor
