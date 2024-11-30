// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// word counter
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open files and determine scaling factor
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char word[LENGTH + 1];

    // Read words from the file
    while (fscanf(input, "%s", word) != EOF)
    {
        // TODO: Insert the word into your data structure
        // printf("File opened successfully.\n");
        // printf("%s\n", word);

        // storing the address of the node memory in 'n'
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Close the dictionary file
            fclose(input);
            return 1;
        }
        strcpy(n->word, word);
        n->next = NULL;
        // set the index using the hash function
        unsigned int index = hash(word);
        // insert the new node into the hash table.
        n->next = table[index];
        // update table to point to new node
        table[index] = n;

        // increment word counter
        word_count++;
    }
    // Close the dictionary file
    fclose(input);

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    printf("%int)
    return word_count;
    // return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
