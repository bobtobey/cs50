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
    // Final Step print result
    printf("%i\n", coins_back);
}

// Divide function
int divide_it(int change)
{
    // divide change by the highest coin value available
    float y = (float) change / 25;
    // SECOND no remainder = done
    // otherwise take the modulus and * it by first coin value, then divide it by the next highest coin value
    int z = change % 25;
    if(z != 0){
        printf("modulus is %i\n", z);
    }
    // repeat

    // divide change by coin value .01
    int x = change / 1;


    //printf("%i\n", z);
    printf("%.2f\n", y);
    return y;
}
