#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <baume.h>

void indent(uint8_t level, uint32_t pipes_needed);
void recursive_print(const NodeAVL *const root, uint8_t level,
        bool is_lower_right, bool is_last);
void recursive_replace(NodeAVL **const root);

/* Calcular factor de equilibrio */
int fe(NodeAVL *node)
{
    int lefth = tree_height(node -> left);
    int righth = tree_height(node -> right);
    return righth - lefth;
}

int tree_height(struct NodeAVL* node)
{
    if(node == NULL){
        return 0;
    }

    int left, right;
    left = tree_height(node -> left);
    right = tree_height(node -> right);
    if (left > right){
        return left + 1;
    }
    return right + 1;
}

NodeAVL *avlInsertNode(NodeAVL **tree, NodeAVL *node)
{
    NodeAVL *son = node;

    if (*tree == NULL) { //--------------------------
        *tree = nodeNewAVL(node->value);
    }
    else if (node->value < (*tree)->value) {

        (*tree)->left = avlInsertNode(&(*tree)->left, son);

        if (fe((*tree)) == -2)
        {
            if (son->value  < (*tree)->left->value){
                (*tree) = RotationRight(&(*tree));
            } else{
            (*tree) -> left = RotationLeft(&(*tree) -> left);
            (*tree) = RotationRight(&(*tree));
            }
        }
    }    
    else{
       (*tree)->right = avlInsertNode(&(*tree)->right, son);
        if (fe((*tree)) >= 2)
        {
            if (son->value  >= (*tree)->right->value)
            {
                (*tree) = RotationLeft(&(*tree));
            } else{
                (*tree)->right = RotationRight(&(*tree)->right);
                (*tree) = RotationLeft(&(*tree));
            }
            
        } 
    }

    (*tree) -> height = tree_height((*tree));
    (*tree) -> fe = fe((*tree));
    return (*tree);
}

NodeAVL *
tree_search_node(const NodeAVL *const tree, const NodeAVL *const node)
{
    const NodeAVL *found_node;
    if (tree == NULL) {
        found_node = NULL;
    }
    else if (tree->value > node->value) {
        found_node = tree_search_node(tree->left, node);
    }
    else if (tree->value < node->value) {
        found_node = tree_search_node(tree->right, node);
    }
    else {
        found_node = tree;
    }
    
    return (NodeAVL *)found_node;
}

/*
 * Inicia la impresión del árbol.
 * Solo se encarga de iniciar las llamadas recursivas que imprimiran 
 * el árbol por completo.
 */
void
tree_print(const NodeAVL *const tree)
{
    printf("%d\n", tree->value);
    recursive_print(tree->right, 1, true, false);
    recursive_print(tree->left, 1, false, true);
}

/*
 * Imprime el árbol recursivamente.
 */
void
recursive_print(const NodeAVL *const root, uint8_t level,
        bool is_lower_right, bool is_last)
{
    if (root == NULL) { return; }

    /* 
     * Agregamos o quitamos un bit en el nivel donde se necesita un
     * '|'; un bit prendido en la posición x significa que x
     * necesita '│'.
     */
    static uint32_t pipes_needed = 0;
    if (is_lower_right) {
        pipes_needed = pipes_needed | (1 << (level - 1));
    } else {
        pipes_needed = pipes_needed ^ (1 << (level - 1));
    }

    indent(level, pipes_needed);
    printf("%s %d\n",
            (is_last)? "└──": "├──",
            root->value);

    bool has_lower_left = (root->left != NULL);
    bool has_lower_right = (root->right != NULL);
    if (has_lower_right && has_lower_left) {
        recursive_print(root->right, level + 1, true, false);
        recursive_print(root->left, level + 1, false, true);
    }
    else if (has_lower_right && !has_lower_left) {
        recursive_print(root->right, level + 1, true, true);
    }
    else if (!has_lower_right && has_lower_left) {
        recursive_print(root->left, level + 1, false, true);
    }
}

/*
 * Imprime las tabulaciones necesarias por nivel, siempre las 
 * tabulaciones necesarias por nivel son el nivel menos uno, ya que
 * se toma en cuenta el espacio ocupado por ├── o └──.
 */
void
indent(uint8_t level, uint32_t pipes_needed)
{
    for (uint8_t i = 0; i < level - 1; i += 1) {
        if (pipes_needed & (1 << i)) {
            printf("│   ");
        } else {
            printf("    ");
        }
    }
}

/* Devuelve la dirección del nodo encontrado en el árbol, en caso de no existir
 * devuelve NULL.
 */
NodeAVL *
tree_extract_node(NodeAVL **const tree, const NodeAVL *const node)
{
    const NodeAVL *found_node;
    if (*tree == NULL) {
        printf("Nodo no encontrado.\n");
        found_node = NULL;
    }
    else if ((*tree)->value > node->value) {
        found_node = tree_extract_node(&(*tree)->left, node);
        if (fe((NodeAVL *)found_node) >= 2)
        {
            NodeAVL *son = found_node->right;
            if (son->value  >= (*tree)->right->value)
            {
                (*tree) = RotationLeft(&(*tree));
            } else{
                (*tree)->right = RotationRight(&(*tree)->right);
                (*tree) = RotationLeft(&(*tree));
            }
            
        } 
        
    }
    else if ((*tree)->value < node->value) {
        found_node = tree_extract_node(&(*tree)->right, node);
        if (fe((*tree)) == -2)
        {
            NodeAVL *son = found_node->left;
            if (son->value  < (*tree)->left->value){
                (*tree) = RotationRight(&(*tree));
            } else{
            (*tree) -> left = RotationLeft(&(*tree) -> left);
            (*tree) = RotationRight(&(*tree));
            }
        }

    }
    else {
        found_node = *tree;

        /* Reemplazo del nodo que se extrajo. */
        if ((*tree)->left == NULL) {
            (*tree) = (*tree)->right;
        }
        else if ((*tree)->right == NULL) {
            (*tree) = (*tree)->left;
        }
        else {
            recursive_replace(tree);
        }
    }

    return (NodeAVL *)found_node;  //Deja de ser constante al momento de regresarlo
}

/*
 * Reemplaza recursivamente el nodo recibido como raíz por el mayor de los
 * menores de sus hijos.
 * La función asume que existe el hijo inferior izquierdo, por lo que es
 * preferible que la función se use únicamente cuando hay dos hijos.
 */
void
recursive_replace(NodeAVL **const root)
{
    NodeAVL *previous_node = *root;
    NodeAVL *current_node = (*root)->left;
    while(current_node->right != NULL) {
        previous_node = current_node;
        current_node = current_node->right;
    }
    (*root)->value = current_node->value;

    /* 
     * Caso: el mayor de los menores es justamente el inferior derecho
     * inmediato.
     */
    if ((*root) == previous_node) {
        previous_node->left = current_node->left;
    }
    else {
        previous_node->right = current_node->left;
    }
}

