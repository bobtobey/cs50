#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n = get_int("Number: ");
    for(int i = 0; i < numbers; i++)
    {
        if (numbers[i] == 50)
        {
            printf("TRUE\n");
            return 0;
        }
    }
    return false;
}
