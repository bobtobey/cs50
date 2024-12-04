from sys import argv

# how to test for a command line argument and exit with code
if len(argv) > 2:
    print(f"Hello, {argv[1]}.")
else:
    print("Hello, world.")
