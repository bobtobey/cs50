import csv

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
    counts = {}

    for row in reader:
        f = row["Sex"]
        if f in counts:
            counts[f] += 1
        else:
            counts[f] = 1

for f in counts:
    print(f"{f}: {counts[f]}")
