# define a prompt function
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass

def main():
    n = get_int("height: ")
    print(n)

for i in range(n):
    print("#")
