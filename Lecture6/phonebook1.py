# Phonebook app revisited
names = ["Carter", "David", "John"]

name = input("Name: ")

for n in names:
    if name == n:
        print("found")
        break
else:
    print("Not Found")
