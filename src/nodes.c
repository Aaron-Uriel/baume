#include <stdio.h>
#include <stdlib.h>

#include <baume.h>

//Crea un nevo nodo
Node *nodeNew(int value)
{
    Node *new_node = malloc(sizeof(*new_node));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->right = NULL;
        new_node->left  = NULL;
    }

	return new_node;
}
//Elimina el nodos
void nodeDelete(Node **node)
{
	free(*node);
    *node = NULL;
}
