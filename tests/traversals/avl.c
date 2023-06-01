#include <stdlib.h>
#include <stdio.h>

#include <baume.h>

/*Protptipos*/
void RotationLeftLeft(NodeAVL **problem, NodeAVL *son);
void RotationRightRight(NodeAVL **problem, NodeAVL *son);
void RotationLeftRight(NodeAVL **problem, NodeAVL *son);
void RotationRightLeft(NodeAVL **problem, NodeAVL *son);
NodeAVL *nodeNewAVL(int value);
int heightAVL(struct node* node);

/*Estructura de prueba para rotaciones*/
typedef struct NodeAVL NodeAVL;
struct NodeAVL {
	int  value;
    int fe;
    int height;
	NodeAVL *right;
    NodeAVL *left;
};


NodeAVL *nodeNewAVL(int value)
{
    NodeAVL *new_nodeAVL = malloc(sizeof(*new_nodeAVL));
    if (new_nodeAVL != NULL) {
        new_nodeAVL->value = value;
        new_nodeAVL->fe = 0;
        new_nodeAVL->height = 0;
        new_nodeAVL->right = NULL;
        new_nodeAVL->left  = NULL;
    }

	return new_nodeAVL;
}

int heightAVL(struct NodeAVL* node)
{
    if(node == NULL){
        return 0;
    }
    int lefth, righth;
    lefth = heightAVL(node -> left);
    righth = heightAVL(node -> right);
    if (lefth > right){
        return lefth + 1;
    }
    return righth + 1;
}


void NodeInsertAVL(NodeAVL **tree, NodeAVL *node)
{
    NodeAVL *son = node;

    if (node->value < (*tree)->value)
    {
        NodeInsertAVL((*tree)->left, *son);
        (*tree)->fe --;

            switch ((*tree)->fe)
            {
            case 0: 
                son->height = 0; 
                break;
                                
            case -1: 
                son->height = 0;
                break;

            case -2: 
                grandson = (*tree)->left;
                if (grandson->fe == -1)
                {
                    RotationLeftLeft(tree, son);
                } else
                {
                    RotationLeftRight(tree, son);
                }

                son->height = 0;
                break;
            }   
        }else if (node->value >= (*tree)->value)
        {
            NodeInsertAVL((*tree)->right, son);

            switch ((*tree)->fe)
            {
            case 1:
                son = (*tree)->right;
                if (son->fe = =1)
                {
                    RotationRightRight(tree, son);
                } else {
                    RotationRightLeft(tree, son);
                }
                son->height = 0;
                break;

            case 0: 
                (*tree)->fe == 1;
                break;

            case -1: 
                son->height = 0;
                break;
            
            }  
        }
}







/*Rotación simple izquierda izquierda*/
void RotationLeftLeft(NodeAVL **problem, NodeAVL *son) //Nodo con fe mayor, su hijo
{
    (*problem)->left = son->right;
    son->right = (*problem);

    //Cambio del fe
    if (son->fe == -1)
    {
        (*problem)->fe = 0;
        son->fe = 0;
    } else
    {
        (*problem)->fe = -1;
        son->fe = 1;
    }

    (*problem) = son;
    
}

/*Rotación simple derecha derecha*/
void RotationRightRight(NodeAVL **problem, NodeAVL *son) //Nodo con fe mayor, su hijo
{
    (*problem)->right = son->left;
    son->left = (*problem);

    //Cambio del fe
    if (son->fe == 1)
    {
        (*problem)->fe = 0;
        son->fe = 0;
    }else
    {
        (*problem)->fe = 1;
        son->fe = -1;
    }

    (*problem) = son;
     
}

/*Rotación doble izquierda derecha*/
void RotationLeftRight(NodeAVL **problem, NodeAVL *son) //Nodo con fe mayor, su hijo
{
    NodeAVL *sonRight = son->right; //El hijo derecho de "son"
   
    (*problem)->left = sonRight->right;
    sonRight->right = (*problem);
    son->right = sonRight->left;
    sonRight->left = son;

    //Cambio de fe
    if (sonRight->fe == 1)
    {
        son->fe = -1;
    }else
    {
        son->fe = 0;
    }

    if (sonRight->fe == -1)
    {
        (*problem)->fe = 1;
    } else
    {
        (*problem)->fe = 0;
    }

    sonRight->fe = 0;
    (*problem) = sonRight;
    
}


/*Rotación doble derecha izquierda */
void RotationRightLeft(NodeAVL **problem, NodeAVL *son) //Nodo con fe mayor, su hijo
{
     NodeAVL *sonLeft = son->left; //El hijo izquierdo de "son"

    (*problem)->right = sonLeft->left;
    sonLeft->left = (*problem);
    son->left = sonLeft->right;
    sonLeft->right = son;

    //Cambio del fe
    if (sonLeft->fe == 1)
    {
        (*problem)->fe = -1;
    }else
    {
        (*problem)->fe = 0;
    }

    if (sonLeft->fe == -1)
    {
        son->fe = 1;
    }else
    {
        son->fe = 0;
    }

    sonLeft->fe = 0;
    (*problem) = sonLeft;

}



