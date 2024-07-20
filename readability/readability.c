#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
double get_grade_index(string text);
double calc_grade_index(double L, double S);

int main(void)
{
    // Prompt for reading level text sample to review
    string textsample = get_string("Text: ");

    // Find formula factors to plug into the equation
    // Get the grade level index for text sample
    double gradelevel = get_grade_index(textsample);

    if (gradelevel < 1)
    {
        // Print out the grade level index value for the text provided
        printf("Grade %.0f\n", gradelevel);
    }

    // Print out the grade level index value for the text provided
    printf("Grade %.0f\n", gradelevel);
}

// Get Average # of letters, words, and sentences in text sample to return grade index
double get_grade_index(string text)
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
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
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
    double letter_average = ((double)num_letters / (double)(num_words + 1)) * 100;

    // calculate average # of sentences per 100 words
    double sentence_average = ((double)num_sentences / (double)(num_words + 1)) * 100;
    printf("Average L/S: %f and %f\n", letter_average , sentence_average);

    // Get the Coleman-Liau index
    double cl_grade_index = calc_grade_index(letter_average, sentence_average);

    // return Letter Average
    return cl_grade_index;
}

// Calculate the Coleman-Liau index
double calc_grade_index(double L, double S)
{
    // Formula Calculations- Coleman-Liau: index = 0.0588 * L - 0.296 * S - 15.8
    double gradeindex = (0.0588 * L) - 0.296 * S - 15.8;
    printf("Index: %f\n", gradeindex);

    // return grade level index
    return gradeindex;
}
