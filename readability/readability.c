#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
double get_letter_avg(string text);
double get_sentence_avg(string text);
double get_grade_index(double L, double S);

// Globabl grade level variable
int gradelevel = 0;

int main(void)
{
    // Prompt for reading level text sample to review
    string textsample = get_string("Text: ");

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
    for (int i = 0; i < textlength; i++)
    {
        if (isalpha(text[i]))
        {
            // Get # of letters in the text by counting alphabet characters
            num_letters++;
            printf("%c\n", text[i]);
        }
        else if (isblank(text[i]))
        {
            // get # of words in the text by counting space between words
            num_words++;
            printf("BLANK\n");
        }
        else if (ispunct(text[i]) && text[i] == '.')
        {
            // Get # of sentences in the text
            num_sentences++;
            printf("Punct\n");
        }
        else
        {
            // if there is any other unaccounted for element do nothing
            printf("NO GO\n");
        }
    }
    printf("Letter count: %f\n", (float)num_letters);
    printf("Word count: %f\n", (float)num_words+1);
    printf("Sentence count: %f\n", (float)num_sentences);

    // calculate average # of letters per 100 words
    double l_letter_average = ((double)num_letters / (double)(num_words + 1)) * 100;
    printf("aver %f\n", letter_average);

    // calculate average # of sentences per 100 words
    double s_sentence_average = ((double)num_sentences / (double)(num_words + 1)) * 100;

    // Get the Coleman-Liau index
    double cl_index = get_grade_index(l_letter_average, s_sentence_average);

    // return Letter Average
    return letter_average;
}

// Calculate the Coleman-Liau index
double get_grade_index(double L, double S)
{
    // Formula Calculations- Coleman-Liau: index = 0.0588 * L - 0.296 * S - 15.8
    gradelevel = 0.0588 * L - 0.296 * S - 15.8;
    printf("Index: %f\n", gradelevel);

    // return grade level index
    return gradelevel;
}

// Get Average # of sentences in text sample
double get_sentence_avg(string text)
{
    // calculate average # of sentences per 100 words
    int sentence_average = 10;

    // return Sentence Average
    return sentence_average;
}
