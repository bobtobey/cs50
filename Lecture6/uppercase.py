# this function changes the input to all uppercase
before = input("Before: ")
# Python does the backslash n \n for you
# To change this default behavior, you pass in a second argument called end and set it equal to something else
print("After: ", end="\n")
for c in before:
    # adding the 'end=""' paramenter allows you to determine
    print(c.upper(), end="")
# When you don't pass print() an argument, it automatically gives you a new line
print()
