# Creates a dictionary of pizza toppings
pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "veggetable": 11,
    "black olive": 12
}
# Loop through keys
for pie in pizzas:
    print(pie)
# Loop through keys and values by temporarily transforming the dictionary to a list
for pie, price in pizzas.items():
    print(price)
# Loop through keys and values
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
