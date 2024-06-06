#include <cs50.h>
#include <stdio.h>

int subtract_it(int change);

int main(void)
{
    // declare change variable
    int change_due;
    do
    {
        // assign the change variable
        change_due = get_int("Change due, please: ");
    }
    // validate the change variable
    while(change_due < 1);

    // find minimum # of coins to give back as change
    // FIRST divide change_due by coin values
    int subtract_it = divide_it(change_due);
    // Final Step print result
    printf("%i\n", coins_back);
}

// Subtract function
int subtract_it(int change)
{
    
    return p;
}
