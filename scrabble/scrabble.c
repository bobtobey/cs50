#include <ctype.h>
#include <cs50.h>
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
    if(player1score > player2score)
    {
        printf("Player 1 wins!\n");
    }
    else if(player1score < player2score)
    {
         printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    // Print out the scores
    printf("Player 1 scores %i!\n", player1score);
    printf("Player 2 scores %i!\n", player2score);
}

// Score words function
int score_words(string word)
{
    // get word length
    int word_length = strlen(word);
    // array of letters with score of 1
    string scrabble_score1[];
    scrabble_score1[0] = A;
    scrabble_score1[1] = E;
    scrabble_score1[2] = I;
    scrabble_score1[3] = O;
    scrabble_score1[4] = U;

    // Loop through arrays
    
    // Score words
    int word_score = word_length;
    // return score
    return word_score;
}
