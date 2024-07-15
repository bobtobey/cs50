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
    if(player1score < player2score)
    {
        printf("Player 1 wins!");
    }
    else if(player1score > player2score)
    {
         printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }

    // Print out the winners name
    printf("\n%i wins!", player1score);
    printf("\n%i wins!", player2score);
}

// Score words function
int score_words(string word)
{
    // Score words
    int word_score = 5;
    // return score
    return word_score;
}
