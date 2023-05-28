#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo* g, int novoId, char cidade[])
{
	Grafo novo = malloc(sizeof(struct registo1));
	if (novo != NULL)
	{
		novo->vertice = novoId;
		strcpy(novo->cidade, cidade);
		novo->adjacentes = NULL;
		novo->seguinte = *g;
		*g = novo;
		return(1);
	}
	else return(0);
}

// Devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo g, int vertice)
{
	while (g != NULL)
	{
		if (g->vertice == vertice) return(1);
		else g = g->seguinte;
	}
	return(0);
}

// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, int vOrigem, int vDestino, float peso)
{
	Adjacente * novo;
	if (existeVertice(g, vOrigem))
	{
		while (g->vertice != vOrigem) g = g->seguinte;
		novo = malloc(sizeof(struct registo1));
		if (novo != NULL)
		{
			novo->vertice = vDestino;
			novo->peso = peso;
			novo->seguinte = g->adjacentes;
			g->adjacentes = novo;
			return(1);
		}
		else return(0);
	}
	else return(0);
}

// Listar os vértices adjacentes 
void listarAdjacentes(Grafo g, int vertice)
{
	printf("Cidade: \n");
	if (existeVertice(g, vertice))
	{
		while (g->vertice != vertice) g = g->seguinte;
		Adjacente* aux = g->adjacentes;

		while (aux != NULL)
		{
			printf("%d %.2f\n", aux->vertice, aux->peso);
			aux = aux->seguinte;
		}
	}
}

void listarVertices(Grafo g) {
	Grafo aux = g;

	while (g != NULL) {
		printf("%d %s\n", g->vertice, g->cidade);
		g = g->seguinte;
		
	}

}

int guardarLocais(Grafo g)
{
	Adjacente * aux;
	FILE* fp;   
	FILE* fp1;   
	fp = fopen("locais.txt", "w");    
	fp1 = fopen("locais_adjacentes.txt", "w");    
	if (fp != NULL)   
	{
		
		while (g != NULL) 
		{
			
			
			fprintf(fp, "%d;%s;\n", g->vertice, g->cidade);
			aux = g->adjacentes;
			while (aux != NULL) {
				fprintf(fp1, "%d;%d;%f;\n", g->vertice, aux->vertice, aux->peso);
				aux = aux->seguinte;
				printf("Teste\n");


			}
			g = g->seguinte;    
		}
		fclose(fp); 
		fclose(fp1);
		return(1);  
	}
	else
		return(0);  
}


 Grafo * lerLocais()
{
	 Grafo* g = NULL;
	FILE* fp;
	fp = fopen("locais.txt", "r");
	if (fp == NULL) {
		printf("Erro ao abrir o arquivo 'locais.txt'!\n");
		return NULL;
	}

	char linha[200];

	while (fgets(linha, 200, fp) != NULL) {
		int codigo;
		char  cidade[50];
		sscanf(linha, "%d;%[^;];\n", &codigo, cidade);
		criarVertice(&g, codigo, cidade);


		FILE* fp1;
		fp1 = fopen("locais_adjacentes.txt", "r");
		if (fp1 == NULL) {
			printf("Erro ao abrir o arquivo 'locais_adjacentes.txt'!\n");
			return NULL;
		}
		char linha1[200];
		while (fgets(linha1, 200, fp1) != NULL) {

			int cod_adjacente, cod_cidade;
			float peso;

			sscanf(linha1, "%d;%d;%f;\n", &cod_cidade, &cod_adjacente, &peso);
			if (cod_cidade == codigo) {
				criarAresta(g, codigo, cod_adjacente, peso);

			}

		}
		fclose(fp1);
		

	}

	

	

	fclose(fp);
	return g;
}

 
