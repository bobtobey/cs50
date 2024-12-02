# Mario revisited:
# define a prompt function
def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))
            if n > 0:
                return n
            else:
                print("Please enter a positive integer")
        except ValueError:
            pass

# defining main function
def main():
    # prompt user for height bricks
    n = get_int("Height: ")
    print(f"You entered: {n}")
    
    # print bricks
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

    # for i in range(n):
    #     print("#")

# Execute the main program
main()
