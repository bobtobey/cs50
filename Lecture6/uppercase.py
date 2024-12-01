# this function changes the input to all uppercase
before = input("Before: ")
print("After: ", end="")
for c in before:
    # adding the 'end=""' paramenter allows you to determine
    print(c.upper(), end="")
# 
print()
