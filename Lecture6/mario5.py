# set height of pyramid
n = 5;

# iterate over each row
for i in range(n):
    # print spaces
    for j in range(n - i - 1):
        print(" ", end="")
    # print brick
    for k in range(i + 1):
        print("#", end="")
    print()
