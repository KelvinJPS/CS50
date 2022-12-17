#include <stdio.h>
#include <cs50.h>
int main(void) 
{
   int a[] = {5, 2, 7, 4, 1, 6, 3, 0};
   int swaps  = 0;
   int n = 8;
   bool swapped;

   do
   {
   swapped = false;
   for (int j = 0; j < n - 1; j++)
   {
         
         if (a[j] > a[j + 1] )
             {
               char temp = a[j + 1];
               a[j + 1] = a[j];
               a[j] = temp;              
               swaps ++;
               swapped = true;
               
             } 
  }
       
  }
   while (swapped);
     
 printf("%i\n",swaps);
   

  for(int i = 0; i < n; i++) 
  {
    printf("%i",a[i]);
    
  }
  printf("\n");
}