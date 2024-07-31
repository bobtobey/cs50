#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// initialize functions
int check_fordecimals(string argvalue);

int main(int argc, string argv[])
{
    // error check for a single, a non-negative integer command-line arguement typed
    if (argc == 1 || argc > 2)
    {
        // 0 or more than 1 command-line argument provided
        printf("There is an error with your key, message nummber: %i\n", argc);
        return 1;
    }
    else if (check_fordecimals(argv[1]))
    {
        // if any character in the command-line argument is not a decimal digit
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        printf("Plaintext: %s\n", argv[1]);
        printf("Ciphertext: %s\n", argv[1]);
    }
}

// Check for non decimal values in the argument
int check_fordecimals(string argvalue)
{
    int get_digit_value = 0;
    for (int i = 0; i < strlen(argvalue); i++)
    {
        if (isdigit(argvalue[i]))
        {
            printf("YO\n");
        }
        else
        {
            printf("eye: %c\n", argvalue[i]);
            get_digit_value++;
        }
    }
    printf("D Value: %i\n", get_digit_value);
    return get_digit_value;
}
