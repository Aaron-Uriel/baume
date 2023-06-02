#include <stdio.h>
#include <stdlib.h>

#include <baume.h>

/* Calcular factor de equilibrio */
int fe(NodeAVL *node)
{
    int lefth = tree_height(node -> left);
    int righth = tree_height(node -> right);
    return righth - lefth;
}

/* Rotación izquierda. */
NodeAVL* RotationLeft(NodeAVL* node)
{
    NodeAVL* temp = node -> right;

    node -> right = temp -> left;
    temp -> left= node;

    node -> height = tree_height(node);
    temp -> height = tree_height(temp);

    node -> fe = fe(node);
    temp -> fe = fe(temp);
    return temp;
}

/* Rotación  derecha. */
NodeAVL* RotationRight(NodeAVL *node) 
{
    NodeAVL* temp = node -> left;

    node -> left = temp -> right;
    temp -> right = node;

    node -> height = tree_height(node);
    temp -> height = tree_height(temp);

    node -> fe = fe(node);
    temp -> fe = fe(temp);
    
}


