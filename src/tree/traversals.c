#include <stdlib.h>
#include <stdio.h>

#include <baume.h>

/* 
 * 'Visita' a un nodo dentro de algún recorrido, es decir, lo imprime.
 */
void visit_node(const Node *const node) {
    printf("%d ", node->value);
}
