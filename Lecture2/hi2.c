#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    string t = "BYE!";

    printf("%s\n", s);
    printf("%s\n", t);

    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    // this line prints out beyond hi to show the nul value of 0 and the first letter in bye 'B'
    printf("%i %i %i %i %i\n", words[0][0], words[0][1], words[0][2], words[0][3], words[0][4]);
}
