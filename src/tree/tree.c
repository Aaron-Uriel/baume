#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <baume.h>

void indent(uint8_t level, uint32_t pipes_needed);
void recursive_print(const Node *const root, uint8_t level, bool is_lower_right);

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
 * Inicia la impresión del árbol.
 * Solo se encarga de iniciar las llamadas recursivas que imprimiran 
 * el árbol por completo.
 */
void
tree_print(const Node *const tree)
{
    printf("%d\n", tree->value);
    recursive_print(tree->right, 1, true);
    recursive_print(tree->left, 1, false);
}

/*
 * Imprime el árbol recursivamente.
 */
void
recursive_print(const Node *const root, uint8_t level, bool is_lower_right)
{
    if (root == NULL) { return; }

    /* 
     * Agregamos o quitamos un bit en el nivel donde se necesita un
     * '|'; un bit prendido en la posición x significa que x
     * necesita '│'.
     */
    static uint32_t pipes_needed = 0;
    if (is_lower_right) {
        pipes_needed = pipes_needed | (1 << (level - 1));
    } else {
        pipes_needed = pipes_needed ^ (1 << (level - 1));
    }

    indent(level, pipes_needed);
    printf("%s %d\n", (is_lower_right)? "├──": "└──", root->value);

    recursive_print(root->right, level + 1, true);
    recursive_print(root->left, level + 1, false);
}

/*
 * Imprime las tabulaciones necesarias por nivel, siempre las 
 * tabulaciones necesarias por nivel son el nivel menos uno, ya que
 * se toma en cuenta el espacio ocupado por ├── o └──.
 */
void
indent(uint8_t level, uint32_t pipes_needed)
{

    for (uint8_t i = 0; i < level - 1; i += 1) {
        if (pipes_needed & (1 << i)) {
            printf("│   ");
        } else {
            printf("    ");
        }
    }
}
