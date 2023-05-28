#include <stdio.h>
#include <stdlib.h>
#include <baume.h>

void inorder (Node *tree)
{
    if (tree == NULL)
    {
        return;       //Si está vacío sólo return
    } else
    {
        inorden(tree->left);
        printf("%d - ", tree->left);
        inorden(tree->right);
        printf("%d - ", tree->right);

    }
    
    
}