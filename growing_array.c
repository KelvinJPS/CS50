#include "stdio.h"

 
int main(void) 
{
    int size = 5;
    //I have this list, How do I do, for adding more values.
    int a[5] = {1,2,3,4,5};
    //Solution, make a second array of a size enough to store the new values. 
    int b[7];

    //Copy arrray to new array
    for (int i = 0; i < size; i++) 
    {
        b[i] = a[i];

    }
    size += 1;
    b[5] = 6;
    
    //Printing values
    for (int i = 0; i < 6; i++) 
    {
        printf("%i,",b[i]);
    }
}


