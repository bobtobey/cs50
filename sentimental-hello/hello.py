# Creating a Hello program

# define a prompt function
def get_string(prompt):

    while True:
        name = input(prompt)
        if len(name) > 0:
            return name
        else:
            print("Please enter a name with at least 1 character.")

def main():
    # prompt user for name
    name = get_string("What is your name? ")
    print(f"hello, {name}")

# Execute the main program
main()
