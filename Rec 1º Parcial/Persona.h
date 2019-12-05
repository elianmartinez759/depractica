#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
    int idPersona;
    char nombre[31];
    int telefono;
    int estaVacio;
}sPersonas;

int inicializarPersonas(sPersonas lista[], int cantidad);

int buscarEspacioPersonas(sPersonas lista[], int cantidad);

sPersonas Pedir_Persona();

int agregarPersonas(sPersonas lista[], int cantidad);

void mostrarPersona(sPersonas unaPersona);

void mostrarTODASlasPersonas(sPersonas lista[], int cantidad);

int eliminarPersona(sPersonas lista[], int cantidad);

void HardcodearPersonas(sPersonas lista[], int cantidad);
