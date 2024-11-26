#include <stdio.h>
#include <stdlib.h>

// create data type
typedef struct node
{
    // store numbers
    int number;
    // points to the next node
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // declare a linked list called list and initialize it to null
    node *list = NULL;

    // build the list by getting #'s from the command line
    for (int i = 1; i < argc; i++)
    {
        // atoi - convert string to int
        int number = atoi(argv[i]);

        // print number as we add to the list
        printf("%i\n", number);

        // allocate node for number
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
        // n is pointing to a chunk of memory, n arrow number means go to that chunk of memory and update that number
        n->number = number;
        // n arrow next should be at this point initialized to null
        n->next = NULL;

        // current node (arrow, next) and set that = to list first. (strictly speaking I don't need to initialize it to null. I can initialize the next field of this new node to point at the existing list.)
        // this insert a new node in front of any nodes that already exist (saying set the node's next field equal to whatever the list currently is)
        n->next = list;
        // then update the list to n (prepends list)
        list = n;
    }
    // Print whole list
    printf("Print whole list.\n");
    // specify a pointer to a node with the star and initialize to the list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}
