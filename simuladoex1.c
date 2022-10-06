#include <stdio.h>
#include <stdlib.h>

int in[100];
int out[100];
int cont = 0;

typedef struct v{
    int visitado;
    int lista_adj[100];
    int tamanho_lista;
    int distancia;
}v;

void dfs(v * vertices, int x, int distancia){

    in[x]=cont;
    cont ++;

    vertices[x].visitado = 1;
    vertices[x].distancia = distancia;

    for(int i = 0; i<vertices[x].tamanho_lista; i++){

        int aux;
        aux = vertices[x].lista_adj[i];

        if(vertices[aux].visitado == 0){
            dfs(vertices, aux, distancia+1);
        }
    }

    out[x]=cont;
    cont++;
}

void zerar_visitados(v * vertices, int qtd){

    for(int i = 1; i<=qtd; i++){
        vertices[i].visitado=0;
        vertices[i].distancia=0;
    }
}

void add_aresta(v * vertices, int x, int y){
    
    vertices[x].lista_adj[vertices[x].tamanho_lista++] = y;
}

int main(){

    int q, vs, i, x, y;

    scanf("%d %d", &q,&vs);

    v * vertices = malloc(sizeof(v)*(q+1));

    for(i = 0; i<vs; i++){

        scanf("%d %d", &x, &y);

        add_aresta(vertices, x, y);
        vertices[y].lista_adj[vertices[y].tamanho_lista++] = x;
    }

    dfs(vertices, 1, 0);

    int filho = 5, pai = 6;

    if(in[filho]>in[pai] && out[filho]<out[pai]){
        printf("\nSim");
    }else{
        printf("\nNao");
    }

    int c;

    scanf("%d", &c);

    for(i = 0; i<c; i++){

        scanf("%d %d", &x, &y);
        zerar_visitados(vertices, q);
        dfs(vertices, x, 0);

        printf("\n%d",vertices[y].distancia);
    }
    printf("\n");
    return 0;
}