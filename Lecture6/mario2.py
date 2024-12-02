# define a prompt function
def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))
            if n > 0:
                return n
            else:
                print("Please enter a positive integer")
        except ValueError:
            pass

def main():
    n = get_int("height: ")

    for i in range(n):
        print("#")

main()
