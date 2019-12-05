#include <stdio.h>
#include <stdlib.h>
#define CANT_LLAMADAS 10
#define CANT_PERSONAS 10
#include "Llamadas.h"
#include "Persona.h"

int main()
{
    sLlamadas listaLlamadas[CANT_LLAMADAS];
    sPersonas listaPersonas[CANT_PERSONAS];

    inicializarLlamadas(listaLlamadas,CANT_LLAMADAS);
    inicializarPersonas(listaPersonas,CANT_PERSONAS);

    HardcodearPersonas(listaPersonas,CANT_PERSONAS);

    int opcionMenu;

    do
    {
        printf("Elija una opcion:\n");
        printf("1.Alta de Personas.\n2.Baja de Personas.\n3.Modificar Personas.\n4.Alta de Llamadas.\n5.Mostrar las llamadas.\n6.salir\n");
        scanf("%d",&opcionMenu);

        switch(opcionMenu)
        {
        case 1:

            agregarPersonas(listaPersonas,CANT_PERSONAS,listaPersonas,CANT_PERSONAS);
            break;
        case 2:
            eliminarPersona(listaPersonas,CANT_PERSONAS);
            break;
        case 3:
            modificarPersona(listaPersonas,CANT_PERSONAS);
            break;
        case 4:
            mostrarTODASlasPersonas(listaPersonas,CANT_PERSONAS);
            agregarLlamadas(listaLlamadas,CANT_LLAMADAS);
            break;
        case 5:
            mostrarTODASlasLlamadas(listaLlamadas,CANT_LLAMADAS);
            break;
        }
        system("pause");
        system("cls");

    }while(opcionMenu!=6);



    return 0;
}
