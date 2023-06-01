#include <stdint.h>

#include <baume.h>

#define NODES_LIMIT 7

int32_t main(void) {
    /* Recreo el árbol de la figura 14.27, página 435. */
    Node *nodes[NODES_LIMIT];
    for (int8_t i = 0; i < NODES_LIMIT; i += 1) {
        nodes[i] = nodeNew(i + 1);
    }
    nodes[6]->left = nodes[2];
    nodes[6]->right = nodes[5];
    nodes[2]->left = nodes[0];
    nodes[2]->right = nodes[1];
    nodes[5]->left = nodes[3];
    nodes[5]->right = nodes[4];

    postorder(nodes[6]);
}

