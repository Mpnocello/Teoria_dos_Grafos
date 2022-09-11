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

void dfs(vertice * v, int n, int distancia)
{
    if (v[n].visitado == 1)
    {
        return;
    }

    v[n].visitado = 1;
    v[n].distancia = distancia;

    if (v[n].lista_adj == NULL)
    {
        return;
    }

    registro * aux = v[n].lista_adj->inicio;
    
    while (aux!=NULL)
    {
        if(v[aux->valor].visitado == 0){
            dfs(v, aux->valor, distancia+1);
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

    int cont;

    for(int i = 1; i <= n; i++){
        if(v[i].visitado == 0){

            dfs(v, i, 0);
            cont++;
        }
    }

    if(cont == 1 && a == n-1){
        printf("Arvore\n");
    }

    for (int i = 1; i <= n; i++){
        
        printf("\n%d - > ", i);
        mostrar_lista(v[i].lista_adj);

        //printf("\n%d -> %d", i, v[i].distancia); 
    }

    printf("\n");
    return 0;
}