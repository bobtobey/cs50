// Implements a list of numbers using a linked list

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
            // This node is the whole list
            // there is no list yet, we can prepend or append to update list
            list = n;
        }

        // If list has numbers or one node already
        else
        {
            // Iterate over nodes in list with a temporary variable called ptr that's initialized to the beginning of the list
            // On every iteration update pointer variable to point to the next node, pointing one node ahead.
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                // On each iteration sure the pointer variable is not null.
                // Because if it is null, that means I'm pointing past the end of the list or, that is, the list has ended.
                if (ptr->next == NULL)
                {
                    // Append node to end
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
