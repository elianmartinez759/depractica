#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int inicializarPersonas(sPersonas lista[], int cantidad)
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

int buscarEspacioPersonas(sPersonas lista[], int cantidad)
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

sPersonas Pedir_Persona()
{
    sPersonas miPersona;

    printf("\nIngrese el numero de telefono de la persona: ");
    scanf("%d",&miPersona.telefono);
    fflush(stdin);

    printf("Ingrese el nombre de la persona: ");
    gets(miPersona.nombre);
    fflush(stdin);

    while(onlyLetters(miPersona.nombre) == -1)
    {
        printf("ERROR.reingrese nombre (solo se permiten letras): ");
        fflush(stdin);
        gets(miPersona.nombre);
    }

    printf("\nPersona ingresada.\n");

    return miPersona;
}

int agregarPersonas(sPersonas lista[], int cantidad)
{
    int indice;

    indice = buscarEspacioPersonas(lista,cantidad);

    if(indice!=-1)
    {
        lista[indice] = Pedir_Persona();

        for(indice=0 ; indice<cantidad ; indice++)
        {
            lista[indice].idPersona =  indice + 1;
        }
    }
    return indice;
}

void mostrarPersona(sPersonas unaPersona)
{
   if(unaPersona.estaVacio!=1)
   {
       printf("%02d\t%10s\t%04d\n",unaPersona.idPersona,unaPersona.nombre,unaPersona.telefono);
   }
}

void mostrarTODASlasPersonas(sPersonas lista[], int cantidad)
{
    printf("ID  NOMBRE  TELEFONO\n");
    int i;
    for(i=0; i<cantidad; i++)
    {
        mostrarPersona(lista[i]);
    }
}

int eliminarPersona(sPersonas lista[], int cantidad)
{
    int codigo;
    int index;
    int baja;

    mostrarTODASlasPersonas(lista, cantidad);
    printf("\nIngrese el id de la persona: ");
    scanf("%d",&codigo);
    index = EncontrarPorCodigoPer(lista,cantidad,codigo);
    printf("\nSeguro que quiere elimiar esta persona: \n");
    mostrarPersona(lista[index]);
    printf("\n1.Si.\n2.No\n");
    scanf("%d",&baja);

    switch(baja)
    {
    case 1:
        lista[index].estaVacio = TRUE;
        break;
    case 2:
        printf("\nCancelado.\n");
        break;
    }
    return 0;
}

int EncontrarPorCodigoPer(sPersonas lista[], int cant, int codigo)
{
    int retorno;
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].idPersona == codigo)
        {
            retorno = i;
        }else{
            retorno = -1;
        }
    }
    return retorno;
}

int modificarPersona(sPersonas lista[], int cantidad)
{
    int index;
    int mod;
    int codigo;
    int auxiliar;

    mostrarTODASlasPersonas(lista, cantidad);
    printf("\nIngrese el id de la persona: ");
    scanf("%d",&codigo);
    index = EncontrarPorCodigoPer(lista,cantidad,codigo);
    mostrarPersona(lista[index]);
    printf("\nQuiere modificar el telefono de esta persona: \n1 para SI\n2 para NO\n");
    scanf("%d",&mod);
    switch(mod)
    {
    case 1:
        printf("\Ingrese nuevo telefono: ");
        fflush(stdin);
        scanf("%d",&lista[index].telefono);
        fflush(stdin);
        printf("\Numero cambiado.\n");
        break;
    case 2:
        printf("\nCancelado.\n");
        break;
    }
    return 0;
}

void HardcodearPersonas(sPersonas lista[], int cantidad)
{
    char nombre[][31] = {"Emilio","Juana","Pedrito","Juliana"};
    int telefono[] = {4789589,45789612,45576133,45163316};
    int i;
    int indice;
    indice = buscarEspacioPersonas(lista,cantidad);
    int sumadorIds = indice + 1;

    for(i=indice; i < indice+4; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].telefono = telefono[i];
        lista[i].idPersona = sumadorIds;
        lista[i].estaVacio = FALSE;
        sumadorIds++;
    }
    return 0;
}

int onlyLetters(char string[])
{
    int length;
    int i;
    int retorno = 1;
    length = strlen(string);
    for(i = 0; i < length; i++)
    {
        if((string[i] > 90 && string[i] < 97) || string[i] < 65 || string[i] > 123)
        {
            retorno = -1;
        }
    }
    return retorno;
}
