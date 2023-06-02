#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#include <baume.h>

/* Prototipos. */
int menu();

/* Función vacía por lo mientras. */
void tree_insert_node(Node *const *tree, const Node *const node) {
    printf("Insertado %d", node->value);
}

bool is_int(char *str);

int32_t
main(int argc, char *argv[])
{
    Node *tree;

    if (argc > 1) {
        Node *tmp_node;
        int32_t number, i;
        for (i = 1; i < argc; i += 1) {
            if (is_int(argv[i]) != true) {
                printf("El argumento %s no es un número.\n", argv[i]);
                continue;
            }

            number = atoi(argv[i]);
            tmp_node = nodeNew(number);
            tree_insert_node(&tree, tmp_node);
        }
        nodeDelete(&tmp_node);
    }
    int option;
    
    do
    {
        option = menu();

        switch (option)
        {
        case 1:     //Agregar. (Crear + Insertar) 
            /* code */
            break;

        case 2:     //Quitar. (Extraer + Eliminar) 
            /* code */
            break;

        case 3:     //Imprimir. 
            /* code */
            break;

        case 4:     //Enorden. 
            /* code */
            break;              
        
        case 5:     //Preorden. 
            /* code */
            break;

        case 6:     //Posorden. 
            /* code */
            break;

        case 7:     //Buscar. 
            /* code */
            break; 

        case 8:     //Altura. 
            /* code */
            break;

        case 9:     //Salir
            break;    
        default:
            printf("\n\t✘ Opción inválida. ✘\n\n");
            break;
        }

    } while (option != 9);
    

    return 0;
}


int menu()
{
    int option;
    printf("═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n\t"
            "x x ⁞ Menú. x x\n\t"
            "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n\t"
            "▒┊1.- Agregar. (Crear + Insertar)\n\t"
            "▒┊2.- Quitar. (Extraer + Eliminar)\n\t"
            "▒┊3.- Imprimir.\n\t"
            "▒┊4.- Enorden\n\t"
            "▒┊5.- Preorden.\n\t"
            "▒┊6.- Posorden.\n\t"
            "▒┊7.- Buscar.\n\t"
            "▒┊8.- Altura.\n\t"
            "▒┊9.- Salir.\n\t"
            "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n\t"
            "➫ ");
    scanf("%d", &option);
    return option;

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
