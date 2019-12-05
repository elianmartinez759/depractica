#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef struct /// <-- Estructura fecha.
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct /// <-- Estructura de equipos.
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int vacio;
}sEquipos;

typedef struct /// <-- Estructura de jugadores.
{
    int codigo;
    char nombre[31];
    char apellido[31];
    int codigoDeEquipo;
    char sexo;
    sFecha fechaDeNacimiento;
    int vacio;
}sJugadores;

typedef struct /// <-- Estructura de referis.
{
    int codigo;
    char nombre[31];
    char apellido[31];
    char sexo;
    char eMail[31];
    sFecha fechaDeNacimiento;
    int vacio;
}sReferis;

typedef struct /// <-- Estructura de partidos.
{
    int codigo;
    int codigoEquipoVisitante;
    int codigoEquipoLocal;
    int codigoReferi;
    sFecha fechaDePartido;
    int vacio;
}sPartidos;


void toLowerCase(char[]);

void firstLetterToUpperCase(char[]);

int onlyLetters(char[]);

void ordenarJugadoresPorApellido(sJugadores unosJugadores[], int cant);

void ordenarEquiposPorNombre(sEquipos unosEquipos[], int cant);

void hardcodearJugadores(sJugadores unosJugadores[], int cant);

void hardcodearEquipos(sEquipos unosEquipos[], int cant);

void printJugador(sJugadores unJugador);

void mostrarJugadores(sJugadores lista[], int cant);

void printEquipo(sEquipos unEquipo);

void printEquipos(sEquipos lista[], int cant);

void printPartido(sPartidos unPartido);

void printReferi(sReferis unReferi);

void MostrarReferis(sReferis lista[], int cant);

void hardcodearReferis(sReferis unosReferis[], int cant);

void hardcodearPartidos(sPartidos unosPartidos[], int cant);

void ordenarReferisPorApellido(sReferis unosReferis[], int cant);

void ordenarPartidosPorFecha(sPartidos unosPartidos[], int  cant);

void MostrarPartidos(sPartidos lista[], int cant);

int EncontrarPorCodigo(sEquipos unEquipo[], int cant, int codigo);
