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

    //for(int i = 0; textsample[i] != '\0'; i++)
    for(int i = 0; i < strlen(textsample); i++)
    {
        if(isblank(textsample[i]))
        {
            printf("BLANK\n");
        } else
        {
            printf("%i : %c\n", i+1, textsample[i]);
        }
    }

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
    int num_letters = 10;
    int num_words = 5;
    int num_sentences = 1;

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
