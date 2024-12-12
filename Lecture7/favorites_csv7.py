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
        favorite = row["Job Title"]
        counts[favorite] += 1

# Alternate way to Sort utilizing the Counter method
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
