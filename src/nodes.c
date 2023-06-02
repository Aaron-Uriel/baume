#include <stdio.h>
#include <stdlib.h>

#include <baume.h>

/* Crea un nuevo nodo, dicho nodo incluye un factor de equilibrio. */
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

//Elimina el nodos
void avlNodeDelete(NodeAVL **node)
{
	free(*node);
    *node = NULL;
}
