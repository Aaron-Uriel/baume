#include <stdio.h>

//Crea un nevo nodo
Node* newNode (int value)
{
    new_node->value     = value;
    new_node->right      = NULL;
    new_node->left  = NULL;

	return new_node;
}
//Elimina el nodos
void nodeDelete(Node **node)
{
	free(*node);
    *node = NULL;
}