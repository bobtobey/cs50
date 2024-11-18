#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        // convert string to #
        int number = atoi(argv[i]);
        printf("%i\n", number);
        // creates pointer 'n' and get and assign memory
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // free memory
            return 1;
        }
        // go to next number and set it = n
        // go into n. I can follow that pointer to the number field and set it equal to the actual number
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }
    // Print whole list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
    }
}
