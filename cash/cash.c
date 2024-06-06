#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change_due;
    do
    {
        change_due = get_int("Change due, please: ");
    }
    while(change_due < 1);
}
