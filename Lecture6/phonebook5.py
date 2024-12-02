# Implements a phone book using a dictionary
from cs50 import get_string

# converts this from a list of dictionaries to just one big dictionary
# but it is more restrictive to just one key/value pair in this case
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

# and it is simpler to Search for name
name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
