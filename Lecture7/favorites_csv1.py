import csv

file = open("people-100.csv", "r")
    # reader library comes with Python
    reader = csv.reader(file)
    # next() allows us to skip the header row of a csv file
    next(reader)
close(file)
