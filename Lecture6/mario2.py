# define a prompt function
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass
