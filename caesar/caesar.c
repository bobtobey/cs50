#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // error check for a minimum of 2 words typed
    if (argc == 1 || argc > 2)
    {
        printf("Error  words: %i\n", argc);
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
    }
}
