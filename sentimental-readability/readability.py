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
    input = get_string("Text: ")
    # initialize variables
    num_letters = 0
    num_words = 0
    num_sentences = 0
    text_length = len(input)
    print(f"Grade X {text_length}")


# Execute the main program
main()
