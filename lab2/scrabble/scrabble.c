#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int alphabet_length = 26; 
char ALPHABET [alphabet_length]  = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
string s = (string) ALPHABET;

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    //Return the winner or tie if it is the case
    if (score1 > score2) 
    {
        printf("Player 1 wins!");

    }
    else if (score2 > score1) 
    {
        printf("Player 2 wins!");
    }

    else 
    {
        printf("Tie!");
    }

}

int compute_score(string word)
{
    int word_length = strlen(word);
    int points = 0;
    
    for (int i = 0; i < word_length; i++) 
    {        
        char letter = toupper(word[i]);
        for (int position = 0; position < alphabet_length; position++) 
        {   
            //Return the  position of the char on the array alphabet
            if (ALPHABET[position] == letter) 
            {
                points = points + POINTS[position]; //the array Points is sorted by the alphabet
            }

        }        
    }

    return points;
}


