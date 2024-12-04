from sys import argv

# how to test for a command line argument and use it for expression
if len(argv) > 2:
    print(f"Hello, {argv[1]}.")
else:
    print("Hello, world.")
