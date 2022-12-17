#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

string sort_string_alpha (string s);
int main(int argc, string argv[]) 
{
  string usage = "Usage: ./substitution key";
  //check how many arguments the user has given.
    if (argc > 2)
    {
        printf("more than one argument %s\n", usage); 
        return 1;   
    }
    else if (argc <= 1) 
    {
        printf("missing command-line argument, %s\n", usage);
        return 1;
    }
   //check the length of the argument
   string key =  argv[1]; 
   int key_length = strlen(argv[1]);
   if (key_length < 26  || key_length > 26)
   {
       printf("key must contain 26 character letters\n");
       return 1;
   }

   //Check if every character is an albathetical character
   for (int i = 0; i < key_length; i++)
   {
        if (isalpha(key[i]) == 0) 
        {
            printf("key must contain 26 character letters\n");
            return 1;
        }
   }

   //check if letters are not repeated
   string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   //sort key in alphabetical order 
   string key_sorted = sort_string_alpha(key);

   //key_letters is not equal to string alphabet then there is more than one letter 
   if (strcasecmp(alphabet, key_sorted) != 0)
    {
        printf("key must not contain repeated characther");
        return 1;
    }
      
}
string sort_string_alpha (string s) 
{
     //Bubble sort
/*    Repeat n-1 times
      For i from 0 to n–2
           If numbers[i] and numbers[i+1] out of order
              Swap them
       If no swaps
         Quit */
   int swaps  = 0;
   int s_length = strlen(s);
   for (int i = 0; i < s_length; i++)
   {
       for (int j = 0; j < s_length - 1; j++)
       {
            if (s[j] > s[j + 1] )
             {
               char temp = s[j + 1];
               s[j + 1] = s[j];
               s[j] = temp;
                swaps ++;
             } 
       }
       
        if (swaps == 0) 
          {
            return s;
          }
   }
    return s;
}