#include <stdio.h>
#include <stdlib.h>

// create data type
typedef struct node
{
    // store numbers
    int number;
    // points to the next node
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    // declare a linked list called list and initialize it to null
    node *list = NULL;

    // build the list by getting #'s from the command line
    for (int i = 1; i < argc; i++)
    {
        // atoi - convert string to int
        int number = atoi(argv[i]);
        printf("%i\n", number);
        // creates temp. pointer 'n' and get and assign memory the size of one node
        node *n = malloc(sizeof(node));
        // check if we have a valid address n equals NULL
        if (n == NULL)
        {
            // free memory
            return 1;
        }
        // go to next number and set it = n
        // go into n. I can follow that pointer to the number field and set it equal to the actual number
        // n is pointing to a chunk of memory
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
        ptr = ptr->next;
    }
}
