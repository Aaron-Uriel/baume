#include <stdio.h>
#include <baume.h>

void preorder (int a [], int n){
    int i;
    for (i = 0; i < n; ++i){
        printf ("%d ", a [i]);
    }
    printf ("%d\n", a [n]);
}