#include <cs50.h>
#include <stdio.h>
#include <string.h>


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
}
candidate;

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
    /* How to implement vote
    What it does take as input and what does that input means? 
    it takes as arguments  voter, rank, name
    voter is an int value, that is the position of the voter , where rank is the order on which the voter wants to put the candidate
    for example :  vote(0,0,0) the first voter put as his/her first candidate on t
    What does need the program verificate?
    it needs to verificate that name exists in the array candidates 
    How it would do that? 
    By impementing a linear search on the array candidates if name exists it would save the position on the array candidates
    Why what would happen if name doesn't exists? 
    Return false
    How does the function record the ranking of a voter? 
    preferences[voter],[rank],[candidateposition]*/

    //Search for the name in the array candidates by implementing linear search 
    for (int i = 0; i < candidate_count; i++) 
    { 
        if (strcmp(name, candidates[i].name) == 0) 
        
        {
            //Update preferences
            preferences[voter][rank]  =  i;
            return true;
        }

    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

    /* Implementing tabulate
       Input : a two dimensional array that contains the voters preferences 
       for example preferences [0][0] = 0 the first voter put as his higher rank the first candidate of the list of candidates. 
       Output : The candidates votes count increases if they have been ranked at the top of the voter preference and if they have not been eliminated.
       The process :  loop in the array preferences 
       if the firt voter's candidate in the  rank is not eliminated 
        increment candidates.votes 

        else 
        loop in the voter's preferences  
         if candidate that have not been eliminated is found
             candidates[voter_candidate].votes++
             quit.

    */
    for (int i = 0; i < voter_count; i++) 
    {
        int voter_candidate = preferences[i][0]; //It sets the vote_Candidate to the first in the rank 
                 
        if (candidates[voter_candidate].eliminated == false)
        {
            candidates[voter_candidate].votes++; 
        }

        else 
        {
            for (int j = 1; j < candidate_count; j++) 
            {
                voter_candidate = preferences[i][j];

                if (candidates[voter_candidate].eliminated == false) 
                {
                    candidates[voter_candidate].votes++;
                    break; 
                }
                    
            }
        }
             

    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    /* Input : The number of voters of each candidate 
       Output : Print the winner of the election if a candidate has the majority of the voters if not return false 
       Process :
        loop in the array of candidates
        if(candidates[i].votes > totalvotes/2) 
        {
            print(candidates[i].name)
            return true
        }
        return false        
    */

    //calculate total votes
    int totalvotes = 0;
    for (int i = 0; i < candidate_count; i++) 
    {
        totalvotes = totalvotes + candidates[i].votes ;
    }
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes > totalvotes / 2) 
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    /* Input : the number of votes of each candidate
       Output : The mininum numbe of votes that has one or more candidates, in the array of candidates 
       Process : loop in the array candidates pick the min votes number using selection sort.
    */
    int minimum = 0;
    for (int i = 0; i < candidate_count - 1; i++) 
    {
        if (candidates[i].eliminated  == false && candidates[i + 1].eliminated == false  && candidates[i].votes >= candidates[i + 1].votes) 
        {
            minimum = candidates[i + 1].votes;
        }
    }
    return minimum;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // if every candidate's votes is equal to min return true
    int counter = 0;
    int candidates_n = 0;
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].eliminated == false) 
        {
            candidates_n++;
        }
        if (candidates[i].votes == min) 
        {
            counter++;
        }
    }
    //candidates that has not been eliminated
    if (counter == candidates_n) 
    {
        return true;
    }
    return false;
}
// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Remove candidate that has candidate.votes == min 
    for (int i = 0; i < candidate_count; i++) 
    {
        if (candidates[i].votes == min) 
        {
            candidates[i].eliminated = true;
        } 
    } 

}