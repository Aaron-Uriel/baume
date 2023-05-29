#include <stdio.h>
#include <stdint.h>

#include <baume.h>

#define NODES_LIMIT 10

int32_t
main(void) {
    Node *nodes[NODES_LIMIT];
    printf("Direcciones de memoria:\n");
    for (int8_t i = 0; i < NODES_LIMIT; i += 1) {
        nodes[i] = nodeNew(i + 1);
        printf("\tnodes[%d]: %p\n", i, (void *)nodes[i]);
    }
    nodes[0]->value = 10;
    nodes[1]->value = 9;
    nodes[2]->value = 5;
    nodes[3]->value = 4;
    nodes[4]->value = 6;
    nodes[5]->value = 7;
    nodes[6]->value = 25;
    nodes[7]->value = 39;
    nodes[8]->value = 41;
    nodes[0]->right = nodes[1];
    nodes[0]->left = nodes[6];
    nodes[1]->right = nodes[2];
    nodes[1]->left = nodes[5];
    nodes[2]->right = nodes[3];
    nodes[2]->left = nodes[4];
    nodes[6]->right = nodes[7];
    nodes[6]->left = nodes[8];
    
    tree_print(nodes[0]);

}

