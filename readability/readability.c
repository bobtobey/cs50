#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Globabl grade level variable
int gradelevel = 0;

int main(void)
{
    // Prompt for reading level text sample to review
    string textsample = get_string("Text: ");
    printf("Text Sample: %s\n", textsample);
    // Find formula factors to get the equation Coleman-Liau: index = 0.0588 * L - 0.296 * S - 15.8
    // get the average number of letters per 100 words
    
    // get the average number of sentences per 100 words

    // Print out the grade level index value for the text provided
    printf("Grade %i\n", gradelevel);
}
