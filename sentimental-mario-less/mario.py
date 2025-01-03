# Mario revisited:
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

    # iterate over each row
    for i in range(n):
        # print spaces
        for j in range(n - i - 1):
            print(" ", end="")
        # prints brick on each line
        for k in range(i + 1):
            print("#", end="")
        # print new line
        print()


# Execute the main program
main()
