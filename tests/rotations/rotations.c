#include <stdio.h>
#include <stdlib.h>

#include <baume.h>

#define NODES_LIMIT 3
int main()
{
  NodeAVL *nodesAvlLL[NODES_LIMIT];
    for (int i = 0; i < NODES_LIMIT; i += 1) {
        nodesAvlLL[i] = nodeNewAVL(i + 1);
    }

    for (int i = 0; i < NODES_LIMIT; i += 1) {
        printf("%d de fe %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->fe);
    }

    nodesAvlLL[2]->left = nodesAvlLL[1];
    nodesAvlLL[1]->left = nodesAvlLL[0];
    nodesAvlLL[2]->fe = -2;
    nodesAvlLL[1]->fe = -1; 

    for (int i = 0; i < NODES_LIMIT; i += 1) {
        if (nodesAvlLL[i]->right == NULL && nodesAvlLL[i]->left == NULL)
        {
           printf("%d en izquierda NULL y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->fe);
        } else if (nodesAvlLL[i]->right == NULL)
        {
            printf("%d en izquierda %d y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->fe);
        }else if (nodesAvlLL[i]->left == NULL)
        {
            printf("%d en izquierda NULL y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);
        } else
        {
          printf("%d en izquierda %d y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);  
        }   
    }

    RotationLeftLeft(&nodesAvlLL[2], nodesAvlLL[1]);

    printf("Después de la función LeftLeft: \n");

    for (int i = 0; i < NODES_LIMIT; i += 1) {
        if (nodesAvlLL[i]->right == NULL && nodesAvlLL[i]->left == NULL)
        {
           printf("%d en izquierda NULL y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->fe);
        } else if (nodesAvlLL[i]->right == NULL)
        {
            printf("%d en izquierda %d y derecha NULL con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->fe);
        }else if (nodesAvlLL[i]->left == NULL)
        {
            printf("%d en izquierda NULL y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);
        } else
        {
          printf("%d en izquierda %d y derecha %d con fe: %d\n", nodesAvlLL[i]->value, nodesAvlLL[i]->left->value, nodesAvlLL[i]->right->value, nodesAvlLL[i]->fe);  
        }   
    }
}
