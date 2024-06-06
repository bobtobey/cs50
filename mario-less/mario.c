#include <cs50.h>
#include <stdio.h>

void buildrow(int blockcount, string blockmaterial);

int main(void)
{
    // declareing the variable
    int blockheight;
    do
    {
        // assigning the variable for the pyramid height
        blockheight = get_int("How tall is your pyramid? ");
    }
    // checking the variable for a positive integer
    while (blockheight < 1);

    // first loop creates the n of rows in the pyramid
    for (int i = 0; i < blockheight; i++)
    {
        // Print row #
        // printf("%i", i);

        // build each row with correct amount of spaces and blocks
        int k = blockheight - 1;
        buildrow(k - i, " ");
        buildrow(i + 1, "#");
        printf("\n");
    }
}

// build row function
void buildrow(int blockcount, string blockmaterial)
{
    // second loop creates the n of blocks and spaces in each row
    for (int j = 0; j < blockcount; j++)
    {
        printf("%s", blockmaterial);
    }
}
