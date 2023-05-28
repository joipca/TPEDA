/**************************
@file grafo.h
@brief arquivo header de grafos
@author Joao G
@date  Junho 2023

******************************/


 /**
  * @brief Valor utilizado para representar a dist�ncia infinita em algoritmos.
  */
#define INFINITY 9999

  /**
   * @brief N�mero m�ximo de v�rtices no grafo.
   */
#define MAX 5

   /**
	* @brief Estrutura que representa um v�rtice adjacente no grafo.
	*/
typedef struct registo2
{
	int vertice; /**< Identificador do v�rtice adjacente. */
	float peso; /**< Peso da aresta que liga o v�rtice atual ao v�rtice adjacente. */
	struct registo2* seguinte; /**< Pr�ximo v�rtice adjacente na lista. */
} Adjacente;

/**
 * @brief Estrutura que representa um v�rtice no grafo.
 */
typedef struct registo1
{
	int vertice; /**< Identificador do v�rtice. */
	char cidade[50]; /**< Nome da cidade associada ao v�rtice. */
	Adjacente** adjacentes; /**< Lista de v�rtices adjacentes. */
	struct registo1* seguinte; /**< Pr�ximo v�rtice na lista. */
} *Grafo;

/**
 * @brief Cria um novo v�rtice no grafo.
 *
 * @param g Ponteiro para o ponteiro do grafo.
 * @param novoId Identificador do novo v�rtice.
 * @return 1 em caso de sucesso ou 0 caso contr�rio.
 */
int criarVertice(Grafo* g, int novoId);

/**
 * @brief Cria uma nova aresta no grafo.
 *
 * @param g Grafo em que a aresta ser� criada.
 * @param vOrigem Identificador do v�rtice de origem.
 * @param vDestino Identificador do v�rtice de destino.
 * @param peso Peso da aresta.
 * @return 1 em caso de sucesso ou 0 caso contr�rio.
 */
int criarAresta(Grafo g, int vOrigem, int vDestino, float peso);

/**
 * @brief Verifica se um v�rtice existe no grafo.
 *
 * @param g Grafo em que ser� realizada a verifica��o.
 * @param vertice Identificador do v�rtice a ser verificado.
 * @return 1 se o v�rtice existe ou 0 caso contr�rio.
 */
int existe(Grafo g, int vertice);

/**
 * @brief Lista os v�rtices adjacentes a um determinado v�rtice.
 *
 * @param g Grafo em que ser� realizada a listagem.
 * @param vertice Identificador do v�rtice.
 */
void listarAdjacentes(Grafo g, int vertice);

/**
 * @brief Lista todos os v�rtices do grafo.
 *
 * @param g Grafo em que ser� realizada a listagem.
 */
void listarVertices(Grafo g);

/**
 * @brief Guarda os locais em um arquivo.
 *
 * @param g Grafo contendo os locais a serem salvos.
 * @return 1 em caso de sucesso ou 0 caso contr�rio.
 */
int guardarLocais(Grafo g);

/**
 * @brief L� os locais de um arquivo e retorna um ponteiro para o grafo.
 *
 * @return Ponteiro para o grafo lido.
 */
Grafo* lerLocais();

/**
 * @brief Executa o algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo.
 *
 * @param G Matriz de adjac�ncia representando o grafo.
 * @param n N�mero de v�rtices no grafo.
 * @param startnode V�rtice de partida para o c�lculo do caminho mais curto.
 */
void dijkstra(int G[MAX][MAX], int n, int startnode);