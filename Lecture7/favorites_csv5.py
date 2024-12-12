people-100.csv", "r") as file:
    # DictReader analyzes the header row of the file and figures out the columns
    reader = csv.DictReader(file)
