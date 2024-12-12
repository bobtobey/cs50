import csv

from collections inport Counter

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

# Sort by values
for f in sorted(counts, key=counts.get, reverse=True):
    print(f"{f}: {counts[f]}")
