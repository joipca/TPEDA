#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include <stdio.h>

//Guarda registos de clientes
int guardarClientes(Clientes * inicio)
{
    FILE* fp;   
    fp = fopen("clientes.txt", "w");    
    if (fp != NULL)   
    {
        Clientes* aux = inicio; 
        while (aux != NULL) 
        {
            
            fprintf(fp, "%d;%d;%d;%s;%s;%f\n", aux->codigo, aux->codigo_local, aux->nif, aux->nome, aux->morada, aux->saldo );
            aux = aux->seguinte;    
        }
        fclose(fp); 
        return(1);  
    }
    else
        return(0);  
}




int existeClientes(Clientes* inicio, int cod)
{
    while (inicio != NULL)
    {
        if (inicio->codigo == cod) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}




//Lê registos dentro de aquivo criado
Clientes* lerClientes()
{
    FILE* fp;
    fp = fopen("clientes.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo 'clientes.txt'!\n");
        return NULL;
    }

    Clientes* inicio = NULL;
    char linha[200];

    while (fgets(linha, 200, fp) != NULL) {
        int codigo,codigo_local, nif;
        char nome[50], morada[50];
        float saldo;
        sscanf(linha, "%d;%d;%d;%[^;];%[^;];%f\n",
            &codigo,&codigo_local, &nif, nome, morada, &saldo);
        inicio = inserirClientes(inicio, codigo, codigo_local, nif, nome, morada, saldo );
    }

    fclose(fp);
    return inicio;
}

// Inserção de novos dados
Clientes* inserirClientes(Clientes* inicio, int cod, int codigo_local, int nif, char nom[], char mor[], float sal)
{
  
    if (!existeClientes(inicio, cod)) { 
        Clientes* novo = malloc(sizeof(struct registo_clientes)); 
        if (novo != NULL) {
            novo->codigo = cod;
            strcpy(novo->morada, mor);
            strcpy(novo->nome, nom);
            novo->saldo = sal;
            novo->nif = nif;
            novo->codigo_local = codigo_local;
            novo->seguinte = inicio; 
            return(novo);
        }
    }
    else { 
        return(inicio);
    }
}





//funcão de organização de listagem
void listarClientes(Clientes** inicio) {
    int tamanho = 0;
    Clientes* atual = *inicio;

    
    while (atual != NULL) {
        tamanho++;
        atual = atual->seguinte;
    }

    
    Clientes** array = (Clientes**)malloc(tamanho * sizeof(Clientes*));
    atual = *inicio;

    
    for (int i = 0; i < tamanho; i++) {
        array[i] = atual;
        atual = atual->seguinte;
    }

   
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMaximo = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (array[j]->codigo > array[indiceMaximo]->codigo) {
                indiceMaximo = j;
            }
        }

        if (indiceMaximo != i) {
            Clientes* temp = array[i];
            array[i] = array[indiceMaximo];
            array[indiceMaximo] = temp;
        }
    }

    
    printf("Lista clientes:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Codigo: %d\nNif: %d\nNome: %s\nMorada: %s\nSaldo: %.2f\nLocal: %d\n",
            array[i]->codigo, array[i]->nif, array[i]->nome,
            array[i]->morada, array[i]->saldo, array[i]->codigo_local);
    }

    
    free(array);
}


// Remover determinado dados por código
Clientes* removerClientes(Clientes* inicio, int cod)
{
    Clientes* anterior = inicio, * atual = inicio, * aux; 

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

Clientes* adicionarLocalizacaoClientes(Clientes* inicio, int cod, int cod_local) {

    Clientes* atual = inicio;
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

int retornarLocalizacaoCliente(Clientes* inicio, int codigo_cliente) {

    Clientes* atual = inicio;

    while (atual != NULL && atual->codigo != codigo_cliente) {

        atual = atual->seguinte;

    }
    return atual->codigo_local;


}