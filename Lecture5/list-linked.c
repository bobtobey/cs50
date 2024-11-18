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
        n->number = number;
    }
}
