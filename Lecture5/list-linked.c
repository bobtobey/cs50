#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    node *list = null;
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}
