from cs50 import get_float

# CASH revisited:
# define a prompt function
def get_flt(prompt):
    while True:
        # test for a non-numeric answer
        try:
            change_due = get_float(prompt)
            # test for positive integer
            if change_due > 0:
                return change_due
            else:
                print("Please enter a positive dollar amount between .01 and 100")
        except ValueError:
            pass

def calculate_change(change):
    change_in_cents = round(change * 100)
    print("Calculate change for: ", + change)
    quarters = (change / .25);
    remaining_change = change - (quarters * .25);
    dimes = remaining_change / .10;
    remaining_change = remaining_change - (dimes * .10);
    nickels = remaining_change / 0.05;
    remaining_change = remaining_change - (nickels * 0.05);
    pennies = remaining_change / 0.01;
    remaining_change = remaining_change - (pennies * 0.01);

    # find sum total of all the coins needed
    total_coin_number = quarters + dimes + nickels + pennies;
    return total_coin_number

# defining main function
def main():
    # prompt user for their change back
    n = get_flt("Change: ")
    # find min # of change to return
    coins_back = calculate_change(n);
    print(f"Amount back: {coins_back}")

# Execute the main program
main()
