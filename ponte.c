#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int visitado;
    int lista_adj[100];
    int tamanho_lista;
}vertices;

int cc;
int * in;
int * lower;

int min(int x, int y){
	if(x < y) 
		return x;
	return y;
}

void dfs(vertices * v, int pos, int pai){

    in[pos] = cc;
	lower[pos] = cc;
	cc++;

	v[pos].visitado = 1;

	for(int i = 0; i < v[pos].tamanho_lista; i++){
		int filho = v[pos].lista_adj[i];

		if(v[filho].visitado == 0){
			dfs(v, filho, pos);

			if(lower[filho] > in[pos]){
				printf("\nPonte: %d -> %d", pos, filho);
			}else{
				lower[pos] = min(lower[pos], lower[filho]);
			}
		}else{
			if(filho != pai){
                lower[pos] = min(lower[pos], lower[filho]);
			}   
		}
	}
}


int main(){

    int n, a, i, x, y;

	scanf("%d %d", &n, &a);

	in = malloc(sizeof(int)*(n+1));
	lower = malloc(sizeof(int)*(n+1));

	vertices * v = malloc(sizeof(vertices)*(n+1));

	for(i = 0; i < a; i++){
		scanf("%d %d", &x, &y);
		v[x].lista_adj[ v[x].tamanho_lista++ ] = y;
		v[y].lista_adj[ v[y].tamanho_lista++ ] = x;
	}

	dfs(v, 1, 0);

	printf("\n");
	return 0;
}