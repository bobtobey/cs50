#include <cs50.h>
#include <stdio.h>

int calculate_change(int change);

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
    while (change_due < 1 );

    // find minimum # of coins to give back as change
    // Call calculate_change function
    int coins_back = calculate_change(change_due);
    // Final Step print result
    printf("%i\n", coins_back);
}

// Subtract function
int calculate_change(int change)
{
    int remaining_change;
    // calculate # of quarters (highest coin value) to give back and subtract it from the change
    int quarters = (change / 25);
    remaining_change = change - (quarters * 25);
    // calculate # of dimes (next highest coin value) to return and subtract from remaining change
    int dimes = remaining_change / 10;
    remaining_change = remaining_change - (dimes * 10);
    // calculate # of nickels (next highest coin value) to return and subtract from remaining change
    int nickels = remaining_change / 5;
    remaining_change = remaining_change - (nickels * 5);
    // calculate # of pennies (next highest coin value) to return and subtract from remaining change
    int pennies = remaining_change / 1;
    remaining_change = remaining_change - (pennies * 1);

    // find the sum total of all the coins needed
    int total_coin_number = quarters + dimes + nickels + pennies;

    // return the total # of coins
    return total_coin_number;
}
