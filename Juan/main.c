#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 10


/*
2- mostrar cada uno
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/


typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
}eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;

}eCliente;

typedef struct
{
    int idSerie;
    int cont;
} eLoser;

typedef struct
{
    int idCliente;
    int idSerie;
} eClientes_Series;



void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);
void mostrarSeries(eSerie[],int);
void mostrarClientes(eCliente[], int);
void mostrarClientesConSerie(eCliente[], eSerie[], int, int);
void mostrarSeriesConClientes(eCliente[], eSerie[], int, int);
void mostrarClientesTBBT(eCliente[],int);
void mostrarSerieLoser(eCliente[], eSerie[], int, int);
void mostrarSeriesporCliente(eCliente[], eSerie[],eClientes_Series[],int,int,int,char);
void cargarCliente_Serie(eClientes_Series x[]);
void mostrarSeriesporJuan(eCliente[], eSerie[],eClientes_Series[],int,int,int);

int main()
{
    eSerie series [5];
    eCliente clientes [10];
    eClientes_Series cs[10];


    char seguir='s',buscar[30];
    int opcion=0;



    cargarSeries(series);
    cargarClientes(clientes);
    cargarCliente_Serie(cs);





    while(seguir=='s')
    {
        printf("1- mostrar cada uno\n");
        printf("2- mostrar clientes con su serie\n");
        printf("3- por cada serie los clientes que la estan viendo\n");
        printf("4- todos los clientes que ven TBBT (100)\n\n");
        printf("5- La serie menos popular\n");
        printf("6- Todas las series que ven los clientes de nombre Juan\n\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                mostrarSeries(series ,5);
                printf("******************************************\n");
                mostrarClientes(clientes,10);
                printf("\n\n");
            break;
            case 2:
               // mostrarClientesConSerie(clientes,series,10,5);
            break;
            case 3:
                printf("Series\t||\tClientes\n");
                printf("*************************\n");
                 //mostrarSeriesConClientes(clientes,series,10,5);
                 printf("\n\n");
            break;
            case 4:
                //mostrarClientesTBBT(clientes,10);
                printf("\n\n");
            break;
            case 5:
                //mostrarSerieLoser(clientes,series,10,5);
                printf("\n\n");
            break;
            case 6:

                mostrarSeriesporJuan(clientes,series,cs,A,5,A);



            break;
            case 7:

                printf("Ingrese el nombre a Buscar:");
                fflush(stdin);
                gets(buscar);

                printf("%c\n\n",buscar);


               // mostrarSeriesporCliente(clientes,series,cs,A,5,A,buscar);
            break;
            case 8:
                seguir = 'n';
            break;


            }
            }




    //mostrarSerieLoser(clientes,series,10,5);



    return 0;
}


void cargarCliente_Serie(eClientes_Series x[])
{
    int i;
    eClientes_Series H[]= {{3, 100}, {1,100}, {1, 102}, {2, 101}, {1, 103}, {7,100}, {4, 103}, {4, 104}, {3, 101}, {4, 102}};
    for(i=0; i< 10; i++)
    {
        x[i] = H[i];
    }
}


void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
     char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia F","Terror","Comedia"};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];

    }

}


void mostrarSeries(eSerie series[],int cant)
{
        int i;

        printf("\tListado de Series\n\n");
        for(i=0; i<cant;i++)
        {

           printf("%d\t%s\t\t\t%s\n", series[i].idSerie,series[i].titulo,series[i].genero);

        }

}

void mostrarClientes(eCliente clientes[] , int cant)
{
    int i;

    for(i=0; i<10;i++)
    {

        printf("%d\t%s\t\t\t\n", clientes[i].idCliente, clientes[i].nombre);

    }


}

void mostrarSeriesporCliente(eCliente clientes[], eSerie series[],eClientes_Series cs[],int cantC,int cantS,int cantCS, char buscar)
{

        int i,j,k;
        int auxIdC, auxIds;





    for(i=0 ; i<cantC ; i++)
    {

    // if( clientes[i].estado!= 0 &&  stricmp( clientes[i].nombre,"juan")==0)
        if( clientes[i].estado!= 0 &&  stricmp( clientes[i].nombre,buscar)==0)

        {

           auxIdC=clientes[i].idCliente;
           printf("*********************\n");
           printf("Peliculas de %s :\n\n",clientes[i].nombre);

            for(j=0 ; j<cantCS ; j++ )
            {
                if(auxIdC== cs[j].idCliente)
                {
                    auxIds=cs[j].idSerie;

                    for(k=0; k<cantS; k++)

                    {
                        if(auxIds==series[k].idSerie)
                        {
                            printf(" %s\t%s\n",series[k].titulo,series[k].genero);

                        }

                    }
                }
            }





    }
    }




                    printf("*********************\n\n");


}

void mostrarSeriesporJuan(eCliente clientes[], eSerie series[],eClientes_Series cs[],int cantC,int cantS,int cantCS)
{

    int i,j,k;
    int auxIdC, auxIds;





    for(i=0 ; i<cantC ; i++)
    {

    // if( clientes[i].estado!= 0 &&  stricmp( clientes[i].nombre,"juan")==0)
        if( clientes[i].estado!= 0 &&  stricmp( clientes[i].nombre,"juan")==0)

        {

           auxIdC=clientes[i].idCliente;
           printf("*********************\n");
           printf("Peliculas de %s :\n\n",clientes[i].nombre);

            for(j=0 ; j<cantCS ; j++ )
            {
                if(auxIdC== cs[j].idCliente)
                {
                    auxIds=cs[j].idSerie;

                    for(k=0; k<cantS; k++)

                    {
                        if(auxIds==series[k].idSerie)
                        {
                            printf(" %s\t%s\n",series[k].titulo,series[k].genero);

                        }

                    }
                }
            }





    }
    }




                    printf("*********************\n\n");
}


/*void mostrarClientesConSerie(eCliente clientes[], eSerie series[], int cantC, int cantS)
{
    int i;
    int j;

    for(i=0; i<cantC;i++)
        {
            for(j=0; j<cantS; j++)
            {
                if( series[j].idSerie== clientes[i].idSerie )
                {
                    printf("%d\t%s\t\t%s\n",clientes[i].idCliente ,clientes[i].nombre,series[j].titulo);
                }

            }


   }
}

void mostrarSeriesConClientes(eCliente clientes[], eSerie series[], int cantC , int cantS)

{
    int i,j;

        for(i=0; i<cantS;i++)
        {
            for(j=0; j<cantC; j++)
            {
                if( series[i].idSerie== clientes[j].idSerie )
                {
                    printf("%s\t\t%s\t\n",series[i].titulo,clientes[j].nombre);
                }

            }



        }

}

void mostrarClientesTBBT(eCliente clientes[], int cantC)
{
     int i;
    printf("     clientes que ven la serie TBBT\n");
    printf("**************************************\n\n");
    for(i=0; i<cantC;i++)
    {
        if(clientes[i].idSerie==100 )
        {
             printf("%d\t%s\t\t\tTBBT\n", clientes[i].idCliente, clientes[i].nombre );
        }


    }

}

void mostrarSerieLoser(eCliente clientes[], eSerie series[], int cantC, int cantS)
{

    int i,j;
    eLoser looser [5];
    eLoser auxLooser;


    int idSerie[5]={100,101,102,103,104};
    int contador[5]={0,0,0,0,0};
    int auxCont,auxId;


    for(i=0; i<5;i++)
    {
        looser[i].idSerie = idSerie[i];
        looser[i].cont= contador[i];

    }

    for(i=0; i<cantC;i++)
    {

        for(j=0 ; j<cantS;j++)
        {

       if(clientes[i].idSerie== looser[j].idSerie )
        {

            looser[j].cont++;
        }

        }
    }

       for(i=0; i<cantS-1;i++)

        {
            for(j=i+1;j<cantS;j++)
            {
                if(looser[i].cont>looser[j].cont)
                {
                   auxLooser = looser[i];
                   looser[i] = looser[j];
                   looser[j] = auxLooser;
                }

            }

        }


             printf("  La Serie menos Popular\n");
            printf("*******************************\n");
            printf("Nombre\t||\tGenero\n\n");
    for(i=0 ; i<5 ; i++)
       {
           if( looser[0].idSerie== series[i].idSerie )
           {
              printf("%s \t\t%s\n\n", series[i].titulo,series[i].genero);

           }



       }



}

*/
