import csv

# import Counter method
from collections import Counter

with open("people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
    # creates an object with counting capabilities built in
    counts = Counter()

    # grab the favorite sex from that row
    for row in reader:
        # index into that counter using favorite and increment by 1
        favorite = row["Sex"]
        counts[favorite] += 1

# Sort by values
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")
