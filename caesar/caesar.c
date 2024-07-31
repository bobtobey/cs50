#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// initialize functions
int check_fordecimals(string argvalue);
string encrypt_text(string key, string plaintext);

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
        printf("Argument Key: %s\n", argv[1]);
        printf("Plaintext: ");
        // prompt user for plain text to encrypt
        string plaintext = get_string(" ");
        // encrypt plain text
        string ciphertext = encrypt_text(argv[1], plaintext);
        printf("Ciphertext: %s\n", ciphertext);
    }
}

// Check for non decimal values in the argument
int check_fordecimals(string argvalue)
{
    int get_digit_value = 0;
    for (int i = 0; i < strlen(argvalue); i++)
    {
        // checks for digits in the arguement
        if (isdigit(argvalue[i]))
        {
            // Check for digits in argument and do nothing
            printf("Digit entered.\n");
        }
        else
        {
            // Add 1 if something other than digits are present in the argument
            printf("EyeSpy: %c\n", argvalue[i]);
            get_digit_value++;
        }
    }
    printf("D Value: %i\n", get_digit_value);
    return get_digit_value;
}

// Encrypt text with cipher key
string encrypt_text(string key, string plaintext)
{
    // Apply cipher to plain text
    string ciphertext = plaintext;
    printf("Use key: %s to encrypt text: %s\n", key, ciphertext);
    printf("CHAR me %c, %i\n", ciphertext[2], ciphertext[2]);
    int sum = 0;
    // Loop through plaintext and apply caesar key
    for (int j = 0; j < strlen(plaintext); j++)
    {
        // string x[] = (plaintext[j] + 1);
        sum = plaintext[j] +1;
        printf("x = %c and %i\n", sum, sum);
        printf("E Char me %c, %i\n", plaintext[j], plaintext[j]);
    }
    printf("my X %c\n", sum);
    return ciphertext;
}
