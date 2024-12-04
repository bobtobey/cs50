# Re-imagining Readability in Python

# define a prompt function
def get_string(prompt):

    while True:
        text = input(prompt)
        if len(text) > 0:
            return text
        else:
            print("Please enter a name with at least 1 character.")


def main():
    # prompt user for name
    text = get_string("Text: ")
    print(f"Text: {text}")


# Execute the main program
main()
