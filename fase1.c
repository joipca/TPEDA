#include <stdio.h>
#include "meio.h"
#include "clientes.h"
#include "gestor.h"
#include "grafo.h"
Grafo g = NULL;
int G[MAX][MAX];


void dijkstra(int G[MAX][MAX], int n, int startnode)
{
    
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
 
    nextnode = 0;
    printf("Startnode: %d\n N: %d", startnode, n);
    for (i = 0;i < n;i++)
        for (j = 0;j < n;j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

                
    
    
    for (i = 0;i < n;i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
   
        for (i = 0;i < n;i++)

            if (distance[i] < mindistance && !visited[i])
            {

                mindistance = distance[i];
                nextnode = i;
            }
 
        visited[nextnode] = 1;
        for (i = 0;i < n;i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;

        
    }

    

  
    for (i = 0;i < n;i++)
        if (i != startnode)
        {
            printf("\nDistancia de nodulo%d=%d", i, distance[i]);
            printf("\nCaminho=%d", i);
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startnode);
        }
        
        

}





void listarMeiosporRaio(Grafo g, Meio** meios, int cod_local, float raio) {

    while (g != NULL)
    {
        if (g->vertice == cod_local) {
            Adjacente* aux = g->adjacentes;
            while (aux != NULL) {
                if (raio >= aux->peso) {
                    listarMeiosporLocalizacao(meios, aux->vertice);

                }

                aux = aux->seguinte;

            }


        }

        g = g->seguinte;
    }

}



int lerRedeEstradas(int G[MAX][MAX], Grafo g)
{
    

  
    for (int l = 0;l < MAX;l++)
        for (int c = 0;c < MAX;c++)
            G[l][c] = 0;

 
    if (g != NULL)
    {
        while (g != NULL)
        {
            Adjacente* aux = g->adjacentes;
            while (aux != NULL) {
                G[g->vertice][aux->vertice] = aux->peso;
                aux = aux->seguinte;

            }
            g = g->seguinte;
        }
        return(1);
    }
    else return(0);
}

void escreverRedeEstradas(int G[MAX][MAX])
{
    int l, c;
    for (l = 0;l < MAX;l++)
    {
        for (c = 0;c < MAX;c++) printf("%d\t", G[l][c]);
        printf("\n");
    }
}






// Menu de opções
int menu()
{
    int op;
    printf("M E N U\n");
    printf("1 Menu Meios\n");
    printf("2 Menu Clientes\n");
    printf("3 Menu Gestores\n");
    printf("4 Menu Localizacoes\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d", &op);
    return op;
}

// Menu Meios
void menuMeios(Meio** meios)
{
    int op, cod, cod_local;
    float bat, aut, alu;
    char tipo[50];

    do {
        printf("M E N U   M E I O S\n");
        printf("1 Inserir Meio\n");
        printf("2 Listar Meios\n");
        printf("3 Remover Meio\n");
        printf("4 Guardar Meios\n");
        printf("5 Ler Meios\n");
        printf("6 Adicionar Localizacao");
        printf("0 Voltar ao menu principal\n");
        printf("Opcao:\n");
        scanf("%d", &op);

        

        switch (op) {
        case 1:
            printf("Codigo?\n");
            scanf("%d", &cod);
            printf("Tipo?\n");
            scanf("%s", tipo);
            printf("Nivel da bateria?\n");
            scanf("%f", &bat);
            printf("Autonomia?\n");
            scanf("%f", &aut);
            printf("Aluguer?\n");
            scanf("%f", &alu);
            *meios = inserirMeio(*meios, cod, 0, tipo, bat, aut, alu);
            break;
        case 2:
            listarMeios(meios);
            break;
        case 3:
            printf("Codigo do meio de mobilidade a remover?\n");
            scanf("%d", &cod);
            *meios = removerMeio(*meios, cod);
            break;
        case 4:
            guardarMeios(*meios);
            break;
        case 5:
            *meios = lerMeios();
            break;
        case 6:
            printf("Codigo do meio para qual quer inserir na localizacao?\n");
            scanf("%d", &cod);
            listarVertices(g);
            printf("Codigo da localizacao?\n");
            scanf("%d", &cod_local);
            *meios = adicionarLocalizacao(*meios, cod, cod_local);

            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);
}

// Menu Clientes
void menuClientes(Clientes** clientes, Meio** meios)
{
    int op, cod, nif, cod_local;
    float sal, raio;
    char nom[50], mor[50];

    do {
        printf("M E N U   C L I E N T E S\n");
        printf("1 Inserir Cliente\n");
        printf("2 Listar Clientes\n");
        printf("3 Remover Cliente\n");
        printf("4 Guardar Clientes\n");
        printf("5 Ler Clientes\n");
        printf("6 Adicionar Localizacao\n");
        printf("7 Listar meios por localizacao de clientes\n");
        printf("0 Voltar ao menu principal\n");
        printf("Opcao:\n");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Codigo?\n");
            scanf("%d", &cod);
            printf("Morada?\n");
            scanf("%s", mor);
            printf("Nome?\n");
            scanf("%s", nom);
            printf("Saldo?\n");
            scanf("%f", &sal);
            printf("Nif?\n");
            scanf("%d", &nif);
            *clientes = inserirClientes(*clientes, cod, 0, nif, nom, mor, sal);
            break;
        case 2: 
            listarClientes(clientes);
                break;
            case 3:
                printf("Codigo do cliente a remover?\n");
                scanf("%d", &cod);
                *clientes = removerClientes(*clientes, cod);
                break;
            case 4:
                guardarClientes(*clientes);
                break;
            case 5:
                *clientes = lerClientes();
                break;
            case 6:
                printf("Codigo do cliente para qual quer inserir na localizacao?\n");
                scanf("%d", &cod);
                listarVertices(g);
                printf("Codigo da localizacao?\n");
                scanf("%d", &cod_local);
                *clientes = adicionarLocalizacaoClientes(*clientes, cod, cod_local);
                break;
            case 7:
                printf("Codigo do cliente?\n");
                scanf("%d", &cod);
                printf("Raio?\n");
                scanf("%f", &raio);
                int cod_local_cliente = retornarLocalizacaoCliente(*clientes, cod);
                printf("Codigo local de cliente: %d\n", cod_local_cliente);
                listarMeiosporLocalizacao(meios, cod_local_cliente);
                listarMeiosporRaio(g, meios, cod_local_cliente, raio) ;
                
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (op != 0);
}

// Menu Gestores
void menuGestores(Gestores** gestores)
{
    int op, cod;
    char nom[50];

    do {
        printf("M E N U   G E S T O R E S\n");
        printf("1 Inserir Gestor\n");
        printf("2 Listar Gestores\n");
        printf("3 Remover Gestor\n");
        printf("4 Guardar Gestores\n");
        printf("5 Ler Gestores\n");
        printf("0 Voltar ao menu principal\n");
        printf("Opcao:\n");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("Codigo?\n");
            scanf("%d", &cod);
            printf("Nome?\n");
            scanf("%s", nom);
            *gestores = inserirGestores(*gestores, cod, nom);
            break;
        case 2:
            listarGestores(gestores);
            break;
        case 3:
            printf("Codigo do Gestor a remover?\n");
            scanf("%d", &cod);
            *gestores = removerGestores(*gestores, cod);
            break;
        case 4:
            guardarGestores(*gestores);
            break;
        case 5:
            *gestores = lerGestores();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);
}



void menuLocalizacoes()
{
    int i, n, j, op, cod, cod_local_partida, cod_local1, cod_local2, startNode, distancia ;
    float peso ;
    char localizacao[50], tipo[50] ;

    do {
        printf("M E N U   L O C A L I Z A C O E S\n");
        printf("1 Inserir Localizacao\n");
        printf("2 Inserir Caminho\n");
        printf("3 Listar Localizacoes\n");
        printf("4 Listar Adjacentes\n");
        printf("5 Salvar Localizacaoes\n");
        printf("6 Recolha de meios\n");
        printf("0 Voltar ao menu principal\n");
        printf("Opcao:\n");
        scanf("%d", &op);

       

        switch (op) {
        case 1:
            printf("Codigo?\n");
            scanf("%d", &cod);
            printf("Localizacao?\n");
            scanf("%s", localizacao);
            criarVertice(&g, cod, localizacao);
            break;
        case 3:
            listarVertices(g) ;
            break;
        case 2:
            listarVertices(g);
            printf("Codigo de Local 1?\n");
            scanf("%d", &cod_local1);
            printf("Codigo de Local 2?\n");
            scanf("%d", &cod_local2);
            printf("Peso?\n");
            scanf("%f", &peso);
            criarAresta(g, cod_local1, cod_local2, peso);
            break;
        case 4:
            printf("Codigo?\n");
            scanf("%d", &cod);
            listarAdjacentes(g, cod);
            break;
        case 5:
            guardarLocais(g);
           
            break;
        case 0:
            break;

        case 6:

            lerRedeEstradas(G, g);
            printf("Conteudo de G:\n");
            escreverRedeEstradas(G);
            
            printf("----------------\n");
            printf("Qual o codigo de seu local?\n");
            scanf("%d", &startNode);

            dijkstra(G, MAX, startNode);


            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);
}





// Seleção de opções, entrada de dados
int main()
{
   

    Meio* meios = NULL;
    Clientes* clientes = NULL;
    Gestores* gestores = NULL;
    int op;

    g = lerLocais();
    meios = lerMeios();
    clientes = lerClientes();
    gestores = lerGestores();

    do {
        op = menu();

        switch (op) {
        case 1:
            menuMeios(&meios);
            break;
        case 2:
            menuClientes(&clientes, &meios);
            break;
        case 3:
            menuGestores(&gestores);
            break;
        case 4:
            menuLocalizacoes();
           break;
        case 0:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);

    return 0;
}

