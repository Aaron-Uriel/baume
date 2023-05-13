#include <stdio.h>

Node* newNode (int value)
{
    new_node->value     = value;
    new_node->right      = NULL;
    new_node->left  = NULL;

	return new_node;
}

void nodeDelete(Node **node)
{
	free(*node);
    *node = NULL;
}