
#include <stdio.h>

// copying everything from the old array to the new array
int main(void)
{
    // re-declare list to be a pointer to address of a chunk of memory - of three integers
    int list = malloc(3 * sizeof(int));

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
