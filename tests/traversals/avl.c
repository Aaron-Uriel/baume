#include <stdlib.h>
#include <stdio.h>

#include <baume.h>

/*Protptipos*/
NodeAVL *nodeNewAVL(int value);

typedef struct NodeAVL NodeAVL;
struct NodeAVL {
	int  value;
    int fe;
	NodeAVL *right;
    NodeAVL *left;
};


NodeAVL *nodeNewAVL(int value)
{
    NodeAVL *new_nodeAVL = malloc(sizeof(*new_nodeAVL));
    if (new_nodeAVL != NULL) {
        new_nodeAVL->value = value;
        new_nodeAVL->fe = 0;
        new_nodeAVL->right = NULL;
        new_nodeAVL->left  = NULL;
    }

	return new_nodeAVL;
}

//La altura para un arbol AVL
int heightAVL(NodeAVL* tree){
    if(tree == NULL){
        return 0;
    }else {
        int leftSide;
        int rightSide;
        leftSide = heightAVL(tree -> left);
        rightSide = heightAVL(tree -> right);
        if (leftSide > rightSide){
            return leftSide + 1;
        }else {
            return rightSide + 1;
        }
    }
}


void NodeInsertAVL(NodeAVL **tree, int value, int height)
{
    NodeAVL *son;

    if (*tree == NULL)
    {
        *tree = nodeNew(value);
    } else if (value < (*tree)->value)
    {
        NodeInsertAVL((*tree)->left, value, height);

        switch ((*tree)->fe)
        {
        case 1: //1 sólo para que no marque error
            /* code */
            break;
        
        default:
            break;
        }
        
    }
    
    {
        /* code */
    }
    
    
}