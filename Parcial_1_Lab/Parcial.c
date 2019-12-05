#include "Parcial.h"

void toLowerCase(char string[])
{
    int length;
    int i;
    length = strlen(string);
    for(i = 1; i < length; i++)
    {
        if(string[i] > 64 && string[i] < 91)
        {
            string[i] = string[i] + 32;
        }
    }
}

void firstLetterToUpperCase(char letter[])
{
    if(letter[0] > 96 && letter[0] < 123)
    {
        letter[0] = letter[0] -32;
    }
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


sEquipos agregarEquipos() /// <-- funcion agregar equipos.
{
    sEquipos miEquipo;
    printf("Nombre de su equipo: ");
    fflush(stdin);
    gets(miEquipo.nombre);
    while(onlyLetters(miEquipo.nombre) == -1)
    {
        printf("ERROR.reingrese nombre (solo se permiten letras): ");
        fflush(stdin);
        gets(miEquipo.nombre);
    }
    printf("Localidad de su equipo: ");
    fflush(stdin);
    gets(miEquipo.localidad);
    while(onlyLetters(miEquipo.localidad) == -1)
    {
        printf("ERROR.reingrese localidad (solo se permiten letras): ");
        fflush(stdin);
        gets(miEquipo.localidad);
    }
    //miEquipo.vacio = 0;

    return miEquipo;
}

sJugadores agregarJugadores() /// <-- funcion agregar jugadores.
{
    sJugadores unJugador;
    printf("Nombre del jugador: ");
    fflush(stdin);
    gets(unJugador.nombre);
    while(onlyLetters(unJugador.nombre) == -1)
    {
        printf("ERROR.reingrese nombre (solo se permiten letras): ");
        fflush(stdin);
        gets(unJugador.nombre);
    }
    printf("Apellido del jugador: ");
    fflush(stdin);
    gets(unJugador.apellido);
    while(onlyLetters(unJugador.apellido) == -1)
    {
        printf("ERROR.reingrese apellido (solo se permiten letras): ");
        fflush(stdin);
        gets(unJugador.apellido);
    }

    return unJugador;
}
void printEquipos(sEquipos lista[], int cant)
{
    printf("COD    NOMBRE    LOCALIDAD\n");
    int i;
    for(i=0; i<cant; i++)
    {
        printEquipo(lista[i]);
    }
}

void printEquipo(sEquipos unEquipo)
{
    if(unEquipo.vacio!=1)
    {
        printf("%04d\t%20s\t%20s\t\n",unEquipo.codigo,
                                      unEquipo.nombre,
                                      unEquipo.localidad);
    }

}

void mostrarJugadores(sJugadores lista[], int cant)
{
    printf("COD        APELLIDO      EQUIPO   SEXO    F.NACIMIENTO   NOMBRE\n");
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].vacio == TRUE)
        {
            printJugador(lista[i]);
        }
    }
}

void printJugador(sJugadores unJugador)
{
    if(unJugador.vacio==0)
    {
        printf("%d\t   %s\t   %02d\t   %c\t  %d/%d/%d\t %s\n",unJugador.codigo,
                                                            unJugador.apellido,
                                                            unJugador.codigoDeEquipo,
                                                            unJugador.sexo,
                                                            unJugador.fechaDeNacimiento.dia,
                                                            unJugador.fechaDeNacimiento.mes,
                                                            unJugador.fechaDeNacimiento.anio,
                                                            unJugador.nombre);
    }
}


void MostrarReferis(sReferis lista[], int cant)
{
    printf("COD        NOMBRE          APELLIDO       SEXO    F.NACIMIENTO\n");
    int i;
    for(i=0; i<cant; i++)
    {
        printReferi(lista[i]);
    }
}


void printReferi(sReferis unReferi)
{
    printf("%d\t   %s\t   %s\t  %c\t  %d/%d/%d\n",unReferi.codigo,
                                                  unReferi.nombre,
                                                  unReferi.apellido,
                                                  unReferi.sexo,
                                                  unReferi.fechaDeNacimiento.dia,
                                                  unReferi.fechaDeNacimiento.mes,
                                                  unReferi.fechaDeNacimiento.anio);
}

