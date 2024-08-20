#include <cs50.h>
#include <stdio.h>
#include <string.h>

// create data type person and this creates the structure for it
typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    // This now creates 1 array of type person called people
    person people[3];

    // Initialize people - set a person's name and number-- like, how can we access those values
    person people[0].name = "Carter";
    person people[0].number = "+1-555-555-5556";
    person people[1].name = "David";
    person people[1].number = "+1-555-555-5557";
    person people[2].name = "John";
    person people[2].number = "+1-555-555-5558";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
