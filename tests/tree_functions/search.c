#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <baume.h>

#define NODES_LIMIT 5

int32_t
main(void) 
{
    /* Árbol de la figura 14.27, página 435. */
    Node *nodes[NODES_LIMIT];
    printf("Direcciones de memoria:\n");
    for (int8_t i = 0; i < NODES_LIMIT; i += 1) {
        nodes[i] = nodeNew(i + 1);
        printf("\tnodes[%d]: %p\n", i, (void *)nodes[i]);
    }
    nodes[0]->value = 3;
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->value = 1;
    nodes[2]->value = 9;
    nodes[2]->left = nodes[3];
    nodes[2]->right = nodes[4];
    nodes[3]->value = 5;
    nodes[4]->value = 10;

    Node *found_node = tree_search_node(nodes[0], nodes[4]);
    assert(found_node == nodes[4]);

    found_node = tree_search_node(nodes[0], nodeNew(20));
    assert(found_node == NULL);

    found_node = tree_search_node(nodes[1], nodes[4]);
    assert(found_node == NULL);

    found_node = tree_search_node(nodes[2], nodes[2]);
    assert(found_node == nodes[2]);

    found_node = tree_search_node(nodes[2], nodes[3]);
    assert(found_node == nodes[3]);
}