void MostrarPartidos(sPartidos lista[], int cant)
{
    printf("COD     COD.L   COD.V   COD.R    FECHA\n");
    int i;
    for(i=0; i<cant; i++)
    {
        printPartido(lista[i]);
    }
}

void printPartido(sPartidos unPartido)
{
    printf("%d\t  %d\t  %d\t  %d\t  %d/%d/%d\n",unPartido.codigo,
                                                unPartido.codigoEquipoLocal,
                                                unPartido.codigoEquipoVisitante,
                                                unPartido.codigoReferi,
                                                unPartido.fechaDePartido.dia,
                                                unPartido.fechaDePartido.mes,
                                                unPartido.fechaDePartido.anio);
}

void hardcodearEquipos(sEquipos unosEquipos[], int cant)
{
    int indice;
    indice = buscarVacio(unosEquipos,cant);
    int sumadorIds = indice + 1;

    int i;
 //   int codigo[] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[][51] = {"Cambios FC","Camboya","Dep Muy Caliente","Hacha y Birra","Bidon de Branco","Real Coholicos","Suc Congreso","Sucursal Flores","Los Isotopos","Ornad"};
    char localidad[][33] = {"Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield"};

    for(i=indice ;i<indice+10;i++)
    {
        unosEquipos[i].codigo = sumadorIds;
        strcpy(unosEquipos[i].nombre, nombre[i]);
        strcpy(unosEquipos[i].localidad, localidad[i]);
        unosEquipos[i].vacio = FALSE;
        sumadorIds++;
    }
    printf("\nEquipos harcodeados.\n");
}

void hardcodearJugadores(sJugadores unosJugadores[], int cant)
{
    char nombre[][31] = {"JUAN","JOSÉ LUIS","JOSÉ    ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA    ","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL","JUAN","JOSÉ LUIS","JOSÉ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL","JUAN","JOSÉ LUIS","JOSÉ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL","JUAN","JOSÉ LUIS","JOSÉ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL","JUAN","JOSÉ LUIS","JOSÉ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL","JUAN","JOSÉ LUIS","JOSÉ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL","JUAN","JOSÉ LUIS","JOSÉ","MARÍA GUADALUPE","FRANCISCO","GUADALUPE","MARÍA","JUANA","ANTONIO","JESÚS","MIGUEL ÁNGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARÍA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTÍN","RAÚL","DAVID","JOSEFINA","JOSÉ ANTONIO","ARTURO","MARCO ANTONIO","JOSÉ MANUEL"};
    char apellido[][31] = {"González","Rodríguez","Gómez","Fernández","López","Díaz ","Martínez","Pérez","Romero","Sánchez","García","Sosa ","Torres","Ramírez","Álvarez","Benítez","Acosta","Flores","Medina","Ruiz ","González","Rodríguez","Gómez","Fernández","López","Díaz ","Martínez","Pérez","Romero","Sánchez","García","Sosa ","Torres","Ramírez","Álvarez","Benítez","Acosta","Flores","Medina","Ruiz ","González","Rodríguez","Gómez","Fernández","López","Díaz ","Martínez","Pérez","Romero","Sánchez","García","Sosa ","Torres","Ramírez","Álvarez","Benítez","Acosta","Flores","Medina","Ruiz "};
    int codigoDeEquipo[] = {1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10};
    char sexo[] = {'M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M','M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M','M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M','M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M'};
    int dia[] = {25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22};
    int anio[] = {2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995};
    int mes[] = {1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1};
    int id = 0;
    int i;

    for(i=0; i<cant; i++)
    {
        strcpy(unosJugadores[i].nombre, nombre[i]);
        strcpy(unosJugadores[i].apellido, apellido[i]);
        unosJugadores[i].codigoDeEquipo = codigoDeEquipo[i];
        unosJugadores[i].sexo = sexo[i];
        unosJugadores[i].fechaDeNacimiento.dia = dia[i];
        unosJugadores[i].fechaDeNacimiento.anio = anio[i];
        unosJugadores[i].fechaDeNacimiento.mes = mes[i];
        id++;
        unosJugadores[i].codigo = id;
        unosJugadores[i].vacio = TRUE;
    }
    printf("\nJugadores hardcodeados\n");
}

