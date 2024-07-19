#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
int valid_triangle(double a, double b, double c);

int main(void)
{
    // Call Triangle function
    bool istriangle = valid_triangle(-2, 2, 3);
    // Print result
    printf("Is it a triangle: %i\n", istriangle);
}

// determine if the 3 lengths form a triangle
int valid_triangle(double a, double b, double c)
{
    // the sum of the lengths of any 2 sides of a triangle must be greater than the length of the third side
    int triange_calc = a + b > c;
    // return result
    return triange_calc;
}
