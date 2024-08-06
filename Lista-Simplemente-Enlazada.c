/*
) Crear y mostrar una lista simplemente enlazada con los siguientes datos:
 -año de nacimiento
 -Nombre
 -peso
 -altura
 La carga termina cuando el año de nacimiento es 0
 °Generar una nueva lista con el año de nacimiento y el índice de masacorporal.
 °Generar otra lista con el nombre de aquellas personas con sobrepeso
 °Insertar antes de cada nodo un en la lista con año de nacimiento eíndice de masa corporal otro nodo con un 1 en el índice de masacorporal
  si no tiene sobrepeso o un cero si tiene sobrepeso.
 °Mostrar el o los nombres con obesidad.
 °Eliminar de la lista original aquellas personas que nacieron entre 1960 y1970 y no tiene sobrepeso.
 IMC:
 -1- 15 o menos: "Delgadez muy severa"
 -2- 15.1 - 15.9: "Delgadez severa"
 -3- 16 - 18.4: "Delgadez"
 -4- 18.5 - 24.9: "Peso saludable"
 -5- 25 - 29.9: "Sobrepeso"
 -6- 30 - 34.9: "Obesidad moderada"
 -7- 35 - 39.9: "Obesidad severa"
 -8- 40 o mas: "Obesidad muy severa"
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista
{
    char nombre[40];
    int nacimiento;
    float peso;
    float altura;
    struct lista *sig;
}nodo;
typedef struct lista1
{
    int nacimiento;
    char imc[40];
    struct lista1 *sig;
}nodo1;
typedef struct lista2
{
    char nombreg[40];
    struct lista2 *sig;
}nodo2;

void crear(nodo *a)
{
    printf("\n------------------------\n");
    printf("\nAño de nacimiento: ");
    scanf("%d",&a->nacimiento);
    if(a->nacimiento == 0)
    {
        a->sig = NULL;
        return;
    }else{
        printf("\nNombre: ");
        scanf("%s",a->nombre);
        printf("\nPeso en kg: ");
        scanf("%f",&a->peso);
        printf("\nAltura en m: ");
        scanf("%f",&a->altura);
        printf("\n------------------------\n");
        a->sig = (nodo*)malloc(sizeof(nodo));
        crear(a->sig);
    }
}
void mostrar(nodo *a)
{
    if(a->sig != NULL)
    {
        printf("\n------------------------\n");
        printf("\n°°Año de nacimiento: %d" , a->nacimiento);
        printf("\n°°Nombre: %s" , a->nombre);
        printf("\n°°Peso: %.2f" , a->peso);
        printf("\n°°Altura: %.2f" , a->altura);
        printf("\n------------------------\n");
        mostrar(a->sig);
    }
}
void mostrar1(nodo1 *b)
{
    if(b->sig != NULL)
    {
        printf("\n------------------------\n");
        printf("\n°Año de nacimiento: %d" , b->nacimiento);
        printf("\n°IMC: %s" , b->imc);
        printf("\n------------------------\n");
        mostrar1(b->sig);
    }
}
void mostrar2(nodo2 *c)
{
    if(c->sig != NULL)
    {
        printf("\n------------------------\n");
        printf("\nNombre: %s" , c->nombreg);
        printf("\n------------------------\n");
        mostrar2(c->sig);
    }
}
int calcularimc(float peso , float altura)
{
    float imc;
    imc = peso / (altura * altura);
    if(imc <= 15)
        return 1;
    if(imc >= 15.1 && imc <= 15.9)
        return 2;
    if(imc >= 16 && imc <= 18.4)
        return 3;
    if(imc >= 18.5 && imc <= 24.9)
        return 4;
    if(imc >= 25 && imc <= 29.9)
        return 5;
    if(imc >= 30 && imc <= 34.9)
        return 6;
    if(imc >= 35 && imc <= 39.9)
        return 7;
    if(imc >= 40)
        return 8;
}
void generar(nodo *a , nodo1 *b)
{
    int estado;
    if(a->sig == NULL)
    {
        b->sig = NULL;
        return;
    }else{
        b->nacimiento = a->nacimiento;
        estado = calcularimc(a->peso,a->altura);
        if(estado == 1)
            strcpy(b->imc , "Delgadez muy severa");
        if(estado == 2)
            strcpy(b->imc , "Delgadez severa");
        if(estado == 3)
            strcpy(b->imc , "Delgadez");
        if(estado == 4)
            strcpy(b->imc , "Peso saludable");
        if(estado == 5)
            strcpy(b->imc , "Sobrepeso");
        if(estado == 6)
            strcpy(b->imc , "Obesidad moderada");
        if(estado == 7)
            strcpy(b->imc , "Obesidad severa");
        if(estado == 8)
            strcpy(b->imc , "Obesidad muy severa");
        b->sig = (nodo1*)malloc(sizeof(nodo1));
        generar(a->sig,b->sig);
    }
}
void generar1(nodo1 *b , nodo2 *c , nodo *a)
{
    if(b->sig == NULL)
    {
        c->sig = NULL;
        return;
    }
    if(strcmp(b->imc , "Sobrepeso") == 0)
    {
        strcpy(c->nombreg , a->nombre);
        c->sig = (nodo2*)malloc(sizeof(nodo2));
        generar1(b->sig,c->sig,a->sig);
    }else{
        generar1(b->sig,c,a->sig);
    }
}
void insertar(nodo1 *b)
{
    nodo1 *aux;
    while(b->sig != NULL && b->sig->sig != NULL)
    {
        if(strcmp(b->sig->imc , "Sobrepeso") == 0)
        {
            aux = (nodo1*)malloc(sizeof(nodo1));
            aux->nacimiento = b->sig->nacimiento;
            strcpy(aux->imc , "0");
            aux->sig = b->sig;
            b->sig = aux;
        }else{
            aux = (nodo1*)malloc(sizeof(nodo1));
            aux->nacimiento = b->sig->nacimiento;
            strcpy(aux->imc , "1");
            aux->sig = b->sig;
            b->sig = aux;
        }
        b = b->sig->sig;
    }
}
nodo1* insertarcabeza(nodo1 *b)
{
    nodo1 *aux;
    aux = (nodo1*)malloc(sizeof(nodo1));
    aux->nacimiento = b->nacimiento;
    if(strcmp(b->imc , "Sobrepeso") == 0)
    {
        strcpy(aux->imc , "0");
        aux->sig = b;
        b = aux;
    }else{
        strcpy(aux->imc , "1");
        aux->sig = b;
        b = aux;
    }
    return b;
}
void mostrarobesos(nodo *a)
{
    if(a->sig != NULL)
    {
        printf("\n-------------------\n");
        if((a->peso / (a->altura * a->altura)) >= 30)
        {
            printf("\n-Nombre-: %s" , a->nombre);
        mostrarobesos(a->sig);
        }
    }
}
nodo* eliminarcabeza(nodo *a)
{
    nodo *aux;
    while(a->nacimiento <= 1970 && a->nacimiento >= 1960 && (a->peso / (a->altura * a->altura)) <= 24.9)
    {
        aux = a->sig;
        free(a);
        a = aux;
    }
    return a;
}
void eliminar(nodo *a)
{
    nodo *aux;
    while(a->sig != NULL && a->sig->sig != NULL)
    {
        if(a->sig->nacimiento <= 1970 && a->sig->nacimiento >= 1960 && (a->sig->peso / (a->sig->altura * a->sig->altura)) <= 24.9)
        {
            aux = a->sig->sig;
            free(a->sig);
            a->sig = aux;
        }else{
            a = a->sig;
        }
    }
}

int main()
{
    nodo *a = NULL;
    nodo1 *b = NULL;
    nodo2 *c = NULL;
    a = (nodo*)malloc(sizeof(nodo));
    b = (nodo1*)malloc(sizeof(nodo1));
    c = (nodo2*)malloc(sizeof(nodo2));
    crear(a);
    mostrar(a);
    generar(a,b);
    printf("\n-----------LISTA IMC-------------\n");
    mostrar1(b);
    generar1(b,c,a);
    printf("\n-----------LISTA SOBREPESO-----------\n");
    mostrar2(c);
    printf("\n-----------LISTA INSERTAR-------------\n");
    insertar(b);
    b = insertarcabeza(b);
    mostrar1(b);
    printf("\n-----------LISTA OBESOS-------------\n");
    mostrarobesos(a);
    printf("\n-----------LISTA ELIM-------------\n");
    a = eliminarcabeza(a);
    eliminar(a);
    mostrar(a);
}

