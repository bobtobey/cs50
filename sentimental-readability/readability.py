from cs50 import get_float

# Re-imagining Readability in Python
# define a prompt function
def get_string(prompt):

    while True:
        text = input(prompt)
        if len(text) > 0:
            return text
        else:
            print("Please enter a name with at least 1 character.")


def calc_grade_index(text_value):
    # initialize variables to 0
    num_letters = 0
    num_words = 0
    num_sentences = 0

    # count letters
    for letters in text_value:
        if letters.isalpha():
            num_letters += 1
    # count words
    num_words_list = text_value.split()
    num_words = len(num_words_list)
    # count sentences
    for sentence in text_value:
        if sentence == '.' or sentence == '!' or sentence == '?':
            num_sentences += 1
    # calculate averages
    letter_average = (num_letters / num_words) * 100
    sentence_average = (num_sentences / num_words) * 100
    # implement Coleman-Liau index
    # Formula Calculation: index = 0.0588 * L - 0.296 * S - 15.8
    calc_index = (0.0588 * letter_average) - 0.296 * sentence_average - 15.8
    calc_index_rounded = round(calc_index)
    # print(f"# of letters {num_letters} |# of words {num_words} |# of sentences {num_sentences}")
    return calc_index_rounded


def main():
    # prompt user for name
    text_value = get_string("Text: ")
    # calculate grade index #
    grade_index = calc_grade_index(text_value)

    # determine text grade level
    if grade_index < 1:
        print(f"Before Grade 1")
    elif grade_index >= 16:
        print(f"Grade 16+")
    else:
        print(f"Grade {grade_index}")


# Execute the main program
main()
