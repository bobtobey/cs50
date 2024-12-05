import csv
import sys


def main():

    # TODO: Check for command-line usage
    # use databases/small.csv sequences/1.txt
    # make sure program takes just 2 arguments
    if len(sys.argv) != 3:
        print("Missing command-line argument.")
        # used to exit a program with an exit/error code #
        sys.exit(1)

    # TODO: Read database file into a variable
    # assigns command line arg. to variable
    db_file = sys.argv[1]
    # creates an empty list
    rows = []
    with open(db_file) as file:
        reader = csv.DictReader(file)
        # create list of str dna sequence sans first name element
        strs = reader.fieldnames[1:]
        # print(strs)
        for row in reader:
            rows.append(row)
            # print(row)

    # TODO: Read DNA sequence file into a variable
    dna_file = sys.argv[2]
    with open(dna_file) as file:
        dna_sequence = file.read()
        # print(dna_sequence)

    # TODO: Find longest match of each STR in DNA sequence
    store_matches = []
    for str in strs:
        dna_match = longest_match(dna_sequence, str)
        store_matches.append(dna_match)
        # print(f"Match: {dna_match} and {store_matches}")

    # TODO: Check database for matching profiles
    match_found = False

    for person in rows:
        match = True
        for str in strs:
            # print("Person: ", person['name'], ":", person[str])
            # print("Seqence: ", store_matches[strs.index(str)])

            if int(person[str]) != store_matches[strs.index(str)]:
                match = False
                break

        if match:
            print(f"Match found: {person['name']}")
            match_found = True
            break

    if not match_found:
        print(f"No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
