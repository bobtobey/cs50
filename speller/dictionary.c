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
    // set the index using the hash function
    unsigned int index_ck = hash(word);

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }


        // insert the new node into the hash table.
        table[index];

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function by checking 2 letters
    int first_letter = 0;
    int second_letter = 0;
    // validate character is a letter
    if (isalpha(word[0]))
    {
        printf("%i\n", word[0]);
        first_letter = toupper(word[0]) - 'A';
    }
    if (word[1] != '\0' && isalpha(word[1]))
    {
        printf("%i\n", word[1]);
        second_letter = toupper(word[1]) - 'A';
    }
    // combine letters 1 & 2
    unsigned int hash_2ltr_value = (first_letter * 26) + second_letter;
    printf("%i\n", hash_2ltr_value);
    // make sure value fits in table size
    return hash_2ltr_value % N;
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
        printf("%s\n", word);

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
    size();
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    printf("%i\n", word_count);
    return word_count;
    // return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
