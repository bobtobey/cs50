#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

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
    // Validate for parameter 'name', check for name value and return true
    // Iterate over candidates Struct to validate for name
    for (int i = 0; i < candidate_count; i++)
    {
        // Look for candicate name and return true if found.
        if (strcasecmp(candidates[i].name, name) == 0) {
            printf("Looking for: %s and Found: %s at i value: %i\n", name, candidates[i].name, i);
            // Add 1 Vote to candidate found
            candidates[i].votes += 1;
            return true;
        }
        else
        {
            // Do nothing
            printf("Lost %s i at value %i\n", candidates[i].name, i);
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Base case - if there is only one candidate
    if (candidate_count == 1) {
        printf("There is only one candidate!\n The winner is %s\n", candidates[0].name);
    };

    int total_votes = 0;
    int currenthighvote = 0;
    // Iterate over the candidate Struct for the total votes per name
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("%i votes for %s\n", candidates[i].votes, candidates[i].name);
        total_votes += candidates[i].votes;
        if (candidates[i].votes > currenthighvote)
        {
            currenthighvote = candidates[i].votes;
            // printf("Current high vote = %s\n", candidates[i].name);
        }
    }

    for (int j = 0; j < candidate_count; j++) {
        if (candidates[j].votes == 0) {
            // Skip over candidates with 0 votes
            // printf("SKIPPED %s\n", candidates[j].name);
            printf("%s\n", candidates[j].name);
        }
        else if (candidates[j].votes == total_votes)
        {
            // Declare and return winner if candidate has max votes
            // printf("Total Winner is %s!\n", candidates[j].name);
            printf("%s\n", candidates[j].name);
            return;
        }
        else if (candidates[j].votes == currenthighvote)
        {
            // printf("Winner with %i votes %s!\n", candidates[j].votes, candidates[j].name);
            printf("%s\n", candidates[j].name);
        }
        else
        {
            // Catch all
            printf("Other %s!\n", candidates[j].name);
        }
    }
    printf("Total Votes: %i\n", total_votes);
    printf("Print Winner Test!\n");
    return;
}
