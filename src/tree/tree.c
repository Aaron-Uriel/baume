#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <baume.h>

void recursive_replace(Node **const root);

Node *
tree_search_node(const Node *const tree, const Node *const node)
{
    const Node *found_node;
    if (tree == NULL) {
        found_node = NULL;
    }
    else if (tree->value > node->value) {
        found_node = tree_search_node(tree->left, node);
    }
    else if (tree->value < node->value) {
        found_node = tree_search_node(tree->right, node);
    }
    else {
        found_node = tree;
    }
    
    return (Node *)found_node;
}

/*
 * Devuelve la dirección del nodo encontrado en el árbol, en caso de no existir
 * devuelve NULL.
 */
Node *
tree_extract_node(Node **const tree, const Node *const node)
{
    const Node *found_node;
    if (*tree == NULL) {
        printf("Nodo no encontrado.\n");
        found_node = NULL;
    }
    else if ((*tree)->value > node->value) {
        found_node = tree_extract_node(&(*tree)->left, node);
    }
    else if ((*tree)->value < node->value) {
        found_node = tree_extract_node(&(*tree)->right, node);
    }
    else {
        found_node = *tree;

        /* Reemplazo del nodo que se extrajo. */
        if ((*tree)->left == NULL) {
            (*tree) = (*tree)->right;
        }
        else if ((*tree)->right == NULL) {
            (*tree) = (*tree)->left;
        }
        else {
            recursive_replace(tree);
        }
    }

    return (Node *)found_node;
}

/*
 * Reemplaza recursivamente el nodo recibido como raíz por el mayor de los
 * menores de sus hijos.
 * La función asume que existe el hijo inferior izquierdo, por lo que es
 * preferible que la función se use únicamente cuando hay dos hijos.
 */
void
recursive_replace(Node **const root)
{
    Node *previous_node = *root;
    Node *current_node = (*root)->left;
    while(current_node->right != NULL) {
        previous_node = current_node;
        current_node = current_node->right;
    }
    (*root)->value = current_node->value;

    /* 
     * Caso: el mayor de los menores es justamente el inferior derecho
     * inmediato.
     */
    if ((*root) == previous_node) {
        previous_node->left = current_node->left;
    }
    else {
        previous_node->right = current_node->left;
    }
}

