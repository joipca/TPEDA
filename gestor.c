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
        Gestores* aux = inicio;  // Declara um ponteiro para o início da lista ligada
        while (aux != NULL) // Percorre cada nó da lista ligada
        {
            // Escreve os dados do nó atual no ficheiro num formato espeçi­fico
            fprintf(fp, "%d;%s\n", aux->codigo, aux->nome);
            aux = aux->seguinte;    // Move para o próximo nó da lista ligada
        }
        fclose(fp); // Fecha o ficheiro
        return(1);  // Retorna 1 para indicar que a função foi concluída com sucesso
    }
    else
        return(0);  // Retorna 0 para indicar que a função falhou ao abrir o ficheiro
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




//Lê registos dentro de aquivo criado
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

// Inserção de novos dados
Gestores* inserirGestores(Gestores* inicio, int cod, char nome[])
{
    if (!existeGestores(inicio, cod)) { //verifica se já existe um Gestores com código
        Gestores* novo = malloc(sizeof(struct registo_gestores)); //aloca memória para um novo registro Gestores
        if (novo != NULL) {
            novo->codigo = cod;
            strcpy(novo->nome, nome);
            novo->seguinte = inicio; //coloca o novo registro no ínico da lista
            return(novo);
        }
    }
    else { //se o código¡ existe na lista, não foi adicionado nenhum registro
        return(inicio);
    }
}



//funcão auxiliar
//void trocar_Gestores(Gestores* a, Gestores* b) {
//    Gestores temp = *a;
//    *a = *b;
 //   *b = temp;
//
 //   a->seguinte = b->seguinte;
//    b->seguinte = &temp;
//}


//funcão de organização de listagem
void listarGestores(Gestores** inicio) {
    int tamanho = 0;
    Gestores* atual = *inicio;

    // Encontra o tamanho da lista
    while (atual != NULL) {
        tamanho++;
        atual = atual->seguinte;
    }

    // Cria um array temporário para armazenar os meios
    Gestores** array = (Gestores**)malloc(tamanho * sizeof(Gestores*));
    atual = *inicio;

    // Copia os meios da lista para o array temporário
    for (int i = 0; i < tamanho; i++) {
        array[i] = atual;
        atual = atual->seguinte;
    }

    // Ordena o array pelo campo autonomia em ordem decrescente usando o algoritmo de seleção
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

    // Libera a memória alocada para o array temporário
    free(array);
}


// Remover determinado dados por código
Gestores* removerGestores(Gestores* inicio, int cod)
{
    Gestores* anterior = inicio, * atual = inicio, * aux; //declaração de ponteiros

    if (atual == NULL) return(NULL); //se o ponteiro atual for null, a lista está¡ vazia, retorna NULL
    else if (atual->codigo == cod)  //se o cóigo fornecido for igual ao do elemento, remove o elemento e retorna o ponteiro
    {
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual != NULL) && (atual->codigo != cod)) //se o primeiro elemento não deve ser removido, percorre a lista até encontrar o elemento com o código fornecido ou chegar ao final da lista
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL) return(inicio); //se o elemento com o código fornecido não for encontrado na lista, retorna o ponteiro para o primeiro elemento.
        else
        {
            anterior->seguinte = atual->seguinte;
            free(atual);                         // libera o espaço na memória alocado para o elemento removido
            return(inicio);
        }
    }
}