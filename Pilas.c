/*
/*
Ejercicio nª1: Crear y Mostrar una Pila. Escribir las funciones necesarias para calcular y luego mostrar:
a) La productoria de posiciones impares.
b) La sumatoria de posiciones pares
c) Mostrar una leyenda si la sumatoria de posiciones pares es menor a 20.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *productoria,int *pos,int *suma)

{
    printf("\n\n\t::posicion::%d\t",*pos);    
    printf("%d \n", aux.dato);
    if(*pos % 2 != 0 )
    {
        if(*productoria == 0)
        {
            *productoria = aux.dato;
        }else{
            *productoria = *productoria * aux.dato;
        }
    }else{
        *suma = *suma + aux.dato;
    }
    *pos=*pos-1;
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");
  	u->siguiente = *p;
	*p = u;
	
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i,num;
   int productoria=0,pos=CANT-1;
   int suma=0;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&productoria,&pos,&suma);
   }

    printf("\nLa productoria de posiciones impares:: %d",productoria);
    if(suma >= 20)
    {
        printf("\nLa sumatoria de posiciones pares es: %d",suma);
    }else{
        printf("\nLa sumatoria es menor a 20 :c (%d)",suma);
    }
}
