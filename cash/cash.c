#include <cs50.h>
#include <stdio.h>

int divide_it(change);

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
    // FIRST divide change_due by the highest coin value available
    divide_it(change_due);
    // SECOND no remainder = done
    // otherwise take the modulus and * it by first coin value, then divide it by the next highest coin value
    // repeat
    // Final Step print result
    printf("%i",)
}

// Divide function
int divide_it(change)
{
    // divide change by coin value
    return change / 1;
}
