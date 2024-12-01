s = input("Do you agree? ")

s = s.lower();

# string comparison test with multiple conditions using an array LIST
if s in ["Y","y", "yes"]:
    print("Agreed")
elif s in ["N", "n", "no"]:
    print("Not Agreed")
