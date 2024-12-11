import csv

file = open("people-100.csv", "r")
# reader library comes with Python
reader = csv.reader(file)
# next() allows us to skip the header row of a csv file
next(reader)
# Loop through file
for row in reader:
    # this will print out the 2nd row
    print(row[2])

file.close()
