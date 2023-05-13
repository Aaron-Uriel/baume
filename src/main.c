#include <stdio.h>

int
main(int argc, char *argv[])
{
    int option;
    if (argc > 1) {
        printf("Hola, recibí argumentos\n");
    }

    option =  menu();

    return 0;
}


int menu()
{
    int option;
    printf("═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n\t"
            "x x ⁞ Menú. x x\n\t"
            "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n\t"
            "▒┊1.- Agregar. (Crear + Insertar)\n\t"
            "▒┊2.- Quitar. (Extraer + eliminar)\n\t"
            "▒┊3.- Imprimir.\n\t"
            "▒┊4.- Preorden\n\t"
            "▒┊5.- Posorden.\n\t"
            "▒┊6.- Enorden.\n\t"
            "▒┊7.- Buscar.\n\t"
            "▒┊8.- Altura.\n\t"
            "▒┊9.- Salir.\n\t"
            "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n\t"
            "➫ ");
    scanf("%d", &option);
    return option;
}