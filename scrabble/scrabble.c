#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize Score words function
int score_words(string word);

int main(void)
{
    // Prompt players for their scrabble word
    string player1word = get_string("Player 1: ");
    string player2word = get_string("Player 2: ");

    // score players word
    int player1score = score_words(player1word);
    int player2score = score_words(player2word);

    // compare scores and determine the winner
    if (player1score > player2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1score < player2score)
    {
         printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    // Print out the scores
    // printf("Player 1 scores %i!\n", player1score);
    // printf("Player 2 scores %i!\n", player2score);
}

// Score words function
int score_words(string word)
{
    // Track Score
    int word_score = 0;

    // get word length
    int word_length = strlen(word);

    // array of letter score values
    int letter_values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Loop through arrays
    for (int i = 0; i < word_length; i++)
    {
        // convert all character to uppercase
        char letter = toupper(word[i]);
        // verify letters is alphabetical and find the index of each letter
        if (isalpha(letter))
        {
            int index_value = letter - 'A';
            // get score value and add them together
            word_score += letter_values[index_value];
        }
        // Prints out the letter and number
        // printf("%c", letter);
        // printf("%i", letter);
    }
    printf("\n");

    // Return word score
    // printf("Word Score for %s: %i\n", word, word_score);
    // return word score
    return word_score;
}
