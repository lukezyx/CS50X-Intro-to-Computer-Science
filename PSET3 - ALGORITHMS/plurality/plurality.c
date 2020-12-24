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
    // look for candidate called name
    // if candidate found, update their vote total and return true
    // does this candidate match bob? if it does, then ++. return true.

    for (int i = 0; i < candidate_count; i++)
    {
        //printf("%i\n", i);
        //printf("iterationVote %i: %s\n", i, candidates[0].name);
        //printf("iterationVote %i: %s\n", i, candidates[1].name);
        //printf("iterationVote %i: %s\n\n", i, candidates[2].name);

        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            //printf("candidate is %s, Votes: %i\n", candidates[i].name, candidates[i].votes);
            return true;
        }

    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    string winner[candidate_count]; //create array to map candidates with progressively higher scores
    int votesMax = 0; //creating a comparator for highest num of votes

    //First for and if loop is to map the candidates (with progressively highest scores) to an array with equal length.
    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes >= votesMax) //If the candidate has a higher or same score than the previous candidate, map it to the array
        {
            winner[k] = candidates[k].name;
            votesMax = candidates[k].votes;

            //Because the array is filled with candidates with progressively higher scores
            //if you print out the array, you're going to print out a bunch of names which does not have the HIGHEST scores
            //as such this next for loop is to set the array positions to NULL if that candidate doesn't have an equally highest vote.
            for (int l = 0 ; l < candidate_count; l++)
            {
                if (candidates[l].votes != votesMax)
                {
                    winner[l] = NULL;
                }
            }
        }

    }

    //This for loop is to print out the winner(s) if the array cells are not NULL

    for (int j = 0; j < candidate_count; j++)
    {
        if (winner[j] != NULL)
        {
            printf("%s\n", winner[j]);
        }
    }

    return;
}

//How to do this  better:
//You don't actually need to set the array back to NULL.
//You can actually just scan through the array to see who has the highest scores comparing it to votesMax and print out.