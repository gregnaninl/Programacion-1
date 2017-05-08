#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define A 5
#define P 10



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
    char descripcion[20];
  }eProducto;

typedef struct
{
    int idPublicacion;
    int idProducto;
    int idUser;
    int estado;
    int precio;
    int stock;
    int vendidos;
}ePublicacion;


typedef struct
{
    int idProducto;
    int idUser;

}eCompra;


void listarUsuarios(eUsuario[]);
void ListarPublicaciones(ePublicacion[],eProducto[]);
int  buscarIdUser(eUsuario[], int);
void ListarPublicacionesPorId (ePublicacion[], eProducto[],int );
int buscarIdProducto(ePublicacion[], int );
int BuscarNombredeProducto(eProducto productos[],int j);
int validarIdPublicacion(ePublicacion[],int, int);
void ListarPublicacionesconId(ePublicacion[], eProducto[],int );
int  obtenerEspacioLibreProducto(ePublicacion[]);
int  obtenerEspacioLibre(eUsuario[]);




int main()
{
    int i;
    int aux,auxInt,auxId,auxCompra,auxNombre,auxCalif,auxProd;
    int suma,x;
    float promedio;



    eUsuario usuarios[A]={{1,1,"Lgregna","leandro","Gregnanin",10},{2,1,"Ggomez","Gonzalo","Gomez",7},{3,1,"Mperez","Martin","Perez",6},{4,1,"Jlopez","Juan","Lopez",3} };
    eProducto productos[P]={{100,"Tijera"},{101,"Alicate"},{102,"Amoladora"},{103,"Martillo"},{104,"Taladro"},{105,"Tenaza"}  };
    ePublicacion publicaciones[P] = {{1,100,1,1,55,1,1 },{2,101,1,1,70,20,6},{3,101,2,1,75,30,0},{4,104,3,1,600,10,1},{5,105,4,1,30,90,10} };

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
                        //calificacion Inicial
                        usuarios[auxInt].calificacion=7;
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
                    scanf("%d", &auxId);

                    auxInt=buscarIdUser(usuarios,auxId);
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
                    scanf("%d", &auxId);

                    auxInt=buscarIdUser(usuarios,auxId);
                    if(usuarios[auxInt].estado==1)
                    {
                    printf("Esta seguro que desea eliminar el usuario y las publicaciones de:\n\n");
                    printf("Usuario: %s\n\n",usuarios[auxInt].usuario);
                    printf("idProducto\tPrecio\tStock\tVendido\n\n");
                    for(i=0;i<P;i++)
                    {
                        if(usuarios[auxInt].idUser==publicaciones[i].idUser)
                        {
                            if(publicaciones[i].estado==1)
                           {
                                printf("%d\t\t%$%d\t%d\t%d\n",publicaciones[i].idProducto,publicaciones[i].precio,publicaciones[i].stock,publicaciones[i].vendidos);
                           }

                        }
                    }


                    respuesta=getche();

                    if(respuesta=='s')
                        {
                            usuarios[auxInt].estado=-1;
                            publicaciones[i].estado=-1;
                            printf("\n\nSe elimino el usuario %s\n",usuarios[auxInt].usuario);
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

                printf("\n\n");
            break;
            case 4:





                printf("\n\n");
            break;
            case 5:

                printf("Ingrese el id de usuario:\n");
                fflush(stdin);
                scanf("%d",&auxInt);

                auxId = buscarIdUser(usuarios,auxInt);

                if(auxId>=0)
                {
                printf("Listado de publicaciones de: %s\n",usuarios[auxId].usuario);

                ListarPublicacionesconId(publicaciones,productos,auxInt);
                printf("\n\nIngrese el id del producto que desea Modificar\n\n");
                scanf("%d",&auxProd);
                for(i=0;i<P;i++)
                 {
                     if(publicaciones[i].idUser==usuarios[auxId].idUser)

                     {
                         x=i;
                     }
                 }

                 printf("Ingrese el nuevo precio;\n");
                 scanf("%d" ,&publicaciones[x].precio);
                 printf("Ingrese el nuevo Stock;\n");
                 scanf("%d" ,&publicaciones[x].stock);

                }

                printf("\n\n");
            break;
            case 6:
                printf("Ingrese el id de usuario:\n");
                fflush(stdin);
                scanf("%d",&auxInt);

                auxId = buscarIdUser(usuarios,auxInt);


                if(auxId>=0)
                {
                printf("Listado de publicaciones de: %s\n",usuarios[auxId].usuario);

                ListarPublicacionesPorId(publicaciones,productos,auxInt);
                printf("\n\nIngrese el id de la publicacion que desea Cancelar\n\n");
                scanf("%d",&auxProd);

                aux=validarIdPublicacion(publicaciones,auxProd,auxInt);


                while(aux!=1)
                {
                    printf("Por favor ingrese un numero de id que corresponda con el usuario");
                    scanf("%d",&aux);
                }

                 for(i=0;i<P;i++)
                 {
                     if(publicaciones[i].idUser==usuarios[auxId].idUser)
                     {
                         x=i;
                     }
                 }
                 publicaciones[x].estado=-1;

                }
                else
                {
                    printf("\n El Id de Usuario no Existe!!\n\n");
                }



            break;
            case 7:
                printf("**********************************************\n");
                printf("*           PORTAL DE COMPRAS                *\n");
                printf("**********************************************\n\n\n");
                printf("Ingrese el id del producto:\n");
                fflush(stdin);
                scanf("%d",&auxInt);

                auxId=buscarIdProducto(publicaciones,auxInt);
                if(auxId>=0)
                {
                   if(publicaciones[auxId].stock>0)
                   {
                       printf("Hay en stock: %d\n\nCuantos desea comprar?\n",publicaciones[auxId].stock);
                       scanf("%d",&auxCompra);

                       while(publicaciones[auxId].stock<auxCompra)
                       {
                           printf("Por Favor ingrese un valor que no supere la cantidad de Stock disponible!!\n\n");
                           scanf("%d",&auxCompra);
                       }

                       printf("COMPRA REALIZADA CON EXITO USTED COMPRO;\n\n");
                       auxNombre =  BuscarNombredeProducto(productos,publicaciones[auxId].idProducto);

                       printf("Nombre;%s\tPrecio;$%d\tCantidad:%d\n\n",productos[auxNombre].descripcion,publicaciones[auxId].precio,auxCompra );
                       printf("Por favor ingrese la calificacion del vendedor\n\n");
                       scanf("%d",&auxCalif);

                       publicaciones[auxId].stock = publicaciones[auxId].stock - auxCompra;
                       publicaciones[auxId].vendidos = publicaciones[auxId].vendidos + auxCompra;
                       auxInt=buscarIdUser(usuarios,publicaciones[auxId].idUser);
                       suma= usuarios[auxInt].calificacion + auxCalif;
                       promedio=suma/2;
                       usuarios[auxInt].calificacion=promedio;
                    }
                   else
                   {
                       printf("No hay STOCK disponible para realizar la compra");
                   }



                }
                else
                {
                    printf("\n El Id de producto no existe o la publicacion no esta activa!!\n\n");
                }



                printf("\n\n");
            break;
            case 8:
                printf("Ingrese el id de usuario:\n");
                fflush(stdin);
                scanf("%d",&auxInt);

                auxId = buscarIdUser(usuarios,auxInt);

                if(auxId>=0)
                {
                printf("Listado de publicaciones de: %s\n",usuarios[auxId].usuario);

                ListarPublicacionesPorId(publicaciones,productos,auxInt);
                }
                else
                {
                    printf("\n El Id de Usuario no Existe!!\n\n");
                }

                printf("\n\n");
            break;
            case 9:
                ListarPublicaciones(publicaciones,productos);
                printf("\n\n");
            break;
            case 10:
                listarUsuarios(usuarios);
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


void listarUsuarios(eUsuario usuarios[])
{
    int i;

    printf("***********Listado de Usuarios****************\n");
    printf("* IdUser\tUsuario\t     Calificacion    *\n");
    printf("**********************************************\n");
    for(i=0;i<A;i++)
    {
    if(usuarios[i].estado==1)
    {
    printf("    %d\t\t%s\t\t  %.2f\n",usuarios[i].idUser,usuarios[i].usuario,usuarios[i].calificacion);
    }
    }
}


void ListarPublicaciones(ePublicacion publicacion[],eProducto productos[])
{

    int i,j;

    printf("***********Listado de Publicaciones****************\n");
    printf("* Id\t Nombre\t\tPrecio\tStock\tVendidos  *\n");
    printf("***************************************************\n");
    for(i=0;i<A;i++)
    {
    if( publicacion[i].estado ==1)
    {
        for(j=0; j<P;j++)

        {
            if(publicacion[i].idProducto== productos[j].idProducto)
            {
            printf(" %d\t%s\t\t$%d\t%d\t%d\n",publicacion[i].idProducto,productos[j].descripcion,publicacion[i].precio,publicacion[i].stock,publicacion[i].vendidos);
            }
        }
    }
    }
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

void ListarPublicacionesPorId(ePublicacion publicaciones[], eProducto productos[],int auxId )
{

    int i,j;


    printf("***************************************************\n");
    printf("* Id\t Nombre\t\tPrecio\tStock\tVendidos  *\n");
    printf("***************************************************\n");
    for(i=0;i<A;i++)
    {
    if( publicaciones[i].idUser== auxId)
    {

        for(j=0; j<P;j++)

        {
            if(publicaciones[i].idProducto==productos[j].idProducto && publicaciones[i].estado==1)
            {
            printf(" %d\t%s\t\t$%d\t %d\t %d\n",publicaciones[i].idPublicacion,productos[j].descripcion,publicaciones[i].precio,publicaciones[i].stock,publicaciones[i].vendidos);
            }
        }
    }
    }
}

int buscarIdProducto(ePublicacion publicaciones[], int j)
   {

    int i,x, flag=0;

    for(i=0 ; i<P ; i++)
    {
        if(publicaciones[i].idProducto == j && publicaciones[i].estado>0)
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

int BuscarNombredeProducto(eProducto productos[],int j)
{
    int i,x,flag=0;


    for(i=0;i<P;i++)
    {
        if(productos[i].idProducto==j)
        {

            x=i;
            flag=1;

        }

    }
   /* if(flag==0)
    {
        x=-1;
    }*/
    return x;


}

int validarIdPublicacion(ePublicacion publicaciones[],int auxIdPub, int auxidUser)

{
    int i,x,flag=0;

     for(i=0;i<P;i++)
    {
        if(publicaciones[i].idPublicacion== auxIdPub && publicaciones[i].idUser==auxidUser)
        {

            x=1;
            flag=1;

        }

    }
    if(flag==0)
    {
        x=-1;
    }
    return x;





}


void ListarPublicacionesconId(ePublicacion publicaciones[], eProducto productos[],int auxId )
{

    int i,j;


    printf("***************************************************\n");
    printf("* Id\t Nombre\t\tPrecio\tStock\tVendidos  *\n");
    printf("***************************************************\n");
    for(i=0;i<A;i++)
    {
    if( publicaciones[i].idUser== auxId)
    {

        for(j=0; j<P;j++)

        {
            if(publicaciones[i].idProducto==productos[j].idProducto && publicaciones[i].estado==1)
            {
            printf(" %d\t%s\t\t$%d\t %d\t %d\n",productos[j].idProducto,productos[j].descripcion,publicaciones[i].precio,publicaciones[i].stock,publicaciones[i].vendidos);
            }
        }
    }
    }
}

int  obtenerEspacioLibreProducto(ePublicacion publicaciones[])
{
   int i,x, flag=0;



       for(i=0; i<P ; i++)
       {
           if(publicaciones[i].estado !=1)
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

