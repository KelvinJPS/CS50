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
    //add spaces for each columns
    for(int j = heigth; j>i; j--) 
      {
         printf(" ");
      }

   //Add a row to the left 
    printf("#");

   //For each column  add a  brick
    for(int j = 0; j<i; j++) 
    {
       printf("#");
    }
 //Add a gap between the two pyramids
   printf("  ");
   
   //For each column add a brick
    for(int j = 0; j<i; j++) 
    {
       printf("#");
    }
  //move to the  next row
    printf("#\n");
 
    }


}