#include <stdio.h>

typedef struct node 
{
    int number;
    struct node *left;
    struct node *right;
}
node;

int main(void)
{
    node *tree = NULL;
    
    //Add number to the list
    node *n = malloc(sizeof(node));
    n->number = 2;
    n->left = NULL;
    n->right =  NULL;
    tree = n;

    //Add number to the list 
    n = malloc(sizeof(node));
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    ///Add number to the lisr 
    n = malloc(sizeof(node));
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    ///print number
    printf("%i,%i,%i\n",tree->left->number,tree->number,tree->right->number);

}
