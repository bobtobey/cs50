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
    # initialize variables to 0
    num_letters = 0
    num_words = 0
    num_sentences = 0
    text_length = len(input)

    # count letters
    for x in input:
        if x.isalpha():
            num_letters += 1
    # count words
    num_words_list = input.split()
    num_words = len(num_words_list)
    # count sentences
    for sentence in input:
        if sentence == '.' or sentence == '!' or sentence == '?':
            num_sentences += 1
    # calculate averages
    letter_average = num_letters / 
    print(f"Grade X {text_length}")
    print(f"# letters {num_letters}")
    print(f"# words {num_words}")
    print(f"# sentences {num_sentences}")


# Execute the main program
main()
