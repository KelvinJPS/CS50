#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int heigth = 0;

//Ask for the heigth
do 
{ 
   heigth = get_int("Heigth: ");
}
while ( heigth<1 || heigth>8 );

//rows
 for(int i = 0; i<heigth; i++) 
 {
    //For each column add a space
    for(int j = heigth; j>i; j--) 
      {
         printf(" ");

      }
   //For each column add a brick
    for(int j = 0; j<i; j++) 
    {
        printf("#");

    }
    printf("#\n");


 }

}