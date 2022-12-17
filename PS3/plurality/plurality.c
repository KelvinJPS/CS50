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
    //search for the name by implementing a linear search in the array of candidates. if found candidate.votes =+ 1
    bool candidatef;
    for (int i = 0; i < candidate_count; i++) 
    {
         
        if (strcmp(candidates[i].name, name) == 0) 
        {
            candidates[i].votes++;
            candidatef = true;                   
        }
    }
    
    return candidatef;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // variable winner_candidate, update it when a candidate with a higher number of votes it's found
    candidate winner_candidate;
    winner_candidate.votes = 0;
    winner_candidate.name = "tied";
    candidate winners [MAX]; 
    int winners_number = 0;

    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes > winner_candidate.votes) 
        {
            winner_candidate.votes = candidates[i].votes;
            winner_candidate.name = candidates[i].name; 
        }
    }

    /*How to print multiple winners 
      Loop in the array candidates
      if candidates[i] == winner_candidate 
      winners.candidates.add (winner.candidate)

    */
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes == winner_candidate.votes) 
        {
            winners[i] = candidates[i]; 
            winners_number++;
        }
    }
    //print winners
    if (winners_number > 1)
    {
        for (int i = 1;  i < winners_number ; i++) 
        {
            printf("%s\n", winners[i].name);
        }
    }
    // print winner
    printf("%s\n", winner_candidate.name);

    
}