#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
double get_letter_avg(string text);
double get_sentence_avg(string text);

// Globabl grade level variable
int gradelevel = 0;

int main(void)
{
    // Prompt for reading level text sample to review
    string textsample = get_string("Text: ");
    printf("Text Sample: %s\n", textsample);

    // Find formula factors to plug into the equation
    // get the average number of letters per 100 words
    double L = get_letter_avg(textsample);
    // get the average number of sentences per 100 words
    double S = get_sentence_avg(textsample);

    // Formula Calculations- Coleman-Liau: index = 0.0588 * L - 0.296 * S - 15.8
    gradelevel = 0.0588 * L - 0.296 * S - 15.8;

    // Print out the grade level index value for the text provided
    printf("Average L/S: %f and %f\n", L , S);
    printf("Grade %i\n", gradelevel);
}

// Get Average # of letters, words, and sentences in text sample
double get_letter_avg(string text)
{
    // initialize variables
    int num_letters = 0;
    int num_words = 0;
    int num_sentences = 0;

    // find length of text
    int textlength = strlen(text);
    for(int i = 0; i < textlength; i++)
    {
        if(isblank(text[i]))
        {
            // get # of words in the text by counting space between words
            num_words++;
            printf("BLANK\n");
        }
        else if(isalpha(text[i]))
        {
            // Get # of letters in the text by counting alphabet characters
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
    printf("Letter count: %f\n", (float)num_letters);
    printf("Word count: %f\n", (float)num_words+1);
    printf("Sentence count: %f\n", (float)num_sentences);

    // calculate average # of letters per 100 words
    double letter_average = ((double)num_letters /(double)(num_words + 1)) * 100;
    printf("aver %f\n", letter_average);

    // return Letter Average
    return letter_average;
}

// Get Average # of sentences in text sample
double get_sentence_avg(string text)
{
    // calculate average # of sentences per 100 words
    int sentence_average = 10;

    // return Sentence Average
    return sentence_average;
}
