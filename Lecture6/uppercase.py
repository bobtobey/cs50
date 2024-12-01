# this function changes the input to all uppercase
before = input("Before: ")
# adding the 'end=""' parameter is defaulted to end="\n"
print("After: ", end="\n")
for c in before:
    # adding the 'end=""' paramenter allows you to determine
    print(c.upper(), end="")
#
print()
