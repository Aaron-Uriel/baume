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
void RotationLeftLeft(NodeAVL **problem, NodeAVL *next);



/*Rotación simple izquierda izquierda*/
void RotationLeftLeft(NodeAVL **problem, NodeAVL *next) //Nodo con fe mayor, el que le sigue
{
    (*problem)->left = next->right;
    next->right = (*problem);

    //Cambio del fe
    if (next->fe == -1)
    {
        (*problem)->fe = 0;
        next->fe = 0;
    } else
    {
        (*problem)->fe = -1;
        next->fe = 1;
    }

    (*problem) = next;
    
}

/*Rotación simple derecha derecha*/
void RotationRightRight(NodeAVL **problem, NodeAVL *next) //Nodo con fe mayor, el que le sigue
{
    (*problem)->right = next->left;
    next->left = (*problem);

    //Cambio del fe
    if (next->fe == 1)
    {
        (*problem)->fe = 0;
        next->fe = 0;
    }else
    {
        (*problem)->fe = 1;
        next->fe = -1;
    }

    (*problem) = next;
     
}