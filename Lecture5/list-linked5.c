// Implements a sorted list of numbers using a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            // there is no list yet, we can prepend or append to update list
            list = n;
        }

        // If number belongs at beginning of list
        // If the new node's number is less than the list's number then it belongs at the beginning of the list because it's smaller than any of the numbers already there.
        else if (n->number < list->number)
        {
            // update new node's next field to point at the current linked list.
            n->next = list;
            // then update the linked list variable to equal the address of this new node
            list = n;
            // The effect is no matter how long the existing list is if this new node's number is smaller than everything else in the list, I splice it in at the beginning.
        }

        // If number belongs later in list
        else
        {
            // Iterate over nodes in list with a temporary variable called ptr that's initialized to the beginning of the list
            // comparing the value, the integer inside of this new node, against what is currently in the list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node to end of list without going past it
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
