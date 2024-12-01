# example of how to handle exceptions
def get_int(prompt):
    # loop until you get a response that does not error out
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer.")


def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)

main()
