#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado; 
    struct lista * lista_adj;

}vertice;

typedef struct lista
{
    int qtd;
    struct registro * inicio;

}lista;

typedef struct registro
{
    int valor;
    struct registro * prox;

}registro;


registro * aloca_registro(){
    registro * aux;

    aux = malloc(sizeof(registro));

    return aux;
}

lista * aloca_lista()
{
    lista * aux;

    lista = malloc(sizeof(lista));

    return aux;
}

int main()
{








    printf("\n");
    return 0;
}
