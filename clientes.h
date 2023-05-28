/**************************
@file grafo.h
@brief arquivo header de listas de clientes
@author Joao G
@date  Junho 2023

******************************/



/**
 * @brief Estrutura para armazenar informações dos clientes.
 */
typedef struct registo_clientes
{
    int codigo; /**< Código do registro. */
    int codigo_local;
    int nif; /**< NIF do registro. */
    char nome[50]; /**< Nome do registro. */
    char morada[50]; /**< Morada do registro. */
    float saldo; /**< Saldo do registro. */
    struct registo_clientes* seguinte; /**< Ponteiro para o próximo registro na lista. */
} Clientes;

/**
 * @brief Insere um novo registro de cliente na lista de clientes.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 * @param[in] cod O código do registro de cliente a ser inserido.
 * @param[in] codigo_local O código local do registro de cliente a ser inserido.
 * @param[in] nif O NIF do registro de cliente a ser inserido.
 * @param[in] nom O nome do registro de cliente a ser inserido.
 * @param[in] mor A morada do registro de cliente a ser inserido.
 * @param[in] sal O saldo do registro de cliente a ser inserido.
 * @return O ponteiro para o início da lista de clientes atualizada.
 */
Clientes* inserirClientes(Clientes* inicio, int cod, int codigo_local, int nif, char nom[], char mor[], float sal);

/**
 * @brief Lista todos os registros de clientes na lista.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 */
void listarClientes(Clientes* inicio);

/**
 * @brief Verifica se um determinado código de cliente existe na lista.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 * @param[in] codigo O código de cliente a ser verificado.
 * @return 1 se o código de cliente existe, 0 caso contrário.
 */
int existeClientes(Clientes* inicio, int codigo);

/**
 * @brief Remove o registro de cliente com o código especificado da lista de clientes.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 * @param[in] cod O código do registro de cliente a ser removido.
 * @return O ponteiro para o início da lista de clientes atualizada.
 */
Clientes* removerClientes(Clientes* inicio, int cod);

/**
 * @brief Guarda os registros de clientes em um arquivo.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 * @return 1 se os registros foram salvos com sucesso, 0 caso contrário.
 */
int guardarClientes(Clientes* inicio);

/**
 * @brief Lê os registros de clientes de um arquivo.
 *
 * @return O ponteiro para o início da lista de clientes lida do arquivo.
 */
Clientes* lerClientes();

/**
 * @brief Adiciona uma localização para um registro de cliente existente.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 * @param[in] cod O código do registro de cliente ao qual adicionar a localização.
 * @param[in] cod_local O código local a ser adicionado.
 * @return O ponteiro para o início da lista de clientes atualizada.
 */
Clientes* adicionarLocalizacaoClientes(Clientes* inicio, int cod, int cod_local);

/**
 * @brief Retorna a localização de um cliente com base no código do cliente.
 *
 * @param[in] inicio O ponteiro para o início da lista de clientes.
 * @param[in] codigo_cliente O código do cliente para o qual deseja-se obter a localização.
 * @return O código local associado ao cliente. Retorna -1 se o cliente não for encontrado.
 */
int retornarLocalizacaoCliente(Clientes* inicio, int codigo_cliente);