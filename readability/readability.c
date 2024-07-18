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
    // Get 
    printf("Grade %i\n", gradelevel);
}
