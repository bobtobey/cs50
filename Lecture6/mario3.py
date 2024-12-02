# Mario revisited: print out a single row of bricks
for i in range(3):
    # use named parameter end="" to create row
    print("#", end="")
    # Alternative way to acheive same result
    # * means multiply the string by itself 4x
    print("#" * 4)

# create new line
print()
