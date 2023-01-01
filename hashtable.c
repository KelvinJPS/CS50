#include <stdio.h> 

typedef struct 
{
    int *number;
    struct node  *left; 
    struct node  *right;
}
node;

int main(void) 
{
    
    node *tree = NULL; 
    //Add number to the tree 
    node *n = malloc(sizeof(node));
    if(n == NULL) 
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    //Add another number
    n = malloc(sizeof(node));
    n->number = 1; 
    n->left = NULL;
    n->right = NULL;
    tree->left = n;
}
