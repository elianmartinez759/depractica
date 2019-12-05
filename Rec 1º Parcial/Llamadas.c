#include <stdio.h>
#include <stdlib.h>
#include "Llamadas.h"
#include "Persona.h"

int inicializarLlamadas(sLlamadas lista[], int cantidad)
{
    int i;
    int ret;
    if(lista != NULL && cantidad > 0)
    {
        for(i=0; i < cantidad; i++)
        {
            lista[i].estaVacio = 1;
        }
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int buscarEspacioLlamadas(sLlamadas lista[], int cantidad)
{
    int i;
    int index = -1;
    for(i=0; i<cantidad ; i++)
    {
        if( lista[i].estaVacio == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}

sLlamadas Pedir_Llamada()
{
    sLlamadas miLlamada;

    printf("Ingrese el Id de la persona que llama:");
    scanf("%d",&miLlamada.IdPersona);
    fflush(stdin);

    printf("\nIngrese el Id del destino de la llamada:");
    fflush(stdin);
    scanf("%d",&miLlamada.idDestino);

    printf("\nIngrese el tipo de llamada (larga o corta distancia):");
    fflush(stdin);
    gets(miLlamada.tipo);

    printf("\nIngrese el estado de la llamada (en curso, terminado, no se pudo concretar):");
    fflush(stdin);
    gets(miLlamada.estado);

    return miLlamada;
}

int agregarLlamadas(sLlamadas lista[], int cantidad, sPersonas listaPer[], int cantPer)
{
    int auxID;
    int auxDest;
    int indice;

    indice = buscarEspacioLlamadas(lista,cantidad);

    if(indice!=-1)
    {
        lista[indice] = Pedir_Llamada();

        auxID = EncontrarPorCodigoPer(listaPer,cantPer,lista[indice].IdPersona);
        while(auxID=-1)
        {
            printf("\nESTE ID NO EXISTE\Nescriba otro");
            scanf("%d", lista[indice].IdPersona);
        }
    }
    return indice;
}

void mostrarLlamada(sLlamadas unaLlamada)
{
    if(unaLlamada.estaVacio!=1)
    {
        printf("%02d     \t%02d\t%10s\t%10s\n",unaLlamada.IdPersona,unaLlamada.idDestino,unaLlamada.tipo,unaLlamada.estado);
    }
}

void mostrarTODASlasLlamadas(sLlamadas lista[], int cantidad)
{
    printf("ID PERS      ID LLAM        TIPO      ESTADO\n");
    int i;
    for(i=0; i<cantidad; i++)
    {
        mostrarLlamada(lista[i]);
    }
}


