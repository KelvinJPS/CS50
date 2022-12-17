#include <stdio.h>

int main(void) 
{
    int n = 50; 
    int *p = &n; //  the address in memory of the variable n, int means that the pointer is referring to a int value.
    printf("%p\n", p);  //Printing n'address  
    printf("%i\n", *p); // here is printing the value that's int, in the address of pointer p, that's what * before the pointer is for.

}