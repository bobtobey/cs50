# CASH revisited:
# define a prompt function
def get_int(prompt):
    while True:
        # test for a non-numeric answer
        try:
            n = int(input(prompt))
            # test for positive integer
            if 0 < n <= 8:
                return n
            else:
                print("Please enter a positive integer between 1 and 8.")
        except ValueError:
            pass
