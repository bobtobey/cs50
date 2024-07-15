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
    string scrabble_score1 = "AEILNORSTU";
    string scrabble_score2 = "DG";
    string scrabble_score3 = "BCMP";
    string scrabble_score4 = "FHVWY";
    string scrabble_score5 = "K";
    string scrabble_score8 = "JX";
    string scrabble_score10 = "QZ";
    printf("%c test\n", toupper(word[0]));

    // Loop through arrays
    for (int i = 0; i < word_length; i++)
    {
        int j = 0;
        while (j < 9)
        {
            if(toupper(word[i]) == ;
        }
        printf("%c", scrabble_score1[i]);
        //printf("%c\n", toupper(word[i]));
    }
    printf("\n");

    // Score words
    int word_score = word_length;
    // return score
    return word_score;
}
