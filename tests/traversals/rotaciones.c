#include <baume.h>

/*Estructura de prueba para rotaciones*/
typedef struct NodeAVL NodeAVL;
struct NodeAVL {
	int  value;
    int fe;
	NodeAVL *right;
    NodeAVL *left;
};

/*Prototipos de prueba para rotaciones*/
void RotationLeftLeft(NodeAVL **problem, NodeAVL *son);
void RotationRightRight(NodeAVL **problem, NodeAVL *son);


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