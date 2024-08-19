#include <cs50.h>
#include <stdio.h>

//  Linear Search example
int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n = get_int("Number: ");
    for(int i = 0; i < 7; i++)
    {
        if (numbers[i] == 50)
        {
            printf("Found\n");
            // end 'main' function with 0 if n is found
            return 0;
        }
    }
    // conclude 'not found' after loop finishes
    printf("Not Found\n");
    return false;
}
