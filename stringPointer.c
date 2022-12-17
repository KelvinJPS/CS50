#include <stdio.h>

int main (void) 
{
    //A string is a pointer to the first value of the characther
    char *s = "Hi!";  
    char *c = &s[0]; 
     
    printf("%p\n",s); 
    printf("%p\n", c);
}
