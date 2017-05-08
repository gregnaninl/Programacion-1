#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int idPerro;
    int idRaza;
    char nombre[20];
}ePerro;

typedef struct
{
    int idRaza;
    char descripcion[20];
}eRaza;

typedef struct
{
    int idPaseador;
    char nombre[20];
}ePaseador;

typedef struct
{
    int idPaseo;
    int idPaseador;
    int idPerro;

}ePaseo;
    typedef struct
{
    int idPaseador;
    int cont;

}eMayorPaseo;


void paseosBobby(ePerro[],int,ePaseo[] ,int);
void masCantidadPaseos(eMayorPaseo[],int,ePaseo[] ,int,ePaseador[]);
void paseadoresDoberman(eRaza[] ,int, ePerro[] ,int ,ePaseo[] ,int,ePaseador[],int );
void perrosConSusRazas(ePerro[],int,eRaza[],int);
void perrosPosRaza(eRaza[],int,ePerro[],int);
void sueldoPorPaseador(eMayorPaseo[],int,ePaseo[] ,int,ePaseador[]);
int main()
{

   ePaseador plantel[] = { {1,"Juan"}, {2,"Miguel"}, {3,"Ana"}};
   ePerro perros[] = { {10,100,"Bobby"},{11,300,"Colita"},{12,200,"Rex"},{13,100,"Roberto"} };
   eRaza razas[] = { {100,"doberman"},{200,"Dogo"},{300,"Salchicha"},{400,"Boxer"}};
   ePaseo Paseos[] = { {1,1,12 }, {2,1,12},{3,2,13},{4,3,11},{5,3,12},{6,3,13} };
   eMayorPaseo mayor[] = { {1,0},{2,0},{3,0} };



    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Cuantos paseos hizo Bobby\n");
        printf("2- Cual es el paseador que mas pasea\n");
        printf("3- Paseadores que pasearon Doberman\n");
        printf("4- Perros con sus razas\n");
        printf("5- Mostrar perros por Raza\n");
        printf("6- Cuanto cobra cada Paseador\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                paseosBobby(perros,4,Paseos,6);
                printf("\n\n");
            break;
            case 2:
                masCantidadPaseos(mayor,3,Paseos,6,plantel);
                printf("\n\n");
            break;
            case 3:

               paseadoresDoberman(razas,4,perros,4,Paseos,6,plantel,3);

                 printf("\n\n");
            break;
            case 4:
                perrosConSusRazas(perros,4,razas,4);
                printf("\n\n");
            break;
            case 5:
                perrosPosRaza(razas,4,perros,4);
                printf("\n\n");
            break;
            case 6:
                sueldoPorPaseador(mayor,6,Paseos,3,plantel);
            break;
            case 7:
                seguir = 'n';

            break;

            }
            }





    return 0;
}


void paseosBobby(ePerro perros[] ,int cant,ePaseo paseos[] ,int cantP)
{

  int i,j;
  int cont=0;

  for(i=0;i<cant;i++ )
  {

      if( stricmp( perros[i].nombre ,"Bobby")==0  )
      {

          for(j=0; j<cantP; j++)
          {

              if(perros[i].idPerro == paseos[j].idPerro  )
              {
                  cont++;
              }

          }

      }

  }

        printf("Bobby Realizo %d paseos",cont);




}

void masCantidadPaseos(eMayorPaseo mayor[] ,int z,ePaseo paseos[] ,int y,ePaseador plantel[]  )
{
    int i,j;
    int max;

    printf("Maxima cantidad de paseos\n\n");


    for( i=0; i<6 ; i++ )
    {
        for(j=0; j<3 ; j++)
        {
            if(paseos[i].idPaseador==mayor[j].idPaseador)
            {
                mayor[j].cont++;
             }
         }
    }

    max=mayor[0].cont;

    for(i=0; i<z ; i++)
    {
        if(mayor[i].cont>max)
        {
            max=mayor[i].cont;
        }
    }


    for(i=0 ; i<z; i++)
    {

        if(mayor[i].cont==max)
        {
            for(j=0 ; j<z; j++)
            {
               if( mayor[i].idPaseador == plantel[j].idPaseador  )

               {
                   printf("Paseador: %s\t%d Paseos\n\n",plantel[j].nombre,mayor[j].cont);
               }

            }

        }

    }


}

void paseadoresDoberman(eRaza razas[] ,int cantR ,   ePerro perros[] ,int cantPe  ,ePaseo paseos[] ,int cantPs,ePaseador plantel[],int cantPl  )

{

    int i,j,k,q;

    printf("***Paseadores que pasean Doberman*****\n\n");

    for(i=0; i<cantR;i++)
    {
        if( stricmp (razas[i].descripcion,"doberman")==0)
         {
              for(j=0; j<cantPe;j++)
            {
                if(razas[i].idRaza==perros[j].idRaza)
                {
                    for(k=0;k<cantPs; k++)
                    {
                        if(perros[j].idPerro== paseos[k].idPerro)
                        {

                           for( q=0;q<cantPl;q++)
                           {
                               if(paseos[k].idPaseador==plantel[q].idPaseador )
                               {
                                   printf("*\t%s\n",plantel[q].nombre);
                                   break;
                               }
                           }

                        }
                    }

                }
            }

        }
     break;

    }


}

void perrosConSusRazas(ePerro perros[],int cantPe,eRaza razas[],int cantRa)
{

    int i,j;

    printf("******Perros con Sus Razas******\n\n");

    for(i=0; i<cantPe;i++)

    {
        for(j=0; j<cantRa; j++)
        {
            if( perros[i].idRaza==razas[j].idRaza  )
            {
                printf("Nombre: %s\tRaza: %s\n",perros[i].nombre,razas[j].descripcion);
            }

        }


    }

}

void perrosPosRaza(eRaza razas[],int cantRa,ePerro perros[],int cantPe)
{
    int i,j;


    printf("*******Perros por Raza******\n");

    for(i=0; i<cantRa;i++)
    {
          printf("\nRaza:%s\n",razas[i].descripcion);
        for(j=0; j<cantPe; j++)
        {
            if(razas[i].idRaza==perros[j].idRaza)
            {
                printf("%s\n",perros[j].nombre);
            }


        }


    }




}

void sueldoPorPaseador(eMayorPaseo mayor[],int cantPs,ePaseo paseos[] ,int cantpl,ePaseador plantel[])
{
     int i,j;
     int sueldo;

    printf("Sueldo Por Paseador\n\n");


    for( i=0; i<cantPs ; i++ )
    {
        for(j=0; j<cantpl ; j++)
        {
            if(paseos[i].idPaseador==mayor[j].idPaseador)
            {
                mayor[j].cont++;
             }
         }
    }

    for(i=0;i<cantpl;i++ )
    {
        for(j=0;j<cantpl;j++)
        {
            if( plantel[i].idPaseador==mayor[j].idPaseador)
            {
                sueldo = mayor[j].cont * 100;
                printf("%s\t$%d\n",plantel[i].nombre,sueldo);
            }
        }
    }


    printf("\n\n");
}