void hardcodearReferis(sReferis unosReferis[], int cant)
{
    char nombre[][31] = {"Nicolás","Nazareno","Darío","Fernando","Gisella","Yael     "};
    char apellido[][31] = {"Lamolina","Arasa","Herrera","Espinoza","Trucco","Falcón Pérez"};
    char sexo[] = {'M','M','M','M','F','F'};
    char eMail[][31] = {"NicolasL@gmail.com","NazarenoArasa@gmail.com","DHerrera@gmail.com","FerEsp@gmail.com","GisellaTrucco1@gmail.com","FalconVerde@gmail.com"};
    int dia[] = {15,5,20,22,12,1};
    int mes[] = {8,10,5,6,6,2};
    int anio[] = {1980,1981,1975,1970,1986,1989};
    int id = 0;
    int i;

    for(i=0; i<cant; i++)
    {
        strcpy(unosReferis[i].nombre, nombre[i]);
        strcpy(unosReferis[i].apellido, apellido[i]);
        unosReferis[i].sexo = sexo[i];
        strcpy(unosReferis[i].eMail, eMail[i]);
        unosReferis[i].fechaDeNacimiento.dia = dia[i];
        unosReferis[i].fechaDeNacimiento.mes = mes[i];
        unosReferis[i].fechaDeNacimiento.anio = anio[i];
        id++;
        unosReferis[i].codigo = id;
    }
    printf("\nReferis hardcodeados\n");
}

void hardcodearPartidos(sPartidos unosPartidos[], int cant)
{
    int codigo = 0;
    int codigoEquipoVisitante[] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
    int codigoEquipoLocal[] = {10,9,8,7,6,4,3,2,1,5,8,7,6,10,9,2,1,5,4,3,6,10,9,8,7};
    int codigoReferi[] = {1,2,6,4,5,1,2,3,4,6,6,2,3,4,5,1,6,3,4,5,1,2,3,6,5};
    int dia[] = {21,21,21,21,21,28,28,28,28,28,5,5,5,5,5,12,12,12,12,12,19,19,19,19,19};
    int mes[] = {9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    int anio[] = {2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};

    int i;
    for(i=0; i<cant; i++)
    {
        codigo++;
        unosPartidos[i].codigo = codigo;
        unosPartidos[i].codigoEquipoVisitante = codigoEquipoVisitante[i];
        unosPartidos[i].codigoEquipoLocal = codigoEquipoLocal[i];
        unosPartidos[i].codigoReferi = codigoReferi[i];
        unosPartidos[i].fechaDePartido.dia = dia[i];
        unosPartidos[i].fechaDePartido.mes = mes[i];
        unosPartidos[i].fechaDePartido.anio = anio[i];
    }
    printf("Partidos hardcodeados.\n");
}







void ordenarEquiposPorNombre(sEquipos unosEquipos[], int cant)
{
    int i;
    int j;
    sEquipos aux;

    for(i=0; i< cant ; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmpi(unosEquipos[i].nombre, unosEquipos[j].nombre) > 0)
            {
                aux = unosEquipos[i];
                unosEquipos[i] = unosEquipos[j];
                unosEquipos[j] = aux;
            }
        }
    }
}

void ordenarJugadoresPorApellido(sJugadores unosJugadores[], int cant)
{
    int i;
    int j;
    sJugadores aux;

    for(i=0; i< cant ; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmpi(unosJugadores[i].apellido, unosJugadores[j].apellido) > 0)
            {
                aux = unosJugadores[i];
                unosJugadores[i] = unosJugadores[j];
                unosJugadores[j] = aux;
            }
        }
    }
}

void ordenarReferisPorApellido(sReferis unosReferis[], int cant)
{
    int i;
    int j;
    sReferis aux;

    for(i=0; i< cant ; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmpi(unosReferis[i].apellido, unosReferis[j].apellido) > 0)
            {
                aux = unosReferis[i];
                unosReferis[i] = unosReferis[j];
                unosReferis[j] = aux;
            }
        }
    }
}

