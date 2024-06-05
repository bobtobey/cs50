#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int n = get_int("What Size? ");

    for(int j=0; j < n; j++)
    {
        printf("Hello ");
    }
    printf("\n");
}
