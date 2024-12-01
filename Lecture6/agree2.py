s = input("Do you agree? ")

# reset all inputs to lowercase to handle diff use cases
s = s.lower();

# string comparison test with multiple conditions using an array LIST
if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not Agreed")