void ordenarPartidosPorFecha(sPartidos unosPartidos[], int  cant)
{
    int i;
    int j;
    sPartidos aux;
    for(i=0; i< cant ; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(unosPartidos[i].fechaDePartido.mes > unosPartidos[j].fechaDePartido.mes)
            {
                if(unosPartidos[i].fechaDePartido.dia > unosPartidos[j].fechaDePartido.dia)
                {
                    aux = unosPartidos[i];
                    unosPartidos[i] = unosPartidos[j];
                    unosPartidos[j] = aux;
                }
            }
        }
    }
}

int EncontrarPorCodigo(sEquipos unEquipo[], int cant, int codigo)
{
    int retorno;
    int i;
    for(i=0; i<cant; i++)
    {
        if(unEquipo[i].codigo == codigo)
        {
            retorno = i;
        }
    }
    return retorno;
}

void ModificarEquipo(sEquipos listaEquipos[], int cant)
{
    int codigo;
    int index;
    int mod;

    printEquipos(listaEquipos, cant);
    printf("\nIngrese el codigo del equipo: ");
    scanf("%d",&codigo);
    index = EncontrarPorCodigo(listaEquipos,cant,codigo);
    while(mod != 3)
    {
        printf("COD    NOMBRE    LOCALIDAD\n");
        printEquipo(listaEquipos[index]);
        printf("\n1.Modificar nombre.\n2.Modificar localidad,\n");
        scanf("%d",&mod);
        switch(mod)
        {
        case 1:
            printf("\nIngrese nuevo nombre: ");
            fflush(stdin);
            gets(listaEquipos[index].nombre);
            printf("\nNombre cambiado con exito.");
            break;
        case 2:
            printf("\nIngrese nueva localidad: ");
            fflush(stdin);
            gets(listaEquipos[index].localidad);
            printf("\nLocalidad cambiada con exito.");
            break;
        default:
            printf("\nOpcion no validad!!.");
        }
    }
}

int EncontrarPorCodigoJugador(sJugadores unJugador[], int cant, int codigo)
{
    int retorno;
    int i;
    for(i=0; i<cant; i++)
    {
        if(unJugador[i].codigo == codigo)
        {
            retorno = i;
        }
    }
    return retorno;
}



int ElimiarEquipo(sEquipos listaEquipos[], int cant)
{
    int codigo;
    int index;
    int baja;

    printEquipos(listaEquipos, cant);
    printf("\nIngrese el codigo del equipo: ");
    scanf("%d",&codigo);
    index = EncontrarPorCodigo(listaEquipos,cant,codigo);
    printf("\nSeguro que quiere elimiar el siguiente equipo: \n");
    printEquipo(listaEquipos[index]);
    printf("\n1.Si.\n2.No\n");
    scanf("%d",&baja);

    if(baja = 1)
    {
        listaEquipos[index].vacio = TRUE;
        return 0;
    }else
    {
        return 0;
    }
}

int EliminarJugador(sJugadores listaJugadores[], int cant)
{
    int codigo;
    int index;
    int baja;

    mostrarJugadores(listaJugadores, cant);
    printf("\nIngrese el codigo del jugador: ");
    scanf("%d",&codigo);
    index = EncontrarPorCodigoJugador(listaJugadores,cant,codigo);
    printf("\nSeguro que quiere elimiar el siguiente jugador: \n");
    printJugador(listaJugadores[index]);
    printf("\n1.Si.\n2.No\n");
    scanf("%d",&baja);

    if(baja = 1)
    {
        listaJugadores[index].vacio = FALSE;
        return 0;
    }else
    {
        return 0;
    }
}

int buscarVacio(sEquipos list[],int len)
{
    int index = -1;
    for(int i=0; i<len ; i++)
    {
        if( list[i].vacio == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}

int initEquipos(sEquipos list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            list[i].vacio = 1;
        }
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int addEquipos(sEquipos lista[], int cantidad)
{
    int indice;
    indice = buscarVacio(lista,cantidad);

    if(indice!=-1)
    {
        lista[indice] = agregarEquipos();

        for(indice = 0 ; indice < cantidad ; indice++)
        {
            //listing[indice].id =  indice;
            lista[indice].codigo =  indice + 1;
        }
    }
    return indice;
}




