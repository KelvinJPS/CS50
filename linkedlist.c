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
    //Understanding linked lists
    // The problem : inserting new values in a "list/collection of data"  without having to create a copy.
    // The advantages: Inserting values with a constant time. 
    // How ? 
    // We can insert always at the begining of the list or end. 
    
    node *list;

    //Add number to list 
    node *n = malloc(sizeof(node));
    n->number = 1;
    n->next = NULL;
    list = n;

    //Add second number to list  
    n = malloc(sizeof(node));
    n->number = 2;
    n->next = NULL;
    list->next = n;
    //Add a third number to the list .
    n = malloc(sizeof(node));
    n->number = 3;
    n->next = NULL;
    list->next->next = n;
    //Printing numbers 
    printf("%i\n",list->number);
    printf("%i\n",list->next->number);
    printf("%i\n",list->next->next->number);

    //Second list using loop
    node *list2 = malloc(sizeof(node));
    int i = 0;

    while(i < 10) 
    {
        //how to insert values at the end. 
        i++;
        node *temp = malloc(sizeof(node));
        temp->number =  i;
        temp->next = NULL; 
        list2->next = temp;
    

    for (node *tmp = list2; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }
    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;
}
