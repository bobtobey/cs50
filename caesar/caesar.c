#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialize functions
int check_fordecimals(string argvalue);
string encrypt_text(int key, string plaintext);
int conversion_index(int key, int index);

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
        // convert argument to int
        int key = atoi(argv[1]);

        printf("Plaintext: ");
        // prompt user for plain text to encrypt
        string plaintext = get_string(" ");
        // encrypt plain text
        string ciphertext = encrypt_text(key, plaintext);
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
            // printf("Digit entered.\n");
        }
        else
        {
            // Add 1 if something other than digits are present in the argument
            // printf("EyeSpy: %c\n", argvalue[i]);
            get_digit_value++;
        }
    }
    return get_digit_value;
}

// Encrypt text with cipher key rotation
string encrypt_text(int key, string plaintext)
{
    // Get text length
    int textlength = strlen(plaintext);

    printf("Use key: %i to encrypt text: %s\n", key, plaintext);

    // Create a new array of characters to hold the encrypted plaintext
    char ciphertext[textlength + 1];

    // Loop through plaintext and apply caesar key
    for (int j = 0; j < textlength; j++)
    {
        if (isalpha(plaintext[j]) && isupper(plaintext[j]))
        {
            // add the cipher key value to each plaintext character
            ciphertext[j] = (plaintext[j] + key);
            printf("Mod %c : %i\n", ((plaintext[j] - 65) + key) % 26, ((plaintext[j] - 65) + key) % 26);
            printf("Modi %c : %i\n", conversion_index(key, plaintext[j]), conversion_index(key, plaintext[j]));
            printf("Plain= %c : %i to Cipher= %c : %i\n", plaintext[j], plaintext[j], ciphertext[j], ciphertext[j]);
        }
        else if (isalpha(plaintext[j]) && islower(plaintext[j]))
        {
            // add the cipher key value to each plaintext character
            ciphertext[j] = (plaintext[j] + key);
            printf("Plain= %c : %i to Cipher= %c : %i\n", plaintext[j], plaintext[j], ciphertext[j], ciphertext[j]);
        }
        else
        {
            // for non-alpha characters do nothing
            ciphertext[j] = plaintext[j];
            printf("Plain= %c : %i to Cipher= %c : %i\n", plaintext[j], plaintext[j], ciphertext[j], ciphertext[j]);
        }
    }
    ciphertext[textlength] = '\0';
    printf("Plain: %s\n", plaintext);
    printf("Cipher: %s\n", ciphertext);
    int x = (25 + 3) % 26;
    printf("Test: %i\n", x);

    string ciphertext2 = ciphertext;
    return ciphertext2;
}

// Conversion Formula to alphabetical index
int conversion_index(int key, int index)
{
    // conversion formula c[i]=(p[i] + k) % 26
    int x = ((index - 65) + key) % 26;
    // reverse conversion
    x = x + 65;
    return x;
}
