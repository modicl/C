#include <cs50.h>
#include <ctype.h>
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
}
candidate;

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
    // We search if the name of the vote is in the candidate list
    for (int i = 0; i < candidate_count ; i++)
    {
        if ( strcasecmp(name, candidates[i].name) == 0 )
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // We sort the list with a selection sort in descending order
    int swap = 0;
    for (int i = 0 ; i < candidate_count; i++)
    {
        int min = candidates[i].votes;
        for (int j = i+1 ; j < candidate_count; j++)
        {
            if (candidates[j].votes > min)
            {
                swap = min;
                string swaptexti = candidates[i].name;
                string swaptextj = candidates[j].name;
                min = candidates[j].votes;
                candidates[i].votes = min;
                candidates[j].votes = swap;
                candidates[i].name = swaptextj;
                candidates[j].name = swaptexti;
            }

        }
    }
    // We look for max votes and the owner of the max votes
    // We initialize the max with 0 because negative votes don't exist!
    int max_votes = 0;
    int max_votes_two[candidate_count-1];
    string max_candidate[candidate_count];
    // We found the first max
    for (int i= 0; i < candidate_count ; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
            max_candidate[i] = candidates[i].name;
            max_votes_two[i] = candidates[i].votes;
        }
    }
    // We look for same max's
    // Since the list is sorted we can do it easily, we start from 1 since index 0 is already the maximum.
    for (int i = 1 ; i <  candidate_count ; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            max_candidate[i] = candidates[i].name;
            max_votes_two[i] = candidates[i].votes;
        }
    }

    // When there is only one maximum
    // We check if the maximum is not equal to the next number to him in de descender sorted list of votes
    if(max_votes_two[0] != candidates[1].votes)
    {
        printf("%s\n",max_candidate[0]);
    }
    else
    {
        // When there are more maximums
        for (int i = 0 ; i < candidate_count ; i++)
        {
            // If the maximum vote in the list is equal to the maximum votes ever detected
            if (max_votes_two[i] == max_votes)
            {
                printf("%s\n", max_candidate[i]);
            }
        }
    }
    return;
}