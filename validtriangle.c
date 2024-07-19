#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
int valid_triangle(double a, double b, double c);

int main(void)
{
    // Call Triangle function
    bool istriangle = valid_triangle(2, 2, 2);
    // Print result
    printf("Is it a triangle: %i\n", istriangle);
}

int valid_triangle(double a, double b, double c)
{
    int triange_calc = a + b > c;
    // return result
    return triange_calc;
}
