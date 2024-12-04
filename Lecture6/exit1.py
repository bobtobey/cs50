import sys
# how to test for a command line argument and exit with code
if len(sys.argv) != 2:
    print("Missing command-line argument.")
    # used to exit a program with an exit/error code #
    sys.exit(1)

print(f"Hello, {sys.argv[1]}")
sys.exit(0)
