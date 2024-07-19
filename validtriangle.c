#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
int valid_triangle(double a, double b, double c);

ing main(void)
{
    // Call Triangle function
    int istriangle = valid_triangle(2, 2, 2);
    // Print result
    printf("Is it a triangle: %b", istriangle);
}

int valid_triangle(double a, double b, double c)
{
    // return result
    return true;
}
