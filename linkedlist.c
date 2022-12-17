#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    typedef struct  node
    {
        int number;
        struct node *next;
    }
    node;
    node *list = NULL; 
    node *n  = malloc(sizeof(node));
    if(n != NULL) 
    {
        for (int  i = 0; i < 10; i++)
        {
            n->number = i;
            n->next  = NULL; 
            list = n;
            list->next = n;
        }
        
        for(node *tmp = list; tmp != NULL; tmp = tmp->next) 
        {
            printf("%i",tmp->number);
        }
        
    }

    
}