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
    // while (true)
    // {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            printf("winner\n");
            // break;
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
            // break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    // }
    // return 0;
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
            // Set voter rank preference for candidate i
            preferences[voter][rank] = i;
            printf("Voter %i : ranks %s (%i) as choice %i\n", voter, name, preferences[voter][rank], rank);
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
        printf("voter %i\n", i);
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated != true)
            {
                printf("candidate name %s has %i votes\n", candidates[preferences[i][j]].name, candidates[preferences[i][j]].votes);
                // Add up votes for non-eliminated candidates
                candidates[preferences[i][0]].votes += 1;
                printf("Tabulate voter %i : Ranks candidate %s with %i votes\n", i, candidates[preferences[i][j]].name, candidates[preferences[i][0]].votes);
            }
        }
    }
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
    for (int i = 0; i < candidate_count; i++)
    {
        printf("Talley candidate %s votes up for a total of %i\n", candidates[i].name, candidates[i].votes);
        // if (candidates[i].votes > victoryNum)
        // {
        //     printf("Total votes = %i and half amount to win %f | Candidate votes num: %i\n", voter_count, victoryNum, candidates[i].votes);
        //     printf("Winning vote count is %i?\n", candidates[i].votes);
        //     printf("x %i %s\n", i, candidates[i].name);
        //     return true;
        // }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int lowestVoteCount = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == 0)
        {
            lowestVoteCount = 0;
            printf("low Vote Count %s %i\n", candidates[i].name, lowestVoteCount);
            return true;
        }
        else if (lowestVoteCount < candidates[i].votes)
        {
            printf("MIN less %s\n", candidates[i].name);
            lowestVoteCount = candidates[i].votes;
        }
        else
        {
            printf("else:? %s \n", candidates[i].name);
        }
        printf("Min Votes %s has %i\n", candidates[i].name, candidates[i].votes);
    }
    return true;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    printf("min = %i\n", min);
    // Loop through candidates list
    for (int i = 0; i < candidate_count; i++)
    {
        // If every candidate had equal votes return Tie is true
        if (min == candidates[i].votes)
        {
            printf("Tie Me %s at %i\n", candidates[i].name, candidates[i].votes);
        }
        else
        {
            printf("False\n");
            return false;
        }
    }
    // return false;
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    printf("Elim min = %i\n", min);
    // Loop through candidates list
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes)
        {
            // elminate me
            printf("Eliminated: %s\n", candidates[i].name);
            printf("Really Eliminated: %i\n", candidates[i].eliminated);
            candidates[i].eliminated = true;
            printf("Oh Yes Eliminated: %i\n", candidates[i].eliminated);
        }
    }
    return;
}
