#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[2]);
    printf("Array of words count: %i\n", argc);

    // If you do not know the length of the argv array
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
