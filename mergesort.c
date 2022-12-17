#include <stdio.h>


int main(void) 
{
   int a[] = {5, 2, 7, 4, 1, 6, 3, 0};
   int swaps  = 0;
   int n = 8;

   /* Merge sort
   if only one number 
        quit

    sort left half
   
    sort rigth half

    merge list by comparing the first value of the left list and the rigth value of the list */

    if (n == 1) 
    {
       return 0;
    }

    //make left half
    int left [n/2];  
    for (int i = 0; i < n/2; i++) 
    { 
         left[i] = a[i];  
    }
   // make right half 
   int right [n/2];
   for (int i = 0; i < n/2; i++) 
    { 
         right[i] = a[i];  
    }

    for (int i = 0;  i<n/2; i++ ) 
    { 
      printf("%i,",right [i]);
    }

   
 

}