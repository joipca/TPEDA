#include <stdlib.h>
#include <string.h>
#include "gestor.h"
#include <stdio.h>


//Guarda registos de clientes
int guardarGestores(Gestores * inicio)
{
    FILE* fp;   // Declara um ponteiro para ficheiro
    fp = fopen("Gestores.txt", "w");    // Abre o ficheiro para escrita
    if (fp != NULL)   // Verifica se o ficheiro foi aberto com sucesso
    {
        Gestores* aux = inicio;  // Declara um ponteiro para o in�cio da lista ligada
        while (aux != NULL) // Percorre cada n� da lista ligada
        {
            // Escreve os dados do n� atual no ficheiro num formato espe�i�fico
            fprintf(fp, "%d;%s\n", aux->codigo, aux->nome);
            aux = aux->seguinte;    // Move para o pr�ximo n� da lista ligada
        }
        fclose(fp); // Fecha o ficheiro
        return(1);  // Retorna 1 para indicar que a fun��o foi conclu�da com sucesso
    }
    else
        return(0);  // Retorna 0 para indicar que a fun��o falhou ao abrir o ficheiro
}




int existeGestores(Gestores* inicio, int cod)
{
    while (inicio != NULL)
    {
        if (inicio->codigo == cod) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}




//L� registos dentro de aquivo criado
Gestores* lerGestores()
{
    FILE* fp;
    fp = fopen("Gestores.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo 'Gestores.txt'!\n");
        return NULL;
    }

    Gestores* inicio = NULL;
    char linha[200];

    while (fgets(linha, 200, fp) != NULL) {
        int codigo;
        char  nome[50];
        sscanf(linha, "%d;%[^;]\n", &codigo, nome);
        inicio = inserirGestores(inicio, codigo, nome);
    }

    fclose(fp);
    return inicio;
}

// Inser��o de novos dados
Gestores* inserirGestores(Gestores* inicio, int cod, char nome[])
{
    if (!existeGestores(inicio, cod)) { //verifica se j� existe um Gestores com c�digo
        Gestores* novo = malloc(sizeof(struct registo_gestores)); //aloca mem�ria para um novo registro Gestores
        if (novo != NULL) {
            novo->codigo = cod;
            strcpy(novo->nome, nome);
            novo->seguinte = inicio; //coloca o novo registro no �nico da lista
            return(novo);
        }
    }
    else { //se o c�digo� existe na lista, n�o foi adicionado nenhum registro
        return(inicio);
    }
}



//func�o auxiliar
//void trocar_Gestores(Gestores* a, Gestores* b) {
//    Gestores temp = *a;
//    *a = *b;
 //   *b = temp;
//
 //   a->seguinte = b->seguinte;
//    b->seguinte = &temp;
//}


//func�o de organiza��o de listagem
void listarGestores(Gestores** inicio) {
    int tamanho = 0;
    Gestores* atual = *inicio;

    // Encontra o tamanho da lista
    while (atual != NULL) {
        tamanho++;
        atual = atual->seguinte;
    }

    // Cria um array tempor�rio para armazenar os meios
    Gestores** array = (Gestores**)malloc(tamanho * sizeof(Gestores*));
    atual = *inicio;

    // Copia os meios da lista para o array tempor�rio
    for (int i = 0; i < tamanho; i++) {
        array[i] = atual;
        atual = atual->seguinte;
    }

    // Ordena o array pelo campo autonomia em ordem decrescente usando o algoritmo de sele��o
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMaximo = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (array[j]->codigo > array[indiceMaximo]->codigo) {
                indiceMaximo = j;
            }
        }

        if (indiceMaximo != i) {
            Gestores* temp = array[i];
            array[i] = array[indiceMaximo];
            array[indiceMaximo] = temp;
        }
    }

    // Imprime os meios ordenados pelo campo autonomia em ordem decrescente
    printf("Lista Gestores:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d\nNome: %s\n",
            array[i]->codigo, array[i]->nome);
    }

    // Libera a mem�ria alocada para o array tempor�rio
    free(array);
}


// Remover determinado dados por c�digo
Gestores* removerGestores(Gestores* inicio, int cod)
{
    Gestores* anterior = inicio, * atual = inicio, * aux; //declara��o de ponteiros

    if (atual == NULL) return(NULL); //se o ponteiro atual for null, a lista est� vazia, retorna NULL
    else if (atual->codigo == cod)  //se o c�igo fornecido for igual ao do elemento, remove o elemento e retorna o ponteiro
    {
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual != NULL) && (atual->codigo != cod)) //se o primeiro elemento n�o deve ser removido, percorre a lista at� encontrar o elemento com o c�digo fornecido ou chegar ao final da lista
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL) return(inicio); //se o elemento com o c�digo fornecido n�o for encontrado na lista, retorna o ponteiro para o primeiro elemento.
        else
        {
            anterior->seguinte = atual->seguinte;
            free(atual);                         // libera o espa�o na mem�ria alocado para o elemento removido
            return(inicio);
        }
    }
}