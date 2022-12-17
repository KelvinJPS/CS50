#include <stdio.h>
#include <cs50.h>

int main (void) 
{   
   int a[] = {5, 2, 7, 4, 1, 6, 3, 0};
   int swaps  = 0;
   int n = 8;
   int sn;
   for(int i = 0; i < n - 1; i++) 
   {
        if(a[i] > a[i + 1]) 
        {
           sn = a[i + 1];
           a[i] = sn;
        }
        
   } 

   for( int i = 0; i < n; i++) 
   {
         printf("%i", i);
   }


}