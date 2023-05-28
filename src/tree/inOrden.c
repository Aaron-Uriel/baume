#include <stdio.h>
#include <stdlib.h>
#include <baume.h>

void inorden (Node *tree)
{
    if (tree == NULL)
    {
        return;       //Si está vacío sólo return
    } else
    {
        inorder(tree->left);
        printf("%d - ", tree->left->value);
        inorder(tree->right);
        printf("%d - ", tree->right->value);

    }
    
    
}