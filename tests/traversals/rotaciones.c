#include <baume.h>
#include <stdio.h>
#include <stdlib.h>

/*Estructura de prueba para rotaciones*/
typedef struct NodeAVL NodeAVL;
struct NodeAVL {
	int  value;
    int fe;
    int height;
	NodeAVL *right;
    NodeAVL *left;
};

/*Prototipos de prueba para rotaciones*/
void RotationLeftLeft(NodeAVL **problem, NodeAVL *son);
void RotationRightRight(NodeAVL **problem, NodeAVL *son);
void RotationLeftRight(NodeAVL **problem, NodeAVL *son);
void RotationRightLeft(NodeAVL **problem, NodeAVL *son);
NodeAVL *nodeNewAVL(int value);

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


#define NODES_LIMIT 3
int main()
{
  NodeAVL *nodesAvlLL[NODES_LIMIT];
    for (int i = 0; i < NODES_LIMIT; i += 1) {
        nodesAvlLL[i] = nodeNewAVL(i + 1);
    }

    for (int i = 0; i < NODES_LIMIT; i += 1) {
        printf("%d de fe %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->fe);
    }

    nodesAvlLL[2]->left = nodesAvlLL[1];
    nodesAvlLL[1]->left = nodesAvlLL[0];
    nodesAvlLL[2]->fe = -2;
    nodesAvlLL[1]->fe = -1; 

    for (int i = 0; i < NODES_LIMIT; i += 1) {
        if (nodesAvlLL[i]->right == NULL && nodesAvlLL[i]->left == NULL)
        {
           printf("%d en izquierda NULL y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->fe);
        } else if (nodesAvlLL[i]->right == NULL)
        {
            printf("%d en izquierda %d y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->fe);
        }else if (nodesAvlLL[i]->left == NULL)
        {
            printf("%d en izquierda NULL y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);
        } else
        {
          printf("%d en izquierda %d y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);  
        }   
    }

    RotationLeftLeft(&nodesAvlLL[2], nodesAvlLL[1]);

    printf("Después de la función LeftLeft: \n");

    for (int i = 0; i < NODES_LIMIT; i += 1) {
        if (nodesAvlLL[i]->right == NULL && nodesAvlLL[i]->left == NULL)
        {
           printf("%d en izquierda NULL y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->fe);
        } else if (nodesAvlLL[i]->right == NULL)
        {
            printf("%d en izquierda %d y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->fe);
        }else if (nodesAvlLL[i]->left == NULL)
        {
            printf("%d en izquierda NULL y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);
        } else
        {
          printf("%d en izquierda %d y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);  
        }   
    }
}
