// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//Helper fuction prototype
node *insert_node(node *head, char word[LENGTH + 1]);
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0) 
        {
            return true;
        } 
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open file 
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("could not open dictionary\n");
        return false;
    }
    //Read dictionary 
    char word [LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) 
    {
        //Update hash table bucket's head.
        table[hash(word)] = 
            insert_node(table[hash(word)], word); 
    }
    fclose(file);
    return true;
}

//Insert node at the beginning and return new head  
node *insert_node(node *head, char word[LENGTH + 1])
{
    node *tmp = malloc(sizeof(node));
    strcpy(tmp->word, word);
    tmp->next = head;
    return tmp;
    
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int  words = 0;
     
    for (int i = 0; i < N; i++)
    {
        //Bucket has a value 
        if (table[i] != NULL) 
        { 
            for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
            {
                words++;
            }
        }
    }
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;

        }
    }
    return true;

}
