from cs50 import get_float

# CASH revisited:
# define a prompt function
def get_flt(prompt):
    while True:
        # test for a non-numeric answer
        try:
            change_due = get_float(prompt)
            # test for positive integer
            if 0 < change_due < 1:
                return change_due
            else:
                print("Please enter a positive integer between 1 and 99.")
        except ValueError:
            pass

# defining main function
def main():
    # prompt user for their change back
    n = get_flt("Change: ")
    print(f"You entered: {n}")

# Execute the main program
main()
