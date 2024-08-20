#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David", "John"};
    // In general, the rule of thumb in programming is even if in English we call something a number,
    // if you wouldn't do math on it ever, you should probably be storing it as a string, not as an integer.
    string numbers[] = {"+1-555-555-5556", "+1-555-555-5557","+1-555-555-5558"};

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
