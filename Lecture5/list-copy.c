#include <stdio.h>
#include <stdlib.h>

// copying everything from the old array to the new array
int main(void)
{
    // re-declare list to be a pointer to address of a chunk of memory - of three integers
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        // abort
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // temporary pointer to address of memory size 4
    int *tmp = malloc(4 * sizeof(int));
    if (list == NULL)
    {
        // free memory and then abort
        free(list);
        return 1;
    }

    // copy list array to temp memory
    for (int h = 0; h < 3; h++)
    {
        tmp[h] = list[h];
    }
    // assign 4 to temp array
    tmp[3] = 4;

    // free list memory/empty
    free(list);

    // Update list to point to the new chuck of memory
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}
