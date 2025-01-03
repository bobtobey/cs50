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
    # convert change to cents -avoid flt division
    change_to_cents = round(change * 100)
    # use integer division //
    quarters = (change_to_cents // 25)
    # capture remainder with modulo
    remaining_change = change_to_cents % 25
    dimes = remaining_change // 10
    remaining_change = remaining_change % 10
    nickels = remaining_change // 5
    remaining_change = remaining_change % 5
    pennies = remaining_change // 1
    remaining_change = remaining_change % 1

    # find sum total of all the coins needed
    # print("Quarters:", quarters, "Dimes:", dimes, "Nickels:", nickels, "Pennies: ", pennies)
    total_coin_number = quarters + dimes + nickels + pennies
    return total_coin_number

# defining main function


def main():
    # prompt user for their change back
    n = get_flt("Change: ")
    # find min # of change to return
    coins_back = calculate_change(n)
    print(coins_back)


# Execute the main program
main()
