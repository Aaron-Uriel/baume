#include <stdio.h>

int
main(int argc, char *argv[])
{
    int option;
    if (argc > 1) {
        printf("Hola, recibí argumentos\n");
    }

    
    do
    {
        option =  menu();

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
}