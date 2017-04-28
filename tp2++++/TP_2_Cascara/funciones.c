#include "funciones.h"
#define A 4




  int buscarPorDni(EPersona datos[], int dni)
   {

    int i,x, flag=0;

    for(i=0 ; i<A ; i++)
    {
        if(datos[i].dni==dni)
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



   int  obtenerEspacioLibre(EPersona datos [])
   {
       int i,x, flag=0;



       for(i=0; i<A ; i++)
       {
           if(datos[i].estado!=1)
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
