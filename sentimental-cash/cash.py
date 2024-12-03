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

def calculate_change(n):
    print("Calculate change for: ", + n)
    return n

# defining main function
def main():
    # prompt user for their change back
    n = get_flt("Change: ")
    # find min # of change to return
    coins_back = calculate_change(n);
    print(f"Amount back: {coins_back:.2f}")

# Execute the main program
main()
