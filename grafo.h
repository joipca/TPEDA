/**************************
@file grafo.h
@brief arquivo header de grafos
@author Joao G
@date  Junho 2023

******************************/


 /**
  * @brief Valor utilizado para representar a distância infinita em algoritmos.
  */
#define INFINITY 9999

  /**
   * @brief Número máximo de vértices no grafo.
   */
#define MAX 5

   /**
	* @brief Estrutura que representa um vértice adjacente no grafo.
	*/
typedef struct registo2
{
	int vertice; /**< Identificador do vértice adjacente. */
	float peso; /**< Peso da aresta que liga o vértice atual ao vértice adjacente. */
	struct registo2* seguinte; /**< Próximo vértice adjacente na lista. */
} Adjacente;

/**
 * @brief Estrutura que representa um vértice no grafo.
 */
typedef struct registo1
{
	int vertice; /**< Identificador do vértice. */
	char cidade[50]; /**< Nome da cidade associada ao vértice. */
	Adjacente** adjacentes; /**< Lista de vértices adjacentes. */
	struct registo1* seguinte; /**< Próximo vértice na lista. */
} *Grafo;

/**
 * @brief Cria um novo vértice no grafo.
 *
 * @param g Ponteiro para o ponteiro do grafo.
 * @param novoId Identificador do novo vértice.
 * @return 1 em caso de sucesso ou 0 caso contrário.
 */
int criarVertice(Grafo* g, int novoId);

/**
 * @brief Cria uma nova aresta no grafo.
 *
 * @param g Grafo em que a aresta será criada.
 * @param vOrigem Identificador do vértice de origem.
 * @param vDestino Identificador do vértice de destino.
 * @param peso Peso da aresta.
 * @return 1 em caso de sucesso ou 0 caso contrário.
 */
int criarAresta(Grafo g, int vOrigem, int vDestino, float peso);

/**
 * @brief Verifica se um vértice existe no grafo.
 *
 * @param g Grafo em que será realizada a verificação.
 * @param vertice Identificador do vértice a ser verificado.
 * @return 1 se o vértice existe ou 0 caso contrário.
 */
int existe(Grafo g, int vertice);

/**
 * @brief Lista os vértices adjacentes a um determinado vértice.
 *
 * @param g Grafo em que será realizada a listagem.
 * @param vertice Identificador do vértice.
 */
void listarAdjacentes(Grafo g, int vertice);

/**
 * @brief Lista todos os vértices do grafo.
 *
 * @param g Grafo em que será realizada a listagem.
 */
void listarVertices(Grafo g);

/**
 * @brief Guarda os locais em um arquivo.
 *
 * @param g Grafo contendo os locais a serem salvos.
 * @return 1 em caso de sucesso ou 0 caso contrário.
 */
int guardarLocais(Grafo g);

/**
 * @brief Lê os locais de um arquivo e retorna um ponteiro para o grafo.
 *
 * @return Ponteiro para o grafo lido.
 */
Grafo* lerLocais();

/**
 * @brief Executa o algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo.
 *
 * @param G Matriz de adjacência representando o grafo.
 * @param n Número de vértices no grafo.
 * @param startnode Vértice de partida para o cálculo do caminho mais curto.
 */
void dijkstra(int G[MAX][MAX], int n, int startnode);