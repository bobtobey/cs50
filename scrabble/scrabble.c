#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt players for their scrabble word
    string player1 = get_string("Player 1 input your word: ");
    string player2 = get_string("Player 2 input your word: ");
    // score players word

    // Print out players words
    printf("Player 1 %s\n", player1);
    printf("Player 2 %s\n", player2);
    // compare scores and determine the winner
    
    // Print out the winners name
    printf("wins!");
}
