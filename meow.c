#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int n = get_int("What Size? ");
    int i = 0;
    while(i < n)
    {
        printf("Hello ");
        i++;
    }
    printf("\n");
}
