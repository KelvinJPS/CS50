#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
         int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //Linear search, if name exists in the array candidates, update ranks
    for (int i = 0; i < candidate_count; i++) 
    {
        if (strcmp(name, candidates[i]) == 0) 
        {  
            ranks[rank] = i;
            return true;
        } 
    }    

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    /* 
      if we have the next values  : 
      ./tideman Alice Bob Charlie
      Alice
      preferences[0][0] = 0 How many voters prefer Alice over Alice 
      preferences[0][1] = 1 voters prefer Alice over Bob 
      preferences[0][2] = 1 voters prefer Alice over Charlie

      Bob
      preferences[1][0] = 0 How many voters prefer Bob over Alice 
      preferences[1][1] = 0 voters prefer Bob over Bob 
      preferences[1][2] = 0 voters prefer Bob over Charlie

      Charlie 
      preferences[2][0] = 0 How many voters prefer Charlie over Alice 
      preferences[2][1] = 1 voters prefer Charlie over Bob 
      preferences[2][2] = 0 voters prefer Charlie over Charlie

     
      Rank 1: Alice
      Rank 2: Charlie
      Rank 3: Bob
      
      Rank 1: Bob
      Rank 2: Charlie
      Rank 3: Alice

      Rank 1: Bob
      Rank 2: Charlie
      Rank 3: Alice

      Rank 1: Charlie
      Rank 2: Alice
      Rank 3: Bob
  

      What should be recorded on preferences[i][j]? 
      Alice
      preferences[0][0] = 0 How many voters prefer Alice over Alice 
      preferences[0][1] = 3 voters prefer Alice over Bob 
      preferences[0][2] = 2 voters prefer Alice over Charlie

      Bob
      preferences[1][0] = 2 How many voters prefer Bob over Alice 
      preferences[1][1] = 0 voters prefer Bob over Bob 
      preferences[1][2] = 2 voters prefer Bob over Charlie

      Charlie 
      preferences[2][0] = 3 How many voters prefer Charlie over Alice 
      preferences[2][1] = 3 voters prefer Charlie over Bob 
      preferences[2][2] = 0 voters prefer Charlie over Charlie

      Proccess :
         
    */
   for (int  i = 0; i < candidate_count; i++)
   { 
        for(int j = 0; j < candidate_count; j++)  
        {
            
        }
   }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}