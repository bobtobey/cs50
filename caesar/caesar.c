#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // error check for a minimum of 2 words typed
    if (argc < 2)
    {
        printf("You did not input enough words: %i\n", argc);
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
    }
}
