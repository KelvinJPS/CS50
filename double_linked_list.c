#include <stdio.h>
#include <stdlib.h>
typedef  struct node 
{
    int number;
    struct node *previous;
    struct node *next;
} 
node;

node *insert(node *head,int n);
int main(void) 
{
    node *head;
    //Inserting values 
    int i = 0;

    while(i < 10) 
    {
        i++;
        head = insert(head,i);    

    }
    //printing values
    for (node *tmp = head; head != NULL; head  = head->next)
    {
        printf("%i",tmp->number);
    }

}

node *insert(node *head,int n) 
{
    node *tmp = malloc(sizeof(node));
    tmp->number = n;
    tmp->previous =  NULL;
    tmp->next = head;
}
