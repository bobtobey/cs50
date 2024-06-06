#include <cs50.h>
#include <stdio.h>

int divide_it(int change);

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
    int coins_back = divide_it(change_due);
    // SECOND no remainder = done
    // otherwise take the modulus and * it by first coin value, then divide it by the next highest coin value
    // repeat
    // Final Step print result
    printf("%i\n", coins_back);
}

// Divide function
int divide_it(int change)
{
    // divide change by the highest coin value available
    if((change % 25) = 0)
    {
        int z = change / 25;
    }
    else {
        float z = (float) change % 25;
    }
    // divide change by coin value .01
    int x = change / 1;
    // divide change by coin value .25
    float y = (float) change / 25;

    printf("%f\n", z);
    return z;
}
