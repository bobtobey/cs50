#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// initialize functions
int check_fordecimals(string argvalue);

int main(int argc, string argv[])
{
    // error check for a minimum of 2 words typed
    if (argc == 1 || argc > 2)
    {
        // 0 or more than 1 command-line argument provided
        printf("There is an error with your key, message nummber: %i\n", argc);
        return 1;
    }
    else if (isdigit(8))
    {
        // if any character in the command-line argument is not a decimal digit
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
        printf("digit: %c\n", isdigit("p"));
    }
}

// Check for non decimal values in the argument
int check_fordecimals(string argvalue)
{
    return 3;
}
