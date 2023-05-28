/**************************
@file grafo.h
@brief arquivo header de listas de clientes
@author Joao G
@date  Junho 2023

******************************/



/**
 * @brief Estrutura para armazenar informa��es dos clientes.
 */
typedef struct registo_clientes
{
    int codigo; /**< C�digo do registro. */
    int codigo_local;
    int nif; /**< NIF do registro. */
    char nome[50]; /**< Nome do registro. */
    char morada[50]; /**< Morada do registro. */
    float saldo; /**< Saldo do registro. */
    struct registo_clientes* seguinte; /**< Ponteiro para o pr�ximo registro na lista. */
} Clientes;

/**
 * @brief Insere um novo registro de cliente na lista de clientes.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 * @param[in] cod O c�digo do registro de cliente a ser inserido.
 * @param[in] codigo_local O c�digo local do registro de cliente a ser inserido.
 * @param[in] nif O NIF do registro de cliente a ser inserido.
 * @param[in] nom O nome do registro de cliente a ser inserido.
 * @param[in] mor A morada do registro de cliente a ser inserido.
 * @param[in] sal O saldo do registro de cliente a ser inserido.
 * @return O ponteiro para o in�cio da lista de clientes atualizada.
 */
Clientes* inserirClientes(Clientes* inicio, int cod, int codigo_local, int nif, char nom[], char mor[], float sal);

/**
 * @brief Lista todos os registros de clientes na lista.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 */
void listarClientes(Clientes* inicio);

/**
 * @brief Verifica se um determinado c�digo de cliente existe na lista.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 * @param[in] codigo O c�digo de cliente a ser verificado.
 * @return 1 se o c�digo de cliente existe, 0 caso contr�rio.
 */
int existeClientes(Clientes* inicio, int codigo);

/**
 * @brief Remove o registro de cliente com o c�digo especificado da lista de clientes.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 * @param[in] cod O c�digo do registro de cliente a ser removido.
 * @return O ponteiro para o in�cio da lista de clientes atualizada.
 */
Clientes* removerClientes(Clientes* inicio, int cod);

/**
 * @brief Guarda os registros de clientes em um arquivo.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 * @return 1 se os registros foram salvos com sucesso, 0 caso contr�rio.
 */
int guardarClientes(Clientes* inicio);

/**
 * @brief L� os registros de clientes de um arquivo.
 *
 * @return O ponteiro para o in�cio da lista de clientes lida do arquivo.
 */
Clientes* lerClientes();

/**
 * @brief Adiciona uma localiza��o para um registro de cliente existente.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 * @param[in] cod O c�digo do registro de cliente ao qual adicionar a localiza��o.
 * @param[in] cod_local O c�digo local a ser adicionado.
 * @return O ponteiro para o in�cio da lista de clientes atualizada.
 */
Clientes* adicionarLocalizacaoClientes(Clientes* inicio, int cod, int cod_local);

/**
 * @brief Retorna a localiza��o de um cliente com base no c�digo do cliente.
 *
 * @param[in] inicio O ponteiro para o in�cio da lista de clientes.
 * @param[in] codigo_cliente O c�digo do cliente para o qual deseja-se obter a localiza��o.
 * @return O c�digo local associado ao cliente. Retorna -1 se o cliente n�o for encontrado.
 */
int retornarLocalizacaoCliente(Clientes* inicio, int codigo_cliente);