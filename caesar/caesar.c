#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // error check for a minimum of 2 words typed
    if (argc == 1 || argc > 2)
    {
        // 0 or more than 1 command-line argument provided
        printf("There is an error with your key, message nummber: %i\n", argc);
        return 1;
    }
    else if (argv[1])
    {
        // if any character in the command-line argument is not a decimal digit
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
    }
}
