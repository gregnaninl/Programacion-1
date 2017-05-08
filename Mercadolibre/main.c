#include <stdio.h>
#include <stdlib.h>
#define A 5
#define P 6



typedef struct
{
    int idUser;
    int estado;
    char usuario[20];
    char nombre[30];
    char apellido[30];
    float calificacion;
}eUsuario;


typedef struct
{
    int idProducto;
    int idUser;
    int estado;
    char nombre[20];
    int precio;
    int stock;
    int vendidos;
}eProducto;

typedef struct
{
    int idProducto;
    int idUser;

}eCompra;

int  obtenerEspacioLibre(eUsuario[]);
int  buscarIdUser(eUsuario[], int);
int  obtenerEspacioLibreProducto(eProducto[]);



int main()
{
    eUsuario usuarios[A]={{1,1,"Lgregna","leandro","Gregnanin",0},{2,1,"Ggomez","Gonzalo","Gomez",0},{3,1,"Mperez","Martin","Perez",0},{4,1,"Jlopez","Juan","Lopez",0} };
    eProducto productos[P]={{ 1,2,1,"Amoladora",1500,10,5},{ 2,2,1,"Martillo",120,3,1},{ 3,1,1,"Destornillador",50,20,18},{4,4,1,"Alicate",170,10,5},{ 5,3,1,"Ahujereadora",800,10,2}} ;

    int i,auxInt,j;
    int id,auxProducto;

    char respuesta='s';
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1-  Alta de Usuarios\n");
        printf("2-  Modificar datos de usuario\n");
        printf("3-  Baja de usuario\n");
        printf("4-  Publicar productos\n");
        printf("5-  Modificar publicacion\n");
        printf("6-  Cancelar publicacion\n");
        printf("7-  Comprar producto\n");
        printf("8-  Listar publicacions de usuario\n");
        printf("9-  Listar publicaciones\n");
        printf("10- Listar usuarios\n");
        printf("11- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:


                auxInt= obtenerEspacioLibre(usuarios);

                  if(auxInt>0)
                    {

                        usuarios[auxInt].idUser=auxInt+1;
                        printf("Ingrese Nombre de Usuario:\n");
                        fflush(stdin);
                        gets(usuarios[auxInt].usuario);
                        printf("Datos Personales\n");
                        printf("Nombre:\n");
                        fflush(stdin);
                        gets(usuarios[auxInt].nombre);
                        printf("Ingrese Apellido:\n");
                        fflush(stdin);
                        gets(usuarios[auxInt].apellido);
                        usuarios[auxInt].estado=1;
                    }
                    else
                    {
                        printf(" *************ALERTA********************\n");
                        printf(" *                                     *\n");
                        printf(" *  No se pueden agregar mas usuarios  *\n");
                        printf(" *                                     *\n");
                        printf(" ***************************************\n\n");
                    break;
                    }

                printf("\n\n");
                break;
            case 2:
                    printf("Ingrese Numero de Id\n\n");
                    fflush(stdin);
                    scanf("%d", &id);

                    auxInt=buscarIdUser(usuarios,id);
                    if(usuarios[auxInt].estado==1)
                    {
                    printf("Esta seguro que desea modifica el id:\n\n");
                    printf(" User\tNombre\t Apellido\tCalificacion\n\n");
                    printf("%s\t%s\t %s\t\t%.2f\n\n\n",usuarios[auxInt].usuario,usuarios[auxInt].nombre,usuarios[auxInt].apellido,usuarios[auxInt].calificacion);
                    respuesta=getche();

                    if(respuesta=='s')
                        {
                          printf("\nIngrese Nombre de Usuario:\n");
                          fflush(stdin);
                          gets(usuarios[auxInt].usuario);
                          printf("Datos Personales\n");
                          printf("Nombre:\n");
                          fflush(stdin);
                          gets(usuarios[auxInt].nombre);
                          printf("Ingrese Apellido:\n");
                          fflush(stdin);
                          gets(usuarios[auxInt].apellido);


                        }
                        else
                        {
                            printf("\nEl usuario cancelo la operacion\n\n");

                        }

                    }
                    else
                    {
                        printf("NO Existe el id ingresado!!\n\n\n");
                    }
                    system("pause");
                    system("cls");


                break;
            case 3:

                    printf("Ingrese Numero de Id\n\n");
                    fflush(stdin);
                    scanf("%d", &id);

                    auxInt=buscarIdUser(usuarios,id);
                    if(usuarios[auxInt].estado==1)
                    {
                    printf("Esta seguro que desea eliminar el usuario y las publicaciones de:\n\n");
                    printf("Usuario: %s\n\n",usuarios[auxInt].usuario);
                    printf("Producto\tPrecio\tStock\tVendido\n\n");
                    for(j=0;j<10;j++)
                    {
                        if(usuarios[auxInt].idUser==productos[j].idUser)
                        {
                            if(productos[j].estado==1)
                           {
                                printf("%s\t%$%d\t%d\t%d\n",productos[j].nombre,productos[j].precio,productos[j].stock,productos[j].vendidos);
                           }

                        }
                    }

                    respuesta=getche();

                    if(respuesta=='s')
                        {
                            usuarios[auxInt].estado=-1;
                            productos[j].estado=-1;
                        }
                        else
                        {
                            printf("\nEl usuario cancelo la operacion\n\n");

                        }

                    }
                    else
                    {
                        printf("NO Existe el id ingresado!!\n\n\n");
                    }


            break;
            case 4:
                    auxInt= obtenerEspacioLibreProducto(productos);

                    if(auxInt>0)
                    {

                        productos[auxInt].idProducto=auxInt+1;
                        printf("ingrese numero de Usuario");
                        fflush(stdin);
                        scanf("%d",&productos[auxInt].idUser);
                        printf("Ingrese Nombre del producto:\n");
                        fflush(stdin);
                        gets(productos[auxInt].nombre);
                        printf("Ingrese Precio:\n");
                        fflush(stdin);
                        scanf("%d",&productos[auxInt].precio);
                        printf("Stock:\n");
                        fflush(stdin);
                        scanf("%d",&productos[auxInt].stock);
                        productos[auxInt].vendidos=0;
                        productos[auxInt].estado=1;
                    }
                    else
                    {
                        printf(" *************ALERTA*********************\n");
                        printf(" *                                      *\n");
                        printf(" *  No se pueden agregar mas Productos  *\n");
                        printf(" *                                      *\n");
                        printf(" ****************************************\n\n");
                    break;
                    }





                printf("\n\n");
            break;
            case 5:
                    printf("Ingrese Numero de Id\n\n");
                    fflush(stdin);
                    scanf("%d", &id);

                    auxInt=buscarIdUser(usuarios,id);
                    if(usuarios[auxInt].estado==1)
                    {

                    printf("Usuario: %s\n\n",usuarios[auxInt].usuario);
                    printf(" Id   \tProducto\tPrecio\tStock\tVendido\n\n");
                    for(j=0;j<10;j++)
                    {
                        if(usuarios[auxInt].idUser==productos[j].idUser)
                        {
                            if(productos[j].estado==1)
                           {
                                printf(" %d\t%s\t%$%d\t%d\t%d\n\n",productos[j].idProducto,productos[j].nombre,productos[j].precio,productos[j].stock,productos[j].vendidos);

                           }

                        }

                    }
                    }


                    printf("Ingrese el Id del producto que quiera modificar:\n\n");
                    fflush(stdin);
                    scanf("%d",&auxProducto);
                   // printf("%d\n",auxProducto);

                   for(i=0; i<P ;i++)
                    {
                    if(auxProducto == productos[i].idProducto )
                    {
                        printf("Ingrese Precio:\n");
                        fflush(stdin);
                        scanf("%d",&productos[auxInt].precio);
                        printf("Stock:\n");
                        fflush(stdin);
                        scanf("%d",&productos[auxInt].stock);
                        break;
                    }
                  /*  else
                    {
                        printf("NO Existe el id ingresado!!\n\n\n");
                        break;
                    }*/
                    }


                printf("\n\n");
            break;
            case 6:

            break;
            case 7:

                printf("\n\n");
            break;
            case 8:

                printf("\n\n");
            break;
            case 9:

                printf("\n\n");
            break;
            case 10:

                printf("\n\n");
            break;
            case 11:
                for(i=0;i<A;i++)
                {
                    if(usuarios[i].estado==1)
                    {

                    printf("IdUser:   %d\n",usuarios[i].idUser);
                    printf("Estado:   %d\n",usuarios[i].estado);
                    printf("Usuario:  %s\n",usuarios[i].usuario);
                    printf("Nombre:   %s\n",usuarios[i].nombre);
                    printf("Apellido: %s\n\n\n",usuarios[i].apellido);
                    }

                }

                printf("\n\n");

            break;
            case 12:
                seguir = 'n';

            break;

            }
            }







    return 0;
}

 int  obtenerEspacioLibre(eUsuario usuarios[])
   {
       int i,x, flag=0;



       for(i=0; i<A ; i++)
       {
           if(usuarios[i].estado!=1)
           {
               x=i;
               flag=1;
           }

       }
       if(flag==0)
       {
           x=-1;
       }
   return x;
   }

int buscarIdUser(eUsuario usuarios[], int auxId)
   {

    int i,x, flag=0;

    for(i=0 ; i<A ; i++)
    {
        if(usuarios[i].idUser == auxId && usuarios[i].estado>0)
        {

            x=i;
            flag=1;

        }

    }
    if(flag==0)
    {
        x=-1;
    }
    return x;
   }


int  obtenerEspacioLibreProducto(eProducto productos[])
{
   int i,x, flag=0;



       for(i=0; i<P ; i++)
       {
           if(productos[i].estado !=1)
           {
               x=i;
               flag=1;
           }

       }
       if(flag==0)
       {
           x=-1;
       }
   return x;
}

