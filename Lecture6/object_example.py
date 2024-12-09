class student():
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))

# Create a student object
student1 = student("Alice", 101)

# Print student details
student1.print()
# Create a student object
student2 = student("Bob", 102)

# Print the original details
student2.print()

# Change the student ID
student2.changeID(202)

# Print the updated details
student2.print()

# Create multiple student objects
students = [
    student("Charlie", 103),
    student("Diana", 104),
    student("Eve", 105)
]

# Print details of all students
for s in students:
    s.print()
# Create a list of students
students = [
    student("Frank", 106),
    student("Grace", 107)
]

# Change the ID of the second student
students[1].changeID(207)

# Print details of all students
for s in students:
    s.print()

# Get student details from the user
name = input("Enter the student's name: ")
id = int(input("Enter the student's ID: "))

# Create a student object
new_student = student(name, id)

# Print the student's details
new_student.print()
