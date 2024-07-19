#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
int get_letter_avg(string text);
int get_sentence_avg(string text);

// Globabl grade level variable
int gradelevel = 0;

int main(void)
{
    // Prompt for reading level text sample to review
    string textsample = get_string("Text: ");
    printf("Text Sample: %s\n", textsample);



    // Find formula factors to get the equation
    // get the average number of letters per 100 words
    int L = get_letter_avg(textsample);
    // get the average number of sentences per 100 words
    int S = get_sentence_avg(textsample);
    // Formula Calculations- Coleman-Liau: index = 0.0588 * L - 0.296 * S - 15.8
    gradelevel = 0.0588 * L - 0.296 * S - 15.8;

    // Print out the grade level index value for the text provided
    printf("Average L/S: %i and %i\n", L , S);
    printf("Grade %i\n", gradelevel);
}

// Get Average # of letters in text sample
int get_letter_avg(string text)
{
    // find numbe of words in the text sample
    int num_letters = 0;
    int num_words = 0;
    int num_sentences = 0;

    int textlength = strlen(text);
    //for(int i = 0; text[i] != '\0'; i++)
    for(int i = 0; i < textlength; i++)
    {
        if(isblank(text[i]))
        {
            // get # of words in the text
            num_words++;
            printf("BLANK\n");
        }
        else if(isalpha(text[i]))
        {
            // Get # of letters in the text
            num_letters++;
            printf("%i : %c\n", i+1, text[i]);
        }
        else
        {
            // Get # of sentences in the text
            num_sentences++;
            printf("NO GO\n");
        }
    }
    printf("Letter count: %i\n", num_letters);
    printf("Word count: %i\n", num_words+1);
    printf("Sentence count: %i\n", num_sentences);

    // calculate average
    int letter_average = 500;

    // return Letter Average
    return letter_average;
}

// Get Average # of sentences in text sample
int get_sentence_avg(string text)
{
    // calculate average
    int sentence_average = 10;

    // return Sentence Average
    return sentence_average;
}
