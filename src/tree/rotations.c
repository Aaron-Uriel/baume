#include <stdio.h>
#include <stdlib.h>

#include <baume.h>

/* Rotación simple izquierda izquierda. */
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

/* Rotación simple derecha derecha. */
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

/* Rotación doble izquierda derecha. */
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

/* Rotación doble derecha izquierda. */
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

