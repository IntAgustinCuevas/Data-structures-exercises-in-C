//-----------------------------Ejercicio 1------------------------------------------------------

/*
Ejercicio nª1: Crear y Mostrar un árbol binario de búsqueda.Escribir las funciones necesarias para calcular y luego mostrar:
a) Buscar el mayor elemento del árbol divisor de la raíz
b) Cantidad de nodos hojas impares.
c) El elemento maximo del arbol
d) Cantidad de nodos con dos hijos divisores de la raiz
e) Promedio de nodos con un valor par con un sólo hijo.
El ingreso de datos es 8 4 10 1 6 14 5 7 13
a) El mayor elemento divisor de la raiz es 4
b) La cantidad de nodos hojas impares es 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
	int dato;
	struct arbol *izq;
	struct arbol *der;
}nodoarbol;
	

int main ()
{
    int raiz;
    int MayorDivisor = 0;
    int cont = 0;
    int Maximo = 0;
    int Cont1 = 0;
	printf ("arboles\n");
	nodoarbol *arbol = NULL;
	crear (&arbol , &raiz);
	printf ("**************\n");
	printf ("mostrar arbol\n");
	printf ("***************\n");
	mostrar (arbol,raiz,&MayorDivisor,&cont,&Maximo,&Cont1);
	printf("\nEl mayor elemento divisor de la raiz es %d" , MayorDivisor);
	printf("\nLa cantidad de nodos hojas impares es %d" , cont);
	printf("\nEl elemento maximo del arbol es %d" , Maximo);
	printf("\nCantidad de nodos con dos hijos divisores de la raiz %d" , Cont1);
}

void crear (nodoarbol **arbol , int *raiz)
{
	int numero;
	printf ("ingrese numero\n");
	scanf ("%d",&numero);
	*raiz = numero;
	while (numero != -1)
	{
		insertar(&(*arbol) , numero);
		printf ("ingrese numero\n");
		scanf ("%d",&numero);
	}
}

void insertar (nodoarbol **arbol , int elem)
{
	int numero = elem;
	if (elem == -1)
	    return;
	if (*arbol == NULL)
	{
		//creo la hoja vacia
		(*arbol) = (nodoarbol*)malloc(sizeof(nodoarbol));
		(*arbol)->dato = elem;
		(*arbol)->der = NULL;
		(*arbol)->izq = NULL;
	}
	else
	{
		if (numero > (*arbol)->dato)
		{
			insertar (&(*arbol)->der , elem);
		}
		else
		{
			insertar (&(*arbol)->izq , elem);
		}
	}
	return;
}

void mostrar (nodoarbol *arbol , int raiz , int *MayorDivisor , int *cont , int *Maximo , int *Cont1)
{
	if (arbol != NULL)
	{
		mostrar(arbol->izq,raiz,MayorDivisor,cont,Maximo,Cont1);
		printf("%d " , arbol->dato);
	    mostrar(arbol->der,raiz,MayorDivisor,cont,Maximo,Cont1);
	    
	    if(raiz % arbol->dato == 0 && arbol->dato != raiz && arbol->dato > *MayorDivisor)
		{
		    *MayorDivisor = arbol->dato;
		}
		if(arbol->izq == NULL && arbol->der == NULL && arbol->dato % 2 != 0)
		{
		    *cont = *cont + 1;
		}
		if(arbol->dato > *Maximo)
		{
		    *Maximo = arbol->dato;
		}
		if(arbol->izq != NULL && arbol->der != NULL && raiz % arbol->dato == 0 && arbol->dato != raiz)
		{
		    *Cont1 = *Cont1 + 1;
		}
		
	}
	return;
}


//-----------------------------Ejercicio 2------------------------------------------------------

//a) Cantidad de los elementos pares con un hijo.
//b) Mínimo elemento impar del árbol.

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


int main ()
{
    int Cont=0;
    int Minimo=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,&Cont,&Minimo);
    
    printf("\nCantidad de element pares con un hijo: %d" , Cont);
    printf("\nMinimo elemento impar: %d" , Minimo);
}
void crear (treenode **hoja)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{




    if (numero>(*hoja)->dato)
    {

        insertar (&(*hoja)->der,elem);

    }
    else
    {

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}



void mostrar (treenode *hoja,int *Cont,int *Minimo)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,Cont,Minimo);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,Cont,Minimo);
        if(hoja->dato % 2 == 0)
        {
            if((hoja->izq == NULL && hoja->der != NULL) || (hoja->izq != NULL && hoja->der == NULL))
            {
                *Cont = *Cont + 1;
            }
        }
        
        if(*Minimo == 0 || hoja->dato % 2 != 0 )
        {
            if(hoja->dato < *Minimo)
            {
                *Minimo = hoja->dato;
            }
        }
    }
    return;
}


