#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char rotate(char c, int n);
bool only_digits(string s);

int main(int argc, string argv[]) 
{
    string usage = "Usage: ./caesar key";
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

    //check if the paramaters are numbers
    else if (only_digits(argv[1]) == false)
    {
        printf("%s", usage);
        return 1;
    }
   
    //program ask the user for the plain text
    string plain_text = get_string("Plain text: ");
    int text_length = strlen(plain_text);
    int key = atoi(argv[1]);  //convert the key that the user has given to int 
    //print the cypher text
    printf("ciphertext:  ");
    for (int i = 0; i < text_length; i++) 
    {
        printf("%c", rotate(plain_text[i], key));

    }
    printf("\n");
    return 0;
   
}
bool only_digits(string s) 
{ 
    int argv_length = strlen(s);
    for (int i = 0; i < argv_length; i++) 
    {
        if (isdigit(s[i]) == 0)
        {
            return false;    
        }
      
    }
    return true; 
}
char rotate(char c, int key) 
{   
    if (isupper(c))
    {
        c = c - 65; //Convert c to an alphabetical index 
        c = (c + key) % 26; //shift c by the key 
        return  c + 65; // convert c back to an ASCII value
        //note 65 is the ASCII value of A the first letter of the alphabet
    }
    if (islower(c))
    {
        c = c - 97; //Convert c to an alhabetical index
        c = (c + key) % 26; //shift c by the key
        return c + 97; //convert c back to an ASCII value 
        //Note 97 is the ASCII value of a the first letter of the alphabet

    }
    //is neither a upper or lower letter then is not a letter at all, so the program will return the charachter as it is
    return c; 
   
}