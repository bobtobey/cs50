#include <cs50.h>
#include <stdio.h>

void buildrow(int i);

int main(void)
{
    //declareing the variable
    int blockheight;
    do
    {
        //assigning the variable for the pyramid height
        blockheight = get_int("How tall is your pyramid? ");
    }
    //checking the variable for a positive integer
    while(blockheight < 1);

    //first loop creates the n of rows in the pyramid
    for(int i=0; i < blockheight; i++)
    {
        //Print row #
        printf("%d ", i);
        //build each row
        buildrow(i);
    }
}

//build row function
void buildrow(int i)
{
    //assigns the variable for # of blocks
    int blockwidth = i;
    //second loop creates the n of blocks in each row
    for(int j=0; j < blockwidth; j++)
    {
        string blocks = "#";
        //printf("%d", j);
        printf("%s ", blocks);
    }
    printf("\n");
}
