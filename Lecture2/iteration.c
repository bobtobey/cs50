#include <cs50.h>
#include <stdio.h>
#include <string.h>
// similar to mario.c pyramid problem

// initialize functions
void draw(int n);

int main(void)
{
    // get user input for height
    int height = get_int("Height is: ");
    // then print the pyramid
    draw(height);
}

void draw(int n)
{
    // first loop provides the height n times/layers
    for (int i = 0; i < n; i++)
    {
        // second loop prints out n number of bricks per layer plus 1
        for (int j = 0; j < n + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
