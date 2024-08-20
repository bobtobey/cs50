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
    people[0].name = "Carter";
    people[0].number = "+1-555-555-5556";
    people[1].name = "David";
    people[1].number = "+1-555-555-5557";
    people[2].name = "John";
    people[2].number = "+1-555-555-5558";

    // capture users name
    string name = get_string("Name: ");
    // iterate over every persons name
    for (int i = 0; i < 3; i++)
    {
        // find the users name in the array
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
