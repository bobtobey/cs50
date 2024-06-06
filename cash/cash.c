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
    int coins_back = subtract_it(change_due);
    // Final Step print result
    printf("%i\n", coins_back);
}

// Subtract function
int subtract_it(int change)
{
    int remaining_change;
    // calculate the # of quarters (highest coin value) to give back and subtract it from the change amount
    int quarters = (change / 25);
    remaining_change = change - (quarters * 25);
    printf("remaining Q %i\n", remaining_change);
    // calculate the # of dimes (next highest coin value) to give back and subtract it from the remaining change amount
    int dimes = remaining_change / 10;
    remaining_change = remaining_change - (dimes * 10);
    printf("remaining D %i\n", remaining_change);
    // calculate the # of nickels (next highest coin value) to give back and subtract it from the change amount
    int nickels = 0;
    // calculate the # of pennies (next highest coin value) to give back and subtract it from the change amount
    int pennies = 0;
    // find the sum total of all the coins needed
    int total_coin_number = quarters + dimes + nickels + pennies;
    // return the total # of coins
    return total_coin_number;
}
