#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include <baume.h>

int32_t
main(void)
{
    Node *nodes[10];
    for (uint8_t i = 0; i < 10; i += 1) {
        nodes[i] = nodeNew(0);
    }
    nodes[0]->value = 1;
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[7];
    nodes[1]->value = -10;
    nodes[1]->left = nodes[2];
    nodes[1]->right = nodes[3];
    nodes[2]->value = -20;
    nodes[3]->value = -5;
    nodes[3]->left = nodes[4];
    nodes[3]->right = nodes[5];
    nodes[4]->value = -7;
    nodes[4]->left = nodes[9];
    nodes[5]->value = -1;
    nodes[5]->left = nodes[6];
    nodes[6]->value = -3;
    nodes[7]->value = 2;
    nodes[8]->value = 3;
    nodes[9]->value = -8;

    tree_extract_node(&nodes[0], nodeNew(1));
    printf("%d", nodes[0]->value);
    assert(nodes[0]->value == -1);
    assert(nodes[3]->right->value == -3);

    tree_extract_node(&nodes[0], nodeNew(-5));
    printf("%d", nodes[3]->value);
    assert(nodes[3]->left == nodes[9]);
    assert(nodes[3]->right == nodes[6]);
}

