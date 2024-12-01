# example for setting the number decimal places to show in python
x = int(input("x: "))
y = int(input("y: "))

# use f string to configure the variable to print out to a specific number of digits
# to print out 50 decimal points use a dot after a colon and specify the number of digits then an f to make clear it's a float.
z = x / y
print(f"{z:.50f}")
