#include <cs50.h>
#include <stdio.h>

//  Linear Search example
// a correct implementation of linear search that goes from left to right, looking for a value that may or may not be there
int main(void)
{
    // This declares an array of values when I know in advance what the values are
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n = get_int("Number: ");

    for(int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            // end 'main' function with 0 if n is found
            // when you return a value, it immediately exits that function
            return 0;
        }
    }
    // conclude 'not found' after loop finishes
    printf("Not Found\n");
    // even though this does not functionally change the program it is good practice
    return 1;
}
