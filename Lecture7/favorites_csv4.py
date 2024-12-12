import csv

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
    # Initialize counter variables
    # male = 0
    # female = 0
    # Cleaner way to initialize multiple variables
    male, female = 0, 0

    for row in reader:
        # set a variable to the row
        f = row["Sex"]
        # increment counters if found in loop
        if f == "Male":
            male += 1
        elif f == "Female":
            female += 1

print(f"Male: {male}")
print(f"Female: {female}")
