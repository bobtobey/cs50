#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declareing the variable
    int blockheight;
    do
    {
        //assigning the variable
        blockheight = get_int("How tall is your pyramid? ");
    }
    //checking the variable for a positive integer
    while(blockheight < 1);

    const int n = blockheight;
    for(int i=0; i < n; i++)
    {
        printf("%d ", i);
        for(int j=0; j < n-1; j++)
        {
            int blockwidth = 8;
            string blocks = "#";
            //printf("%d", j);
            printf("%s ", blocks);
        }
        printf("\n");
    }
}
