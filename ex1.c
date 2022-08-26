#include <stdio.h>

/* 
Faça um programa que receba do usuário N pares de valores, onde cada PAR representa uma aresta
bidirecional entre cada valor do par.

Mostre uma matriz de adjacência que represente esse grafo
Mostre uma lista de adjacência que represente esse grafo. 
*/

int main() {

	int matriz_adj[50][50], n, i = 0, limite = 0;

	printf("Digite o valor n: ");
	scanf("%d", &n);

	while(i < n){

		int n1, n2;

		printf("\nPar %d(numero 1): ", i+1);
		scanf("%d", &n1);

		printf("\nPar %d(numero 2): ", i+1);
		scanf("%d", &n2);

		matriz_adj[n1-1][n2-1] = 1;
		matriz_adj[n2-1][n1-1] = 1;

		matriz_adj[n1-1][n1-1] = 1;
		matriz_adj[n2-1][n2-1] = 1;

		if(n1 > n2){
			if(n1 > limite){
				limite = n1;
			}
		}else{
			if(n2 > limite){
				limite = n2;
			}
		}

		i+=1;
	}

	printf("Matriz:\n");
	for(int i = 0; i < limite; i+=1){
		for(int j = 0; j < limite; j+=1){
			if(i == j){
				matriz_adj[i][j] = 1;
			}
			printf("%d ", matriz_adj[i][j]);
		}
		printf("\n");
	}


	printf("Lista:\n");
	for(int i = 0; i < limite; i+=1){
		printf("Vertice: %d ---> ", i+1);
		for(int j = 0; j < limite; j+=1){
			if(j != i){
				matriz_adj[i][j] == 1 ? printf("%d, ", j+1) : printf("");
			}
		}
		printf("\n");
	}


	return 0;
}