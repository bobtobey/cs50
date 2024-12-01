s = input("Do you agree? ")

s = s.lower();

# string comparison test with multiple conditions using an array LIST
if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not Agreed")
