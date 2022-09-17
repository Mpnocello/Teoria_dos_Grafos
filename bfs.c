#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado; 
    int distancia; 
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

typedef struct fila
{
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}fila;


registro * aloca_registro()
{
    registro * aux;

    aux = malloc(sizeof(registro));

    return aux;
}

lista * aloca_lista()
{
    lista * aux;

    aux = malloc(sizeof(lista));

    return aux;
}

void inclui_fila(fila * f, int n)
{
    registro * novo;

    novo = aloca_registro();

    novo->valor = n;

    if(f->qtd == 0)
    {
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->qtd++;
}

int pop (fila * f)
{
    if(f->qtd == 0)
    {
        return -1;
    }else{

        int n;
        registro * aux;

        aux = f->inicio;
        n = aux->valor;

        f->inicio = aux->prox;
        f->qtd--;

        if(f->inicio == NULL)
        {
            f->fim = NULL;
        }

        return n;
    }
}

void inclui_lista(lista * l1, int n)
{
    registro * novo = aloca_registro();

    novo->valor = n;

    if(l1->inicio == NULL){
        l1->inicio = novo;
    }else{

        registro * aux = l1->inicio;

        while (aux!=NULL)
        {
            if(aux->valor == novo->valor){
                return;
            }

            if (aux->prox==NULL)
            {
                aux->prox = novo;
            }

            aux = aux->prox;
        }
    }
    l1->qtd++;
}


void mostrar_lista(lista * l1)
{
    if(l1->inicio == NULL){
        printf("Lista vazia\n");
    }else{

        registro * aux = l1->inicio;

        while(aux != NULL)
        {
            printf("%d ,",aux->valor);
            aux = aux->prox;  
        }
    }
}

void adiciona(vertice * v, int n)
{
    if(v->lista_adj == NULL){
        v->lista_adj = aloca_lista();
    }

    inclui_lista(v->lista_adj, n);
}

void bfs(vertice * v, int i, fila * f)
{
    registro * aux;

    if(v[i].lista_adj == NULL)
    {
        return;
    }

    aux = v[i].lista_adj->inicio;

    while(aux)
    {
        if(v[aux->valor].visitado == 0)
        {
            inclui_fila(f, aux->valor);
            v[aux->valor].distancia = v[i].distancia + 1;
        }
        aux = aux->prox;
    }
}



int main()
{
    int n, a;

    scanf("%d %d",&n, &a);

    vertice * v;

    v = malloc(sizeof(vertice)* (n+1));

    for(int i = 0; i < a; i++){

        int x, y;
        scanf("%d %d",&x, &y);

        if(x == y){
            printf("ERROR\n");
            return 1;
        }
        adiciona(&v[x], y);
        adiciona(&v[y], x);
    }

    fila * f = calloc(1, sizeof(registro));

    int raiz;
    printf("\nRaiz: ");
    scanf("\n%d", &raiz);
    
    inclui_fila(f, raiz);

    while(f->qtd > 0)
    {
        int n;

        n = pop(f);

        if(v[n].visitado == 0)
        {
            v[n].visitado = 1;

            bfs(v, n, f);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        printf("\n %d: distancia = %d", i, v[i].distancia);
    }

    printf("\n");
    return 0;
}