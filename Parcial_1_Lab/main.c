#include "Parcial.h"
#define CANT_EQUIPOS 100
#define CANT_JUGADORES 60
#define CANT_REFERIS 6
#define CANT_PARTIDOS 25


int main()
{
    sEquipos listaEquipos[CANT_EQUIPOS];
    sJugadores listaJugadores[CANT_JUGADORES];
    sReferis listaReferis[CANT_REFERIS];
    sPartidos listaPartidos[CANT_PARTIDOS];

    initEquipos(listaEquipos,CANT_EQUIPOS);

    int option;
    int opcionEquipos;
    int opcionJugadores;
    int opcionReferis;
    int opcionPartidos;
    /*int retorno;
    int codigoEquipos = 1;
    int codigoJugadores = 1;
    int codigoReferis = 1;
    int codigoPartidos = 1;
    int baja;
    int mod;
    int orden;
    int submenu;*/

        do
        {
            printf("\nElija una opcion\n");
            printf("1.Menu Equipos\n2.Menu Jugadores\n3.Menu Referis\n4.Menu Partidos\n5.SALIR\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                printf("\nMenu equipos.\n\n1.Cargar equipos (Hardcodear).\n2.Listar equipos (orden alfabetico).\n3.Modificar equipos.\n4.Borrar equipo.\n5.Agregar equipo.\n");
                scanf("%d",&opcionEquipos);
                switch(opcionEquipos)
                {
                case 1:
                    hardcodearEquipos(listaEquipos, CANT_EQUIPOS);
                    break;
                case 2:
                    ordenarEquiposPorNombre(listaEquipos, CANT_EQUIPOS);
                    printEquipos(listaEquipos, CANT_EQUIPOS);
                    break;
                case 3:
                    ModificarEquipo(listaEquipos, CANT_EQUIPOS);
                    break;
                case 4:
                    ElimiarEquipo(listaEquipos, CANT_EQUIPOS);
                    break;
                case 5:
                    addEquipos(listaEquipos,CANT_EQUIPOS);
                    break;
                }
                break;

            case 2:
                printf("\nMenu jugadores.\n\n1.Cargar jugadores (Hardcodear).\n2.Listar jugadores (orden alfabetico).\n3.Borrar jugador.\n");
                scanf("%d",&opcionJugadores);
                switch(opcionJugadores)
                {
                case 1:
                    hardcodearJugadores(listaJugadores, CANT_JUGADORES);
                    break;
                case 2:
                    ordenarJugadoresPorApellido(listaJugadores, CANT_JUGADORES);
                    mostrarJugadores(listaJugadores, CANT_JUGADORES);
                    break;
                case 3:
                    EliminarJugador(listaJugadores, CANT_JUGADORES);
                    break;
                }
                break;
            case 3:
                printf("\nMenu referis.\n\n1.Cargar referis (Hardcodear).\n2.Listar referis (orden alfabetico).\n");
                scanf("%d",&opcionReferis);
                switch(opcionReferis)
                {
                case 1:
                    hardcodearReferis(listaReferis, CANT_REFERIS);
                    break;
                case 2:
                    ordenarReferisPorApellido(listaReferis, CANT_REFERIS);
                    MostrarReferis(listaReferis, CANT_REFERIS);
                    break;
                }
                break;
            case 4:
                printf("\nMenu de partidos.\n\n1.Cargar partidos (Hardcodear).\n2.Listar partidos por fecha.ºn");
                scanf("%d",&opcionPartidos);
                switch(opcionPartidos)
                {
                case 1:
                    hardcodearPartidos(listaPartidos, CANT_PARTIDOS);
                    break;
                case 2:
                    ordenarPartidosPorFecha(listaPartidos, CANT_PARTIDOS);
                    MostrarPartidos(listaPartidos, CANT_PARTIDOS);
                    break;
                }
                break;
            }
            system("pause");
            system("cls");
        }
        while(option != 5);
}
