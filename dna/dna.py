import csv
import sys


def main():

    # TODO: Check for command-line usage
    # use databases/small.csv sequences/1.txt
    if len(sys.argv) != 3:
        print("Missing command-line argument.")
        # used to exit a program with an exit/error code #
        sys.exit(1)
    else:
        print(f"Your {sys.argv[1]} and {sys.argv[2]}")

    # TODO: Read database file into a variable
    db_file = sys.argv[1]
    rows = []
    with open(db_file) as file:
        reader = csv.DictReader(file)
        print(reader.fieldnames)
        for row in reader:
            rows.append(row)
            print(row)
            # break

    # TODO: Read DNA sequence file into a variable
    dna_file = sys.argv[2]
    dna_rows = []
    with open(dna_file) as file:
        reader = csv.DictReader(file)
        # print(reader.fieldnames)
        for dna_row in reader:
            dna_rows.append(dna_row)
            print(dna_row)

    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles

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
