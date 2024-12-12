import csv

from collections import Counter

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        f = row["Sex"]
        counts[f] += 1

# Sort by values
for f in sorted(counts, key=counts.get, reverse=True):
    print(f"{f}: {counts[f]}")
