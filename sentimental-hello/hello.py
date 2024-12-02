# Creating a Hello program

# define a prompt function
def get_string(prompt):

    name = input(prompt)
    return name
    # while True:
    #     try:
    #         name = input(prompt)
    #         if name > 0:
    #             return name
    #         else:
    #             print("Please enter a positive integer")
    #     except ValueError:
    #         pass

def main():
    # prompt user for name
    name = get_string("What is your name? ")
    print(f"hello, {name}")

# Execute the main program
    main()
