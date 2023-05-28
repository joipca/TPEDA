#include <stdlib.h>
#include <string.h>
#include "meio.h"
// #include <algorithm>
#include <stdio.h>


//Guarda registos de clientes
int guardarMeios(Meio* inicio)
{
    FILE* fp;   
    fp = fopen("meios.txt", "w");    
    if (fp != NULL)   
    {
        Meio* aux = inicio;  
        while (aux != NULL) 
        {
            
            fprintf(fp, "%d;%d;%s;%f;%f;%f\n", aux->codigo, aux->codigo_local, aux->tipo, aux->autonomia, aux->bateria, aux->aluguer);
            aux = aux->seguinte;    
        }
        fclose(fp); 
        return(1);  
    }
    else
        return(0);  
}




int existeMeio(Meio* inicio, int cod)
{
    while (inicio != NULL)
    {
        if (inicio->codigo == cod) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}




//Lê registos dentro de aquivo criado
Meio* lerMeios()
{
    FILE* fp;
    fp = fopen("meios.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo 'meios.txt'!\n");
        return NULL;
    }

    Meio* inicio = NULL;
    char linha[200];

    while (fgets(linha, 200, fp) != NULL) {
        int codigo, codigo_local;
        char  tipo[50];
        float autonomia, bateria, aluguer;
        sscanf(linha, "%d;%d;%[^;];%f;%f;%f\n", &codigo, &codigo_local, tipo, &autonomia, &bateria, &aluguer);
        inicio = inserirMeio(inicio, codigo, codigo_local, tipo, autonomia, bateria, aluguer);
    }

    fclose(fp);
    return inicio;
}

// Inserção de novos dados
Meio* inserirMeio(Meio* inicio, int cod,int codigo_local, char tipo[], float bat, float aut, float alu)
{
    if (!existeMeio(inicio, cod)) { 
        Meio* novo = malloc(sizeof(struct registo)); 
        if (novo != NULL) {
            novo->codigo = cod;
            novo->codigo_local = codigo_local;
            strcpy(novo->tipo, tipo);
            novo->bateria = bat;
            novo->autonomia = aut;
            novo->aluguer = alu;
            novo->seguinte = inicio; 
            return(novo);
        }
    }
    else { 
        return(inicio);
    }
}



//Funcão auxiliar
void trocar(Meio* a, Meio* b) {
    Meio temp = *a;
    *a = *b;
    *b = temp;

    a->seguinte = b->seguinte;
    b->seguinte = &temp;
}


//Funcão de organização de listagem
void listarMeios(Meio** inicio) {
    int tamanho = 0;
    Meio* atual = *inicio;

    
    while (atual != NULL) {
        tamanho++;
        atual = atual->seguinte;
    }

    
    Meio** array = (Meio**)malloc(tamanho * sizeof(Meio*));
    atual = *inicio;

   
    for (int i = 0; i < tamanho; i++) {
        array[i] = atual;
        atual = atual->seguinte;
    }

   
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMaximo = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (array[j]->autonomia > array[indiceMaximo]->autonomia) {
                indiceMaximo = j;
            }
        }

        if (indiceMaximo != i) {
            Meio* temp = array[i];
            array[i] = array[indiceMaximo];
            array[indiceMaximo] = temp;
        }
    }

   
    printf("Lista de meios ordenada por autonomia em ordem decrescente:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d\nTipo: %s\nBateria: %.2f\nAutonomia: %.2f\nAluguer: %.2f\nLocal: %d\n\n",
            array[i]->codigo, array[i]->tipo, array[i]->bateria, 
            array[i]->autonomia, array[i]->aluguer,array[i]->codigo_local);
    }

    // Libera a memória alocada para o array temporário
    free(array);
}

// Remover determinado dados por código
Meio* removerMeio(Meio* inicio, int cod)
{
    Meio* anterior = inicio, * atual = inicio, * aux; 

    if (atual == NULL) return(NULL); 
    else if (atual->codigo == cod)  
    {
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual != NULL) && (atual->codigo != cod)) 
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual == NULL) return(inicio); 
        else
        {
            anterior->seguinte = atual->seguinte;
            free(atual);                         
            return(inicio);
        }
    }
}

Meio* adicionarLocalizacao(Meio* inicio, int cod, int cod_local) {

    Meio* atual = inicio;
    while ((atual != NULL) && (atual->codigo != cod)) 
    {
     
        atual = atual->seguinte;
    }
    if (atual == NULL) return(inicio); 
    else
    {
        atual->codigo_local = cod_local;             
        return(inicio);
    }



}

void listarMeiosporLocalizacao(Meio** inicio, int cod_local) {

    Meio* atual = *inicio;
    
    while (atual != NULL) {
        if (atual->codigo_local == cod_local) {
            printf("Codigo: %d\nTipo: %s\nBateria: %.2f\nAutonomia: %.2f\nAluguer: %.2f\nLocal: %d\n\n", atual->codigo, atual->tipo, atual->bateria, atual->autonomia, atual->aluguer, atual->codigo_local);


        }

        atual = atual->seguinte;

    }




}