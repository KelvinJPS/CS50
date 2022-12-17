#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_grade(int letters, int words, int sentences);

int text_length;

int main(void) 
{  
    string text = get_string("Text:");
    text_length = strlen(text);

    int grade =  calculate_grade(count_letters(text), count_words(text),
                                 count_sentences(text));

    if (grade < 1) 
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16) 
    {
        printf("Grade 16+\n");
    }
    else     
    {
        printf("Grade %i\n", grade);

    }

}

int count_letters(string text) 
{
    int number_letters = 0;
    for (int i = 0; i < text_length; i++) 
    { 
        if (isalpha(text[i]))
        {         
            number_letters += 1;
        }
    } 
    return number_letters;   
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i])) 
        {
            words++;
        }
       
    }
    return words + 1;
}

int count_sentences(string text) 
{
    int sentences = 0;
    for (int i = 0; i < text_length; i++) 
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 21)  //the ascii codes for .  ? and ! 
        {
            sentences++;
        }
    }
    return sentences;   
}

int calculate_grade(int letters, int words, int sentences) 
{ 
    float avg_l = (float) letters / (float) words * 100;
    float avg_s = (float) sentences / (float)words * 100;
  
    float index = (0.0588 * avg_l - 0.296 * avg_s - 15.8); 
 
    return round(index);



}