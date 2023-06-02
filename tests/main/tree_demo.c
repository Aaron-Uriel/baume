#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#include <baume.h>


/* Globales, enumeraciones y estructuras. */
enum MenuOptions { 
    ADD = 1, REMOVE, PRINT, PREORDER, INORDER, POSTORDER, SEARCH, HEIGHT, EXIT
};

/* Prototipos. */
enum MenuOptions menu(void);
bool is_int(char *str);

int32_t
main(int argc, char *argv[])
{
    NodeAVL *tree = NULL;

    if (argc > 1) {
        NodeAVL *tmp_node = nodeNewAVL(0);
        int32_t number, i;
        for (i = 1; i < argc; i += 1) {
            if (is_int(argv[i]) != true) {
                printf("El argumento %s no es un número.\n", argv[i]);
                continue;
            }

            number = atoi(argv[i]);
            tmp_node->value = number;
            avlInsertNode(&tree, tmp_node);
        }
        avlNodeDelete(&tmp_node);
    }
    
    NodeAVL *tmp_node;
    NodeAVL dummy_node = { 0 };        /* Solo se utiliza su value para buscar. */
    enum MenuOptions opt;
    do {
        opt = menu();

        switch (opt) {
        case ADD:
            printf("Ingrese el valor del nodo a insertar: ");
            scanf("%d", &dummy_node.value);
            avlInsertNode(&tree, nodeNewAVL(dummy_node.value));
            break;

        case REMOVE:
            printf("¿Qué nodo desea eliminar?: ");
            scanf("%d", &dummy_node.value);

            tmp_node = tree_extract_node(&tree, &dummy_node);
            if (tmp_node == NULL) {
                printf("El nodo con valor %d no existe.\n", dummy_node.value);
            }
            else {
                avlNodeDelete(&tmp_node);
                printf("Nodo con valor %d eliminado.\n", dummy_node.value);
            }
            break;

        case PRINT:
            tree_print(tree);
            break;

        case PREORDER:
            printf("Recorrido en preorden: ");
            preorder(tree);
            break;

        case INORDER:
            printf("Recorrido en enorden: ");
            inorder(tree);
            break;              

        case POSTORDER:
            printf("Recorrido en postorden: ");
            inorder(tree);
            break;

        case SEARCH:
            printf("¿Qué valor desea buscar?: ");
            scanf("%d", &dummy_node.value);
            tmp_node = tree_search_node(tree, &dummy_node);
            printf("El nodo con valor %d: %s.\n",
                    dummy_node.value,
                    (tmp_node != NULL)? "existe": "no existe");
            break; 

        case HEIGHT:
            printf("La altura del árbol es %d", tree_height(tree));
            break;

        case EXIT:
            exit(0);
            break;    
        }

        printf("Presione Enter para continuar...");
        while (getchar() != '\n');
        while (getchar() != '\n');

    } while (opt != EXIT);

    return 0;
}


enum MenuOptions
menu(void)
{
    enum MenuOptions opt;
    uint8_t succesfull_inputs;
    do {
        opt = 0;

        printf("═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n"
                "x x ⁞ Menú. x x\n"
                "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n"
                "▒┊1.- Agregar. (Crear + Insertar)\n"
                "▒┊2.- Quitar. (Extraer + Eliminar)\n"
                "▒┊3.- Imprimir.\n"
                "▒┊4.- Preorden.\n"
                "▒┊5.- Enorden\n"
                "▒┊6.- Postorden.\n"
                "▒┊7.- Buscar.\n"
                "▒┊8.- Altura.\n"
                "▒┊9.- Salir.\n"
                "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n"
                "➫ ");
        succesfull_inputs = scanf("%d", (int *)&opt);

        if (opt < 1 || opt > EXIT || succesfull_inputs != 1) {
            printf("Opción inválida.\n");
            while (getchar() != '\n');
            continue;
        }
    } while (false);

    return opt;
}

bool
is_int(char *str)
{
    for (uint32_t i = 0; str[i] != '\0'; i += 1) {
        if (isdigit(str[i]) == false && str[i] != '-') {
            return false;
        }
    }
    return true;
}
