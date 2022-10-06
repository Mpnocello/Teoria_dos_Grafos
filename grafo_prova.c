#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
	int tamanho;
	struct e * inicio;
	struct e * fim;
}fila;

typedef struct e{
	int valor;
	struct e * prox;
}e;

void push(fila * f, int valor)
{
	e * novo = malloc(sizeof(e));
	novo->valor = valor;

	if(f->tamanho == 0){
		f->inicio = novo;
		f->fim = novo;
	}else{
		f->fim->prox = novo;
		f->fim = novo;
	}
	f->tamanho++;
}

int pop(fila * f)
{
	int ret;
	ret = f->inicio->valor;

	if(f->tamanho == 1){
		f->inicio = NULL;
		f->fim = NULL;
	}else{

		f->inicio = f->inicio->prox;
	}

	f->tamanho--;

	return ret;
}

void mostra(fila * f){
	e* aux = f->inicio;
	while(aux){
		printf("\n%d ", aux->valor);
		aux = aux->prox;
	}
}

typedef struct v{
	int visitado;
	int lista_adj[100];
	int tamanho_lista;
}v;

v * aloca_vertice(){
	v * novo;
	novo = malloc(sizeof(v));
	return novo;
}

void bfs(v * vertices, int raiz)
{
	int i, current;
	fila * f = malloc(sizeof(fila));

	push(f, raiz);

	while(f->tamanho > 0){

		current = pop(f);
		if(vertices[current].visitado == 0){
			printf("%d ", current);
			vertices[current].visitado = 1;

			for(i = 0; i < vertices[current].tamanho_lista; i++){
				push(f, vertices[current].lista_adj[i]);
			}
		}
	}
}

void dfs(v * vertices, int raiz){

	vertices[raiz].visitado = 1;
	printf("%d ", raiz);

	for(int i = 0; i < vertices[raiz].tamanho_lista;i++){
		int elemento = vertices[raiz].lista_adj[i];

		if(vertices[ elemento ].visitado == 0){
			dfs(vertices, elemento);
		}
	}

}

void zera_visitados(v * vertices, int qtd)
{
	for(int i = 1; i <= qtd; i++){
		vertices[i].visitado = 0;
	}
}

int main(int argc, char *argv[]){

	int n = atoi(argv[1]);
	int a = atoi(argv[2]);
	v * vertices = malloc(sizeof(vertices) * (n+1));

	for(int i = 0; i < a; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		vertices[x].lista_adj[ vertices[x].tamanho_lista++ ] = y;

		vertices[y].lista_adj[ vertices[y].tamanho_lista++ ] = x;
	}

	for(int i = 1; i <= n; i++){
		printf("\n%d -> ", i);
		for(int j = 0; j < vertices[i].tamanho_lista; j++){
			printf("%d ", vertices[i].lista_adj[j]);
		}
	}
	
	printf("\ndfs: ");
	dfs(vertices, 1);

	zera_visitados(vertices, n);

	printf("\nbfs: ");
	bfs(vertices, 1);

	printf("\n");
	return 0;
}