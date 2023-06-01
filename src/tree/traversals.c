#include <stdlib.h>
#include <stdio.h>

#include <baume.h>

/* 
 * 'Visita' a un nodo dentro de algún recorrido, es decir, lo imprime.
 */
void visit_node(const Node *const node) {
    printf("%d ", node->value);
}

void
postorder(const Node *const root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    visit_node(root);
}

void preorder (const Node *const root){
    if (root){
        visit_node (root);
        preorder (root -> left);
        preorder (root -> right);
    }
}

void inorder (Node *tree)
{
    if (tree == NULL)
    {
        return; 
    } else
    {
        inorder(tree->left);
        visit_node(tree);
        inorder(tree->right);
    } 
}