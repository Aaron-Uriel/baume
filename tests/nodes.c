#include <stdlib.h>
#include <assert.h>

#include <baume.h>

int
main(void) {
    Node *test_node = nodeNew(99);
    assert(test_node->value == 99 && test_node->left == NULL
            && test_node->right == NULL);

    nodeDelete(&test_node);
    assert(test_node == NULL);
}
