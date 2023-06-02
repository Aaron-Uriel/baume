#include <stdlib.h>
#include <assert.h>

#include <baume.h>

int
main(void) {
    NodeAVL *test_node = nodeNewAVL(99);
    assert(test_node->value == 99 && test_node->left == NULL
            && test_node->right == NULL);

    avlNodeDelete(&test_node);
    assert(test_node == NULL);
}
