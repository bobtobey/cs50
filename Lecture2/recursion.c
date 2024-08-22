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
    // base case - if there is nothing to draw stop
    if (n <= 0)
    {
        return;
    }
    // Print pyramid of height n - 1
    draw(n - 1);

    // first loop provides the height n times/layers
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    // start new layer
    printf("\n");
}
