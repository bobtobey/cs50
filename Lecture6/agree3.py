# reset all inputs to uppercase to handle diff use cases
# and this chains the string method to end of the variable declaration
s = input("Do you agree? ").upper();

# string comparison test with multiple conditions using an array LIST
if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not Agreed")
