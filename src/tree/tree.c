#include <stdlib.h>
#include <stdbool.h>

#include <baume.h>

#include <stdio.h>

Node *
tree_search_node(const Node *const tree, const Node *const node)
{
    const Node *found_node;
    if (tree == NULL) {
        found_node = NULL;
    }
    else if (tree->value > node->value) {
        printf("Izquierdo\n");
        found_node = tree_search_node(tree->left, node);
    }
    else if (tree->value < node->value) {
        printf("Derecho\n");
        found_node = tree_search_node(tree->right, node);
    }
    else {
        found_node = tree;
    }
    
    return (Node *)found_node;
}
