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

# What is new in this version I'm now using one dictionary instead of two variables to keep track of 2 things
# And once I have that dictionary, whether there's 2 sexes, or, maybe, tomorrow there'll be 4 - this will iterate over all of those keys and print out the values
