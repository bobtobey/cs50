#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);

}

int string_length(string s)
{
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
    return n;
}
