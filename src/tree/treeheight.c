#include <stdio.h>
#include <baume.h>

int treeheigth (int a [], int n){
    int vez, treelevel;
    for (vez = 0; vez < n; vez++){
        if (a [vez] -> a[vez + 1] && a [vez + 1] -> a [vez]){
            ++treelevel;
        }
        else {
            ++vez;
        }
    }
    return treelevel;
}