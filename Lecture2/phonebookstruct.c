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
