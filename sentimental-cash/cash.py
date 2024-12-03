from cs50 import get_float
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

# defining main function
def main():
    # prompt user for height of bricks
    n = get_int("Height: ")
    # print(f"You entered: {n}")
