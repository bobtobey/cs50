#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // error check for a minimum of 2 words typed
    if (argc == 1 || argc > 2)
    {
        // no command-line argument or more than 1 provided
        printf("There is an error with your key, message nummber: %i\n", argc);
        return 1;
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
    }
}
