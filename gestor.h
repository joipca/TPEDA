/**************************
@file gestor.h
@brief arquivo header de listas de gestores
@author Joao G
@date  Junho 2023

******************************/




/**
 * @brief Estrutura de dados para representar um registro de gestor.
 */
typedef struct registo_gestores
{
    int codigo; /**< Código do registro. */
    char nome[50]; /**< Nome do registro. */
    struct registo_gestores* seguinte; /**< Ponteiro para o próximo registro na lista. */
} Gestores;

/**
 * @brief Insere um novo registro de gestor no início da lista.
 *
 * @param[in] inicio O ponteiro para o início da lista de gestores.
 * @param[in] cod O código do novo registro de gestor.
 * @param[in] nom O nome do novo registro de gestor.
 * @return O ponteiro para o início da lista atualizada.
 */
Gestores* inserirGestores(Gestores* inicio, int cod, char nom[]);

/**
 * @brief Lista todos os registros de gestores presentes na lista.
 *
 * @param[in] inicio O ponteiro para o início da lista de gestores.
 */
void listarGestores(Gestores* inicio);

/**
 * @brief Verifica se um registro de gestor com o código especificado existe na lista.
 *
 * @param[in] inicio O ponteiro para o início da lista de gestores.
 * @param[in] codigo O código a ser verificado.
 * @return 1 se o registro existir, 0 caso contrário.
 */
int existeGestores(Gestores* inicio, int codigo);

/**
 * @brief Remove um registro de gestor com o código especificado da lista.
 *
 * @param[in] inicio O ponteiro para o início da lista de gestores.
 * @param[in] cod O código do registro a ser removido.
 * @return O ponteiro para o início da lista atualizada.
 */
Gestores* removerGestores(Gestores* inicio, int cod);

/**
 * @brief Guarda a lista de gestores em algum formato de armazenamento.
 *
 * @param[in] inicio O ponteiro para o início da lista de gestores.
 * @return 1 se a operação foi bem-sucedida, 0 caso contrário.
 */
int guardarGestores(Gestores* inicio);

/**
 * @brief Lê a lista de gestores de algum formato de armazenamento.
 *
 * @return O ponteiro para o início da lista de gestores lida.
 */
Gestores* lerGestores();