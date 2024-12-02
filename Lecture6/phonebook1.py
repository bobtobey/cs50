# Phonebook app revisited search for a name in a list
names = ["Carter", "David", "John"]

name = input("Name: ")

for n in names:
    if name == n:
        print("found")
        break
else:
    print("Not Found")
