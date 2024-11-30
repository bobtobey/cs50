answer = get_string("What is your name? ")
# this version concatenates with the normal + symbol to join the strings
print("hello," + answer)
# this version lets python provide the space needed between strings itself and uses a ',' comma to apply multiple 
print("hello,", answer)
# this version uses a format string by prefixes 'f' at the start and using { braces } inside
print(f"hello, {answer}")
