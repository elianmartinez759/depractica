#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

#define TRUE 1
#define FALSE 0

typedef struct
{
    int IdPersona;
    int idDestino;
    char tipo[31];
    char estado[51];
    int estaVacio;
}sLlamadas;

int inicializarLlamadas(sLlamadas lista[], int cantidad);

int buscarEspacioLlamadas(sLlamadas lista[], int cantidad);

sLlamadas Pedir_Llamada();


void mostrarTODASlasLlamadas(sLlamadas lista[], int cantidad);

void mostrarLlamada(sLlamadas unaLlamada);

int agregarLlamadas(sLlamadas lista[], int cantidad, sPersonas listaPer[], int cantPer);


