#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

2    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
Tom        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    printf("VOTE Name value: %s\n", name);

    // Validate for parameter 'name', check for name value and return it.
    // Iterate over candidates Struct to validate for name
    for (int i = 0; i < candidate_count; i++)
    {
        // Look for candicate name and return true if found.
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Found %s\n", candidates[i].name);
            candidates[i].votes = 1;
            printf("Found Count %i\n", i);
            return true;
        }
        else
        {
            printf("Lost %s\n", candidates[i].name);
            printf("Lost Count %i\n", i);
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Iterate over the candidate Struct for the total votes per name
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Votes %i\n", candidates[i].votes);
        printf("Votes %s\n", candidates[i].name);
    }
    printf("Print Winner Test!\n");
    return;
}
