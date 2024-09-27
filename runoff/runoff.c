#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Iterate over candidates Struct to validate for name
    for (int i = 0; i < candidate_count; i++)
    {
        // Look for candicate name and return true if found.
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            printf("Voter %i : ranks %s as choice %i\n", voter, name, rank);
            // Add 1 Vote to candidate found
            // candidates[i].votes += 1;
            // Set voter rank preference
            preferences[voter][i] = rank;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop through preferences array
    for (int i = 0; i < voter_count; i++)
    {
        printf("Tabulate voter %i : Prefers candidate %i first.\n", i, preferences[i][0]);
        // Add up votes for non-eliminated candidates
        candidates[preferences[i][0]].votes += 1;
        printf("Add candidate %s votes up for a total of %i\n", candidates[0].name, candidates[0].votes);
    }
    printf("Voter 0 - candidate Choices: %i first, %i second, %i third.\n", preferences[0][0], preferences[0][1], preferences[0][2]);
    printf("Voter 1 - candidate Choices: %i first, %i second, %i third.\n", preferences[1][0], preferences[1][1], preferences[1][2]);
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Base case - if there is only one candidate
    if (candidate_count == 1)
    {
        printf("There is only one candidate!\n The winner is %s\n", candidates[0].name);
    };
    // number needed for victory
    float victoryNum = voter_count/2.0;
    // Loop through candidate vote count
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes >= victoryNum) {
            printf("Winning count is %i?\n", candidates[i].votes);
            printf("%s\n", candidates[i].name);
            printf("Total votes %f\n", victoryNum);
            return true;
        }
    }
    return true;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
            printf("Min Votes\n");
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
            printf("Tie\n");
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
            printf("Eliminated\n");
    return;
}